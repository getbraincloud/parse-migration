//
//  BrainCloudOneWayMatch.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-11.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudOneWayMatch : NSObject

/**
* Starts a match
*
* Service Name - OneWayMatch
* Service Operation - StartMatch
*
* @param otherPlayerId The player to start a match with
* @param rangeDelta The range delta used for the initial match search
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*    "status": 200,
*    "data": {
*        "playbackStreamId": "d18719db-9d02-2341-b62f-8e2f013369be",
*        "initiatingPlayerId": "d175f6ac-9221-4adc-aea4-f25f2426ff62",
*        "targetPlayerId": "07a0d23e-996b-4488-90ae-cb438342423a54",
*        "status": "STARTED",
*        "summary": {},
*        "initialSharedData": {
*            "entities": [],
*            "statistics": {}
*        },
*        "events": [],
*        "createdAt": 1437419496282,
*        "updatedAt": 1437419496282
*    }
* }
*/
- (void)startMatch:(NSString *)otherPlayerId
              rangeDelta:(int32_t)range
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Cancels a match
*
* Service Name - OneWayMatch
* Service Operation - CancelMatch
*
* @param playbackStreamId The playback stream id returned in the start match
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
- (void)cancelMatch:(NSString *)playbackStreamId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Completes a match
*
* Service Name - OneWayMatch
* Service Operation - CompleteMatch
*
* @param playbackStreamId The playback stream id returned in the initial start match
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
- (void)completeMatch:(NSString *)playbackStreamId
      completionBlock:(BCCompletionBlock)cb
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject;

@end