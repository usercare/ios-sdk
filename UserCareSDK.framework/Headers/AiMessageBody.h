//
//  AIMessage.h
//  UserCareSDK
//
//  Created by Kirill Kazachenko on 12/8/16.
//  Copyright © 2016 UserCare. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const kAITypeKey;
extern NSString * const kAITextKey;
extern NSString * const kAIQuickReplyKey;

@interface AiMessageBody : NSObject

@property (copy, nonatomic, readonly) NSString *messageType;

@end
