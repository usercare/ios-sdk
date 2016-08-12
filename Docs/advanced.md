# Advanced Setup

### Buttons

Once your SDK initialized, within completeion block you can create and place UserCare buttons to your layout:

	UCManager *ucManager = [UCManager sharedInstance];

	if (ucManager.isLiveChatEnabled) {
		UIButton *button = [ucManager createLiveChatButton];
		...
	}
	
	if (ucManager.isFAQEnabled) {
		UIButton *button = [ucManager createFAQButton];
		...
	}

	if (ucManager.isLandingPageEnabled) {
		UIButton *button = [ucManager createLandingPageButton];
		...
	}

	if (ucManager.isMyTicketsEnabled) {
		UIButton *button = [ucManager createMyTicketsButton];
		...
	}
	
### Open UserCare screens directly

Create button with your custom style and add callback:

	- (IBAction)help:(id)sender
	{
		UCManager *ucManager = [UCManager sharedInstance];
		if (ucManager.isLandingPageEnabled) {
			[[userCareInstance presentLandingPageWithParent:self];
		}
		
		// same could be used for presenting another screens:
		// [[userCareInstance presentLiveChatWithParent:self];
		// [[userCareInstance presentFAQWithParent:self];
		// [[userCareInstance presentMyTicketsWithParent:self];
		// but always check if such screen enabled
	}

### Override UI style properties

UCManager contains UCSettings model, which contains styling properties:

	UCFAQStyle *FAQStyle;
	UCLiveChatStyle *liveChatStyle;
	UCTicketStyle *ticketStyle;
	
Once SDK initialized, you can override settings in completion block:

	UCManager *ucManager = [UCManager sharedInstance];
	UCFAQStyle *faqStyle = ucManager.settings.FAQStyle;

	faqStyle.faqButtonStyle.textStyle.textColor = [UIColor redColor];

For detailed description about styling properties, please check [docs](https://docs.usercare.com/sdk/ios/latest/) page.