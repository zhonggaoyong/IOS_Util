//
//  JSONParser.m
//  Lottery_JiangXi
//
//  Created by 钟高勇 on 15/3/17.
//  Copyright (c) 2015年 WZL. All rights reserved.
//

#import "JSONParser.h"
#import "Command.h"


/**
 *解析JSON
 */
@implementation JSONParser


+(JSONParser *)sharedInstance{
    static JSONParser* _instance;
    static dispatch_once_t predicate;
    dispatch_once(&predicate, ^{
        _instance = [[self alloc] init];
    });
    return _instance;
}




@end



