// Copyright 2016 bitHeads, Inc. All Rights Reserved.

#include "BrainCloudEntity.h"

#include "BrainCloudClient.h"
#include "IServerCallback.h"
#include "ServerCall.h"
#include "ServiceName.h"
#include "ServiceOperation.h"
#include "OperationParam.h"
#include "json/json.h"

#include "StringUtil.h"
#include "JsonUtil.h"

namespace BrainCloud
{
    BrainCloudEntity::BrainCloudEntity(BrainCloudClient* in_client) : m_client(in_client) { }

    void BrainCloudEntity::createEntity(const char * in_entityType, const std::string& in_jsonEntityData, const std::string& in_jsonEntityAcl, IServerCallback * in_callback)
    {
        Json::Value message;
        message[OperationParam::EntityServiceEntityType.getValue()] = in_entityType;
        message[OperationParam::EntityServiceData.getValue()] = JsonUtil::jsonStringToValue(in_jsonEntityData);
        message[OperationParam::EntityServiceAcl.getValue()] = JsonUtil::jsonStringToValue(in_jsonEntityAcl);

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::Create, message, in_callback);
        m_client->sendRequest(sc);
    }

    void BrainCloudEntity::getEntity(const char * in_entityId, IServerCallback * in_callback)
    {
        Json::Value message;
        message[OperationParam::EntityServiceEntityId.getValue()] = in_entityId;

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::Read, message, in_callback);
        m_client->sendRequest(sc);
    }

    void BrainCloudEntity::getSingleton(const char * in_entityType, IServerCallback * in_callback)
    {
        Json::Value message;
        message[OperationParam::EntityServiceEntityType.getValue()] = in_entityType;

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::ReadSingleton, message, in_callback);
        m_client->sendRequest(sc);
    }

    void BrainCloudEntity::getEntitiesByType(const char * in_entityType, IServerCallback * in_callback)
    {
        Json::Value message;
        message[OperationParam::EntityServiceEntityType.getValue()] = in_entityType;

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::ReadByType, message, in_callback);
        m_client->sendRequest(sc);
    }

    void BrainCloudEntity::updateEntity(const char * in_entityId, const char * in_entityType, const std::string& in_jsonEntityData, const std::string& in_jsonEntityAcl, int64_t in_version, IServerCallback * in_callback)
    {
        Json::Value message;
        message[OperationParam::EntityServiceEntityId.getValue()] = in_entityId;
        message[OperationParam::EntityServiceEntityType.getValue()] = in_entityType;
        message[OperationParam::EntityServiceData.getValue()] = JsonUtil::jsonStringToValue(in_jsonEntityData);
        message[OperationParam::EntityServiceAcl.getValue()] = JsonUtil::jsonStringToValue(in_jsonEntityAcl);
        message[OperationParam::EntityServiceVersion.getValue()] = (Json::Int64) in_version;

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::Update, message, in_callback);
        m_client->sendRequest(sc);
    }

    void BrainCloudEntity::updateSingleton(const char * in_entityType, const std::string& in_jsonEntityData, const std::string& in_jsonEntityAcl, int64_t in_version, IServerCallback * in_callback)
    {
        Json::Value message;
        message[OperationParam::EntityServiceEntityType.getValue()] = in_entityType;
        message[OperationParam::EntityServiceData.getValue()] = JsonUtil::jsonStringToValue(in_jsonEntityData);
        message[OperationParam::EntityServiceAcl.getValue()] = JsonUtil::jsonStringToValue(in_jsonEntityAcl);
        message[OperationParam::EntityServiceVersion.getValue()] = (Json::Int64) in_version;

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::UpdateSingleton, message, in_callback);
        m_client->sendRequest(sc);
    }

    void BrainCloudEntity::deleteEntity(const char * in_entityId, int64_t in_version, IServerCallback * in_callback)
    {
        Json::Value message;
        message[OperationParam::EntityServiceEntityId.getValue()] = in_entityId;
        message[OperationParam::EntityServiceVersion.getValue()] = (Json::Int64) in_version;

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::Delete, message, in_callback);
        m_client->sendRequest(sc);
    }

    void BrainCloudEntity::deleteSingleton(const char * in_entityType, int64_t in_version, IServerCallback * in_callback)
    {
        Json::Value message;
        message[OperationParam::EntityServiceEntityType.getValue()] = in_entityType;
        message[OperationParam::EntityServiceVersion.getValue()] = (Json::Int64) in_version;

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::DeleteSingleton, message, in_callback);
        m_client->sendRequest(sc);
    }

    void BrainCloudEntity::getSharedEntityForPlayerId(const char * in_playerId, const char * in_entityId, IServerCallback * in_callback)
    {
        Json::Value message;
        message[OperationParam::EntityServiceTargetPlayerId.getValue()] = in_playerId;
        message[OperationParam::EntityServiceEntityId.getValue()] = in_entityId;

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::ReadSharedEntity, message, in_callback);
        m_client->sendRequest(sc);
    }

    void BrainCloudEntity::getSharedEntitiesForPlayerId(const char * in_playerId, IServerCallback * in_callback)
    {
        Json::Value message;
        message[OperationParam::EntityServiceTargetPlayerId.getValue()] = in_playerId;

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::ReadShared, message, in_callback);
        m_client->sendRequest(sc);
    }

    void BrainCloudEntity::updateSharedEntity(
        const char * in_entityId,
        const char * in_targetPlayerId,
        const char * in_entityType,
        const std::string& in_jsonEntityData,
        int64_t in_version,
        IServerCallback * in_callback)
    {
        Json::Value message;
        message[OperationParam::EntityServiceEntityId.getValue()] = in_entityId;
        message[OperationParam::EntityServiceTargetPlayerId.getValue()] = in_targetPlayerId;
        message[OperationParam::EntityServiceEntityType.getValue()] = in_entityType;
        message[OperationParam::EntityServiceVersion.getValue()] = (Json::Int64) in_version;
        message[OperationParam::EntityServiceData.getValue()] = JsonUtil::jsonStringToValue(in_jsonEntityData);

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::UpdateShared, message, in_callback);
        m_client->sendRequest(sc);
    }

    void BrainCloudEntity::getPage(const char * in_context, IServerCallback * in_callback)
    {
        Json::Value message;
        Json::Reader reader;

        Json::Value parsedContext;
        reader.parse(in_context, parsedContext);
        message[OperationParam::GlobalEntityServiceContext.getValue()] = parsedContext;

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::GetPage, message, in_callback);
        m_client->sendRequest(sc);
    }

    void BrainCloudEntity::getPageOffset(const char * in_context, int in_pageOffset, IServerCallback * in_callback)
    {
        Json::Value message;
        Json::Reader reader;

        message[OperationParam::GlobalEntityServiceContext.getValue()] = in_context;
        message[OperationParam::GlobalEntityServicePageOffset.getValue()] = in_pageOffset;

        ServerCall * sc = new ServerCall(ServiceName::Entity, ServiceOperation::GetPageOffset, message, in_callback);
        m_client->sendRequest(sc);
    }
}