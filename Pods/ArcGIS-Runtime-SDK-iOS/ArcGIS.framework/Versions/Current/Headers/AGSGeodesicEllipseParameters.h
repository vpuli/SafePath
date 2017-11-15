/*
 COPYRIGHT 2014 ESRI
 
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
#import "AGSEnumerations.h"

@class AGSPoint;
@class AGSLinearUnit;
@class AGSAngularUnit;
@class AGSGeometry;

/** @file AGSGeodesicEllipseParameters.h */ //Required for Globals API doc

/**  Parameters for  [AGSGeometryEngine geodesicEllipseWithParameters:]
 
 This class holds options for the  [AGSGeometryEngine geodesicEllipseWithParameters:] operation.
 
 
 @since 100
 */
@interface AGSGeodesicEllipseParameters : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/**Initializes an AGSGeodesicEllipseParameters object.
 @param center The center point of the ellipse.
 @param maxSegmentLength The maximum distance between vertices used to construct the ellipse.
 @param semiAxisLength The length of the semi-major or the semi-minor axis of the ellipse.
 @return A new geodesic ellipse parameter object.
 @since 100
 */
-(instancetype)initWithCenter:(AGSPoint*)center maxSegmentLength:(double)maxSegmentLength semiAxisLength:(double)semiAxisLength;

/**Initializes an AGSGeodesicEllipseParameters object.
 @param center The center AGSPoint of the ellipse.
 @param maxSegmentLength The maximum distance between vertices used to construct the ellipse.
 @param semiAxisLength The length of the semi-major or the semi-minor axis of the ellipse.
 @return A new, autoreleased, geodesic ellipse parameter object.
 @since 100
 */
+(instancetype)parametersWithCenter:(AGSPoint*)center maxSegmentLength:(double)maxSegmentLength semiAxisLength:(double)semiAxisLength;

/**Initializes an AGSGeodesicEllipseParameters object.
 @return A new geodesic ellipse parameter object.
 @since 100
 */
+(instancetype)geodesicEllipseParameters;

#pragma mark -
#pragma mark properties

/** The center AGSPoint of the ellipse.
 @since 100
 */
@property (nullable, nonatomic, strong) AGSPoint *center;

/** The length of the semi-major or the semi-minor axis of the ellipse.
 @since 100
 */
@property (nonatomic, assign) double semiAxis1Length;

/** The length of the semi-major or the semi-minor axis of the ellipse. If semiAxis1 = semiAxis2 then a geodesic circle is created.
 @since 100
 */
@property (nonatomic, assign) double semiAxis2Length;

/** The linear units of the lengths maxSegment, semiAxis1 and semiAxis2. The default is AGSLinearUnitIDMeters.
 @since 100
 */
@property (nullable, nonatomic, strong) AGSLinearUnit *linearUnit;

/** The angular unit of the sectorAngle.
 @since 100
 */
@property (nullable, nonatomic, strong) AGSAngularUnit *angularUnit;

/** The direction of the longest axis of the ellipse as an angle (in degrees).
 @since 100
 */
@property (nonatomic, assign) double axisDirection;

/** The maximum distance between vertices used to construct the ellipse.
 @since 100
 */
@property (nonatomic, assign) double maxSegmentLength;

/** The type of output geometry created. Acceptable values are AGSMultipoint, AGSPolyline and AGSPolygon. Defaults to AGSGeometryTypePolgon.
 @since 100
 */
@property (nonatomic, assign) AGSGeometryType geometryType;

/** The maximum number of points permitted in the constructed ellipse.
 @since 100
 */
@property (nonatomic, assign) NSInteger maxPointCount;

NS_ASSUME_NONNULL_END
@end
