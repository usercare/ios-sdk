#import <Foundation/Foundation.h>

@class UCEvent;
@class UCFAQEntry;
@class AiPushInAppAction;

extern NSString * const _Nonnull kAiEventPurchaseTitle;
extern NSString * const _Nonnull kAiEventPurchaseSKU;
extern NSString * const _Nonnull kAiEventPurchasePrice;
extern NSString * const _Nonnull kAiEventPurchaseCurrency;
extern NSString * const _Nonnull kAiEventPurchaseTransactionId;
extern NSString * const _Nonnull kAiEventPurchaseTransactionTime;

/**
 Main interface of event SDK. Initialize it with startLoggingWithAPISecret: . First get API secret from developer console.
 */
@interface UCEventLogger : NSObject

+ (UCEventLogger * _Nonnull)sharedInstance;

/**
 * @breif Starts service.
 * @return pointer to instance of UCEventLogger.
 * @param secret - your API secret. Sign up and check developer console to receive it.
 */

+ (UCEventLogger * _Nonnull)startLoggingWithAPISecret:(NSString * _Nonnull)secret;

#pragma mark - v2 api

/**
 * @brief Logs FAQ read event to server.
 * @param faqNumber - read faq seq. number
 * @param locale - faq locale
 */
+ (void)v2LogFaqRead:(NSNumber * _Nonnull)faqNumber locale:(NSString * _Nonnull)locale;

/**
 * @brief Logs FAQ rated event to server.
 * @param faqNumber - rated faq sequence number
 * @param locale - faq locale
 * @param positive - is faq item was helpful
 * @param message - comment to be submitted when faq item wasn't helpful
 */
+ (void)v2LogFaqRated:(NSNumber * _Nonnull)faqNumber locale:(NSString * _Nonnull)locale positive:(BOOL)positive message:(NSString * _Nullable)message;

/**
 * @breif Purchase details with next required keys:
 * kAiEventPurchasePrice - Product price e.g. @(4.99)
 * kAiEventPurchaseCurrency - Currency e.g. @"USD"
 * kAiEventPurchaseSKU - Product sku e.g. @"sku25coins"
 * kAiEventPurchaseTitle - Purchase title e.g. @"25 coins"
 * kAiEventPurchaseTransactionId - Transaction identifier
 * kAiEventPurchaseTransactionTime - Transaction time
 * @param purchaseDetails - NSDictionary whcih contains properties of purchase event
 */
+ (void)v2LogPurchase:(NSDictionary<NSString *, id> * _Nonnull)purchaseDetails;

/**
 * @brief Logs event when action invoked.
 * @param action - AiPushInAppAction to be marked as invoked.
 * @param error - NSError if action execution failed
 */
+ (void)v2LogActionInvoked:(AiPushInAppAction * _Nonnull)action error:(NSError * _Nullable)error;

/**
 * @brief Logs crash report from crashlytics
 * @param crashReport - CLSReport report provided by crashlytics
 */
+ (void)v2LogCrashlyticsCrash:(id _Nonnull)crashReport;

/**
 * @brief Logs crash report
 * @param error - NSError to be logged
 */
+ (void)v2LogError:(NSError * _Nonnull)error;

/**
 * @brief Logs crash report
 * @param error - NSError to be logged
 * @param name - Error name
 */
+ (void)v2LogError:(NSError * _Nonnull)error named:(NSString * _Nullable)name;

/**
 * @breif Sets customer's properties
 * @param properties - Properties dictionary
 */
+ (void)v2SetCustomerProperties:(NSDictionary<NSString *, id> * _Nonnull)properties;

/**
 * @brief Send event to server that session started
 */
+ (void)v2StartSession;

/**
 * @brief Send event to server that session has ended
 */
+ (void)v2StopSession;

/**
 * @brief Send event to server that session has ended
 * @param customerId - Specify external customer id which session was ended
 */
+ (void)v2StopSession:(NSString * _Nullable)customerId;

/**
 * @brief Stop active session and start new one
 */
+ (void)v2InvalidateSession;

/**
 * @brief Validate if session expired. 
 */
+ (BOOL)validateSession;

/**
 * @brief Log custom event to be displayed in customer's timeline
 * @param eventData - Custom attributes to be sent
 */
+ (void)v2LogCustomEvent:(NSDictionary<NSString *, id> * _Nullable)eventData;

+ (void)v2LogEvent:(NSString * _Nonnull)eventType withCustomAttributes:(NSDictionary<NSString *, id> * _Nullable)attributes;

#pragma mark - deprecated api

/**
 Logs event when action invoked.
 @param action - Action to be invoked.
 */
- (void)sendActionInvokedEvent:(AiPushInAppAction * _Nonnull)action __deprecated_msg("Use `[UCEventLogger v2LogActionInvoked:action error:error]`");

/**
 @param crashReport - CLSReport report provided by crashlytics
 */
- (void)sendCrashlyticsCrashEvent:(id _Nonnull)crashReport __deprecated_msg("Use `[UCEventLogger v2LogActionInvoked:action]`");

/**
 Logs custom event to server.
 @param eventType - user-defined type of event. Should be NSString no longer than 63 characters, alphanumeric with undercores allowed.
 @param userData - dictionary of additional parameters
 */
- (void)sendEvent:(NSString * _Nonnull)eventType withUserData:(NSDictionary * _Nonnull)userData __deprecated_msg("Use `[UCEventLogger v2LogEvent:type withCustomAttributes:attrs]`");

/**
 Logs custom event to server.
 @param eventType - user-defined type of event. Should be NSString no longer than 63 characters, alphanumeric with undercores allowed.
 */
- (void)sendEvent:(NSString * _Nonnull)eventType __deprecated_msg("Use `[UCEventLogger v2LogEvent:type withCustomAttributes:attrs]`");

/**
 Logs custom event to server.
 @param event - user-defined event. Should be UCEvent instance.
 */
- (void)sendEventWithEvent:(UCEvent * _Nonnull)event __deprecated_msg("Use `[UCEventLogger v2LogEvent:type withCustomAttributes:attrs]`");

/**
 Logs FAQ read event to server.
 @param faqEntry - current faq. Should be UCFAQEntry instance.
 */
- (void)sendFaqReadEvent:(UCFAQEntry * _Nonnull)faqEntry __deprecated_msg("Use `[UCEventLogger v2LogFaqRead:faqNumber locale:locale]`");

@end
