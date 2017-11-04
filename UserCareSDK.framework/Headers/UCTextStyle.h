#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UCCustomizable.h"

extern NSString * const kUCJSONKeyLabelBackgroundColor;

/**
 @brief Style model for text labels. 
 */
@interface UCTextStyle : NSObject <UCStyle>

@property (nonatomic, strong) NSString *fontFamily;
@property (nonatomic, strong) NSString *fontStyle;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *hintColor;
@property (nonatomic, strong) NSNumber *fontSize;

/**
 @brief Return font that have applied values style to default one.
 @param sourceFont - Original font
 @return Styled font
 */
- (UIFont *)styledFont:(UIFont *)sourceFont;

@end
