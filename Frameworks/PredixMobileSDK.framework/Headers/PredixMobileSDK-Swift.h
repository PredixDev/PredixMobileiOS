// Generated by Apple Swift version 4.1.2 (swiftlang-902.0.54 clang-902.0.39.2)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR __attribute__((enum_extensibility(open)))
# else
#  define SWIFT_ENUM_ATTR
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_ATTR SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if __has_feature(modules)
@import ObjectiveC;
@import Foundation;
#endif

#import <PredixMobileSDK/PredixMobileSDK.h>

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="PredixMobileSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

/// Enumeration for specifying location of configuration elements.
typedef SWIFT_ENUM(NSInteger, ConfigurationLocation) {
/// Configuration is stored in the Settings bundle
  ConfigurationLocationSettings = 0,
/// Configuration is stored in the Info.plist
  ConfigurationLocationInfoplist = 1,
};


/// Used to create full text search database views.
/// <ul>
///   <li>
///     example:
///     \code
///       PredixMobilityConfiguration.appendDataViewDefinition("views/searchtext", version: "1") { (properties: [String : Any], emit: (Any, Any?) -> Void) -> Void in
///
///           if let body = properties["body"] as? String
///           {
///               emit(FullTextSearch.createKey(body), nil)
///           }
///       }
///
///     \endcode</li>
/// </ul>
SWIFT_CLASS("_TtC15PredixMobileSDK14FullTextSearch")
@interface FullTextSearch : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end

enum LoggerLevel : NSInteger;

/// Protocol used by Logger class for logging operations.
SWIFT_PROTOCOL("_TtP15PredixMobileSDK14LoggerProtocol_")
@protocol LoggerProtocol
/// Sets and gets the current logger verbosity level.
@property (nonatomic) enum LoggerLevel loggerLevel;
/// Return true if the log level will output trace level messages.
- (BOOL)isTraceEnabled SWIFT_WARN_UNUSED_RESULT;
/// log a trace message.
- (void)trace:(NSString * _Nonnull)log;
/// Return true if the log level will output debug level messages.
- (BOOL)isDebugEnabled SWIFT_WARN_UNUSED_RESULT;
/// log a debug message.
- (void)debug:(NSString * _Nonnull)log;
/// Return true if the log level will output info level messages.
- (BOOL)isInfoEnabled SWIFT_WARN_UNUSED_RESULT;
/// log a info message.
- (void)info:(NSString * _Nonnull)log;
/// Return true if the log level will output warning level messages.
- (BOOL)isWarnEnabled SWIFT_WARN_UNUSED_RESULT;
/// log a warning message.
- (void)warn:(NSString * _Nonnull)log;
/// Return true if the log level will output error level messages.
- (BOOL)isErrorEnabled SWIFT_WARN_UNUSED_RESULT;
/// log a error message.
- (void)error:(NSString * _Nonnull)log;
/// Return true if the log level will output fatal level messages.
- (BOOL)isFatalEnabled SWIFT_WARN_UNUSED_RESULT;
/// log a fatal message.
- (void)fatal:(NSString * _Nonnull)log;
/// Return true if logging is disabled and nothing will be logged.
- (BOOL)isLoggingOff SWIFT_WARN_UNUSED_RESULT;
@end


