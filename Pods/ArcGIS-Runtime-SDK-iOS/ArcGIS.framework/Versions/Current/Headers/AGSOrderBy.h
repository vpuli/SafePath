/*
 COPYRIGHT 2015 ESRI
 
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

/** @file AGSOrderBy.h */ //Required for Globals API doc

/**  An object that is used to specify the sort order of a query.
 
 Instances of this class represent information about the sort order of a query.
 
 @since 100
 */
@interface AGSOrderBy : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init;

-(instancetype)initWithFieldName:(NSString *)fieldName sortOrder:(AGSSortOrder)sortOrder;

+(instancetype)orderByWithFieldName:(NSString *)fieldName sortOrder:(AGSSortOrder)sortOrder;

#pragma mark -
#pragma mark properties

@property (nonatomic, copy, readwrite) NSString *fieldName;
@property (nonatomic, assign, readwrite) AGSSortOrder sortOrder;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
