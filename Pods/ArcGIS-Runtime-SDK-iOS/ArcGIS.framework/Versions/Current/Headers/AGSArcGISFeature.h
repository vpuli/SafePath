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
#import "AGSFeature.h"
#import "AGSLoadable.h"

@class AGSAttachment;

/** @file AGSArcGISFeature.h */ //Required for Globals API doc

/**  Represents a geographic feature in an ArcGIS Geodatabase
 
 Instances of this class represent geographic features that specifically originate from an ArcGIS Geodatabase.
 
 A feature can contain a set of attributes (key-value pairs) providing more
 information about the real-world entity it represents. Attribute types supported are  NSNull, NSString, NSDate, and NSNumber.
 All other attribute types will be ignored. A feature can also have a geometry which describes the location and the shape of the. A feature can also have additional data associated with it in the form of picture, video, or document attachments.
 entity.

 @since 100
 */
@interface AGSArcGISFeature : AGSFeature <AGSLoadable>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));


#pragma mark -
#pragma mark properties

@property (nonatomic, assign, readonly) BOOL canEditAttachments;
@property (nonatomic, assign, readonly) BOOL canUpdateGeometry;

#pragma mark -
#pragma mark methods

-(BOOL)refreshObjectID;

/** Adds a new attachment for the feature
 @param name of the attachment
 @param contentType The MIME type of the attachment
 @param data representing the attachment's content
 @param completion block that is invoked when operation completes.
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)addAttachmentWithName:(NSString *)name
                               contentType:(NSString *)contentType
                                      data:(NSData *)data
                                completion:(nullable void(^)(AGSAttachment *__nullable result, NSError *__nullable error))completion;

/** Delete an existing attachment of this feature.
 @param attachment to be deleted
 @param completion block that is invoked when the operation completes
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)deleteAttachment:(AGSAttachment *)attachment
                           completion:(nullable void(^)(NSError *__nullable error))completion;

/** Delete a set of existing attachments of this feature.
 @param attachments to be deleted as an array of `AGSAttachment` objects
 @param completion block that is invoked when the operation completes
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)deleteAttachments:(NSArray<AGSAttachment*> *)attachments
                            completion:(nullable void(^)(NSError *__nullable error))completion;


/**
 Fetch information about attachments that belong to this feature.
 @param completion block that is called when the operation is complete. The attachments are passed in as an array of  AGSAttachment objects.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchAttachmentsWithCompletion:(nullable void(^)(NSArray<AGSAttachment*> *__nullable result, NSError *__nullable error))completion;

/** Update an existing attachment of the feature
 @param attachment The attachment to update
 @param name The new name of the attachment
 @param contentType The new MIME type
 @param data The new data
 @param completion block that is invoked when the operation completes
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)updateAttachment:(AGSAttachment *)attachment
                                 name:(NSString *)name
                          contentType:(NSString *)contentType
                                 data:(NSData*)data
                           completion:(nullable void(^)(NSError *__nullable error))completion;

NS_ASSUME_NONNULL_END

@end
