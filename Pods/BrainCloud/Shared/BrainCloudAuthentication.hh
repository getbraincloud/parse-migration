//
//  BrainCloudAuthentication.hh
//  brainCloudClientObjc
//
//  Created by Ryan Homer on 8/4/2015.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

extern NSString *const AUTH_FACEBOOK;

@interface BrainCloudAuthentication : NSObject

@property(strong, nonatomic) NSString *anonymousID;
@property(strong, nonatomic) NSString *profileID;

// NOT an Objective-C designated initializer
/**
* Initialize - initializes the identity service with the saved
* anonymous installation id and most recently used profile id
*
* @param anonymousId  The anonymous installation id that was generated for this device
* @param profileId The id of the profile id that was most recently used by the app (on this device)
*/
- (void)initialize:(NSString *)profileID anonymousID:(NSString *)anonymousID;

/**
* Generates a GUID for use as an anonymous installation id for brainCloud.  This method is provided
*as a convenience to the
* client application - but clients can override this id with a scheme of their own if they'd like
*(as long as the scheme in place
* generates unique ids per client device).
*
* @returns the id
*/
- (NSString *)generateGUID;

/**
* Used to create the anonymous installation id for the brainCloud profile.
* Normally only called once when the application starts for the first time.
*/
- (void)generateNewAnonymousID;

/**
* Used to clear the saved profile id - to use in cases when the user is
* attempting to switch to a different game profile.
*/
- (void)clearSavedProfile;

/**
* Authenticate a user anonymously with brainCloud - used for apps that don't want to bother
* the user to login, or for users who are sensitive to their privacy
*
* Service Name - Authenticate
* Service Operation - Authenticate
*
* @param forceCreate  Should a new profile be created if it does not exist?
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
*/
- (void)authenticateAnonymous:(BOOL)forceCreate
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                     cbObject:(BCCallbackObject)cbObject;

/**
* Authenticate the user with brainCloud using their Facebook Credentials
*
* Service Name - Authenticate
* Service Operation - Authenticate
*
* @param externalId The facebook id of the user
* @param authenticationToken The validated token from the Facebook SDK
*   (that will be further validated when sent to the bC service)
* @param forceCreate Should a new profile be created for this user if the account does not exist?
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
*/
- (void)authenticateFacebook:(NSString *)externalID
         authenticationToken:(NSString *)authToken
                 forceCreate:(BOOL)forceCreate
             completionBlock:(BCCompletionBlock)completionBlock
        errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                    cbObject:(BCCallbackObject)cbObject;

/**
* Authenticate the user using their Game Center id
*
* Service Name - Authenticate
* Service Operation - Authenticate
*
* @param gameCenterId The player's game center id  (use the playerID property from the local
*GKPlayer object)
* @param forceCreate Should a new profile be created for this user if the account does not exist?
* @param success The method to call in event of successful login
* @param failure The method to call in the event of an error during authentication
*
* @returns   performs the success callback on success, failure callback on failure
*
*/
- (void)authenticateGameCenter:(NSString *)gameCenterID
                   forceCreate:(BOOL)forceCreate
               completionBlock:(BCCompletionBlock)completionBlock
          errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                      cbObject:(BCCallbackObject)cbObject;

/**
* Authenticate the user with a custom Email and Password.  Note that the client app
* is responsible for collecting (and storing) the e-mail and potentially password
* (for convenience) in the client data.  For the greatest security,
* force the user to re-enter their * password at each login.
* (Or at least give them that option).
*
* Note that the password sent from the client to the server is protected via SSL.
*
* Service Name - Authenticate
* Service Operation - Authenticate
*
* @param email  The e-mail address of the user
* @param password  The password of the user
* @param forceCreate Should a new profile be created for this user if the account does not exist?
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
*/
- (void)authenticateEmailPassword:(NSString *)email
                         password:(NSString *)password
                      forceCreate:(BOOL)forceCreate
                  completionBlock:(BCCompletionBlock)completionBlock
             errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                         cbObject:(BCCallbackObject)cbObject;

