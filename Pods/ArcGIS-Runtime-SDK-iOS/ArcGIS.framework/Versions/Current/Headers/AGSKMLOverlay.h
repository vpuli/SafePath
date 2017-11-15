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

#import "AGSKMLFeature.h"

/** @file AGSKMLOverlay.h */ //Required for Globals API doc

/**  A KML Overlay element
 
 An instance of this class represents a KML `<Overlay>` element which is the base type for image overlays drawn at a geographic location or screen location.
 
 @since 100
 */
@interface AGSKMLOverlay : AGSKMLFeature

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)KMLOverlay;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

