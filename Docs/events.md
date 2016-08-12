# Events

After you have initialized SDK with your API key it will automatically track user sessions. Aside from that you may log any of your events using custom event feature. This may be useful when tracking user's progress in order to provide better feedback. You can use any event name and add any data structure that may be encoded to JSON.  

### Custom events

	[[UCEventLogger sharedInstance] sendEvent:@"your_event" withUserData: @{@"param1": @"val1",@"param2": @"val2"}];
	
### Purchases

	// check if purchase was successful or not
	NSString *eventType = isSuccessful ? kUCEventPurchaseSuccess : kUCEventPurchaseFailed;
	
	UCEvent *event = [[UCEvent alloc] initWithEventType:eventType];
	event.title = @"25 Coins";
	event.price = @(4.99);
	event.priceCurrency = @"USD";
	event.productId = @"25coins";
	event.transactionId = [[NSUUID UUID] UUIDString];
	event.transactionTime = [UCUtils currentFormattedTimeForEvents];
    
	[[UCEventLogger sharedInstance] sendEventWithEvent:event];
