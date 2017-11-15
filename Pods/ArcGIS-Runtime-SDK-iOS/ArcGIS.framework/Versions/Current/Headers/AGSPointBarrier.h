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

@class AGSPoint;

/*@file AGSPointBarrier.h */

/**  A point barrier to constrain routes
 
 Instances of this class represent a point barrier that can be used to constrain routes generated by `AGSRouteTask`.
 
 Barriers serve to temporarily restrict, add impedance (cost) to, and scale impedance on parts of the transportation network.
 
 @since 100
 @see http://desktop.arcgis.com/en/arcmap/latest/extensions/network-analyst/barriers.htm
 */
@interface AGSPointBarrier : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the point barrier with provided location
 @param point where the barrier should be located
 @return Initialized point barrier
 @since 100
 */
-(instancetype)initWithPoint:(AGSPoint*)point;

/** Initialize the point barrier with provided location
 @param point where the barrier should be located
 @return Initialized point barrier
 @since 100
 */
+(instancetype)barrierWithPoint:(AGSPoint*)point;

#pragma mark -
#pragma mark properties

/** Where the barrier is located
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSPoint *geometry;

/** The type of the barrier, whether it fully restricts travel accross it, or merely increases the cost of travel
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSBarrierType type;

/** Specifies how the restriction applies to the direction a vehicle may arrive at or depart from the barrier.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSCurbApproach curbApproach;

/** The status of where this barrier appears on the underlying transportation network
 @since 100
 */
@property (nonatomic, assign, readonly) AGSLocationStatus locationStatus;

#pragma mark -
#pragma mark methods

-(double)addedCostForCostAttribute:(NSString*)attributeName;
-(void)setAddedCost:(double)addedCost forCostAttribute:(NSString*)attributeName;

NS_ASSUME_NONNULL_END
@end