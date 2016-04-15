//
//  Platform.hh
//  brainCloudClientObjc
//
//  Created by Brad Hill on 2016-03-27.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma once

@interface FriendPlatformObjc : NSObject

+ (FriendPlatformObjc *) All;
+ (FriendPlatformObjc *) BrainCloud;
+ (FriendPlatformObjc *) Facebook;
+ (FriendPlatformObjc *) Unknown;

- (NSString *)toString;
+ (FriendPlatformObjc *)fromString:(NSString *)platform;

- (id)initWithValue:(NSString *)value;

@property (readonly) NSString *value;

@end
