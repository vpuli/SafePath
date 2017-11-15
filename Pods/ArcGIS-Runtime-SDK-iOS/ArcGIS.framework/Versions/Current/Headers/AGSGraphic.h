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

#import "AGSGeoElement.h"

@class AGSSymbol;
@class AGSGraphicsOverlay;

/**  A graphic on top of a map.
 
 Instances of this class represent graphics. Graphics can be displayed on the
 map through an  AGSGraphicsOverlay. Graphics can be used as input to a task, or
 they can be used to display output from a task, or in response to user interaction.
 
 Each graphic must contain an  AGSGeometry describing the location and the shape
 of the graphic. The geometry preferably should be in the same spatial reference as the map, otherwise it will be reprojected on-the-fly (computationally expensive for large number of graphics)
 
 A graphic can be associated with an  AGSSymbol which determines how the graphic
 looks. Alternatively, the graphics overlay can be assgined an  AGSRenderer which
 determines the appearance of all graphics in the overlay. Note, symbols associated
 with individual graphics take precedence over the symbols chosen by the renderer.
 The symbol used depends upon the geometry type associated with the graphic.
 An  AGSMarkerSymbol is used for point and multipoint geometries,
  AGSLineSymbol for polyline geometries, and  AGSFillSymbol
 for polygon geometries.
 
 A graphic can contain a set of attributes (key-value pairs) providing more
 information about the graphic. Some of this information can be displayed in a  AGSCallout
 when a user taps on the graphic. Attribute types supported are NSNull, NSString, NSDate, and NSNumber.
 All other attribute types will be ignored.
 
 Graphic objects respond to key value coding (KVC) methods for setting and getting attribute values.

 @since 100
 */
@interface AGSGraphic : AGSObject <AGSGeoElement>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a new graphic
 @param geometry specifying the location and shape of the graphic
 @param symbol specifying how the graphic should be rendered
 @param attributes of key-value pairs representing information associated with the graphic
 @return A new initialized graphic
 @since 100
 */
-(instancetype)initWithGeometry:(nullable AGSGeometry *)geometry symbol:(nullable AGSSymbol *)symbol attributes:(nullable NSDictionary<NSString*,id>*)attributes;

/** Initialize a new graphic
 @return A new initialized graphic
 @since 100
 */
+(instancetype)graphic;

/** Initialize a new graphic
 @param geometry specifying the location and shape of the graphic
 @param symbol specifying how the graphic should be rendered
 @param attributes of key-value pairs representing information associated with the graphic
 @return A new initialized graphic
 @since 100
 */
+(instancetype)graphicWithGeometry:(nullable AGSGeometry *)geometry symbol:(nullable AGSSymbol *)symbol attributes:(nullable NSDictionary<NSString*,id>*)attributes;

#pragma mark -
#pragma mark properties

/** A dictionary containing all the attributes.
 Attribute types supported are NSNull, NSString, NSDate, and NSNumber.
 Other attribute types will be ignored.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString*,id> *attributes;

/** The geometry that defines shape and location.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSGeometry *geometry;

/** The graphics overlay containing this graphic, if any.
 @since 100
 */
@property (nullable, nonatomic, weak, readonly) AGSGraphicsOverlay *graphicsOverlay;

/** Specifies whether the graphic should appear selected or not.
 @see [`AGSGraphicsOverlay selectionColor`]
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isSelected) BOOL selected;

/** Specifies whether the graphic should be visible or not.
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isVisible) BOOL visible;

/** Symbol with which the graphic should be rendered
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSymbol *symbol;

/** The drawing index that controls the order in which graphics from a single graphics overlay are rendered.
 @since 100
 */
@property (nonatomic, assign, readwrite) NSInteger zIndex;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
