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

#import "AGSAddRastersParameters.h"

@interface AGSFrameCameraAddRastersParameters : AGSAddRastersParameters

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)frameCameraAddRastersParameters;

#pragma mark -
#pragma mark properties

@property (nullable, nonatomic, strong, readwrite) NSURL *camerasFileURL;
@property (nullable, nonatomic, strong, readwrite) NSURL *framesFileURL;
@property (nonatomic, assign, readwrite) BOOL shareRasterInfo;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
