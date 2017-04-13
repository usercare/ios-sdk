#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UCCustomizable.h"

@class UCTextStyle;
@class UCTicketItemStyle;
@class UCImageStyle;
@class UCTicketImageTextStyle;
@class UCHeaderStyle;
@class UCButtonStyle;
@class UCLabelStyle;
@class AiNoTicketsStyle;

#pragma mark - UCTicketStyle

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
 Style for "My Tickets" screen when user have no tickets
 */
@property (nonatomic, strong) AiNoTicketsStyle *noTicketsStyle;

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

#pragma mark - AiNoTicketsStyle

/**
 @brief Style for tickets screen when customer have no tickets.
 */
@interface AiNoTicketsStyle : NSObject<UCStyle>

/**
 Background icon
 */
@property (nonatomic, strong) NSString *noTicketsImage;

/**
 Style for "Create ticket" button at bottom
 */
@property (nonatomic, strong) UCButtonStyle *createTicketButtonStyle;

/**
 Style for "No tickets" title
 */
@property (nonatomic, strong) UCTextStyle *noTicketsTitleStyle;

/**
 Style for "No tickets" message
 */
@property (nonatomic, strong) UCTextStyle *noTicketsMessageStyle;

@end
