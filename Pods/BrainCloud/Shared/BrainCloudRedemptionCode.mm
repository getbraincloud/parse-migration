//
//  BrainCloudRedemptionCode.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-10-26.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

#import "BrainCloudRedemptionCode.hh"

@implementation BrainCloudRedemptionCode

- (void)redeemCode:(NSString*)scanCode
              codeType:(NSString*)codeType
  jsonCustomRedemptionInfo:(NSString*)jsonCustomRedemptionInfo
       completionBlock:(BCCompletionBlock)cb
  errorCompletionBlock:(BCErrorCompletionBlock)ecb
              cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getRedemptionCodeService()->redeemCode(
        [scanCode UTF8String], [codeType UTF8String], [jsonCustomRedemptionInfo UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getRedeemedCodes:(NSString*)codeType
       completionBlock:(BCCompletionBlock)cb
  errorCompletionBlock:(BCErrorCompletionBlock)ecb
              cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getRedemptionCodeService()->getRedeemedCodes(
        [codeType UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

@end
