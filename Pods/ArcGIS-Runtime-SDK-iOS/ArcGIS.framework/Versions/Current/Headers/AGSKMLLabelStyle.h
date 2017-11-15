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

#import "AGSKMLColorStyle.h"

/** @file AGSKMLLabelStyle.h */ //Required for Globals API doc

/**  A KML Label Style element
 
 An instance of this class represents a KML `<LabelStyle>` element which controls how a KML feature is labelled on the map.
 
 @since 100
 */
@interface AGSKMLLabelStyle : AGSKMLColorStyle

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Specifies how to resize the label.
 @since 100
 */
@property (nonatomic, assign, readonly) double scale;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

