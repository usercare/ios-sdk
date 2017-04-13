#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UCUtils : NSObject

+ (NSString *)convertPushTokenToString:(NSData *)data;
+ (bool)isNetworkAvailable;

+ (void)customizeBackgroundView:(UIImageView *)view withImage:(UIImage *)image mode:(NSString *)mode;
+ (UIColor *)colorFromHexString:(NSString *)hexString;

//time
+ (NSString *)currentFormattedTimeForEvents;
+ (NSString *)currentFormattedTime;
+ (NSString *)formattedShortTimeForChatWithDate:(NSDate *)date;
+ (NSString *)formattedDateTimeForNewMessagesInChatWithDate:(NSDate *)date;
+ (NSString *)formattedTimeWithDate:(NSDate *)date;
+ (NSString *)formattedTimeForChatWithDate:(NSDate *)date;
+ (NSDate *)dateFromString:(NSString *)string;
+ (NSString *)formattedTicketDateWithDateString:(NSString *)initialDateString;

+ (NSString *)stringWithLocalizedString:(NSString *)localizedString defaultString:(NSString *)defaultString;

+ (void)customizeTableView:(UITableView *)tableView backgroundWithColor:(UIColor *)color image:(NSString *)image repeat:(NSString *)repeat;

+ (BOOL)validateEmail:(NSString *)email;

+ (CGSize)sizeForText:(NSAttributedString *)text withFont:(UIFont *)font within:(CGFloat)maxWidth;

+ (NSAttributedString *)attributedText:(NSString *)text;

@end
