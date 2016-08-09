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
 */
- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;

/**
 @brief Handle push notification from UserCare and open LiveChat
 @param userInfo - notification body
 */
- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo;

/**
 @brief Handle push notification with custom actions from UserCare
 @param identifier - action identifier
 @param userInfo - notification body
 @param responseInfo - action response info
 @param completionHandler - handler that should be executed after action processed
 */
- (void)handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo withResponseInfo:(NSDictionary *)responseInfo completionHandler:(void (^)())completionHandler;

/**
 @brief Handle push notification with custom actions from UserCare
 @param identifier - action identifier
 @param userInfo - notification body
 @param completionHandler - handler that should be executed after action processed
 */
- (void)handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo completionHandler:(void (^)())completionHandler;

@end
