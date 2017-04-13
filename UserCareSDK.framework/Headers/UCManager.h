#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "UCPush.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

@class UCLiveChatClient;
@class UCActionEntity;
@class UCSettings;
@class UCLocalizedStringsDataSource;
@class UCCacheSettings;
@class UCLoggerSettings;
@class AiCustomerProperties;

/**
 Block used into startService method. Called when initialization is successful.
 */
typedef void(^UCInitializeSuccessfulBlock)(void);

/**
 Block used into startService method. Called when initialization is failed.
 */
typedef void(^UCInitializeFailedBlock)(NSError *error);

/**
 Block used into updateMyTickets method.
 */
typedef void(^UCMyTicketsUpdatedBlock)(NSArray *myTickets);

/**
 UserCare Manager delegate. 
 Every callback method will be executed at main queue.
 */
@protocol UCDelegate <NSObject>

/**
 Method called when any action received.
 @param action - action received in push notification.
 @param error - pointer to error, defined by user. Example: `*error = [NSError errorWithDomain:[NSString stringWithFormat: @"User defined error for callback: %@", action.callbackName] code:1 userInfo:nil];`
 @return YES - if action callback was handled. Please use AiPushInAppAction's property callbackName for identification.
 */
- (BOOL)handleAction:(AiPushInAppAction *)action executionError:(NSError **)error;

/**
 Method called when system message received.
 @param message - system message
 */
- (void)onSystemMessageReceived:(NSString *)message;

/**
 Method called when supporter message received.
 @param message - supporter message
 */
- (void)onSupporterMessageReceived:(NSString *)message;
/**
 Method called when UserCare SDK failed with error.
 @param error - received error
 */
- (void)usercareSdkFailedWithError:(NSError *)error;

/**
 Method called when UserCare SDK failed with error.
 @param error - received error
 @param statusCode - status code
 */
- (void)usercareSdkFailedWithError:(NSError *)error withStatusCode:(NSInteger)statusCode;

@optional
/**
 Method called when any action occured.
 @param actionEntity - action entity received in message
 */
- (void)onActionMessageReceived:(UCActionEntity *)actionEntity __attribute__ ((deprecated("Will not be executed anymore and removed in next version. Use handleAction:executionError: instead.")));

@end

/** 
 Model class containing initialization settings for UserCare SDK. Initialize instance of it, set required parameters and pass to startServiceWithSettings: completion:failure:
 */
@interface UCManagerSettings : NSObject

/** 
 Application identifier received from UserCare.
 */
@property (nonatomic, strong) NSString *appId;

/**
 Key for Events.
 */
@property (nonatomic, strong) NSString *eventsAPIKey;

/**
 AiCustomerProperties customer properties
 */
@property (nonatomic, strong) AiCustomerProperties *customerProperties;

/** 
 Customer identifier received from UserCare.
 */
@property (nonatomic, strong) NSString *customerId;

/**
 Optional property. Will be seen in agent panel. Unless specified here SDK will prompt user to enter it upon opening live chat.
 */
//@property (nonatomic, strong) NSString *customerFirstName;

/**
 Optional property. Will be seen in agent panel. Unless specified here SDK will prompt user to enter it upon opening live chat.
 */
//@property (nonatomic, strong) NSString *customerLastName;

/**
 Optional property. Will be seen in agent panel. Unless specified here SDK will prompt user to enter it upon opening live chat.
 */
//@property (nonatomic, strong) NSString *customerEmail;

/**
 Optional property. Will be used for definind caching policy. 
 */
@property (nonatomic, strong) UCCacheSettings *cacheSettings;

/**
 Optional property. Will be used for logging customizing.
 */
@property (nonatomic, strong) UCLoggerSettings *loggerSettings;

/**
 @brief Create UCManagerSettings instance with Application ID and Events API key taken from Info.plist file.  
 
 Example: Add this code at the end of Info.plist file (open as source code), before `</dict></plist>` nodes and replace [YOUR_APP_ID] and [YOUR_EVENTS_API_KEY] with correct values.
    
    <key>Agent.ai</key>
    <dict>
        <key>ApplicationID</key>
        <string>[YOUR_APP_ID]</string>
        <key>EventsAPIKey</key>
        <string>[YOUR_EVENTS_API_KEY]</string>
    </dict>
 
 @return UCManagerSettings or nil if there was unable to fetch config from Info.plist
 */
