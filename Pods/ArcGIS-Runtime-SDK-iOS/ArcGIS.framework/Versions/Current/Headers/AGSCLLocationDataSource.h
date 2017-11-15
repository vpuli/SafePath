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
#import "AGSLocationDataSource.h"

/*@file AGSCLLocationDataSource.h */

/**  A datasource for  AGSLocationDisplay based on Core Location
 
 Instances of this class represent a datasource that provides device location based on Apple's Core Location services.
 
 @since 100
 @see AGSLocationDisplay
 */
@interface AGSCLLocationDataSource : AGSLocationDataSource
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** The location manager used by this datasource. You should not call the start/stop methods
 on the location manager directly (startUpdatingLocation, startUpdatingHeading, stopUpdatingLocation, stopUdpdatingHeading, etc).
 Also do not assign yourself as the delegate to this location manager.
 @since 100
 */
@property (nonatomic, strong, readonly) CLLocationManager *locationManager;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end

