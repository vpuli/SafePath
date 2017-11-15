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

@class AGSColor;

/** @file AGSKMLBalloonStyle.h */ //Required for Globals API doc

/**  A KML Balloon Style element
 
 An instance of this class represents a KML `<BalloonStyle>` element which controls how a KML feature should be described in a balloon callout.
 
 @since 100
 */
@interface AGSKMLBalloonStyle : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The background color of the balloon callout
 @since 100
 */
@property (nonatomic, strong, readonly) AGSColor *backgroundColor;

/** The text to display in the balloon callout
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *formattedText;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
