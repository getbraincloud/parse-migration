//
//  BrainCloudPlayerStatisticsEvent.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-12.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

#import "BrainCloudPlayerStatisticsEvent.hh"

@implementation BrainCloudPlayerStatisticsEvent

- (void)triggerPlayerStatisticsEvent:(NSString *)eventName
                     eventMultiplier:(int)multiplier
                     completionBlock:(BCCompletionBlock)cb
                errorCompletionBlock:(BCErrorCompletionBlock)ecb
                            cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getPlayerStatisticsEventService()
        ->triggerPlayerStatisticsEvent([eventName UTF8String], multiplier,
                                       new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)triggerPlayerStatisticsEvents:(NSString *)jsonData
                      completionBlock:(BCCompletionBlock)cb
                 errorCompletionBlock:(BCErrorCompletionBlock)ecb
                             cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getPlayerStatisticsEventService()
        ->triggerPlayerStatisticsEvents([jsonData UTF8String],
                                        new BrainCloudCallback(cb, ecb, cbObject));
}

@end