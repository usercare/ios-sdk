#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "UCCustomizable.h"

@class UCTextStyle;

/**
 * @discussion Style for labels.
 * Each label have background and text style to be configured.
 */
@interface UCLabelStyle : NSObject <UCStyle>

@property (nonatomic, strong) UCTextStyle *textStyle;
@property (nonatomic, strong) UIColor *backgroundColor;

@end
