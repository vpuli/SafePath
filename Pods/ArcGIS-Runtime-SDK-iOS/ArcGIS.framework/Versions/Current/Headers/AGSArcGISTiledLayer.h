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

#import "AGSImageAdjustmentLayer.h"
#import "AGSImageTiledLayer.h"

@class AGSCredential;
@class AGSArcGISMapServiceInfo;
@class AGSFuture;
@class AGSTileCache;
@class AGSArcGISTiledSublayer;
@class AGSPortalItem;
@protocol AGSRemoteResource;

/** @file AGSArcGISTiledLayer.h */ //Required for Globals API doc

/**  A layer based on a tiled ArcGIS Map service.
 
 An instance of this class allows you to display maps from a tiled ArcGIS Map service, or a local Tile Package (.tpk file). It uses a cache of pre-generated tiles to assemble a map instead of
 dynamically generating map images.
 
 
 @see AGSArcGISMapImageLayer for layer that can display maps from dynamic ArcGIS Map services.
 @since 100
 */


@interface AGSArcGISTiledLayer : AGSImageTiledLayer <AGSRemoteResource>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this layer with a URL of a tiled ArcGIS Map service
 @param url URL to a tiled ArcGIS Map service.
 @return A new tiled layer object.
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize this layer with a tile cache representing a local Tile Package (.tpk file)
 @param tileCache representing a local Tile Package (.tpk file)
 @return A new tiled layer object
 @since 100
 */
-(instancetype)initWithTileCache:(AGSTileCache*)tileCache;

/** Initialize this layer with an item on ArcGIS Online or ArcGIS Portal representing a tiled ArcGIS Map service.
 @param item representing a tiled ArcGIS Map service.
 @return A new tiled layer object
 @since 100
 */
-(instancetype)initWithItem:(AGSItem*)item;

/** Initialize this layer with an item on ArcGIS Online or ArcGIS Portal representing a tiled ArcGIS Map service.
 @param item representing a tiled ArcGIS Map service.
 @return A new tiled layer object
 @since 100
 */
+(instancetype)ArcGISTiledLayerWithItem:(AGSItem*)item;

/** Initialize this layer with a URL of a tiled ArcGIS Map service
 @param url URL to a cached ArcGIS Map service.
 @return A new tiled layer object.
 @since 100
 */
+(instancetype)ArcGISTiledLayerWithURL:(NSURL*)URL;

/** Initialize this layer with a tile cache representing a local Tile Package (.tpk file)
 @param tileCache representing a local Tile Package (.tpk file)
 @return A new tiled layer object
 @since 100
 */
+(instancetype)ArcGISTiledLayerWithTileCache:(AGSTileCache*)tileCache;

#pragma mark -
#pragma mark properties

/** Information about this layer's map service.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSArcGISMapServiceInfo *mapServiceInfo;

/** The tile cache being used by the layer, if any
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSTileCache *tileCache;

/** Sub-layers of this layer
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSArcGISTiledSublayer*> *tiledSublayers;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
