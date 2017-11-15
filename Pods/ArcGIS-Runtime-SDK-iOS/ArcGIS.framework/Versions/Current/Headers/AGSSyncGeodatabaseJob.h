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

@class AGSSyncLayerResult;

#import "AGSJob.h"

/**  A job to synchronize changes between a geodatabase and an ArcGIS Feature service.
 
 Instances of this class represent a long running job on a remote server that can synchronize changes between a geodatabase and an ArcGIS Feature service.
 
 A job is initiated when it is submitted to the server. See [` startWithStatusHandler:completion:`.]
 
 When the server accepts the job, it assigns a unique ID to the job which is avialable in [` serverJobID`.] The client then periodically polls for the status of the job on the server and provides this information in the status handler. If the job completes successfully, the result of the job is provided in the completion handler, otherwise an error is provided when the job fails.
 
 @since 100
 */
@interface AGSSyncGeodatabaseJob : AGSJob
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Result of the job.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSArray<AGSSyncLayerResult*> *result;

#pragma mark -
#pragma mark methods

/** Start the job by submitting it to the server
 @param statusHandler is invoked periodically whenever the job's status changes
 @param completion block that is invoked with the result when the job succeeds, or an error if it fails
 @since 100
 */
-(void)startWithStatusHandler:(nullable void(^)(AGSJobStatus status))statusHandler
                   completion:(void(^)(NSArray<AGSSyncLayerResult*>  * __nullable result, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
