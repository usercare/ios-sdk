#import <Foundation/Foundation.h>
#import "UCTextStyle.h"

@interface UCButtonStyle : NSObject

@property (nonatomic, strong) NSString *image;
@property (nonatomic, strong) UCTextStyle *textStyle;
@property (nonatomic, strong) NSString *textLocation;
@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) UIColor *backgroundColor;

+ (UCButtonStyle *)buttonStyleWithDictionary:(NSDictionary *)dictionary;

@end
