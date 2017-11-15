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

#import "AGSElevationSource.h"

/** @file AGSRasterElevationSource.h */ //Required for Globals API doc

/**  An elevation source based on raster elevation data
 
 Instances of this class represent an elevation source based on raster elevation data on disk. It can be used in [`AGSSurface elevationSources`] to specify the surface of a scene.
 
 @since 100
 @see [`AGSScene baseSurface`] to specify the surface of a scene
 @license{Basic}
 @ingroup licensing
 @ios
 @beta
 @ingroup beta
 @endios
 */
@interface AGSRasterElevationSource : AGSElevationSource

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)rasterElevationSource;

/** Initialize a raster elevation source based on the given elevation raster data
 @param fileURLs containing a list of URLs to elevation raster data on disk
 @return A new raster elevation source
 @since 100
 */
-(instancetype)initWithFileURLs:(NSArray<NSURL*>*)fileURLs;

/** Initialize a raster elevation source based on the given elevation raster data
 @param fileURLs containing a list of URLs to elevation raster data on disk
 @return A new raster elevation source
 @since 100
 */
+(instancetype)rasterElevationSourceWithFileURLs:(NSArray<NSURL*>*)fileURLs;

#pragma mark -
#pragma mark properties

/** URLs to elevation raster data on disk.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSURL*> *fileURLs;

NS_ASSUME_NONNULL_END

@end
