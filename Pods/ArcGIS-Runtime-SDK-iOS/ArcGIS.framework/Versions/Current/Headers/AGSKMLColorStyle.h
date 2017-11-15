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

/** @file AGSKMLColorStyle.h */ //Required for Globals API doc

/**  A KML Color Style element
 
 An instance of this class represents a KML `<ColorStyle>` element which controls how a KML feature should be rendered.
 
 @since 100
 */
@interface AGSKMLColorStyle : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)KMLColorStyle;

#pragma mark -
#pragma mark properties

/** Color of the KML feature
 @since 100
 */
@property (nonatomic, strong, readonly) AGSColor *color;

/** Specifies how the [` color`] should be interpreted. A value of `AGSKMLColorModeRandom`  applies a random linear scale to the base color.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSKMLColorMode colorMode;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
