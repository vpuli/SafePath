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

@class AGSSpatialReference;
@class AGSGeometry;
@class AGSPolygon;
@class AGSEnvelope;
@class AGSPolyline;
@class AGSPoint;
@class AGSProximityResult;
@class AGSUnit;
@class AGSAreaUnit;
@class AGSLinearUnit;
@class AGSAngularUnit;
@class AGSGeodesicEllipseParameters;
@class AGSGeodeticDistanceResult;
@class AGSMutablePointCollection;
@class AGSGeodesicSectorParameters;

/** @file AGSGeometryEngine.h */ //Required for Globals API doc

/**  An engine to perform geometric operations
 
 This class can perform geometric operations such as spatial relationship tests, reprojections, shape manipulations, and topological query and analysis operations.
 
 The class contains static methods that operate on geometries. The types of operations that can be performed include the following -
 
 @li Create new geometries from others with methods that buffer, clip and join (union) geometries.
 @li Test spatial relationships between geometries such as intersect and contains.
 @li Find the points of nearest distance between geometries.
 @li Reproject geometries.
 @li Calculate area and length.
 @li Convert geometries to and from their JSON representation.
 @li Perform planar and geodesic/geodetic operations.
 
 
 Some operations use geodesic line interpolation rather than planar (Cartesian). Those that use geodesic line interpolation are specified in their descriptions. A geodesic line follows the shortest distance between two points on the Earth's surface when Earth's surface is approximated by a spheroid. When geodesic line interpolation is used, measurements of distance, area and azimuth are accurate with respect to the curved surface of the spheroid.
 
 @see oncept{geometry-operations.htm, Peforming geometric operations}
 @see 
 @since 100
 */

@interface AGSGeometryEngine : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark - Geodetic/Geodesic Operators

/** Gets the geodetic area for the AGSGeometry passed in. Will return NAN if the calculation
 results in a linear to angular conversion (for instance, Decimal Degrees to Meters)
 @param geometry The geometry to calculate the area for.
 @param areaUnit The unit at which the area is calculated.
 @param curveType The type of geodetic curve
 @return The calculated geodetic area in the specified unit.
 @since 100
 */
+ (double)geodeticAreaOfGeometry:(AGSGeometry*)geometry areaUnit:(AGSAreaUnit*)areaUnit curveType:(AGSGeodeticCurveType)curveType;

/** Creates a buffer polygon at the specified distance around the given geometry.
 @param geometry The input geometry
 @param distance The distance by which to buffer the geometry
 @param distanceUnit in which the distance is specified
 @param maxDeviation the maximum distance that the generalized buffer geometry can deviate from the original one, specified in the units of the input geometry's spatial reference
 @param curveType The type of geodetic curve
 @return The geodetically buffered geometry.
 @since 100
 */
+ (nullable AGSPolygon*)geodeticBufferGeometry:(AGSGeometry*)geometry distance:(double)distance distanceUnit:(AGSLinearUnit*)distanceUnit maxDeviation:(double)maxDeviation curveType:(AGSGeodeticCurveType)curveType;

/** Densifies the input geometry by plotting points between existing vertices.
 @param geometry The input geometry
 @param maxSegmentLength The maximum distance between points after densification.
 @param lengthUnit The unit that the max segment length parameter is in.
 @param curveType The type of geodetic curve
 @return The geodetically densified geometry.
 @since 100
 */
+ (nullable AGSGeometry*)geodeticDensifyGeometry:(AGSGeometry*)geometry maxSegmentLength:(double)maxSegmentLength lengthUnit:(AGSLinearUnit*)lengthUnit curveType:(AGSGeodeticCurveType)curveType;

