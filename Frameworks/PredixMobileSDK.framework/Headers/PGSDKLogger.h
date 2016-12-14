//
// Created by Johns, Andy (GE Corporate) on 6/22/15.
// Copyright (c) 2015 GE. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PGSDKLogProvider.h"

typedef void (^PDSDKLogLineWriter) (NSString* _Nonnull format, va_list args) __deprecated;

typedef enum
{
    PGSDKLoggerLevelOff = 0,
    PGSDKLoggerLevelFatal = 1,
    PGSDKLoggerLevelError = 2,
    PGSDKLoggerLevelWarn = 3,
    PGSDKLoggerLevelInfo = 4,
    PGSDKLoggerLevelDebug = 5,
    PGSDKLoggerLevelTrace = 6
} PGSDKLoggerLevelEnum __deprecated_msg("use LoggingLevel instead.");

/** PGSDKLogger is deprecated: Use Logger instead. */
__deprecated_msg("use Logger instead.")
@interface PGSDKLogger : NSObject<PGSDKLogProvider>
+(void) setLogLineWriterBlock: (_Nullable PDSDKLogLineWriter) writerBlock;
+(void) setLoggerLevel: (PGSDKLoggerLevelEnum) value;
+(PGSDKLoggerLevelEnum) loggerLevel;
+(NSString* _Nonnull) loggerLevelName: (PGSDKLoggerLevelEnum) value;
@end

@interface PGSDKLogger(internal)
+ (void)trace:(NSString* _Nonnull)format args:(va_list)args __deprecated_msg("use Logger instead.");
+ (void)debug:(NSString* _Nonnull)format args:(va_list)args __deprecated_msg("use Logger instead.");
+ (void)info:(NSString* _Nonnull)format args:(va_list)args __deprecated_msg("use Logger instead.");
+ (void)warn:(NSString* _Nonnull)format args:(va_list)args __deprecated_msg("use Logger instead.");
+ (void)error:(NSString* _Nonnull)format args:(va_list)args __deprecated_msg("use Logger instead.");
+ (void)fatal:(NSString* _Nonnull)format args:(va_list)args __deprecated_msg("use Logger instead.");
@end


