//
//  BrainCloudPlaybackStream.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-12.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import "BrainCloudPlaybackStream.hh"

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

@implementation BrainCloudPlaybackStream

- (void)startStream:(NSString *)targetPlayerId
       includeSharedData:(bool)includeSharedData
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlaybackStreamService()->startStream(
        [targetPlayerId UTF8String], includeSharedData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readStream:(NSString *)streamId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlaybackStreamService()->readStream(
        [streamId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)endStream:(NSString *)streamId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlaybackStreamService()->endStream(
        [streamId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)deleteStream:(NSString *)streamId
     completionBlock:(BCCompletionBlock)cb
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlaybackStreamService()->deleteStream(
        [streamId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)addEvent:(NSString *)streamId
           jsonEventData:(NSString *)eventData
             jsonSummary:(NSString *)summary
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlaybackStreamService()->addEvent(
        [streamId UTF8String], [eventData UTF8String], [summary UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getStreamSummariesForInitiatingPlayer:(NSString *)playerId
                              completionBlock:(BCCompletionBlock)cb
                         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getPlaybackStreamService()
        ->getStreamSummariesForInitiatingPlayer([playerId UTF8String],
                                                new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getStreamSummariesForTargetPlayer:(NSString *)playerId
                          completionBlock:(BCCompletionBlock)cb
                     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getPlaybackStreamService()
        ->getStreamSummariesForTargetPlayer([playerId UTF8String],
                                            new BrainCloudCallback(cb, ecb, cbObject));
}

@end