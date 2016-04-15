//
//  BrainCloudGlobalEntity.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-06.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#include <stdlib.h>
#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

#import "BrainCloudGlobalEntity.hh"

@implementation BrainCloudGlobalEntity

- (void)createEntity:(NSString *)entityType
          timeToLive:(int64_t)timeToLive
       jsonEntityAcl:(NSString *)jsonEntityAcl
      jsonEntityData:(NSString *)jsonEntityData
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject
{
    std::string type, acl, data;

    if (entityType != nil) type = [entityType UTF8String];
    if (jsonEntityAcl != nil) acl = [jsonEntityAcl UTF8String];
    if (jsonEntityData != nil) data = [jsonEntityData UTF8String];

    BrainCloud::BrainCloudClient::getInstance()->getGlobalEntityService()->createEntity(
        type, timeToLive, acl, data, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)createEntityWithIndexedId:(NSString *)entityType
                        indexedId:(NSString *)indexedId
                       timeToLive:(int64_t)timeToLive
                    jsonEntityAcl:(NSString *)jsonEntityAcl
                   jsonEntityData:(NSString *)jsonEntityData
                  completionBlock:(BCCompletionBlock)completionBlock
             errorCompletionBlock:(BCErrorCompletionBlock)ecb
                         cbObject:(BCCallbackObject)cbObject
{
    std::string type, index, acl, data;

    if (entityType != nil) type = [entityType UTF8String];
    if (indexedId != nil) index = [indexedId UTF8String];
    if (jsonEntityAcl != nil) acl = [jsonEntityAcl UTF8String];
    if (jsonEntityData != nil) data = [jsonEntityData UTF8String];

    BrainCloud::BrainCloudClient::getInstance()
        ->getGlobalEntityService()
        ->createEntityWithIndexedId(type, index, timeToLive, acl, data,
                                    new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)updateEntity:(NSString *)entityId
             version:(int64_t)version
      jsonEntityData:(NSString *)jsonEntityData
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject
{
    std::string eId, data;

    if (entityId != nil) eId = [entityId UTF8String];
    if (jsonEntityData != nil) data = [jsonEntityData UTF8String];

    BrainCloud::BrainCloudClient::getInstance()->getGlobalEntityService()->updateEntity(
        eId, version, data, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)updateEntityAcl:(NSString *)entityId
                version:(int64_t)version
          jsonEntityAcl:(NSString *)jsonEntityAcl
        completionBlock:(BCCompletionBlock)completionBlock
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject
{
    std::string eId, acl;

    if (entityId != nil) eId = [entityId UTF8String];
    if (jsonEntityAcl != nil) acl = [jsonEntityAcl UTF8String];

    BrainCloud::BrainCloudClient::getInstance()->getGlobalEntityService()->updateEntityAcl(
        eId, version, acl, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)updateEntityTimeToLive:(NSString *)entityId
                       version:(int64_t)version
                    timeToLive:(int64_t)timeToLive
               completionBlock:(BCCompletionBlock)completionBlock
          errorCompletionBlock:(BCErrorCompletionBlock)ecb
                      cbObject:(BCCallbackObject)cbObject
{
    std::string eId;
    if (entityId != nil) eId = [entityId UTF8String];

    BrainCloud::BrainCloudClient::getInstance()->getGlobalEntityService()->updateEntityTimeToLive(
        eId, version, timeToLive, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)deleteEntity:(NSString *)entityId
             version:(int64_t)version
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject
{
    std::string eId;
    if (entityId != nil) eId = [entityId UTF8String];

    BrainCloud::BrainCloudClient::getInstance()->getGlobalEntityService()->deleteEntity(
        eId, version, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)readEntity:(NSString *)entityId
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    std::string eId;
    if (entityId != nil) eId = [entityId UTF8String];

    BrainCloud::BrainCloudClient::getInstance()->getGlobalEntityService()->readEntity(
        eId, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getList:(NSString *)where
                 orderBy:(NSString *)orderBy
               maxReturn:(int64_t)maxReturn
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    std::string wh, order;

    if (where != nil) wh = [where UTF8String];
    if (orderBy != nil) order = [orderBy UTF8String];

    BrainCloud::BrainCloudClient::getInstance()->getGlobalEntityService()->getList(
        wh, order, maxReturn, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getListByIndexedId:(NSString *)entityIndexedId
                 maxReturn:(int64_t)maxReturn
           completionBlock:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)ecb
                  cbObject:(BCCallbackObject)cbObject
{
    std::string index;
    if (entityIndexedId != nil) index = [entityIndexedId UTF8String];

    BrainCloud::BrainCloudClient::getInstance()->getGlobalEntityService()->getListByIndexedId(
        index, maxReturn, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getListCount:(NSString *)where
     completionBlock:(BCCompletionBlock)completionBlock
errorCompletionBlock:(BCErrorCompletionBlock)ecb
            cbObject:(BCCallbackObject)cbObject
{
    std::string wh;
    if (where != nil) wh = [where UTF8String];

    BrainCloud::BrainCloudClient::getInstance()->getGlobalEntityService()->getListCount(
        wh, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getPage:(NSString *)context
         completionBlock:(BCCompletionBlock)completionBlock
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGlobalEntityService()->getPage(
        [context UTF8String], new BrainCloudCallback(completionBlock, ecb, cbObject));
}

- (void)getPageOffset:(NSString *)context
           pageOffset:(int)pageOffset
      completionBlock:(BCCompletionBlock)completionBlock
 errorCompletionBlock:(BCErrorCompletionBlock)ecb
             cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getGlobalEntityService()->getPageOffset(
        [context UTF8String], pageOffset, new BrainCloudCallback(completionBlock, ecb, cbObject));
}

@end