/// Provides Logging support for the SDK.
/// seealso:
///
/// <ul>
///   <li>
///     <a href="https://developer.apple.com/reference/os/1891852-logging">Logging - os | Apple Developer Documentation</a>
///   </li>
///   <li>
///     <a href="https://developer.apple.com/videos/play/wwdc2016/721/">WWDC 2016: Unified Logging and Activity Tracing</a>
///   </li>
/// </ul>
/// <ul>
///   <li>
///     On iOS 9 and below and macOS El Capitan and below this class will use the Apple NSLog-style logs.
///   </li>
///   <li>
///     When running in iOS 10+ and macOS Sierra+ this class will use the Apple Unified Logging API
///   </li>
/// </ul>
SWIFT_CLASS("_TtC15PredixMobileSDK6Logger")
@interface Logger : NSObject <LoggerProtocol>
/// Initialization
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
/// Sets and gets the current logger verbosity level. Logs more verbose than this level will not be output to the logging system.
/// For example:
/// If the loggerLevel is set to <code>LoggerLevel.info</code>, then:
/// <code>Logger.shared.loggerlevel = LoggerLevel.info</code>
/// <code>Logger.warn("this will be output")</code>
/// <code>Logger.info("this will be output")</code>
/// <code>Logger.debug("this will not be output")</code>
/// <code>Logger.trace("this will not be output")</code>
@property (nonatomic) enum LoggerLevel loggerLevel;
/// Return true if the log level will output trace level messages.
- (BOOL)isTraceEnabled SWIFT_WARN_UNUSED_RESULT;
/// log a trace message.
- (void)trace:(NSString * _Nonnull)log;
/// Return true if the log level will output debug level messages.
- (BOOL)isDebugEnabled SWIFT_WARN_UNUSED_RESULT;
/// log a debug message.
- (void)debug:(NSString * _Nonnull)log;
/// Return true if the log level will output info level messages.
- (BOOL)isInfoEnabled SWIFT_WARN_UNUSED_RESULT;
/// log a info message.
- (void)info:(NSString * _Nonnull)log;
/// Return true if the log level will output warning level messages.
- (BOOL)isWarnEnabled SWIFT_WARN_UNUSED_RESULT;
/// log a warning message.
- (void)warn:(NSString * _Nonnull)log;
/// Return true if the log level will output error level messages.
- (BOOL)isErrorEnabled SWIFT_WARN_UNUSED_RESULT;
/// log a error message.
- (void)error:(NSString * _Nonnull)log;
/// Return true if the log level will output fatal level messages.
- (BOOL)isFatalEnabled SWIFT_WARN_UNUSED_RESULT;
/// log a fatal message.
- (void)fatal:(NSString * _Nonnull)log;
/// Return true if logging is disabled and nothing will be logged.
- (BOOL)isLoggingOff SWIFT_WARN_UNUSED_RESULT;
@end

/// Logging verbosity levels
typedef SWIFT_ENUM(NSInteger, LoggerLevel) {
/// No logging will be output
  LoggerLevelOff = 0,
/// Output Fatal level log messages only
  LoggerLevelFatal = 1,
/// Error level
  LoggerLevelError = 2,
/// Warn level
  LoggerLevelWarn = 3,
/// Info level
  LoggerLevelInfo = 4,
/// Debug level
  LoggerLevelDebug = 5,
/// Trace level - most verbose. All messages are output.
  LoggerLevelTrace = 6,
};



