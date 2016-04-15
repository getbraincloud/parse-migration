//
//  BrainCloudEntity.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-06.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudEntity : NSObject

/**
* Method creates a new entity on the server.
*
* Service Name - Entity
* Service Operation - Create
*
* @param entityType The entity type as defined by the user
* @param jsonEntityData The entity's data as a json string
* @param jsonEntityAcl The entity's access control list as json. A null acl implies default
* permissions which make the entity readable/writeable by only the player.
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
- (void)createEntity:(NSString *)entityType
      jsonEntityData:(NSString *)jsonEntityData
       jsonEntityAcl:(NSString *)jsonEntityAcl
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject;

/**
* Method updates a new entity on the server. This operation results in the entity
* data being completely replaced by the passed in JSON string.
*
* Service Name - Entity
* Service Operation - Update
*
* @param entityId The id of the entity to update
* @param entityType The entity type as defined by the user
* @param jsonEntityData The entity's data as a json string.
* @param jsonEntityAcl The entity's access control list as json. A null acl implies default
* permissions which make the entity readable/writeable by only the player.
* @param version Current version of the entity. If the version of the
* entity on the server does not match the version passed in, the
* server operation will fail. Use -1 to skip version checking.
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
- (void)updateEntity:(NSString *)entityId
          entityType:(NSString *)entityType
      jsonEntityData:(NSString *)jsonEntityData
       jsonEntityAcl:(NSString *)jsonEntityAcl
             version:(int64_t)version
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject;

/**
* Method updates a new singleton entity on the server. This operation results in the entity
* data being completely replaced by the passed in JSON string. If the entity doesn't exists it is created
*
* Service Name - Entity
* Service Operation - UpdateSingleton
*
* @param entityType The entity type as defined by the user
* @param jsonEntityData The entity's data as a json string.
* permissions which make the entity readable/writeable by only the player.
* @param jsonEntityAcl The entity's access control list as json. A null acl implies default
* permissions which make the entity readable/writeable by only the player.
* @param version Current version of the entity. If the version of the
* entity on the server does not match the version passed in, the
* server operation will fail. Use -1 to skip version checking.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*    "data" :   {
*         "entityId": "113db68a-48ad-4fc9-9f44-5fd36fc6445f",
*         "entityType": "settings",
*         "version": 1,
*         "data": {
*           "name": "john",
*           "age": 30
*         },
*         "createdAt": 1395943044322,
*         "updatedAt": 1395943044322
*       },
* }
*/
- (void)updateSingleton:(NSString *)entityType
         jsonEntityData:(NSString *)jsonEntityData
          jsonEntityAcl:(NSString *)jsonEntityAcl
                version:(int64_t)version
        completionBlock:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject;

/**
* Method deletes the given entity on the server.
*
* Service Name - Entity
* Service Operation - Delete
*
* @param entityId The id of the entity to update
* @param version Current version of the entity. If the version of the
* entity on the server does not match the version passed in, the
* server operation will fail. Use -1 to skip version checking.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows. Note that status 200 is returned
* whether or not the given entity was found on the server.
* {
*   "status":200,
*   "data":null
* }
*/
- (void)deleteEntity:(NSString *)entityId
             version:(int64_t)version
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject;

/**
* Method deletes the given singleton entity on the server.
*
* Service Name - Entity
* Service Operation - DeleteSingleton
*
* @param entityType The type of the entity to delete
* @param version Current version of the entity. If the version of the
* entity on the server does not match the version passed in, the
* server operation will fail. Use -1 to skip version checking.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows. Note that status 200 is returned
* whether or not the given entity was found on the server.
* {
*   "status":200,
*   "data":null
* }
*/
- (void)deleteSingleton:(NSString *)entityType
                version:(int64_t)version
        completionBlock:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject;

/** Method to get a specific entity.
*
* Service Name - Entity
* Service Operation - Read
*
* @param entityId The entity id
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*/
- (void)getEntity:(NSString *)entityId
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
 * Method retreives a singleton entity on the server. If the entity doesn't exist, null is returned.
 *
 * Service Name - Entity
 * Service Operation - GetSingleton
 *
 * @param entityType The entity type as defined by the user
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @return The JSON returned in the completion block is as follows:
 * {
 *   "status":200,
 *    "data" :   {
 *         "entityId": "113db68a-48ad-4fc9-9f44-5fd36fc6445f",
 *         "entityType": "settings",
 *         "version": 1,
 *         "data": {
 *           "name": "john",
 *           "age": 30
 *         },
 *         "createdAt": 1395943044322,
 *         "updatedAt": 1395943044322
 *       },
 * }
 */
