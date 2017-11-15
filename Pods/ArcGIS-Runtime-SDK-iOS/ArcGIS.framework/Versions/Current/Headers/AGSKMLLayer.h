/*
 COPYRIGHT 2016 ESRI
 
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

#import "AGSLayer.h"
#import "AGSRemoteResource.h"

@class AGSKMLFeature;

/** @file AGSKMLLayer.h */ //Required for Globals API doc

/**  A layer that can display map content from KML data
 
 An instance of this class represents a layer based on a KML (Keyhole Markup Language) file (.kml,.kmz file extension). KML is an XML tag based syntax that holds geographic information (geometric shapes, symbology, and attributes) in a file. KML uses a tag-based structure with nested elements and attributes and is based on the XML standard. For more information about KML and how to create a KML file, please refer to the [Google documentation](http://developers.google.com/kml/documentation).
 
 A KML Layer can be created by a local .kml or .kmz file on your device or a valid URL pointing to the files on the internet.
 
 KML data is typically composed of one or more KML feature elements - a document, folder, placemark, network link or overlays  - arranged hierarchially in a tree structure starting at the [` rootFeature`.]

 @license{Standard}
 @ingroup licensing
 @since 100
 @beta
 @ingroup beta
 */
@interface AGSKMLLayer : AGSLayer <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this layer with URL to a KML/KMZ file on the web or on disk.
 @param url to a KML/KMZ file on the web or on disk.
 @return A new kml layer
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize this layer with a name of a KML or KMZ file, excluding the .kml or .kmz file extension,
 within the application bundle or shared documents directory.
 @param name of the KML or KMZ file (excluding the .kml or .kmz file extension)
 @return A new kml layer
 @since 100
 */
-(instancetype)initWithName:(NSString *)name;

/** Initialize this layer with URL to a KML/KMZ file on the web or on disk.
 @param url to a KML/KMZ file on the web or on disk.
 @return A new kml layer
 @since 100
 */
+(instancetype)KMLLayerWithURL:(NSURL*)URL;

/** Initialize this layer with a name of a KML or KMZ file, excluding the .kml or .kmz file extension,
 within the application bundle or shared documents directory.
 @param name of the KML or KMZ file (excluding the .kml or .kmz file extension)
 @return A new kml layer
 @since 100
 */
+(instancetype)KMLLayerWithName:(NSString *)name;

#pragma mark -
#pragma mark properties

/** The root of hierarhicial tree of feature elements in the KML document 
 @since 100
 */
@property (nonatomic, strong, readonly) AGSKMLFeature *rootFeature;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
