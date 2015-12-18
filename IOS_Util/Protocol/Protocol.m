//
//  Protocol.m
//  IOS_Util
//
//  Created by 钟高勇 on 15/12/18.
//  Copyright © 2015年 钟高勇. All rights reserved.
//

#import "Protocol.h"
#import "AFNetworking.h"


@implementation Protocol
{
    AFHTTPRequestOperationManager * httpManager;
    AFHTTPSessionManager * httpSessionManager;
}

+(Protocol *)getInstance{
    
    static Protocol * instance;
    static dispatch_once_t predicate;
    dispatch_once(&predicate, ^{
        instance=[[Protocol alloc]init];
    });
    return instance;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        httpManager=[AFHTTPRequestOperationManager manager];
        httpSessionManager=[AFHTTPSessionManager manager];
    }
    return self;
}



-(void)login:(NSString * )userName pwd:(NSString *)pwd successBlock:(SuccessBlock) successBlock errorBlock:(ErrorBlock)errorBlock{
    
    NSString * url=[[URLParser sharedInstance] getApiUrl:LOGIN];
    
    NSDictionary * params=@{@"username":userName,@"pwd":pwd};
    
    [self requestPost:url params:params success:^(AFHTTPRequestOperation *operation, id responseObject){
        
        NSDictionary * json=responseObject;
        //得到实体类
        id model=[[JSONParser sharedInstance] parseDic:LOGIN jsonDiction:json];
        //进行数据返回
        successBlock(model);
        
    } failure:^(AFHTTPRequestOperation *operation, CError *error) {
        
        errorBlock(error.error,error.errorCode);
    }];
    
}

/**
 GET 请求
 **/
-(void) requestGet:(NSString *)url params:(NSDictionary*) params success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
           failure:(void (^)(AFHTTPRequestOperation *operation, CError *error))failure{
    [self httpRequest:@"GET" url:url params:params ssuccess:success failure:failure];
}

/**
 GET 请求
 **/
-(void) requestPost:(NSString *)url params:(NSDictionary*) params success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
            failure:(void (^)(AFHTTPRequestOperation *operation, CError *error))failure{
    [self httpRequest:@"POST" url:url params:params ssuccess:success failure:failure];
}

-(void) httpRequest:(NSString *)method url:(NSString *)url params:(NSDictionary*) params ssuccess:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
            failure:(void (^)(AFHTTPRequestOperation *operation, CError *error))failure{
    
    NSMutableURLRequest *request = [httpManager.requestSerializer requestWithMethod:method URLString:[[NSURL URLWithString:url relativeToURL:httpManager.baseURL] absoluteString] parameters:params error:nil];
   
    NSLog(@"httpRequest=method=%@ url=%@?%@",method,url,params);
    
    AFHTTPRequestOperation *operation = [httpManager HTTPRequestOperationWithRequest:request success:^(AFHTTPRequestOperation *operation1, id responseObject1) {
        
        NSLog(@"httpResponse=%@=%@",operation1.request.URL,responseObject1);
        
    } failure:^(AFHTTPRequestOperation *operation1, NSError *error) {
        CError * cerror=[[CError alloc]initWithErrorCode:error.code];
         NSLog(@"httpResponse=%@=%@",operation1.request.URL,error);
        failure(operation1,cerror);
    }];
    
    [httpManager.operationQueue addOperation:operation];
    
}

@end
