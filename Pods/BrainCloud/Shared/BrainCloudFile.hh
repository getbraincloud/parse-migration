//
//  BrainCloudFile.h
//  brainCloudClientObjc
//
//  Created by Preston Jennings on 2016-01-21.
//  Copyright © 2016 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudFile : NSObject

/**
 * Prepares a user file upload. On success the file will begin uploading
 * to the brainCloud server. To be informed of success/failure of the upload
 * register an IFileUploadCallback with the BrainCloudClient class.
 *
 * @param cloudPath The desired cloud path of the file
 * @param cloudFilename The desired cloud filename of the file
 * @param shareable True if the file is shareable.
 * @param replaceIfExists Whether to replace file if it exists
 * @param localPath The path and filename of the local file
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 * @return A bool which is false if the file cannot be found, or file size cannot be determind.
 * Otherwise the JSON returned in the callback is as follows
 * {
 *  "status": 200,
 *  "data": {
 *   "fileDetails": {
 *    "updatedAt": 1452616408147,
 *    "fileSize": 100,
 *    "fileType": "User",
 *    "expiresAt": 1452702808146,
 *    "shareable": true,
 *    "uploadId": "cf9a075c-587e-4bd1-af0b-eab1a79b958f",
 *    "createdAt": 1452616408147,
 *    "profileId": "bf8a1433-62d2-448e-b396-f3dbffff44",
 *    "gameId": "99999",
 *    "path": "dir1/dir2",
 *    "filename": "filename",
 *    "replaceIfExists": true,
 *    "cloudPath": "bc/g/99999/u/bf8a1433-62d2-448e-b396-f3dbffff44/f/dir1/dir2/filename"
 *   }
 *  }
 * }
 *
 * Significant error codes:
 *
 * 40429 - File maximum file size exceeded
 * 40430 - File exists, replaceIfExists not set
 */
- (bool)uploadFile:(NSString *)cloudPath
cloudFilename:(NSString *)cloudFilename
shareable:(bool)shareable
replaceIfExists:(bool)replaceIfExists
localPath:(NSString *)localPath
completionBlock:(BCCompletionBlock)cb
errorCompletionBlock:(BCErrorCompletionBlock)ecb
cbObject:(BCCallbackObject)cbObject;


/**
 * List all user files
 *
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 * @return The JSON returned in the callback is as follows
 * {
 *  "status": 200,
 *  "data": {
 *   "fileList": [
 *    {
 *     "updatedAt": 1452603368201,
 *     "uploadedAt": null,
 *     "fileSize": 85470,
 *     "shareable": true,
 *     "createdAt": 1452603368201,
 *     "profileId": "bf8a1433-62d2-448e-b396-f3dbffff44",
 *     "gameId": "99999",
 *     "path": "test2",
 *     "filename": "testup.dat",
 *     "downloadUrl": "https://sharedprod.braincloudservers.com/s3/bc/g/99999/u/bf8a1433-62d2-448e-b396-f3dbffff44/f/test2/testup.dat"
 *     "cloudLocation": "bc/g/99999/u/bf8a1433-62d2-448e-b396-f3dbffff44/f/test2/testup.dat"
 *    }
 *   ]
 *  }
 * }
 *
 */
- (void)listUserFiles:(BCCompletionBlock)cb
errorCompletionBlock:(BCErrorCompletionBlock)ecb
cbObject:(BCCallbackObject)cbObject;

/**
 * List all user files
 *
 * @param cloudPath File path
 * @param recurse Whether to recurse into sub-directories
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 * @return The JSON returned in the callback is as follows
 * {
 *  "status": 200,
 *  "data": {
 *   "fileList": [
 *    {
 *     "updatedAt": 1452603368201,
 *     "uploadedAt": null,
 *     "fileSize": 85470,
 *     "shareable": true,
 *     "createdAt": 1452603368201,
 *     "profileId": "bf8a1433-62d2-448e-b396-f3dbffff44",
 *     "gameId": "99999",
 *     "path": "test2",
 *     "filename": "testup.dat",
 *     "downloadUrl": "https://sharedprod.braincloudservers.com/s3/bc/g/99999/u/bf8a1433-62d2-448e-b396-f3dbffff44/f/test2/testup.dat"
 *     "cloudLocation": "bc/g/99999/u/bf8a1433-62d2-448e-b396-f3dbffff44/f/test2/testup.dat"
 *    }
 *   ]
 *  }
 * }
 *
 */
