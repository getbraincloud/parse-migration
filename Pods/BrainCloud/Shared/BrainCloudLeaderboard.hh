//
//  BrainCloudLeaderboard.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-07.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

typedef NS_ENUM(NSUInteger, LeaderboardType)
{
    HIGH_VALUE,
    CUMULATIVE,
    LAST_VALUE,
    LOW_VALUE
};

typedef NS_ENUM(NSUInteger, RotationType)
{
    NEVER,
    DAILY,
    WEEKLY,
    MONTHLY,
    YEARLY
};

typedef NS_ENUM(NSUInteger, SortOrder)
{
    HIGH_TO_LOW,
    LOW_TO_HIGH
};

@interface BrainCloudLeaderboard : NSObject

/**
* Method returns the social leaderboard. A player's social leaderboard is
* comprised of players who are recognized as being your friend.
* For now, this applies solely to Facebook connected players who are
* friends with the logged in player (who also must be Facebook connected).
* In the future this will expand to other identification means (such as
* Game Centre, Google circles etc).
*
* Leaderboards entries contain the player's score and optionally, some user-defined
* data associated with the score. The currently logged in player will also
* be returned in the social leaderboard.
*
* Note: If no friends have played the game, the bestScore, createdAt, updatedAt
* will contain NULL.
*
* @param leaderboardId The id of the leaderboard to retrieve
* @param replaceName If true, the currently logged in player's name will be replaced
* by the string "You".
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns JSON string representing the entries in the leaderboard.
* Note that the friend summary data is returned for each record
* in the leaderboard.
*
* {
*   "status": 200,
*   "data": {
*     "social_leaderboard": [
*       {
*         "updatedAt": 1395840936348,
*         "pictureUrl": null,
*         "playerId": "26f8bb07-3e94-458b-8485-f9031c3a6ef1",
*         "createdAt": 1395840936348,
*         "name": "You",
*         "otherData": null,
*         "authenticationType": null,
*         "externalId": null,
*         "summaryFriendData": null,
*         "score": 20000
*       },
*       {
*         "updatedAt": 1395840936351,
*         "pictureUrl": null,
*         "playerId": "3ad8bc09-4a34-e324-1231-3b2c1c3a6bc6",
*         "createdAt": 1395840936351,
*         "name": "Jenny Goldsmith",
*         "otherData": null,
*         "authenticationType": null,
*         "externalId": null,
*         "summaryFriendData": null,
*         "score": 10000
*       }
*     ],
*     "timeBeforeReset": 588182412,
*     "server_time": 1395840957588
*   }
* }
*
*/
- (void)getSocialLeaderboard:(NSString *)leaderboardId
           replaceName:(bool)replaceName
       completionBlock:(BCCompletionBlock)cb
  errorCompletionBlock:(BCErrorCompletionBlock)ecb
              cbObject:(BCCallbackObject)cbObject;

/**
 * Reads multiple social leaderboards.
 *
 * @param leaderboardIds NSArray of NSString leaderboard IDs.
 * @param leaderboardResultCount Maximum count of entries to return for each leaderboard.
 * @param replaceName If true, the currently logged in player's name will be replaced
 * by the string "You".
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @returns JSON string representing the entries in each leaderboard.
 * Note that the friend summary data is returned for each record
 * in the leaderboard.
 *
 * {
 *   "server_time": 1445952203123,
 *   "leaderboards": [
 *    {
 *     "leaderboardId": "default",
 *     "leaderboard": [
 *      {
 *       "externalId": "pacer5",
 *       "name": "Rollo",
 *       "pictureUrl": "http://localhost:8080/gameserver/s3/portal/g/eggies/metadata/pacers/pacer5.png",
 *       "playerId": "pacer5",
 *       "authenticationType": null,
 *       "score": 100000,
 *       "data": {
 *        "pacerTag": null,
 *        "pacerLeaderboardTag": {}
 *       },
 *       "createdAt": null,
 *       "updatedAt": null
 *      },
 *      {
 *       "externalId": "pacer4",
 *       "name": "Chirp",
 *       "pictureUrl": "http://localhost:8080/gameserver/s3/portal/g/eggies/metadata/pacers/pacer4.png",
 *       "playerId": "pacer4",
 *       "authenticationType": null,
 *       "score": 80000,
 *       "data": {
 *        "pacerTag": null,
 *        "pacerLeaderboardTag": {}
 *       },
 *       "createdAt": null,
 *       "updatedAt": null
 *      }
 *     ],
 *     "self": {
 *      "externalId": null,
 *      "name": null,
 *      "pictureUrl": null,
 *      "playerId": "49390659-33bd-4812-b0c4-ab04e614ec98",
 *      "authenticationType": null,
 *      "score": 10,
 *      "data": {
 *       "nickname": "batman"
 *      },
 *      "createdAt": 1445952060607,
 *      "updatedAt": 1445952060607,
 *      "summaryFriendData": null
 *     },
 *     "selfIndex": 5
 *    }
 *   ]
 *  }
 */
