//
// Created by Johns, Andy (GE Corporate) on 6/22/15.
// Copyright (c) 2015 GE. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PGSDKLogProvider.h"

typedef void (^PDSDKLogLineWriter) (NSString* _Nonnull format, va_list args);

typedef enum
{
    PGSDKLoggerLevelOff = 0,
    PGSDKLoggerLevelFatal = 1,
    PGSDKLoggerLevelError = 2,
    PGSDKLoggerLevelWarn = 3,
    PGSDKLoggerLevelInfo = 4,
    PGSDKLoggerLevelDebug = 5,
    PGSDKLoggerLevelTrace = 6
} PGSDKLoggerLevelEnum;

@interface PGSDKLogger : NSObject<PGSDKLogProvider>
+(void) setLogLineWriterBlock: (_Nullable PDSDKLogLineWriter) writerBlock;
+(void) setLoggerLevel: (PGSDKLoggerLevelEnum) value;
+(PGSDKLoggerLevelEnum) loggerLevel;
+(NSString* _Nonnull) loggerLevelName: (PGSDKLoggerLevelEnum) value;
@end

@interface PGSDKLogger(internal)
+ (void)trace:(NSString* _Nonnull)format args:(va_list)args;
+ (void)debug:(NSString* _Nonnull)format args:(va_list)args;
+ (void)info:(NSString* _Nonnull)format args:(va_list)args;
+ (void)warn:(NSString* _Nonnull)format args:(va_list)args;
+ (void)error:(NSString* _Nonnull)format args:(va_list)args;
+ (void)fatal:(NSString* _Nonnull)format args:(va_list)args;
@end

@interface NSString(SHA512)
- (NSString * _Nonnull)getSHA512Hash;
@end