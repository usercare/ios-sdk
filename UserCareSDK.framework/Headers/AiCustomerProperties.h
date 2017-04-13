//
//  AiCustomerProperties.h
//  UserCareSDK
//
//  Created by Kirill Kazachenko on 3/18/17.
//  Copyright © 2017 UserCare. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @brief Customer gender type. Default is Unspecified
 */
typedef NS_ENUM(NSInteger, AiCustomerGender) {
    /**
     Unspecified customer's gender type
     */
    Unspecified=0,
    /**
     Male customer's gender type
     */
    Male,
    /**
     Female customer's gender type
     */
    Female
};

/**
 @brief Customer properties model which includes basic fields and custom properties.
 */
@interface AiCustomerProperties : NSObject

/**
 Optional property. Will be seen in agent panel. Unless specified here SDK will prompt user to enter it upon opening live chat.
 */
@property (nonatomic, strong) NSString *firstName;

/**
 Optional property. Will be seen in agent panel. Unless specified here SDK will prompt user to enter it upon opening live chat.
 */
@property (nonatomic, strong) NSString *lastName;

/**
 Optional property. Will be seen in agent panel. Unless specified here SDK will prompt user to enter it upon opening live chat.
 */
@property (nonatomic, strong) NSString *email;

/**
 Optional property. Will be seen in agent panel. Int value;
 */
@property (nonatomic, strong) NSNumber *age;

/**
 Optional property. Will be seen in agent panel. Default - Unspecified.
 */
@property (nonatomic, assign) AiCustomerGender gender;

/**
 Optional property. Will be seen in agent panel.
 */
@property (nonatomic, strong) NSString *timezone;

/**
 Custom properties of the customer, specified by developer. Use alphabetical characters, numers and undercores only.
 */
@property (nonatomic, strong) NSDictionary *customProperties;

/**
 @brief Creates AiCustomerProperties using provided values.
 @param dictionary - NSDictionary with properties.
 @return parsed properties.
 */
+ (AiCustomerProperties *)propertiesWithDictionary:(NSDictionary *)dictionary;

/**
 @brief Converts AiCustomerProperties to NSDictionary.
 @return NSDictionary representation of AiCustomerProperties model.
 */
- (NSDictionary *)dictionaryRepresentation;

/**
 @brief Synchronizes customer properties with server.
 */
- (void)synchronize;

/**
 @brief Resets customer properties.
 */
- (void)reset;

@end