/// Allows an application developer to provide mock data responses for URLSession and other types of network request classes (UIWebView for example).
/// The MockNetworkDataManager works with mock data providers to determine if a requested URL should return real network data or mock network data.
/// By default the MockNetworkDataManager uses a default data provider that works with a resource bundle and plist to determine if a requested URL should return mock data.
/// Here is an example of how the default provider works:
/// In a project define a MockData.bundle resource bundle, inside that bundle it should contain all of the contents you need to mock a network response for a request.  The bundle should also include a
/// DataMapping.plist file.
/// <em>Example:</em>
/// <?xml version="1.0" encoding="UTF-8"?>
/// <!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
/// <plist version="1.0">
/// <dict>
///     <key>https://apple.com</key>
///     <dict>
///         <key>dataFilename</key>
///         <string>mockData.json</string>
///         <key>requests</key>
///         <array>
///             <dict>
///                 <key>httpMethod</key>
///                 <string>GET</string>
///                 <key>headerFields</key>
///                 <dict>
///                     <key>a</key>
///                     <string>b</string>
///                 </dict>
///                 <key>response</key>
///                 <dict>
///                     <key>headerFields</key>
///                     <dict>
///                         <key>a</key>
///                         <string>b</string>
///                     </dict>
///                     <key>httpVersion</key>
///                     <string>1.1</string>
///                     <key>statusCode</key>
///                     <integer>200</integer>
///                 </dict>
///             </dict>
///             <dict>
///                 <key>httpMethod</key>
///                 <string>POST</string>
///             </dict>
///         </array>
///     </dict>
/// </plist>
/// Alternatively you can define a simple response structure, this will return the response for ANY requests sent for the given endpoint
/// <?xml version="1.0" encoding="UTF-8"?>
/// <!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
/// <plist version="1.0">
/// <dict>
///     <key>https://simple.com</key>
///     <dict>
///         <key>dataFilename</key>
///         <string>mockData.json</string>
///         <key>response</key>
///         <dict>
///             <key>headerFields</key>
///             <dict>
///                 <key>a</key>
///                 <string>b</string>
///             </dict>
///             <key>httpVersion</key>
///             <string>1.1</string>
///             <key>statusCode</key>
///             <integer>200</integer>
///         </dict>
///     </dict>
/// </dict>
/// </plist>
/// The data is loaded from disk as raw Data using the contents of file as the data response.  This means the default provider should be able to work with most
/// file types (JSON, text, images, video, etc.)
SWIFT_CLASS("_TtC15PredixMobileSDK22MockNetworkDataManager")
@interface MockNetworkDataManager : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSHTTPURLResponse;
@class NSURLResponse;

/// Protocol all services must implement to be considered a “service”
/// important:
/// You will notice all these methods are staticly defined. Services are expected to be completely static classes. This is done to emphasize and promote the stateless nature of service calls. Services should be stateless, reentrant, and thread-safe.
/// <em>There are no guarentees for how, when, on what thread, or how often any service is called.</em>
SWIFT_PROTOCOL("_TtP15PredixMobileSDK15ServiceProtocol_")
@protocol ServiceProtocol
/// Unique identifier for this service.
/// The serviceIdentifier string will make up the first part of the path for requests made to services.
/// Example:
/// If a serviceIdentifier is “foo” then a request to the service will look like:
/// <code>http://pmapi/foo</code>
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull serviceIdentifier;)
+ (NSString * _Nonnull)serviceIdentifier SWIFT_WARN_UNUSED_RESULT;
/// The method called when the ServiceRouter detects a request was made for this service (as identified by the serviceIdentifier)
/// \param request the URLRequest that was made to call this service.
///
/// \param response a template response, preset to have a 200 status code.
/// This response object can be used as-is or be used to create a new response.
///
/// \param responseReturn First of three return closures. Used to return the response object back to the calling code.
/// <em>This closure must be called and must be called only once.</em>
///
/// \param dataReturn Second of the three return closures. Used to return data back to the calling code.
/// This closure is may be skipped if no data is to be returned.
/// If called, this closure must be called after the responseReturn closure, and before the requestComplete closure.
///
/// \param requestComplete Third and final of the three return closures. This indicates the service request has completed.
/// <em>This closure must be called, or the service request will not be complete</em>
/// <em>No additional code should be executed after this closure is called</em>
///
+ (void)performRequest:(NSURLRequest * _Nonnull)request response:(NSHTTPURLResponse * _Nonnull)response responseReturn:(responseReturnBlock _Nonnull)responseReturn dataReturn:(dataReturnBlock _Nonnull)dataReturn requestComplete:(requestCompleteBlock _Nonnull)requestComplete;
@optional
/// Optional: if this method is implimented, the this method will be called when the service is registered with the service router.
+ (void)registered;
/// Optional: if this method is implimented, the this method will be called when the service is unregistered with the service router.
+ (void)unregistered;
@end


