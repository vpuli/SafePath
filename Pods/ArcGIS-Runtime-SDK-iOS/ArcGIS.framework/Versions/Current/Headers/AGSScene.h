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

#import "AGSLoadableBase.h"

@class AGSLayer;
@class AGSSpatialReference;
@class AGSBasemap;
@class AGSBookmark;
@class AGSViewpoint;
@class AGSSurface;

/** @file AGSScene.h */ //Required for Globals API doc

/**  A scene containing 3D geographic content
 
 Instance of this class represent a scene. It can be displayed on the screen by `AGSSceneView`.
 Thus, a scene represents the Model in an MVC architecture, and a sceneview represents the View.  A scene specifies how the geographic data is organized, and a sceneview renders the data and allows users to interact with it.
 
 Conceptually, a scene's geographic content is derived from its [` basemap`] and [` operationalLayers`,] which may be draped over a [` baseSurface`] to account for elevation.
 
 A basemap helps orient the user and provides a geographical context for the content you want to display in the scene. It is used for locational reference and provides a framework on which you can overlay operational layers. Thus, the basemap serves as a foundation and provides a framework for working with information geographically. It's content is typically static and does not change frequently. For eg, streets, parcel boundaries, or geographic features such as rivers. Some basemaps also contain reference layers, such as labels, which are drawn on top of operational layers.
 
 Operational layers provide content that is of unique interest to the application and the task at hand. Their content might change frequently. For eg earthquakes, traffic, or the weather.
 
 The scene has a [` spatialReference`] which specifies how the geographic content from its basemap and operational layers is aligned when combined together.
 
 @see `AGSMap` for 2D geographic content
 @since 100
 @ios
 @beta
 @ingroup beta
 @endios
 */
@interface AGSScene : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Instantiates a scene with the given basemap
 @param basemap to use with the scene
 @since 100
 */
-(instancetype)initWithBasemap:(AGSBasemap *)basemap;

/** Instantiates a scene with the given basemap type
 @param basemapType to use with the scene
 @since 100
 */
-(instancetype)initWithBasemapType:(AGSBasemapType)basemapType;

+(instancetype)scene;

/** Instantiates a scene with the given basemap
 @param basemap to use with the scene
 @since 100
 */
+(instancetype)sceneWithBasemap:(AGSBasemap *)basemap;


/** Instantiates a scene with the given basemap type
 @param basemapType to use with the scene
 @since 100
 */
+(instancetype)sceneWithBasemapType:(AGSBasemapType)basemapType;

#pragma mark -
#pragma mark properties

/** The base surface of this scene which provides an elevation context for the basemap and operational layers.
  The layers may be draped on or offset from this surface.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSurface *baseSurface;

/** The scene's basemap.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSBasemap *basemap;

/** The scene's initial viewpoint. This is the area initially displayed by an `AGSSceneView` when the scene is used.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSViewpoint *initialViewpoint;

/** The scene's operational layers. These layers are displayed in a sceneview sandwiched between a basemap's `baseLayers` at the bottom and `referenceLayers` at the top. The layers are drawn in a bottom-up fashion with the 0th layer in the list drawn first, next layer drawn on top of the previous one, and so on.
 @note This array does not allow duplicate objects.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSLayer*> *operationalLayers;

/** The scene's spatial reference.
 
 Spatial references define where coordinates are located on the earth's surface and how the geographic content from the basemap and operational layers is aligned when combined together.
 
 If a spatial reference wasn't provided when the scene was instantiated, it is typically derived from the bottom-most base layer in the basemap. If the scene does not have a basemap or if the basemap is empty, the spatial reference is derived from the bottom-most operational layer.
 
 If the spatial reference of layers is different from that of the scene, the layers must be reprojected to the spatial reference of the scene before displaying. Some layers may not be able to re-project their data, for example layers based on tiles that have been pre-generated ahead of time. To maximize performance, avoid reprojection entirely by ensuring all layers have the same spatial reference as the scene.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** The bookmarks associated with the scene
 @note This array does not allow duplicate objects.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSBookmark*> *bookmarks;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
