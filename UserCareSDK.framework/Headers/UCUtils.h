#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UCUtils : NSObject

+ (NSString *)convertPushTokenToString:(NSData *)data;
+ (bool)isNetworkAvailable;

+ (void)customizeBackgroundView:(UIImageView *)view withImage:(UIImage *)image mode:(NSString *)mode;
+ (UIColor *)colorFromHexString:(NSString *)hexString;
+ (NSString *)colorToHexString:(UIColor *)color;

//time
+ (NSDateFormatter *)localizedFormatter;
+ (NSString *)currentFormattedTimeForEvents;
+ (NSString *)currentFormattedTime;
+ (NSString *)formattedShortTimeForChatWithDate:(NSDate *)date;
+ (NSString *)formattedDateTimeForNewMessagesInChatWithDate:(NSDate *)date;
+ (NSString *)formattedTimeWithDate:(NSDate *)date;
+ (NSDate *)dateFromString:(NSString *)string;
+ (NSString *)formattedTicketDateWithDateString:(NSString *)initialDateString;
+ (NSString *)formattedDate:(NSDate *)date withFormat:(NSString *)format;
+ (BOOL)isToday:(NSDate *)date;

+ (NSString *)stringWithLocalizedString:(NSString *)localizedString defaultString:(NSString *)defaultString;

+ (void)customizeTableView:(UITableView *)tableView backgroundWithColor:(UIColor *)color image:(NSString *)image repeat:(NSString *)repeat;

+ (BOOL)validateEmail:(NSString *)email;

+ (CGSize)sizeForText:(NSAttributedString *)text withFont:(UIFont *)font within:(CGFloat)maxWidth;

+ (NSAttributedString *)attributedText:(NSString *)text;

+ (NSString *)sanitizeString:(NSString *)string;

+ (nullable id)jsonFromString:(NSString * _Nullable)json error:(NSError **)error;

+ (nullable id)jsonFromData:(NSData * _Nullable)data error:(NSError **)error;

+ (void)applyTitle:(UIViewController * _Nonnull)controller title:(NSString *)title;

+ (void)shortenBackTitle:(UINavigationItem * _Nullable)navigationItem;

+ (void)hideBackTitle:(UINavigationItem * _Nullable)navigationItem;

+ (NSArray<NSString *> * _Nonnull)allPropertyNames: (Class _Nonnull)clazz;

@end
