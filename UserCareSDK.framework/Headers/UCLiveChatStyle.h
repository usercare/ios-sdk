#import <Foundation/Foundation.h>
#import "UCCustomizable.h"
#import <UIKit/UIKit.h>

@class UCTextStyle;
@class UCLabelStyle;
@class UCImageStyle;
@class UCButtonStyle;
@class UCHeaderStyle;
@class UCCustomMessage;
@class AiQuickResponseStyle;
@class AiCardDeckStyle;
@class AiAttachentIconStyle;

/**
 * Instanse of this class contain settings of Live chat screen.
 */
@interface UCLiveChatStyle : NSObject

/**
 Style of a first name text filed in user settings.
 */
@property (nonatomic, strong) UCTextStyle *userSettingsFirstNameStyle;

/**
 Style of a last name text filed in user settings.
 */
@property (nonatomic, strong) UCTextStyle *userSettingsLastNameStyle;

/**
 Style of an e-mail text filed in user settings.
 */
@property (nonatomic, strong) UCTextStyle *userSettingsEmailStyle;

/**
 Style of a messaging text filed in live chat.
 */
@property (nonatomic, strong) UCTextStyle *messagingEntryBoxStyle;

/**
 Style of links in link messagetype.
 */
@property (nonatomic, strong) UCLabelStyle *faqLinkStyle;

/**
 Style of a messaging text filed in live chat.
 */
@property (nonatomic, strong) UCLabelStyle *entryBoxStyle;

/**
 Style of user messages background and text.
 */
@property (nonatomic, strong) UCLabelStyle *userMessageLabelStyle;

/**
 Style of user message time.
 */
@property (nonatomic, strong) UCLabelStyle *userTimestampLabelStyle;

/**
 Style of system messages background and text.
 */
@property (nonatomic, strong) UCLabelStyle *systemMessageLabelStyle;

/**
 Style of a system message receiving time.
 */
@property (nonatomic, strong) UCLabelStyle *systemTimestampLabelStyle;

/**
 Style of agent messages background and text.
 */
@property (nonatomic, strong) UCLabelStyle *agentMessageLabelStyle;

/**
 Style of agent message time.
 */
@property (nonatomic, strong) UCLabelStyle *agentTimestampLabelStyle;

/**
 Style of greeting messages background and text.
 */
@property (nonatomic, strong) UCLabelStyle *greetingMessageTextStyle;

@property (nonatomic, strong) AiAttachentIconStyle *entryImageAttachment;

@property (nonatomic, strong) AiAttachentIconStyle *entryPhotoAttachment;

/**
 Style of a send button.
 */
@property (nonatomic, strong) UCButtonStyle *entrySendStyle;

/**
 Style of a done(back) button.
 */
@property (nonatomic, strong) UCButtonStyle *entryDoneStyle;

/**
 Style of a live chat button.
 */
@property (nonatomic, strong) UCButtonStyle *liveChatButtonStyle;

/**
 Style of a user settings butoon.
 */
@property (nonatomic, strong) UCButtonStyle *userSettingsButtonStyle;

/**
 Display user settings button at LiveChat.
 */
@property (nonatomic, assign) BOOL showSettingsButton;

/**
 Display user settings on create new ticket.
 */
@property (nonatomic, assign) BOOL showUserSettingsOnCreate;

/**
 Style of a cancel(back) button.
 */
@property (nonatomic, strong) UCButtonStyle *userSettingsCancelStyle;

/**
 Style of a live chat input toolbar.
 */
@property (nonatomic, strong) UCImageStyle *liveChatToolbarBackgroundStyle;

/**
 Background style of a live chat screen.
 */
@property (nonatomic, strong) UCImageStyle *liveChatBackgroundStyle;

/**
 Background style of a user settings screen.
 */
@property (nonatomic, strong) UCImageStyle *userSettingsBackgroundStyle;

/**
 Navigation bar style of a live chat screen
 */
@property (nonatomic, strong) UCHeaderStyle *liveChatHeaderStyle;

/**
 Navigation bar style of a user settings screen
 */
@property (nonatomic, strong) UCHeaderStyle *userSettingsHeaderStyle;

/**
 Quick response message style
 */
@property (nonatomic, strong) AiQuickResponseStyle *quickResponseStyle;

/**
 Card Deck message style
 */
@property (nonatomic, strong) AiCardDeckStyle *cardDeckStyle;

/**
 Group chat messages from a person within interval (hide date, smaller spacing) in seconds. Default value is 5 minutes.
 */
@property (nonatomic, assign) NSTimeInterval groupMessagesWithinInterval;

/**
 @brief Creates instanse of UCLiveChatStyle from dictionary.
 @param dictionary Parsed from JSON dictionary.
 @return instanse of UCLiveChatStyle.
 */
+ (UCLiveChatStyle *)styleWithDictionary:(NSDictionary *)dictionary;

/**
 @brief Creates instanse of UCLiveChatStyle from dictionary.
 @param dictionary Parsed from JSON dictionary.
 @return instanse of UCLiveChatStyle.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (UCLabelStyle *) styleForMessage: (UCCustomMessage *)message;

- (UCLabelStyle *) timeStyleForMessage: (UCCustomMessage *)message;

@end

@interface AiAttachentIconStyle : NSObject<UCStyle>

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) NSString *icon;

@end
