#import "UCMessage.h"

extern NSString * const kUCSenderIdSelf;
extern NSString * const kUCFAQLinkCaption;

/**
 UCMessageType. Represents the different types of a message.
 */
typedef NS_ENUM(NSUInteger, UCMessageType) {
    /**
     UCMessageTypeSystem Messages received on state change i.e. the user has open live chat.
     */
    UCMessageTypeSystem = 0,
    /**
     UCMessageTypeRegular User or agent chat message.
     */
    UCMessageTypeRegular,
    /**
     UCMessageTypeFAQLink Message cotain link what could be opened.
     */
    UCMessageTypeFAQLink,
    /**
     UCMessageTypeAction Message when the User receive a bonuce.
     */
    UCMessageTypeAction,
};

/**
 * Class represents model object is used for storing messaging information in Live chat.
 */
@interface UCCustomMessage : UCMessage

/**
 Defines type of a message. Different types described above.
 */
@property (nonatomic, assign) UCMessageType messageType;

/**
 URL of the image pending to be displayed on a message.
 */
@property (nonatomic, copy) NSString *imageURL;

/**
 Property defines whether the message is Greeting i.e. should be displayed centred on the top.
 */
@property (nonatomic, assign) BOOL isGreetingMessage;

/**
 @brief Mhetod is used for creating instance of the message from parsed dictionary.
 @param dictionary Parsed dictionary from JSON object.
 @return instance of a custom message.
 */
+ (UCCustomMessage *)messageWithDictionary:(NSDictionary *)dictionary;

@end