- (void)getMultiSocialLeaderboard:(NSArray *)leaderboardIds
           leaderboardResultCount:(NSInteger)leaderboardResultCount
                      replaceName:(bool)replaceName
                  completionBlock:(BCCompletionBlock)cb
             errorCompletionBlock:(BCErrorCompletionBlock)ecb
                         cbObject:(BCCallbackObject)cbObject;


/**
* Method returns a page of global leaderboard results.
*
* Leaderboards entries contain the player's score and optionally, some user-defined
* data associated with the score.
*
* Note: This method allows the client to retrieve pages from within the global leaderboard list
*
* Service Name - SocialLeaderboard
* Service Operation - GetGlobalLeaderboardPage
*
* @param leaderboardId The id of the leaderboard to retrieve.
* @param sort Sort key Sort order of page.
* @param startIndex The index at which to start the page.
* @param endIndex The index at which to end the page.
* @param includeLeaderboardSize Whether to return the leaderboard size
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns JSON string representing the entries in the leaderboard.
* Note that the friend summary data is returned for each record
* in the leaderboard.
*
* {
*  "status": 200,
*  "data": {
*   "leaderboardId": "abc",
*   "moreBefore": false,
*   "timeBeforeReset": 48085996,
*   "leaderboard": [
*    {
*     "playerId": "8c86f306-73ea-4536-9c92-aba086064d2c",
*     "score": 10,
*     "data": {
*      "nickname": "batman"
*     },
*     "createdAt": 1433863814394,
*     "updatedAt": 1433863814394,
*     "index": 0,
*     "rank": 1,
*     "name": "",
*     "summaryFriendData": {
*      "xp": 12,
*      "favColour": "red"
*     }
*    },
*    {
*     "playerId": "ab21c0af-9d3e-4a81-b3c8-ddc1fb77d9a1",
*     "score": 8,
*     "data": {
*      "nickname": "robin"
*     },
*     "createdAt": 1433864253221,
*     "updatedAt": 1433864253221,
*     "index": 1,
*     "rank": 2,
*     "name": "",
*     "summaryFriendData": null
*    }
*   ],
*   "server_time": 1433864314004,
*   "moreAfter": false
*  }
* }
*/
- (void)getGlobalLeaderboardPage:(NSString *)leaderboardId
                       sortOrder:(SortOrder)sortOrder
                      startIndex:(int)startIndex
                        endIndex:(int)endIndex
          includeLeaderboardSize:(bool)includeLeaderboardSize
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject;

/**
* Method returns a page of global leaderboard results.
* By using a non-current version id, the user can retrieve a historial leaderboard.
* See GetGlobalLeaderboardVersions method to retrieve the version id.
*
* Service Name - SocialLeaderboard
* Service Operation - GetGlobalLeaderboardPage
*
* @param leaderboardId The id of the leaderboard to retrieve.
* @param sort Sort key Sort order of page.
* @param startIndex The index at which to start the page.
* @param endIndex The index at which to end the page.
* @param includeLeaderboardSize Whether to return the leaderboard size
* @param versionId The historical version to retrieve.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns JSON string representing the entries in the leaderboard.
* See GetGlobalLeaderboardPage documentation. Note that historial leaderboards do not
* include the 'timeBeforeReset' parameter.
*/
- (void)getGlobalLeaderboardPageByVersion:(NSString *)leaderboardId
                                sortOrder:(SortOrder)sortOrder
                               startIndex:(int)startIndex
                                 endIndex:(int)endIndex
                   includeLeaderboardSize:(bool)includeLeaderboardSize
                                versionId:(int)versionId
                          completionBlock:(BCCompletionBlock)cb
                     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                 cbObject:(BCCallbackObject)cbObject;