/** Returns the geodetic distance between 2 given points and calculates the azimuth at both points for the geodetic curves that connects the points.
 @param point1 The first point
 @param point2 The second point
 @param distanceUnit The linear units of the distance returned in the AGSGeodeticDistanceResult object
 @param azimuthUnit The angular unit of the azimuth returned in the AGSGeodeticDistanceResult object
 @param curveType The type of geodetic curve
 @return The AGSGeodeticDistanceResult object containing the shortest distance between the 2 points along the geodetic curve, and the azimuth at both those points.
 @since 100
 */
+ (nullable AGSGeodeticDistanceResult*)geodeticDistanceBetweenPoint1:(AGSPoint*)point1 point2:(AGSPoint*)point2 distanceUnit:(AGSLinearUnit*)distanceUnit azimuthUnit:(AGSAngularUnit*)azimuthUnit curveType:(AGSGeodeticCurveType)curveType;

/** Constructs a geodesic ellipse that is centered on a specified point and defined by it's 2 axes and the direction of it's longest axis. The ellipse is provided as a AGSPolygon, AGSPolyline or AGSMultipoint geometry.
 @param params Specifies the parameters for constructing the ellipse.
 @return The ellipse is returned in the format specified by the geometryType parameter. The ellipse is generalized according to the vertexCount.
 @since 100
 */
+ (nullable AGSGeometry*)geodesicEllipseWithParameters:(AGSGeodesicEllipseParameters*)params;

/** Gets the geodetic length for the AGSGeometry passed in. The length is calculated  using only the vertices of the polygon and define the lines between the points as geodesic segments independent of the actual shape of the polygon. A geodesic segment is the shortest path between two points on an ellipsoid. Thus, if you have a line that spans the width of the world, with only two vertices, each on the edges of the map, the geodesic length would be zero (shortest distance between the two vertices).
 
 Will return NAN if the calculation
 results in a linear to angular conversion (for instance, Decimal Degrees to Meters)
 @param geometry The geometry to calculate the geodetic length for.
 @param lengthUnit The unit at which the length is calculated.
 @param curveType The type of geodetic curve
 @return The calculated geodetic length in the specified unit.
 @since 100
 @see [` lengthOfGeometry:`]
 
 */
+ (double)geodeticLengthOfGeometry:(AGSGeometry*)geometry lengthUnit:(AGSLinearUnit*)lengthUnit curveType:(AGSGeodeticCurveType)curveType;

/** Gets an array of AGSPoint objects that have been moved by geodetic calculation. Each point in the array is moved by the given distance and azimuth.
 @param points An array of points to be moved.
 @param distance The distance by which the points are moved.
 @param distanceUnit The linear units of the distance. The default is AGSSRUnitMeter.
 @param azimuth The azimuth for the points to be moved along.
 @param azimuthUnit The angular unit of the azimuth.
 @param curveType The type of geodetic curve
 @return An array of points moved along a geodetic curve by distance and azimuth.
 @since 100
 */
+ (nullable NSArray<AGSPoint*>*)geodeticMovePoints:(NSArray<AGSPoint*>*)points distance:(double)distance distanceUnit:(AGSLinearUnit*)distanceUnit azimuth:(double)azimuth azimuthUnit:(AGSAngularUnit*)azimuthUnit curveType:(AGSGeodeticCurveType)curveType;

/** Constructs a geodesic sector defined by a geodesic arc and 2 radii. The arc is a portion of an ellipse that is centered on a specified point and is defined by it's 2 axes and the length of it's longest axis. The first radius angle is defined by the startDirection angle and the second radius angle is the sum of the startDirection and the sectorAngle. The sector is constructed as a AGSPolygon, AGSPolyline or AGSMultipoint geometry.
 @param params Specifies the parameters for constructing the sector.
 @return The sector is returned in the format specified by the geometryType and is generalized according to the arcVertexCount and the radiusVertexCount parameters.
 @since 100
 */
+ (nullable AGSGeometry*)geodesicSectorWithParameters:(AGSGeodesicSectorParameters*)params;


#pragma mark - Topological Query Operators

