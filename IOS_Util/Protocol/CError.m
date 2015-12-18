//
//  CError.m
//  IOS_Util
//
//  Created by 钟高勇 on 15/12/18.
//  Copyright © 2015年 钟高勇. All rights reserved.
//

#import "CError.h"

@implementation CError

-(instancetype) initWithErrorCode:(NSInteger)code{
    CError * error=[self init];
    error.errorCode=code;
    error.error=[CError getNetDataError:code];
    return [self init];
}

/**判断状态码是否为成功**/
+(BOOL) isSuccess:(NSInteger) errorCode{
    if(errorCode==ERROR_0){
        return YES;
    }else{
        return NO;
    }
}

+(BOOL) isSessionInvalid:(NSInteger) errorCode
{
    if(errorCode==ERROR_0){
        return YES;
    }else{
        return NO;
    }
}


/**根据CODE获取错误信息**/
+(NSString *) getNetDataError:(NSInteger) errorCode{
    
    NSString * message;
    switch (errorCode) {
        case ERROR:
            message = @"无法请求到服务器";
            break;
        case ERROR_1:
            message = @"流水号校验不通过";
            break;
        case ERROR_2:
            message = @"玩法英文名校验不通过";
            break;
        case ERROR_3:
            message = @"销售期号校验不通过";
            break;
        case ERROR_5:
            message = @"商家 ID 校验不通过";
            break;
           }
    
    return message;
    
}
@end
