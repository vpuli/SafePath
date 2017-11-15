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

#import "AGSKMLFeature.h"

/** @file AGSKMLContainer.h */ //Required for Globals API doc

/**  A KML Container element
 
 An instance of this class represents a KML `<Container>` element which contains nested KML features.
 
 @since 100
 */
@interface AGSKMLContainer : AGSKMLFeature

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)KMLContainer;

#pragma mark -
#pragma mark properties

/** Specifies the container type.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSKMLListItemType listItemType;

/** Indicates whether the container node should be displayed expanded in the table-of-contents view
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isOpen) BOOL open;

/** Indicates if only a subset of nested features in this container are visible.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isPartiallyVisible) BOOL partiallyVisible;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
