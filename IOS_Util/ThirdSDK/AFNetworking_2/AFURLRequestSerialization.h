// AFSerialization.h
//
// Copyright (c) 2013-2014 AFNetworking (http://afnetworking.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#if defined(__IPHONE_OS_VERSION_MIN_REQUIRED)
#import <UIKit/UIKit.h>
#endif

/**
 The `AFURLRequestSerialization` protocol is adopted by an object that encodes parameters for a specified HTTP requests. Request serializers may encode parameters as query strings, HTTP bodies, setting the appropriate HTTP header fields as necessary.

 For example, a JSON request serializer may set the HTTP body of the request to a JSON representation, and set the `Content-Type` HTTP header field value to `application/json`.
 */
@protocol AFURLRequestSerialization <NSObject, NSSecureCoding, NSCopying>

/**
 Returns a request with the specified parameters encoded into a copy of the original request.

 @param request The original request.
 @param parameters The parameters to be encoded.
 @param error The error that occurred while attempting to encode the request parameters.

 @return A serialized request.
 */
- (NSURLRequest *)requestBySerializingRequest:(NSURLRequest *)request
                               withParameters:(id)parameters
                                        error:(NSError * __autoreleasing *)error;

@end

#pragma mark -

/**

 */
typedef NS_ENUM(NSUInteger, AFHTTPRequestQueryStringSerializationStyle) {
    AFHTTPRequestQueryStringDefaultStyle = 0,
};

@protocol AFMultipartFormData;

/**
 `AFHTTPRequestSerializer` conforms to the `AFURLRequestSerialization` & `AFURLResponseSerialization` protocols, offering a concrete base implementation of query string / URL form-encoded parameter serialization and default request headers, as well as response status code and content type validation.

 Any request or response serializer dealing with HTTP is encouraged to subclass `AFHTTPRequestSerializer` in order to ensure consistent default behavior.
 */
@interface AFHTTPRequestSerializer : NSObject <AFURLRequestSerialization>

//编码格式
@property (nonatomic, assign) NSStringEncoding stringEncoding;

//是否建立请求可以使用设备的蜂窝无线电（如果存在的话）。默认情况下`YES`。
@property (nonatomic, assign) BOOL allowsCellularAccess;

//The cache policy of created requests. `NSURLRequestUseProtocolCachePolicy` by default.
@property (nonatomic, assign) NSURLRequestCachePolicy cachePolicy;

//无论是创建请求应使用默认的cookie处理。默认情况下`YES`。
@property (nonatomic, assign) BOOL HTTPShouldHandleCookies;

//无论是创建请求能够继续收到从较早传输的响应之前传输数据。默认情况下`NO`
@property (nonatomic, assign) BOOL HTTPShouldUsePipelining;

//网络服务类型创建请求。默认情况下`NSURLNetworkServiceTypeDefault`。
@property (nonatomic, assign) NSURLRequestNetworkServiceType networkServiceType;

//超时时间间隔，以秒为单位创建的请求。默认的超时时间间隔为60秒。
@property (nonatomic, assign) NSTimeInterval timeoutInterval;

//http header
@property (readonly, nonatomic, strong) NSDictionary *HTTPRequestHeaders;


+ (instancetype)serializer;

//添加header值
- (void)setValue:(NSString *)value
forHTTPHeaderField:(NSString *)field;

- (void)setAuthorizationHeaderFieldWithUsername:(NSString *)username
                                       password:(NSString *)password;

//写入token
- (void)setAuthorizationHeaderFieldWithToken:(NSString *)token DEPRECATED_ATTRIBUTE;

- (void)clearAuthorizationHeader;


@property (nonatomic, strong) NSSet *HTTPMethodsEncodingParametersInURI;

- (void)setQueryStringSerializationWithStyle:(AFHTTPRequestQueryStringSerializationStyle)style;

- (void)setQueryStringSerializationWithBlock:(NSString * (^)(NSURLRequest *request, NSDictionary *parameters, NSError * __autoreleasing *error))block;


- (NSMutableURLRequest *)requestWithMethod:(NSString *)method
                                 URLString:(NSString *)URLString
                                parameters:(id)parameters DEPRECATED_ATTRIBUTE;

- (NSMutableURLRequest *)requestWithMethod:(NSString *)method
                                 URLString:(NSString *)URLString
                                parameters:(id)parameters
                                     error:(NSError * __autoreleasing *)error;

- (NSMutableURLRequest *)multipartFormRequestWithMethod:(NSString *)method
                                              URLString:(NSString *)URLString
                                             parameters:(NSDictionary *)parameters
                              constructingBodyWithBlock:(void (^)(id <AFMultipartFormData> formData))block DEPRECATED_ATTRIBUTE;

- (NSMutableURLRequest *)multipartFormRequestWithMethod:(NSString *)method
                                              URLString:(NSString *)URLString
                                             parameters:(NSDictionary *)parameters
                              constructingBodyWithBlock:(void (^)(id <AFMultipartFormData> formData))block
                                                  error:(NSError * __autoreleasing *)error;

- (NSMutableURLRequest *)requestWithMultipartFormRequest:(NSURLRequest *)request
                             writingStreamContentsToFile:(NSURL *)fileURL
                                       completionHandler:(void (^)(NSError *error))handler;

@end

#pragma mark -

extern NSUInteger const kAFUploadStream3GSuggestedPacketSize;
extern NSTimeInterval const kAFUploadStream3GSuggestedDelay;

@protocol AFMultipartFormData

- (BOOL)appendPartWithFileURL:(NSURL *)fileURL
                         name:(NSString *)name
                        error:(NSError * __autoreleasing *)error;

- (BOOL)appendPartWithFileURL:(NSURL *)fileURL
                         name:(NSString *)name
                     fileName:(NSString *)fileName
                     mimeType:(NSString *)mimeType
                        error:(NSError * __autoreleasing *)error;

- (void)appendPartWithInputStream:(NSInputStream *)inputStream
                             name:(NSString *)name
                         fileName:(NSString *)fileName
                           length:(int64_t)length
                         mimeType:(NSString *)mimeType;

- (void)appendPartWithFileData:(NSData *)data
                          name:(NSString *)name
                      fileName:(NSString *)fileName
                      mimeType:(NSString *)mimeType;

- (void)appendPartWithFormData:(NSData *)data
                          name:(NSString *)name;


- (void)appendPartWithHeaders:(NSDictionary *)headers
                         body:(NSData *)body;


- (void)throttleBandwidthWithPacketSize:(NSUInteger)numberOfBytes
                                  delay:(NSTimeInterval)delay;

@end

#pragma mark -

@interface AFJSONRequestSerializer : AFHTTPRequestSerializer


@property (nonatomic, assign) NSJSONWritingOptions writingOptions;

+ (instancetype)serializerWithWritingOptions:(NSJSONWritingOptions)writingOptions;

@end

@interface AFPropertyListRequestSerializer : AFHTTPRequestSerializer

@property (nonatomic, assign) NSPropertyListFormat format;


@property (nonatomic, assign) NSPropertyListWriteOptions writeOptions;

+ (instancetype)serializerWithFormat:(NSPropertyListFormat)format
                        writeOptions:(NSPropertyListWriteOptions)writeOptions;

@end
