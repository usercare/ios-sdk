#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class UCTextStyle;

@interface UCLabelStyle : NSObject

@property (nonatomic, strong) UCTextStyle *textStyle;
@property (nonatomic, strong) UIColor *backgroundColor;

- (id)initWithDictionary:(NSDictionary *)dictionary;
- (void)applyStyle:(id)uiElement;
- (void)applyStyleToAttributedString:(NSMutableAttributedString *)attrString;

@end
