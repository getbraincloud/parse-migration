//
//  BrainCloudGamification.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-12.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudGamification : NSObject

/**
* Method retrieves all gamification data for the player.
*
* Service Name - Gamification
* Service Operation - Read
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
*
* {
*  "status": 200,
*  "data": {
*   "milestones": [
*    {
*     "id": "milestone02",
*     "category": "general",
*     "title": "Level 2 milestone",
*     "status": "SATISFIED",
*     "description": "Awarded when you get to level 2",
*     "gameId": "10068",
*     "rewards": {
*      "currency": {
*       "gold": 1000
*      }
*     },
*     "extraData": null,
*     "questId": null,
*     "milestoneId": "milestone02"
*    },
*    {
*     "id": "milestone01",
*     "thresholds": {
*      "playerStatistics": {
*       "experiencePoints": 0
*      }
*     },
*     "category": "general",
*     "title": "Level 1 milestone",
*     "status": "SATISFIED",
*     "description": "Awarded when you get to player level 1",
*     "gameId": "10068",
*     "rewards": {
*      "currency": {
*       "gems": 10
*      }
*     },
*     "extraData": null,
*     "questId": null,
*     "milestoneId": "milestone01"
*    }
*   ],
*   "achievements": [
*    {
*     "fbEnabled": true,
*     "imageUrl": null,
*     "status": "NOT_AWARDED",
*     "gameId": "10068",
*     "steamEnabled": false,
*     "extraData": null,
*     "achievementId": "ach01",
*     "invisibleUntilEarned": false,
*     "steamAchievementId": "",
*     "id": "ach01",
*     "appleEnabled": false,
*     "title": "Finish Tutorial",
*     "fbGamePoints": 10,
*     "description": "Achievement awarded when you finish the tutorial",
*     "appleAchievementId": ""
*    },
*    {
*     "fbEnabled": true,
*     "imageUrl": null,
*     "status": "NOT_AWARDED",
*     "gameId": "10068",
*     "steamEnabled": false,
*     "extraData": null,
*     "achievementId": "ach02",
*     "invisibleUntilEarned": false,
*     "steamAchievementId": "",
*     "id": "ach02",
*     "appleEnabled": false,
*     "title": "Level up",
*     "fbGamePoints": 10,
*     "description": "Awarded when you level up for the first time!",
*     "appleAchievementId": ""
*    }
*   ],
*   "quests": [],
*   "xp": {
*    "xpCapped": false,
*    "experiencePoints": 0,
*    "xpLevel": {
*     "gameId": "10068",
*     "level": 0,
*     "statusTitle": "Lesser",
*     "experience": 0,
*     "fbAction": ""
*    },
*    "experienceLevel": 0
*   }
*  }
* }
*/
- (void)readAllGamification:(bool)includeMetaData
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject;

/**
* Method retrieves all milestones defined for the game.
*
* Service Name - Gamification
* Service Operation - ReadMilestones
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data": {
*     "milestones": [
*       {
*         "gameId": "com.bitheads.unityexample",
*         "milestoneId": "milestone01",
*         "playerStatistics": {
*           "experiencePoints": null,
*           "experienceLevel": null,
*           "empty": true,
*           "statistics": {}
*         },
*         "globalStatistics": {
*           "statistics": {},
*           "empty": true
*         },
*         "playerStatisticsUnlockThresholds": {
*           "experiencePoints": null,
*           "experienceLevel": null,
*           "empty": true,
*           "statistics": {}
*         },
*         "globalStatisticsUnlockThresholds": {
*           "statistics": {},
*           "empty": true
*         },
*         "reward": {
*           "experiencePoints": null,
*           "playerStatistics": null,
*           "currencies": {
*             "gems": 10
*           },
*           "globalGameStatistics": null,
*           "achievement": null
*         },
*         "title": "Level 1 milestone",
*         "extraData": null,
*         "description": "Awarded when you get to player level 1",
*         "category": "general",
*         "key": {
*           "gameId": "com.bitheads.unityexample",
*           "milestoneId": "milestone01",
*           "primaryKey": true
*         }
*       }
*     ]
*   }
* }
*/
- (void)readMilestones:(bool)includeMetaData
       completionBlock:(BCCompletionBlock)cb
  errorCompletionBlock:(BCErrorCompletionBlock)ecb
              cbObject:(BCCallbackObject)cbObject;

/**
* Read all of the achievements defined for the game.
*
* Service Name - Gamification
* Service Operation - ReadAchievements
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data": {
*     "achievements": [
*       {
*         "gameId": "com.bitheads.unityexample",
*         "achievementId": "ach01",
*         "facebookUrl": "http://someurl.com",
*         "title": "Finish Tutorial",
*         "imageUrl": "http://someurl.com",
*         "facebookGamePoints": 10,
*         "extraData": null,
*         "invisibleUntilEarned": null,
*         "description": "Achievement awarded when you finish the tutorial",
*         "key": {
*           "gameId": "com.bitheads.unityexample",
*           "achievementId": "ach01",
*           "primaryKey": true
*         }
*       },
*       {
*         "gameId": "com.bitheads.unityexample",
*         "achievementId": "ach02",
*         "facebookUrl": "http://someurl.com",
*         "title": "Level up",
*         "imageUrl": "http://someurl.com",
*         "facebookGamePoints": 10,
*         "extraData": null,
*         "invisibleUntilEarned": null,
*         "description": "Awarded when you level up for the first time.",
*         "key": {
*           "gameId": "com.bitheads.unityexample",
*           "achievementId": "ach02",
*           "primaryKey": true
*         }
*       }
*     ]
*   }
* }
*/
- (void)readAchievements:(bool)includeMetaData
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Method returns all defined xp levels and any rewards associated
* with those xp levels.
*
* Service Name - Gamification
* Service Operation - ReadXpLevels
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*  "status": 200,
*  "data": {
*   "xp_levels": [
*    {
*     "level": 1,
*     "statusTitle": "Peon",
*     "experience": 0,
*     "fbAction": ""
*    },
*    {
*     "level": 2,
*     "statusTitle": "Small Fry",
*     "experience": 1000,
*     "fbAction": "",
*     "reward": {
*      "currency": {
*       "gold": 500
*      }
*     }
*    }
*   ]
*  }
* }
*/
- (void)readXpLevelsMetaData:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject;