/// Provides the ability to open a URL on device external to app.
/// URLs may launch different apps on the device, for example:
/// <ul>
///   <li>
///     The URL <code>mailto://someone@example.com?Subject=Hello%20again</code> would open the mail app.
///   </li>
///   <li>
///     The URL <code>tel:1-800-555-1212</code> would open the phone app, and initiate a phone call.
///   </li>
///   <li>
///     The URL <code>https://www.google.com</code> would open the Safari app.
///   </li>
/// </ul>
SWIFT_CLASS("_TtC15PredixMobileSDK14OpenURLService")
@interface OpenURLService : NSObject <ServiceProtocol>
/// Unique identifier for this service.
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull serviceIdentifier;)
+ (NSString * _Nonnull)serviceIdentifier SWIFT_WARN_UNUSED_RESULT;
/// ServiceProtocol performRequest implementation for this service.
/// seealso:
/// <code>ServiceProtocol</code>
+ (void)performRequest:(NSURLRequest * _Nonnull)request response:(NSHTTPURLResponse * _Nonnull)response responseReturn:(responseReturnBlock _Nonnull)responseReturn dataReturn:(dataReturnBlock _Nonnull)dataReturn requestComplete:(requestCompleteBlock _Nonnull)requestComplete;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

enum WaitState : NSInteger;
@class WaitStateReturn;

/// Primary interface for the PredixMobileSDK to communicate with the UI.
/// Used to display the main UI, and the Authentication UI
/// Informs the UI when to display a native UI waiting component (spinner or progress bar)
/// Provides communication channel for notifications (script execution)
SWIFT_PROTOCOL("_TtP15PredixMobileSDK23PredixAppWindowProtocol_")
@protocol PredixAppWindowProtocol
/// LoadURL will be called when the SDK wants the UI to display a new page, i.e. a Predix Mobile WebApp.
/// Prior to calling LoadURL any attachments associated with the webapp document will be extracted.
/// \param url URL to the HTML page the UI should load.
/// Generally this is the file indicated in the “main” property of the webapp document, but may also be other values such as “about:blank”, non-URLs in the case of non-hybrid native applications, or for the authentication UI, URLs associated with offline password management.
///
/// \param parameters The properties from the webapp document. Generally these are included in the webapp.json file when doing a <code>pm publish</code>. The webapp document can thus be used to pass infromation to the container for how to behave when loading the webapp.
/// The example Predix Mobile iOS container uses this to indicate how scrolling behavior should be handled within the web view.
///
/// \param onComplete Optional closure, that if included should be called when the URL load has been completed.
///
- (void)loadURL:(NSURL * _Nonnull)url parameters:(NSDictionary * _Nullable)parameters onComplete:(void (^ _Nullable)(void))onComplete;
/// Informs the UI that the wait state should be updated, optionally displaying a message.
/// Wait state visualizations can be progress bars, spinners, text, etc.
- (void)updateWaitState:(enum WaitState)state message:(NSString * _Nullable)message;
/// Returns the current wait state to the SDK on request.
/// The SDK will call this when a GET request has been made to the window service, spinner path (http:/pmapi/window/spinner)
- (WaitStateReturn * _Nonnull)waitState SWIFT_WARN_UNUSED_RESULT;
@optional
/// Called when the SDK wants to send a message to the UI; generally a JavaScript command to be run in a webapp.
/// This method is not usually implemented for native UI implementations.
/// Notifications coming from the SDK will be sent to the WebApp through this method.
/// For webapps, the provided script should be executed via a command like: <code>stringByEvaluatingJavaScript(from: String)</code>
/// \param script The script string to evaluate.
///
- (void)receiveAppNotification:(NSString * _Nonnull)script;
@end


/// Static class of elements Predix Mobile SDK consumers can use to adjust to configure aspects of the SDK.
SWIFT_CLASS("_TtC15PredixMobileSDK27PredixMobilityConfiguration")
@interface PredixMobilityConfiguration : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// <h2>Predix Mobile SDK main manager class</h2>
/// Controls the interface between the container application and the SDK.
SWIFT_CLASS("_TtC15PredixMobileSDK21PredixMobilityManager")
@interface PredixMobilityManager : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end





