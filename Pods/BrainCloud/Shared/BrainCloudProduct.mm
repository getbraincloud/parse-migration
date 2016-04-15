//
//  BrainCloudProduct.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-04.
//  Copyright (c) 2015 bitHeads. All rights
//  reserved.
//

#import "BrainCloudProduct.hh"

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

@implementation BrainCloudProduct

- (void)awardCurrency:(NSString *)currencyType
               amount:(int)amount
      completionBlock:(BCCompletionBlock)completionBlock
 errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
             cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->awardCurrency(
        [currencyType UTF8String], amount, bcCallback);
}

- (void)consumeCurrency:(NSString *)currencyType
                 amount:(int)amount
        completionBlock:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
               cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->consumeCurrency(
        [currencyType UTF8String], amount, bcCallback);
}

- (void)getCurrency:(NSString *)currencyType
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->getCurrency(
        [currencyType UTF8String], bcCallback);
}

- (void)resetCurrency:(BCCompletionBlock)completionBlock
 errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
             cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->resetCurrency(bcCallback);
}

- (void)getEligiblePromotions:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->getEligiblePromotions(
        bcCallback);
}

- (void)getSalesInventory:(NSString *)platform
             userCurrency:(NSString *)userCurrency
          completionBlock:(BCCompletionBlock)completionBlock
     errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->getSalesInventory(
        [platform UTF8String], [userCurrency UTF8String], bcCallback);
}

- (void)getSalesInventoryByCategory:(NSString *)platform
                       userCurrency:(NSString *)userCurrency
                           category:(NSString *)category
                    completionBlock:(BCCompletionBlock)completionBlock
               errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                           cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->getSalesInventoryByCategory(
        [platform UTF8String], [userCurrency UTF8String], [category UTF8String], bcCallback);
}

- (void)startSteamTransaction:(NSString *)language
                       itemId:(NSString *)itemId
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->startSteamTransaction(
        [language UTF8String], [itemId UTF8String], bcCallback);
}

- (void)finalizeSteamTransaction:(NSString *)transId
                 completionBlock:(BCCompletionBlock)completionBlock
            errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                        cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->finalizeSteamTransaction(
        [transId UTF8String], bcCallback);
}

- (void)verifyMicrosoftReceipt:(NSString *)receipt
               completionBlock:(BCCompletionBlock)completionBlock
          errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                      cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->verifyMicrosoftReceipt(
        [receipt UTF8String], bcCallback);
}

- (void)verifyItunesReceipt:(NSString *)base64EncReceiptData
            completionBlock:(BCCompletionBlock)completionBlock
       errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->verifyItunesReceipt(
        [base64EncReceiptData UTF8String], bcCallback);
}

- (void)confirmGooglePlayPurchase:(NSString *)orderId
                        productId:(NSString *)productId
                            token:(NSString *)token
                  completionBlock:(BCCompletionBlock)completionBlock
             errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                         cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->confirmGooglePlayPurchase(
        [orderId UTF8String], [productId UTF8String], [token UTF8String], bcCallback);
}

- (void)awardParentCurrency:(NSString *)currencyType
                     amount:(int)amount
                parentLevel:(NSString *)parentLevel
            completionBlock:(BCCompletionBlock)completionBlock
       errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->awardParentCurrency(
        [currencyType UTF8String], amount, [parentLevel UTF8String], bcCallback);
}

- (void)consumeParentCurrency:(NSString *)currencyType
                       amount:(int)amount
                  parentLevel:(NSString *)parentLevel
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->consumeParentCurrency(
        [currencyType UTF8String], amount, [parentLevel UTF8String], bcCallback);
}

- (void)getParentCurrency:(NSString *)currencyType
              parentLevel:(NSString *)parentLevel
          completionBlock:(BCCompletionBlock)completionBlock
     errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->getParentCurrency(
        [currencyType UTF8String], [parentLevel UTF8String], bcCallback);
}

- (void)resetParentCurrency:(NSString *)parentLevel
            completionBlock:(BCCompletionBlock)completionBlock
       errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback =
        new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    BrainCloud::BrainCloudClient::getInstance()->getProductService()->resetParentCurrency(
        [parentLevel UTF8String], bcCallback);
}

@end