/**
* Method returns a view of global leaderboard results that centers on the current player.
*
* Leaderboards entries contain the player's score and optionally, some user-defined
* data associated with the score.
*
* Service Name - SocialLeaderboard
* Service Operation - GetGlobalLeaderboardView
*
* @param leaderboardId The id of the leaderboard to retrieve.
* @param sort Sort key Sort order of page.
* @param beforeCount The count of number of players before the current player to include.
* @param afterCount The count of number of players after the current player to include.
* @param includeLeaderboardSize Whether to return the leaderboard size
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns JSON string representing the entries in the leaderboard.
* Note that the friend summary data is returned for each record
* in the leaderboard.
*
* {
*  "status": 200,
*  "data": {
*   "leaderboardId": "abc",
*   "moreBefore": false,
*   "timeBeforeReset": 48085996,
*   "leaderboard": [
*    {
*     "playerId": "8c86f306-73ea-4536-9c92-aba086064d2c",
*     "score": 10,
*     "data": {
*      "nickname": "batman"
*     },
*     "createdAt": 1433863814394,
*     "updatedAt": 1433863814394,
*     "index": 0,
*     "rank": 1,
*     "name": "",
*     "summaryFriendData": {
*      "xp": 12,
*      "favColour": "red"
*     }
*    },
*    {
*     "playerId": "ab21c0af-9d3e-4a81-b3c8-ddc1fb77d9a1",
*     "score": 8,
*     "data": {
*      "nickname": "robin"
*     },
*     "createdAt": 1433864253221,
*     "updatedAt": 1433864253221,
*     "index": 1,
*     "rank": 2,
*     "name": "",
*     "summaryFriendData": null
*    }
*   ],
*   "server_time": 1433864314004,
*   "moreAfter": false
*  }
* }
*/
- (void)getGlobalLeaderboardView:(NSString *)leaderboardId
                       sortOrder:(SortOrder)sortOrder
                     beforeCount:(int)beforeCount
                      afterCount:(int)afterCount
          includeLeaderboardSize:(bool)includeLeaderboardSize
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject;

/**
* Method returns a view of global leaderboard results that centers on the current player.
* By using a non-current version id, the user can retrieve a historial leaderboard.
* See GetGlobalLeaderboardVersions method to retrieve the version id.
*
* Service Name - SocialLeaderboard
* Service Operation - GetGlobalLeaderboardView
*
* @param leaderboardId The id of the leaderboard to retrieve.
* @param sort Sort key Sort order of page.
* @param beforeCount The count of number of players before the current player to include.
* @param afterCount The count of number of players after the current player to include.
* @param includeLeaderboardSize Whether to return the leaderboard size
* @param versionId The historical version to retrieve.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns JSON string representing the entries in the leaderboard.
* See GetGlobalLeaderboardView documentation. Note that historial leaderboards do not
* include the 'timeBeforeReset' parameter.
*/
- (void)getGlobalLeaderboardViewByVersion:(NSString *)leaderboardId
                                sortOrder:(SortOrder)sortOrder
                              beforeCount:(int)beforeCount
                               afterCount:(int)afterCount
                   includeLeaderboardSize:(bool)includeLeaderboardSize
                                versionId:(int)versionId
                          completionBlock:(BCCompletionBlock)cb
                     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                 cbObject:(BCCallbackObject)cbObject;

