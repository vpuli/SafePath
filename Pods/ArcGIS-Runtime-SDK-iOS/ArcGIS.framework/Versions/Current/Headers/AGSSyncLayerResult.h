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

@class AGSFeatureEditResult;

/** @file AGSSyncLayerResult.h */ //Required for Globals API doc

/**  Result of a sync operation by `AGSGeodatabaseSyncTask`
 
 Instances of this class represent results of a sync job initiated by [`AGSGeodatabaseSyncTask syncJobWithParameters:geodatabase:`]
 
 @since 100
 */
@interface AGSSyncLayerResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The result of edits applied during the sync operation.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureEditResult*> *editResults;

/** The ID of the layer in the feature service this result applies to.
 Same as [`AGSArcGISFeatureLayerInfo serviceLayerID`] and [`AGSLayer layerID`]
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger layerID;

/** The name of the table in the geodatabase this result applies to.
 Same as [`AGSFeatureTable tableName`.]
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *tableName;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
