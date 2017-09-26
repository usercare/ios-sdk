
#import <UIKit/UIKit.h>
#import "UCMessage.h"
#import "AiMessageBody.h"
#import "AiQuickResponseMessage.h"
#import "AiCardDeckMessage.h"

extern NSString *const kAIRoleCustomer;
extern NSString *const kAIRoleAgent;
extern NSString *const kAIRoleSystem;

extern NSString * const kAIMessageTypeQR;
extern NSString * const kAIMessageTypeImage;
extern NSString * const kAIMessageTypeText;
extern NSString * const kAIMessageTypeCardDeck;

/**
 UCMessageType. Represents the different types of a message.
 */
typedef NS_ENUM(NSUInteger, UCMessageType) {
    /**
     AIMessageTypeSystem Messages received on state change i.e. the user has open live chat.
     */
    AiMessageTypeSystem = 0,
    /**
     AIMessageTypeRegular User or agent chat message.
     */
    AiMessageTypeRegular,
    /**
     AIMessageTypeFAQLink Message cotain link what could be opened.
     */
    AiMessageTypeFAQLink,
    /**
     AIMessageTypeImage image message.
     */
    AiMessageTypeImage,
    /**
     AiMessageTypeCardDeck Card Deck message.
     */
    AiMessageTypeCardDeck,
    /**
     AiMessageTypeCardDeckReply user's reply to card deck button.
     */
    AiMessageTypeCardDeckReply,
    /**
     AiMessageTypeQuickResponse quick response message.
     */
    AiMessageTypeQuickResponse,
    /**
     AiMessageTypeQuickReply user's reply to quick response.
     */
    AiMessageTypeQuickReply,
    /**
     AIMessageTypeText text message.
     */
    AiMessageTypeText
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

@property (nonatomic, copy) UIImage *localPreview;

@property (nonatomic, assign) BOOL pending;

/**
 ID of the uploaded file to CDN.
 */
@property (nonatomic, copy) NSString *fileID;

/**
 QuickResponse data
 */
@property (nonatomic, strong) AiMessageBody *body;

/**
 Property defines whether the message is Greeting i.e. should be displayed centred on the top.
 */
@property (nonatomic, assign) BOOL isGreetingMessage;

/**
 Property defines whether the message was read or not.
 */
@property (nonatomic, assign) BOOL isRead;

@property (nonatomic, assign) BOOL timeHidden;

@property (nonatomic, strong) AiQuickReply *quickReply;

@property (nonatomic, strong) AiCardButton *cardButton;

/**
 @brief Mhetod is used for creating instance of the message from parsed dictionary.
 @param dictionary Parsed dictionary from JSON object.
 @return instance of a custom message.
 */
+ (UCCustomMessage *)messageWithDictionary:(NSDictionary *)dictionary;

- (BOOL)isOutgoing;

- (BOOL)isSystem;

/**
 @return NSDictionary representation of message.
 */
- (NSDictionary *)asDictionary;

@end
