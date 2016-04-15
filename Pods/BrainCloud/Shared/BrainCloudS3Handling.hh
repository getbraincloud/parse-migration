//
//  BrainCloudS3Handling.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-13.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudS3Handling : NSObject

/**
* Sends an array of file details and returns
* the details of any of those files that have changed
*
* Service Name - S3Handling
* Service Operation - GetUpdatedFiles
*
* @param category  Category of files on server to compare against
* @param fileDetailsJson  An array of file details
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns  The JSON returned in the callback is as follows.
* {
*     "status": 200,
*     "data": {
*         "fileDetails": [{
*             "gameId": "12311331",
*             "fileId": "3780516b-14f8-4055-8899-8eaab6ac7e82",
*             "shortName": "Test Doc",
*             "fileName": "testDoc.txt",
*             "type": "g",
*             "subType": "cust",
*             "category": null,
*             "fileSize": 4,
*             "dateUploaded": 1437154770000,
*             "relativeUrl": "/cust/testDoc.txt",
*             "absoluteUrl": "http://internal.braincloudservers.com/s3/portal/g/12311331/cust/testDoc.txt",
*             "md5Hash": "d41d8cd98f00b204e9800998ecf8427e",
*             "md5HashHex" : "b895454d7210f7cb84aab76289ffd39c"
*         }]
*     }
* }
*/
- (void)getUpdatedFiles:(NSString *)category
            fileDetails:(NSString *)details
        completionBlock:(BCCompletionBlock)cb
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject;

/**
* Retrieves the details of custom files stored on the server
*
* Service Name - S3Handling
* Service Operation - GetFileList
*
* @param category  Category of files to retrieve
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @returns  The JSON returned in the callback is as follows.
* {
*     "status": 200,
*     "data": {
*         "fileDetails": [{
*             "gameId": "12311331",
*             "fileId": "3780516b-14f8-4055-8899-8eaab6ac7e82",
*             "shortName": "Test Doc",
*             "fileName": "testDoc.txt",
*             "type": "g",
*             "subType": "cust",
*             "category": null,
*             "fileSize": 4,
*             "dateUploaded": 1437154770000,
*             "relativeUrl": "/cust/testDoc.txt",
*             "absoluteUrl": "http://internal.braincloudservers.com/s3/portal/g/12311331/cust/testDoc.txt",
*             "md5Hash": "d41d8cd98f00b204e9800998ecf8427e",
*             "md5HashHex" : "b895454d7210f7cb84aab76289ffd39c"
*         }]
*     }
* }
*/
- (void)getFileList:(NSString *)category
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

@end
