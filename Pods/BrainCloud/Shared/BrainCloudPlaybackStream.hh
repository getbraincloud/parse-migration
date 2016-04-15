//
//  BrainCloudPlaybackStream.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-12.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudPlaybackStream : NSObject

/**
* Starts a stream
*
* Service Name - PlaybackStream
* Service Operation - StartStream
*
* @param targetPlayerId The player to start a stream with
* @param includeSharedData Whether to include shared data in the stream
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*    "status": 200,
*    "data": {
*     "playbackStreamId": "b8da4619-2ddc-4184-b654-cd11d12a3275",
*     "gameId": "10000",
*     "initiatingPlayerId": "198bcafcd-6e84-4c30-9f6e-3f9f016440c6",
*     "targetPlayerId": "a6943c74-6655-4245-8b2b-13bb908d3f88",
*     "status": "STARTED",
*     "summary": {},
*     "initialSharedData": {
*      "entities": [],
*      "statistics": {}
*     },
*     "events": [],
*     "createdAt": 1425481184200,
*     "updatedAt": 1425481184200
*    }
* }
*
*/
- (void)startStream:(NSString *)targetPlayerId
       includeSharedData:(bool)includeSharedData
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Reads a stream
*
* Service Name - PlaybackStream
* Service Operation - ReadStream
*
* @param playbackStreamId Identifies the stream to read
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*    "status": 200,
*    "data": {
*     "playbackStreamId": "b8da4619-2ddc-4184-b654-cd11d12a3275",
*     "gameId": "10000",
*     "initiatingPlayerId": "198bcafcd-6e84-4c30-9f6e-3f9f016440c6",
*     "targetPlayerId": "a6943c74-6655-4245-8b2b-13bb908d3f88",
*     "status": "COMPLETE",
*     "summary": { total : 5 },
*     "initialSharedData": {
*      "entities": [ {entry : 3}, {entry : 2 }],
*      "statistics": {}
*     },
*     "events": [],
*     "createdAt": 1425481184200,
*     "updatedAt": 1425481184200
*    }
*   }
*
*/
- (void)readStream:(NSString *)streamId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Ends a stream
*
* Service Name - PlaybackStream
* Service Operation - EndStream
*
* @param playbackStreamId Identifies the stream to read
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*    "status": 200,
*    "data": null
* }
*
*/
- (void)endStream:(NSString *)streamId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Deletes a stream
*
* Service Name - PlaybackStream
* Service Operation - DeleteStream
*
* @param playbackStreamId Identifies the stream to read
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*    "status": 200,
*    "data": null
* }
*
*/
- (void)deleteStream:(NSString *)streamId
     completionBlock:(BCCompletionBlock)cb
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject;

/**
* Adds a stream event
*
* Service Name - PlaybackStream
* Service Operation - AddEvent
*
* @param playbackStreamId Identifies the stream to read
* @param jsonEventData Describes the event
* @param jsonSummary Current summary data as of this event
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*    "status": 200,
*    "data": null
* }
*
*/
- (void)addEvent:(NSString *)streamId
           jsonEventData:(NSString *)eventData
             jsonSummary:(NSString *)summary
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Gets stream summaries for initiating player
*
* Service Name - PlaybackStream
* Service Operation - GetStreamSummariesForInitiatingPlayer
*
* @param initiatingPlayerId The player that started the stream
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*  "status": 200,
*  "data": {
*   "streams": [
*    {
*     "playbackStreamId": "b8da4619-2ddc-4184-b654-cd11d12a3275",
*     "gameId": "10000",
*     "initiatingPlayerId": "198bcadb-6e84-4c30-9f6e-3f9f016440c6",
*     "targetPlayerId": "a6943c74-6636-4245-8b2b-13bb908d3f88",
*     "status": "PROGRESS",
*     "summary": {
*      "total": 5
*     },
*     "createdAt": 1425481184200,
*     "updatedAt": 1425484485139
*    }
*   ]
*  }
* }         
*/
- (void)getStreamSummariesForInitiatingPlayer:(NSString *)playerId
                              completionBlock:(BCCompletionBlock)cb
                         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                     cbObject:(BCCallbackObject)cbObject;

/**
* Gets stream summaries for target player
*
* Service Name - PlaybackStream
* Service Operation - GetStreamSummariesForTargetPlayer
*
* @param targetPlayerId The player that started the stream
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*  "status": 200,
*  "data": {
*   "streams": [
*    {
*     "playbackStreamId": "b8da4619-2ddc-4184-b654-cd11d12a3275",
*     "gameId": "10000",
*     "initiatingPlayerId": "198bcadb-6e84-4c30-9f6e-3f9f016440c6",
*     "targetPlayerId": "a6943c74-6636-4245-8b2b-13bb908d3f88",
*     "status": "PROGRESS",
*     "summary": {
*      "total": 5
*     },
*     "createdAt": 1425481184200,
*     "updatedAt": 1425484485139
*    }
*   ]
*  }
* }         
*/
- (void)getStreamSummariesForTargetPlayer:(NSString *)playerId
                          completionBlock:(BCCompletionBlock)cb
                     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                 cbObject:(BCCallbackObject)cbObject;

@end
