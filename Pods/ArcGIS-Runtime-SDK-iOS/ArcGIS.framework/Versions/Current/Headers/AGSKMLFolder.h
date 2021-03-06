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

#import "AGSKMLContainer.h"

/** @file AGSKMLFolder.h */ //Required for Globals API doc

/**  A KML Folder element
 
 An instance of this class represents a KML `<Folder>` element which is used to arrange other KML features hierarchially (Folders, Placemarks, NetworkLinks, or Overlays). 
 
 @since 100
 */
@interface AGSKMLFolder : AGSKMLContainer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
