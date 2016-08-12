# Initialize SDK

In your view controller import header:
	
	#import <UserCareSDK/UserCareSDK.h>

Set AppID and Events API key (they could be found under [My Apps](https://my.usercare.com/apps/) section):

	static NSString *const kUCAppID = @"input_app_id";
	static NSString *const kUCEventsApiKey = @"input_API_key";
	
When view loaded, initialize SDK with credentials:

	- (void)viewDidLoad
	{
    	[super viewDidLoad];
    	[self initializeSDK];
    }

	- (void)initializeSDK
	{
		NSData *pushToken = [UCManager push].pushToken;
    
		UCManagerSettings *settings = [UCManagerSettings settingsWithAppId:kUCAppID andEventsApiKey:kUCEventsApiKey];
		settings.pushNotificationToken = pushToken;
    
		[UCManager startServiceWithSettings:settings completion:^{
			...
		} failure:^(NSError *error) {
			NSLog(@"Failed to initialize SDK: %@", [error localizedDescription]);
		}];
	}

Once SDK initialized, you can trigger your UI controlls visibility or create UserCare buttons. For more details navigate to [advanced setup](advanced.md).