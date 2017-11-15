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
@class AGSAttributeParameterValue;

/** @file AGSTravelMode.h */ //Required for Globals API doc

/**  Travel options for routes generated by `AGSRouteTask`
 
 Instances of this class represent options that can be used to customize the routes generated by `AGSRouteTask`.
 
 A default list of travel modes is available on [`AGSRouteTaskInfo travelModes`] based on the options supported by the underlying network analyst service or transportation network dataset.
 
 @since 100
 */
@interface AGSTravelMode : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init;
+(instancetype)travelMode;

#pragma mark -
#pragma mark properties

/** Overrides to the attribute values of a cost attribute specified in [` impedanceAttributeName`,] or to the attribute values of a restriction attribute specified in [` restrictionAttributeNames`.]
 
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<AGSAttributeParameterValue*> *attributeParameterValues;

/** Description of this travel mode
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *travelModeDescription;

/** The name of the attribute that can set as [` impedanceAttributeName`] to optimize routes based on distance travelled.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *distanceAttributeName;

/** The name of the attribute to use as the impedance. Routes will be optimized in order to minimize this impedance along the route. To minimize time taken by the route, use [` timeAttributeName`.] To minimize distance travelled by the route, use [` distanceAttributeName`.] 
 
 You can also use other attributes that are available in [`AGSRouteTaskInfo costAttributes`] as the impedance.
 
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *impedanceAttributeName;

/** Name of the travel mode
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *name;

/** The desired precision (in Meters) of the output route geometry after generalization.
 @since 100
 */
@property (nonatomic, assign, readwrite) double outputGeometryPrecision;

/** The list of network attribute names to be used as restrictions while computing the route.
 Possible values are specified in [`AGSRouteTaskInfo restrictionAttributes`]
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *restrictionAttributeNames;


/** The name of the attribute that can be set as [` impedanceAttributeName`] to optimize routes based on time taken.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *timeAttributeName;

/** The type of travel mode this instance represents
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *type;

/** Specifies whether hierarchy of elements in the transportation network should be considered.
 @since 100
 @see https://desktop.arcgis.com/en/arcmap/latest/extensions/network-analyst/network-analysis-with-hierarchy.htm
 */
@property (nonatomic, assign, readwrite) BOOL useHierarchy;

/** Specifies how U-Turns should be handled. U-turns can be allowed everywhere, nowhere, only at dead ends, or only at intersections and dead ends. Allowing U-turns implies the vehicle can turn around at a junction and double back on the same street.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSUTurnPolicy uTurnPolicy;

NS_ASSUME_NONNULL_END
@end