- (void)getSingleton:(NSString *)entityType
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject;

/** Method returns all player entities that match the given type.
* Service Name - Entity
* Service Operation - ReadByType
*
* @param entityType The entity type to search for
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return JSON including the entities matching the given type
* {
*   "status": 200,
*   "data": {
*     "entities": [
*       {
*         "entityId": "113db68a-48ad-4fc9-9f44-5fd36fc6445f",
*         "entityType": "person",
*         "version": 1,
*         "data": {
*           "name": "john",
*           "age": 30
*         },
*         "acl": {
*           "other": 0
*         },
*         "createdAt": 1395943044322,
*         "updatedAt": 1395943044322
*       },
*       {
*         "entityId": "255db68a-48ad-4fc9-9f44-5fd36fc6445f",
*         "entityType": "person",
*         "version": 1,
*         "data": {
*           "name": "mary",
*           "age": 25
*         },
*         "acl": {
*           "other": 0
*         },
*         "createdAt": 1395943044322,
*         "updatedAt": 1395943044322
*       }
*     ]
*   }
*/
- (void)getEntitiesByType:(NSString *)entityType
          completionBlock:(BCCompletionBlock)completionBlock
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject;

/**
 * Method returns a shared entity for the given player and entity ID.
 * An entity is shared if its ACL allows for the currently logged
 * in player to read the data.
 *
 * Service Name - Entity
 * Service Operation - READ_SHARED_ENTITY
 *
 * @param playerId The the profile ID of the player who owns the entity
 * @param entityId The ID of the entity that will be retrieved
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @return The JSON returned in the callback is as follows:
 * {
 *     "status": 200,
 *     "data": {
 *         "entityId": "544db68a-48ad-4fc9-9f44-5fd36fc6445f",
 *         "entityType": "publicInfo",
 *         "version": 1,
 *         "data": {
 *             "name": "john",
 *             "age": 30
 *         },
 *         "acl": {
 *             "other": 1
 *         },
 *         "createdAt": 1395943044322,
 *         "updatedAt": 1395943044322
 *     }
 * }
 */
- (void)getSharedEntityForPlayerId:(NSString *)playerId
                          entityId:(NSString*)entityId
                   completionBlock:(BCCompletionBlock)completionBlock
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject;

/**
* Method returns all shared entities for the given player id.
* An entity is shared if its ACL allows for the currently logged
* in player to read the data.
*
* Service Name - Entity
* Service Operation - ReadShared
*
* @param playerId The player id to retrieve shared entities for
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return JSON including the shared entities for the given player id
* {
*   "status": 200,
*   "data": {
*     "entities": [
*       {
*         "entityId": "544db68a-48ad-4fc9-9f44-5fd36fc6445f",
*         "entityType": "publicInfo",
*         "version": 1,
*         "data": {
*           "name": "john",
*           "age": 30
*         },
*         "acl": {
*           "other": 1
*         },
*         "createdAt": 1395943044322,
*         "updatedAt": 1395943044322
*       }
*     ]
*   }
* }
*/
- (void)getSharedEntitiesForPlayerId:(NSString *)playerId
                     completionBlock:(BCCompletionBlock)completionBlock
                errorCompletionBlock:(BCErrorCompletionBlock)ecb
                            cbObject:(BCCallbackObject)cbObject;

/**
* Method updates a shared entity owned by another player. This operation results in the entity
* data being completely replaced by the passed in JSON string.
*
* Service Name - Entity
* Service Operation - UpdateShared
*
* @param entityId The id of the entity to update
* @param targetPlayerId The id of the player who owns the shared entity
* @param entityType The entity type as defined by the user
* @param jsonEntityData The entity's data as a json string.
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
- (void)updateSharedEntity:(NSString *)entityId
            targetPlayerId:(NSString *)targetPlayerId
                entityType:(NSString *)entityType
            jsonEntityData:(NSString *)jsonEntityData
                   version:(int64_t)version
           completionBlock:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)ecb
                  cbObject:(BCCallbackObject)cbObject;

/**
 * Method uses a paging system to iterate through entities
 * After retrieving a page of entities with this method,
 * use GetPageOffset() to retrieve previous or next pages.
 *
 * Service Name - Entity
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
 *                     "entityType": "testEntity",
 *                     "version": 1,
 *                     "data": {
 *                         "testName": "Test Name 01"
 *                     },
 *                     "acl": {
 *                         "other": 2
 *                     },
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
 * Service Name - Entity
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
 *                     "entityType": "testGlobalEntity",
 *                     "version": 1,
 *                     "data": {
 *                         "testName": "Test Name 01"
 *                     },
 *                     "acl": {
 *                         "other": 2
 *                     },
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