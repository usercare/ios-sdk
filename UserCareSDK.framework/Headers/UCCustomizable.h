#ifndef UCCustomizable_h
#define UCCustomizable_h

/**
 * @discussion Abstract protocol for style.
 * Each customizable UI object could be updated with object, that comfirm this protocol.
 */
@protocol UCStyle <NSObject>

/**
 @brief Used for acheiving UCStyle object from dictionary.
 @param dictionary - A dictionary, parsed from JSON object.
 @return Instance of a UCStyle object.
 */
+ (id<UCStyle>)styleWithDictionary:(NSDictionary *)dictionary;

/**
 @brief Used for acheiving UCStyle object from dictionary.
 @param dictionary - A dictionary, parsed from JSON object.
 @return Instance of a UCStyle object.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

/**
 * @discussion An abstract interface for designable items.
 * Subclasses must override -updateWithStyle: method
 */
@protocol UCCustomizable <NSObject>

/**
 @brief Called for updating UI elements with style.
 @param style - abstract item must confirm <UCStyle> protocol
 */
- (void)updateWithStyle:(id<UCStyle>)style;

@end

#endif /* UCCustomizable_h */
