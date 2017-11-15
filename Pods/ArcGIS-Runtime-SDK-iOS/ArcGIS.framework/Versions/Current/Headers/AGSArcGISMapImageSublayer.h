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

#import "AGSArcGISSublayer.h"

/** @file AGSArcGISMapImageSublayer.h */ //Required for Globals API doc

/**  Information about an individual layer or table in a dynamic ArcGIS Map Service.
 
 Instances of this class represent information about an individual layer or table in a dynamic ArcGIS Map Service.
 
 @since 100
 */

@interface AGSArcGISMapImageSublayer : AGSArcGISSublayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this sublayer with an ID
 @return Initialized map image sublayer
 @since 100
 */
-(instancetype)initWithID:(NSInteger)ID;

/** Initialize this sublayer with an ID
 @return Initialized map image sublayer
 @since 100
 */
+(instancetype)ArcGISMapImageSublayerWithID:(NSInteger)ID;

#pragma mark -
#pragma mark properties

/** The default visibility of this layer.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isVisibleByDefault) BOOL visibleByDefault;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
