//
//  BrainCloudProduct.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-04.
//  Copyright (c) 2015 bitHeads. All rights
//  reserved.
//

#import "BrainCloudProfanity.hh"

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

@implementation BrainCloudProfanity

- (void)profanityCheck:(NSString *)text
             languages:(NSString *)languages
             flagEmail:(BOOL)flagEmail
             flagPhone:(BOOL)flagPhone
              flagUrls:(BOOL)flagUrls
       completionBlock:(BCCompletionBlock)completionBlock
  errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
              cbObject:(BCCallbackObject)cbObject
{
    BrainCloudCallback *bcCallback = new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    const char *szLanguages = NULL;
    if (languages != nil)
    {
        szLanguages = [languages UTF8String];
    }
    BrainCloud::BrainCloudClient::getInstance()->getProfanityService()
    ->profanityCheck([text UTF8String], szLanguages, flagEmail, flagPhone, flagUrls, bcCallback);
}


- (void)profanityReplaceText:(NSString *)text
               replaceSymbol:(NSString *)replaceSymbol
                   languages:(NSString *)languages
                   flagEmail:(BOOL)flagEmail
                   flagPhone:(BOOL)flagPhone
                    flagUrls:(BOOL)flagUrls
             completionBlock:(BCCompletionBlock)completionBlock
        errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                    cbObject:(BCCallbackObject)cbObject;
{
    BrainCloudCallback *bcCallback = new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    const char *szLanguages = NULL;
    if (languages != nil)
    {
        szLanguages = [languages UTF8String];
    }
    BrainCloud::BrainCloudClient::getInstance()->getProfanityService()
    ->profanityReplaceText([text UTF8String], [replaceSymbol UTF8String], szLanguages, flagEmail, flagPhone, flagUrls, bcCallback);
}


- (void)profanityIdentifyBadWords:(NSString *)text
                        languages:(NSString *)languages
                        flagEmail:(BOOL)flagEmail
                        flagPhone:(BOOL)flagPhone
                         flagUrls:(BOOL)flagUrls
                  completionBlock:(BCCompletionBlock)completionBlock
             errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                         cbObject:(BCCallbackObject)cbObject;
{
    BrainCloudCallback *bcCallback = new BrainCloudCallback(completionBlock, errorCompletionBlock, cbObject);
    const char *szLanguages = NULL;
    if (languages != nil)
    {
        szLanguages = [languages UTF8String];
    }
    BrainCloud::BrainCloudClient::getInstance()->getProfanityService()
    ->profanityIdentifyBadWords([text UTF8String], szLanguages, flagEmail, flagPhone, flagUrls, bcCallback);
}

@end
