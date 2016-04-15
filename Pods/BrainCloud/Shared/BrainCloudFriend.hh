//
//  BrainCloudFriend.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-10.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@class FriendPlatformObjc;
@interface BrainCloudFriend : NSObject

/**
* Retrieves profile information for the specified user.
*
* Service Name - Friend
* Service Operation - GetFriendProfileInfoForExternalId
*
* @param externalId The friend's external id e.g. Facebook id
* @param authenticationType The authentication type of the friend id e.g. Facebook
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the callback
* {
*   "status":200,
*   "data": {
*     "playerId" : "17c7ee96-1b73-43d0-8817-cba1953bbf57",
*     "playerName" : "Donald Trump",
*     "email" : "donald@trumpcastle.com",
*     "playerSummaryData" : {},
*   }
* }
*/
- (void)getFriendProfileInfoForExternalId:(NSString *)externalId
                        authenicationType:(NSString *)authenticationType
                          completionBlock:(BCCompletionBlock)cb
                     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                 cbObject:(BCCallbackObject)cbObject;

/**
 * Retrieves the external ID for the specified user profile ID on the specified social platform.
 *
 * @param profileId Profile (player) ID.
 * @param authenticationType Associated authentication type.
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @return The JSON returned in the callback
 * {
 *    "status": 200,
 *    "data": {
 *        "externalId": "19e1c0cf-9a2d-4d5c-9a71-1b0f6asdfb4b"
 *    }
 * }
 */
- (void) getExternalIdForProfileId:(NSString *)profileId
                authenticationType:(NSString *)authenticationType
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject;

/**
* Returns a particular entity of a particular friend.
*
* Service Name - Friend
* Service Operation - ReadFriendEntity
*
* @param entityId Id of entity to retrieve.
* @param friendId Profile Id of friend who owns entity.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block
*/
- (void)readFriendEntity:(NSString *)entityId
                friendId:(NSString *)friendId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Returns entities of all friends optionally based on type.
*
* Service Name - Friend
* Service Operation - ReadFriendsEntities
*
* @param entityType Types of entities to retrieve.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block
*/
- (void)readFriendsEntities:(NSString *)entityType
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject;

/**
* Deprecated - Use listFriends instead. Removal after June 21 2016.
*/
- (void)readFriendsWithApplication:(bool)includeSummaryData
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject
DEPRECATED_MSG_ATTRIBUTE("Use listFriends instead. Removal after June 21 2016.");

/**
* Read a friend's player state.
*
* Service Name - PlayerState
* Service Operation - ReadFriendsPlayerState
*
* @param friendId Target friend
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*/
- (void)readFriendPlayerState:(NSString *)friendId
              completionBlock:(BCCompletionBlock)cb
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject;

/**
 * Deprecated - Use version in BrainCloudPlayerState instead. Removal after June 21 2016.
 */
- (void)updateSummaryFriendData:(NSString *)jsonSummaryData
                completionBlock:(BCCompletionBlock)cb
           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                       cbObject:(BCCallbackObject)cbObject
DEPRECATED_MSG_ATTRIBUTE("Use version in BrainCloudPlayerState instead. Removal after June 21 2016.");

/**
* Finds a list of players matching the search text by performing a substring
* search of all player names.
* If the number of results exceeds maxResults the message
* "Too many results to return." is received and no players are returned
*
* Service Name - Friend
* Service Operation - FindPlayerByName
*
* @param searchText The substring to search for. Minimum length of 3 characters.
* @param maxResults  Maximum number of results to return. If there are more the message
*                       "Too many results to return." is sent back instead of the players.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "matches": [
*         {
*             "profileId": "63d1fdbd-2971-4791-a248-f8cda1a79bba",
*             "playerSummaryData": null,
*             "profileName": "ABC"
*         }
*         ],
*         "matchedCount": 1
*     }
* }
*/
- (void)findPlayerByName:(NSString *)searchText
              maxResults:(int)maxResults
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
 * Retrieves profile information for the partial matches of the specified text.
 *
 * @param searchText Universal ID text on which to search.
 * @param maxResults Maximum number of results to return.
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @return Object containing profile information.
 *  The JSON returned in the callback
 * {
 *   "status":200,
 *   "data": {
 *     "matchedCount" : 20,
 *     "matches" : [{
 *       "profileId" : "17c7ee96-1b73-43d0-8817-cba1953bbf57",
 *       "profileName" : "Donald Trump",
 *       "playerSummaryData" : {}
 *     },{
 *       "profileId" : "19d7ee96-2x73-43d0-8817-cba1953bbf57",
 *       "profileName" : "Donald Duck",
 *       "playerSummaryData" : {}
 *     }
 *     ]
 *   }
 * }
 *
 * Alternatively, if there are too many results:
 * {
 *   "status":200,
 *   "data": {
 *     "matchedCount" : 2059,
 *     "message" : "Too many results to return."
 *   }
 * }
 */