/** Gets the global leaderboard versions.
*
* Service Name - SocialLeaderboard
* Service Operation - GetGlobalLeaderboardVersions
*
* @param leaderboardId The leaderboard
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns JSON string representing the leaderboard versions.
* {
*   "status": 200,
*   "data": {
*     "leaderboardId":"L1",
*     "leaderboardType":"HIGH_VALUE",
*     "rotationType":"WEEKLY",
*     "retainedCount":2,
*     "versions":[
*        {
*         "versionId":27,
*         "startingAt":1434499200000,
*         "endingAt":1435104000000
*        },
*        {
*         "versionId":26,
*         "startingAt":1433894400000,
*         "endingAt":1434499200000
*        }
*        ]
*     }
*   }
* }
*/
- (void)getGlobalLeaderboardVersions:(NSString *)leaderboardId
                     completionBlock:(BCCompletionBlock)cb
                errorCompletionBlock:(BCErrorCompletionBlock)ecb
                            cbObject:(BCCallbackObject)cbObject;

/**
* Post the players score to the given social leaderboard.
* You can optionally send a user-defined json string of data
* with the posted score. This string could include information
* relevant to the posted score.
*
* Note that the behaviour of posting a score can be modified in
* the brainCloud portal. By default, the server will only keep
* the player's best score.
*
* @param leaderboardId The leaderboard to post to
* @param score The score to post
* @param data Optional user-defined data to post with the score
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data": null
* }
*/
- (void)postScoreToLeaderboard:(NSString *)leaderboardId
                         score:(int)score
                 jsonOtherData:(NSString *)jsonOtherData
               completionBlock:(BCCompletionBlock)cb
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject;

/**
* Post the players score to the given social leaderboard.
* Pass leaderboard config data to dynamically create if necessary.
* You can optionally send a user-defined json string of data
* with the posted score. This string could include information
* relevant to the posted score.
*
* Service Name - SocialLeaderboard
* Service Operation - PostScoreDynamic
*
* @param leaderboardId The leaderboard to post to
* @param score The score to post
* @param data Optional user-defined data to post with the score
* @param leaderboardType leaderboard type
* @param rotationType Type of rotation
* @param rotationReset Date to start rotation calculations
* @param retainedCount How many rotations to keep
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data": null
* }
*/
- (void)postScoreToDynamicLeaderboard:(NSString *)leaderboardId
                                score:(int)score
                             jsonData:(NSString *)jsonData
                      leaderboardType:(LeaderboardType)leaderboardType
                         rotationType:(RotationType)rotationType
                       roatationReset:(NSDate*)rotationReset
                        retainedCount:(int)retainedCount
                      completionBlock:(BCCompletionBlock)cb
                 errorCompletionBlock:(BCErrorCompletionBlock)ecb
                             cbObject:(BCCallbackObject)cbObject;

/**
* Reset the player's score for the given social leaderboard id.
*
* @param leaderboardId The leaderboard to post to
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data": null
* }
*/
- (void)resetLeaderboardScore:(NSString *)leaderboardId
              completionBlock:(BCCompletionBlock)cb
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject;

/**
* If a social leaderboard has been configured to reset periodically, each period
* can be considered to be a tournament. When the leaderboard resets, the tournament
* has ended and participants can be ranked based on their final scores.
*
* This API method will return the sorted leaderboard including:
* the player
* the game's pacers
* all friends who participated in the tournament
*
* This API method will return the leaderboard results for a particular
* tournament only once. If the method is called twice, the second call
* will yield an empty result.
*
* Note that if the leaderboard has not been configured to reset, the concept of a
* tournament does not apply.
*
* @param leaderboardId The id of the leaderboard
* @param replaceName True if the player's name should be replaced with "You"
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":{
*   }
* }
*/
- (void)getCompletedLeaderboardTournament:(NSString *)leaderboardId
                              replaceName:(bool)replaceName
                          completionBlock:(BCCompletionBlock)cb
                     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                 cbObject:(BCCallbackObject)cbObject;

/**
* This method triggers a reward (via a player statistics event)
* to the currently logged in player for ranking at the
* completion of a tournament.
*
* @param leaderboardId The id of the leaderboard
* @param eventName The player statistics event name to trigger
* @param eventMultiplier The multiplier to associate with the event
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":{
*   }
* }
*/
- (void)triggerSocialLeaderboardTournamentReward:(NSString *)leaderboardId
                                       eventName:(NSString *)eventName
                                 eventMultiplier:(uint64_t)eventMultiplier
                                 completionBlock:(BCCompletionBlock)cb
                            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                        cbObject:(BCCallbackObject)cbObject;

@end