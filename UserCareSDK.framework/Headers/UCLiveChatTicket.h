#import <Foundation/Foundation.h>

@interface UCLiveChatTicket : NSObject

@property (nonatomic, strong) NSNumber *identifier;
@property (nonatomic, strong) NSString *dateLastMessage;
@property (nonatomic, strong) NSString *dateOpened;
@property (nonatomic, strong) NSString *dateClosed;

@property (nonatomic, strong) NSString *assignee;
@property (nonatomic, strong) NSString *subject;
@property (nonatomic, strong) NSString *conversationId;
@property (nonatomic, strong) NSString *status;

@property (nonatomic, assign, readonly) BOOL isClosed;

@property (nonatomic, strong) NSNumber *bonuses;
@property (nonatomic, strong) NSNumber *messages;

@property (nonatomic, strong) NSString *transcriptURL __deprecated;
@property (nonatomic, strong) NSString *detailsURL __deprecated;

- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
