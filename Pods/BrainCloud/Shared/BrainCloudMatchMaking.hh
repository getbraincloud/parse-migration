//
//  BrainCloudMatchMaking.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-10.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudMatchMaking : NSObject

/**
* Read match making record
*
* Service Name - MatchMaking
* Service Operation - Read
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "lastMatch": 0,
*         "matchAttackExpiry": 0,
*         "matchEnabled": false,
*         "sharedAPIToken": null,
*         "shieldExpiry": 0,
*         "playerRating": 100,
*         "matchesPlayed": 0
*     }
* }
*/
- (void)read:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Sets player rating
*
* Service Name - MatchMaking
* Service Operation - SetPlayerRating
*
* @param playerRating The new player rating.
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
- (void)setPlayerRating:(int)rating
        completionBlock:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject;

/**
* Resets player rating
*
* Service Name - MatchMaking
* Service Operation - ResetPlayerRating
*
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
- (void)resetPlayerRating:(BCCompletionBlock)cb
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject;

/**
* Increments player rating
*
* Service Name - MatchMaking
* Service Operation - IncrementPlayerRating
*
* @param increment The increment amount
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
- (void)incrementPlayerRating:(int)increment
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject;

/**
* Decrements player rating
*
* Service Name - MatchMaking
* Service Operation - DecrementPlayerRating
*
* @param decrement The decrement amount
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
- (void)decrementPlayerRating:(int)decrement
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject;

/**
* Turns shield on
*
* Service Name - MatchMaking
* Service Operation - ShieldOn
*
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
- (void)turnShieldOn:(BCCompletionBlock)cb
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject;

/**
* Turns shield on for the specified number of minutes
*
* Service Name - MatchMaking
* Service Operation - ShieldOnFor
*
* @param minutes Number of minutes to turn the shield on for
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
- (void)turnShieldOnFor:(int)minutes
        completionBlock:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject;

/**
* Turns shield off
*
* Service Name - MatchMaking
* Service Operation - ShieldOff
*
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
- (void)turnShieldOff:(BCCompletionBlock)cb
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject;

/**
* Gets the shield expiry for the given player id. Passing in a null player id
* will return the shield expiry for the current player. The value returned is
* the time in UTC millis when the shield will expire.
*
* Service Name - MatchMaking
* Service Operation - GetShieldExpiry
*
* @param playerId The player id or use null to retrieve for the current player
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data": {
*     "shieldExpiry": 1433259734956
*   }
* }
*/
- (void)getShieldExpiry:(NSString *)playerId
        completionBlock:(BCCompletionBlock)cb
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject;

/**
* Finds matchmaking enabled players
*
* Service Name - MatchMaking
* Service Operation - FIND_PLAYERS
*
* @param rangeDelta The range delta
* @param numMatches The maximum number of matches to return
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data": {
*     "matchesFound" : [
*       {
*         "playerId" : "9073dff7-0df6-437e-9be6-39cd704dcoj4",
*         "playerName" : "Jane Smith",
*         "playerRating" : 25,
*         "pictureUrl" : "",
*         "summaryFriendData" : null
*       },
*       {
*         "playerId" : "9073dff7-0df6-437e-9be6-39cd704dcoj4",
*         "playerName" : "John Smith",
*         "playerRating" : 30,
*         "pictureUrl" : "",
*         "summaryFriendData" : null
*       }
*     ]
*   }
* }
*/
- (void)findPlayers:(int)rangeDelta
         numMatches:(int)numMatches
    completionBlock:(BCCompletionBlock)completionBlock
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
           cbObject:(BCCallbackObject)cbObject;

