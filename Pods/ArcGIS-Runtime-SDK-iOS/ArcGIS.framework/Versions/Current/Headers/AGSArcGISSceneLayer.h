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
#import "AGSLayer.h"
#import "AGSRemoteResource.h"

/** @file AGSArcGISSceneLayer.h */ //Required for Globals API doc

/**  A layer that can display 3D features from an ArcGIS Scene service
 
 An instance of this class represents a layer that can display 3D features in a scene by `AGSSceneView`. The features are provided by an ArcGIS Scene service such as http://scene.arcgis.com/arcgis/rest/services/Hosted/Building_Basel/SceneServer
 
 Features are rendered according to their distance from the viewpoint's camera; thus, features closer to the camera are more detailed.
 
 @since 100
 @ios
 @beta
 @ingroup beta
 @endios
 */
@interface AGSArcGISSceneLayer : AGSLayer <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this layer with a URL to an individual layer in an ArcGIS Scene Service, for e.g. http://scene.arcgis.com/arcgis/rest/services/Hosted/Building_Basel/SceneServer/layers/0
 @param url URL to an individual layer in an ArcGIS Scene Service
 @return A new scene layer
 @since 100
 */
-(instancetype)initWithURL:(NSURL *)url;

-(instancetype)initWithItem:(AGSItem*)item;

-(instancetype)initWithName:(NSString*)name;

+(instancetype)ArcGISSceneLayerWithItem:(AGSItem*)item;

/** Initialize this layer with a URL to an individual layer in an ArcGIS Scene Service, for e.g. http://scene.arcgis.com/arcgis/rest/services/Hosted/Building_Basel/SceneServer/layers/0
 @param url URL to an individual layer in an ArcGIS Scene Service
 @return A new scene layer
 @since 100
 */
+(instancetype)ArcGISSceneLayerWithURL:(NSURL *)url;

+(instancetype)ArcGISSceneLayerWithName:(NSString*)name;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

