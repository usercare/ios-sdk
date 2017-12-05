#import <Foundation/Foundation.h>

extern NSString * const kUCItemsKey;

@class UCCustomMessage;
@class UCLiveChatClient;
@protocol UCLiveChatDelegate;

/**
 Class represents live chat client used for communication between user and agent.
 */
@interface UCLiveChatClient : NSObject

/**
 * UCLiveChatDelegate delegate
 */
@property (nonatomic, weak) id<UCLiveChatDelegate> delegate;

/**
 * Send new message to specified server.
 * You are able to use this function if only You are connected to the server.
 * Use connect function first.
 *
 * @param message - A message to send.
 */
- (void)sendMessage:(UCCustomMessage *)message;

/**
 * Send notification to specific server, that the messages were read 
 * @param messages - incoming messages thad should be marked as read
 */
- (void)markMessagesAsRead:(NSArray *)messages;

/**
 @brief Initialize connection. 
 */
- (void)connect;

/**
 @brief Closes the connection.
 */
- (void)disconnect;

@end

/**
 Live Chat Client Delegate.
 */
@protocol UCLiveChatDelegate <NSObject>

/**
 @brief Method called when live chat conected to socket.
 @param client - UCLiveChatClient instance.
 */
- (void)connectedToLiveChat:(UCLiveChatClient *)client;

/**
 @brief Method called when live chat disconnected from socket.
 @param client - UCLiveChatClient instance.
*/
- (void)disconnectedFromLiveChat:(UCLiveChatClient *)client;

/**
 @brief Method called when new messages comes.
 @param messages - Messages array
 */
- (void)receiveMessages:(NSArray *)messages;

/**
 @brief Method called when history comes.
 @param messages - History messages array
 */
- (void)receiveHistory:(NSArray *)messages;

/**
 @brief Method called when message delivered.
 @param message - Delivered message. Please refer to UCMessage.localID property to determine message identifier.
 */
- (void)messageDelivered:(UCCustomMessage *)message;

/**
 @brief Method called when message was not delivered.
 @param message - Not delivered message. Please refer to UCMessage.localID property to determine message identifier.
 */
- (void)messageNotDelivered:(UCCustomMessage *)message;

/*
 @brief Method called when live chat ready for a new conversation.
 */
- (void)readyForNewConversation;

@end
