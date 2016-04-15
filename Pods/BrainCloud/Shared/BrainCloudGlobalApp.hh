//
//  BrainCloudGlobalApp.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-10.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudGlobalApp : NSObject

/**
* Read game's global properties
*
* Service Name - GlobalApp
* Service Operation - ReadProperties
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return JSON describing the global properties:
* {
*   "status":200,
*   "data":{
*     {
*        "pName": {
*         "name": "pName",
*         "description": "pValue",
*         "value": "pDescription"
*        }
*       }
*   }
* }
*/
- (void)readProperties:(BCCompletionBlock)completionBlock
  errorCompletionBlock:(BCErrorCompletionBlock)ecb
              cbObject:(BCCallbackObject)cbObject;

@end
