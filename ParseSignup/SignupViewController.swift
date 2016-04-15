//
//  SignupController.swift
//  parseBrainSample
//
//  Created by Mario Couture on 2016-03-09.
//  Copyright © 2016 bitHeads inc. All rights reserved.
//

import Foundation
import UIKit

class SignupController: UIViewController {
    
    @IBOutlet weak var emailField: UITextField!
    @IBOutlet weak var userNameField: UITextField!
    @IBOutlet weak var displayName: UITextField!
    @IBOutlet weak var passwordField: UITextField!
    @IBOutlet weak var validatePwdField: UITextField!
    @IBOutlet weak var messageLabel: UILabel!
    
    var currentUser: PFUser?
    
    @IBAction func signupAction(sender: AnyObject) {
        self.messageLabel.text = ""
        let user = PFUser()
        user.username = self.userNameField.text
        user.password = self.passwordField.text
        user.email = self.emailField.text
        // other fields can be set just like with PFObject
        user["displayName"] = self.displayName.text
        
        if self.passwordField.text == self.validatePwdField.text  {
            user.signUpInBackgroundWithBlock
                { [unowned self] (succeeded: Bool, error: NSError?) -> Void in
                    if let error = error {
                        let errorString = error.userInfo["error"] as? NSString
                        // Show the errorString somewhere and let the user try again.
                        self.messageLabel.text = errorString as String?
                    } else if succeeded {
                        // Hooray! Let them use the app now.
                        self.currentUser = user
                        self.messageLabel.text = ""
                        self.confirmSignupSuccess()
                    } else {
                        self.messageLabel.text = "Unknown state"
                        NSLog("Signup returned an unknown state")
                    }
            }
        } else {
            self.messageLabel.text = "Password validation failed."
        }
    }
    
    @IBAction func clearAction(sender: AnyObject) {
        self.emailField.text = ""
        self.userNameField.text = ""
        self.displayName.text = ""
        self.passwordField.text = ""
        self.validatePwdField.text = ""
        self.emailField.becomeFirstResponder()
    }
    
    func confirmSignupSuccess() {
        let confirm = UIAlertController.init(title: "Signup completed", message: "You are now registered as a user.", preferredStyle: UIAlertControllerStyle.Alert)
        
        self.presentViewController(confirm, animated: true, completion: {
            self.clearAction(self)
            // show message for 2 seconds
            let triggerTime = (Int64(NSEC_PER_SEC) * 2)
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, triggerTime), dispatch_get_main_queue(), { () -> Void in
                confirm.dismissViewControllerAnimated(true, completion: nil)
            })
        })
    }
    
}