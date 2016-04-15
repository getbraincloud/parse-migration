//
//  BrainCloudRedemptionCode.hh
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-10-26.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudRedemptionCode : NSObject

/**
* Redeem a code.
*
* Service Name - RedemptionCode
* Service Operation - REDEEM_CODE
*
* @param scanCode The code to redeem
* @param codeType The type of code
* @param jsonCustomRedemptionInfo Optional - A JSON string containing custom redemption data
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "gameId": "123456",
*         "scanCode": "1200347",
*         "codeType": "default",
*         "version": 2,
*         "codeState": "Redeemed",
*         "customCodeInfo": {},
*         "customRedemptionInfo": {},
*         "redeemedByProfileId": "28adw61e-5634-49ae-9b09-f61930ce6e43",
*         "redeemedByProfileName": "",
*         "invalidationReason": null,
*         "createdAt": 0,
*         "activatedAt": null,
*         "redeemedAt": 1445875694706,
*         "invalidatedAt": null
*     }
* }
*/
- (void)redeemCode:(NSString*)scanCode
              codeType:(NSString*)codeType
  jsonCustomRedemptionInfo:(NSString*)jsonCustomRedemptionInfo
       completionBlock:(BCCompletionBlock)cb
  errorCompletionBlock:(BCErrorCompletionBlock)ecb
              cbObject:(BCCallbackObject)cbObject;

/**
* Retrieve the codes already redeemed by player.
*
* Service Name - RedemptionCode
* Service Operation - GET_REDEEMED_CODES
*
* @param codeType Optional - The type of codes to retrieve. Returns all codes if left unspecified.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "codes": [
*             {
*                 "gameId": "123456",
*                 "scanCode": "999999",
*                 "codeType": "default",
*                 "version": 2,
*                 "codeState": "Redeemed",
*                 "customCodeInfo": {},
*                 "customRedemptionInfo": {},
*                 "redeemedByProfileId": "28d0745e-5634-49ae-9b09-f61930ce6e43",
*                 "redeemedByProfileName": "",
*                 "invalidationReason": null,
*                 "createdAt": 0,
*                 "activatedAt": null,
*                 "redeemedAt": 1445456503428,
*                 "invalidatedAt": null
*             }
*         ]
*     }
* }
*/
- (void)getRedeemedCodes:(NSString*)codeType
       completionBlock:(BCCompletionBlock)cb
  errorCompletionBlock:(BCErrorCompletionBlock)ecb
              cbObject:(BCCallbackObject)cbObject;
@end
