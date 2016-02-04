#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UCUtils.h"

static NSString *const kUCJSONKeyLabelFont = @"font";
static NSString *const kUCJSONKeyLabelFontColor = @"fontColor";
static NSString *const kUCJSONKeyLabelBackgroundColor = @"backgroundColor";
static NSString *const kUCJSONKeyLabelFontSize = @"fontSize";
static NSString *const kUCJSONKeyLabelFontFamily = @"fontFamily";
static NSString *const kUCJSONKeyLabelFontStyle = @"fontStyle";
static CGFloat const kUCDefaultFontSizeForLiveChat = 11.0f;

@interface UCTextStyle : NSObject

@property (nonatomic, strong) NSString *fontFamily;
@property (nonatomic, strong) NSString *fontStyle;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) NSNumber *fontSize;
@property (nonatomic, strong) UIFont *font;

- (id)initWithDictionary:(NSDictionary *)dictionary;

+ (UCTextStyle *)textStyleWithDictionary:(NSDictionary *)dictionary;
- (void)applyStyle:(id)uiElement;
- (void)applyStyleToAttributedString:(NSMutableAttributedString *)string;

@end
