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

#import "AGSMarkerSceneSymbol.h"
#import "AGSRemoteResource.h"
#import "AGSLoadable.h"

/** @file AGSModelSceneSymbol.h */ //Required for Globals API doc

/**  A marker scene symbol based on a 3D model
 
 Instances of this class represent a marker symbol based on a 3D model that can be displayed in a scene by `AGSSceneview`.
 
 The file formats listed in the following document are supported - http://www.assimp.org/main_features_formats.html
 
 @note Digital Asset Exchange (*.dae) files that are added to your project will need to be renamed to use a different file extension, or their @i Type setting in Xcode File Inspector be changed to "Data" in order to work correctly with ArcGIS Runtime. This is because Xcode compresses such files by default which causes a failure when opening them.
 @since 100
 @ios
 @beta
 @ingroup beta
 @endios
*/
@interface AGSModelSceneSymbol : AGSMarkerSceneSymbol <AGSLoadable, AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a model marker symbol with a URL to a model file on the network or on disk.
 @param URL to the model file on the network or on disk
 @param scale factor to adjust the size of the model
 @return Initialized model marker symbol
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL scale:(float)scale;

/** Initialize a model marker symbol with a model file within the application bundle or shared documents directory.
 @param name of the model file
 @param extension of the model file
 @param scale factor to adjust the size of the model
 @return Initialized model marker symbol
 @note Digital Asset Exchange (*.dae) files that are added to your project will need to be renamed to use a different file extension, or their @i Type setting in Xcode File Inspector be changed to "Data" in order to work correctly with ArcGIS Runtime. This is because Xcode compresses such files by default which causes a failure when opening them.
 @since 100
 */
-(instancetype)initWithName:(NSString*)name extension:(NSString*)extension scale:(float)scale;

/** Initialize a model marker symbol with a URL to a model file on the network or on disk.
 @param URL to the model file on the network or on disk
 @param scale factor to adjust the size of the model
 @return Initialized model marker symbol
 @since 100
 */
+(instancetype)modelSceneSymbolWithURL:(NSURL*)URL scale:(float)scale;

/** Initialize a model marker symbol with a model file within the application bundle or shared documents directory.
 @param name of the model file
 @param extension of the model file
 @param scale factor to adjust the size of the model
 @return Initialized model marker symbol
 @note Digital Asset Exchange (*.dae) files that are added to your project will need to be renamed to use a different file extension, or their @i Type setting in Xcode File Inspector be changed to "Data" in order to work correctly with ArcGIS Runtime. This is because Xcode compresses such files by default which causes a failure when opening them.
@since 100
 */
+(instancetype)modelSceneSymbolWithName:(NSString*)name extension:(NSString*)extension scale:(float)scale;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
