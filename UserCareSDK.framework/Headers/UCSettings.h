#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class UCButtonStyle;
@class UCFAQStyle;
@class UCLiveChatStyle;
@class UCTicketStyle;

extern NSString * const kUCJSONKeyFAQ;
extern NSString * const kUCJSONKeyLink;
extern NSString * const kUCJSONKeyEmpty;

extern NSString * const kUCBackgroundImageRepeat;
extern NSString * const kUCBackgroundImageRepeatX;
extern NSString * const kUCBackgroundImageRepeatY;
extern NSString * const kUCBackgroundImageNoRepeatFit;
extern NSString * const kUCBackgroundImageNoRepeatFill;
extern NSString * const kUCBackgroundImageNoRepeatCenter;
extern NSString * const kUCBackgroundImageNoRepeatCrop;

extern NSUInteger const kUCSessionDefaultInterval;

/**
 * Contains UI settings, parsed from server responce. Initiates with initWithStatusDictionary:.
 */
@interface UCSettings : NSObject

/**
 * @brief Creates instance of UCSettings object.
 * @param dictionary parsed dictionary from JSON.
 * @return UCSettings object instance.
 */
- (instancetype)initWithStatusDictionary:(NSDictionary *)dictionary;

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
 * Timeout of session.
 * Should be set up.
 */
@property (nonatomic, strong) NSNumber *sessionContinuationInterval;

/**
 * An AppID used for events
 */
@property (nonatomic, strong) NSNumber *customerAppIdForEvents;

/**
 * String of a VIP Lounge URL address
 */
@property (nonatomic, strong) NSString *VIPLoungeURL;

/**
 * String of a Landing page URL address
 */
@property (nonatomic, strong) NSString *landingPageURL;

/**
 * Style of a VIP Lounge.
 */
@property (nonatomic, strong) UCButtonStyle *vipLoungeButtonStyle;

/**
 * Style of a landing page button.
 */
@property (nonatomic, strong) UCButtonStyle *landingPageButtonStyle;

/**
 * Style of a FAQ screen.
 * @see UCFAQStyle.
 */
@property (nonatomic, strong) UCFAQStyle *FAQStyle;

/**
 * Style of a Live Chat screen.
 * @see UCLiveChatStyle.
 */
@property (nonatomic, strong) UCLiveChatStyle *liveChatStyle;

/**
 * Style of a Tickets screen.
 * @see UCTicketStyle.
 */
@property (nonatomic, strong) UCTicketStyle *ticketStyle;

@end
