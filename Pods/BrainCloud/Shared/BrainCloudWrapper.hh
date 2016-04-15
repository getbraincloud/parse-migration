#import <Foundation/Foundation.h>

#import "BrainCloudClient.hh"

@interface BrainCloudWrapper : NSObject

#pragma mark - Properties

/**
 * The stored anonymous id
 */
@property (copy, nonatomic) NSString *storedAnonymousId;

/**
 * The stored profile id
 */
@property (copy, nonatomic) NSString *storedProfileId;

/**
 * The stored authentication type (unused)
 */
@property (copy, nonatomic) NSString *storedAuthenticationType;

/**
 * For non-anonymous authentication methods, a profile id will be passed in
 * when this value is set to false. This will generate an error on the server
 * if the profile id passed in does not match the profile associated with the
 * authentication credentials. By default, this value is true.
 */
@property (nonatomic) BOOL alwaysAllowProfileSwitch;

/**
 * Method returns a singleton instance of the BrainCloudWrapper.
 * @return A singleton instance of the BrainCloudWrapper.
 */
+ (BrainCloudWrapper *) getInstance;

/**
 * Method returns a singleton instance of the BrainCloudClient.
 * @return A singleton instance of the BrainCloudClient.
 */
+ (BrainCloudClient *) getBC;

/**
 * Method initializes the BrainCloudClient.
 *
 * @param serverUrl The url to the brainCloud server
 * @param secretKey The secret key for your game
 * @param gameId The game id
 * @param gameVersion The game version
 * @param companyName The company name used in the keychain for storing anonymous and profile ids.
 * You are free to pick anything you want.
 * @param gameName The game name used in teh keychain for storing anonymous and profile ids.
 * You are free to pick anything you want.
 */
- (void)initialize:(NSString *)serverUrl
         secretKey:(NSString *)secretKey
            gameId:(NSString *)gameId
       gameVersion:(NSString *)gameVersion
       companyName:(NSString *)companyName
          gameName:(NSString *)gameName;


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
- (void)authenticateAnonymous:(BCCompletionBlock)completionBlock
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
- (void)authenticateExternal:(NSString *)userId
         authenticationToken:(NSString *)authToken
  externalAuthenticationName:(NSString *)externalAuthName
                 forceCreate:(BOOL)forceCreate
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
- (void)authenticateFacebook:(NSString *)externalId
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
- (void)authenticateGameCenter:(NSString *)gameCenterId
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
- (void)authenticateGoogle:(NSString *)userId
                     token:(NSString *)token
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
- (void)authenticateSteam:(NSString *)userId
            sessionTicket:(NSString *)sessionticket
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
- (void)authenticateTwitter:(NSString *)userId
                      token:(NSString *)token
                     secret:(NSString *)secret
                forceCreate:(BOOL)forceCreate
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
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
 * Run callbacks, to be called once per frame from your main thread
 */
- (void)update;

@end
