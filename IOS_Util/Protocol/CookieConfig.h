//
//  HttpCookieConfig.h
//  Lottery_JiangXi
//
//  Created by 钟高勇 on 15/3/19.
//  Copyright (c) 2015年 WZL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFHTTPRequestOperation.h"
#import "AFURLRequestSerialization.h"
@interface CookieConfig : NSObject


//存储cookie
+(void) setCookie:(AFHTTPRequestOperation *)  cookieOperation;
+(void) setCookie2:( NSDictionary*)  cookieNSDictionary;

//获取cookie

+(void)getCookie:(AFHTTPRequestSerializer *) requestSerializer;

//
+(void)getCookieURLRequest:(NSMutableURLRequest *) urlResuest;
//清除所有cookie
+(void) clearCookie;
@end
