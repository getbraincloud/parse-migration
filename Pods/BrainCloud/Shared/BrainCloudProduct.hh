//
//  BrainCloudProduct.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-04.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudProduct : NSObject

/**
* Award player the passed-in amount of currency. Returns
* JSON representing the new currency values.
*
* Service Name - Product
* Service Operation - AwardVC
*
* @param currencyType The currency type to award
* @param amount The amount of currency to award
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data": {
*     "updatedAt": 1395693913234,
*     "currencyMap": {
*       "gems": {
*         "purchased": 0,
*         "balance": 0,
*         "consumed": 0,
*         "awarded": 0
*       },
*       "gold": {
*         "purchased": 0,
*         "balance": 123,
*         "consumed": 0,
*         "awarded": 123
*       }
*     },
*     "playerId": "acf11847-055f-470d-abb7-b93052201491",
*     "createdAt": 1395693907421
*   }
* }
*/
- (void)awardCurrency:(NSString *)currencyType
               amount:(int)amount
      completionBlock:(BCCompletionBlock)completionBlock
 errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
             cbObject:(BCCallbackObject)cbObject;

/**
* Consume the passed-in amount of currency from the player.
*
* Service Name - Product
* Service Operation - ConsumePlayerVC
*
* @param currencyType The currency type to consume.
* @param amount The amount of currency to consume.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data": {
*     "updatedAt": 1395693913234,
*     "currencyMap": {
*       "gems": {
*         "purchased": 0,
*         "balance": 0,
*         "consumed": 0,
*         "awarded": 0
*       },
*       "gold": {
*         "purchased": 0,
*         "balance": 0,
*         "consumed": 123,
*         "awarded": 123
*       }
*     },
*     "playerId": "acf11847-055f-470d-abb7-b93052201491",
*     "createdAt": 1395693907421
*   }
* }
*/
- (void)consumeCurrency:(NSString *)currencyType
                 amount:(int)amount
        completionBlock:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
               cbObject:(BCCallbackObject)cbObject;

/**
* Gets the player's currency for the given currency type
* or all currency types if null passed in.
*
* Service Name - Product
* Service Operation - GetPlayerVC
*
* @param currencyType The currency type to retrieve or null
* if all currency types are being requested.
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data": {
*     "updatedAt": 1395693676208,
*     "currencyMap": {
*       "gold": {
*         "purchased": 0,
*         "balance": 0,
*         "consumed": 0,
*         "awarded": 0
*       }
*     },
*     "playerId": "6ea79853-4025-4159-8014-60a6f17ac4e6",
*     "createdAt": 1395693676208
*   }
* }
*/
- (void)getCurrency:(NSString *)currencyType
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                cbObject:(BCCallbackObject)cbObject;

/**
* Resets the player's currency back to zero.
*
* Service Name - Product
* Service Operation - ResetPlayerVC
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":null
* }
*/
- (void)resetCurrency:(BCCompletionBlock)completionBlock
 errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
             cbObject:(BCCallbackObject)cbObject;

/**
* Get Eligible Promotions
*
* Service Name - Product
* Service Operation - GetEligiblePromotions
*
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data":
*   {
*      {
* "promotions": [
*  {
*   "gameId": "10019",
*   "promotionId": 9,
*   "type": "SCHEDULED",
*   "name": "session >= 2",
*   "message": "test1",
*   "enabled": true,
*   "targetAllUsers": false,
*   "segments": [
*    5
*   ],
*   "prices": [
*    {
*     "itemId": "regGems150",
*     "priceId": 1
*    }
*   ],
*   "notifications": [
*    {
*     "trigger": "ACTIVATED",
*     "notificationTemplateId": 10
*    }
*   ],
*   "startAt": 1415374185745,
*   "endAt": 1415806185745,
*   "createdAt": 0,
*   "updatedAt": 1415729753294
*  }
* ]
*}
*   }
* }
*/
- (void)getEligiblePromotions:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                     cbObject:(BCCallbackObject)cbObject;

