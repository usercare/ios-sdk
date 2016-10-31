#import <Foundation/Foundation.h>

@class UCCustomMessage;
@protocol UCLiveChatDelegate;

/**
 Class represents live chat client used for communication between user and agent.
 */
@interface UCLiveChatClient : NSObject

/**
 * Send new message to specified server.
 * You are able to use this function if only You are connected to the server.
 * Use connect function first.
 *
 * @param message A message to send.
 */
- (void)sendMessage:(UCCustomMessage *)message;

/**
 * Send notification to specific server, that the messages were read 
 * @param messages - incoming messages thad should be marked as read
 */
- (void)markMessagesAsRead: (NSArray *) messages;

/**
 * Initialises connection using SocketIO with parameters specified in shared instance of UCNetworkManager
 */
- (void)connect;

/**
 Closes the connection.
 */
- (void)disconnect;


/**
 Property for live chat delegate. Should implement UCLiveChatDelegate.
 */
@property (nonatomic, weak) id <UCLiveChatDelegate> delegate;

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

/*
 @brief Method called when live chat ready for a new conversation.
 */
- (void)readyForNewConversation;

@end
