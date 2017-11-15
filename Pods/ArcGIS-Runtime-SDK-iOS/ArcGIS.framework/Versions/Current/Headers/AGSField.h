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
@class AGSDomain;

/** @file AGSField.h */ //Required for Globals API doc

/**  An object that represents information about a field.
 
 Instances of this class represent information about each field in a layer.
 
 @since 100
 */
@interface AGSField : AGSObject <AGSJSONSerializable>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

-(instancetype)initWithFieldType:(AGSFieldType)fieldType
                             name:(NSString *)name
                            alias:(NSString *)alias
                           length:(NSInteger)length
                           domain:(nullable AGSDomain *)domain
                         editable:(BOOL)editable
                        allowNull:(BOOL)allowNull;


+(instancetype)fieldWithFieldType:(AGSFieldType)fieldType
                             name:(NSString *)name
                            alias:(NSString *)alias
                           length:(NSInteger)length
                           domain:(nullable AGSDomain *)domain
                         editable:(BOOL)editable
                        allowNull:(BOOL)allowNull;

+(instancetype)dateFieldWithName:(NSString *)name alias:(NSString *)alias;
+(instancetype)doubleFieldWithName:(NSString *)name alias:(NSString *)alias;
+(instancetype)floatFieldWithName:(NSString *)name alias:(NSString *)alias;
+(instancetype)longIntFieldWithName:(NSString *)name alias:(NSString *)alias;
+(instancetype)shortIntFieldWithName:(NSString *)name alias:(NSString *)alias;
+(instancetype)textFieldWithName:(NSString *)name alias:(NSString *)alias length:(NSInteger)length;

#pragma mark -
#pragma mark properties

/** Name of the field.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Type of value in the field.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSFieldType type;

/** Alias name of the field. Alias name is usually more user friendly than the
 actual field name which may use underlying datasource naming conventions.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *alias;

/** The domain limiting values to a range or a set of coded values for the field.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSDomain *domain;

/** Indicates whether the field is editable.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isEditable) BOOL editable;

/** Indicates if the field can accept null values.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allowNull;

/** The field length.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger length;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
