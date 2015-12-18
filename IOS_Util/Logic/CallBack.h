//
//  CallBack.h
//  Lottery_JiangXi
//
//  Created by 钟高勇 on 15/3/17.
//  Copyright (c) 2015年 WZL. All rights reserved.
//

#import <Foundation/Foundation.h>

//数据获取成功回调
typedef void (^SuccessBlock)(id data ,...);
//数据获取失败回调
typedef void (^ErrorBlock)(NSString* error,NSInteger errorCode,...);
//页面的回调类
@interface CallBack : NSObject

@end