- (void)findPlayerByUniversalId:(NSString *)searchText
                     maxResults:(int)maxResults
                completionBlock:(BCCompletionBlock)cb
           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                       cbObject:(BCCallbackObject)cbObject;

/**
 * Retrieves a list of player and friend platform information for all friends of the current player.
 *
 * Service Name - Friend
 * Service Operation - LIST_FRIENDS
 *
 * @param friendPlatform Friend platform to query.
 * @param includeSummaryData  True if including summary data; false otherwise.
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @return The JSON returned in the callback is as follows:
 * Example 1: for friendPlatform = All
 * {
 *     "status": 200,
 *     "data": {
 *         "friends": [{
 *             "externalData": {
 *                 "Facebook": {
 *                     "pictureUrl": "https://scontent.xx.fbcdn.net/hprofile-xfp1/v/t1.0-1/p50x50/XXX.jpg?oh=YYY&oe=ZZZ",
 *                     "name": "scientist at large",
 *                     "externalId": "100003668521730"
 *
 *                 },
 *                 "brainCloud": {}
 *             },
 *             "playerId": "1aa3428c-5877-4624-a909-f2b1af931f00",
 *             "name": "Mr. Peabody",
 *             "summaryFriendData": {
 *                 "LEVEL": -4
 *             }
 *         }, {
 *             "externalData": {
 *                 "Facebook": {
 *                     "pictureUrl": "https://scontent.xx.fbcdn.net/hprofile-xfa1/v/t1.0-1/c0.11.50.50/p50x50/3AAA.jpg?oh=BBBa&oe=CCC",
 *                     "name": "Aquaman",
 *                     "externalId": "100003509724516"
 *                 }
 *             },
 *             "playerId": "1598c5b6-1b09-431b-96bc-9c2c928cad3b",
 *             "name": null,
 *             "summaryFriendData": {
 *                 "LEVEL": 1
 *             }
 *         }],
 *         "server_time": 1458224807855
 *     }
 * }
 *
 * Example 2: for friendPlatform = Facebook
 * {
 *     "status": 200,
 *     "data": {
 *         "friends": [{
 *             "externalData": {
 *                 "Facebook": {
 *                     "pictureUrl": "https://scontent.xx.fbcdn.net/hprofile-xfp1/v/t1.0-1/p50x50/XXX.jpg?oh=YYY&oe=ZZZ",
 *                     "name": "scientist at large",
 *                     "externalId": "100003668521730"
 *                 }
 *             },
 *             "playerId": "1aa3428c-5877-4624-a909-f2b1af931f00",
 *             "name": "Mr. Peabody",
 *             "summaryFriendData": {
 *                 "LEVEL": -4
 *             }
 *         }, {
 *             "externalData": {
 *                 "Facebook": {
 *                     "pictureUrl": "https://scontent.xx.fbcdn.net/hprofile-xfa1/v/t1.0-1/c0.11.50.50/p50x50/3AAA.jpg?oh=BBBa&oe=CCC",
 *                     "name": "Aquaman",
 *                     "externalId": "100003509724516"
 *                 }
 *             },
 *             "playerId": "1598c5b6-1b09-431b-96bc-9c2c928cad3b",
 *             "name": null,
 *             "summaryFriendData": {
 *                 "LEVEL": 1
 *             }
 *         }],
 *         "server_time": 1458224807855
 *     }
 * }
 */
- (void)listFriends:(FriendPlatformObjc *)friendPlatform
      includeSummaryData:(bool)includeSummaryData
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
 * Links the current player and the specified players as brainCloud friends.
 *
 * Service Name - Friend
 * Service Operation - ADD_FRIENDS
 *
 * @param profileIds Collection of player IDs.
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @return The JSON returned in the callback is as follows:
 * {
 *     "status": 200,
 *     "data": null
 * }
 */
- (void)addFriends:(NSArray *)profileIds
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
 * Unlinks the current player and the specified players as brainCloud friends.
 *
 * Service Name - Friend
 * Service Operation - REMOVE_FRIENDS
 *
 * @param profileIds Collection of player IDs.
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @return The JSON returned in the callback is as follows:
 * {
 *     "status": 200,
 *     "data": null
 * }
 */
- (void)removeFriends:(NSArray *)profileIds
      completionBlock:(BCCompletionBlock)cb
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject;

@end