/**
 * Finds matchmaking enabled players with additional attributes
 *
 * Service Name - MatchMaking
 * Service Operation - FIND_PLAYERS
 *
 * @param rangeDelta The range delta
 * @param numMatches The maximum number of matches to return
 * @param jsonAttributes Attributes match criteria
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @return The JSON returned in the callback is as follows:
 * {
 *   "status": 200,
 *   "data": {
 *     "matchesFound" : [
 *       {
 *         "playerId" : "9073dff7-0df6-437e-9be6-39cd704dcoj4",
 *         "playerName" : "Jane Smith",
 *         "playerRating" : 25,
 *         "pictureUrl" : "",
 *         "summaryFriendData" : null
 *       },
 *       {
 *         "playerId" : "9073dff7-0df6-437e-9be6-39cd704dcoj4",
 *         "playerName" : "John Smith",
 *         "playerRating" : 30,
 *         "pictureUrl" : "",
 *         "summaryFriendData" : null
 *       }
 *     ]
 *   }
 * }
 */
- (void)findPlayersWithAttributes:(int)rangeDelta
                       numMatches:(int)numMatches
                   jsonAttributes:(NSString *)jsonAttributes
                  completionBlock:(BCCompletionBlock)cb
             errorCompletionBlock:(BCErrorCompletionBlock)ecb
                         cbObject:(BCCallbackObject)cbObject;

/**
* Finds matchmaking enabled players using a cloud code filter
*
* Service Name - MatchMaking
* Service Operation - FIND_PLAYERS_USING_FILTER
*
* @param rangeDelta The range delta
* @param numMatches The maximum number of matches to return
* @param jsonExtraParms Other parameters
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data": {
*     "matchesFound" : [
*       {
*         "playerId" : "9073dff7-0df6-437e-9be6-39cd704dcoj4",
*         "playerName" : "Jane Smith",
*         "playerRating" : 25,
*         "pictureUrl" : "",
*         "summaryFriendData" : null
*       },
*       {
*         "playerId" : "9073dff7-0df6-437e-9be6-39cd704dcoj4",
*         "playerName" : "John Smith",
*         "playerRating" : 30,
*         "pictureUrl" : "",
*         "summaryFriendData" : null
*       }
*     ]
*   }
* }
*/
- (void)findPlayersUsingFilter:(int)rangeDelta
                    numMatches:(int)numMatches
               jsonExtraParams:(NSString *)jsonExtraParams
               completionBlock:(BCCompletionBlock)cb
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject;

/**
 * Finds matchmaking enabled players using a cloud code filter
 * and additional attributes
 *
 * Service Name - MatchMaking
 * Service Operation - FIND_PLAYERS_USING_FILTER
 *
 * @param rangeDelta The range delta
 * @param numMatches The maximum number of matches to return
 * @param jsonAttributes Attributes match criteria
 * @param jsonExtraParms Parameters to pass to the CloudCode filter script
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @return The JSON returned in the callback is as follows:
 * {
 *   "status": 200,
 *   "data": {
 *     "matchesFound" : [
 *       {
 *         "playerId" : "9073dff7-0df6-437e-9be6-39cd704dcoj4",
 *         "playerName" : "Jane Smith",
 *         "playerRating" : 25,
 *         "pictureUrl" : "",
 *         "summaryFriendData" : null
 *       },
 *       {
 *         "playerId" : "9073dff7-0df6-437e-9be6-39cd704dcoj4",
 *         "playerName" : "John Smith",
 *         "playerRating" : 30,
 *         "pictureUrl" : "",
 *         "summaryFriendData" : null
 *       }
 *     ]
 *   }
 * }
 */
- (void)findPlayersWithAttributesUsingFilter:(int)rangeDelta
                                  numMatches:(int)numMatches
                              jsonAttributes:(NSString *)jsonAttributes
                             jsonExtraParams:(NSString *)jsonExtraParams
                             completionBlock:(BCCompletionBlock)cb
                        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                    cbObject:(BCCallbackObject)cbObject;

/**
* Enables Match Making for the Player
*
* Service Name - MatchMaking
* Service Operation - EnableMatchMaking
*
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
- (void)enableMatchMaking:(BCCompletionBlock)cb
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject;

@end
