//
//  BrainCloudDataStream.m
//  brainCloudClientObjc
//
//  Created by Preston Jennings on 2015-11-26.
//  Copyright © 2015 bitHeads. All rights reserved.
//

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

#import "BrainCloudDataStream.hh"

@implementation BrainCloudDataStream

- (void)customPageEvent:(NSString *)eventName
    jsonEventProperties:(NSString *)jsonEventProperties
        completionBlock:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
    ->getDataStreamService()->customPageEvent(
                                              [eventName UTF8String],
                                              [jsonEventProperties UTF8String],
                                              new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)customScreenEvent:(NSString *)eventName
      jsonEventProperties:(NSString *)jsonEventProperties
          completionBlock:(BCCompletionBlock)completionBlock
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
    ->getDataStreamService()->customScreenEvent(
                                                [eventName UTF8String],
                                                [jsonEventProperties UTF8String],
                                                new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)customTrackEvent:(NSString *)eventName
     jsonEventProperties:(NSString *)jsonEventProperties
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
    ->getDataStreamService()->customTrackEvent(
                                               [eventName UTF8String],
                                               [jsonEventProperties UTF8String],
                                               new BrainCloudCallback(completionBlock, ecb, cbObject));
}

@end