+ (_Nullable instancetype)settings;

/**
 @brief Custom settings for SDK initialization with specific Application ID and Events API key
 @param appId - Application ID
 @param eventsKey - Events API key
 @return UCManagerSettings
 */
+ (instancetype)settingsWithAppId:(NSString *)appId andEventsApiKey:(NSString *)eventsKey;

@end

/** 
 Main interface of UserCareSDK. Initialize it with startServiceWithSettings:completion:failure:
 */
@interface UCManager : NSObject

/**
  @brief Delegate for SDK callbacks.
 */
@property (nonatomic, weak) id <UCDelegate> delegate;

/** This value may be false if SDK is not yet initialized, if live chat is disabled on agent panel or if user is ineligible for it.
 Method presentLiveChatWithParent: will have no effect in such case.
  @brief A Boolean indicating whether the live chat feature is available currently for this user.
 */
@property (nonatomic, readonly) BOOL isLiveChatEnabled;

/** This value may be false if SDK is not yet initialized or if user is ineligible for vip lounge.
 Method presentVipLoungeWithParent: will have no effect in such case.
  @brief A Boolean indicating whether the vip lounge feature is available currently for this user.
 */
@property (nonatomic, readonly) BOOL isVIPLoungeEnabled;

/** This value may be false if SDK is not yet initialized or if FAQ section is not filled on server side.
 Method presentFAQWithParent: will have no effect in such case.
  @brief A Boolean indicating whether the FAQ feature is available currently for this user.
 */
@property (nonatomic, readonly) BOOL isFAQEnabled;

/** This value may be false if SDK is not yet initialized or if landing page is disabled on agent panel.
 Method presentLandingPageWithParent: will have no effect in such case.
  @brief A Boolean indicating whether the landing page is available currently for this user.
 */
@property (nonatomic, readonly) BOOL isLandingPageEnabled;

/** This value may be false if SDK is not yet initialized or if user has no tickets yet.
 Method presentMyTicketsWithParent: will have no effect in such case.
  @brief A Boolean indicating whether the my tickets feature is available currently for this user.
 */
@property (nonatomic, readonly) BOOL isMyTicketsEnabled;

/**
 @brief Settings used for customization. Includes all styles for different components.
 */
@property (nonatomic, strong) UCSettings *settings;

/**
 @brief Settings used for user properties.
 */
@property (nonatomic, strong, readonly) UCManagerSettings *_Nullable managerSettings;

/**
 @brief Localization Settings used for customization.
 */
@property (nonatomic, strong) UCLocalizedStringsDataSource *localizationSettings;

/**
    @brief Shows  SDK contact us screen if possible. Property isLiveChatEnabled indicates whether this function is available.
    @param parent - Your ViewController that will be used as parent to present SDK navigation stack.
 */
- (void)presentLiveChatWithParent:(UIViewController *)parent;

/**
 @brief Shows  SDK contact us screen if possible. Property isLiveChatEnabled indicates whether this function is available.
 @param params - Specific params related to LiveChat (for example message to be sent to Agent, once chat initiated)
 @param parent - Your ViewController that will be used as parent to present SDK navigation stack.
 */
- (void)presentLiveChatWithParams:(NSDictionary *_Nullable)params andParent:(UIViewController *)parent;

/**
    Shows  SDK FAQ if possible. Property isFAQEnabled indicates whether this function is available.
    @param parent - Your ViewController that will be used as parent to present SDK navigation stack.
 */
- (void)presentFAQWithParent:(UIViewController *)parent;

/**
    Shows  SDK's contact us screen if possible. Property isVipLoungeEnabled indicates whether this function is available.
    @param parent - Your ViewController that will be used as parent to present SDK navigation stack.
 */
- (void)presentVipLoungeWithParent:(UIViewController *)parent;

/**
    Shows  SDK's landing page if possible. Property isLandingPageEnabled indicates whether this function is available.
    @param parent - Your ViewController that will be used as parent to present SDK navigation stack.
 */
