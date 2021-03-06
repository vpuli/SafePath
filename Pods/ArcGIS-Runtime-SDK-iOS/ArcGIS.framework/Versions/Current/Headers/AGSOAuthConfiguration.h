/*
 COPYRIGHT 2015 ESRI
 
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

/** @file AGSOAuthConfiguration.h */ //Required for Globals API doc


/**  OAuth details of an app
 
 Instances of this class contain the OAuth configuration details of an app that can sign into an ArcGIS Portal or ArcGIS Online using OAuth.
 
 @since 100
 */
@interface AGSOAuthConfiguration : NSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/* Initialize the OAuth configuration with provided parameters
 @param portalURL The URL of the portal to authenticate with. This can be nil if you want to use the provided clientID and/or redirectURL for all portals
 @param clientID Unique ID with which this application was registered with the portal.
 @param redirectURL The URL that the OAuth login page will redirect to when authentication completes. For example, `myapp://oauth/`. This URL must be registered with the portal when generating the clientID, and this application must declare that it can handle the URL.
 */
-(instancetype)initWithPortalURL:(nullable NSURL*)portalURL clientID:(NSString*)clientID redirectURL:(nullable NSString*)redirectURL;

/* Initialize the OAuth configuration with provided parameters
 @param portalURL The URL of the portal to authenticate with. This can be nil if you want to use the provided clientID and/or redirectURL for all portals
 @param clientID Unique ID with which this application was registered with the portal.
 @param redirectURL The URL that the OAuth login page will redirect to when authentication completes. For example, `myapp://oauth/`. This URL must be registered with the portal when generating the clientID, and this application must declare that it can handle the URL.
 */
+(instancetype)OAuthConfigurationWithPortalURL:(nullable NSURL*)portalURL clientID:(NSString*)clientID redirectURL:(nullable NSString*)redirectURL;

#pragma mark -
#pragma mark properties

/* The URL of the portal to authenticate with. For example, https://www.arcgis.com
 */
@property (nullable, nonatomic, strong, readonly) NSURL *portalURL;

/* Unquie ID with which this application was registered with the portal.
 */
@property (nonatomic, copy, readonly) NSString *clientID;

/* The URL that the OAuth login page will redirect to when authentication completes. For example, `myapp://oauth/`. The URL must be registered with the portal when generating the clientID, and this application must declare that it can handle the URL.
 */
@property (nullable, nonatomic, copy, readonly) NSString *redirectURL;

/* The requested expiration interval (in minutes) for the refreshToken generated by the
 OAuth request. The max interval can be overridden by the portal administrator.
 NOTE: For a permanent refreshToken (if the portal supports it), use -1.
 */
@property (nonatomic, assign, readwrite) NSInteger refreshTokenExpirationInterval;

/*Defaults to `NO`. When set to `YES`, options to use social logins (Facebook and Google+) will be displayed on the OAuth login page.
 */
@property (nonatomic, assign, readwrite) BOOL showSocialLogins;

/* Deafults to `YES`. When set to `NO`, the OAuth login page will hide the `cancel` button.
 */
@property (nonatomic, assign, readwrite) BOOL showCancelButton;

NS_ASSUME_NONNULL_END
@end