/** Returns YES if geometry1 contains geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 containsGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 crosses geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 crossesGeometry:(AGSGeometry*)geometry2;

/** Cut the 'geometry' with the 'cutter'. The cutter and geometry's spatial references must match.
 When cutting an  AGSPolyline, all left cuts will be grouped together in the first  AGSGeometry, right cuts and coincident cuts are grouped in the second  AGSGeometry, and each undefined cut, along with any uncut parts, are output as separate  AGSPolylines.
 When cutting an  AGSPolygon, all left cuts are grouped in the first  AGSGeometry, all right cuts are in the second  AGSGeometry, and each undefined cut, along with any left-over parts after cutting, are output as a separate  AGSGeometry.
 If there were no cuts the an empty  NSArray will be returned.
 If the left or right cut does not exist, the returned  AGSGeometry will be empty for this type of cut. An undefined cut will only be produced if a left cut or right cut was produced, and there was a part left over after cutting or a cut is bounded to the left and right of the cutter.
 If an error occurs, nil is returned.
 
 @param geometry to cut
 @param cutter polyline to cut with
 @since 100
 */
+ (nullable NSArray<AGSGeometry *> *)cutGeometry:(AGSGeometry*)geometry withCutter:(AGSPolyline*)cutter;

/** Returns YES if geometry1 is disjoint to geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 disjointToGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 is equal to geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 equalsGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 intersects geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 intersectsGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry is topologically simple.
 @since 100
 */
+ (BOOL)geometryIsSimple:(AGSGeometry*)geometry;

/** Returns YES if geometry1 overlaps geometry2.
 It compares two geometries of the same dimension
 and returns TRUE if their intersection results in a geometry different from both but of the same dimension.

 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 overlapsGeometry:(AGSGeometry*)geometry2;

/** Determines if @p geometry1 is related to @p geometry2 by the @p relation specified.
 Example: To test if a polygon 'P' contains a point 'pt' you would pass the following:
 <code>-[AGSGeometryEngine geometry:P relatesToGeometry:pt byRelation:@"T*****FF*"]</code>.
 This checks:
 1. The interiors of both geometries intersect.
 2. The exterior of P does not intersect the interior of pt
 3. The exterior of P does not intersect the boundary of pt.
 
 @param geometry1 The input geometry to be compared.
 @param geometry2 The input geometry in which we are comparing @p geometry1 against.
 @param relation The DE-9IM string to be evaluated. Strings such as <code>"T*****FF*"</code> are accepted.
 @return A boolean indicating if the relation is <code>True</code> or <code>False</code>.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 relatesToGeometry:(AGSGeometry*)geometry2 byRelation:(NSString*)relation;

/** Returns YES if geometry1 touches geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 touchesGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 is completely within geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 withinGeometry:(AGSGeometry*)geometry2;


#pragma mark - Topological Analysis Operators

/** Gets the simple area for the AGSGeometry passed in. This is a planar measurement using 2D Cartesian mathematics to compute the area.
 
 The geometry must be topologically correct
 to get its accurate legth. Geometries returned by ArcGIS Server services are always correct.
 If you construct geometries programmatically or using the sketch layer, or if you modify geometries returned by ArcGIS Server,
 you should simplify them using [<code> simplifyGeometry:</code>]
 @param geometry The geometry to calculate the area for.
 @return The computed area in the same units as the geometry's spatial reference unit.
 @since 100
 @see [` geodeticAreaOfGeometry:areaUnit:curveType:`]
 */
+ (double)areaOfGeometry:(AGSGeometry*)geometry;

+ (nullable AGSGeometry*)boundaryOfGeometry:(AGSGeometry*)geometry;

/** Creates a buffer polygon at the specified distance around the given geometry.
 @param geometry Specifies the input geometry.
 @param distance The distance (in the unit of the geometry's spatial reference) by which
 to buffer the geometry.
 @return The polygon that represents the buffered area.
 @since 100
 @see  [AGSUnit convert:fromUnit:] and  [AGSUnit convert:toUnit:] to convert values between different units
 */
