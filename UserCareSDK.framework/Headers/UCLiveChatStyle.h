#import <Foundation/Foundation.h>

@class UCTextStyle;
@class UCLabelStyle;
@class UCImageStyle;
@class UCButtonStyle;
@class UCHeaderStyle;

@interface UCLiveChatStyle : NSObject

@property (nonatomic, strong) UCTextStyle *userSettingsFirstNameStyle;
@property (nonatomic, strong) UCTextStyle *userSettingsLastNameStyle;
@property (nonatomic, strong) UCTextStyle *userSettingsEmailStyle;
@property (nonatomic, strong) UCTextStyle *messagingEntryBoxStyle;

@property (nonatomic, strong) UCLabelStyle *timestampLabelStyle;
@property (nonatomic, strong) UCLabelStyle *faqLinkStyle;
@property (nonatomic, strong) UCLabelStyle *entryBoxStyle;
@property (nonatomic, strong) UCLabelStyle *userMessageLabelStyle;
@property (nonatomic, strong) UCLabelStyle *systemMessageLabelStyle;
@property (nonatomic, strong) UCLabelStyle *agentMessageLabelStyle;
@property (nonatomic, strong) UCLabelStyle *greetingMessageTextStyle;

@property (nonatomic, strong) UCButtonStyle *entrySendStyle;
@property (nonatomic, strong) UCButtonStyle *entryDoneStyle;
@property (nonatomic, strong) UCButtonStyle *liveChatButtonStyle;
@property (nonatomic, strong) UCButtonStyle *userSettingsButtonStyle;

@property (nonatomic, strong) UCImageStyle *liveChatToolbarBackgroundStyle;
@property (nonatomic, strong) UCImageStyle *liveChatBackgroundStyle;
@property (nonatomic, strong) UCImageStyle *userSettingsBackgroundStyle;

@property (nonatomic, strong) UCHeaderStyle *liveChatHeaderStyle;
@property (nonatomic, strong) UCHeaderStyle *userSettingsHeaderStyle;

+ (UCLiveChatStyle *)styleWithDictionary:(NSDictionary *)dictionary;
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
