//
//  BrainCloudGamification.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-12.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import "BrainCloudGamification.hh"

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

#include "TypeHelpers.hh"

@implementation BrainCloudGamification


- (void)readAllGamification:(bool)includeMetaData
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readAllGamification(
        includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readMilestones:(bool)includeMetaData
       completionBlock:(BCCompletionBlock)cb
  errorCompletionBlock:(BCErrorCompletionBlock)ecb
              cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readMilestones(
        includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readAchievements:(bool)includeMetaData
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readAchievements(
        includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readXpLevelsMetaData:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readXpLevelsMetaData(
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readAchievedAchievements:(bool)includeMetaData
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readAchievedAchievements(
        includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readCompletedMilestones:(bool)includeMetaData
                completionBlock:(BCCompletionBlock)cb
           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                       cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readCompletedMilestones(
        includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readInProgressMilestones:(bool)includeMetaData
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readInProgressMilestones(
        includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readMilestonesByCategory:(NSString *)category
                 includeMetaData:(bool)includeMetaData
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readMilestonesByCategory(
        [category UTF8String], includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)awardAchievements:(NSArray *)achievementIds
          completionBlock:(BCCompletionBlock)cb
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->awardAchievements(
        TypeHelpers::NSStringArrayToVector(achievementIds), new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)resetMilestones:(NSArray *)milestoneIds
        completionBlock:(BCCompletionBlock)cb
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->resetMilestones(
        TypeHelpers::NSStringArrayToVector(milestoneIds), new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readQuests:(bool)includeMetaData
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readQuests(
        includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readCompletedQuests:(bool)includeMetaData
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readCompletedQuests(
        includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readInProgressQuests:(bool)includeMetaData
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readInProgressQuests(
        includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readNotStartedQuests:(bool)includeMetaData
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readNotStartedQuests(
        includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readQuestsWithStatus:(bool)includeMetaData
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readQuestsWithStatus(
        includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readQuestsWithBasicPercentage:(bool)includeMetaData
                      completionBlock:(BCCompletionBlock)cb
                 errorCompletionBlock:(BCErrorCompletionBlock)ecb
                             cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getGamificationService()
        ->readQuestsWithBasicPercentage(includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readQuestsWithComplexPercentage:(bool)includeMetaData
                        completionBlock:(BCCompletionBlock)cb
                   errorCompletionBlock:(BCErrorCompletionBlock)ecb
                               cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getGamificationService()
        ->readQuestsWithComplexPercentage(includeMetaData,
                                          new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readQuestsByCategory:(NSString *)category
             includeMetaData:(bool)includeMetaData
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGamificationService()->readQuestsByCategory(
        [category UTF8String], includeMetaData, new BrainCloudCallback(cb, ecb, cbObject));
}

@end