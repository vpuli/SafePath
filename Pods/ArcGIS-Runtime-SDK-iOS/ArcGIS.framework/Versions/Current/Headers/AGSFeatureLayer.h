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

#import "AGSObject.h"
#import "AGSLayer.h"
#import "AGSPopupSource.h"

@class AGSFeatureTable;
@class AGSRenderer;
@class AGSColor;
@class AGSFeature;
@class AGSQueryParameters;
@class AGSFeatureQueryResult;
@class AGSItem;

/** @file AGSFeatureLayer.h */ //Required for Globals API doc

/**  A layer that can display features on a map or a scene
 
 Instances of this class represent a feature layer. Feature layers can display features from an `AGSFeatureTable` on a map using `AGSMapView` or a scene using `AGSSceneView`. The feature table represents feature data either in a remote ArcGIS Feature Service or in a local geodatabase on disk.
 
 Feature layer adopts the loadable pattern; many of its properties are initialized asynchronously. See `AGSLoadable` for more information.
 
 The feature layer has a load dependency on its [` featureTable`] from where it gets information about itself such as min/max scale, renderer, etc. Calling [`AGSLoadable loadWithCompletion:`] on the feature layer initiates loading of its [` featureTable`] too.
 
 @see  AGSFeatureTable
 @since 100
 */
@interface AGSFeatureLayer : AGSLayer <AGSPopupSource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize the layer with the given  AGSFeatureTable
 @param featureTable The backing dataset whose features need to be drawn on the map by this layer.
 @since 100
*/
-(instancetype)initWithFeatureTable:(AGSFeatureTable *)featureTable;
-(instancetype)init;
-(instancetype)initWithItem:(AGSItem*)item layerID:(NSInteger)layerID;
+(instancetype)featureLayerWithItem:(AGSItem*)item layerID:(NSInteger)layerID;
+(instancetype)featureLayer;

/** Initialize the layer with the given  AGSFeatureTable
 @param featureTable The backing dataset whose features need to be drawn on the map by this layer.
 @since 100
 */
+(instancetype)featureLayerWithFeatureTable:(AGSFeatureTable*)featureTable;

#pragma mark -
#pragma mark properties 

/** The definition expression in the syntax of a SQL where clause by which to limit which features are displayed on the map.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *definitionExpression;

/** Indicates whether or not features will be labelled on the map
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL labelsEnabled;

/** The renderer specifying how the features should be symbolized
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSRenderer *renderer;

/** The color to use for drawing a halo around selected features. Defaults to cyan color.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSColor *selectionColor;

/** The width (in points) of the selection halo
 @since 100
 */
@property (nonatomic, assign, readwrite) double selectionWidth;


/** The backing dataset whose features are drawn on the map by this layer.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSFeatureTable *featureTable;

#pragma mark -
#pragma mark methods

/** Reset the visibility of all features back to their original state
 @since 100
 */
-(void)resetFeaturesVisible;

/** Reset the [` renderer`] back to the original renderer provided by the [` featureTable`.]
 This is useful if you, for instance, change the renderer and then want to revert back to the original.
 @since 100
 */
-(void)resetRenderer;

/** Change the visibility of the specified feature. The map is redrawn to reflect the change.
 @param feature to change
 @param visible If true, feature is made visible. If false, feature is hidden
 @since 100
 @note Use [` setFeatures:visible:`] to change the visibility of a group of features together. It provides better performance as the map will only need to be updated once.
 */
-(void)setFeature:(AGSFeature *)feature visible:(BOOL)visible;

/** Change the visibility of the specified features. The map is updated to reflect the change.
 @param features to change
 @param visible If true, features are made visible. If false, features are hidden
 @since 100
 */
-(void)setFeatures:(NSArray<AGSFeature*> *)features visible:(BOOL)visible;

/** Clears selection on all features.
 @since 100
 */
-(void)clearSelection;

/** Retrieve the list of features that have selection enabled.
 @param completion block that is invoked with the results, or an error if one is encountered.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)getSelectedFeaturesWithCompletion:(void(^)(AGSFeatureQueryResult *__nullable featureQueryResult, NSError *__nullable error))completion;

/** Select the specified feature. The map will be updated to render the feature with [` selectionColor`]
 @param feature to select
 @since 100
 @see [` selectionColor`]
 @note Use [` selectFeatures:`] to enable selection on a group of features together. It provides better performance as the map will only need to be updated once.
 */
-(void)selectFeature:(AGSFeature *)feature;

/** Select the specified features. The map will be updated to render the features with [` selectionColor`]
 @param features to select
 @since 100
 @see [` selectionColor`]
 */
-(void)selectFeatures:(NSArray<AGSFeature*> *)features;

/** Select features that match the query criteria. The map will be updated to render the features with [` selectionColor`.]
 @param parameters defining which features should be considered
 @param mode defining how selection needs to be applied to the features
 @param completion block that is invoked with the results, or an error if one is encountered.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)selectFeaturesWithQuery:(AGSQueryParameters *)parameters mode:(AGSSelectionMode)mode completion:(nullable void (^)(AGSFeatureQueryResult *__nullable featureQueryResult, NSError *__nullable error))completion;


/** Disable selection on the specified feature. The map will be redrawn to reflect the change.
 @param feature to unselect
 @since 100
 @note Use [` unselectFeatures:`] to disable selection on a group of features together. It provides better performance as the map will only need to be updated once.
 */
-(void)unselectFeature:(AGSFeature *)feature;

/** Disable selection on the specified features. The map will be redrawn to reflect the change.
 @param features to unselect
 @since 100
 */
-(void)unselectFeatures:(NSArray<AGSFeature*> *)features;

NS_ASSUME_NONNULL_END

@end
