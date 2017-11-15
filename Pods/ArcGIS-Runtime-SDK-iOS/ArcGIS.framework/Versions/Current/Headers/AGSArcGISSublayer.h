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
#import "AGSLayerContent.h"
#import "AGSPopupSource.h"

@class AGSPopupDefinition;

/** @file AGSArcGISSublayer.h */ //Required for Globals API doc

/**  Information about an individual layer or table in ArcGIS Map Service.
 
 Instances of this class represent information about an individual layer or table in an ArcGIS Map Service.
 
 @since 100
 */

@interface AGSArcGISSublayer : AGSObject <AGSLayerContent, AGSPopupSource, NSCopying>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers
 
#pragma mark -
#pragma mark properties

/** The ID of this layer.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger sublayerID;

/** This layer's max scale.
 @since 100
 */
@property (nonatomic, assign, readonly) double maxScale;

/** This layer's min scale.
 @since 100
 */
@property (nonatomic, assign, readonly) double minScale;

/** This layer's sub-layers.
 @note This array does not allow duplicate objects.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSArcGISSublayer*> *sublayers;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
