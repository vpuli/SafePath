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

@class AGSLocation;
@class AGSPolyline;
#import "AGSLocationDataSource.h"

/*@file AGSSimulatedLocationDataSource.h */

/**  Simulates location updates based on a list of locations or a polyline geometry
 
 Instances of this class represent a datasource that can simulate location updates based on
 a predefined list of locations (see [` locations`)] or a polyline geometry (see [` setLocationsWithPolyline:`).]
 This is useful for testing or demo purposes.
 
 @since 100
 @see AGSLocationDisplay
 */

@interface AGSSimulatedLocationDataSource : AGSLocationDataSource
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/**
 An array of  AGSLocation objcts that this datasource will use to simulate location updates.
 A location update will be fired every second.
 @since 100
 */
@property (nullable, nonatomic, copy) NSArray<AGSLocation*> *locations;

#pragma mark -
#pragma mark methods

/** Each vertex in the supplied polyline is used to simulate a location update. This
 is useful, for example, if you have a polyline geometry representing a route and you want to simulate device movement along the route. A location update will be fired every second.
 @param polyline The polyline must have valid spatial reference
 @since 100
 */
-(void)setLocationsWithPolyline:(AGSPolyline*)polyline;

NS_ASSUME_NONNULL_END
@end

