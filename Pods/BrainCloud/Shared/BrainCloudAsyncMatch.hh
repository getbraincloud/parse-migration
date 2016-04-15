//
//  BrainCloudAsyncMatch.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-10.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudAsyncMatch : NSObject

/**
* Creates an instance of an asynchronous match.
*
* Service Name - AsyncMatch
* Service Operation - Create
*
* @param jsonOpponentIds  JSON string identifying the opponent platform and id for this match.
*
* Platforms are identified as:
* BC - a brainCloud profile id
* FB - a Facebook id
*
* An exmaple of this string would be:
* [
*     {
*         "platform": "BC",
*         "id": "some-braincloud-profile"
*     },
*     {
*         "platform": "FB",
*         "id": "some-facebook-id"
*     }
* ]
*
* @param pushNotificationMessage Optional push notification message to send to the other party.
*  Refer to the Push Notification functions for the syntax required.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns The JSON returned in the completion block is as follows:
* {
*     "gameId": "16245",
*     "ownerId": "0df9f282-183b-4d67-866e-670fb35a2376",
*     "matchId": "b55d12d6-f01f-45c5-827c-ded706374524",
*     "version": 0,
*     "players": [
*         {
*             "playerId": "0df9f282-183b-4d67-866e-670fb35a2376",
*             "playerName": "UserB",
*             "pictureUrl": null
*         },
*         {
*             "playerId": "4693ec75-3a99-4577-aef7-0f41d299339c",
*             "playerName": "Presto1",
*             "pictureUrl": null
*         }
*     ],
*     "status": {
*         "status": "NOT_STARTED",
*         "currentPlayer": "0df9f282-183b-4d67-866e-670fb35a2376"
*     },
*     "summary": null,
*     "createdAt": 1415641372974,
*     "updatedAt": 1415641372974
* }
*/
- (void)createMatch:(NSString *)jsonOpponentIds 
    pushNotificationMessage:(NSString *)pushMessage
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject;


- (void)createMatch:(NSString *)jsonOpponentIds
    pushNotificationMessage:(NSString *)pushMessage
                    matchId:(NSString *)matchId
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
DEPRECATED_MSG_ATTRIBUTE("Use version without matchId param instead. Removal after May 10 2016.");

/**
* Creates an instance of an asynchronous match with an initial turn.
*
* Service Name - AsyncMatch
* Service Operation - Create
*
* @param jsonOpponentIds  JSON string identifying the opponent platform and id for this match.
*
* Platforms are identified as:
* BC - a brainCloud profile id
* FB - a Facebook id
*
* An exmaple of this string would be:
* [
*     {
*         "platform": "BC",
*         "id": "some-braincloud-profile"
*     },
*     {
*         "platform": "FB",
*         "id": "some-facebook-id"
*     }
* ]
*
* @param jsonMatchState    JSON string blob provided by the caller
* @param pushNotificationMessage Optional push notification message to send to the other party.
* Refer to the Push Notification functions for the syntax required.
* @param nextPlayer Optionally, force the next player player to be a specific player
* @param jsonSummary Optional JSON string defining what the other player will see as a summary of the game when listing their games
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns The JSON returned in the completion block is as follows:
* {
*     "gameId": "16245",
*     "ownerId": "0df9f282-183b-4d67-866e-670fb35a2376",
*     "matchId": "b55d12d6-f01f-45c5-827c-ded706374524",
*     "version": 0,
*     "players": [
*         {
*             "playerId": "0df9f282-183b-4d67-866e-670fb35a2376",
*             "playerName": "UserB",
*             "pictureUrl": null
*         },
*         {
*             "playerId": "4693ec75-3a99-4577-aef7-0f41d299339c",
*             "playerName": "Presto1",
*             "pictureUrl": null
*         }
*     ],
*     "status": {
*         "status": "NOT_STARTED",
*         "currentPlayer": "0df9f282-183b-4d67-866e-670fb35a2376"
*     },
*     "summary": null,
*     "createdAt": 1415641372974,
*     "updatedAt": 1415641372974
* }
*/
- (void)createMatchWithInitialTurn:(NSString *)jsonOpponentIds
                    jsonMatchState:(NSString *)matchState
           pushNotificationMessage:(NSString *)pushMessage
                        nextPlayer:(NSString *)nextPlayer
                       jsonSummary:(NSString *)summary
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject;

- (void)createMatchWithInitialTurn:(NSString *)jsonOpponentIds
                    jsonMatchState:(NSString *)matchState
           pushNotificationMessage:(NSString *)pushMessage
                           matchId:(NSString *)matchId
                        nextPlayer:(NSString *)nextPlayer
                       jsonSummary:(NSString *)summary
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject
DEPRECATED_MSG_ATTRIBUTE("Use version without matchId param instead. Removal after May 10 2016.");

