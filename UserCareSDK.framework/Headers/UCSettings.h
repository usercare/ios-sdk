#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class UCButtonStyle;
@class UCFAQStyle;
@class UCLiveChatStyle;
@class UCTicketStyle;

extern NSString * const _Nonnull kUCJSONKeyFAQ;
extern NSString * const _Nonnull kUCJSONKeyLink;
extern NSString * const _Nonnull kUCJSONKeyEmpty;

extern NSString * const _Nonnull kUCBackgroundImageRepeat;
extern NSString * const _Nonnull kUCBackgroundImageRepeatX;
extern NSString * const _Nonnull kUCBackgroundImageRepeatY;
extern NSString * const _Nonnull kUCBackgroundImageNoRepeatFit;
extern NSString * const _Nonnull kUCBackgroundImageNoRepeatFill;
extern NSString * const _Nonnull kUCBackgroundImageNoRepeatCenter;
extern NSString * const _Nonnull kUCBackgroundImageNoRepeatCrop;

extern NSUInteger const kUCSessionDefaultInterval;

/**
 * Contains UI settings, parsed from server responce. Initiates with initWithStatusDictionary:.
 */
@interface UCSettings : NSObject

/**
 * Defines whether Live Chat will be displayed.
 */
@property (nonatomic, assign) BOOL isLiveChatEnabled;

/**
 * Defines whether VIP Lounge will be displayed.
 */
@property (nonatomic, assign) BOOL isVIPLoungeEnabled;

/**
 * Defines whether FAQ will be displayed.
 */
@property (nonatomic, assign) BOOL isFAQEnabled;

/**
 * Defines whether Landing page will be displayed.
 */
@property (nonatomic, assign) BOOL isLandingPageEnabled;

/**
 * Defines whether My tickets will be displayed.
 */
@property (nonatomic, assign) BOOL isMyTicketsEnabled;

/**
 * Defines whether VIP Lounge will be displayed in FAQ.
 */
@property (nonatomic, assign) BOOL faqShouldDisplayVipLounge;

/**
 * @brief Display shorten back title of previous screen or just back arrow. Default YES.
 */
@property (nonatomic, assign) BOOL showNavigationBackTitle;

/**
 * Timeout of session.
 * Should be set up.
 */
@property (nonatomic, strong) NSNumber *sessionContinuationInterval;

/**
 * String of a VIP Lounge URL address
 */
@property (nonatomic, strong) NSString *VIPLoungeURL;

/**
 * Style of a VIP Lounge.
 */
@property (nonatomic, strong, nonnull) UCButtonStyle *vipLoungeButtonStyle;

/**
 * Style of a landing page button.
 */
@property (nonatomic, strong, nonnull) UCButtonStyle *landingPageButtonStyle;

/**
 * Style of a FAQ screen.
 * @see UCFAQStyle.
 */
@property (nonatomic, strong, nonnull) UCFAQStyle *FAQStyle;

/**
 * Style of a Live Chat screen.
 * @see UCLiveChatStyle.
 */
@property (nonatomic, strong, nonnull) UCLiveChatStyle *liveChatStyle;

/**
 * Style of a Tickets screen.
 * @see UCTicketStyle.
 */
@property (nonatomic, strong, nonnull) UCTicketStyle *ticketStyle;

@property (nonatomic, readonly, copy) NSString * _Nonnull defaultLocale;

@property (nonatomic, readonly, copy) NSString * _Nonnull translationsLink;

@property (nonatomic, readonly, copy) NSString * _Nonnull faqsLink;

/**
 * @brief Creates instance of UCSettings object.
 * @param dictionary parsed dictionary from JSON.
 * @return UCSettings object instance.
 */
- (instancetype _Nonnull)initWithStatusDictionary:(NSDictionary * _Nonnull)dictionary;

@end
