//
//  BrainCloudPushNotification.mm
//  brainCloudClientObjc
//
//  Created by Ryan Homer on 2/5/2015.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import "BrainCloudPushNotification.hh"
#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"
#import "PlatformObjc.hh"
#include "Platform.h"

@implementation BrainCloudPushNotification

- (void)deregisterAllPushNotificationDeviceTokens:(BCCompletionBlock)cb
                             errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                         cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback = new BrainCloudCallback(cb, ecb, cbObject);
    
    BrainCloud::BrainCloudClient::getInstance()
    ->getPushNotificationService()
    ->deregisterAllPushNotificationDeviceTokens(brainCloudCallback);
}

- (void)deregisterPushNotificationDeviceToken:(PlatformObjc *) platform
                                  deviceToken:(NSString *)deviceToken
                              completionBlock:(BCCompletionBlock)cb
                         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback = new BrainCloudCallback(cb, ecb, cbObject);
    
    std::string platformStr = [[platform toString] UTF8String];
    BrainCloud::Platform cppPlatform = BrainCloud::Platform::fromString(platformStr);
    BrainCloud::BrainCloudClient::getInstance()
    ->getPushNotificationService()
    ->deregisterPushNotificationDeviceToken(cppPlatform,
                                            [deviceToken cStringUsingEncoding:NSUTF8StringEncoding],
                                            brainCloudCallback);
}

- (void)registerPushNotificationDeviceToken:(PlatformObjc *)platform
                                deviceToken:(NSString *)deviceToken
                            completionBlock:(BCCompletionBlock)cb
                       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback = new BrainCloudCallback(cb, ecb, cbObject);

    BrainCloud::BrainCloudClient::getInstance()
        ->getPushNotificationService()
        ->registerPushNotificationDeviceToken(
            [[platform toString] UTF8String], [deviceToken cStringUsingEncoding:NSUTF8StringEncoding],
            brainCloudCallback);
}

- (void)registerPushNotificationDeviceTokenData:(PlatformObjc *) platform
                                    deviceToken:(NSData *)deviceToken
                                completionBlock:(BCCompletionBlock)cb
                           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                       cbObject:(BCCallbackObject)cbObject
{
    const uint32_t * tokenBytes = (const uint32_t *) [deviceToken bytes];
    NSString * nsDeviceToken = [NSString stringWithFormat:@"%08x%08x%08x%08x%08x%08x%08x%08x",
                                ntohl(tokenBytes[0]), ntohl(tokenBytes[1]), ntohl(tokenBytes[2]),
                                ntohl(tokenBytes[3]), ntohl(tokenBytes[4]), ntohl(tokenBytes[5]),
                                ntohl(tokenBytes[6]), ntohl(tokenBytes[7])];
    [self registerPushNotificationDeviceToken:platform deviceToken:nsDeviceToken completionBlock:cb
        errorCompletionBlock:ecb cbObject:cbObject];
}

- (void)sendSimplePushNotification:(NSString *)toPlayerId
                           message:(NSString *)message
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback = new BrainCloudCallback(cb, ecb, cbObject);

    BrainCloud::BrainCloudClient::getInstance()
        ->getPushNotificationService()
        ->sendSimplePushNotification([toPlayerId UTF8String], [message UTF8String],
                                     brainCloudCallback);
}

- (void)sendRichPushNotification:(NSString *)toPlayerId
          notificationTemplateId:(int)notificationTemplateId
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback = new BrainCloudCallback(cb, ecb, cbObject);

    BrainCloud::BrainCloudClient::getInstance()
        ->getPushNotificationService()
        ->sendRichPushNotification([toPlayerId UTF8String], notificationTemplateId,
                                   brainCloudCallback);
}

- (void)sendRichPushNotificationWithParams:(NSString *)toPlayerId
                    notificationTemplateId:(int)notificationTemplateId
                          substitutionJson:(NSString*)substitutionJson
                           completionBlock:(BCCompletionBlock)cb
                      errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                  cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *brainCloudCallback = new BrainCloudCallback(cb, ecb, cbObject);
    
    BrainCloud::BrainCloudClient::getInstance()
    ->getPushNotificationService()
    ->sendRichPushNotificationWithParams([toPlayerId UTF8String], notificationTemplateId,
                                [substitutionJson UTF8String], brainCloudCallback);
}

@end
