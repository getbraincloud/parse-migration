//
//  BrainCloudFile.m
//  brainCloudClientObjc
//
//  Created by Preston Jennings on 2016-01-21.
//  Copyright © 2016 bitHeads. All rights reserved.
//

#import "BrainCloudFile.hh"

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

@implementation BrainCloudFile

- (bool)uploadFile:(NSString *)cloudPath
     cloudFilename:(NSString *)cloudFilename
         shareable:(bool)shareable
   replaceIfExists:(bool)replaceIfExists
         localPath:(NSString *)localPath
   completionBlock:(BCCompletionBlock)cb
errorCompletionBlock:(BCErrorCompletionBlock)ecb
          cbObject:(BCCallbackObject)cbObject;
{
    BrainCloudCallback * bcb = new BrainCloudCallback(cb, ecb, cbObject);
    bool res = BrainCloud::BrainCloudClient::getInstance()->
    getFileService()->uploadFile(
                                 [cloudPath UTF8String],
                                 [cloudFilename UTF8String],
                                 shareable,
                                 replaceIfExists,
                                 [localPath UTF8String],
                                 bcb);
    if (!res)
    {
        delete bcb;
        bcb = NULL;
    }
    return res;
}

- (void)listUserFiles:(BCCompletionBlock)cb
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->
    getFileService()->listUserFiles(new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)listUserFiles:(NSString *)cloudPath
              recurse:(bool)recurse
      completionBlock:(BCCompletionBlock)cb
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->
    getFileService()->listUserFiles([cloudPath UTF8String], recurse, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)deleteUserFile:(NSString *)cloudPath
         cloudFilename:(NSString *)cloudFilename
       completionBlock:(BCCompletionBlock)cb
  errorCompletionBlock:(BCErrorCompletionBlock)ecb
              cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->
    getFileService()->deleteUserFile([cloudPath UTF8String], [cloudFilename UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)deleteUserFiles:(NSString *)cloudPath
                recurse:(bool)recurse
        completionBlock:(BCCompletionBlock)cb
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->
    getFileService()->deleteUserFiles([cloudPath UTF8String], recurse, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void) cancelUpload:(NSString *)uploadId
{
    BrainCloud::BrainCloudClient::getInstance()->
    getFileService()->cancelUpload([uploadId UTF8String]);
}

- (double) getUploadProgress:(NSString *)uploadId
{
    return BrainCloud::BrainCloudClient::getInstance()->
    getFileService()->getUploadProgress([uploadId UTF8String]);
}

- (NSInteger) getUploadBytesTransferred:(NSString *)uploadId
{
    return BrainCloud::BrainCloudClient::getInstance()->
    getFileService()->getUploadBytesTransferred([uploadId UTF8String]);
}


- (NSInteger) getUploadTotalBytesToTransfer:(NSString *)uploadId
{
    return BrainCloud::BrainCloudClient::getInstance()->
    getFileService()->getUploadTotalBytesToTransfer([uploadId UTF8String]);
}

@end
