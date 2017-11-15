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

#pragma mark -

#import "AGSObject.h"

@class AGSTimeReference;

/** @file AGSLayerTimeInfo.h */ //Required for Globals API doc

/**  Time information details.
 
 Instances of this class represent time information of a layer. It contains various time related
 info for dealing with time-aware layers.
 
 @since 100
 */
@interface AGSLayerTimeInfo : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The name of the attribute field that contains the start time information.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *startTimeField;

/** The name of the attribute field that contains the end time information.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *endTimeField;

/** The field that contains the trackId.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *trackIDField;

/** Information about how the time was referenced.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSTimeReference *timeReference;

/** Time interval of the data in the layer.
 @since 100
 */
@property (nonatomic, assign, readonly) long long timeInterval;

/** Temporal unit in which the time interval is measured.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSTimeUnit timeUnit;

@property (nonatomic, assign, readonly) BOOL hasLiveData;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