- (void)presentLandingPageWithParent:(UIViewController *)parent;

/**
    Shows  SDK's landing page if possible. Property isMyTicketsEnabled indicates whether this function is available.
    @param parent - Your ViewController that will be used as parent to present SDK navigation stack.
 */
- (void)presentMyTicketsWithParent:(UIViewController *)parent;

/**
 @brief Initialize UC SDK.
 @param settings - your Manager Settings. Create them and customize.
 */
- (void)initWithSettings:(UCManagerSettings *)settings;

/**
 @return pointer to instance of UC
 */
+ (UCManager *)sharedInstance;

/**
    @brief Starts service. Immediately triggers settings and update requests to server
    @param settings - your Manager Settings. Create them and customize.
    @param completionBlock - completion block called after successful init.
    @param failureBlock - failure block called if something goes wrong during initialization.
    @return pointer to instance of UC

 */
+ (UCManager *)startServiceWithSettings:(UCManagerSettings *)settings completion:(UCInitializeSuccessfulBlock)completionBlock failure:(UCInitializeFailedBlock)failureBlock;

+ (void)startServiceWithCompletion:(UCInitializeSuccessfulBlock)completionBlock
                           failure:(UCInitializeFailedBlock)failureBlock;


/**
 @brief Receives new tickets from server. Can be called if startService method was called before.
 @param completionBlock - completion block called after my tickets update.
 
 */
+ (void)updateMyTicketsWithCompletion:(UCMyTicketsUpdatedBlock)completionBlock;

/**
* Creates VIP lounge button. Can be called anytime, returns invisible button if VIP lounge is unavailable. Visibility will be updated automatically.
    @return pointer to VIP lounge button

*/
- (UIButton *)createVIPLoungeButton;

/**
Creates live chat button. Can be called anytime, returns invisible button if live chat is unavailable. Visibility will be updated automatically.
    @return pointer to live chat button

*/
- (UIButton *)createLiveChatButton;

/**
  Creates faq button. Can be called anytime, returns invisible button if live faq is unavailable. Visibility will be updated automatically.
    @return pointer to faq button
 
 */
- (UIButton *)createFAQButton;

/**
  Creates landingPage button. Can be called anytime, returns invisible button if live faq is unavailable. Visibility will be updated automatically.
    @return pointer to faq button

 */
- (UIButton *)createLandingPageButton;

/**
  Creates my tickets button. Can be called anytime, returns invisible button if live faq is unavailable. Visibility will be updated automatically.
    @return pointer to faq button
 */

- (UIButton *)createMyTicketsButton;

/**

Receives entry point for chat interface.

    @return pointer to live chat interface

*/
- (UCLiveChatClient *)getChatClient;

#pragma mark - Tags

/**
 @brief Identify user to specific queue by tag
 @param tag - String tag name
 */
+ (void)setTag:(NSString*)tag;

/**
 @brief Identify user to specific queue by tags
 @param tags - NSArray of NSString tags
 */
+ (void)setTags:(NSArray*)tags;

/**
 @return array of tags applied to user or nil
 */
+ (NSArray*)getTags;

/**
 @brief Clears cache for all SDK requests and responses
 */
+ (void)clearCache;

#pragma mark - UCPush

/**
 @brief Push notifications manager
 @return insance of UCPush
 */
+ (UCPush *)push;

#pragma mark - Deeplinks

/**
 Opens AgentAi SDK screens and resources byprovided url.
 @param url - NSURL which came from the app or outside (add to app delegate's override).
 @return YES - if url was processed by AgentAi SDK
 */
+ (BOOL)openUrl:(NSURL *)url;

#pragma mark - Device ID

/**
 Set device identifier that developer would like to use (such as IDFA or calculated) instead of default one (IDFV).
 Max length should not exceed 42 chars. 
 @param customDeviceId - custom identifier or nil to use default IDFV
 */
+ (void)setDeviceId: (NSString *)customDeviceId;

/**
 * Returns device identifier. Default value is identifier for vendor (IDFV), can be set custom identifier via UCManager::setDeviceId
 @return IDFV or custom device identifier
 */
+ (NSString *)deviceId;



#pragma clang diagnostic pop

@end
