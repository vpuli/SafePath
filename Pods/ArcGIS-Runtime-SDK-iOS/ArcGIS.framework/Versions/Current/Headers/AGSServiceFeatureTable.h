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
#import "AGSArcGISFeatureTable.h"
#import "AGSRemoteResource.h"

@class AGSFeatureEditResult;

/** @file AGSServiceFeatureTable.h */ //Required for Globals API doc

/**  A dataset from an individual layer or table in ArcGIS Map or Feature service
 
 Instances of this class represent datasets in an individual layer or table of an ArcGIS Map or Feature service. The service may be hosted in the cloud on ArcGIS Online, or on-premises on an ArcGIS Server. The data is retrieved
 from the service as needed and stored in a temporary geodatabase on disk. How data is retrieved depends upon the [` featureRequestMode`.]
 
 
 
 When using a Feature service, you can potentially create, delete, and update the data depending upon whether the service allows those operations, who owns the data, and what ownership-based access control policies are in place. Refer to the  editCapabilities,  canUpdateFeature:,  canDeleteFeature:, for information on what's permitted.
 
 Edits can be performed through [`#addFeature:completion`,` addFeatures:completion:`,] [` deleteFeature:completion:`,] [` deleteFeatures:completion:`,] [` updateFeature:completion:`,] [` updateFeatures:completion:`.] However, these edits only affect the temporary geodatabase and must be committed to the service through [` applyEditsWithCompletion:`]
 
 If the service supports attachments ( hasAttachments), you can also view and potentially edit the attachments.
 
 You can also query the data based on SQL expressions and/or spatial relationships.
 
 This class is typically used in conjunction with  AGSFeatureLayer to display feature data on a map. It can handle temporary network outages while still allowing you to work with the data that
 has already been retrieved from the service. Your edits are immediately peristed to the local geodatabase and can be applied to the service later when network connectivity is restored.
 
 Service feature table adopts the loadable pattern; many of its properties are initialized asynchronously after connecting to the service. See `AGSLoadable` for more information.
 
 
 @see  AGSFeatureLayer to visualize features from this dataset on a map.
 @since 100
 */
@interface AGSServiceFeatureTable : AGSArcGISFeatureTable <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize the table with the given URL
 @param url The URL of an individual layer or table in ArcGIS Map or Feature service whose data needs to be accessed or edited
 @since 100
 */
-(instancetype)initWithURL:(NSURL *)url;
-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the table with the given URL
 @param url The URL of an individual layer or table in ArcGIS Map or Feature service whose data needs to be accessed or edited
 @since 100
 */
+(instancetype)serviceFeatureTableWithURL:(NSURL*)URL;

#pragma mark -
#pragma mark properties

/** This factor determines the size of the buffer around the map's current extent for which data is retrieved from the service. Data is not retrieved again until either it expires or the map extent changes and is
 no longer in the buffered extent. Buffer factor can be up to 10. If it is set to 0 or 1,
 every time the map extent is changed data for that extent will be requested from the service. 
 Default value is 2
 @since 100
 @note Only applies to `AGSFeatureRequestModeOnInteractionCache`
 */
@property (nonatomic, assign, readwrite) double bufferFactor;

/** Specifies how data should be retrieved from the service. Default is AGSFeatureRequestModeOnInteractionCache.
 
 @since 100
 @note You cannot change this after the table is successfully loaded.
 */
@property (nonatomic, assign, readwrite) AGSFeatureRequestMode featureRequestMode;

/** The geodatabase version.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *geodatabaseVersion;

#pragma mark -
#pragma mark methods

/** Apply the temporary edits in the local geodatabase to the service. Includes edits to a feature's attributes, geometry, and attachments.
 @param completion block that is executed when the operation finishes. The `error` argument will be populated if a problem is encountered with the entire `applyEdits` operation, for example, due to network disruption. Otherwise, the `result` array will contain `AGSFeatureEditResult` objects representing the result of each individual edit to a feature or an attachment. 
 @return operation which can be canceled.
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)applyEditsWithCompletion:(nullable void(^)(NSArray<AGSFeatureEditResult*> *__nullable result, NSError *__nullable error))completion;

/** Clear all the data in the table, including any temporary edits.
 @since 100
 */
-(void)clearCacheWithKeepLocalEdits:(BOOL)keepLocalEdits;

/** Request data from the service based on the specified query parameters and add it to the table. Especially important for non-geographic data or when [` featureRequestMode`] is `AGSFeatureRequestModeManualCache` because the data is not requested automatically based on the map's extent. 
 @param parameters defining which data should be requsted from the service and added to the table
 @param clearCache If true, existing data will cleared before adding the new data
 @param outFields A list of field names specifying which attribute values (columns) should be included in the table.
 @param completion block that is executed when the operation finishes.
 @return operation which can be canceled
 @since 100
*/
-(id<AGSCancelable>)populateFromServiceWithParameters:(AGSQueryParameters *)parameters
                                             clearCache:(BOOL)clearCache
                                             outFields:(NSArray<NSString*> *)outFields
                                             completion:(nullable void(^)(AGSFeatureQueryResult *__nullable result, NSError *__nullable error))completion;

-(id<AGSCancelable>)queryFeaturesWithParameters:(AGSQueryParameters *)parameters
                                          fields:(AGSQueryFeatureFields)fields
                                      completion:(nullable void(^)(AGSFeatureQueryResult *__nullable result, NSError *__nullable error))completion;

NS_ASSUME_NONNULL_END

@end
