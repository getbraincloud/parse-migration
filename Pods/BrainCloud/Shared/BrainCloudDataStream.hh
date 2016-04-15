//
//  BrainCloudDataStream.hh
//  brainCloudClientObjc
//
//  Created by Preston Jennings on 2015-11-26.
//  Copyright © 2015 bitHeads. All rights reserved.
//
#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudDataStream : NSObject

/**
 * Creates custom data stream page event
 *
 * @param eventName Name of event
 * @param eventProperties Properties of event
 * @return json as follows
 *
 * {
 * "status": 200,
 * "data": {
 *   null
 *  }
 * }
 *
 */
- (void)customPageEvent:(NSString *)eventName
    jsonEventProperties:(NSString *)jsonEventProperties
        completionBlock:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject;


/**
 * Creates custom data stream screen event
 *
 * @param eventName Name of event
 * @param eventProperties Properties of event
 * @return json as follows
 *
 * {
 * "status": 200,
 * "data": {
 *   null
 *  }
 * }
 *
 */
- (void)customScreenEvent:(NSString *)eventName
      jsonEventProperties:(NSString *)jsonEventProperties
          completionBlock:(BCCompletionBlock)completionBlock
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject;

/**
 * Creates custom data stream track event
 *
 * @param eventName Name of event
 * @param eventProperties Properties of event
 * @return json as follows
 *
 * {
 * "status": 200,
 * "data": {
 *   null
 *  }
 * }
 *
 */
- (void)customTrackEvent:(NSString *)eventName
     jsonEventProperties:(NSString *)jsonEventProperties
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

@end

