//
//  AiCardDeckMessage.h
//  UserCareSDK
//
//  Created by Kirill Kazachenko on 4/13/17.
//  Copyright © 2017 UserCare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AiMessageBody.h"

@class AiCardItem;
@class AiCardButton;

#pragma mark - AiCardButtonPostbackDelegate

@protocol AiCardButtonPostbackDelegate

- (void)sendPostback:(AiCardButton *_Nonnull)cardButton;

@end

#pragma mark - AiCardButtonType

/**
 * @brief Type of card deck button
 */
typedef NS_ENUM(NSUInteger, AiCardButtonType) {
    /**
     * @brief send Postback answer to agent
     */
    Postback,
    /**
     * @brief Open web url in safari / deeplink
     */
    WebUrl,
    /**
     * @brief Open dialer
     */
    Call
};

#pragma mark - AiCardDeckMessage

@interface AiCardDeckMessage : AiMessageBody

@property (nonatomic, strong, readonly) NSArray<AiCardItem *> *_Nonnull cards;

+ (instancetype _Nonnull)cardDeckWithDictionary:(NSDictionary *_Nonnull)dictionary;

@end

#pragma mark - AiCardItem

@interface AiCardItem : NSObject

@property (nonatomic, strong) NSArray<AiCardButton *> *_Nullable buttons;
@property (nonatomic, strong) NSString *_Nullable clickUrl;
@property (nonatomic, strong) NSString *_Nullable imageUrl;
@property (nonatomic, strong) NSString *_Nullable title;
@property (nonatomic, strong) NSString *_Nullable subTitle;

@property (nonatomic, weak) AiCardDeckMessage *_Nullable cardMessage;

+ (instancetype _Nonnull)cardItemWithDictionary:(NSDictionary *_Nonnull)dictionary;

@end

#pragma mark - AiCardButton

@interface AiCardButton : NSObject

@property (nonatomic, strong) NSString *_Nonnull title;
@property (nonatomic, strong) NSString *_Nullable payload;
@property (nonatomic, strong) NSURL *_Nullable url;
@property (nonatomic, assign) AiCardButtonType type;
@property (nonatomic, strong) NSString *_Nonnull rawType;
@property (nonatomic, assign) BOOL selected;

@property (nonatomic, weak) AiCardItem *_Nullable cardItem;

+ (instancetype _Nonnull)cardButtonWithDictionary:(NSDictionary *_Nonnull)dictionary;

- (void)execute:(id<AiCardButtonPostbackDelegate> _Nullable)postbackDelegate;

@end
