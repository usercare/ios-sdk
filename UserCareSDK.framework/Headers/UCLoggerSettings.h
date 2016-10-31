#import <Foundation/Foundation.h>

/**
 Class represents settings for EventLogger.
 */
@interface UCLoggerSettings : NSObject

/**
 Crashlytics Key will be used in crash logs.
 */
@property (nonatomic, readonly) NSString * _Nullable crashlyticsKey;

/**
 Defines wheter SDK will send logs.
 */
@property (nonatomic, assign) BOOL useCrashEventsLogger;

/**
 Defines wheter logs will contain logs from NSLog() function.
 */
@property (nonatomic, assign) BOOL sendApplicationLogs;

@end
