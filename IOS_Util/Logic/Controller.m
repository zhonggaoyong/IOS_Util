//
//  Controller.m
//  Lottery_JiangXi
//
//  Created by 钟高勇 on 15/3/17.
//  Copyright (c) 2015年 WZL. All rights reserved.
//

#import "Controller.h"
#import "URLParser.h"
//业务处理类 所有的数据资源以及请求都须通过此类进行衔接与其他各层交互
@implementation Controller

static Controller * _instance;

+(Controller *)sharedInstance{
    if(_instance==nil){
        _instance=[[Controller alloc]init];
    }
    
    return _instance;
}

@end
