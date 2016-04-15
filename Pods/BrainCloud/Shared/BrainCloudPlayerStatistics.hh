//
//  BrainCloudPlayerStatistics.hh
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-06.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudPlayerStatistics : NSObject

/**
* Read all available player statistics.
*
* Service Name - PlayerStatistics
* Service Operation - Read
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":{
*     "statistics":{
*       "minions":0,
*       "wood":50,
*       "pantelons":3,
*       "iron":0
*     }
*   }
* }
*/
- (void)readAllPlayerStats:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)ecb
                  cbObject:(BCCallbackObject)cbObject;

/**
* Reads a subset of player statistics.
*
* Service Name - PlayerStatistics
* Service Operation - ReadSubset
*
* @param playerStats A NSString array containing the subset of statistics to read:
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return JSON with the subset of global statistics:
* {
*   "status":200,
*   "data":{
*     "statistics":{
*       "wood":11,
*       "minions":1
*     }
*   }
* }
*/
- (void)readPlayerStatsSubset:(NSArray *)playerStats
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject;

/**
 * Method retrieves the player statistics for the given category.
 *
 * Service Name - PlayerStatistics
 * Service Operation - READ_FOR_CATEGORY
 *
 * @param category The player statistics category
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @return The JSON returned in the completion block is as follows:
 * {
 *   "status":200,
 *   "data":{
 *     "playerStatistics": []
 *   }
 * }
 */
- (void)readPlayerStatsForCategory:(NSString *)category
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject;

/**
* Reset all of the statistics for this player back to their initial value.
*
* Service Name - PlayerStatistics
* Service Operation - Reset
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
*/
- (void)resetAllPlayerStats:(BCCompletionBlock)completionBlock
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject;

/**
* Atomically increment (or decrement) player statistics.
* Any rewards that are triggered from player statistic increments
* will be considered. Player statistics are defined through the brainCloud portal.
* Note also that the "xpCapped" property is returned (true/false depending on whether
* the xp cap is turned on and whether the player has hit it).
*
* Service Name - PlayerStatistics
* Service Operation - Update
*
* @param jsonData The JSON encoded data to be sent to the server as follows:
* {
*   stat1: 10,
*   stat2: -5.5,
* }
* would increment stat1 by 10 and decrement stat2 by 5.5.
* For the full statistics grammer see the api.braincloudservers.com site.
* There are many more complex operations supported such as:
* {
*   stat1:INC_TO_LIMIT#9#30
* }
* which increments stat1 by 9 up to a limit of 30.
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return JSON describing the new value of the statistics and any rewards that were triggered:
*  {
*    "status":200,
*    "data":{
*      "experiencePoints":10,
*      "xpCapped":false,
*      "rewardDetails":{
*        "xp":{
*          "experienceLevels":[
*            {
*              "level":1,
*              "rewards":{
*                "currency":{
*                  "gold":1000
*                }
*              }
*            }
*          ]
*        }
*      },
*      "rewards":{
*        "experienceLevels":[
*          1
*        ],
*        "currency":{
*          "gold":1000
*        }
*      },
*      "experienceLevel":1,
*      "statistics":{
*        "LIVES":1
*      },
*      "currency":{
*        "gems":{
*          "purchased":0,
*          "balance":10,
*          "consumed":0,
*          "awarded":10
*        },
*        "gold":{
*          "purchased":0,
*          "balance":2000,
*          "consumed":0,
*          "awarded":2000
*        }
*      }
*    }
*  }
*/
- (void)incrementPlayerStats:(NSString *)jsonData
             completionBlock:(BCCompletionBlock)completionBlock
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject;

/**
* Returns JSON representing the next experience level for the player.
*
* Service Name - PlayerStatistics
* Service Operation - ReadNextXpLevel
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return JSON describing the next experience level for the player.
* {
*   "status":200,
*   "data":{
*     "xp_level":{
*       "gameId":"com.bitheads.unityexample",
*       "numericLevel":2,
*       "experience":20,
*       "rewards":{
*         "globalGameStatistics":null,
*         "experiencePoints":null,
*         "playerStatistics":null,
*         "achievement":null,
*         "currencies":{
*           "gems":10,
*           "gold":2000
*         }
*       },
*       "facebookAction":"",
*       "statusTitle":"Jester",
*       "key":{
*         "gameId":"com.bitheads.unityexample",
*         "numericLevel":2,
*         "primaryKey":true
*       }
*     }
*   }
* }
*/
- (void)getNextExperienceLevel:(BCCompletionBlock)completionBlock
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject;

/**
* Increments the player's experience. If the player goes up a level,
* the new level details will be returned along with a list of rewards.
*
* Service Name - PlayerStatistics
* Service Operation - UpdateIncrement
*
* @param xpValue The amount to increase the player's experience by
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return JSON describing the player's .
* {
*   "status":200,
*   "data":{
*     "statisticsExceptions":{
*     },
*     "milestones":{
*     },
*     "experiencePoints":110,
*     "quests":{
*     },
*     "experienceLevel":1,
*     "statistics":{
*       "minions":0,
*       "wood":50,
*       "pantelons":3,
*       "iron":0
*     }
*   }
* }
*/
- (void)incrementExperiencePoints:(int)xpValue
                  completionBlock:(BCCompletionBlock)completionBlock
             errorCompletionBlock:(BCErrorCompletionBlock)ecb
                         cbObject:(BCCallbackObject)cbObject;

/**
* Sets the player's experience to an absolute value. Note that this
* is simply a set and will not reward the player if their level changes
* as a result.
*
* Service Name - PlayerStatistics
* Service Operation - SetXpPoints
*
* @param xpValue The amount to set the the player's experience to
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
- (void)setExperiencePoints:(int)xpValue
            completionBlock:(BCCompletionBlock)completionBlock
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject;

@end
