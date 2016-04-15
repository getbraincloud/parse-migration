//
//  BrainCloudPlayerState.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-06.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudPlayerState : NSObject

/**
* Read the state of the currently logged in player.
* This method returns a JSON object describing most of the
* player's data: entities, statistics, level, currency.
* Apps will typically call this method after authenticating to get an
* up-to-date view of the player's data.
*
* Service Name - PlayerState
* Service Operation - Read
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data": {
*     "vcPurchased": null,
*     "id": "210ee817-d555-40c3-b109-c24a84c84dc7",
*     "experiencePoints": 10,
*     "sent_events": [],
*     "vcClaimed": null,
*     "server_time": 1395950294285,
*     "experienceLevel": 1,
*     "incoming_events": [],
*     "currency": {
*       "gems": {
*         "purchased": 0,
*         "balance": 0,
*         "consumed": 0,
*         "awarded": 0
*       },
*       "gold": {
*         "purchased": 0,
*         "balance": 0,
*         "consumed": 0,
*         "awarded": 0
*       }
*     },
*     "statistics": {
*       "minions": 0,
*       "wood": 50,
*       "pantelons": 3,
*       "iron": 0
*     },
*     "abTestingId": 60
*   }
* }
*/
- (void)readPlayerState:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject;

/**
* Completely deletes the player record and all data fully owned
* by the player. After calling this method, the player will need
* to re-authenticate and create a new profile.
* This is mostly used for debugging/qa.
*
* Service Name - PlayerState
* Service Operation - FullReset
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
- (void)deletePlayer:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject;

/**
* This method will delete *most* data for the currently logged in player.
* Data which is not deleted includes: currency, credentials, and
* purchase transactions. ResetPlayer is different from DeletePlayer in that
* the player record will continue to exist after the reset (so the user
* does not need to re-authenticate).
*
* Service Name - PlayerState
* Service Operation - DataReset
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
- (void)resetPlayerState:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Logs player out of server.
*
* Service Name - PlayerState
* Service Operation - Logout
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
- (void)logout:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Sets the players name.
*
* Service Name - playerState
* Service Operation - UPDATE_NAME
*
* @param playerName The name of the player
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":
*   {
*     "playerName": "someName"
*   }
* }
*/
- (void)updatePlayerName:(NSString *)playerName
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Retrieve the player attributes.
*
* Service Name - PlayerState
* Service Operation - GetAttributes
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data": {
*     "attributes": {
*          "key1": "value1",
*          "key2": "value2"
*     }
*   }
* }
*/
- (void)getAttributes:(BCCompletionBlock)completionBlock
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject;

/**
* Update player attributes.
*
* Service Name - PlayerState
* Service Operation - UpdateAttributes
*
* @param jsonAttributes Single layer json string that is a set of key-value pairs
* @param wipeExisting Whether to wipe existing attributes prior to update.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
* }
*/
- (void)updateAttributes:(NSString *)jsonAttributes
            wipeExisting:(bool)wipeExisting
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Remove player attributes.
*
* Service Name - PlayerState
* Service Operation - RemoveAttributes
*
* @param attributeNames NSString array of attribute names.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
* }
*/
- (void)removeAttributes:(NSArray *)attributeNames
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
 * Remove player attributes.
 *
 * Service Name - PlayerState
 * Service Operation - UPDATE_PICTURE_URL
 *
 * @param pictureUrl URL to apply
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @return The JSON returned in the completion block is as follows:
 * {
 *     "status": 200,
 *     "data": {
 *         "playerPictureUrl": "https://some.domain.com/mypicture.jpg"
 *      }
 * }
 */
- (void)updatePlayerPictureUrl:(NSString *)pictureUrl
               completionBlock:(BCCompletionBlock)completionBlock
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject;

/**
 * Update the player's contact email.
 * Note this is unrelated to email authentication.
 *
 * Service Name - PlayerState
 * Service Operation - UPDATE_CONTACT_EMAIL
 *
 * @param contactEmail Updated email
 * @param callback The method to be invoked when the server response is received
 *
 * @return The JSON returned in the callback is as follows:
 * {
 *     "status": 200,
 *     "data": {
 *         "contactEmail": "someName@somedomain.com"
 *     }
 * }
 */
- (void)updateContactEmail:(NSString *)contactEmail
           completionBlock:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)ecb
                  cbObject:(BCCallbackObject)cbObject;

/**
* Updates the "friend summary data" associated with the logged in player.
* Some operations will return this summary data. For instance the social
* leaderboards will return the player's score in the leaderboard along
* with the friend summary data. Generally this data is used to provide
* a quick overview of the player without requiring a separate API call
* to read their public stats or entity data.
*
* Note this API call pre-dates the shared player data api (public entity/stats)
* and thus usage for anything outside of social leaderboards should be
* deprecated.
*
* Service Name - PlayerState
* Service Operation - UpdateSummary
*
* @param jsonSummaryData A JSON string defining the summary data.
* For example:
* {
*   "xp":123,
*   "level":12,
*   "highScore":45123
* }
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
- (void)updateSummaryFriendData:(NSString *)jsonSummaryData
                completionBlock:(BCCompletionBlock)cb
           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                       cbObject:(BCCallbackObject)cbObject;

@end
