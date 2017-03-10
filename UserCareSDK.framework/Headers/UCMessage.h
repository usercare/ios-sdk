//
//  Created by Jesse Squires
//  http://www.jessesquires.com
//
//
//  Documentation
//  http://cocoadocs.org/docsets/UCMessagesViewController
//
//
//  GitHub
//  https://github.com/jessesquires/UCMessagesViewController
//
//
//  License
//  Copyright (c) 2014 Jesse Squires
//  Released under an MIT license: http://opensource.org/licenses/MIT
//

#import <Foundation/Foundation.h>

/**
*  The `UCMessage` class is a concrete class for message model objects that represents a single user message.
*  The message can be a text message or media message, depending on how it is initialized.
*  It contains the senderId, senderDisplayName, and the date that the message was sent. If initialized as a media message it also contains a media attachment,
*  otherwise it contains the message text.
*/
@interface UCMessage : NSObject <NSCoding, NSCopying>

/**
* Local message identifier. Used to determine delivered message.
*/
@property (nonatomic, strong) NSString *localID;

/**
*  Returns array of roles, which belong message.
*/
@property (copy, nonatomic, readonly) NSArray *roles;

/**
*  Returns the display name for the user who sent the message. This value does not have to be unique.
*/
@property (copy, nonatomic, readonly) NSString *senderDisplayName;

/**
*  Returns the date that the message was sent.
*/
@property (copy, nonatomic, readonly) NSDate *date;

/**
*  Returns a boolean value specifying whether or not the message contains media.
*  If `NO`, the message contains text. If `YES`, the message contains media.
*  The value of this property depends on how the object was initialized.
*/
@property (assign, nonatomic, readonly) BOOL isMediaMessage;

/**
*  Returns the body text of the message, or `nil` if the message is a media message.
*  That is, if `isMediaMessage` is equal to `YES` then this value will be `nil`.
*/
@property (copy, nonatomic) NSString *text;

@property (strong, nonatomic) NSNumber *messageId;

#pragma mark - Initialization

/**
*  Initializes and returns a message object having the given senderId, displayName, text,
*  and current system date.
*
*  @param roles    Message roles (can be one of Customer, Agent, System).
*  @param displayName The display name for the user who sent the message. This value must not be `nil`.
*  @param text        The body text of the message. This value must not be `nil`.
*
*  @discussion Initializing a `UCMessage` with this method will set `isMediaMessage` to `NO`.
*
*  @return An initialized `UCMessage` object if successful, `nil` otherwise.
*/
+ (instancetype)messageWithRoles:(NSArray *)roles
                        displayName:(NSString *)displayName
                               text:(NSString *)text;

/**
*  Initializes and returns a message object having the given senderId, senderDisplayName, date, and text.
*
*  @param roles             Collection of sender's roles.
*  @param senderDisplayName The display name for the user who sent the message. This value must not be `nil`.
*  @param date              The date that the message was sent. This value must not be `nil`.
*  @param text              The body text of the message. This value must not be `nil`.
*
*  @discussion Initializing a `UCMessage` with this method will set `isMediaMessage` to `NO`.
*
*  @return An initialized `UCMessage` object if successful, `nil` otherwise.
*/
- (instancetype)initWithRoles:(NSArray *)roles
               senderDisplayName:(NSString *)senderDisplayName
                            date:(NSDate *)date
                            text:(NSString *)text;

@end
