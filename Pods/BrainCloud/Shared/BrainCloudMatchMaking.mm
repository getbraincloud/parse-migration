//
//  BrainCloudMatchMaking.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-10.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

#import "BrainCloudMatchMaking.hh"

@implementation BrainCloudMatchMaking

- (void)read:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->read(
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)setPlayerRating:(int)rating
        completionBlock:(BCCompletionBlock)cb
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->setPlayerRating(
        rating, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)resetPlayerRating:(BCCompletionBlock)cb
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->resetPlayerRating(
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)incrementPlayerRating:(int)increment
              completionBlock:(BCCompletionBlock)cb
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->incrementPlayerRating(
        increment, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)decrementPlayerRating:(int)decrement
              completionBlock:(BCCompletionBlock)cb
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->decrementPlayerRating(
        decrement, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)turnShieldOn:(BCCompletionBlock)cb
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->turnShieldOn(
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)turnShieldOnFor:(int)minutes
        completionBlock:(BCCompletionBlock)cb
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->turnShieldOnFor(
        minutes, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)turnShieldOff:(BCCompletionBlock)cb
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->turnShieldOff(
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getShieldExpiry:(NSString *)playerId
        completionBlock:(BCCompletionBlock)cb
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->getShieldExpiry(
        [playerId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)findPlayers:(int)rangeDelta
         numMatches:(int)numMatches
    completionBlock:(BCCompletionBlock)cb
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
           cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->findPlayers(
        rangeDelta, numMatches, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)findPlayersWithAttributes:(int)rangeDelta
                       numMatches:(int)numMatches
                   jsonAttributes:(NSString *)jsonAttributes
                  completionBlock:(BCCompletionBlock)cb
             errorCompletionBlock:(BCErrorCompletionBlock)ecb
                         cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->findPlayersWithAttributes(
        rangeDelta, numMatches, [jsonAttributes UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)findPlayersUsingFilter:(int)rangeDelta
                    numMatches:(int)numMatches
               jsonExtraParams:(NSString *)jsonExtraParams
               completionBlock:(BCCompletionBlock)cb
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getMatchmakingService()
        ->findPlayersUsingFilter(rangeDelta, numMatches, [jsonExtraParams UTF8String],
                                     new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)findPlayersWithAttributesUsingFilter:(int)rangeDelta
                                  numMatches:(int)numMatches
                              jsonAttributes:(NSString *)jsonAttributes
                             jsonExtraParams:(NSString *)jsonExtraParams
                             completionBlock:(BCCompletionBlock)cb
                        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->findPlayersWithAttributesUsingFilter(
        rangeDelta, numMatches, [jsonAttributes UTF8String], [jsonExtraParams UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)enableMatchMaking:(BCCompletionBlock)cb
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getMatchmakingService()->enableMatchMaking(
        new BrainCloudCallback(cb, ecb, cbObject));
}

@end