+ (nullable AGSPolygon*)bufferGeometry:(AGSGeometry*)geometry byDistance:(double)distance;


/** Constructs the polygon created by clipping geometry by envelope.
 @param geometry The geometry to be clipped by the given envelope.
 @param envelope The envelope in which to use in order to clip geometry.
 @return A geometry that represents the area clipped by envelope.
 @since 100
 */
+ (nullable AGSGeometry*)clipGeometry:(AGSGeometry*)geometry withEnvelope:(AGSEnvelope*)envelope;

/** Returns the minimum bounding geometry that completely encloses the given geometry.
 @param geometry for which convex hull needs to be calculated. Typically either an  AGSMultipoint,  AGSPolygon, or  AGSPolyline.
 @return minimum bounding geometry
 @since 100
 */
+ (nullable AGSGeometry*)convexHullForGeometry:(AGSGeometry*)geometry;


/** Densifies the input geometry by plotting points between existing vertices.
 @param geometry The input geometry
 @param maxSegmentLength The maximum distance between points after densification. This
 distance should be in the same unit as the geometry's spatial reference.
 @return The densified geometry.
 @since 100
 */
+ (nullable AGSGeometry*)densifyGeometry:(AGSGeometry*)geometry maxSegmentLength:(double)maxSegmentLength;

/** Constructs the set-theoretic difference between two geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry. Must be of same type as first geometry.
 @return A geometry that represents the difference of the two input geometries.
 @since 100
 */
+ (nullable AGSGeometry*)differenceOfGeometry1:(AGSGeometry*)geometry1 geometry2:(AGSGeometry*)geometry2;

/** Measures the simple planar distance between two geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry.
 @return The distance between the two input geometries in the same unit as the spatial reference of the
 input geometries.
 @since 100
 */
+ (double)distanceBetweenGeometry1:(AGSGeometry*)geometry1 geometry2:(AGSGeometry*)geometry2;

/** Generalizes the input geometry by removing vertices based on the Douglas-Poiker algorithm.
 @param geometry The input geometry
 @param maxDeviation the maximum distance that the generalized geometry can deviate from the original one, specified in the units of the input geometry's spatial reference
 @param removeDegenerateParts If YES, degenerate parts of the generalized geometry that are undesired for drawing will be removed.
 @since 100
 */
+ (nullable AGSGeometry*)generalizeGeometry:(AGSGeometry*)geometry maxDeviation:(double)maxDeviation removeDegenerateParts:(BOOL)removeDegenerateParts;

/** Constructs the set-theoretic intersection between two geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry. Must be of same type as first geometry.
 @return A geometry that represents the intersection of the two input geometries.
 @since 100
 */
+ (nullable AGSGeometry*)intersectionOfGeometry1:(AGSGeometry*)geometry1 geometry2:(AGSGeometry*)geometry2;

/** Gets the length for a specified  AGSGeometry. This is a planar measurement using 2D Cartesian mathematics to compute the length.
 
 The geometry must be topologically correct
 to get its accurate legth. Geometries returned by ArcGIS Server services are always correct.
 If you construct geometries programmatically or using the sketch layer, or if you modify geometries returned by ArcGIS Server,
 you should simplify them using <code>simplifyGeometry:</code>
 
 @param geometry The geometry to calculate the length for.
 @return The calculated length in the same units as the geometry's spatial reference unit.
 @since 100
 @see [` geodeticLengthOfGeometry:lengthUnit:curveType:`]
 */
+ (double)lengthOfGeometry:(AGSGeometry*)geometry;

/** Simplifies the given geometry to make it topologically consistent according
 to their geometry type. For instance, it rectifies polygons that may be
 self-intersecting, or contain incorrect ring orientations.
 @param geometry The geometry to be simplified.
 @return The simplified geometry.
 @since 100
 */
+ (nullable AGSGeometry*)simplifyGeometry:(AGSGeometry*)geometry;

