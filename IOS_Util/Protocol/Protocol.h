//
//  Protocol.h
//  IOS_Util
//
//  Created by 钟高勇 on 15/12/18.
//  Copyright © 2015年 钟高勇. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "URLParser.h"
#import "CallBack.h"
#import "JSONParser.h"
#import "CError.h"

@interface Protocol : NSObject

+(Protocol *)getInstance;

/*
 登录
 */

-(void)login:(NSString * )userName pwd:(NSString *)pwd successBlock:(SuccessBlock) successBlock errorBlock:(ErrorBlock)errorBlock;
@end
