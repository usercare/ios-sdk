//
//  UCPush.h
//  UserCareSDK
//
//  Created by Kirill Kazachenko on 7/21/16.
//  Copyright © 2016 UserCare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class UCManager;
@class AiPushMessage;
@class AiPushInAppAction;

/**
 @brief UCPush contains necessary methods for processing push notifications and actions.
 */
@interface UCPush : NSObject

/**
 @brief Initialize UCPush with UCManager instance
 @param ucManager - UCManager instance
 */
- (instancetype)initWithManager:(UCManager *) ucManager;

/**
 Stores APNS device token for the further usage
 @param pushToken - push notifications token
 */
- (void)registeredForPushNotifications:(NSData *)pushToken;

/**
 @return push notifications token
 */
- (NSData *)pushToken;

/**
 @brief Handle push notification from UserCare and open LiveChat
 @param userInfo - notification body
 @param completionHandler - handler that should be executed after notification processed
 @return YES if push notification was handled by Agent.Ai SDK
 */
- (BOOL)didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;

/**
 @brief Handle push notification from UserCare and open LiveChat
 @param userInfo - notification body
 @return YES if push notification was handled by Agent.Ai SDK
 */
- (BOOL)didReceiveRemoteNotification:(NSDictionary *)userInfo;

/**
 @brief Handle push notification with custom actions from UserCare
 @param identifier - action identifier
 @param userInfo - notification body
 @param responseInfo - action response info
 @param completionHandler - handler that should be executed after action processed
 @return YES if push notification was handled by Agent.Ai SDK
 */
- (BOOL)handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo withResponseInfo:(NSDictionary *)responseInfo completionHandler:(void (^)())completionHandler;

/**
 @brief Handle push notification with custom actions from UserCare
 @param identifier - action identifier
 @param userInfo - notification body
 @param completionHandler - handler that should be executed after action processed
 @return YES if push notification was handled by Agent.Ai SDK
 */
- (BOOL)handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo completionHandler:(void (^)())completionHandler;

@end

/**
 @brief Describes push notification model.
 */
@interface AiPushMessage : NSObject

/**
 @brief Create and initialize AiPushMessage with aps data
 @param userInfo - received notification
 @return parsed model or nil (if parse error occur)
 */
+ (AiPushMessage *)messageWithDictionary:(NSDictionary *)userInfo;

@end

/**
 @brief Describes push action model.
 */
@interface AiPushInAppAction : NSObject

/**
 @brief Create and initialize AiPushInAppAction with provided data
 @param rawAction - NSDictionary representation of AiPushInAppAction
 @return parsed model
 */
+ (AiPushInAppAction *)actionWithDictionary:(NSDictionary *)rawAction;

/**
 @brief imageUrl - path to the image to be displayed to user
 */
@property (nonatomic, strong) NSString *imageUrl;

/**
 @brief key - unique identifier string
 */
@property (nonatomic, strong) NSString *key;

/**
 @brief identifier - push id
 */
@property (nonatomic, assign) NSInteger identifier;

/**
 @brief timestamp - timestamp of the date when action was sent
 */
@property (nonatomic, strong) NSString *timestamp;

/**
 @brief callbackName - Name of the callback function to be executed by developer
 */
@property (nonatomic, strong) NSString *callbackName;

/**
 @brief callbackData - Data of the callback function
 */
@property (nonatomic, strong) NSString *callbackData;

@end
