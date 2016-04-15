//
//  BrainCloudAuthentication.mm
//  brainCloudClientObjc
//
//  Created by Ryan Homer on 8/4/2015.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import "BrainCloudAuthentication.hh"

#include "ServiceName.h"
#include "ServiceOperation.h"
#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"


@implementation BrainCloudAuthentication

- (NSString *)profileID
{
    const char* str = BrainCloud::BrainCloudClient::getInstance()
    ->getAuthenticationService()
    ->getProfileId()
    .c_str();
    
    return [NSString stringWithUTF8String:str];
}

- (NSString *)anonymousID
{
    const char* str = BrainCloud::BrainCloudClient::getInstance()
    ->getAuthenticationService()
    ->getAnonymousId()
    .c_str();
    
    return [NSString stringWithUTF8String:str];
}

- (void)initialize:(NSString *)profileID anonymousID:(NSString *)anonymousID
{
    BrainCloud::BrainCloudClient::getInstance()->getAuthenticationService()->initialize(
        [profileID UTF8String], [anonymousID UTF8String]);
}

- (NSString *)generateGUID { return [NSUUID UUID].UUIDString; }

- (void)generateNewAnonymousID
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getAuthenticationService()
        ->generateNewAnonymousId();
}

- (void)clearSavedProfile
{
    BrainCloud::BrainCloudClient::getInstance()->getAuthenticationService()->clearSavedProfileId();
}

- (void)authenticateAnonymous:(BOOL)forceCreate
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAuthenticationService()->authenticateAnonymous(
        forceCreate, new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject));
}

- (void)authenticateFacebook:(NSString *)externalID
         authenticationToken:(NSString *)authToken
                 forceCreate:(BOOL)forceCreate
             completionBlock:(BCCompletionBlock)completionBlock
        errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getAuthenticationService()->authenticateFacebook(
        [externalID cStringUsingEncoding:NSUTF8StringEncoding],
        [authToken cStringUsingEncoding:NSUTF8StringEncoding], forceCreate, brainCloudCallback);
}

- (void)authenticateGameCenter:(NSString *)gameCenterID
                   forceCreate:(BOOL)forceCreate
               completionBlock:(BCCompletionBlock)completionBlock
          errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                      cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getAuthenticationService()->authenticateGameCenter(
        [gameCenterID cStringUsingEncoding:NSUTF8StringEncoding], forceCreate, brainCloudCallback);
}

- (void)authenticateEmailPassword:(NSString *)email
                         password:(NSString *)password
                      forceCreate:(BOOL)forceCreate
                  completionBlock:(BCCompletionBlock)completionBlock
             errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                         cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()
        ->getAuthenticationService()
        ->authenticateEmailPassword([email cStringUsingEncoding:NSUTF8StringEncoding],
                                    [password cStringUsingEncoding:NSUTF8StringEncoding],
                                    forceCreate, brainCloudCallback);
}

- (void)authenticateUniversal:(NSString *)userid
                     password:(NSString *)password
                  forceCreate:(BOOL)forceCreate
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getAuthenticationService()->authenticateUniversal(
        [userid cStringUsingEncoding:NSUTF8StringEncoding],
        [password cStringUsingEncoding:NSUTF8StringEncoding], forceCreate, brainCloudCallback);
}

- (void)authenticateSteam:(NSString *)userID
            sessionTicket:(NSString *)sessionticket
              forceCreate:(BOOL)forceCreate
          completionBlock:(BCCompletionBlock)completionBlock
     errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getAuthenticationService()->authenticateSteam(
        [userID cStringUsingEncoding:NSUTF8StringEncoding],
        [sessionticket cStringUsingEncoding:NSUTF8StringEncoding], forceCreate, brainCloudCallback);
}

- (void)authenticateGoogle:(NSString *)userID
                     token:(NSString *)token
               forceCreate:(BOOL)forceCreate
           completionBlock:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                  cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getAuthenticationService()->authenticateGoogle(
        [userID cStringUsingEncoding:NSUTF8StringEncoding],
        [token cStringUsingEncoding:NSUTF8StringEncoding], forceCreate, brainCloudCallback);
}

- (void)authenticateTwitter:(NSString *)userID
                      token:(NSString *)token
                     secret:(NSString *)secret
                forceCreate:(BOOL)forceCreate
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAuthenticationService()->authenticateTwitter(
        [userID UTF8String], [token UTF8String], [secret UTF8String], forceCreate,
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)authenticateParse:(NSString *)userID
                    token:(NSString *)token
              forceCreate:(BOOL)forceCreate
          completionBlock:(BCCompletionBlock)cb
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAuthenticationService()->authenticateParse(
        [userID UTF8String], [token UTF8String], forceCreate,
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)resetEmailPassword:(NSString *)email
       withCompletionBlock:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                  cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getAuthenticationService()->resetEmailPassword(
        [email cStringUsingEncoding:NSUTF8StringEncoding], brainCloudCallback);
}

- (void)authenticateExternal:(NSString *)userID
         authenticationToken:(NSString *)authToken
  externalAuthenticationName:(NSString *)externalAuthName
                 forceCreate:(BOOL)forceCreate
             completionBlock:(BCCompletionBlock)completionBlock
        errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getAuthenticationService()->authenticateExternal(
        [userID cStringUsingEncoding:NSUTF8StringEncoding],
        [authToken cStringUsingEncoding:NSUTF8StringEncoding],
        [externalAuthName cStringUsingEncoding:NSUTF8StringEncoding], forceCreate,
        brainCloudCallback);
}

@end