// Copyright 2016 bitHeads, Inc. All Rights Reserved.
 
#include "BrainCloudEvent.h"

#include "BrainCloudClient.h"
#include "IServerCallback.h"
#include "ServerCall.h"
#include "ServiceName.h"
#include "ServiceOperation.h"
#include "OperationParam.h"
#include "json/json.h"

#include "JsonUtil.h"

namespace BrainCloud 
{
    BrainCloudEvent::BrainCloudEvent(BrainCloudClient* in_client) : m_client(in_client) { }

	void BrainCloudEvent::sendEvent( const char * in_toPlayerId, const char * in_eventType, const std::string& in_jsonEventData, bool in_recordLocally, IServerCallback * in_callback )
	{
		Json::Value message;
		message[OperationParam::EventServiceSendToId.getValue()] = in_toPlayerId;
		message[OperationParam::EventServiceSendEventType.getValue()] = in_eventType;
		message[OperationParam::EventServiceSendEventData.getValue()] = JsonUtil::jsonStringToValue(in_jsonEventData);
		message[OperationParam::EventServiceSendRecordLocally.getValue()] = in_recordLocally;
		
		ServerCall * sc = new ServerCall( ServiceName::Event, ServiceOperation::Send, message, in_callback );
		m_client->getBrainCloudComms()->addToQueue( sc );
	}

	void BrainCloudEvent::updateIncomingEventData( const char * in_fromPlayerId, uint64_t in_eventId, const std::string& in_jsonEventData, IServerCallback * in_callback )
	{
		Json::Value message;
		message[OperationParam::EventServiceUpdateEventDataFromId.getValue()] = in_fromPlayerId;
		message[OperationParam::EventServiceUpdateEventDataEventId.getValue()] = (Json::UInt64) in_eventId;
		message[OperationParam::EventServiceUpdateEventDataData.getValue()] = JsonUtil::jsonStringToValue(in_jsonEventData);
		
		ServerCall * sc = new ServerCall( ServiceName::Event, ServiceOperation::UpdateEventData, message, in_callback );
		m_client->getBrainCloudComms()->addToQueue( sc );
	}

	void BrainCloudEvent::deleteIncomingEvent( const char * in_fromPlayerId, uint64_t in_eventId, IServerCallback * in_callback )
	{
		Json::Value message;
		message[OperationParam::EventServiceDeleteIncomingFromId.getValue()] = in_fromPlayerId;
		message[OperationParam::EventServiceDeleteIncomingEventId.getValue()] = (Json::UInt64) in_eventId;
		
		ServerCall * sc = new ServerCall( ServiceName::Event, ServiceOperation::DeleteIncoming, message, in_callback );
		m_client->getBrainCloudComms()->addToQueue( sc );
	}

	void BrainCloudEvent::deleteSentEvent( const char * in_toPlayerId, uint64_t in_eventId, IServerCallback * in_callback)
	{
		Json::Value message;
		message[OperationParam::EventServiceDeleteSentToId.getValue()] = in_toPlayerId;
		message[OperationParam::EventServiceDeleteSentEventId.getValue()] = (Json::UInt64) in_eventId;
		
		ServerCall * sc = new ServerCall( ServiceName::Event, ServiceOperation::DeleteSent, message, in_callback );
		m_client->getBrainCloudComms()->addToQueue( sc );
	}
    
    void BrainCloudEvent::getEvents( bool in_includeIncomingEvents, bool in_includeSentEvents, IServerCallback * in_callback)
    {
        Json::Value message;
        message[OperationParam::EventServiceIncludeIncomingEvents.getValue()] = in_includeIncomingEvents;
        message[OperationParam::EventServiceIncludeSentEvents.getValue()] = in_includeSentEvents;
        
        ServerCall * sc = new ServerCall( ServiceName::Event, ServiceOperation::GetEvents, message, in_callback );
        m_client->getBrainCloudComms()->addToQueue( sc );
    }
}