- (void)listUserFiles:(NSString *)cloudPath
recurse:(bool)recurse
completionBlock:(BCCompletionBlock)cb
errorCompletionBlock:(BCErrorCompletionBlock)ecb
cbObject:(BCCallbackObject)cbObject;

/**
 * Deletes a single user file.
 *
 * @param in_cloudPath File path
 * @param in_cloudFilename name of file
 * @param in_callback The method to be invoked when the server response is received
 * @return The JSON returned in the callback is as follows
 * {
 *  "status": 200,
 *  "data": {
 *   "fileDetails": {
 *     "updatedAt": 1452603368201,
 *     "uploadedAt": null,
 *     "fileSize": 85470,
 *     "shareable": true,
 *     "createdAt": 1452603368201,
 *     "profileId": "bf8a8733-62d2-448e-b396-f3dbffff44",
 *     "gameId": "99999",
 *     "path": "test2",
 *     "filename": "testup.dat",
 *     "downloadUrl": "https://sharedprod.braincloudservers.com/s3/bc/g/99999/u/bf8a1433-62d2-448e-b396-f3dbffff44/f/test2/testup.dat"
 *     "cloudLocation": "bc/g/99999/u/bf8a1433-62d2-448e-b396-f3dbffff44/f/test2/testup.dat"
 *   }
 *  }
 * }
 *
 * Significant error codes:
 *
 * 40431 - Cloud storage service error
 * 40432 - File does not exist
 *
 */
- (void)deleteUserFile:(NSString *)cloudPath
cloudFilename:(NSString *)cloudFilename
completionBlock:(BCCompletionBlock)cb
errorCompletionBlock:(BCErrorCompletionBlock)ecb
cbObject:(BCCallbackObject)cbObject;


/**
 * Delete multiple user files
 *
 * @param in_cloudPath File path
 * @param in_recurse Whether to recurse into sub-directories
 * @param in_callback The method to be invoked when the server response is received
 * @return The JSON returned in the callback is as follows
 * {
 *  "status": 200,
 *  "data": {
 *   "fileList": [
 *    {
 *     "updatedAt": 1452603368201,
 *     "uploadedAt": null,
 *     "fileSize": 85470,
 *     "shareable": true,
 *     "createdAt": 1452603368201,
 *     "profileId": "bf8a1433-62d2-448e-b396-f3dbffff44",
 *     "gameId": "99999",
 *     "path": "test2",
 *     "filename": "testup.dat",
 *     "downloadUrl": "https://sharedprod.braincloudservers.com/s3/bc/g/99999/u/bf8a1433-62d2-448e-b396-f3dbffff44/f/test2/testup.dat"
 *     "cloudLocation": "bc/g/99999/u/bf8a1433-62d2-448e-b396-f3dbffff44/f/test2/testup.dat"
 *    }
 *   ]
 *  }
 * }
 *
 */
- (void)deleteUserFiles:(NSString *)cloudPath
recurse:(bool)recurse
completionBlock:(BCCompletionBlock)cb
errorCompletionBlock:(BCErrorCompletionBlock)ecb
cbObject:(BCCallbackObject)cbObject;


/**
 * Method cancels an upload. If an IFileUploadCallback has been registered with the BrainCloudClient class,
 * the fileUploadFailed callback method will be called once the upload has been canceled.
 *
 * @param in_uploadId The id of the upload
 */
- (void) cancelUpload:(NSString *)uploadId;

/**
 * Returns the progress of the given upload from 0.0 to 1.0
 * or -1 if upload not found.
 *
 * @param in_uploadId The id of the upload
 * @return A progress from 0.0 to 1.0 or -1 if upload not found.
 */
- (double) getUploadProgress:(NSString *)uploadId;

/**
 * Returns the number of bytes uploaded or -1 if upload not found.
 *
 * @param in_uploadId The id of the upload
 * @return The number of bytes uploaded or -1 if upload not found.
 */
- (NSInteger) getUploadBytesTransferred:(NSString *)uploadId;

/**
 * Returns the total number of bytes that will be uploaded or -1 if upload not found.
 *
 * @param in_uploadId The id of the upload
 * @return The total number of bytes that will be uploaded or -1 if upload not found.
 */
- (NSInteger) getUploadTotalBytesToTransfer:(NSString *)uploadId;

@end
