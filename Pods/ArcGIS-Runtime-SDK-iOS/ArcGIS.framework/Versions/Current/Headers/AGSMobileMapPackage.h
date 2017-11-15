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

#import "AGSLoadableBase.h"

@class AGSLocatorTask;
@class AGSMap;
@class AGSItem;

/** @file AGSMobileMapPackage.h */ //Required for Globals API doc

/**  A mobile map package
 
 Instances of this class represent a mobile map package (.mmpk file).
 
 A mobile map package can be created from ArcGIS Pro. It is a transport mechanism for mobile maps and scenes, their layers, and the layer's data. It contains metadata about the package (description, thumbnail, etc.), one or more mobile maps/scenes, layers, data and optionally networks and locators.
 
 @since 100
 */
@interface AGSMobileMapPackage : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this object with the specified mobile map package (.mmpk file) on disk.
 @param fileURL to the mobile map package (.mmpk file) on disk.
 @return A new mobile map package object
 @since 100
 */
-(instancetype)initWithFileURL:(NSURL *)fileURL;

/** Initialize this object with the name of a mobile map package (.mmpk file), excluding the ".mmpk" extension,
 within the application bundle or shared documents directory.
 @param name of the mobile map package (excluding the .mmpk extension)
 @return A new mobile map package object
 @since 100
 */
-(instancetype)initWithName:(NSString *)name;

/** Initialize this object with the specified mobile map package (.mmpk file) on disk.
 @param fileURL to the mobile map package (.mmpk file) on disk.
 @return A new mobile map package object
 @since 100
 */
+(instancetype)mobileMapPackageWithFileURL:(NSURL *)fileURL;

/** Initialize this object with the name of a mobile map package (.mmpk file), excluding the ".mmpk" extension,
 within the application bundle or shared documents directory.
 @param name of the mobile map package (excluding the .mmpk extension)
 @return A new mobile map package object
 @since 100
 */
+(instancetype)mobileMapPackageWithName:(NSString *)name;

#pragma mark -
#pragma mark properties

/** Metadata associated with the mobile map package
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSItem *item;

/** The locator contained in the mobile map package
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLocatorTask *locatorTask;

/** The maps contained in the mobile map package
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSMap*> *maps;

/** The URL of the mobile map package (.mmpk file) on disk.
 @since 100
 */
@property (nonatomic, strong, readonly) NSURL *fileURL;

/** Version of the mobile map package
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *version;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

