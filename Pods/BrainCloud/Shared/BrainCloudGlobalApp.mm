//
//  BrainCloudGlobalApp.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-10.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import "BrainCloudGlobalApp.hh"

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

@implementation BrainCloudGlobalApp

- (void)readProperties:(BCCompletionBlock)completionBlock
  errorCompletionBlock:(BCErrorCompletionBlock)ecb
              cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGlobalAppService()->readProperties(
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

@end