//
//  JSONParser.h
//  Lottery_JiangXi
//
//  Created by 钟高勇 on 15/3/17.
//  Copyright (c) 2015年 WZL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Command.h"

/**
 *解析JSON
 */
@interface JSONParser : NSObject

/**
 单例模式
 
 **/
+(JSONParser *)sharedInstance;

/*
   解析集合类型数据
 */
-(id) parse:(Commands) command jsonArray:(NSArray *) jsonArray;

/*
  解析字典类型数据
 */
-(id) parseDic:(Commands) command jsonDiction:(NSDictionary *) jsonDiction;

@end
