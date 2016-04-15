//
//  BrainCloudGlobalEntity.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-06.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudGlobalEntity : NSObject

/**
* Method creates a new entity on the server.
*
* Service Name - GlobalEntity
* Service Operation - Create
*
* @param entityType The entity type as defined by the user
* @param timeToLive Sets expiry time for entity in milliseconds if > 0
* @param jsonEntityAcl The entity's access control list as json. A null acl implies default
* @param jsonEntityData  The entity's data as a json string
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":
*   {
*      gameId : "game",
*      entityId : "hucfshugvgvfhug",
*      ownerId : "ubfcbvfbsdvbb",
*      entityType : "",
*      entityIndexedId : "",
*      version : 1,
*      timeToLive: 0,
*      expiresAt : 9947395735758975,
*      data :
*      {
*          field : "value"
*      },
*      acl :
*      {
*          other, 1
*      },
*      createdAt : 74889479874,
*      updatedAt : 73847474897487
*
*   }
* }
*/
- (void)createEntity:(NSString *)entityType
          timeToLive:(int64_t)timeToLive
       jsonEntityAcl:(NSString *)jsonEntityAcl
      jsonEntityData:(NSString *)jsonEntityData
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject;

/**
* Method creates a new entity on the server with an indexed id.
*
* Service Name - GlobalEntity
* Service Operation - CreateWithIndexedId
*
* @param entityType The entity type as defined by the user
* @param indexedId A secondary ID that will be indexed
* @param timeToLive Sets expiry time for entity in milliseconds if > 0
* @param jsonEntityAcl The entity's access control list as json. A null acl implies default
* @param jsonEntityData  The entity's data as a json string
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":
*   {
*      gameId : "game",
*      entityId : "hucfshugvgvfhug",
*      ownerId : "ubfcbvfbsdvbb",
*      entityType : "",
*      entityIndexedId : "hhjdyjghjd",
*      version : 1,
*      timeToLive: 0,
*      expiresAt : 9947395735758975,
*      data :
*      {
*          field : "value"
*      },
*      acl :
*      {
*          other, 1
*      },
*      createdAt : 74889479874,
*      updatedAt : 73847474897487
*
*   }
* }
*/
- (void)createEntityWithIndexedId:(NSString *)entityType
                        indexedId:(NSString *)indexedId
                       timeToLive:(int64_t)timeToLive
                    jsonEntityAcl:(NSString *)jsonEntityAcl
                   jsonEntityData:(NSString *)jsonEntityData
                  completionBlock:(BCCompletionBlock)completionBlock
             errorCompletionBlock:(BCErrorCompletionBlock)ecb
                         cbObject:(BCCallbackObject)cbObject;

/**
* Method updates an existing entity on the server.
*
* Service Name - GlobalEntity
* Service Operation - Update
*
* @param entityId The entity ID
* @param version The version of the entity to update
* @param jsonEntityData  The entity's data as a json string
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":
*   {
*      gameId : "game",
*      entityId : "hucfshugvgvfhug",
*      ownerId : "ubfcbvfbsdvbb",
*      entityType : "",
*      entityIndexedId : "",
*      version : 1,
*      timeToLive: 0,
*      expiresAt : 9947395735758975,
*      data :
*      {
*          field : "value"
*      },
*      acl :
*      {
*          other, 1
*      },
*      createdAt : 74889479874,
*      updatedAt : 73847474897487
*
*   }
* }
*/
- (void)updateEntity:(NSString *)entityId
             version:(int64_t)version
      jsonEntityData:(NSString *)jsonEntityData
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject;

/**
* Method updates an existing entity's Acl on the server.
*
* Service Name - GlobalEntity
* Service Operation - UpdateAcl
*
* @param entityId The entity ID
* @param version The version of the entity to update
* @param jsonEntityAcl The entity's access control list as json.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":
*   {
*      gameId : "game",
*      entityId : "hucfshugvgvfhug",
*      ownerId : "ubfcbvfbsdvbb",
*      entityType : "",
*      entityIndexedId : "",
*      version : 1,
*      timeToLive: 0,
*      expiresAt : 9947395735758975,
*      data :
*      {
*          field : "value"
*      },
*      acl :
*      {
*          other, 1
*      },
*      createdAt : 74889479874,
*      updatedAt : 73847474897487
*
*   }
* }
*/
- (void)updateEntityAcl:(NSString *)entityId
                version:(int64_t)version
          jsonEntityAcl:(NSString *)jsonEntityAcl
        completionBlock:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject;

