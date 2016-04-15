//
//  BrainCloudOneWayMatch.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-11.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

#import "BrainCloudOneWayMatch.hh"

@implementation BrainCloudOneWayMatch

- (void)startMatch:(NSString *)otherPlayerId
              rangeDelta:(int32_t)range
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getOneWayMatchService()->startMatch(
        [otherPlayerId UTF8String], range, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)cancelMatch:(NSString *)playbackStreamId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getOneWayMatchService()->cancelMatch(
        [playbackStreamId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)completeMatch:(NSString *)playbackStreamId
      completionBlock:(BCCompletionBlock)cb
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getOneWayMatchService()->completeMatch(
        [playbackStreamId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

@end