/// Public protocol implemented by the Service Router for service registration and processing requests.
/// seealso:
/// <code>ServiceRouter</code>
SWIFT_PROTOCOL("_TtP15PredixMobileSDK21ServiceRouterProtocol_")
@protocol ServiceRouterProtocol
/// Registers the provided service class.
/// \param service class type meeting the ServiceProtocol type.
///
///
/// returns:
///
/// true if registration was successful.
- (BOOL)registerService:(Class <ServiceProtocol> _Nonnull)service;
/// Unregisters the provided service class, if the service was previously registered.
/// If the service was not registered this method has no effect.
/// \param service class type meeting the ServiceProtocol type to unregister
///
- (void)unregisterService:(Class <ServiceProtocol> _Nonnull)service;
/// Processes the provided request, routing the request to the appropriate service.
/// All processRequest methods should be considered asynchronous. Return closures may not be called on the same dispatch queue as the original request.
/// The request URL will be similar to: <code>http://pmapi/serviceid/extrapath</code>
/// \param request The URLRequest to process
///
/// \param responseBlock First of three return closures. The service will call this closure to return response object back to the calling code.
///
/// \param dataBlock Second of the three return closures. The service will call this closure to return data back to the calling code.
/// This closure may not be called if the service does not return any data.
///
/// \param completionBlock Third and final of the three return closures. The service will call this closure when the service request has completed.
///
- (void)processRequest:(NSURLRequest * _Nonnull)request responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
/// Constructs a basic GET request for given service identifier and processes the provided request, routing the request to the appropriate service.
/// All processRequest methods should be considered asynchronous. Return closures may not be called on the same dispatch queue as the original request.
/// The request URL will be similar to: <code>http://pmapi/serviceid</code>
/// \param serviceId Service Identifier, specifying the service that should process the request.
///
/// \param responseBlock First of three return closures. The service will call this closure to return response object back to the calling code.
///
/// \param dataBlock Second of the three return closures. The service will call this closure to return data back to the calling code.
/// This closure may not be called if the service does not return any data.
///
/// \param completionBlock Third and final of the three return closures. The service will call this closure when the service request has completed.
///
- (void)processRequestWithServiceId:(NSString * _Nonnull)serviceId responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
/// Constructs a GET request for given service identifier and processes the provided request, routing the request to the appropriate service.
/// All processRequest methods should be considered asynchronous. Return closures may not be called on the same dispatch queue as the original request.
/// The request URL will be similar to: <code>http://pmapi/serviceid/extrapath</code>
/// <ul>
///   <li>
///     examples, given a servideId of “serviceid”, and extraPath of:
///     <ul>
///       <li>
///         <code>foo</code> –> resulting url: <code>http://pmapi/serviceid/foo</code>
///       </li>
///       <li>
///         <code>foo/bar?some=query&another=value</code> –> resulting url: <code>http://pmapi/serviceid/foo/bar?some=query&another=value</code>
///       </li>
///     </ul>
///   </li>
/// </ul>
/// \param serviceId Service Identifier, specifying the service that should process the request.
///
/// \param extraPath Optional string to include in the request URL after the service identifier. This string may include any valid URL components, including multiple path depths, and query strings
///
/// \param responseBlock First of three return closures. The service will call this closure to return response object back to the calling code.
///
/// \param dataBlock Second of the three return closures. The service will call this closure to return data back to the calling code.
/// This closure may not be called if the service does not return any data.
///
/// \param completionBlock Third and final of the three return closures. The service will call this closure when the service request has completed.
///
- (void)processRequest:(NSString * _Nonnull)serviceId extraPath:(NSString * _Nullable)extraPath responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
/// Constructs a request for given service identifier and processes the provided request, routing the request to the appropriate service.
/// All processRequest methods should be considered asynchronous. Return closures may not be called on the same dispatch queue as the original request.
/// The request URL will be similar to: <code>http://pmapi/serviceid/extrapath</code>
/// <ul>
///   <li>
///     examples, given a servideId of “serviceid”, and extraPath of:
///     <ul>
///       <li>
///         <code>foo</code> –> resulting url: <code>http://pmapi/serviceid/foo</code>
///       </li>
///       <li>
///         <code>foo/bar?some=query&another=value</code> –> resulting url: <code>http://pmapi/serviceid/foo/bar?some=query&another=value</code>
///       </li>
///     </ul>
///   </li>
/// </ul>
/// \param serviceId Service Identifier, specifying the service that should process the request.
///
/// \param extraPath Optional string to include in the request URL after the service identifier. This string may include any valid URL components, including multiple path depths, and query strings
///
/// \param method HTTP method string to use for the request, i.e. “GET”, “POST, “PUT”, “DELETE”, “OPTION”, etc.
///
/// \param data Body data to include in the request.
///
/// \param responseBlock First of three return closures. The service will call this closure to return response object back to the calling code.
///
/// \param dataBlock Second of the three return closures. The service will call this closure to return data back to the calling code.
/// This closure may not be called if the service does not return any data.
///
/// \param completionBlock Third and final of the three return closures. The service will call this closure when the service request has completed.
///
- (void)processRequest:(NSString * _Nonnull)serviceId extraPath:(NSString * _Nullable)extraPath method:(NSString * _Nonnull)method data:(NSData * _Nullable)data responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
@end


