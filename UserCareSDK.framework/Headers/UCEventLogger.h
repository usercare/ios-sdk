#import <Foundation/Foundation.h>

@class UCEvent;
@class UCFAQEntry;
@class AiPushInAppAction;

/**
 Main interface of event SDK. Initialize it with startLoggingWithAPISecret: . First get API secret from developer console.
 */
@interface UCEventLogger : NSObject


+ (UCEventLogger *)sharedInstance;

/**
    Starts service.
    @return pointer to instance of UCEventLogger.
    @param secret - your API secret. Sign up and check developer console to receive it.
 */

+ (UCEventLogger *)startLoggingWithAPISecret:(NSString *)secret;

/**
    Logs custom event to server.
    @param eventType - user-defined type of event. Should be NSString no longer than 63 characters, alphanumeric with undercores allowed.
    @param userData - dictionary of additional parameters
 */
- (void)sendEvent:(NSString *)eventType withUserData:(NSDictionary *)userData;

/**
 Logs custom event to server.
 @param eventType - user-defined type of event. Should be NSString no longer than 63 characters, alphanumeric with undercores allowed.
 */
- (void)sendEvent:(NSString *)eventType;

/**
 Logs custom event to server.
 @param event - user-defined event. Should be UCEvent instance.
 */
- (void)sendEventWithEvent:(UCEvent *)event;

/**
 Logs FAQ read event to server.
 @param faqEntry - current faq. Should be UCFAQEntry instance.
 */
- (void)sendFaqReadEvent:(UCFAQEntry *)faqEntry;

/**
 Logs event when action invoked.
 @param action - Action to be invoked.
 */
- (void)sendActionInvokedEvent:(AiPushInAppAction *)action;

/**
 @param crashReport - CLSReport report provided by crashlytics
 */
- (void)sendCrashlyticsCrashEvent:(id)crashReport;

/**
 Extends session timeout. Executed each time when network operation was pefomed by UC SDK.
 Session timeout controlled by settings property: [UCManager sharedInstance].settings.sessionContinuationInterval
 */
- (void)extendSession;


@end
