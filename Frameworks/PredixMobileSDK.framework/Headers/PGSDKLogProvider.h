//
// Created by Johns, Andy (GE Corporate) on 5/27/15.
// Copyright (c) 2015 GE. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PGSDKLogProvider <NSObject>
/*!
 @method
 @abstract Return true if the log level will output trace level messages.
 */
+ (BOOL)isTraceEnabled;

/*!
 @method
 @abstract log a trace message.
 */
+ (void)trace:(NSString *)format, ...;

/*!
 @method
 @abstract Return true if the log level will output debug level messages.
 */
+ (BOOL)isDebugEnabled;

/*!
 @method
 @abstract log a debug message.
 */
+ (void)debug:(NSString *)format, ...;

/*!
 @method
 @abstract Return true if the log level will output info level messages.
 */
+ (BOOL)isInfoEnabled;

/*!
 @method
 @abstract log a info message.
 */
+ (void)info:(NSString *)format, ...;

/*!
 @method
 @abstract Return true if the log level will output warning level messages.
 */
+ (BOOL)isWarnEnabled;

/*!
 @method
 @abstract log a warning message.
 */
+ (void)warn:(NSString *)format, ...;

/*!
 @method
 @abstract Return true if the log level will output error level messages.
 */
+ (BOOL)isErrorEnabled;

/*!
 @method
 @abstract log a error message.
 */
+ (void)error:(NSString *)format, ...;

/*!
 @method
 @abstract Return true if the log level will output fatal level messages.
 */
+ (BOOL)isFatalEnabled;

/*!
 @method
 @abstract log a fatal message.
 */
+ (void)fatal:(NSString *)format, ...;

/*!
 @method
 @abstract Return true if logging is disabled and nothing will be logged.
 */
+ (BOOL)isLoggingOff;

@end