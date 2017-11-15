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

#import "AGSObject.h"
#import "AGSLayerContent.h"

@class AGSKMLLabelStyle;
@class AGSKMLBalloonStyle;
@class AGSViewpoint;
@class AGSSymbol;

/** @file AGSKMLFeature.h */ //Required for Globals API doc

/**  A layer that can display map content from KML data
 
 An instance of this class represents KML feature elements which could be a folder, placemark, line, polygon, screen overlay, ground overlay etc.. A KML feature may or may not have child features depending upon its type. Certain properties of a feature only relate to features of a certain type. For Example KML features with defined graphic type will have a center and out bound envelope.
 
 @since 100
 */
@interface AGSKMLFeature : AGSObject <AGSLayerContent>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)KMLFeature;

#pragma mark -
#pragma mark properties

/** The label style for the KML feature.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSKMLLabelStyle *labelStyle;

/** The balloon style for the KML feature.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSKMLBalloonStyle *balloonStyle;

/** List of child features related to this feature.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSKMLFeature *> *childFeatures;

/** Indicates whether the feature is highlighted or not.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isHighlighted) BOOL highlighted;

/** Symbol used to render this feature.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSymbol *symbol;

/** Viewpoint defining how best to view this feature.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSViewpoint *viewpoint;

#pragma mark -
#pragma mark methods


NS_ASSUME_NONNULL_END

@end