/**
* Submits a turn for the given match.
*
* Service Name - AsyncMatch
* Service Operation - SubmitTurn
*
* @param ownerId Match owner identfier
* @param matchId Match identifier
* @param version Game state version to ensure turns are submitted once and in order
* @param jsonMatchState JSON string provided by the caller
* @param pushNotificationMessage Optional push notification message to send to the other party.
*  Refer to the Push Notification functions for the syntax required.
* @param nextPlayer Optionally, force the next player player to be a specific player
* @param jsonSummary Optional JSON string that other players will see as a summary of the game when listing their games
* @param jsonStatistics Optional JSON string blob provided by the caller
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "gameId": "145677",
*         "ownerId": "2bd7abc6-c2ec-4946-a1a8-02bad38540ad",
*         "matchId": "1aac24b2-7976-4fd7-b7c6-44dere6d26a4",
*         "version": 1,
*         "players": [
*             {
*                 "playerId": "2bd7abc6-c2ec-4946-a1a8-02bad38540ad",
*                 "playerName": "UserB",
*                 "pictureUrl": null
*             },
*             {
*                 "playerId": "11c9dd4d-9ed1-416d-baw2-5228c1efafac",
*                 "playerName": "UserA",
*                 "pictureUrl": null
*             }
*         ],
*         "status": {
*             "status": "PENDING",
*             "currentPlayer": "11c9dd4d-9ed1-416d-baw2-5228c1efafac"
*         },
*         "summary": {
*             "resources": 1234
*         },
*         "createdAt": 1442507219609,
*         "updatedAt": 1442507319700
*     }
* }
*/
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
                   cbObject:(BCCallbackObject)cbObject;

/**
* Allows the current player (only) to update Summary data without having to submit a whole turn.
*
* Service Name - AsyncMatch
* Service Operation - UpdateMatchSummary
*
* @param ownerId Match owner identfier
* @param matchId Match identifier
* @param version Game state version to ensure turns are submitted once and in order
* @param jsonSummary JSON string that other players will see as a summary of the game when listing their games
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "gameId": "145677",
*         "ownerId": "2bd723c6-c2ec-4946-a1a8-02b7a38540ad",
*         "matchId": "1aac24b2-7976-4fd7-b7c6-44d7ae6d26a4",
*         "version": 2,
*         "players": [
*             {
*                 "playerId": "2bd723c6-c2ec-4946-a1a8-02b7a38540ad",
*                 "playerName": "UserA",
*                 "pictureUrl": null
*             },
*             {
*                 "playerId": "11c2dd4d-9ed1-416d-bd04-5228c1efafac",
*                 "playerName": "UserB",
*                 "pictureUrl": null
*             }
*         ],
*         "status": {
*             "status": "PENDING",
*             "currentPlayer": "11c2dd4d-9ed1-416d-bd04-5228c1efafac"
*         },
*         "summary": {
*             "resources": 2564
*         },
*         "createdAt": 1442507219609,
*         "updatedAt": 1442507550372
*     }
* }
*/
- (void)updateMatchSummaryData:(NSString *)ownerId
                       matchId:(NSString *)matchId
                       version:(uint64_t)version
                   jsonSummary:(NSString *)summary
               completionBlock:(BCCompletionBlock)cb
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject;

/**
* Marks the given match as complete.
*
* Service Name - AsyncMatch
* Service Operation - Complete
*
* @param ownerId Match owner identifier
* @param matchId Match identifier
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {}
* }
*/
- (void)completeMatch:(NSString *)ownerId
              matchId:(NSString *)matchId
      completionBlock:(BCCompletionBlock)cb
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject;

/**
* Returns the current state of the given match.
*
* Service Name - AsyncMatch
* Service Operation - ReadMatch
*
* @param ownerId   Match owner identifier
* @param matchId   Match identifier
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "gameId": "10299",
*         "ownerId": "11c9dd4d-9ed1-416d-bd04-5228c1efafac",
*         "matchId": "0d4c1803-887a-4f20-a2e4-73eeedba411e",
*         "version": 1,
*         "players": [
*             {
*                 "playerId": "11c9dd4d-9ed1-416d-bd04-5228c1efafac",
*                 "playerName": "UserB",
*                 "pictureUrl": null
*             },
*             {
*                 "playerId": "2bd7abc6-c2ec-4946-a1a8-02b7a38540ad",
*                 "playerName": "UserA",
*                 "pictureUrl": null
*             }
*         ],
*         "status": {
*             "status": "PENDING",
*             "currentPlayer": "2bd7abc6-c2ec-4946-a1a8-02b7a38540ad"
*         },
*         "summary": null,
*         "statistics": {},
*         "matchState": {},
*         "createdAt": 1442508171624,
*         "updatedAt": 1442508171632
*     }
* }
*/
- (void)readMatch:(NSString *)ownerId
                 matchId:(NSString *)matchId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Marks the given match as abandoned.
