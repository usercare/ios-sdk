#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class UCTextStyle;
@class UCTicketItemStyle;

@interface UCTicketStyle : NSObject

@property (nonatomic, strong) UCTextStyle *textStyle;
@property (nonatomic, strong) UCTextStyle *bonusesTextStyle;
@property (nonatomic, strong) UCTextStyle *messagesTextStyle;
@property (nonatomic, strong) UCTicketItemStyle *openButtonStyle;
@property (nonatomic, strong) UCTicketItemStyle *closedButtonStyle;
@property (nonatomic, strong) UCTicketItemStyle *openNewButtonStyle;
@property (nonatomic, strong) UCTicketItemStyle *headerStyle;

- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
