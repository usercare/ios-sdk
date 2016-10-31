#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

extern NSString *const kUCEventSessionEnd;
extern NSString *const kUCEventPurchaseSuccess;
extern NSString *const kUCEventPurchaseFailed;
extern NSString *const kUCEventCrash;

/**
 Class represents event model used by EventLogger.
 */

@interface UCEvent : NSObject

/**
 @brief Type of event. Should be NSString no longer than 63 characters, alphanumeric with hyphens allowed.NSString representation of time when event occured. Predefined event types are: kUCEventSession, kUCEventSessionEnd, kUCEventPurchaseSuccess, kUCEventPurchaseFailed
 */
@property (nonatomic, copy) NSString *eventType;

/**
 @brief Product identifier of purchased product. Used for purchase events. Should be NSString.
 */
@property (nonatomic, copy) NSString *productId;

/**
 @brief Product title of purchased product. Used for purchase events. Should be NSString.
 */
@property (nonatomic, copy) NSString *title;

/**
 @brief Purchase transaction time. Used for purchase events. Should be NSString.
 */
@property (nonatomic, copy) NSString *transactionTime;

/**
 @brief Price for the purchased product. Used for purchase events. Should be NSNumber.
 */
@property (nonatomic, copy) NSNumber *price;

/**
 @brief Currency for the purchased product. Used for purchase events. Should be NSString in international currency format, for example "USD".
 */
@property (nonatomic, copy) NSString *priceCurrency;

/**
 @brief Transaction identifier for purchase operation. Used for purchase events. Should be NSString.
 */
@property (nonatomic, copy) NSString *transactionId;

/**
 @brief Custom parameters for any event. Should be NSDictionary.
 */
@property (nonatomic, strong) NSDictionary *customParameters;

/**
 @brief Custom parameters for any event. Should be NSDictionary.
 */
@property (nonatomic, strong) NSDictionary *customEventData;

/**
 @brief Session start identifier. Used for session tracking events. Should be NSString.
 */
@property (nonatomic, copy) NSString *sessionStartId;

/**
 @brief Crashlytics exception ID. Used if crashlytics is integrated into project.
 */
@property (nonatomic, copy) NSString *crashlyticsKey;

/**
 @brief Stack trace of handeled crash. Used for logging instead of crashlytics.
 */
@property (nonatomic, copy) NSString *stacktrace;

/**
 @breif Event timestamp
 */
@property (nonatomic, copy) NSString *timestamp;

/**
 @return instance of UCEvent with type.
 @param eventType - user-defined type of event. Should be NSString no longer than 63 characters, alphanumeric with hyphens allowed. Predefined event types are: kUCEventSession, kUCEventSessionEnd, kUCEventPurchaseSuccess, kUCEventPurchaseFailed
 */
- (id)initWithEventType:(NSString *)eventType;

/**
 @return instance of UCEvent with type.
 @param dictionary - user-defined dictinary with event parameters. Should be NSDictionary.
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

/**
 @return dictionary representation of UCEvent.
 */
- (NSDictionary *)dictionaryRepresentation;

/**
 @return dictionary representation of UCEvent with internal fields.
 */
- (NSDictionary *)persistentDictionaryRepresentation;

/**
 @return flag that allows event to be sent to server
 */
- (BOOL)readyToSync;

@end
