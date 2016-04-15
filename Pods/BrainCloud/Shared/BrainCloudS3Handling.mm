//
//  BrainCloudS3Handling.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-13.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

#import "BrainCloudS3Handling.hh"

@implementation BrainCloudS3Handling

- (void)getUpdatedFiles:(NSString *)category
            fileDetails:(NSString *)details
        completionBlock:(BCCompletionBlock)cb
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getS3HandlingService()->getUpdatedFiles(
        [category UTF8String], [details UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getFileList:(NSString *)category
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getS3HandlingService()->getFileList(
        [category UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

@end
