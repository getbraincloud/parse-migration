//
//  SigninController.swift
//  parseBrainSample
//
//  Created by Mario Couture on 2016-03-09.
//  Copyright © 2016 bitHeads inc. All rights reserved.
//

import Foundation
import UIKit

class SigninController: UIViewController {
    
    @IBOutlet weak var usernameField: UITextField!
    @IBOutlet weak var passwordField: UITextField!
    @IBOutlet weak var messageLabel: UILabel!
    
    var currentParseUser: PFUser?
    private let bcc : BrainCloudClient = BrainCloudClient.getInstance()
    private var migrateStatusViewController: MigrateStatusViewController?
    
    // MARK: - View management
    
    override func viewDidAppear(animated: Bool) {
        if  let username = NSUserDefaults.standardUserDefaults().valueForKey("UserName") as? String {
            self.usernameField.text = username
        }
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "loginSegue"  {
            // get a reference to the MigrationStatusViewController
            self.migrateStatusViewController = segue.destinationViewController as? MigrateStatusViewController
        }
    }
    
    /**
    Close the migration status view controller after a 2 sec. delay then segueway to Game Screen
    */
    func closeMigrationStatusViewController(signinDone:Bool) {
        // After 2 seconds remove migration status view and go to game.
        let triggerTime = (Int64(NSEC_PER_SEC) * 3)
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, triggerTime), dispatch_get_main_queue(), { () -> Void in
            self.migrateStatusViewController!.dismissViewControllerAnimated(true, completion: {
                if signinDone {
                    self.performSegueWithIdentifier("signinDoneSegue", sender: self)
                }
                self.migrateStatusViewController = nil
            })
        })
    }
    
    /**
     Close the migration status view controller after a 2 sec. delay then segueway back to Main Screen
     */
    func returnToMainController() {
        let triggerTime = (Int64(NSEC_PER_SEC) * 3)
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, triggerTime), dispatch_get_main_queue(), { () -> Void in
            self.migrateStatusViewController!.dismissViewControllerAnimated(true, completion: {
                self.performSegueWithIdentifier("backToMain", sender: self)
                self.migrateStatusViewController = nil
            })
        })
    }
    
    // MARK: Actions
    
    @IBAction func signinAction(sender: AnyObject) {
        
        // ****************************************
        // Display Migration Status Controller
        self.performSegueWithIdentifier("loginSegue", sender: self)

        // ****************************************
        //Clear any profile id that may have been used before.
        self.bcc.authenticationService.clearSavedProfile();

        // ****************************************
        // Authenticate with brainCloud
        bcc.authenticationService.authenticateEmailPassword(
            self.usernameField.text!,
            password: self.passwordField.text!,
            forceCreate: false,
            completionBlock: { (serviceName, serviceOperation, jsonData, cbObject) -> Void in

                // ****************************************
                // Login to brainCloud succeeded, will proceed to Game Screen
                self.migrateStatusViewController?.loggedinToField.text = "Logged-in to brainCloud"
                self.closeMigrationStatusViewController(true)

            },
            errorCompletionBlock: { (serviceName, serviceOperation, statusCode, returnCode, jsonError, cbObject) -> Void in

                // ****************************************
                // If missing brainCloud profile the try with Parse
                if statusCode == 202 {
                    print("No brainCloud profile, trying Parse...")
                    self.loginToParse()
                } else {
                    // Other error
                    print(" \(serviceName) \(serviceOperation) failed with status \(statusCode) \(returnCode) \n \(jsonError)")
                }
                
            },
            cbObject: nil)
    }
    
    // MARK: - Parse
    
    /**
     Login to Parse
    */
    func loginToParse() {
        PFUser.logInWithUsernameInBackground(self.usernameField.text!, password:self.passwordField.text!, block: {
            (user: PFUser?, error: NSError?) -> Void in
                if user != nil {
                    // Do stuff after successful login.
                    self.currentParseUser = user
                    self.migrateStatusViewController?.loggedinToField.text = "Authenticated to Parse"
                    
                    // ****************************************
                    // Authenticate to braincloud using external authentication
                    self.loginExternalToBrainCloud();
                } else {
                    // Show error
                    if let error = error {
                        let errorString = error.userInfo["error"] as? NSString
                        print("Could not log in to Parse error \(errorString)")
                        self.migrateStatusViewController?.loggedinToField.text = errorString as? String
                    } else {
                        print("Could not log in to Parse unknown error")
                        self.migrateStatusViewController?.loggedinToField.text = "Unknown error"
                    }
                    self.closeMigrationStatusViewController(false)
                }
        } )
    }

    // MARK: - brainCloud
    
    /**
    Login to braincloud using Parse as external authentication service.
    */
    func loginExternalToBrainCloud() {
        
        // ****************************************
        // Use external authentication to login to brainCloud
        bcc.authenticationService.authenticateParse(
            self.currentParseUser?.objectId,
            token:self.currentParseUser?.sessionToken,
            forceCreate: true,
            completionBlock: {
                serviceName, serviceOperation, jsonData, cbObject in
                self.migrateStatusViewController?.authneticatingToBCField.text = "Authenticated to brainCloud"
                do {
                    let data:NSDictionary = try NSJSONSerialization.JSONObjectWithData(jsonData.dataUsingEncoding(NSUTF8StringEncoding)!, options: []) as! NSDictionary
                    print("Authenticated to brainCloud with status \(data["status"]?.intValue)")
                } catch {
                    print("Could not decode authenticateExternal results")
                }
                
                // ****************************************
                // Copy user data from Parse
                self.syncUserData()
            },
            errorCompletionBlock: {
                serviceName, serviceOperation, statusCode, returnCode, jsonError, cbObject in
                self.migrateStatusViewController?.authneticatingToBCField.text = "Authenticated to brainCloud Failed"
                print(" \(serviceName) \(serviceOperation) failed with status \(statusCode) \(returnCode) \n \(jsonError)")
                self.returnToMainController()
            },
            cbObject: nil)
        
        
    }
    
    /**
    Using a custom server script (SynUser) copy user properties from Parse to brainCloud
    */
    func syncUserData() {
        if let user = self.currentParseUser {
            let param: NSDictionary = [ "externalId" : user.objectId!, "sessionToken": (self.currentParseUser?.sessionToken)! ]
            if NSJSONSerialization.isValidJSONObject(param) {
                do {
                    let paramString = try String( data: NSJSONSerialization.dataWithJSONObject(param, options: NSJSONWritingOptions.PrettyPrinted) ,encoding: NSUTF8StringEncoding)

                    // ****************************************
                    // Execute Cloud Script SyncUser to copy user properties
                    bcc.scriptService.runScript("SyncUser",
                        jsonScriptData: paramString,
                        completionBlock: {
                            serviceName, serviceOperation, jsonData, cbObject in
                            print("SyncUser returned data: \(jsonData)")
                            // Show Status on screen
                            do {
                                let data = try NSJSONSerialization.JSONObjectWithData(jsonData.dataUsingEncoding(NSUTF8StringEncoding)!, options:[])
                                if let displayName = data["data"]??["response"]??["data"]??["attributes"]??["displayName"] as? String {
                                    self.migrateStatusViewController?.migratingToBCField.text = "Migrated user \n- \(displayName) -\n data to brainCloud"
                                } else {
                                    self.migrateStatusViewController?.migratingToBCField.text = "Migrated user data to brainCloud"
                                }
                            } catch {
                                print(" Could not decode syncUser result")
                            }
                            
                            // ****************************************
                            // Now create a equivalent Login in brainCloud
                            self.migrateLoginToBC()
                            
                        },
                        errorCompletionBlock: {
                            serviceName, serviceOperation, statusCode, returnCode, jsonError, cbObject in
                            print(" \(serviceName) \(serviceOperation) failed with status \(statusCode) \(returnCode) \n \(jsonError)")
                            self.migrateStatusViewController?.migratingToBCField.text = "Error Migrating User"
                            self.returnToMainController()
                        },
                        cbObject: nil)
                } catch {
                    print("Failed to serialize externalId")
                }
            }
        }
    }
    
    
    /**
    Create native brainCloud credentials using the ones from Parse.
    */
    func migrateLoginToBC() {
        
        // ****************************************
        // Associate an email/password identity to the current session so brainCloud authentication can be used directly
        self.bcc.identityService.attachEmailIdentity(self.currentParseUser?.email, authenticationToken: self.passwordField.text,
            completionBlock: {
                serviceName, serviceOperation, jsonData, cbObject in
                do {
                    let data:NSDictionary = try NSJSONSerialization.JSONObjectWithData(jsonData.dataUsingEncoding(NSUTF8StringEncoding)!, options:[]) as! NSDictionary
                    print(" \(serviceName) \(serviceOperation) Login Migration returned \(data)")
                    if data.valueForKey("status")?.intValue == 200 {
                        // replace the persisted username
                        NSUserDefaults.standardUserDefaults().setObject(self.currentParseUser?.email, forKey: "UserName")
                        self.migrateStatusViewController?.readyField.text = "Migration Completed"
                    }
                } catch {
                    print(" \(serviceName) \(serviceOperation) Failed to read jsonData")
                }
                self.closeMigrationStatusViewController(true)
            },
            errorCompletionBlock: { (serviceName, serviceOperation, statusCode, returnCode, jsonError, cbObject) -> Void in
                print(" \(serviceName) \(serviceOperation) failed with status \(statusCode) \(returnCode) \n \(jsonError)")
                self.migrateStatusViewController?.readyField.text = "Error Creating Identity"
                self.returnToMainController()
                
            }, cbObject: nil)
    }
    

    
}