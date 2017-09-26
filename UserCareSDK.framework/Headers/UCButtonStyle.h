#import <Foundation/Foundation.h>
#import "UCCustomizable.h"

@class UIColor;
@class UCTextStyle;

/**
 * @discussion Style object for updating information for UIButton objects
 * @warning UIButton must comfirm UCCustomizable protocol
 */
@interface UCButtonStyle : NSObject <UCStyle>

/**
 @brief URI to backbround image
 */
@property (nonatomic, strong) NSString *image;

/**
 @brief Defines custom text style.
 */
@property (nonatomic, strong) UCTextStyle *textStyle;

/**
 @brief Defines a text location
 */
@property (nonatomic, strong) NSString *textLocation;

/**
 @brief Defines a text alignment
 */
@property (nonatomic, strong) NSString *textAlignment;

/**
 @brief Defines button background color if backbround image is not set.
 */
@property (nonatomic, strong) UIColor *backgroundColor;

@end
