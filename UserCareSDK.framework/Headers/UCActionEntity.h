#import <Foundation/Foundation.h>

/**
 Model class containing action entity for UserCare SDK. Action entity represents any action message that comes into LiveChat.
 */
@interface UCActionEntity : NSObject

/**
 Title of action configured at server.
 */
@property (nonatomic, copy) NSString *actionTitle;

/**
 Url for action image.
 */
@property (nonatomic, copy) NSString *actionImageUrl;

@end
