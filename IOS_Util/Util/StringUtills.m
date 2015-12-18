//
//  StringUtills.m
//  Lottery_IOS_V1.0
//
//  Created by ztj on 13-1-22.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#import "StringUtills.h"

@implementation StringUtills

+ (BOOL)isBlankString:(NSString *)string{
    
    if (string == nil) {
        return YES;
    }
    if (string == NULL) {
        return YES;
    }
    if ([string isKindOfClass:[NSNull class]]) {
        return YES;
    }
   
    //去除回车的方法
    if ([[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length]==0) {
        return YES;
    }
    
    return NO;
    
}



@end