/**
* Method gets the active sales inventory for the passed-in platform and
* currency type.
*
* Service Name - Product
* Service Operation - GetInventory
*
* @param platform The store platform. Valid stores are:
* - itunes
* - facebook
* - appworld
* - steam
* - windows
* - windowsPhone
* - googlePlay
* @param userCurrency The currency to retrieve the sales
* inventory for. This is only used for Steam and Facebook stores.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":{
*      "product_inventory":[
*          {
*              "gameId":"com.roger.football",
*              "itemId":"0000001",
*              "title":"Item 0000001",
*              "description":"Buy 5 footballs",
*              "imageUrl":"http:",
*              "fbUrl":"http:",
*              "currency":{"footballs":5},
*              "priceData":{"currency":"USD","price":1000}
*           }
*       ],
*       "server_time":1398960658981
*    }
* }
*/
- (void)getSalesInventory:(NSString *)platform
             userCurrency:(NSString *)userCurrency
          completionBlock:(BCCompletionBlock)completionBlock
     errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                 cbObject:(BCCallbackObject)cbObject;

/**
* Method gets the active sales inventory for the passed-in platform,
* currency type and category.
*
* Service Name - Product
* Service Operation - GetInventory
*
* @param platform The store platform. Valid stores are:
* - itunes
* - facebook
* - appworld
* - steam
* - windows
* - windowsPhone
* - googlePlay
* @param userCurrency The currency to retrieve the sales
* inventory for. This is only used for Steam and Facebook stores.
* @param category Inventory category to retrieve
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":{
*      "product_inventory":[
*          {
*              "gameId":"com.roger.football",
*              "itemId":"0000001",
*              "title":"Item 0000001",
*              "description":"Buy 5 footballs",
*              "imageUrl":"http:",
*              "fbUrl":"http:",
*              "currency":{"footballs":5},
*              "priceData":{"currency":"USD","price":1000}
*           }
*       ],
*       "server_time":1398960658981
*    }
* }
*/
- (void)getSalesInventoryByCategory:(NSString *)platform
                       userCurrency:(NSString *)userCurrency
                           category:(NSString *)category
                    completionBlock:(BCCompletionBlock)completionBlock
               errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                           cbObject:(BCCallbackObject)cbObject;

/**
* Initialize Steam Transaction
*
* Service Name - Product
* Service Operation - StartSteamTransaction
*
* @param language ISO 639-1 language code
* @param items Items to purchase
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data":
*   {
*      "steamStatus" : 200,
*      "steamData" :
*      {
*      }
*   }
* }
*/
- (void)startSteamTransaction:(NSString *)language
                       itemId:(NSString *)itemId
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                     cbObject:(BCCallbackObject)cbObject;

/**
* Finalize Steam Transaction. On success, the player will be awarded the
* associated currencies.
*
* Service Name - Product
* Service Operation - FinalizeSteamTransaction
*
* @param transId Steam transaction id
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data":
*   {
*      "steamStatus" : 200,
*      "steamData" :
*      {
*      }
*   }
* }
*/
- (void)finalizeSteamTransaction:(NSString *)transId
                 completionBlock:(BCCompletionBlock)completionBlock
            errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                        cbObject:(BCCallbackObject)cbObject;

/**
* Verify Microsoft Receipt. On success, the player will be awarded the
* associated currencies.
*
* Service Name - Product
* Service Operation - VerifyMicrosoftReceipt
*
* @param receipt Receipt XML
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data":
*   {
*      "result" : "OK"
*   }
* }
*/
- (void)verifyMicrosoftReceipt:(NSString *)receipt
               completionBlock:(BCCompletionBlock)completionBlock
          errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                      cbObject:(BCCallbackObject)cbObject;

/**
* Method verifies an iTunes receipt and awards the items related to this receipt.
*
* Service Name - Product
* Server Operation - OP_CASH_RECEIPT
*
* @param base64EncReceiptData The iTunes receipt
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data":
*   {
*      "playerCurrency" : {
*         "playerId" : "sfhsjdfhfjhf",
*         "currencyMap" : {
*             "coin" : {
*                 "purchased" : NumberLong(0),
*                 "balance" : NumberLong(5000),
*                 "consumed" : NumberLong(0),
*                 "awarded" : NumberLong(5000)
*             },
*             "bar" : {
*                 "purchased" : NumberLong(0),
*                 "balance" : NumberLong(2),
*                 "consumed" : NumberLong(0),
*                 "awarded" : NumberLong(2)
*             }
*         },
*         "createdAt" : 763578645786,
*         "updatedAt" : 8692486255764,
*       },
*       "appleReceipt" : "gsgsfvgvg",
*       "status" : 0,
*       "server_time" : 987490827457
*   }
* }
*/
- (void)verifyItunesReceipt:(NSString *)base64EncReceiptData
            completionBlock:(BCCompletionBlock)completionBlock
       errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                   cbObject:(BCCallbackObject)cbObject;

