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

#import "AGSKMLOverlay.h"

@class AGSEnvelope;

/** @file AGSKMLGroundOverlay.h */ //Required for Globals API doc

/**  A KML Ground Overlay element
 
 An instance of this class represents a KML `<GroundOverlay>` element which draws an image overlay at a particular geographic location.
 
 @since 100
 */
@interface AGSKMLGroundOverlay : AGSKMLOverlay

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Specifies the geographic location for the ground overlay.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSGeometry *geometry;

/** Specifies how the altitude contained in the [` geometry`] z-value is interpreted.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSKMLAltitudeMode altitudeMode;

/** The geographic extent of the overlay.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSEnvelope *overlayExtent;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
