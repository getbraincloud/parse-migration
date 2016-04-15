//
//  BrainCloudEvent.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-12.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import "BrainCloudEvent.hh"

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

@implementation BrainCloudEvent

- (void)sendEvent:(NSString *)toPlayerId
               eventType:(NSString *)eventType
           jsonEventData:(NSString *)eventData
           recordLocally:(bool)recordLocally
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEventService()->sendEvent(
        [toPlayerId UTF8String], [eventType UTF8String], [eventData UTF8String], recordLocally,
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)updateIncomingEventData:(NSString *)fromPlayerId
                        eventId:(uint64_t)eventId
                  jsonEventData:(NSString *)eventData
                completionBlock:(BCCompletionBlock)cb
           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                       cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEventService()->updateIncomingEventData(
        [fromPlayerId UTF8String], eventId, [eventData UTF8String],
        new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)deleteIncomingEvent:(NSString *)fromPlayerId
                    eventId:(uint64_t)eventId
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEventService()->deleteIncomingEvent(
        [fromPlayerId UTF8String], eventId, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)deleteSentEvent:(NSString *)toPlayerId
                eventId:(uint64_t)eventId
        completionBlock:(BCCompletionBlock)cb
   errorCompletionBlock:(BCErrorCompletionBlock)ecb
               cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEventService()->deleteSentEvent(
        [toPlayerId UTF8String], eventId, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)getEvents:(bool)includeIncomingEvents
    includeSentEvents:(bool)includeSentEvents
          completionBlock:(BCCompletionBlock)cb
     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getEventService()->getEvents(
        includeIncomingEvents, includeSentEvents, new BrainCloudCallback(cb, ecb, cbObject));
}

@end
