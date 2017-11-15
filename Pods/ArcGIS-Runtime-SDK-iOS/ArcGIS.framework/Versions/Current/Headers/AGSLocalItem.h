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

#import "AGSItem.h"

/** @file AGSLocalItem.h */ //Required for Globals API doc

/**  A unit of content on-disk
 
 Instances of this class represent a unit of content locally on-disk. It is similar to `AGSPortalItem` except it is local on the device instead of being remote on a portal.
 
 @since 100
 */
@interface AGSLocalItem : AGSItem

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The type of content that is local
 @since 100
 */
@property (nonatomic, assign, readonly) AGSLocalItemType type;

@end
