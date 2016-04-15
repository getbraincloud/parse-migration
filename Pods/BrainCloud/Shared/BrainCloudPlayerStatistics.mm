//
//  BrainCloudPlayerStatistics.mm
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-06.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"
#import "TypeHelpers.hh"

#import "BrainCloudPlayerStatistics.hh"

@implementation BrainCloudPlayerStatistics

- (void)readAllPlayerStats:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)ecb
                  cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStatisticsService()->readAllPlayerStats(
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)readPlayerStatsSubset:(NSArray *)playerStats
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getPlayerStatisticsService()
    ->readPlayerStatsSubset(TypeHelpers::NSStringArrayToVector(playerStats),
                                new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)readPlayerStatsForCategory:(NSString *)category
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getPlayerStatisticsService()
        ->readPlayerStatsForCategory([category UTF8String],
                                     new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)resetAllPlayerStats:(BCCompletionBlock)completionBlock
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStatisticsService()->resetAllPlayerStats(
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)incrementPlayerStats:(NSString *)jsonData
             completionBlock:(BCCompletionBlock)completionBlock
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStatisticsService()->incrementPlayerStats(
        [jsonData UTF8String], new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getNextExperienceLevel:(BCCompletionBlock)completionBlock
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getPlayerStatisticsService()
        ->getNextExperienceLevel(new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)incrementExperiencePoints:(int)xpValue
                  completionBlock:(BCCompletionBlock)completionBlock
             errorCompletionBlock:(BCErrorCompletionBlock)ecb
                         cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getPlayerStatisticsService()
        ->incrementExperiencePoints(xpValue,
                                    new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)setExperiencePoints:(int)xpValue
            completionBlock:(BCCompletionBlock)completionBlock
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getPlayerStatisticsService()->setExperiencePoints(
        xpValue, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

@end
