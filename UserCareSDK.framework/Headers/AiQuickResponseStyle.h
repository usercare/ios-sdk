//
//  AiQuickResponseStyle.h
//  UserCareSDK
//
//  Created by Kirill Kazachenko on 2/21/17.
//  Copyright © 2017 UserCare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UCLabelStyle.h"

@protocol UCStyle;
@class UCTextStyle;

@interface AiQuickResponseButtonStyle : NSObject <UCStyle>

@property (nonatomic, strong) UIColor *borderColor;
@property (nonatomic, strong) UCLabelStyle *buttonStyle;

@end

@interface AiQuickResponseStyle : NSObject <UCStyle>

@property (nonatomic, strong) UCLabelStyle *messageStyle;
@property (nonatomic, strong) AiQuickResponseButtonStyle *selectedStyle;
@property (nonatomic, strong) AiQuickResponseButtonStyle *unselectedStyle;

@end