/**
* Method updates an existing entity's time to live on the server.
*
* Service Name - GlobalEntity
* Service Operation - UpdateTimeToLive
*
* @param entityId The entity ID
* @param version The version of the entity to update
* @param timeToLive Sets expiry time for entity in milliseconds if > 0
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":
*   {
*      gameId : "game",
*      entityId : "hucfshugvgvfhug",
*      ownerId : "ubfcbvfbsdvbb",
*      entityType : "",
*      entityIndexedId : "",
*      version : 1,
*      data :
*      timeToLive: 0,
*      expiresAt : 9947395735758975,
*      {
*          field : "value"
*      },
*      acl :
*      {
*          other, 1
*      },
*      createdAt : 74889479874,
*      updatedAt : 73847474897487
*
*   }
* }
*/
- (void)updateEntityTimeToLive:(NSString *)entityId
                       version:(int64_t)version
                    timeToLive:(int64_t)timeToLive
               completionBlock:(BCCompletionBlock)completionBlock
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject;

/**
* Method deletes an existing entity on the server.
*
* Service Name - GlobalEntity
* Service Operation - Delete
*
* @param entityId The entity ID
* @param version The version of the entity to delete
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":
*   {
*   }
* }
*/
- (void)deleteEntity:(NSString *)entityId
             version:(int64_t)version
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject;

/**
* Method reads an existing entity from the server.
*
* Service Name - GlobalEntity
* Service Operation - Read
*
* @param entityId The entity ID
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":
*   {
*      gameId : "game",
*      entityId : "hucfshugvgvfhug",
*      ownerId : "ubfcbvfbsdvbb",
*      entityType : "",
*      entityIndexedId : "",
*      version : 1,
*      timeToLive: 0,
*      expiresAt : 9947395735758975,
*      data :
*      {
*          field : "value"
*      },
*      acl :
*      {
*          other, 1
*      },
*      createdAt : 74889479874,
*      updatedAt : 73847474897487
*
*   }
* }
*/
- (void)readEntity:(NSString *)entityId
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Method gets list of entities from the server base on type and/or where clause
*
* Service Name - GlobalEntity
* Service Operation - GetList
*
* @param where Mongo style query string
* @param orderBy Sort order
* @param maxReturn The maximum number of entities to return
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":
*   {
*      entities : [
*          {
*              gameId : "game",
*              entityId : "hucfshugvgvfhug",
*              ownerId : "ubfcbvfbsdvbb",
*              entityType : "",
*              entityIndexedId : "",
*              version : 1,
*              timeToLive: 0,
*              expiresAt : 9947395735758975,
*              data :
*              {
*                  field : "value"
*              },
*              acl :
*              {
*                  other, 1
*              },
*              createdAt : 74889479874,
*              updatedAt : 73847474897487
*          },
*          {
*              gameId : "game",
*              entityId : "dgdgg",
*              ownerId : "ubfcbvfbsdvbb",
*              entityType : "",
*              entityIndexedId : "",
*              version : 1,
*              timeToLive: 0,
*              expiresAt : 9947395735758975,
*              data :
*              {
*                  field : "value2"
*              },
*              acl :
*              {
*                  other, 1
*              },
*              createdAt : 74889479874,
*              updatedAt : 73847474897487
*          }
*
*   }
* }
*/
- (void)getList:(NSString *)where
                 orderBy:(NSString *)orderBy
               maxReturn:(int64_t)maxReturn
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Method gets list of entities from the server base on indexed id
*
* Service Name - GlobalEntity
* Service Operation - GetListByIndexedId
*
* @param entityIndexedId The entity indexed Id
* @param maxReturn The maximum number of entities to return
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":
*   {
*      entities : [
*          {
*              gameId : "game",
*              entityId : "hucfshugvgvfhug",
*              ownerId : "ubfcbvfbsdvbb",
*              entityType : "",
*              entityIndexedId : "",
*              version : 1,
*              timeToLive: 0,
*              expiresAt : 9947395735758975,
*              data :
*              {
*                  field : "value"
*              },
*              acl :
*              {
*                  other, 1
*              },
*              createdAt : 74889479874,
*              updatedAt : 73847474897487
*          },
*          {
*              gameId : "game",
*              entityId : "dgdgg",
*              ownerId : "ubfcbvfbsdvbb",
*              entityType : "",
*              entityIndexedId : "",
*              version : 1,
*              timeToLive: 0,
*              expiresAt : 9947395735758975,
*              data :
*              {
*                  field : "value2"
*              },
*              acl :
*              {
*                  other, 1
*              },
*              createdAt : 74889479874,
*              updatedAt : 73847474897487
*          }
*
*   }
* }
*/
- (void)getListByIndexedId:(NSString *)entityIndexedId
                 maxReturn:(int64_t)maxReturn
           completionBlock:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)ecb
                  cbObject:(BCCallbackObject)cbObject;