/// The ServiceRouter controls what services are available or unavailable and processes service requests.
/// When a service is <code>registered</code> it is made available to process requests. When it is <code>unregistered</code> it is no longer available to service requests.
/// <ul>
///   <li>
///     All services registered must have a unique serviceIdentifier string.
///   </li>
///   <li>
///     Attempts to register a service with a serviceIdentifier string that is already registered will not be successful.
///   </li>
/// </ul>
SWIFT_CLASS("_TtC15PredixMobileSDK13ServiceRouter")
@interface ServiceRouter : NSObject <ServiceRouterProtocol>
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
/// Registers the provided service class.
/// \param service class type meeting the ServiceProtocol type.
///
///
/// returns:
///
/// true if registration was successful.
- (BOOL)registerService:(Class <ServiceProtocol> _Nonnull)service;
/// Unregisters the provided service class, if the service was previously registered.
/// If the service was not registered this method has no effect.
/// \param service class type meeting the ServiceProtocol type to unregister
///
- (void)unregisterService:(Class <ServiceProtocol> _Nonnull)service;
/// Constructs a basic GET request for given service identifier and processes the provided request, routing the request to the appropriate service.
/// All processRequest methods should be considered asynchronous. Return closures may not be called on the same dispatch queue as the original request.
/// The request URL will be similar to: <code>http://pmapi/serviceid</code>
/// \param serviceId Service Identifier, specifying the service that should process the request.
///
/// \param responseBlock First of three return closures. The service will call this closure to return response object back to the calling code.
///
/// \param dataBlock Second of the three return closures. The service will call this closure to return data back to the calling code.
/// This closure may not be called if the service does not return any data.
///
/// \param completionBlock Third and final of the three return closures. The service will call this closure when the service request has completed.
///
- (void)processRequestWithServiceId:(NSString * _Nonnull)serviceId responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
/// Constructs a GET request for given service identifier and processes the provided request, routing the request to the appropriate service.
/// All processRequest methods should be considered asynchronous. Return closures may not be called on the same dispatch queue as the original request.
/// The request URL will be similar to: <code>http://pmapi/serviceid/extrapath</code>
/// \param serviceId Service Identifier, specifying the service that should process the request.
///
/// \param extraPath Optional string to include in the request URL after the service identifier. This string may include any valid URL components, including multiple path depths, and query strings
/// <ul>
///   <li>
///     examples, given a servideId of “serviceid”, and extraPath of:
///     <ul>
///       <li>
///         <code>foo</code> –> resulting url: <code>http://pmapi/serviceid/foo</code>
///       </li>
///       <li>
///         <code>foo/bar?some=query&another=value</code> –> resulting url: <code>http://pmapi/serviceid/foo/bar?some=query&another=value</code>
///       </li>
///     </ul>
///   </li>
/// </ul>
///
/// \param responseBlock First of three return closures. The service will call this closure to return response object back to the calling code.
///
/// \param dataBlock Second of the three return closures. The service will call this closure to return data back to the calling code.
/// This closure may not be called if the service does not return any data.
///
/// \param completionBlock Third and final of the three return closures. The service will call this closure when the service request has completed.
///
- (void)processRequest:(NSString * _Nonnull)serviceId extraPath:(NSString * _Nullable)extraPath responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
/// Constructs a request for given service identifier and processes the provided request, routing the request to the appropriate service.
/// All processRequest methods should be considered asynchronous. Return closures may not be called on the same dispatch queue as the original request.
/// The request URL will be similar to: <code>http://pmapi/serviceid/extrapath</code>
/// <ul>
///   <li>
///     examples, given a servideId of “serviceid”, and extraPath of:
///     <ul>
///       <li>
///         <code>foo</code> –> resulting url: <code>http://pmapi/serviceid/foo</code>
///       </li>
///       <li>
///         <code>foo/bar?some=query&another=value</code> –> resulting url: <code>http://pmapi/serviceid/foo/bar?some=query&another=value</code>
///       </li>
///     </ul>
///   </li>
/// </ul>
/// \param serviceId Service Identifier, specifying the service that should process the request.
///
/// \param extraPath Optional string to include in the request URL after the service identifier. This string may include any valid URL components, including multiple path depths, and query strings
///
/// \param method HTTP method string to use for the request, i.e. “GET”, “POST, “PUT”, “DELETE”, “OPTION”, etc.
///
/// \param data Body data to include in the request.
///
/// \param responseBlock First of three return closures. The service will call this closure to return response object back to the calling code.
///
/// \param dataBlock Second of the three return closures. The service will call this closure to return data back to the calling code.
/// This closure may not be called if the service does not return any data.
///
/// \param completionBlock Third and final of the three return closures. The service will call this closure when the service request has completed.
///
- (void)processRequest:(NSString * _Nonnull)serviceId extraPath:(NSString * _Nullable)extraPath method:(NSString * _Nonnull)method data:(NSData * _Nullable)data responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
/// Processes the provided request, routing the request to the appropriate service.
/// All processRequest methods should be considered asynchronous. Return closures may not be called on the same dispatch queue as the original request.
/// The request URL will be similar to: <code>http://pmapi/serviceid/extrapath</code>
/// \param request The URLRequest to process
///
/// \param responseBlock First of three return closures. The service will call this closure to return response object back to the calling code.
///
/// \param dataBlock Second of the three return closures. The service will call this closure to return data back to the calling code.
/// This closure may not be called if the service does not return any data.
///
/// \param completionBlock Third and final of the three return closures. The service will call this closure when the service request has completed.
///
- (void)processRequest:(NSURLRequest * _Nonnull)request responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
@end








/// Possible Wait states, either the spinner/progress bar is showing (Waiting), or not showing (NotWaiting).
typedef SWIFT_ENUM(NSInteger, WaitState) {
/// Spinner or other indicator is displayed while user is waiting for a long-running task
  WaitStateWaiting = 0,
/// No spinner is being displayed, user is not waiting
  WaitStateNotWaiting = 1,
};


/// Wrapper object used for returning the wait state of the UI. Encapsulates both the WaitState enumeration, and the optional string message.
SWIFT_CLASS("_TtC15PredixMobileSDK15WaitStateReturn")
@interface WaitStateReturn : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
