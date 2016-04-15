//
//  BrainCloudEntity.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-06.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

#import "BrainCloudEntity.hh"

@implementation BrainCloudEntity

- (void)createEntity:(NSString *)entityType
      jsonEntityData:(NSString *)jsonEntityData
       jsonEntityAcl:(NSString *)jsonEntityAcl
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->createEntity(
        [entityType UTF8String], [jsonEntityData UTF8String], [jsonEntityAcl UTF8String],
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)updateEntity:(NSString *)entityId
          entityType:(NSString *)entityType
      jsonEntityData:(NSString *)jsonEntityData
       jsonEntityAcl:(NSString *)jsonEntityAcl
             version:(int64_t)version
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->updateEntity(
        [entityId UTF8String], [entityType UTF8String], [jsonEntityData UTF8String],
        [jsonEntityAcl UTF8String], version,
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)updateSingleton:(NSString *)entityType
         jsonEntityData:(NSString *)jsonEntityData
          jsonEntityAcl:(NSString *)jsonEntityAcl
                version:(int64_t)version
        completionBlock:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->updateSingleton(
        [entityType UTF8String], [jsonEntityData UTF8String], [jsonEntityAcl UTF8String], version,
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)deleteEntity:(NSString *)entityId
             version:(int64_t)version
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->deleteEntity(
        [entityId UTF8String], version, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)deleteSingleton:(NSString *)entityType
                version:(int64_t)version
        completionBlock:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->deleteEntity(
        [entityType UTF8String], version, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getEntity:(NSString *)entityId
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->getEntity(
        [entityId UTF8String], new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getSingleton:(NSString *)entityType
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->getSingleton(
        [entityType UTF8String], new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getEntitiesByType:(NSString *)entityType
          completionBlock:(BCCompletionBlock)completionBlock
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->getEntitiesByType(
        [entityType UTF8String], new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getSharedEntityForPlayerId:(NSString *)playerId
                          entityId:(NSString*)entityId
                   completionBlock:(BCCompletionBlock)completionBlock
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->getSharedEntityForPlayerId(
        [playerId UTF8String], [entityId UTF8String], new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getSharedEntitiesForPlayerId:(NSString *)playerId
                     completionBlock:(BCCompletionBlock)completionBlock
                errorCompletionBlock:(BCErrorCompletionBlock)ecb
                            cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->getSharedEntitiesForPlayerId(
        [playerId UTF8String], new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)updateSharedEntity:(NSString *)entityId
            targetPlayerId:(NSString *)targetPlayerId
                entityType:(NSString *)entityType
            jsonEntityData:(NSString *)jsonEntityData
                   version:(int64_t)version
           completionBlock:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)ecb
                  cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->updateSharedEntity(
        [entityId UTF8String], [targetPlayerId UTF8String], [entityType UTF8String],
        [jsonEntityData UTF8String], version,
        new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getPage:(NSString *)context
completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
       cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->getPage(
         [context UTF8String], new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getPageOffset:(NSString *)context
           pageOffset:(int)pageOffset
      completionBlock:(BCCompletionBlock)completionBlock
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEntityService()->getPageOffset(
         [context UTF8String], pageOffset, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

@end
