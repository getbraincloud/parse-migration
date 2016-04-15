//
//  BrainCloudIdentity.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-13.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

#import "BrainCloudIdentity.hh"

@implementation BrainCloudIdentity

- (void)attachFacebookIdentity:(NSString *)facebookId
           authenticationToken:(NSString *)token
               completionBlock:(BCCompletionBlock)cb
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->attachFacebookIdentity(
        [facebookId UTF8String], [token UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)mergeFacebookIdentity:(NSString *)facebookId
          authenticationToken:(NSString *)token
              completionBlock:(BCCompletionBlock)cb
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->mergeFacebookIdentity(
        [facebookId UTF8String], [token UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)detachFacebookIdentity:(NSString *)facebookId
                  continueAnon:(bool)continueAnon
               completionBlock:(BCCompletionBlock)cb
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->detachFacebookIdentity(
        [facebookId UTF8String], continueAnon, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)attachGameCenterIdentity:(NSString *)gameCenterId
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->attachGameCenterIdentity(
        [gameCenterId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)mergeGameCenterIdentity:(NSString *)gameCenterId
                completionBlock:(BCCompletionBlock)cb
           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                       cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->mergeGameCenterIdentity(
        [gameCenterId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)detachGameCenterIdentity:(NSString *)gameCenterId
                    continueAnon:(bool)continueAnon
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->detachGameCenterIdentity(
        [gameCenterId UTF8String], continueAnon, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)attachEmailIdentity:(NSString *)email
        authenticationToken:(NSString *)password
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->attachEmailIdentity(
        [email UTF8String], [password UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)mergeEmailIdentity:(NSString *)email
       authenticationToken:(NSString *)password
           completionBlock:(BCCompletionBlock)cb
      errorCompletionBlock:(BCErrorCompletionBlock)ecb
                  cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->mergeEmailIdentity(
        [email UTF8String], [password UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)detachEmailIdentity:(NSString *)email
               continueAnon:(bool)continueAnon
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->detachEmailIdentity(
        [email UTF8String], continueAnon, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)attachUniversalIdentity:(NSString *)userId
            authenticationToken:(NSString *)password
                completionBlock:(BCCompletionBlock)cb
           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                       cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->attachUniversalIdentity(
        [userId UTF8String], [password UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)mergeUniversaIdentity:(NSString *)userId
          authenticationToken:(NSString *)password
              completionBlock:(BCCompletionBlock)cb
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->mergeUniversalIdentity(
        [userId UTF8String], [password UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)detachUniversalIdentity:(NSString *)userId
                   continueAnon:(bool)continueAnon
                completionBlock:(BCCompletionBlock)cb
           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                       cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->detachUniversalIdentity(
        [userId UTF8String], continueAnon, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)attachSteamIdentity:(NSString *)steamId
        authenticationToken:(NSString *)sessionTicket
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->attachSteamIdentity(
        [steamId UTF8String], [sessionTicket UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)mergeSteamIdentity:(NSString *)steamId
       authenticationToken:(NSString *)sessionTicket
           completionBlock:(BCCompletionBlock)cb
      errorCompletionBlock:(BCErrorCompletionBlock)ecb
                  cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->mergeSteamIdentity(
        [steamId UTF8String], [sessionTicket UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)detachSteamIdentity:(NSString *)steamId
               continueAnon:(bool)continueAnon
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->detachSteamIdentity(
        [steamId UTF8String], continueAnon, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)attachGoogleIdentity:(NSString *)googleId
         authenticationToken:(NSString *)token
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->attachGoogleIdentity(
        [googleId UTF8String], [token UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)mergeGoogleIdentity:(NSString *)googleId
        authenticationToken:(NSString *)token
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->mergeGoogleIdentity(
        [googleId UTF8String], [token UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)detachGoogleIdentity:(NSString *)googleId
                continueAnon:(bool)continueAnon
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->detachGoogleIdentity(
        [googleId UTF8String], continueAnon, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)attachTwitterIdentity:(NSString *)twitterId
          authenticationToken:(NSString *)token
                       secret:(NSString *)secret
              completionBlock:(BCCompletionBlock)cb
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->attachTwitterIdentity(
        [twitterId UTF8String], [token UTF8String], [secret UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)mergeTwitterIdentity:(NSString *)twitterId
         authenticationToken:(NSString *)token
                      secret:(NSString *)secret
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->mergeTwitterIdentity(
        [twitterId UTF8String], [token UTF8String], [secret UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)detachTwitterIdentity:(NSString *)twitterId
                 continueAnon:(bool)continueAnon
              completionBlock:(BCCompletionBlock)cb
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->detachTwitterIdentity(
        [twitterId UTF8String], continueAnon, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)switchToChildProfile:(NSString *)childProfileId
                  childAppId:(NSString *)childAppId
                 forceCreate:(bool)forceCreate
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->switchToChildProfile(
        [childProfileId UTF8String], [childAppId UTF8String], forceCreate,
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)switchToSingletonChildProfile:(NSString *)childAppId
                          forceCreate:(bool)forceCreate
                      completionBlock:(BCCompletionBlock)cb
                 errorCompletionBlock:(BCErrorCompletionBlock)ecb
                             cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getIdentityService()
        ->switchToSingletonChildProfile([childAppId UTF8String], forceCreate,
                                        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)switchToParentProfile:(NSString *)parentLevelName
              completionBlock:(BCCompletionBlock)cb
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->switchToParentProfile(
        [parentLevelName UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getChildProfiles:(bool)includeSummaryData
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getIdentityService()->getChildProfiles(
        includeSummaryData, new BrainCloudCallback(cb, ecb, cbObject));
}

@end
