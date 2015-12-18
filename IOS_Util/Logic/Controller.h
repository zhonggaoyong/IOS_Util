//
//  Controller.h
//  Lottery_JiangXi
//
//  Created by 钟高勇 on 15/3/17.
//  Copyright (c) 2015年 WZL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Command.h"
#import "JSONParser.h"
#import "CallBack.h"
#import "CookieConfig.h"


@interface Controller : CallBack
//单例模式
+(Controller *)sharedInstance;

@end