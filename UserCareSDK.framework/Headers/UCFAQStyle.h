#import <Foundation/Foundation.h>

@class UCButtonStyle;
@class UCLabelStyle;
@class UCFAQStyle;
@class UCFAQDialogStyle;
@class UCImageStyle;
@class UCHeaderStyle;

/**
 * Instance of this class contain settings of a FAQ screen
 */
@interface UCFAQStyle : NSObject

/**
 Style of a FAQ button.
 */
@property (nonatomic, strong) UCButtonStyle *faqButtonStyle;

/**
 Style of a back button
 */
@property (nonatomic, strong) UCButtonStyle *backButtonStyle;

/**
 Background style of a FAQ screen.
 */
@property (nonatomic, strong) UCImageStyle *faqBackgroundStyle;

/**
 Style of a table view headers.
 */
@property (nonatomic, strong) UCLabelStyle *headerCellLabelStyle;

/**
 Style of a top FAQ cells.
 */
@property (nonatomic, strong) UCLabelStyle *topCellLabelStyle;

/**
 Style of a FAQ cells.
 */
@property (nonatomic, strong) UCLabelStyle *cellLabelStyle;

/**
 Style of a empty FAQ list label warning.
 */
@property (nonatomic, strong) UCLabelStyle *emptyFaqLabelStyle;

/**
 Style of a FAQ navigation bar.
 */
@property (nonatomic, strong) UCHeaderStyle *navigationBarStyle;

/**
 Style of a search bar.
 */
@property (nonatomic, strong) UCHeaderStyle *searchBarStyle;

/**
 Style of a search Button.
 */
@property (nonatomic, strong) UCButtonStyle *searchButtonStyle;

/**
 Negative dialog buttons style.
 */
@property (nonatomic, strong) UCFAQDialogStyle *faqNoButtonDialogStyle;

/**
 Positive dialog buttons style
 */
@property (nonatomic, strong) UCFAQDialogStyle *faqYesButtonDialogStyle;

/**
 Negative button style
 */
@property (nonatomic, strong) UCLabelStyle *faqNoButtonStyle;

/**
 Positive feedback button style
 */
@property (nonatomic, strong) UCLabelStyle *faqYesButtonStyle;

/**
 FAQ feedback label style
 */
@property (nonatomic, strong) UCLabelStyle *faqFeedbackLabelStyle;

/**
 FAQ feedback label style
 */
@property (nonatomic, strong) UCLabelStyle *faqLastUpdatedLabelStyle;

/**
 @brief Creates instanse of UCFAQStyle from dictionary.
 @param dictionary Parsed from JSON dictionary.
 @return instanse of UCFAQStyle.
 */
+ (UCFAQStyle *)styleWithDictionary:(NSDictionary *)dictionary;

/**
 @brief Creates instanse of UCFAQStyle from dictionary.
 @param dictionary Parsed from JSON dictionary.
 @return instanse of UCFAQStyle.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
