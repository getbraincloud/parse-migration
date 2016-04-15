//
//  BrainCloudGlobalStatistics.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-06.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"
#import "TypeHelpers.hh"

#import "BrainCloudGlobalStatistics.hh"

@implementation BrainCloudGlobalStatistics

- (void)readAllGlobalStats:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)ecb
                  cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGlobalStatisticsService()->readAllGlobalStats(
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)readGlobalStatsSubset:(NSArray *)globalStats
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getGlobalStatisticsService()
    ->readGlobalStatsSubset(TypeHelpers::NSStringArrayToVector(globalStats),
                                new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)readGlobalStatsForCategory:(NSString *)category
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getGlobalStatisticsService()
        ->readGlobalStatsForCategory([category UTF8String],
                                   new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)incrementGlobalStats:(NSString *)jsonData
             completionBlock:(BCCompletionBlock)completionBlock
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getGlobalStatisticsService()
        ->incrementGlobalGameStat([jsonData UTF8String],
                                  new BrainCloudCallback(completionBlock, ecb, cbObject));
}

@end