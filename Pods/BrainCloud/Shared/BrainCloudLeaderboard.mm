//
//  BrainCloudLeaderboard.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-07.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#include <vector>
#include <string>

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

#import "BrainCloudLeaderboard.hh"

@implementation BrainCloudLeaderboard

- (void)getSocialLeaderboard:(NSString *)leaderboardId
           replaceName:(bool)replaceName
       completionBlock:(BCCompletionBlock)cb
  errorCompletionBlock:(BCErrorCompletionBlock)ecb
              cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getSocialLeaderboardService()->getSocialLeaderboard(
        [leaderboardId UTF8String], replaceName, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getMultiSocialLeaderboard:(NSArray *)leaderboardIds
           leaderboardResultCount:(NSInteger)leaderboardResultCount
                      replaceName:(bool)replaceName
                  completionBlock:(BCCompletionBlock)cb
             errorCompletionBlock:(BCErrorCompletionBlock)ecb
                         cbObject:(BCCallbackObject)cbObject
{
    std::vector<std::string> lbIds;
    for (NSString * nsid in leaderboardIds)
    {
        std::string lbId = [nsid UTF8String];
        lbIds.push_back(lbId);
    }
    BrainCloud::BrainCloudClient::getInstance()->getSocialLeaderboardService()->getMultiSocialLeaderboard(
        lbIds, (int) leaderboardResultCount, replaceName, new BrainCloudCallback(cb, ecb, cbObject));
}


- (void)getGlobalLeaderboardPage:(NSString *)leaderboardId
                       sortOrder:(SortOrder)sortOrder
                      startIndex:(int)startIndex
                        endIndex:(int)endIndex
          includeLeaderboardSize:(bool)includeLeaderboardSize
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getSocialLeaderboardService()
        ->getGlobalLeaderboardPage([leaderboardId UTF8String], (BrainCloud::SortOrder)sortOrder,
                                   startIndex, endIndex, includeLeaderboardSize,
                                   new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getGlobalLeaderboardPageByVersion:(NSString *)leaderboardId
                                sortOrder:(SortOrder)sortOrder
                               startIndex:(int)startIndex
                                 endIndex:(int)endIndex
                   includeLeaderboardSize:(bool)includeLeaderboardSize
                                versionId:(int)versionId
                          completionBlock:(BCCompletionBlock)cb
                     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getSocialLeaderboardService()
        ->getGlobalLeaderboardPageByVersion(
            [leaderboardId UTF8String], (BrainCloud::SortOrder)sortOrder, startIndex, endIndex,
            includeLeaderboardSize, versionId, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getGlobalLeaderboardView:(NSString *)leaderboardId
                       sortOrder:(SortOrder)sortOrder
                     beforeCount:(int)beforeCount
                      afterCount:(int)afterCount
          includeLeaderboardSize:(bool)includeLeaderboardSize
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getSocialLeaderboardService()
        ->getGlobalLeaderboardView([leaderboardId UTF8String], (BrainCloud::SortOrder)sortOrder,
                                   beforeCount, afterCount, includeLeaderboardSize,
                                   new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getGlobalLeaderboardViewByVersion:(NSString *)leaderboardId
                                sortOrder:(SortOrder)sortOrder
                              beforeCount:(int)beforeCount
                               afterCount:(int)afterCount
                   includeLeaderboardSize:(bool)includeLeaderboardSize
                                versionId:(int)versionId
                          completionBlock:(BCCompletionBlock)cb
                     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getSocialLeaderboardService()
        ->getGlobalLeaderboardViewByVersion(
            [leaderboardId UTF8String], (BrainCloud::SortOrder)sortOrder, beforeCount, afterCount,
            includeLeaderboardSize, versionId, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getGlobalLeaderboardVersions:(NSString *)leaderboardId
                     completionBlock:(BCCompletionBlock)cb
                errorCompletionBlock:(BCErrorCompletionBlock)ecb
                            cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getSocialLeaderboardService()
        ->getGlobalLeaderboardVersions([leaderboardId UTF8String],
                                       new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)postScoreToLeaderboard:(NSString *)leaderboardId
                         score:(int)score
                 jsonOtherData:(NSString *)jsonOtherData
               completionBlock:(BCCompletionBlock)cb
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getSocialLeaderboardService()
        ->postScoreToLeaderboard([leaderboardId UTF8String], score, [jsonOtherData UTF8String],
                                 new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)postScoreToDynamicLeaderboard:(NSString *)leaderboardId
                                score:(int)score
                             jsonData:(NSString *)jsonData
                      leaderboardType:(LeaderboardType)leaderboardType
                         rotationType:(RotationType)rotationType
                       roatationReset:(NSDate *)rotationReset
                        retainedCount:(int)retainedCount
                      completionBlock:(BCCompletionBlock)cb
                 errorCompletionBlock:(BCErrorCompletionBlock)ecb
                             cbObject:(BCCallbackObject)cbObject
{
    time_t time = [rotationReset timeIntervalSince1970];
    struct tm *timeStruct = localtime(&time);

    BrainCloud::BrainCloudClient::getInstance()
        ->getSocialLeaderboardService()
        ->postScoreToDynamicLeaderboard([leaderboardId UTF8String], score, [jsonData UTF8String],
                                        (BrainCloud::SocialLeaderboardType)leaderboardType,
                                        (BrainCloud::RotationType)rotationType, timeStruct,
                                        retainedCount, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)resetLeaderboardScore:(NSString *)leaderboardId
              completionBlock:(BCCompletionBlock)cb
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getSocialLeaderboardService()
        ->resetLeaderboardScore([leaderboardId UTF8String],
                                new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getCompletedLeaderboardTournament:(NSString *)leaderboardId
                              replaceName:(bool)replaceName
                          completionBlock:(BCCompletionBlock)cb
                     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getSocialLeaderboardService()
        ->getCompletedLeaderboardTournament([leaderboardId UTF8String], replaceName,
                                            new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)triggerSocialLeaderboardTournamentReward:(NSString *)leaderboardId
                                       eventName:(NSString *)eventName
                                 eventMultiplier:(uint64_t)eventMultiplier
                                 completionBlock:(BCCompletionBlock)cb
                            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                        cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getSocialLeaderboardService()
        ->triggerSocialLeaderboardTournamentReward([leaderboardId UTF8String],
                                                   [eventName UTF8String], eventMultiplier,
                                                   new BrainCloudCallback(cb, ecb, cbObject));
}

@end