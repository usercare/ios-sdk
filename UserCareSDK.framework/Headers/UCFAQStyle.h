#import <Foundation/Foundation.h>

@class UCButtonStyle;
@class UCLabelStyle;
@class UCFAQStyle;
@class UCFAQDialogStyle;
@class UCImageStyle;
@class UCHeaderStyle;

@interface UCFAQStyle : NSObject

@property (nonatomic, strong) UCButtonStyle *faqButtonStyle;
@property (nonatomic, strong) UCButtonStyle *backButtonStyle;
@property (nonatomic, strong) UCImageStyle *faqBackgroundStyle;

@property (nonatomic, strong) UCLabelStyle *headerCellLabelStyle;
@property (nonatomic, strong) UCLabelStyle *topCellLabelStyle;
@property (nonatomic, strong) UCLabelStyle *cellLabelStyle;

@property (nonatomic, strong) UCHeaderStyle *navigationBarStyle;

@property (nonatomic, strong) UCHeaderStyle *searchBarStyle;
@property (nonatomic, strong) UCButtonStyle *searchButtonStyle;

@property (nonatomic, strong) UCFAQDialogStyle *faqNoButtonDialogStyle;
@property (nonatomic, strong) UCFAQDialogStyle *faqYesButtonDialogStyle;

+ (UCFAQStyle *)styleWithDictionary:(NSDictionary *)dictionary;
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
