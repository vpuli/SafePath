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

/** @file AGSEditorTrackingInfo.h */ //Required for Globals API doc

/**  information about a feature service's editor tracking configuration
 
 
 @since 100
 */
@interface AGSEditorTrackingInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates whether owner access control allows non-owners to delete features
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allowOthersToDelete;

/** Indicates whether owner access control allows non-owners to update features
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allowOthersToUpdate;

/** Indicates whether the feature service has editor tracking enabled
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL editorTrackingEnabled;

/** Indicates whether the feature service has owner access control enabled
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL ownershipBasedAccessControlEnabled;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
