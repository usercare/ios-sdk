#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UCTextStyle.h"

@interface UCSectionStyle : NSObject

@property (nonatomic, copy) NSString *navbarBackgroundImage;
@property (nonatomic, strong) UCTextStyle *navbarTextStyle;
@property (nonatomic, strong) UIColor *navbarBackgroundColor;

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, copy) NSString *backgroundImage;
@property (nonatomic, copy) NSString *backgroundImageRepeat;

- (void)styleNavigationBar:(UINavigationBar *)navbar;
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
