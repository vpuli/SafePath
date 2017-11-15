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

/** @file AGSMapViewInteractionOptions.h */ //Required for Globals API doc

/**  Options to configure Map View user interactions
 
 Instances of this class provide options to configure the user interactions supported by `AGSMapView`.
 
 @since 100
 */
@interface AGSMapViewInteractionOptions : NSObject

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Whether all the user interaction is enabled on the  AGSMapView.
 Default is  YES
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isEnabled) BOOL enabled;

/** Whether the user can rotate the  AGSMapView.
 Default is  YES
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isRotateEnabled) BOOL rotateEnabled;

/** Whether the user can pan the  AGSMapView.
 If this is disabled then zooming will zoom to center instead of any anchor point.
 Also when diabled this will prevent the magnifier panning the  AGSMapView regardless of what `allowMagnifierToPan` is set to.
 Default is  YES
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isPanEnabled) BOOL panEnabled;

/** Whether the user can zoom in or out on the  AGSMapView.
 Default is  YES
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isZoomEnabled) BOOL zoomEnabled;

/** Indicates whether a magnifier should be shown on the  AGSMapView when the user performs a long press.
 Default is  YES
 */
@property (nonatomic, assign, readwrite, getter=isMagnifierEnabled) BOOL magnifierEnabled;

/** Indicates whether the  AGSMapView should be panned automatically when the magnifier gets near the edge of the  AGSMapView.
 Default is  YES
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL allowMagnifierToPan;

#pragma mark -
#pragma mark methods

@end



