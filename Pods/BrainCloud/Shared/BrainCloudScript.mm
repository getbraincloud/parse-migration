#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

#import "BrainCloudScript.hh"

@implementation BrainCloudScript

- (void)runScript:(NSString *)scriptName
          jsonScriptData:(NSString *)jsonScriptData
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;
{
    BrainCloud::BrainCloudClient::getInstance()->getScriptService()->runScript(
        [scriptName cStringUsingEncoding:NSUTF8StringEncoding],
        [jsonScriptData cStringUsingEncoding:NSUTF8StringEncoding],
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)scheduleRunScriptUTC:(NSString *)scriptName
              jsonScriptData:(NSString *)jsonScriptData
              startDateInUTC:(NSDate *)startDateInUTC
             completionBlock:(BCCompletionBlock)cb
        errorCompletionBlock:(BCErrorCompletionBlock)ecb
                    cbObject:(BCCallbackObject)cbObject
{
    time_t time = [startDateInUTC timeIntervalSince1970];
    struct tm *timeStruct = localtime(&time);

    BrainCloud::BrainCloudClient::getInstance()->getScriptService()->scheduleRunScriptUTC(
        [scriptName UTF8String], [jsonScriptData UTF8String], timeStruct,
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)scheduleRunScriptMinutes:(NSString *)scriptName
                  jsonScriptData:(NSString *)jsonScriptData
                  minutesFromNow:(int)minutesFromNow
                 completionBlock:(BCCompletionBlock)cb
            errorCompletionBlock:(BCErrorCompletionBlock)ecb
                        cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getScriptService()->scheduleRunScriptMinutes(
        [scriptName UTF8String], [jsonScriptData UTF8String], minutesFromNow,
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)runParentScript:(NSString *)scriptName
          jsonScriptData:(NSString *)jsonScriptData
         parentLevelName:(NSString *)parentLevelName
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getScriptService()->runParentScript(
        [scriptName UTF8String], [jsonScriptData UTF8String], [parentLevelName UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

@end