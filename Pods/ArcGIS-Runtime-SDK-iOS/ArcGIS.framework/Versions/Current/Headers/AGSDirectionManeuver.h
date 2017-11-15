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

@class AGSGeometry;
@class AGSDirectionMessage;
@class AGSDirectionEvent;

/** @file AGSDirectionManeuver.h */ //Required for Globals API doc

/**  A single maneuver in a series of driving direction
 
 Instances of this class represent an individual maneuver in a series of turn-by-turn driving directions.
 
 @since 100
 */
@interface AGSDirectionManeuver : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Events along the maneuver
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSDirectionEvent*> *directionEvents;

/** User-friendly text describing the maneuver
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *directionText;

/** Estimated time of arrival at the destination of this manuever in the current locale of the device.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *estimatedArriveTime;

/** Time zone shift in minutes (based on the destination of this manuever) for the estimated arrival time.
 @since 100
 */
@property (nonatomic, assign, readonly) double estimatedArrivalTimeShift;

/** The detailed messages describing this manuever
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSDirectionMessage*> *maneuverMessages;

/** Geometry representing the maneuver, be it a turn or travelling in a straight line.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSGeometry *geometry;

/** The maneuver type
 @since 100
 */
@property (nonatomic, assign, readonly) AGSDirectionManeuverType maneuverType;

/** Length (in meters) of the maneuver
 @since 100
 */
@property (nonatomic, assign, readonly) double length;

/** Duration (in minutes) of the maneuver
 @since 100
 */
@property (nonatomic, assign, readonly) double duration;

NS_ASSUME_NONNULL_END
@end
