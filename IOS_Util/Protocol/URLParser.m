//
//  URLParser.m
//  Lottery_JiangXi
//
//  Created by nnn on 15/4/3.
//  Copyright (c) 2015年 WZL. All rights reserved.
//

#import "URLParser.h"

@implementation URLParser


+(URLParser *)sharedInstance{
    
    static URLParser * _instance;
    static dispatch_once_t predicate;
    dispatch_once(&predicate, ^{
        _instance = [[self alloc] init];
    });
    return _instance;
}

//根据Command指令，获取相应的UR  注:本url根据接口定义，多用于投注、获取期次、开奖等直接与彩票相关的接口
-(NSString *) getUrl:(Commands) command{
    return nil;
}

//根据Command指令，获取相应的UR  注:本url根据接口定义，多用于个人用户信息的接口

-(NSString *) getApiUrl:(Commands) command{
    return nil;
}

//获取遗漏数据用
-(NSString *)getChartmallUrl:(Commands) command{
    return nil;
}


@end
