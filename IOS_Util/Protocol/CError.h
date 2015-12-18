//
//  CError.h
//  IOS_Util
//
//  Created by 钟高勇 on 15/12/18.
//  Copyright © 2015年 钟高勇. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CError : NSObject

#define  CODE_100000  100000

#define ERROR  9999

#define ERROR_0  100000 // 成功

#define ERROR_1  100002 // 流水号校验不通过

#define ERROR_2  100003 // 玩法英文名校验不通过

#define ERROR_3  100004 // 销售期号校验不通过

#define ERROR_5  100005 // 商家 ID 校验不通过

@property(nonatomic,assign) NSInteger errorCode;

@property(nonatomic,strong) NSString * error;


-(instancetype) initWithErrorCode:(NSInteger)code;



/**根据CODE获取错误信息**/
+(NSString *) getNetDataError:(NSInteger) errorCode;

/**判断状态码是否为成功**/
+(BOOL) isSuccess:(NSInteger) errorCode;

/**判断session是否失效**/
+(BOOL) isSessionInvalid:(NSInteger) errorCode;

@end
