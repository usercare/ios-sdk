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
 Method called when new messages comes.
 @param messages - Messages array
 */
- (void)receiveMessages:(NSArray *)messages;

/**
 Method called when history comes.
 @param messages - History messages array
 */
- (void)receiveHistory:(NSArray *)messages;

@end