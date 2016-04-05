#import <Foundation/Foundation.h>

/**
 Enum used for Cache Policy setup.
 */
typedef NS_ENUM(NSUInteger, UCCachePolicy)
{
    /**
     This type will disable cache for all requests.
     */
    UCCachePolicyNone,
    /**
     This type will cache top FAQ questions.
     */
    UCCachePolicyTop,
    /**
     This type will cache all FAQ questions.
     */
    UCCachePolicyAll
};

/**
 Protocol used for Cache Settings.
 */
@protocol UCCachingProtocol <NSObject>

/**
 Defines wheter SDK will use cache.
 */
@property (nonatomic, assign) BOOL isCacheEnabled;

/**
 Cache policy determines pre-caching policy for FAQs.
 */
@property (nonatomic, assign) UCCachePolicy cachePolicy;

/**
 Maximum amount of disk space will be used for storing cached files in bytes.
 2^29 bytes = 512 megabytes, for example (By default).
 */
@property (nonatomic, assign) NSUInteger cacheSize;

@end

/**
 Class represents settings used for caching.
 */
@interface UCCacheSettings : NSObject <UCCachingProtocol>

/**
 Returns instance of UCCacheSettings.
 @param policy - policy used for caching. By default UCCachePolicyTop is used.
 */
+ (instancetype)settingsWithCachePolicy:(UCCachePolicy)policy;

@end