/**
* Method gets a count of entities based on the where clause
*
* Service Name - GlobalEntity
* Service Operation - GetListCount
*
* @param where Mongo style query string
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":
*   {
*      "entityListCount" : 5
*   }
* }
*/
- (void)getListCount:(NSString *)where
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject;

/**
* Method uses a paging system to iterate through Global Entities
* After retrieving a page of Global Entities with this method,
* use GetPageOffset() to retrieve previous or next pages.
*
* Service Name - GlobalEntity
* Service Operation - GetPage
*
* @param context The json context for the page request.
*                   See the portal appendix documentation for format.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "results": {
*             "moreBefore": false,
*             "count": 200,
*             "items": [
*                 {
*                     "entityId": "00edfd8e-5028-45d5-95d4-b1869cf2afaa",
*                     "ownerId": "153a5ac3-582e-42d7-9e7d-aa80ca7e6689",
*                     "entityType": "testGlobalEntity",
*                     "entityIndexedId": null,
*                     "version": 1,
*                     "data": {
*                         "globalTestName": "Test Name 01"
*                     },
*                     "acl": {
*                         "other": 2
*                     },
*                     "expiresAt": 9223372036854776000,
*                     "timeToLive": 0,
*                     "createdAt": 1437505537168,
*                     "updatedAt": 1437505537168
*              }],
*              "page": 1,
*              "moreAfter": true
*         },
*         "context": "eyJzZWFyY2hDcml0ZXJpYSI6eyJlbnRpdHlUeXBlIjoiYnVpbGRpbmciLCJnYW
*              1lSWQiOiIxMDI4NyIsIiRvciI6W3sib3duZXJJZCI6Ijk5MjM4ZmFiLTkxYTItNDdiYy1
*              iMDExLWJjMThhN2IyOWY3NiJ9LHsiYWNsLm90aGVyIjp7IiRuZSI6MH19XX0sInNvcnRD
*              cml0ZXJpYSI6eyJjcmVhdGVkQXQiOjEsInVwZGF0ZWRBdCI6LTF9LCJwYWdpbmF0aW9uI
*              jp7InJvd3NQZXJQYWdlIjo1MCwicGFnZU51bWJlciI6NH0sIm9wdGlvbnMiOm51bGx9"
*     }
* }
*/
- (void)getPage:(NSString *)context
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Method to retrieve previous or next pages after having called the GetPage method.
*
* Service Name - GlobalEntity
* Service Operation - GetPageOffset
*
* @param context The context string returned from the server from a
*      previous call to GetPage or GetPageOffset
* @param pageOffset The positive or negative page offset to fetch. Uses the last page
*      retrieved using the context string to determine a starting point.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "results": {
*             "moreBefore": true,
*             "count": 200,
*             "items": [
*                 {
*                     "entityId": "00edfd8e-5028-45d5-95d4-b1869cf2afaa",
*                     "ownerId": "153a5ac3-582e-42d7-9e7d-aa80ca7e6689",
*                     "entityType": "testGlobalEntity",
*                     "entityIndexedId": null,
*                     "version": 1,
*                     "data": {
*                         "globalTestName": "Test Name 01"
*                     },
*                     "acl": {
*                         "other": 2
*                     },
*                     "expiresAt": 9223372036854776000,
*                     "timeToLive": 0,
*                     "createdAt": 1437505537168,
*                     "updatedAt": 1437505537168
*              }],
*              "page": 2,
*              "moreAfter": true
*         },
*         "context": "eyJzZWFyY2hDcml0ZXJpYSI6eyJlbnRpdHlUeXBlIjoiYnVpbGRpbmciLCJnYW
*              1lSWQiOiIxMDI4NyIsIiRvciI6W3sib3duZXJJZCI6Ijk5MjM4ZmFiLTkxYTItNDdiYy1
*              iMDExLWJjMThhN2IyOWY3NiJ9LHsiYWNsLm90aGVyIjp7IiRuZSI6MH19XX0sInNvcnRD
*              cml0ZXJpYSI6eyJjcmVhdGVkQXQiOjEsInVwZGF0ZWRBdCI6LTF9LCJwYWdpbmF0aW9uI
*              jp7InJvd3NQZXJQYWdlIjo1MCwicGFnZU51bWJlciI6NH0sIm9wdGlvbnMiOm51bGx9"
*     }
* }
*/
- (void)getPageOffset:(NSString *)context
           pageOffset:(int)pageOffset
      completionBlock:(BCCompletionBlock)completionBlock
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject;

@end