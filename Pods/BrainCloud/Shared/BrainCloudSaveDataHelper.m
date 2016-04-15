//
//  BrainCloudSaveDataHelper.m
//  BrainCloud
//
//  Created by Benoit Sarrazin on 2016-02-29.
//  Copyright © 2016 BitHeads Inc. All rights reserved.
//

#import "BrainCloudSaveDataHelper.h"

#import <SSKeychain/SSKeychain.h>

@interface BrainCloudSaveDataHelper ()

@property (copy, nonatomic) NSString *companyName;
@property (copy, nonatomic) NSString *gameName;
@property (copy, nonatomic) NSString *path;

@end

@implementation BrainCloudSaveDataHelper

- (instancetype)initWithCompanyName:(NSString *)companyName gameName:(NSString *)gameName {
    self = [self init];
    if (nil != self) {
        self.path = [NSString stringWithFormat:@"%@.%@", companyName, gameName];
    }
    return self;
}

- (void)saveString:(NSString *)string forKey:(NSString *)key {
    if (nil == self.path || 0 == self.path.length)
        return;
    
    if (nil == string) {
        [SSKeychain deletePasswordForService:self.path account:key];
    } else {
        [SSKeychain setPassword:string forService:self.path account:key];
    }
}

- (NSString *)stringForKey:(NSString *)key {
    if (nil == self.path || 0 == self.path.length)
        return nil;
    
    return [SSKeychain passwordForService:self.path account:key];
}

@end
