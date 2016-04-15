//
//  BrainCloudAsyncMatch.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-10.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import "BrainCloudAsyncMatch.hh"

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

@implementation BrainCloudAsyncMatch

- (void)createMatch:(NSString *)jsonOpponentIds
    pushNotificationMessage:(NSString *)pushMessage
                    matchId:(NSString *)matchId
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->createMatch(
        [jsonOpponentIds UTF8String], [pushMessage UTF8String], [matchId UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

//deprecated
- (void)createMatch:(NSString *)jsonOpponentIds
    pushNotificationMessage:(NSString *)pushMessage
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->createMatch(
        [jsonOpponentIds UTF8String], [pushMessage UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)createMatchWithInitialTurn:(NSString *)jsonOpponentIds
                    jsonMatchState:(NSString *)matchState
           pushNotificationMessage:(NSString *)pushMessage
                        nextPlayer:(NSString *)nextPlayer
                       jsonSummary:(NSString *)summary
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->createMatchWithInitialTurn(
        [jsonOpponentIds UTF8String], [matchState UTF8String], [pushMessage UTF8String],
        [nextPlayer UTF8String], [summary UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

// deprecated
- (void)createMatchWithInitialTurn:(NSString *)jsonOpponentIds
                    jsonMatchState:(NSString *)matchState
           pushNotificationMessage:(NSString *)pushMessage
                           matchId:(NSString *)matchId
                        nextPlayer:(NSString *)nextPlayer
                       jsonSummary:(NSString *)summary
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->createMatchWithInitialTurn(
        [jsonOpponentIds UTF8String], [matchState UTF8String], [pushMessage UTF8String],
        [matchId UTF8String], [nextPlayer UTF8String], [summary UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)submitTurn:(NSString *)ownerId
                    matchId:(NSString *)matchId
                    version:(uint64_t)version
             jsonMatchState:(NSString *)matchState
    pushNotificationMessage:(NSString *)pushMessage
                 nextPlayer:(NSString *)nextPlayer
                jsonSummary:(NSString *)summary
             jsonStatistics:(NSString *)stats
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->submitTurn(
        [ownerId UTF8String], [matchId UTF8String], version, [matchState UTF8String],
        [pushMessage UTF8String], [nextPlayer UTF8String], [summary UTF8String], [stats UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)updateMatchSummaryData:(NSString *)ownerId
                       matchId:(NSString *)matchId
                       version:(uint64_t)version
                   jsonSummary:(NSString *)summary
               completionBlock:(BCCompletionBlock)cb
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->updateMatchSummaryData(
        [ownerId UTF8String], [matchId UTF8String], version, [summary UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)completeMatch:(NSString *)ownerId
              matchId:(NSString *)matchId
      completionBlock:(BCCompletionBlock)cb
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->completeMatch(
        [ownerId UTF8String], [matchId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readMatch:(NSString *)ownerId
                 matchId:(NSString *)matchId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->readMatch(
        [ownerId UTF8String], [matchId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)abandonMatch:(NSString *)ownerId
             matchId:(NSString *)matchId
     completionBlock:(BCCompletionBlock)cb
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->abandonMatch(
        [ownerId UTF8String], [matchId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)deleteMatch:(NSString *)ownerId
                 matchId:(NSString *)matchId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->deleteMatch(
        [ownerId UTF8String], [matchId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readMatchHistory:(NSString *)ownerId
                 matchId:(NSString *)matchId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->readMatchHistory(
        [ownerId UTF8String], [matchId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)findMatches:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->findMatches(
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)findCompleteMatches:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getAsyncMatchService()->findCompleteMatches(
        new BrainCloudCallback(cb, ecb, cbObject));
}

@end