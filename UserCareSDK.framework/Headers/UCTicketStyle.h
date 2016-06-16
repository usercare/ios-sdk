#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class UCTextStyle;
@class UCTicketItemStyle;
@class UCImageStyle;
@class UCTicketImageTextStyle;
@class UCHeaderStyle;
@class UCButtonStyle;
@class UCLabelStyle;

/**
 * Instanse of this class contain settings of My Tickets screen.
 */
@interface UCTicketStyle : NSObject

/**
 Text style of a ticket.
 */
@property (nonatomic, strong) UCTextStyle *textStyle;

/**
 Background image of a table view in My Tickets screen.
 */
@property (nonatomic, strong) UCImageStyle *sectionStyle;

/**
 Add new ticket button style.
 */
@property (nonatomic, strong) UCButtonStyle *addTicketButtonStyle;

/**
 My tickets button style.
 */
@property (nonatomic, strong) UCButtonStyle *myTicketsButtonStyle;

/**
 Style of a empty Tickets list label warning. 
 */
@property (nonatomic, strong) UCLabelStyle *emptyTicketsLabelStyle;

/**
 Opened ticket cell style.
 */
@property (nonatomic, strong) UCTicketItemStyle *openTicketStyle;

/**
 Closed ticket button style.
 */
@property (nonatomic, strong) UCTicketItemStyle *closedTicketStyle;

/**
 My Ticket bonuses style.
 */
@property (nonatomic, strong) UCTicketImageTextStyle *bonusesStyle;

/**
 Messages style on a ticket cell.
 */
@property (nonatomic, strong) UCTicketImageTextStyle *messagesStyle;

/**
 Navigation bar style in My Tickets screen.
 */
@property (nonatomic, strong) UCHeaderStyle *headerStyle;

/**
 Navigation bar style in My Tickets Details screen.
 */
@property (nonatomic, strong) UCHeaderStyle *detailsHeaderStyle;

/**
 @brief Creates instanse of UCTicketStyle from dictionary.
 @param dictionary Parsed from JSON dictionary.
 @return instanse of UCTicketStyle.
 */
+ (UCTicketStyle *)styleWithDictionary:(NSDictionary *)dictionary;

/**
 @brief Creates instanse of UCTicketStyle from dictionary.
 @param dictionary Parsed from JSON dictionary.
 @return instanse of UCTicketStyle.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
