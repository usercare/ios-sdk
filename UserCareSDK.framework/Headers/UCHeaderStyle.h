#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UCCustomizable.h"

@class UCTextStyle;

@interface UCHeaderStyle : NSObject <UCStyle>

@property (nonatomic, strong) UCTextStyle *textStyle;
@property (nonatomic, copy) NSString *backgroundImageUrl;
@property (nonatomic, strong) UIColor *backgroundColor;

@end
