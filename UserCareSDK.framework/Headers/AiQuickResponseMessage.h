//
//  AIQuickResponseMessage.h
//  UserCareSDK
//
//  Created by Kirill Kazachenko on 2/10/17.
//  Copyright © 2017 UserCare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AiMessageBody.h"

extern NSString * const kAIQRTitleKey;
extern NSString * const kAIQRPayloadKey;
extern NSString * const kAIQRRepliesKey;
extern NSString * const kAIQRSelectedKey;

@interface AiQuickReply : NSObject

@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *payload;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, assign) BOOL selected;

+ (instancetype) quickReplyWithDictionary:(NSDictionary *)dictionary;

@end

@interface AiQuickResponseMessage : AiMessageBody

@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSArray *quickReplies;

+ (instancetype) quickResponseWithDictionary:(NSDictionary *)dictionary;

- (AiQuickReply *)selectedReply;

@end
