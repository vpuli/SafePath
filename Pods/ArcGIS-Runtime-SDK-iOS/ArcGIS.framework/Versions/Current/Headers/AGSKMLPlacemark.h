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

@class AGSEnvelope;
@class AGSKMLGeometry;

/** @file AGSKMLPlacemark.h */ //Required for Globals API doc

/**  A KML Placemark element
 
 An instance of this class represents a KML `<Placemark>` element which is a feature with associated Geometry.
 
 @since 100
 */
@interface AGSKMLPlacemark : AGSKMLFeature

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The type of geometry associated with this placemark.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSKMLGeometryType geometryType;

/** Geometry specifying the geographic location and shape of this placemark.
 If the placemark is based on multiple geometries, this will contain only the first point geometry, or if none exists, the center of geographic extent of all the geometries.
 
 @see [` geometries`] to get access to each individual geometry when the placemark is based on multiple geometries.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSGeometry *geometry;

/** The geometries associated with this placemark.
 @since 100
 */
@property (nonatomic, strong, readonly) NSArray<AGSKMLGeometry *> *geometries;

/** The geographic extent of this placemark.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSEnvelope *geometryExtent;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

