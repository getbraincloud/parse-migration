//
//  ACL.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-07.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import "ACL.hh"

@implementation ACL

+ (NSString *)getAclJson:(Access)access
{
    return [NSString stringWithFormat:@"%@%lu", @"{ \"other\": ", (unsigned long)access];
}

@end
