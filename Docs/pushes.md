# Push notifications

Update your `<UIApplicationDelegate>` class import:  

	- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
	{
	    ...
        
	   [self registerAppForNotifications];
    
		return YES;
	}

This example contains iOS 10 beta support, if you are using 9.x SDK then focus on `legacyRegisterAppForNotifications` method:

	#import <UserNotifications/UserNotifications.h>

	...

	- (void)registerAppForNotifications
	{
		if([[NSProcessInfo processInfo] operatingSystemVersion].majorVersion >= 10) {
			[[UNUserNotificationCenter currentNotificationCenter] requestAuthorizationWithOptions:(UNAuthorizationOptionSound | UNAuthorizationOptionAlert | UNAuthorizationOptionBadge) completionHandler:^(BOOL granted, NSError * _Nullable error) {
				if (granted) {
					[[UIApplication sharedApplication] registerForRemoteNotifications];
				}            
			}];
		} else {
			[self legacyRegisterAppForNotifications];
		}
	}
	
Register for push notifications for iOS 8-9:

	- (void)legacyRegisterAppForNotifications
	{
		if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)])
		{
			UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge) categories:nil];
			[[UIApplication sharedApplication] registerUserNotificationSettings:settings];
			[[UIApplication sharedApplication] registerForRemoteNotifications];
		}
		else
		{
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wdeprecated"
			[[UIApplication sharedApplication] registerForRemoteNotificationTypes:UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeSound];
	#pragma clang diagnostic pop
		}
	}

Add registration and notification callbacks:

	- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
		[[UCManager push] didReceiveRemoteNotification:userInfo
                            fetchCompletionHandler:completionHandler];
	}

	- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
	{
		[[UCManager push] didReceiveRemoteNotification:userInfo];
	}

	- (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo completionHandler:(void (^)())completionHandler
	{   
		[[UCManager push] handleActionWithIdentifier:identifier
                           forRemoteNotification:userInfo
                               completionHandler:completionHandler];
	}

	- (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo withResponseInfo:(NSDictionary *)responseInfo completionHandler:(void (^)())completionHandler
	{
		[[UCManager push] handleActionWithIdentifier:identifier
                           forRemoteNotification:userInfo
                                withResponseInfo:responseInfo
                               completionHandler:completionHandler];
	}

	- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
	{
		[[UCManager push] registeredForPushNotifications:deviceToken];
	}