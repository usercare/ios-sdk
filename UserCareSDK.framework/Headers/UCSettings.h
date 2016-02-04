#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UCTextStyle.h"
#import "UCButtonStyle.h"
#import "UCFAQDialogStyle.h"
#import "UCLocalizedStringsDataSource.h"
#import "UCTicketStyle.h"
#import "UCLabelStyle.h"
#import "UCSectionStyle.h"

static NSString *kUCBackgroundImageRepeat = @"REPEAT";
static NSString *kUCBackgroundImageRepeatX = @"REPEAT-X";
static NSString *kUCBackgroundImageRepeatY = @"REPEAT-Y";
static NSString *kUCBackgroundImageNoRepeatFit = @"NO-REPEAT-FIT";
static NSString *kUCBackgroundImageNoRepeatFill = @"NO-REPEAT-FILL";
static NSString *kUCBackgroundImageNoRepeatCenter = @"NO-REPEAT-CENTER";
static NSString *kUCBackgroundImageNoRepeatCrop = @"NO-REPEAT-CROP";

@interface UCSettings : NSObject

- (id)initWithStatusDictionary:(NSDictionary *)dictionary;

@property (nonatomic, assign) BOOL isLiveChatEnabled;
@property (nonatomic, assign) BOOL isVIPLoungeEnabled;
@property (nonatomic, assign) BOOL isFAQEnabled;
@property (nonatomic, assign) BOOL isLandingPageEnabled;
@property (nonatomic, assign) BOOL isMyTicketsEnabled;

@property (nonatomic, strong) NSNumber *sessionContinuationInterval;
@property (nonatomic, strong) NSNumber *customerAppIdForEvents;

@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) NSString *badgeCount;
@property (nonatomic, strong) NSString *VIPLoungeURL;

@property (nonatomic, strong) NSString *landingPageURL;

//UI Customization

@property (nonatomic, assign) BOOL faqShouldDisplayVipLounge;

@property (nonatomic, strong) UCButtonStyle *entrySendStyle;
@property (nonatomic, strong) UCButtonStyle *entryDoneStyle;
@property (nonatomic, strong) UCButtonStyle *faqCancelButtonStyle;
@property (nonatomic, strong) UCButtonStyle *vipLoungeButtonStyle;
@property (nonatomic, strong) UCButtonStyle *liveChatButtonStyle;
@property (nonatomic, strong) UCButtonStyle *faqButtonStyle;
@property (nonatomic, strong) UCButtonStyle *landingPageButtonStyle;
@property (nonatomic, strong) UCButtonStyle *myTicketsButtonStyle;
@property (nonatomic, strong) UCButtonStyle *myTicketsLiveChatButtonStyle;

@property (nonatomic, strong) UCLabelStyle *userStyle;
@property (nonatomic, strong) UCLabelStyle *systemStyle;
@property (nonatomic, strong) UCLabelStyle *agentStyle;
@property (nonatomic, strong) UCLabelStyle *greetingStyle;
@property (nonatomic, strong) UCLabelStyle *timestampStyle;
@property (nonatomic, strong) UCLabelStyle *faqLinkStyle;
@property (nonatomic, strong) UCLabelStyle *faqTableRowStyle;
@property (nonatomic, strong) UCLabelStyle *faqTableHeaderStyle;
@property (nonatomic, strong) UCLabelStyle *entryBoxStyle;

@property (nonatomic, strong) UCSectionStyle *myTicketsSectionStyle;
@property (nonatomic, strong) UCSectionStyle *liveChatSectionStyle;
@property (nonatomic, strong) UCSectionStyle *faqSectionStyle;

@property (nonatomic, strong) UCFAQDialogStyle *faqNoButtonDialogStyle;
@property (nonatomic, strong) UCFAQDialogStyle *faqYesButtonDialogStyle;

@property (nonatomic, strong) UCTicketStyle *ticketStyle;

@property (nonatomic, strong) UIColor *liveChatEntryBarBackgroundColor;
@property (nonatomic, strong) NSString *liveChatEntryBarBackgroundImage;

@end
