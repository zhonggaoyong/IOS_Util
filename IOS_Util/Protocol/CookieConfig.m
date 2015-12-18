//
//  HttpCookieConfig.m
//  Lottery_JiangXi
//
//  Created by 钟高勇 on 15/3/19.
//  Copyright (c) 2015年 WZL. All rights reserved.
//

#import "CookieConfig.h"

@implementation CookieConfig


+(void) setCookie:(AFHTTPRequestOperation *)  cookieOperation;{
    if(cookieOperation){
        NSDictionary *fields= [cookieOperation.response allHeaderFields];
        [self setCookie2:fields];
    }
    
}

+(void) setCookie2:(NSDictionary*) cookieNSDictionary{
    if(cookieNSDictionary){
        NSString * cookieNSString=[[cookieNSDictionary objectForKey:@"Set-Cookie"] stringByReplacingOccurrencesOfString:@" Path=/," withString:@""];
        if(cookieNSString){
            NSUserDefaults *cookieUserDefaults = [NSUserDefaults standardUserDefaults];
            //获取所有的cookie保存到本地
            NSArray * cookieArray= [cookieNSString componentsSeparatedByString:@";"];
            if(cookieArray){
                for(NSString * text in cookieArray){
                    NSRange range = [text rangeOfString:@"="];
                    NSString * key=[text substringToIndex:range.location ];
                    NSString * value=text;
                    [cookieUserDefaults setValue:value forKey:key];
                    [cookieUserDefaults synchronize];
                }
            }
        }
    }
}

//获取cookie
+(void)getCookieURLRequest:(NSMutableURLRequest *) urlResuest{
    //保存COOKIE

    NSString * cookieStr=[[NSString alloc]init];
    NSUserDefaults *cookieUserDefaults = [NSUserDefaults standardUserDefaults];
    //获取所有数据
    NSDictionary * cookieDictionary=cookieUserDefaults.dictionaryRepresentation;
    //遍历数据，检索出所有的cookie值
    for(NSString * key in cookieDictionary){
        
        id value=[cookieDictionary objectForKey:key];
        if([value isKindOfClass:[NSString class]]){
            
            NSRange range = [value rangeOfString:@"="];
            if(range.length>0){
                cookieStr=[[cookieStr stringByAppendingString:value] stringByAppendingString:@";"];
            }
        }
    }
    if(urlResuest && cookieStr){
        [urlResuest setValue:cookieStr forHTTPHeaderField:@"Cookie"];
    }
}

+(void)getCookie:(AFHTTPRequestSerializer *) requestSerializer{
    //保存COOKIE
    if(requestSerializer){
        requestSerializer.HTTPShouldHandleCookies = YES;
    }
    NSString * cookieStr=[[NSString alloc]init];
    NSUserDefaults *cookieUserDefaults = [NSUserDefaults standardUserDefaults];
    //获取所有数据
    NSDictionary * cookieDictionary=cookieUserDefaults.dictionaryRepresentation;
    //遍历数据，检索出所有的cookie值
    for(NSString * key in cookieDictionary){
        
        id value=[cookieDictionary objectForKey:key];
        if([value isKindOfClass:[NSString class]]){
            
            NSRange range = [value rangeOfString:@"="];
            if(range.length>0){
                cookieStr=[[cookieStr stringByAppendingString:value] stringByAppendingString:@";"];
            }
        }
    }
    if(requestSerializer && cookieStr){
        //        requestSerializer = [AFJSONRequestSerializer serializer];
        [requestSerializer setValue:cookieStr forHTTPHeaderField:@"Cookie"];
    }
}

//清除所有cookie
+(void) clearCookie{
    NSUserDefaults *userDefatluts = [NSUserDefaults standardUserDefaults];
    NSDictionary *dictionary = [userDefatluts dictionaryRepresentation];
    for(NSString* key in [dictionary allKeys]){
        [userDefatluts removeObjectForKey:key];
        [userDefatluts synchronize];
    }

}
@end