/**
* Authenticate the user using a userid and password (without any validation on the userid).
* Similar to AuthenticateEmailPassword - except that that method has additional features to
* allow for e-mail validation, password resets, etc.
*
* Service Name - Authenticate
* Service Operation - Authenticate
*
* @param email  The e-mail address of the user
* @param password  The password of the user
* @param forceCreate Should a new profile be created for this user if the account does not exist?
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
*/
- (void)authenticateUniversal:(NSString *)userid
                     password:(NSString *)password
                  forceCreate:(BOOL)forceCreate
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                     cbObject:(BCCallbackObject)cbObject;

/**
* Authenticate the user using a steam userid and session ticket (without any validation on the
*userid).
*
* Service Name - Authenticate
* Service Operation - Authenticate
*
* @param userid  String representation of 64 bit steam id
* @param sessionticket  The session ticket of the user (hex encoded)
* @param forceCreate Should a new profile be created for this user if the account does not exist?
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns   performs the success callback on success, failure callback on failure
*
*/
- (void)authenticateSteam:(NSString *)userID
            sessionTicket:(NSString *)sessionticket
              forceCreate:(BOOL)forceCreate
          completionBlock:(BCCompletionBlock)completionBlock
     errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                 cbObject:(BCCallbackObject)cbObject;

/**
* Authenticate the user using a google userid(email address) and google authentication token.
*
* Service Name - Authenticate
* Service Operation - Authenticate
*
* @param userid  String representation of google+ userid (email)
* @param token  The authentication token derived via the google apis.
* @param forceCreate Should a new profile be created for this user if the account does not exist?
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns   performs the success callback on success, failure callback on failure
*
*/
- (void)authenticateGoogle:(NSString *)userID
                     token:(NSString *)token
               forceCreate:(BOOL)forceCreate
           completionBlock:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                  cbObject:(BCCallbackObject)cbObject;

/**
* Authenticate the user using a Twitter userid, authentication token, and secret from Twitter.
*
* Service Name - Authenticate
* Service Operation - Authenticate
*
* @param userid  String representation of Twitter userid
* @param token  The authentication token derived via the Twitter apis.
* @param secret  The secret given when attempting to link with Twitter
* @param forceCreate Should a new profile be created for this user if the account does not exist?
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns   runs the completion block on success, errorCompletion block on failure
*
*/
- (void)authenticateTwitter:(NSString *)userID
                      token:(NSString *)token
                     secret:(NSString *)secret
                forceCreate:(BOOL)forceCreate
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject;

/*
 * Authenticate the user using a Pase userid and authentication token
 *
 * Service Name - Authenticate
 * Service Operation - Authenticate
 *
 * @param userId String representation of Parse userid
 * @param token The authentication token
 * @param forceCreate Should a new profile be created for this user if the account does not exist?
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @returns   performs the success callback on success, failure callback on failure
 *
 */
- (void)authenticateParse:(NSString *)userID
                    token:(NSString *)token
              forceCreate:(BOOL)forceCreate
          completionBlock:(BCCompletionBlock)cb
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject;

/**
* Reset Email password - Sends a password reset email to the specified address
*
* Service Name - Authenticate
* Operation - ResetEmailPassword
*
* @param externalId The email address to send the reset email to.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data": {}
* }
*
* Note the follow error reason codes:
*
* SECURITY_ERROR (40209) - If the email address cannot be found.
*/
- (void)resetEmailPassword:(NSString *)email
       withCompletionBlock:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                  cbObject:(BCCallbackObject)cbObject;

/**
* Authenticate the user via cloud code (which in turn validates the supplied credentials against an
*external system).
* This allows the developer to extend brainCloud authentication to support other backend
*authentication systems.
*
* Service Name - Authenticate
* Server Operation - Authenticate
*
* @param userid The user id
* @param token The user token (password etc)
* @param externalAuthName The name of the cloud script to call for external authentication
* @param force Should a new profile be created for this user if the account does not exist?
*
* @returns   runs the completion block on success, errorCompletion block on failure
*/
- (void)authenticateExternal:(NSString *)userID
         authenticationToken:(NSString *)authToken
  externalAuthenticationName:(NSString *)externalAuthName
                 forceCreate:(BOOL)forceCreate
             completionBlock:(BCCompletionBlock)completionBlock
        errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                    cbObject:(BCCallbackObject)cbObject;

@end
