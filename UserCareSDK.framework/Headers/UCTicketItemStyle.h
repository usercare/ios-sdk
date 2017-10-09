#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UCCustomizable.h"

@class UCTextStyle;

/**
 * @brief UCTicketItemStyle used for styling ticket item.
 */
@interface UCTicketItemStyle : NSObject <UCStyle>

@property (nonatomic, strong) UCTextStyle *openedTextStyle;
@property (nonatomic, strong) UCTextStyle *closedTextStyle;
@property (nonatomic, strong) UIColor *itemBackgroundColor;

/**
 * Constraint value for tickets & bonuses icon width
 * @default 14
 */
@property (nonatomic, assign) CGFloat indicatorIconWidth;

/**
 * Constraint value for tickets & bonuses icon height
 * @default 14
 */
@property (nonatomic, assign) CGFloat indicatorIconHeight;

/*
 * Indicator icon content mode.
 * @default UIViewContentModeScaleAspectFit
 */
@property (nonatomic, assign) UIViewContentMode indicatorIconContentMode;

@end
