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

@class AGSItem;

#import "AGSElevationSource.h"
#import "AGSRemoteResource.h"

/** @file AGSArcGISTiledElevationSource.h */ //Required for Globals API doc

/**  An elevation source based on tiled elevation data
 
 Instances of this class represent an elevation source based on a tiled ArcGIS Image Service containing elevation data. It can be used in [`AGSSurface elevationSources`] to specify the surface of a scene.
 
 @since 100
 @see [`AGSScene baseSurface`] to specify the surface of a scene
 @ios
 @beta
 @ingroup beta
 @endios
 
 */
@interface AGSArcGISTiledElevationSource : AGSElevationSource <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a tiled elevation source based on the given elevation service
 @param URL to a tiled ArcGIS Image service containing elevation data
 @return A new tiled elevation source
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize a tiled elevation source based on an item on ArcGIS Online or ArcGIS Portal representing an elevation service.
 @param item representing an elevation service.
 @return A new tiled elevation source
 @since 100
 */
-(instancetype)initWithItem:(AGSItem*)item;

+(instancetype)ArcGISTiledElevationSource;

/** Initialize a tiled elevation source based on the given elevation service
 @param URL to a tiled elevation service
 @return A new tiled elevation source
 @since 100
 */
+(instancetype)ArcGISTiledElevationSourceWithURL:(NSURL*)URL;

/** Initialize a tiled elevation source based on an item on ArcGIS Online or ArcGIS Portal representing an elevation service.
 @param item representing an elevation service.
 @return A new tiled elevation source
 @since 100
 */
+(instancetype)ArcGISTiledElevationSourceWithItem:(AGSItem*)item;

#pragma mark -
#pragma mark properties

/** The item being used by the elevation source, if any.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSItem *item;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
