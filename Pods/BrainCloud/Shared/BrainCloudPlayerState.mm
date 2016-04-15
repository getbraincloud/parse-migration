//
//  BrainCloudPlayerState.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-06.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"
#import "TypeHelpers.hh"

#import "BrainCloudPlayerState.hh"

@implementation BrainCloudPlayerState

- (void)readPlayerState:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStateService()->readPlayerState(
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)deletePlayer:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStateService()->deletePlayer(
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)resetPlayerState:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStateService()->resetPlayerState(
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)logout:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStateService()->logout(
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)updatePlayerName:(NSString *)playerName
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStateService()->updatePlayerName(
        [playerName UTF8String], new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getAttributes:(BCCompletionBlock)completionBlock
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStateService()->getAttributes(
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)updateAttributes:(NSString *)jsonAttributes
            wipeExisting:(bool)wipeExisting
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStateService()->updateAttributes(
        [jsonAttributes UTF8String], wipeExisting,
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)removeAttributes:(NSArray *)attributeNames
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStateService()->removeAttributes(
        TypeHelpers::NSStringArrayToVector(attributeNames), new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)updatePlayerPictureUrl:(NSString *)pictureUrl
               completionBlock:(BCCompletionBlock)completionBlock
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStateService()->updatePlayerPictureUrl(
        [pictureUrl UTF8String], new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)updateContactEmail:(NSString *)contactEmail
           completionBlock:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)ecb
                  cbObject:(BCCallbackObject)cbObject
{
        BrainCloud::BrainCloudClient::getInstance()->getPlayerStateService()->updateContactEmail(
        [contactEmail UTF8String], new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)updateSummaryFriendData:(NSString *)jsonSummaryData
                completionBlock:(BCCompletionBlock)cb
           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                       cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStateService()->updateSummaryFriendData(
        [jsonSummaryData UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

@end
