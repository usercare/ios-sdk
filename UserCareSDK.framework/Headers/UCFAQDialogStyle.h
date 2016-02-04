#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class UCTextStyle;

@interface UCFAQDialogStyle : NSObject

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) NSString *backgroundImageUrlString;
@property (nonatomic, strong) UCTextStyle *textStyle;

+ (UCFAQDialogStyle *)faqDialogStyleWithDictionary:(NSDictionary *)dictionary;

@end
