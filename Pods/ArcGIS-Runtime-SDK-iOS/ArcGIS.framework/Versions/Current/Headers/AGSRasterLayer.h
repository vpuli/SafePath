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

@class AGSRasterRenderer;
@class AGSRaster;

#import "AGSImageAdjustmentLayer.h"
#import "AGSPopupSource.h"

/** @file AGSRasterLayer.h */ //Required for Globals API doc

/**  A layer that can display raster data
 
 An instance of this class represents a layer that can display raster data. 
 
 In its simplest form, a raster consists of a matrix of cells (or pixels) organized into rows and columns (or a grid) where each cell contains a value representing information, such as temperature. Rasters are digital aerial photographs, imagery from satellites, digital pictures, or even scanned maps.
 
 [Learn more about rasters](http://desktop.arcgis.com/en/arcmap/latest/manage-data/raster-and-images/what-is-raster-data.htm)
 
 @see `AGSRaster`
 @license{Standard}
 @ingroup licensing
 @since 100
 @ios
 @beta
 @ingroup beta
 @endios
 */
@interface AGSRasterLayer : AGSImageAdjustmentLayer <AGSPopupSource>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the layer with the provided raster
 @param raster
 @return Initialized raster layer
 @since 100
 */
-(instancetype)initWithRaster:(AGSRaster*)raster;

/** Initialize the layer with the provided raster
 @param raster
 @return Initialized raster layer
 @since 100
 */
+(instancetype)rasterLayerWithRaster:(AGSRaster*)raster;

#pragma mark -
#pragma mark properties

/** The layer's raster object
 @since 100
 */
@property (nonatomic, strong, readonly) AGSRaster *raster;

/** The renderer specifying how raster data should be  displayed
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSRasterRenderer *renderer;

NS_ASSUME_NONNULL_END
@end
