//
//  ProtocolCustomer.h
//  Lottery_JiangXi
//
//  Created by nnn on 15/4/3.
//  Copyright (c) 2015年 WZL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Command.h"
#import "StringUtills.h"

/**
  获取需要请求的完整URL
*/
@interface URLParser : NSObject

+(URLParser *)sharedInstance;

//根据Command指令，获取相应的UR  注:本url根据接口定义，多用于投注、获取期次、开奖等直接与彩票相关的接口
-(NSString *) getUrl:(Commands) command;

//根据Command指令，获取相应的UR  注:本url根据接口定义，多用于个人用户信息的接口

-(NSString *) getApiUrl:(Commands) command;

//获取遗漏数据用
-(NSString *)getChartmallUrl:(Commands) command;



@end
