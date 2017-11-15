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
#import "AGSFeatureTable.h"

@class AGSArcGISFeatureServiceInfo;
@class AGSArcGISFeatureLayerInfo;
@class AGSFeatureQueryResult;
@class AGSFeatureTemplate;
@class AGSFeatureType;
@class AGSField;
@class AGSArcGISFeature;

/** @file AGSArcGISFeatureTable.h */ //Required for Globals API doc

/**  An ArcGIS specific source for dataset containing geographic features or non-spatial records
 
 Subclasses represent an ArcGIS-specific source for dataset that could include either geographic features or non-spatial records. You can query the dataset using attribute or spatial criteria, and if permitted, also edit the data. Edits are tracked, so you can later retrieve a list of edits. If the dataset contains geographic features you can display them on a map using `AGSFeatureLayer`.
 
 @since 100
 */
@interface AGSArcGISFeatureTable : AGSFeatureTable

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Array of  AGSField objects representing the subset of fields (columns) in the dataset that are editable.
@since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSField*> *editableAttributeFields;

/** A collection of  AGSFeatureTemplate objects representing feature templates
 for the layer. Usually only present if the layer does not contain feature
 sub-types. Only applicable if this dataset is based on an ArcGIS Feature
 Service.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureTemplate*> *featureTemplates;

/** A collection of  AGSFeatureType objects representing feature sub-types in
 the layer. For example, a @em roads layer may contain 2 feature sub-types : highways
 and streets.
 @note This feature is only available for ArcGIS services v10.0 or greater.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureType*> *featureTypes;

/** The name of field which contains the @em GLOBALID for each feature
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *globalIDField;

/** Indicates whether features may have attachments.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasAttachments;


/** The name of field which contains the @em OBJECTID for each feature
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *objectIDField;


@property (nonatomic, assign, readonly) NSInteger serviceLayerID;


/** Information about the source this dataset originates from. 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSArcGISFeatureLayerInfo *layerInfo;

/** The name of the field which contains the sub-type information for each feature.
 @note This feature is only available for ArcGIS services v10.0 or greater.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *typeIDField;


/** Indicates whether the dataset should be visualized using advanced CIM symbols.
 The default is NO. Servers which don't support this simply ignore
 the parameter and return regular symbols instead.
 @since 100
 @note You cannot change this after the table is successfully loaded.
 */
@property (nonatomic, assign, readwrite) BOOL useAdvancedSymbology;

#pragma mark -
#pragma mark methods

/** Creates a new feature based on the specified feature
 template. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param featureTemplate The feature template to use while creating the feature.
 @return The new feature.
 @note The feature will need to be explicitly added to the dataset. See [`AGSFeatureTable addFeature:completion:`]
 @since 100
 */
-(nullable AGSArcGISFeature *)createFeatureWithTemplate:(AGSFeatureTemplate *)featureTemplate;

/** Creates a new feature based on the specified feature
 template and geometry. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param featureTemplate The feature template to use while creating the feature.
 @param geometry for the feature
 @return The new feature.
 @note The feature will need to be explicitly added to the dataset. See [`AGSFeatureTable addFeature:completion:`]
 @since 100
 */
-(nullable AGSArcGISFeature *)createFeatureWithTemplate:(AGSFeatureTemplate *)featureTemplate geometry:(AGSGeometry *)geometry;

/** Creates a new feature based on the specified feature
 type. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param featureType The type of feature to create.
 @return The new feature.
 @note The feature will need to be explicitly added to the dataset. See [`AGSFeatureTable addFeature:completion:`]
 @since 100
 */
-(nullable AGSArcGISFeature *)createFeatureWithType:(AGSFeatureType *)featureType;

/** Creates a new feature based on the specified feature
 type and geoemtry. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param featureType The type of feature to create.
 @param geoemtry for the feature
 @return The new feature.
 @note The feature will need to be explicitly added to the dataset. See [`AGSFeatureTable addFeature:completion:`]
 @since 100
 */
-(nullable AGSArcGISFeature *)createFeatureWithType:(AGSFeatureType *)featureType geometry:(AGSGeometry *)geometry;

/**
 Set of features that have been locally added to the dataset, but not yet to the originating source.
 @since 100
 */
-(id<AGSCancelable>)addedFeaturesWithCompletion:(void(^)(AGSFeatureQueryResult * __nullable result, NSError * __nullable error))completion;

/**
 Number of features that have been locally added to the dataset, but not yet to the originating source.
 @since 100
 */
-(id<AGSCancelable>)addedFeaturesCountWithCompletion:(void(^)(NSInteger count, NSError * __nullable error))completion;

/**
 Set of features that have been locally deleted from the dataset, but not yet from the originating source.
 @since 100
 */
-(id<AGSCancelable>)deletedFeaturesWithCompletion:(void(^)(AGSFeatureQueryResult * __nullable result, NSError * __nullable error))completion;

/**
 Number of features that have been locally deleted from the dataset, but not yet from the originating source.
 @since 100
 */
-(id<AGSCancelable>)deletedFeaturesCountWithCompletion:(void(^)(NSInteger count, NSError * __nullable error))completion;

/**
 Set of features that have been locally updated in the dataset, but not yet in the originating source.
 @since 100
 */
-(id<AGSCancelable>)updatedFeaturesWithCompletion:(void(^)(AGSFeatureQueryResult * __nullable result, NSError * __nullable error))completion;

/**
 Number of features that have been locally updated in the dataset, but not yet in the originating source.
 @since 100
 */
-(id<AGSCancelable>)updatedFeaturesCountWithCompletion:(void(^)(NSInteger count, NSError * __nullable error))completion;

/** Convenience method to retrieve a feature template given its name
 @param name of feature template
 @return feature template
 @since 100
 */
-(nullable AGSFeatureTemplate *)featureTemplateForName:(NSString *)name;

/** Convenience method to retrieve a feature type given its name
 @param name of feature type
 @return feature type
 @since 100
 */
-(nullable AGSFeatureType *)featureTypeForName:(NSString *)name;

NS_ASSUME_NONNULL_END

@end