*
* Service Name - AsyncMatch
* Service Operation - Abandon
*
* @param ownerId   Match owner identifier
* @param matchId   Match identifier
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {}
* }
*/
- (void)abandonMatch:(NSString *)ownerId
             matchId:(NSString *)matchId
     completionBlock:(BCCompletionBlock)cb
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject;

/**
* Removes the match and match history from the server. DEBUG ONLY, in production it is recommended
*   the user leave it as completed.
*
* Service Name - AsyncMatch
* Service Operation - Delete
*
* @param ownerId   Match owner identifier
* @param matchId   Match identifier
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {}
* }
*/
- (void)deleteMatch:(NSString *)ownerId
                 matchId:(NSString *)matchId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Returns the match history of the given match.
*
* Service Name - AsyncMatch
* Service Operation - ReadMatchHistory
*
* @param ownerId   Match owner identifier
* @param matchId   Match identifier
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "gameId": "14577",
*         "ownerId": "2bd32bc6-c2ec-4916-a1a8-02b7a38540ad",
*         "matchId": "1aac24b2-7976-4fd7-b7c6-44d32e6d26a4",
*         "turns": [
*             {
*                 "playerId": "2bd32bc6-c2ec-4916-a1a8-02b7a38540ad",
*                 "matchState": {
*                     "color": "red"
*                 },
*                 "createdAt": 1442507319697
*             },
*             {
*                 "playerId": "11c9324d-9ed1-416d-b124-5228c1efafac",
*                 "matchState": {},
*                 "createdAt": 1442507703667
*             }
*         ]
*     }
* }
*/
- (void)readMatchHistory:(NSString *)ownerId
                 matchId:(NSString *)matchId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Returns all matches that are NOT in a COMPLETE state for which the player is involved.
*
* Service Name - AsyncMatch
* Service Operation - FindMatches
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "results": [
*             {
*                 "gameId": "123456",
*                 "ownerId": "7630f98e-1236-4ead-88ee-27ce63b2db2c",
*                 "matchId": "97c8d087-40d8-45c2-aa2b-6d0d83424ec5",
*                 "version": 1,
*                 "players": [
*                     {
*                         "playerId": "7630f98e-13b6-4ead-88ee-27ce63b2db2c",
*                         "playerName": "UserA-122217922",
*                         "pictureUrl": null
*                     },
*                     {
*                         "playerId": "efab2d0b-90a1-48cf-8678-ae81d7aaed89",
*                         "playerName": "UserB-122217922",
*                         "pictureUrl": null
*                     },
*                     {
*                         "playerId": "b28ff14a-364a-40b3-ac4e-d2b23983519c",
*                         "playerName": "UserC-338593317",
*                         "pictureUrl": null
*                     }
*                 ],
*                 "status": {
*                     "status": "PENDING",
*                     "currentPlayer": "efab2d0b-90a1-48cf-8678-ae81d7aaed89"
*                 },
*                 "summary": null,
*                 "createdAt": 1442586020180,
*                 "updatedAt": 1442586020188
*             }
*         ]
*     }
* }
*/
- (void)findMatches:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Returns all matches that are in a COMPLETE state for which the player is involved.
*
* Service Name - AsyncMatch
* Service Operation - FindMatchesCompleted
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "results": [
*             {
*                 "gameId": "10170",
*                 "ownerId": "9ad4f990-5466-4d00-a334-de834e1ac4ec",
*                 "matchId": "877dd25d-ea21-4857-ba2a-2134d0f5ace2",
*                 "version": 2,
*                 "players": [
*                     {
*                         "playerId": "9ad4f990-5466-4d00-a334-de834e1ac4ec",
*                         "playerName": "",
*                         "pictureUrl": null
*                     },
*                     {
*                         "playerId": "963a2079-6e7a-48de-a4f2-8ab16c811975",
*                         "playerName": "",
*                         "pictureUrl": null
*                     }
*                 ],
*                 "status": {
*                     "status": "COMPLETE",
*                     "currentPlayer": "963a2079-6e7a-48de-a4f2-8ab16c811975"
*                 },
*                 "summary": null,
*                 "createdAt": 1442586358023,
*                 "updatedAt": 1442586374787
*             }
*         ]
*     }
* }
*/
- (void)findCompleteMatches:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject;

@end