/**
* Method retrives the list of achieved achievements.
*
* Service Name - Gamification
* Service Operation - ReadAchievedAchievements
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
*  {
*   "status": 200,
*   "data": {
*     "achievements": []
*   }
* }
*/
- (void)readAchievedAchievements:(bool)includeMetaData
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject;

/**
* Method retrieves the list of completed milestones.
*
* Service Name - Gamification
* Service Operation - ReadCompleteMilestones
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data": {
*     "milestones": []
*   }
* }
*/
- (void)readCompletedMilestones:(bool)includeMetaData
                completionBlock:(BCCompletionBlock)cb
           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                       cbObject:(BCCallbackObject)cbObject;

/**
* Method retrieves the list of in progress milestones
*
* Service Name - Gamification
* Service Operation - ReadInProgressMilestones
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
*  {
*   "status": 200,
*   "data": {
*     "milestones": []
*   }
* }
*/
- (void)readInProgressMilestones:(bool)includeMetaData
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject;

/**
* Method retrieves milestones of the given category.
*
* Service Name - Gamification
* Service Operation - ReadMilestonesByCategory
*
* @param category The milestone category
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":{
*     "milestones": []
*   }
* }
*/
- (void)readMilestonesByCategory:(NSString *)category
                 includeMetaData:(bool)includeMetaData
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject;

/**
* Method will award the achievements specified. On success, this will
* call AwardThirdPartyAchievement to hook into the client-side Achievement
* service (ie GameCentre, Facebook etc).
*
* Service Name - Gamification
* Service Operation - AwardAchievements
*
* @param achievementIds A NSString array of achievement ids to award
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":null
* }
*/
- (void)awardAchievements:(NSArray*) achievementIds
          completionBlock:(BCCompletionBlock)cb
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject;

/**
* Resets the specified milestones' statuses to LOCKED.
*
* Service Name - Gamification
* Service Operation - ResetMilestones
*
* @param milestoneIds A NSString array of milestones to reset
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows.
* {
*   "status":200,
*   "data":null
* }
*/
- (void)resetMilestones:(NSArray *)milestoneIds
        completionBlock:(BCCompletionBlock)cb
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject;

/**
* Method retrieves all of the quests defined for the game.
*
* Service Name - Gamification
* Service Operation - ReadQuests
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":null
* }
*
*
*  {
*   "status": 200,
*   "data": {
*     "quests": []
*   }
* }
*/
- (void)readQuests:(bool)includeMetaData
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
*  Method returns all completed quests.
*
* Service Name - Gamification
* Service Operation - ReadCompletedQuests
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
*  {
*   "status": 200,
*   "data": {
*     "quests": []
*   }
* }
*/
- (void)readCompletedQuests:(bool)includeMetaData
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject;

/**
*  Method returns quests that are in progress.
*
* Service Name - Gamification
* Service Operation - ReadInProgressQuests
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
*  {
*   "status": 200,
*   "data": {
*     "quests": []
*   }
* }
*/
- (void)readInProgressQuests:(bool)includeMetaData
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject;

/**
*  Method returns quests that have not been started.
*
* Service Name - Gamification
* Service Operation - ReadNotStartedQuests
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
*  {
*   "status": 200,
*   "data": {
*     "quests": []
*   }
* }
*/
- (void)readNotStartedQuests:(bool)includeMetaData
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject;

/**
*  Method returns quests with a status.
*
* Service Name - Gamification
* Service Operation - ReadQuestsWithStatus
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
*  {
*   "status": 200,
*   "data": {
*     "quests": []
*   }
* }
*/
- (void)readQuestsWithStatus:(bool)includeMetaData
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject;

/**
*  Method returns quests with a basic percentage.
*
* Service Name - Gamification
* Service Operation - ReadQuestsWithBasicPercentage
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
*  {
*   "status": 200,
*   "data": {
*     "quests": []
*   }
* }
*/
- (void)readQuestsWithBasicPercentage:(bool)includeMetaData
                      completionBlock:(BCCompletionBlock)cb
                 errorCompletionBlock:(BCErrorCompletionBlock)ecb
                             cbObject:(BCCallbackObject)cbObject;

/**
*  Method returns quests with a complex percentage.
*
* Service Name - Gamification
* Service Operation - ReadQuestsWithComplexPercentage
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
*  {
*   "status": 200,
*   "data": {
*     "quests": []
*   }
* }
*/
- (void)readQuestsWithComplexPercentage:(bool)includeMetaData
                        completionBlock:(BCCompletionBlock)cb
                   errorCompletionBlock:(BCErrorCompletionBlock)ecb
                               cbObject:(BCCallbackObject)cbObject;

/**
* Method returns quests for the given category.
*
* Service Name - Gamification
* Service Operation - ReadQuestsByCategory
*
* @param category The quest category
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data": {
*     "quests": []
*   }
* }
*/
- (void)readQuestsByCategory:(NSString *)category
             includeMetaData:(bool)includeMetaData
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject;

@end
