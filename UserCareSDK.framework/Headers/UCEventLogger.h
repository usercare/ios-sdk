#import <Foundation/Foundation.h>

@class SKProduct;
@class SKPaymentTransaction;
@class UCEvent;
@class UCFAQEntry;

static NSString *const kUCEventActionInvoked = @"action_invoked";

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
    @param eventType - user-defined type of event. Should be NSString no longer than 63 characters, alphanumeric with hyphens allowed.
    @param parameters - dictionary of additional parameters
 */
- (void)sendEvent:(NSString *)eventType withCustomParameters:(NSDictionary *)parameters;

/**
 Logs custom event to server.
 @param eventType - user-defined type of event. Should be NSString no longer than 63 characters, alphanumeric with hyphens allowed.
 */
- (void)sendEvent:(NSString *)eventType;

/**
 Logs custom event to server.
 @param event - user-defined event. Should be UCEvent instance.
 */
- (void)sendEventWithEvent:(UCEvent *)event;

/**
 Logs FAQ read event to server.
 @param faqEntry - cureent faq. Should be UCFAQEntry instance.
 */
- (void)sendFaqReadEvent:(UCFAQEntry *)faqEntry;

@end
