//
//  AiCardDeckStyle.h
//  UserCareSDK
//
//  Created by Kirill Kazachenko on 7/11/17.
//  Copyright © 2017 UserCare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UCLabelStyle.h"
#import "UCButtonStyle.h"

@interface AiCardMessageStyle : NSObject<UCStyle>

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UCLabelStyle *linkStyle;
@property (nonatomic, strong) UCLabelStyle *titleStyle;
@property (nonatomic, strong) UCLabelStyle *subTitleStyle;

@end

@interface AiCardDeckStyle : NSObject<UCStyle>

@property (nonatomic, strong) AiCardMessageStyle *messageStyle;
@property (nonatomic, strong) UCButtonStyle *buttonStyle;
@property (nonatomic, strong) UCLabelStyle *postBackSelectedStyle;
@property (nonatomic, assign) BOOL titleAboveImage;

@end
