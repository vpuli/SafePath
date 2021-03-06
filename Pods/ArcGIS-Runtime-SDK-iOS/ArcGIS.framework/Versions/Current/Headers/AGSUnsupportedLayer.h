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

#import "AGSLayer.h"

/**  An unsupported layer
 
 Instance of this class represent a layer that is based on a service or dataset that is not yet supported.
 The layer will not be drawn in the map view and its [` loadStatus`] will be set to `AGSLoadStatusFailedToLoad`
 
 @since 100
 */
@interface AGSUnsupportedLayer : AGSLayer
NS_ASSUME_NONNULL_BEGIN

-(instancetype)init __attribute__((unavailable("init is not available.")));

NS_ASSUME_NONNULL_END
@end
