/*
 COPYRIGHT 2016 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */

#import "AGSObject.h"
@class AGSSymbol;

/** @file AGSSymbolStyleSearchResult.h */ //Required for Globals API doc

/**  Results of search operations on a symbol style
 
 Instances of this class represent the results of [`AGSSymbolStyle searchSymbolsWithParameters:completion:`.] It contains the information related to name, tags, category, class type, and key associated to a symbol. It also returns the symbol.
 
 @see [`AGSSymbolStyle searchSymbolsWithParameters:completion:`]
 @since 100
 */

@interface AGSSymbolStyleSearchResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Category associated with the result symbol
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *category;

/** Key (unique identifier) associated with the result symbol
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *key;

/** Name associated with the result symbol
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Class associated with the result symbol
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *symbolClass;

/** Tags associated with the result symbol
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *tags;

/** Symbol of the search result
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSymbol *symbol;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