/** Constructs the set-theoretic symmetric difference between two geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry of dimension equal
 to or greater than the elements of the first geometry.
 @return A geometry that represents the difference of the two input geometries.
 @since 100
 */
+ (nullable AGSGeometry*)symmetricDifferenceOfGeometry1:(AGSGeometry*)geometry1 geometry2:(AGSGeometry*)geometry2;

/** The union operation constructs the set-theoretic union of the two provided geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry. Must be of same type as first geometry.
 @return The union of both the input geometries.
 @since 100
 */
+ (nullable AGSGeometry*)unionOfGeometry1:(AGSGeometry*)geometry1 geometry2:(AGSGeometry*)geometry2;


#pragma mark - Other

/** Calculates an interior point for a specified polygon. This interior
 point can be used by clients to place a label for the polygon.
 @param polygon The polygon to get label points for.
 @return The label point.
 @since 100
 */
+ (nullable AGSPoint*)labelPointForPolygon:(AGSPolygon*)polygon;

/** Folds the geometry into a range of 360 degrees. This may be necessary when wrap around
 is enabled on the map.
 @param geometry The geometry that you want folded.
 @return The folded geometry
 @since 100
 */
+ (nullable AGSGeometry*)normalizeCentralMeridianOfGeometry:(AGSGeometry*)geometry;

/** Creates offset version of the input geometries.
 
 The offset operation creates a geometry that is a constant distance from an input polyline or polygon.
 It is similar to buffering, but produces a one sided result. If offsetDistance > 0, then the offset
 geometry is constructed to the right of the oriented input geometry, otherwise it is constructed to
 the left. For a simple polygon, the orientation of outer rings is clockwise and for inner rings it is counter
 clockwise. So the “right side” of a simple polygon is always its inside.
 The bevelRatio is multiplied by the offset distance and the result determines how far a mitered
 offset intersection can be from the input curve before it is beveled.
 
 @param geometry The geometry to calculate offset for. Point and MultiPoint are not supported.
 @param distance The offset distance for the Geometries.
 @param joinType The join type of the offset geometry.
 @param bevelRatio The ratio used to produce a bevel join instead of a miter join (used only when joins is Miter)
 @param flattenError The maximum distance of the resulting segments compared to the true circular arc (used only when joins is Round).
 If flattenError is 0, tolerance value is used. Also, the algorithm never produces more than around 180 vetices for each round join.
 @return Returns the result of the offset operation.
 @since 100
 */
+ (nullable AGSGeometry*)offsetGeometry:(AGSGeometry*)geometry distance:(double)distance offsetType:(AGSGeometryOffsetType)offsetType bevelRatio:(double)bevelRatio flattenError:(double)flattenError;

/**  Projects the given geometry into a new spatial reference.
 @param geometry The geometry to be projected.
 @param spatialReference The spatial reference to which geometry need to be
 projected.
 @return The projected geometry
 @since 100
 */
+ (nullable AGSGeometry*)projectGeometry:(AGSGeometry*)geometry toSpatialReference:(AGSSpatialReference*)spatialReference;

/** Finds the nearest coordinate in a specified geometry to a specified point.
 @param geometry The geometry in which the nearest coordinate to a specified point is to be found.
 @param point The point which to find the nearest coordinate to.
 @return The proximity result.
 @since 100
 */
+ (nullable AGSProximityResult*)nearestCoordinateInGeometry:(AGSGeometry*)geometry toPoint:(AGSPoint*)point;

/** Finds the nearest vertex in a specified geometry to a specified point.
 @param geometry The geometry in which the nearest vertex to a specified point is to be found.
 @param point The point which to find the nearest vertex to.
 @return The proximity result.
 @since 100
 */
+ (nullable AGSProximityResult*)nearestVertexInGeometry:(AGSGeometry*)geometry toPoint:(AGSPoint*)point;

NS_ASSUME_NONNULL_END
@end