/**
* Confirms a google play purchase. On success, the player will be awarded the
* associated currencies.
*
* Service Name - Product
* Server Operation - CONFIRM_GOOGLEPLAY_PURCHASE
*
* @param orderId The order id
* @param productId The product id
* @param token Google Play token string
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
* @return The JSON returned in the completion block is as follows:
* {
*   "status": 200,
*   "data":
*   {
*      "result" : "OK"
*   }
* }
*/
- (void)confirmGooglePlayPurchase:(NSString *)orderId
                        productId:(NSString *)productId
                            token:(NSString *)token
                  completionBlock:(BCCompletionBlock)completionBlock
             errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                         cbObject:(BCCallbackObject)cbObject;

/**
* Awards currency in a parent app.
*
* Service Name - Product
* Service Operation - AWARD_PARENT_VC
*
* @param in_currencyType The ID of the parent currency
* @param in_amount The amount of currency to award
* @param in_parentLevel The level of the parent containing the currency
* @param in_callback The method to be invoked when the server response is received
*
* @return The JSON returned in the callback is as follows:
* {
*   "status":200,
*   "data": {
*     "updatedAt": 1395693913234,
*     "currencyMap": {
*       "gems": {
*         "purchased": 0,
*         "balance": 0,
*         "consumed": 0,
*         "awarded": 0
*       },
*       "gold": {
*         "purchased": 0,
*         "balance": 123,
*         "consumed": 0,
*         "awarded": 123
*       }
*     },
*     "playerId": "acf11847-055f-470d-abb7-b93052201491",
*     "createdAt": 1395693907421
*   }
* }
*/
- (void)awardParentCurrency:(NSString *)currencyType
                     amount:(int)amount
                parentLevel:(NSString *)parentLevel
            completionBlock:(BCCompletionBlock)completionBlock
       errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                   cbObject:(BCCallbackObject)cbObject;

/**
* Consumes currency in a parent app.
*
* Service Name - Product
* Service Operation - CONSUME_PARENT_VC
*
* @param in_currencyType The ID of the parent currency
* @param in_amount The amount of currency to consume
* @param in_parentLevel The level of the parent containing the currency
* @param in_callback The method to be invoked when the server response is received
*
* @return The JSON returned in the callback is as follows:
* {
*   "status":200,
*   "data": {
*     "updatedAt": 1395693913234,
*     "currencyMap": {
*       "gems": {
*         "purchased": 0,
*         "balance": 0,
*         "consumed": 0,
*         "awarded": 0
*       },
*       "gold": {
*         "purchased": 0,
*         "balance": 123,
*         "consumed": 0,
*         "awarded": 123
*       }
*     },
*     "playerId": "acf11847-055f-470d-abb7-b93052201491",
*     "createdAt": 1395693907421
*   }
* }
*/
- (void)consumeParentCurrency:(NSString *)currencyType
                       amount:(int)amount
                  parentLevel:(NSString *)parentLevel
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                     cbObject:(BCCallbackObject)cbObject;

/**
* Gets information on a single currency in a parent app
* or all currency types if a null type is passed in.
*
* Service Name - Product
* Service Operation - GET_PARENT_VC
*
* @param currencyType The ID of the parent currency or null to get all currencies
* @param parentLevel The level of the parent containing the currency
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data": {
*     "updatedAt": 1395693913234,
*     "currencyMap": {
*       "gems": {
*         "purchased": 0,
*         "balance": 0,
*         "consumed": 0,
*         "awarded": 0
*       }
*     },
*     "playerId": "acf11847-055f-470d-abb7-b93052201491",
*     "createdAt": 1395693907421
*   }
* }
*/
- (void)getParentCurrency:(NSString *)currencyType
              parentLevel:(NSString *)parentLevel
          completionBlock:(BCCompletionBlock)completionBlock
     errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                 cbObject:(BCCallbackObject)cbObject;

/**
* Resets all currencies in a parent app.
*
* Service Name - Product
* Service Operation - RESET_PARENT_VC
*
* @param parentLevel The level of the parent containing the currencies
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": null
* }
*/
- (void)resetParentCurrency:(NSString *)parentLevel
            completionBlock:(BCCompletionBlock)completionBlock
       errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                   cbObject:(BCCallbackObject)cbObject;

@end
