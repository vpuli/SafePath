/*
 COPYRIGHT 2011 ESRI

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

/** @file AGSEnumerations.h */

#import "AGSDefines.h"

@class AGSSpatialReference;
@class AGSGeometry;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Geometry

/** Supported geometry types.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGeometryType)  {
    AGSGeometryTypeUnknown = -1,    /*!< Undefined */
    AGSGeometryTypePoint = 1,           /*!< Point */
    AGSGeometryTypeEnvelope = 2,          /*!< Envelope */
    AGSGeometryTypePolyline = 3,        /*!< Polyline */
    AGSGeometryTypePolygon = 4,         /*!< Polygon */
    AGSGeometryTypeMultipoint = 5,      /*!< Multipoint */
};

/** Supported @p offsetHow types.
 Square only applicable with the AGSGeometryEngine
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGeometryOffsetType) {
	AGSGeometryOffsetTypeMitered = 0,       /*!< Mietered */
	AGSGeometryOffsetTypeBevelled = 1,      /*!< Bevelled  */
	AGSGeometryOffsetTypeRounded = 2,       /*!< Rounded */
    AGSGeometryOffsetTypeSquared = 3       /**  Squared  */
};

/** Dimension classification of the geometry
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGeometryDimension) {
    AGSGeometryDimensionPoint = 0,          /*!<  */
    AGSGeometryDimensionCurve = 1,          /*!<  */
    AGSGeometryDimensionArea = 2,           /*!<  */
    AGSGeometryDimensionVolume = 3,         /*!<  */
    AGSGeometryDimensionUnknown = -1,       /*!<  */
};


#pragma mark - Geometry Engine enums

/**
 Types of Geodetic curves.
 @since 100
 @see [About geodetic [features](http://resources.arcgis.com/en/help/main/10.1/index.html /About_geodetic_features/01m70000003q000000/)]
 */
typedef NS_ENUM(NSInteger, AGSGeodeticCurveType) {
    AGSGeodeticCurveTypeGeodesic = 0,       /*!< The shortest line between any two points on the Earth's surface on a spheroid (ellipsoid) */
    AGSGeodeticCurveTypeLoxodrome,          /*!< A line of constant bearing, or azimuth.*/
    AGSGeodeticCurveTypeGreatElliptic,      /*!< The line on a spheroid (ellipsoid) defined by the intersection at the surface by a plane that passes through the center of the spheroid and the start and end points of a segment. This is also known as a great circle when a sphere is used */
    AGSGeodeticCurveTypeNormalSection,      /*!<  */
    AGSGeodeticCurveTypeShapePreserving    /*!< Keeps the original shape of the geometry or curve  */
};



#pragma mark - Network Request

/** The HTTP method being used by the network request.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSRequestHTTPMethod) {
    AGSRequestHTTPMethodGet = 0,						/*!< GET */
    AGSRequestHTTPMethodPostFormEncodeParameters = 1,	/*!< POST Form Encoded Params */
    AGSRequestHTTPMethodPostJSON = 2					/*!< POST Json */
};



#pragma mark - Errors

/** Constant representing domain for errors originating from web services.
 @since 100
 */
AGS_EXTERN NSString *const AGSServicesErrorDomain;

/** Constants representing error codes coming from web services. These errors belongs to  AGSServicesErrorDomain.
 The values in this enumeration are not comprehensive. You may get error codes belonging to the AGSServicesErrorDomain 
 that are not in this enumeration.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSServicesErrorCode) {
    AGSServicesErrorCodeBadRequest = 400,                   /*!< Bad Request */
    AGSServicesErrorCodeUnauthorized = 401,                 /*!< Authorization Required */
    AGSServicesErrorCodeInvalidToken = 498,                 /*!< Invalid Token */
    AGSServicesErrorCodeTokenRequired = 499,                /*!< Token Required */
    AGSServicesErrorCodeUnknownError = 500                  /*!< Unknown Error */
};

/** Constant representing domain for errors originating from ArcGIS Runtime.
 @since 100
 @see `AGSServicesErrorDomain`
 */
AGS_EXTERN NSString *const AGSErrorDomain;

/** Constants representing core error codes. These errors belongs to  AGSErrorDomain.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSErrorCode) {
    AGSErrorCodeUnknown = -1,                                               /*!<  */
    AGSErrorCodeCommonNullPtr = 1,                                          /*!<  */
    AGSErrorCodeCommonInvalidArgument = 2,                                  /*!<  */
    AGSErrorCodeCommonNotImplemented = 3,                                   /*!<  */
    AGSErrorCodeCommonOutOfRange = 4,                                       /*!<  */
    AGSErrorCodeCommonInvalidAccess = 5,                                    /*!<  */
    AGSErrorCodeCommonIllegalState = 6,                                     /*!<  */
    AGSErrorCodeCommonNotFound = 7,                                         /*!<  */
    AGSErrorCodeCommonExists = 8,                                           /*!<  */
    AGSErrorCodeCommonTimeout = 9,                                          /*!<  */
    AGSErrorCodeCommonRegularExpression = 10,                               /*!<  */
    AGSErrorCodeCommonPropertyNotSupported = 11,                            /*!<  */
    AGSErrorCodeCommonNoPermission = 12,                                    /*!<  */
    AGSErrorCodeCommonFile = 13,                                            /*!<  */
    AGSErrorCodeCommonFileNotFound = 14,                                    /*!<  */
    AGSErrorCodeCommonInvalidCall = 15,                                     /*!<  */
    AGSErrorCodeCommonIO = 16,                                              /*!<  */
    AGSErrorCodeCommonUserCanceled = 17,                                    /*!<  */
    AGSErrorCodeCommonInternalError = 18,                                   /*!<  */
    AGSErrorCodeCommonConversionFailed = 19,                                /*!<  */
    AGSErrorCodeCommonNoData = 20,                                          /*!<  */
    AGSErrorCodeCommonInvalidJSON = 21,                                     /*!<  */
    AGSErrorCodeCommonUserDefinedFailure = 22,                              /*!<  */
    AGSErrorCodeSqliteError = 1001,                                         /*!<  */
    AGSErrorCodeSqliteInternal = 1002,                                      /*!<  */
    AGSErrorCodeSqlitePerm = 1003,                                          /*!<  */
    AGSErrorCodeSqliteAbort = 1004,                                         /*!<  */
    AGSErrorCodeSqliteBusy = 1005,                                          /*!<  */
    AGSErrorCodeSqliteLocked = 1006,                                        /*!<  */
    AGSErrorCodeSqliteNoMem = 1007,                                         /*!<  */
    AGSErrorCodeSqliteReadonly = 1008,                                      /*!<  */
    AGSErrorCodeSqliteInterrupt = 1009,                                     /*!<  */
    AGSErrorCodeSqliteIOErr = 1010,                                         /*!<  */
    AGSErrorCodeSqliteCorrupt = 1011,                                       /*!<  */
    AGSErrorCodeSqliteNotFound = 1012,                                      /*!<  */
    AGSErrorCodeSqliteFull = 1013,                                          /*!<  */
    AGSErrorCodeSqliteCantOpen = 1014,                                      /*!<  */
    AGSErrorCodeSqliteProtocol = 1015,                                      /*!<  */
    AGSErrorCodeSqliteEmpty = 1016,                                         /*!<  */
    AGSErrorCodeSqliteSchema = 1017,                                        /*!<  */
    AGSErrorCodeSqliteTooBig = 1018,                                        /*!<  */
    AGSErrorCodeSqliteConstraint = 1019,                                    /*!<  */
    AGSErrorCodeSqliteMismatch = 1020,                                      /*!<  */
    AGSErrorCodeSqliteMisuse = 1021,                                        /*!<  */
    AGSErrorCodeSqliteNolfs = 1022,                                         /*!<  */
    AGSErrorCodeSqliteAuth = 1023,                                          /*!<  */
    AGSErrorCodeSqliteFormat = 1024,                                        /*!<  */
    AGSErrorCodeSqliteRange = 1025,                                         /*!<  */
    AGSErrorCodeSqliteNotadb = 1026,                                        /*!<  */
    AGSErrorCodeSqliteNotice = 1027,                                        /*!<  */
    AGSErrorCodeSqliteWarning = 1028,                                       /*!<  */
    AGSErrorCodeSqliteRow = 1029,                                           /*!<  */
    AGSErrorCodeSqliteDone = 1030,                                          /*!<  */
    AGSErrorCodeGeometryCorruptedGeometry = 2001,                           /*!<  */
    AGSErrorCodeGeometryEmptyGeometry = 2002,                               /*!<  */
    AGSErrorCodeGeometryMathSingularity = 2003,                             /*!<  */
    AGSErrorCodeGeometryBufferIsTooSmall = 2004,                            /*!<  */
    AGSErrorCodeGeometryInvalidShapeType = 2005,                            /*!<  */
    AGSErrorCodeGeometryProjectionOutOfSupportedRange = 2006,				/*!<  */
    AGSErrorCodeGeometryNonSimpleGeometry = 2007,                           /*!<  */
    AGSErrorCodeGeometryCannotCalculateGeodesic = 2008,						/*!<  */
    AGSErrorCodeGeometryNotationConversion = 2009,                          /*!<  */
    AGSErrorCodeGeometryMissingGridFile = 2010,                             /*!<  */
    AGSErrorCodeGDBValueOutOfRange = 3001,                                  /*!<  */
    AGSErrorCodeGDBDataTypeMismatch = 3002,                                 /*!<  */
    AGSErrorCodeGDBBadXml = 3003,                                           /*!<  */
    AGSErrorCodeGDBDatabaseAlreadyExists = 3004,                            /*!<  */
    AGSErrorCodeGDBDatabaseDoesNotExist = 3005,                             /*!<  */
    AGSErrorCodeGDBNameLongerThan128Characters = 3006,						/*!<  */
    AGSErrorCodeGDBInvalidShapeType = 3007,                                 /*!<  */
    AGSErrorCodeGDBRasterNotSupported = 3008,                               /*!<  */
    AGSErrorCodeGDBRelationshipClassOneToOne = 3009,						/*!<  */
    AGSErrorCodeGDBItemNotFound = 3010,                                     /*!<  */
    AGSErrorCodeGDBDuplicateCode = 3011,                                    /*!<  */
    AGSErrorCodeGDBMissingCode = 3012,                                      /*!<  */
    AGSErrorCodeGDBWrongItemType = 3013,                                    /*!<  */
    AGSErrorCodeGDBIDFieldNotNullable = 3014,                               /*!<  */
    AGSErrorCodeGDBDefaultValueNotSupported = 3015,                         /*!<  */
    AGSErrorCodeGDBTableNotEditable = 3016,                                 /*!<  */
    AGSErrorCodeGDBFieldNotFound = 3017,                                    /*!<  */
    AGSErrorCodeGDBFieldExists = 3018,                                      /*!<  */
    AGSErrorCodeGDBCannotAlterFieldType = 3019,                             /*!<  */
    AGSErrorCodeGDBCannotAlterFieldWidth = 3020,                            /*!<  */
    AGSErrorCodeGDBCannotAlterFieldToNullable = 3021,						/*!<  */
    AGSErrorCodeGDBCannotAlterFieldToEditable = 3022,						/*!<  */
    AGSErrorCodeGDBCannotAlterFieldToDeletable = 3023,						/*!<  */
    AGSErrorCodeGDBCannotAlterGeometryProperties = 3024,					/*!<  */
    AGSErrorCodeGDBUnnamedTable = 3025,                                     /*!<  */
    AGSErrorCodeGDBInvalidTypeForDomain = 3026,                             /*!<  */
    AGSErrorCodeGDBMinMaxReversed = 3027,                                   /*!<  */
    AGSErrorCodeGDBFieldNotSupportedOnRelationshipClass = 3028,             /*!<  */
    AGSErrorCodeGDBRelationshipClassKey = 3029,                             /*!<  */
    AGSErrorCodeGDBValueIsNull = 3030,                                      /*!<  */
    AGSErrorCodeGDBMultipleSqlStatements = 3031,                            /*!<  */
    AGSErrorCodeGDBNoSqlStatements = 3032,                                  /*!<  */
    AGSErrorCodeGDBGeometryFieldMissing = 3033,                             /*!<  */
    AGSErrorCodeGDBTransactionStarted = 3034,                               /*!<  */
    AGSErrorCodeGDBTransactionNotStarted = 3035,                            /*!<  */
    AGSErrorCodeGDBShapeRequiresZ = 3036,                                   /*!<  */
    AGSErrorCodeGDBShapeRequiresM = 3037,                                   /*!<  */
    AGSErrorCodeGDBShapeNoZ = 3038,                                         /*!<  */
    AGSErrorCodeGDBShapeNoM = 3039,                                         /*!<  */
    AGSErrorCodeGDBShapeWrongType = 3040,                                   /*!<  */
    AGSErrorCodeGDBCannotUpdateFieldType = 3041,                            /*!<  */
    AGSErrorCodeGDBNoRowsAffected = 3042,                                   /*!<  */
    AGSErrorCodeGDBSubtypeInvalid = 3043,                                   /*!<  */
    AGSErrorCodeGDBSubtypeMustBeInteger = 3044,                             /*!<  */
    AGSErrorCodeGDBSubtypesNotEnabled = 3045,                               /*!<  */
    AGSErrorCodeGDBSubtypeExists = 3046,                                    /*!<  */
    AGSErrorCodeGDBDuplicateFieldNotAllowed = 3047,                         /*!<  */
    AGSErrorCodeGDBCannotDeleteField = 3048,                                /*!<  */
    AGSErrorCodeGDBIndexExists = 3049,                                      /*!<  */
    AGSErrorCodeGDBIndexNotFound = 3050,                                    /*!<  */
    AGSErrorCodeGDBCursorNotOnRow = 3051,                                   /*!<  */
    AGSErrorCodeGDBInternalError = 3052,                                    /*!<  */
    AGSErrorCodeGDBCannotWriteGeodatabaseManagedFields = 3053,              /*!<  */
    AGSErrorCodeGDBItemAlreadyExists = 3054,                                /*!<  */
    AGSErrorCodeGDBInvalidSpatialIndexName = 3055,                          /*!<  */
    AGSErrorCodeGDBRequiresSpatialIndex = 3056,                             /*!<  */
    AGSErrorCodeGDBReservedName = 3057,                                     /*!<  */
    AGSErrorCodeGDBCannotUpdateSchemaIfChangeTracking = 3058,				/*!<  */
    AGSErrorCodeGDBInvalidDate = 3059,                                      /*!<  */
    AGSErrorCodeGDBDatabaseDoesNotHaveChanges = 3060,						/*!<  */
    AGSErrorCodeGDBReplicaDoesNotExist = 3061,                              /*!<  */
    AGSErrorCodeGDBStorageTypeNotSupported = 3062,                          /*!<  */
    AGSErrorCodeGDBReplicaModelError = 3063,                                /*!<  */
    AGSErrorCodeGDBReplicaClientGenError = 3064,                            /*!<  */
    AGSErrorCodeGDBReplicaNoUploadToAcknowledge = 3065,						/*!<  */
    AGSErrorCodeGDBLastWriteTimeInTheFuture = 3066,                         /*!<  */
    AGSErrorCodeGDBInvalidArgument = 3067,                                  /*!<  */
    AGSErrorCodeGDBTransportationNetworkCorrupt = 3068,						/*!<  */
    AGSErrorCodeGDBTransportationNetworkFileIO = 3069,						/*!<  */
    AGSErrorCodeGDBFeatureHasPendingEdits = 3070,                           /*!<  */
    AGSErrorCodeGDBChangeTrackingNotEnabled = 3071,                         /*!<  */
    AGSErrorCodeGDBTransportationNetworkFileOpen = 3072,					/*!<  */
    AGSErrorCodeGDBTransportationNetworkUnsupported = 3073,					/*!<  */
    AGSErrorCodeGDBCannotSyncCopy = 3074,                                   /*!<  */
    AGSErrorCodeGDBAccessControlDenied = 3075,                              /*!<  */
    AGSErrorCodeGDBGeometryOutsideReplicaExtent = 3076,                     /*!<  */
    AGSErrorCodeGDBUploadAlreadyInProgress = 3077,                          /*!<  */
    AGSErrorCodeGeocodeUnsupportedFileFormat = 4001,						/*!<  */
    AGSErrorCodeGeocodeUnsupportedSpatialReference = 4002,					/*!<  */
    AGSErrorCodeGeocodeUnsupportedProjectionTransformation = 4003,			/*!<  */
    AGSErrorCodeGeocodeGeocoderCreation = 4004,                             /*!<  */
    AGSErrorCodeGeocodeIntersectionsNotSupported = 4005,					/*!<  */
    AGSErrorCodeGeocodeUninitializedGeocodeTask = 4006,						/*!<  */
    AGSErrorCodeGeocodeInvalidLocatorProperties = 4007,						/*!<  */
    AGSErrorCodeGeocodeRequiredFieldMissing = 4008,                         /*!<  */
    AGSErrorCodeGeocodeCannotReadAddress = 4009,                            /*!<  */
    AGSErrorCodeGeocodeReverseGeocodingNotSupported = 4010,					/*!<  */
    AGSErrorCodeNAInvalidRouteSettings = 5001,                              /*!<  */
    AGSErrorCodeNANoSolution = 5002,                                        /*!<  */
    AGSErrorCodeNATaskCanceled = 5003,                                     /*!<  */
    AGSErrorCodeNAInvalidNetwork = 5004,                                    /*!<  */
    AGSErrorCodeNADirectionsError = 5005,                                   /*!<  */
    AGSErrorCodeNAInsufficientNumberOfStops = 5006,                         /*!<  */
    AGSErrorCodeNAStopUnlocated = 5007,                                     /*!<  */
    AGSErrorCodeNAStopLocatedOnNonTraversableElement = 5008,                /*!<  */
    AGSErrorCodeNAPointBarrierInvalidAddedCostAttributeName = 5009,			/*!<  */
    AGSErrorCodeNALineBarrierInvalidScaledCostAttributeName = 5010,			/*!<  */
    AGSErrorCodeNAPolygonBarrierInvalidScaledCostAttributeName = 5011,		/*!<  */
    AGSErrorCodeNAPolygonBarrierInvalidScaledCostAttributeValue = 5012,     /*!<  */
    AGSErrorCodeNAPolylineBarrierInvalidScaledCostAttributeValue = 5013,    /*!<  */
    AGSErrorCodeNAInvalidImpedanceAttribute = 5014,                         /*!<  */
    AGSErrorCodeNAInvalidRestrictionAttribute = 5015,						/*!<  */
    AGSErrorCodeNAInvalidAccumulateAttribute = 5016,						/*!<  */
    AGSErrorCodeNAInvalidDirectionsTimeAttribute = 5017,					/*!<  */
    AGSErrorCodeNAInvalidDirectionsDistanceAttribute = 5018,				/*!<  */
    AGSErrorCodeNAInvalidAttributeParametersAttributeName = 5019,			/*!<  */
    AGSErrorCodeNAInvalidAttributeParametersParameterName = 5020,			/*!<  */
    AGSErrorCodeNAInvalidAttributeParametersValueType = 5021,				/*!<  */
    AGSErrorCodeNAInvalidAttributeParametersRestrictionUsageValue = 5022,	/*!<  */
    AGSErrorCodeNANetworkHasNoHierarchyAttribute = 5023,					/*!<  */
    AGSErrorCodeNANoPathFoundBetweenStops = 5024,                           /*!<  */
    AGSErrorCodeNAUndefinedInputSpatialReference = 5025,					/*!<  */
    AGSErrorCodeNAUndefinedOutputSpatialReference = 5026,					/*!<  */
    AGSErrorCodeNAInvalidDirectionsStyle = 5027,                            /*!<  */
    AGSErrorCodeNAInvalidDirectionsLanguage = 5028,                         /*!<  */
    AGSErrorCodeNADirectionsTimeAndImpedanceAttributeMismatch = 5029,		/*!<  */
    AGSErrorCodeNAInvalidDirectionsRoadClassAttribute = 5030,				/*!<  */
    AGSErrorCodeNAStopIsUnreachable = 5031,                                 /*!<  */
    AGSErrorCodeNAStopTimeWindowStartsBeforeUnixEpoch = 5032,               /*!<  */
    AGSErrorCodeNAStopTimeWindowIsInverted = 5033,                          /*!<  */
    AGSErrorCodeNAWalkingModeRouteTooLarge = 5034,                          /*!<  */
    AGSErrorCodeNAStopHasNullGeometry = 5035,                               /*!<  */
    AGSErrorCodeNAPointBarrierHasNullGeometry = 5036,                       /*!<  */
    AGSErrorCodeNAPolylineBarrierHasNullGeometry = 5037,                    /*!<  */
    AGSErrorCodeNAPolygonBarrierHasNullGeometry = 5038,                     /*!<  */
    AGSErrorCodeNAUnsupportedSearchWhereClause = 5039,                      /*!<  */
    AGSErrorCodeNAInsufficientNumberOfFacilities = 5040,                    /*!<  */
    AGSErrorCodeNAFacilityHasNullGeometry = 5041,                           /*!<  */
    AGSErrorCodeNAFacilityHasInvalidAddedCostAttributeName = 5042,          /*!<  */
    AGSErrorCodeNAFacilityHasNegativeAddedCostAttribute = 5043,             /*!<  */
    AGSErrorCodeNAFacilityHasInvalidImpedanceCutoff = 5044,                 /*!<  */
    AGSErrorCodeNAInsufficientNumberOfIncidents = 5045,                     /*!<  */
    AGSErrorCodeNAIncidentHasNullGeometry = 5046,                           /*!<  */
    AGSErrorCodeNAIncidentHasInvalidAddedCostAttributeName = 5047,          /*!<  */
    AGSErrorCodeNAIncidentHasNegativeAddedCostAttribute = 5048,             /*!<  */
    AGSErrorCodeNAInvalidTargetFacilityCount = 5049,                        /*!<  */
    AGSErrorCodeNAIncidentHasInvalidImpedanceCutoff = 5050,                 /*!<  */
    AGSErrorCodeNAStartTimeIsBeforeUnixEpoch = 5051,                        /*!<  */
    AGSErrorCodeNAInvalidDefaultImpedanceCutoff = 5052,                     /*!<  */
    AGSErrorCodeNAInvalidDefaultTargetFacilityCount = 5053,                 /*!<  */
    AGSErrorCodeNAInvalidPolygonBufferDistance = 5054,                      /*!<  */
    AGSErrorCodeNAPolylinesCannotBeReturned = 5055,                         /*!<  */
    AGSErrorCodeNATimeWindowsWithNonTimeImpedance = 5056,                   /*!<  */
    AGSErrorCodeJSONParserInvalidToken = 6001,                              /*!<  */
    AGSErrorCodeJSONParserInvalidCharacter = 6002,                          /*!<  */
    AGSErrorCodeJSONParserInvalidUnicode = 6003,                            /*!<  */
    AGSErrorCodeJSONParserInvalidJSONStart = 6004,                          /*!<  */
    AGSErrorCodeJSONParserInvalidEndOfPair = 6005,                          /*!<  */
    AGSErrorCodeJSONParserInvalidEndOfElement = 6006,                       /*!<  */
    AGSErrorCodeJSONParserInvalidEscapeSequence = 6007,                     /*!<  */
    AGSErrorCodeJSONParserInvalidEndOfFieldName = 6008,                     /*!<  */
    AGSErrorCodeJSONParserInvalidStartOfFieldName = 6009,                   /*!<  */
    AGSErrorCodeJSONParserInvalidStartOfComment = 6010,                     /*!<  */
    AGSErrorCodeJSONParserInvalidDecDigit = 6011,                           /*!<  */
    AGSErrorCodeJSONParserInvalidHexDigit = 6012,                           /*!<  */
    AGSErrorCodeJSONParserExpectingNull = 6013,                             /*!<  */
    AGSErrorCodeJSONParserExpectingTrue = 6014,                             /*!<  */
    AGSErrorCodeJSONParserExpectingFalse = 6015,                            /*!<  */
    AGSErrorCodeJSONParserExpectingClosingQuote = 6016,                     /*!<  */
    AGSErrorCodeJSONParserExpectingNan = 6017,                              /*!<  */
    AGSErrorCodeJSONParserExpectingEndOfComment = 6018,                     /*!<  */
    AGSErrorCodeJSONParserUnexpectedEndOfData = 6019,                       /*!<  */
    AGSErrorCodeJSONObjectExpectingStartObject = 6020,                      /*!<  */
    AGSErrorCodeJSONObjectExpectingStartArray = 6021,                       /*!<  */
    AGSErrorCodeJSONObjectExpectingValueObject = 6022,                      /*!<  */
    AGSErrorCodeJSONObjectExpectingValueArray = 6023,                       /*!<  */
    AGSErrorCodeJSONObjectExpectingValueInt32 = 6024,                       /*!<  */
    AGSErrorCodeJSONObjectExpectingIntegerType = 6025,                      /*!<  */
    AGSErrorCodeJSONObjectExpectingNumberType = 6026,                       /*!<  */
    AGSErrorCodeJSONObjectExpectingValueString = 6027,                      /*!<  */
    AGSErrorCodeJSONObjectExpectingValueBool = 6028,                        /*!<  */
    AGSErrorCodeJSONObjectIteratorNotStarted = 6029,                        /*!<  */
    AGSErrorCodeJSONObjectIteratorIsFinished = 6030,                        /*!<  */
    AGSErrorCodeJSONObjectKeyNotFound = 6031,                               /*!<  */
    AGSErrorCodeJSONObjectIndexOutOfRange = 6032,                           /*!<  */
    AGSErrorCodeJSONStringWriterJSONIsComplete = 6033,                      /*!<  */
    AGSErrorCodeJSONStringWriterInvalidJSONInput = 6034,                    /*!<  */
    AGSErrorCodeJSONStringWriterExpectingContainer = 6035,                  /*!<  */
    AGSErrorCodeJSONStringWriterExpectingKeyOrEndObject = 6036,             /*!<  */
    AGSErrorCodeJSONStringWriterExpectingValueOrEndArray = 6037,            /*!<  */
    AGSErrorCodeJSONStringWriterExpectingValue = 6038,                      /*!<  */
    AGSErrorCodeMappingMissingSpatialReference = 7001,                      /*!<  */
    AGSErrorCodeMappingMissingInitialViewpoint = 7002,                      /*!<  */
    AGSErrorCodeMappingInvalidResponse = 7003,                              /*!<  */
    AGSErrorCodeMappingMissingBingMapKey = 7004,                            /*!<  */
    AGSErrorCodeMappingUnsupportedLayerType = 7005,                         /*!<  */
    AGSErrorCodeMappingSyncNotEnabled = 7006,                               /*!<  */
    AGSErrorCodeMappingTileExportNotEnabled = 7007,                         /*!<  */
    AGSErrorCodeMappingMissingItemProperty = 7008,                          /*!<  */
    AGSErrorCodeMappingWebmapNotSupported = 7009,                           /*!<  */
    AGSErrorCodeLicensingUnlicensedFeature = 8001,                          /*!<  */
    AGSErrorCodeLicensingLicenseLevelFixed = 8002,                          /*!<  */
    AGSErrorCodeLicensingLicenseLevelAlreadySet = 8003,                     /*!<  */
    AGSErrorCodeLicensingMainLicenseNotSet = 8004,                          /*!<  */
    AGSErrorCodeLicensingUnlicensedExtension = 8005,                        /*!<  */
    AGSErrorCodeLocalServerServerFailedToStart = 9001,                      /*!<  */
    AGSErrorCodeLocalServerServiceFailedToStart = 9002,                     /*!<  */
    AGSErrorCodeLocalServerServiceTerminatedUnexpectedly = 9003,            /*!<  */
    AGSErrorCodeLocalServerServerFailed = 9004,                             /*!<  */
    AGSErrorCodeLocalServerServiceFailed = 9005,                            /*!<  */
    AGSErrorCodeStdIosBaseFailure = 10001,                                  /*!<  */
    AGSErrorCodeStdBadArrayNewLength = 10002,                               /*!<  */
    AGSErrorCodeStdUnderflowError = 10003,                                  /*!<  */
    AGSErrorCodeStdSystemError = 10004,                                     /*!<  */
    AGSErrorCodeStdRangeError = 10005,                                      /*!<  */
    AGSErrorCodeStdOverflowError = 10006,                                   /*!<  */
    AGSErrorCodeStdOutOfRange = 10007,                                      /*!<  */
    AGSErrorCodeStdLengthError = 10008,                                     /*!<  */
    AGSErrorCodeStdInvalidArgument = 10009,                                 /*!<  */
    AGSErrorCodeStdFutureError = 10010,                                     /*!<  */
    AGSErrorCodeStdDomainError = 10011,                                     /*!<  */
    AGSErrorCodeStdRuntimeError = 10012,                                    /*!<  */
    AGSErrorCodeStdLogicError = 10013,                                      /*!<  */
    AGSErrorCodeStdBadWeakPtr = 10014,                                      /*!<  */
    AGSErrorCodeStdBadTypeId = 10015,                                       /*!<  */
    AGSErrorCodeStdBadFunctionCall = 10016,                                 /*!<  */
    AGSErrorCodeStdBadException = 10017,                                    /*!<  */
    AGSErrorCodeStdBadCast = 10018,                                         /*!<  */
    AGSErrorCodeStdBadAlloc = 10019,                                        /*!<  */
    AGSErrorCodeStdException = 10020,                                       /*!<  */
};

/** Constant representing domain for popup validation errors.
 @since 100
 */
AGS_EXTERN NSString *const AGSPopupValidationErrorDomain;

/** Constants representing popup validation error codes. These errors belongs to  AGSPopupValidationErrorDomain.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupValidationErrorCode) {
    AGSPopupValidationErrorCodeInvalidGeoElement = 11000,          /*!< Invalid attributes or geometry on the associated AGSGeoElement */
    AGSPopupValidationErrorCodeNullNotAllowed = 11001,          /*!< Null value not allowed */
    AGSPopupValidationErrorCodeValueOutOfRange = 11002,         /*!< Value out of range */
    AGSPopupValidationErrorExceedsMaxLength = 11003             /*!< Value exceeds maximum field length */
};

/** The edit state of attachments in an AGSPopupAttachmentManager.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupAttachmentEditState) {
    AGSPopupAttachmentEditStateOriginal = 0,    /*!<  */
    AGSPopupAttachmentEditStateAdded,           /*!<  */
    AGSPopupAttachmentEditStateDeleted,         /*!<  */
};

/** The type of attachments in an AGSPopupAttachmentManager.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupAttachmentType) {
    AGSPopupAttachmentTypeImage = 0,/*!< Any attachment whose MIME type contains 'image' prefix */
    AGSPopupAttachmentTypeVideo,    /*!< Any attachment whose MIME type contains 'video' prefix */
    AGSPopupAttachmentTypeDocument, /*!< PDF, MS-Word, MS-Excel, MS-Powerpoint, HTML */
    AGSPopupAttachmentTypeOther     /*!< */
};

/** Size options for an image attachment
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupAttachmentSize) {
    AGSPopupAttachmentSizeActual = 0,        /*!<  full resolution */
    AGSPopupAttachmentSizeSmall,             /*!<  240x320 */
    AGSPopupAttachmentSizeMedium,            /*!<  480x640 */
    AGSPopupAttachmentSizeLarge,             /*!<  960x1280 */
    AGSPopupAttachmentSizeExtraLarge,        /*!<  1126x1500 */
};

#pragma mark - Portal

/** The type of content represented by the local item
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLocalItemType) {
    AGSLocalItemTypeUnknown = -1,           /*!<  */
    AGSLocalItemTypeMobileMap = 0,          /*!<  */
    AGSLocalItemTypeMobileScene = 1,        /*!<  */
    AGSLocalItemTypeMobileMapPackage = 2    /*!<  */
};


/** The type of content represented by the portal item
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalItemType) {
    AGSPortalItemTypeUnknown = -1,                      /*!<  */
    AGSPortalItemTypeArcGISProAddIn = 0,                /*!<  */
    AGSPortalItemTypeArcPadPackage = 1,					/*!<  */
    AGSPortalItemTypeCADDrawing = 2,                    /*!<  */
    AGSPortalItemTypeCSV = 3,							/*!<  */
    AGSPortalItemTypeCityEngineWebScene = 4,			/*!<  */
    AGSPortalItemTypeCodeAttachment = 5,				/*!<  */
    AGSPortalItemTypeCodeSample = 6,					/*!<  */
    AGSPortalItemTypeColorSet = 7,						/*!<  */
    AGSPortalItemTypeDesktopAddIn = 8,					/*!<  */
    AGSPortalItemTypeDesktopApplication = 9,            /*!<  */
    AGSPortalItemTypeDesktopApplicationTemplate = 10,	/*!<  */
    AGSPortalItemTypeDesktopStyle = 11,                 /*!<  */
    AGSPortalItemTypeDocumentLink = 12,					/*!<  */
    AGSPortalItemTypeExplorerAddIn = 13,				/*!<  */
    AGSPortalItemTypeExplorerLayer = 14,				/*!<  */
    AGSPortalItemTypeExplorerMap = 15,					/*!<  */
    AGSPortalItemTypeFeatureCollection = 16,			/*!<  */
    AGSPortalItemTypeFeatureCollectionTemplate = 17,	/*!<  */
    AGSPortalItemTypeFeatureService = 18,				/*!<  */
    AGSPortalItemTypeFileGeodatabase = 19,              /*!<  */
    AGSPortalItemTypeForm = 20,                         /*!<  */
    AGSPortalItemTypeGeocodingService = 21,				/*!<  */
    AGSPortalItemTypeGeodataService = 22,				/*!<  */
    AGSPortalItemTypeGeometryService = 23,				/*!<  */
    AGSPortalItemTypeGeoprocessingPackage = 24,			/*!<  */
    AGSPortalItemTypeGeoprocessingPackageProVersion = 25,/*!<  */
    AGSPortalItemTypeGeoprocessingSample = 26,			/*!<  */
    AGSPortalItemTypeGeoprocessingService = 27,			/*!<  */
    AGSPortalItemTypeGlobeDocument = 28,				/*!<  */
    AGSPortalItemTypeGlobeService = 29,					/*!<  */
    AGSPortalItemTypeImage = 30,						/*!<  */
    AGSPortalItemTypeImageCollection = 31,              /*!<  */
    AGSPortalItemTypeImageService = 32,					/*!<  */
    AGSPortalItemTypeInsightsModel = 33,                /*!<  */
    AGSPortalItemTypeInsightsPage = 34,                 /*!<  */
    AGSPortalItemTypeInsightsWorkbook = 35,             /*!<  */
    AGSPortalItemTypeIWorkKeynote = 36,                 /*!<  */
    AGSPortalItemTypeIWorkNumbers = 37,                 /*!<  */
    AGSPortalItemTypeIWorkPages = 38,                   /*!<  */
    AGSPortalItemTypeKML = 39,							/*!<  */
    AGSPortalItemTypeKMLCollection = 40,                /*!<  */
    AGSPortalItemTypeLayer = 41,						/*!<  */
    AGSPortalItemTypeLayerPackage = 42,					/*!<  */
    AGSPortalItemTypeLayout = 43,                       /*!<  */
    AGSPortalItemTypeLocatorPackage = 44,				/*!<  */
    AGSPortalItemTypeMapDocument = 45,					/*!<  */
    AGSPortalItemTypeMapPackage = 46,					/*!<  */
    AGSPortalItemTypeMapService = 47,					/*!<  */
    AGSPortalItemTypeMapTemplate = 48,					/*!<  */
    AGSPortalItemTypeMicrosoftExcel = 49,				/*!<  */
    AGSPortalItemTypeMicrosoftPowerpoint = 50,          /*!<  */
    AGSPortalItemTypeMicrosoftWord = 51,				/*!<  */
    AGSPortalItemTypeMobileApplication = 52,			/*!<  */
    AGSPortalItemTypeMobileBasemapPackage = 53,         /*!<  */
    AGSPortalItemTypeMobileMapPackage = 54,				/*!<  */
    AGSPortalItemTypeNativeApplication = 55,            /*!<  */
    AGSPortalItemTypeNativeApplicationInstaller = 56,   /*!<  */
    AGSPortalItemTypeNativeApplicationTemplate = 57,    /*!<  */
    AGSPortalItemTypeNetCDF = 58,                       /*!<  */
    AGSPortalItemTypeNetworkAnalysisService = 59,		/*!<  */
    AGSPortalItemTypeOperationView = 60,				/*!<  */
    AGSPortalItemTypeOperationsDashboardAddIn = 61,		/*!<  */
    AGSPortalItemTypeOperationsDashboardExtension = 62, /*!<  */
    AGSPortalItemTypePDF = 63,							/*!<  */
    AGSPortalItemTypeProjectPackage = 64,               /*!<  */
    AGSPortalItemTypeProjectTemplate = 65,              /*!<  */
    AGSPortalItemTypeProMap = 66,                       /*!<  */
    AGSPortalItemTypePublishedMap = 67,					/*!<  */
    AGSPortalItemTypeRasterFunctionTemplate = 68,       /*!<  */
    AGSPortalItemTypeRelationalDatabaseConnection = 69, /*!<  */
    AGSPortalItemTypeReportTemplate = 70,               /*!<  */
    AGSPortalItemTypeRulePackage = 71,                  /*!<  */
    AGSPortalItemTypeSceneDocument = 72,				/*!<  */
    AGSPortalItemTypeScenePackage = 73,                 /*!<  */
    AGSPortalItemTypeSceneService = 74,                 /*!<  */
    AGSPortalItemTypeServiceDefinition = 75,			/*!<  */
    AGSPortalItemTypeShapeFile = 76,					/*!<  */
    AGSPortalItemTypeStatisticalDataCollection = 77,    /*!<  */
    AGSPortalItemTypeSymbolSet = 78,					/*!<  */
    AGSPortalItemTypeTaskFile = 79,                     /*!<  */
    AGSPortalItemTypeTilePackage = 80,					/*!<  */
    AGSPortalItemTypeVectorTilePackage = 81,			/*!<  */
    AGSPortalItemTypeVectorTileService = 82,			/*!<  */
    AGSPortalItemTypeVisioDocument = 83,				/*!<  */
    AGSPortalItemTypeVr360Experience = 84,              /*!<  */
    AGSPortalItemTypeWFS = 85,                          /*!<  */
    AGSPortalItemTypeWMS = 86,							/*!<  */
    AGSPortalItemTypeWMTS = 87,							/*!<  */
    AGSPortalItemTypeWebMap = 88,						/*!<  */
    AGSPortalItemTypeWebMappingApplication = 89,		/*!<  */
    AGSPortalItemTypeWebScene = 90,                     /*!<  */
    AGSPortalItemTypeWindowsMobilePackage = 91,			/*!<  */
    AGSPortalItemTypeWorkflowManagerPackage = 92,		/*!<  */
    AGSPortalItemTypeWorkflowManagerService = 93,       /*!<  */
    AGSPortalItemTypeWorkforceProject = 94				/*!<  */
};



/** Access types on Portal, Item, Group or User.

 <b> For Portal or Organization </b>

 Determines who can view your organization as an anonymous user. <code>AGSPortalAccessPublic</code>
 means it allows anonymous users to access your organization's custom URL. <code>AGSPortalAccessPrivate </code> restricts access to only members of your organization.

 <b> For Portal Item </b>

 Indicates the access level of the item. If <code>AGSPortalAccessPrivate</code>, only the item owner can
 access. <code>AGSPortalAccessShared</code> allows the item to be shared with a specific group. <code>
 AGSPortalAccessOrganization</code> restricts item access to members of your organization. If <code>
 AGSPortalAccessPublic</code>, all users can access the item.

 <b> For Portal Group </b>

 Determines who can access the group. <code>AGSPortalAccessPrivate</code> gives access to only the group
 members. If <code>AGSPortalAccessOrganization</code>, all members of this organization can access the
 group. <code>AGSPortalAccessPublic</code> makes the group accessible to all.

 <b> For Portal User </b>

 Determines if other users can search for this user's name to find content and groups owned by this user
 and to invite this user to join their groups. <code>AGSPortalAccessPrivate</code> hides the user from
 user searches and invites. If <code>AGSPortalAccessOrganization</code>, only members of this user's
 organization can search for this user, the content and groups. <code>AGSPortalAccessPublic</code> makes
 the user findable.

 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalAccess) {
    AGSPortalAccessUnknown = -1,
    AGSPortalAccessOrganization = 0,                    /*!< Applicable for Items, Groups and Users  */
    AGSPortalAccessPrivate = 1,                     /*!< Applicable for All  */
    AGSPortalAccessPublic = 2,                           /*!< Applicable for All  */
    AGSPortalAccessShared = 3                          /*!< Applicable for only Items  */
};

/** Indicates the order of results of the portal query.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalQuerySortOrder){
	AGSPortalQuerySortOrderAscending = 0,   	/*!< Ascending */
	AGSPortalQuerySortOrderDescending,			/*!< Descending */
} ;


/** Indicating whether the portal contains multiple organizations or not.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalMode) {
	AGSPortalModeSingleTenant = 0,   	/*!< Only one organization*/
	AGSPortalModeMultiTenant,			/*!< Multiple organizations*/
} ;

/** Indicates the role of the portal user within an organization.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalUserRole) {
    AGSPortalUserRoleUnknown = 0,           /*!< The user does not belong to an organization */
    AGSPortalUserRoleUser,                  /*!< Information worker */
    AGSPortalUserRolePublisher,             /*!< Publisher */
    AGSPortalUserRoleAdmin,                 /*!< Administrator */
} ;

/** Indicates the desired sorting criterion for group items.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalGroupSortField) {
	AGSPortalGroupSortFieldTitle = 0,       /*!< Title */
	AGSPortalGroupSortFieldOwner,           /*!< Ownder */
	AGSPortalGroupSortFieldAvgRating,       /*!< Average Rating */
	AGSPortalGroupSortFieldNumViews,        /*!< Number of Views */
	AGSPortalGroupSortFieldCreated,         /*!< Created Date */
	AGSPortalGroupSortFieldModified,        /*!< Modified Date */
} ;

/** Supported login types for portal.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalLoginType) {
    AGSPortalLoginTypeOAuth = 0,                   /*!<  */
    AGSPortalLoginTypeClientCertificate,           /*!<  */
    AGSPortalLoginTypeUsernamePassword,            /*!<  */
    AGSPortalLoginTypeUnknown,                     /*!<  */
} ;

/** Loading status of an object implementing `<AGSLoadable>` protocol.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLoadStatus) {
    AGSLoadStatusLoaded = 0,            /*!< Loading completed successfully */
    AGSLoadStatusLoading = 1,           /*!< Loading in progress */
    AGSLoadStatusFailedToLoad = 2,      /*!< Loading completed with error */
    AGSLoadStatusNotLoaded = 3,         /*!< Loading not started */
    AGSLoadStatusUnknown = -1           /*!< Unknwon */
} ;

#pragma mark - Portal Privileges

/** Supported portal privilege realms.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalPrivilegeRealm) {
    AGSPortalPrivilegeRealmUnknown = 0,         /*!<  */
    AGSPortalPrivilegeRealmFeatures,            /*!<  */
    AGSPortalPrivilegeRealmMarketplace,         /*!<  */
    AGSPortalPrivilegeRealmOpenData,            /*!<  */
    AGSPortalPrivilegeRealmPortal,              /*!<  */
    AGSPortalPrivilegeRealmPremium,             /*!<  */
};

/** Supported portal privilege roles.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalPrivilegeRole) {
    AGSPortalPrivilegeRoleUnknown = 0,          /*!<  */
    AGSPortalPrivilegeRoleUser,                 /*!<  */
    AGSPortalPrivilegeRoleAdmin,                /*!<  */
    AGSPortalPrivilegeRolePublisher,            /*!<  */
};

/** Supported portal privilege types.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalPrivilegeType) {
    AGSPortalPrivilegeTypeUnknown = 0,          /*!<  */
    AGSPortalPrivilegeTypeEdit,                 /*!<  */
    AGSPortalPrivilegeTypeFullEdit,             /*!<  */
    AGSPortalPrivilegeTypeManage,               /*!<  */
    AGSPortalPrivilegeTypePurchase,             /*!<  */
    AGSPortalPrivilegeTypeStartTrial,           /*!<  */
    AGSPortalPrivilegeTypeDesignateGroup,       /*!<  */
    AGSPortalPrivilegeTypeOpenDataAdmin,        /*!<  */
    AGSPortalPrivilegeTypeAssignToGroups,       /*!<  */
    AGSPortalPrivilegeTypeManageEnterpriseGroups,/*!<  */
    AGSPortalPrivilegeTypeChangeUserRoles,      /*!<  */
    AGSPortalPrivilegeTypeDeleteGroups,         /*!<  */
    AGSPortalPrivilegeTypeDeleteItems,          /*!<  */
    AGSPortalPrivilegeTypeDeleteUsers,          /*!<  */
    AGSPortalPrivilegeTypeDisableUsers,         /*!<  */
    AGSPortalPrivilegeTypeInviteUsers,          /*!<  */
    AGSPortalPrivilegeTypeManageLicenses,       /*!<  */
    AGSPortalPrivilegeTypeReassignGroups,       /*!<  */
    AGSPortalPrivilegeTypeReassignItems,        /*!<  */
    AGSPortalPrivilegeTypeReassignUsers,        /*!<  */
    AGSPortalPrivilegeTypeUpdateGroups,         /*!<  */
    AGSPortalPrivilegeTypeUpdateItems,          /*!<  */
    AGSPortalPrivilegeTypeUpdateUsers,          /*!<  */
    AGSPortalPrivilegeTypeViewGroups,           /*!<  */
    AGSPortalPrivilegeTypeViewItems,            /*!<  */
    AGSPortalPrivilegeTypeViewUsers,            /*!<  */
    AGSPortalPrivilegeTypePublishFeatures,      /*!<  */
    AGSPortalPrivilegeTypePublishTiles,         /*!<  */
    AGSPortalPrivilegeTypePublishScenes,        /*!<  */
    AGSPortalPrivilegeTypeCreateGroup,          /*!<  */
    AGSPortalPrivilegeTypeCreateItem,           /*!<  */
    AGSPortalPrivilegeTypeJoinGroup,            /*!<  */
    AGSPortalPrivilegeTypeJoinNonOrgGroup,      /*!<  */
    AGSPortalPrivilegeTypeShareGroupToOrg,      /*!<  */
    AGSPortalPrivilegeTypeShareGroupToPublic,   /*!<  */
    AGSPortalPrivilegeTypeShareToGroup,         /*!<  */
    AGSPortalPrivilegeTypeShareToOrg,           /*!<  */
    AGSPortalPrivilegeTypeShareToPublic,        /*!<  */
    AGSPortalPrivilegeTypeDemographics,         /*!<  */
    AGSPortalPrivilegeTypeElevation,            /*!<  */
    AGSPortalPrivilegeTypeGeocode,              /*!<  */
    AGSPortalPrivilegeTypeGeoEnrichment,        /*!<  */
    AGSPortalPrivilegeTypeNetworkAnalysis,      /*!<  */
    AGSPortalPrivilegeTypeSpatialAnalysis       /*!<  */
};

#pragma mark - popups

/** Style options for the Popups VC
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupsViewControllerContainerStyle) {
    AGSPopupsViewControllerContainerStyleNavigationController,  /*!< The popups view controller will be pushed onto a navigation controller stack by the client */
    AGSPopupsViewControllerContainerStyleNavigationBar,         /*!< The popups view controller will add a navigation bar for the client (useful for when presenting modally) */
    AGSPopupsViewControllerContainerStyleCustom                 /*!< The popups view controller will be embedded in a custom container by the client, who is then responsible for having an edit button */
};

/** Options specifying how to handle existing field values when a feature's type is changed.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupFeatureTypeChangeMode) {
    AGSPopupFeatureTypeChangeModeResetDefaultValues = 0,        /*!< Reset all fields to default values when feature type is changed */
    AGSPopupFeatureTypeChangeModeKeepValues = 1                 /*!< Keep existing field values even when the feature type is changed */
};

/** An enumeration that is used for defining the editing style of an AGSPopupsViewController.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupsViewControllerGeometryEditingStyle) {
	AGSPopupsViewControllerGeometryEditingStyleToolbar,     /*!< Shows a toolbar with a button for attachments and a button for collecting the geometry */
	AGSPopupsViewControllerGeometryEditingStyleInline    /*!< Has a view to switch between attributes and attachments.
                                                     There is no button for the collecting the geometry, as this is assumed
                                                     the user has access to the map while the popup is up (think ipad), or
                                                     the user will not be collecting a geometry at all. */
};

/** Enumeration that specifies how date fields are formatted in an AGSPopup.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupDateFormat) {
    AGSPopupDateFormatDayShortMonthYear = 0,           /*!< Date with d, MMM yyyy */
    AGSPopupDateFormatLongDate = 1,                    /*!< Date with NSDateFormatterFullStyle */
    AGSPopupDateFormatLongMonthDayYear = 2,            /*!< Date with  NSDateFormatterLongStyle */
    AGSPopupDateFormatLongMonthYear = 3,               /*!< Date with MMMM yyyy */
    AGSPopupDateFormatShortDate = 4,                   /*!< Date with NSDateFormatterShortStyle */
    AGSPopupDateFormatShortDateLE = 5,                 /*!< Date with d/M/yyyy */
    AGSPopupDateFormatShortDateLELongTime = 6,         /*!< Date with d/M/yyyy h:mm:ss a */
    AGSPopupDateFormatShortDateLELongTime24 = 7,       /*!< Date with d/M/yyyy HH:mm:ss */
    AGSPopupDateFormatShortDateLEShortTime = 8,        /*!< Date with d/M/yyyy h:mm */
    AGSPopupDateFormatShortDateLEShortTime24 = 9,      /*!< Date with d/M/yyyy HH:mm */
    AGSPopupDateFormatShortDateLongTime = 10,          /*!< Date with NSDateFormatterShortStyle Time with NSDateFormatterMediumStyle */
    AGSPopupDateFormatShortDateLongTime24 = 11,        /*!< Date with M/d/yyyy HH:mm:ss */
    AGSPopupDateFormatShortDateShortTime = 12,         /*!< Date & Time with NSDateFormatterShortStyle */
    AGSPopupDateFormatShortDateShortTime24 = 13,       /*!< Date with M/d/yyyy HH:mm */
    AGSPopupDateFormatShortMonthYear = 14,             /*!< Date with MMM yyyy */
    AGSPopupDateFormatYear = 15,                       /*!< Date with yyyy */
    AGSPopupDateFormatUnknown = -1,
};

/** Enumeration that specifies different types of media in an AGSPopup.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupMediaType){
    AGSPopupMediaTypeImage = 0,                       /*!< Image */
    AGSPopupMediaTypeBarChart = 1,                    /*!< Bar Chart */
    AGSPopupMediaTypeColumnChart = 2,                 /*!< Column Chart */
    AGSPopupMediaTypeLineChart = 3,                   /*!< Line Chart */
    AGSPopupMediaTypePieChart = 4,                    /*!< Pie Chart */
    AGSPopupMediaTypeUnknown = -1                     /*!< Unknown */
};

/** The type of view within  AGSPopupsViewController
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupViewControllerType){
    AGSPopupViewControllerTypeContainer = 0,  /*!< The default starting view controller */
    AGSPopupViewControllerTypeUIImagePicker,  /*!< View controller that displays the AGSImagePicker */
    AGSPopupViewControllerTypeFullMedia,      /*!< View controller that displays a single media item (image/chart)  */
    AGSPopupViewControllerTypeWeb,            /*!< View controller that displays an embedded UIWebView */
    AGSPopupViewControllerTypeMovie,          /*!< View controller that displays movies */
    AGSPopupViewControllerTypeAttributeInput,  /*!< View controller that displays interface for inputting an attribute value */
    AGSPopupViewControllerTypeAlert           /*!< View controller of type UIAlertController */
};

/** Options for string fields in AGSPopupsViewController
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupStringFieldOption) {
    AGSPopupStringFieldOptionSingleLine = 0,        /*!<  */
    AGSPopupStringFieldOptionMultiLine = 1,         /*!<  */
    AGSPopupStringFieldOptionRichText = 2,          /*!<  */
    AGSPopupStringFieldOptionUnknown = -1,          /*!<  */
};

#pragma mark - License

/** Status for license operations
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLicenseStatus) {
    AGSLicenseStatusInvalid = 0,                /*!< License is invalid */
    AGSLicenseStatusExpired	= 1,	    		/*!< License has expired */
    AGSLicenseStatusLoginRequired = 2,          /*!< License has passed the 30-day timeout period for a named user. User will need to login in again */
    AGSLicenseStatusValid = 3					/*!< License is valid */
};

/** Available license levels
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLicenseLevel) {
    AGSLicenseLevelDeveloper = 0,           /*!< No license set. Application will run in developer mode. Full functionality but with a watermarked view. Not suitable for production deployment. */
    AGSLicenseLevelLite = 1,                /*!< Lite license set. No watermark. Functionality available at the lowest level.*/
    AGSLicenseLevelBasic = 2,				/*!< Basic license set. No watermark. Functionality available at the basic level. */
    AGSLicenseLevelStandard = 3,			/*!< Standard license set. No watermark. Functionality available at the standard level. */
    AGSLicenseLevelAdvanced = 4             /*!< Advanced license set. No watermark. Functionality available at the advanced level.*/
};

/** The type of license being used by the application.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLicenseType) {
    AGSLicenseTypeDeveloper = 0,             /*!< A license has not been set and application is running in developer mode. Not suitable for production deployment.*/
    AGSLicenseTypeNamedUser = 1,             /*!< Using a subscription license from a named user account.*/
    AGSLicenseTypeLicenseKey = 2             /*!< Licensed from a license key.*/
};

#pragma mark - Load status

/** Return load status for status string.
 @param loadStatus The string representation of a load status.
 @return  AGSLoadStatus for @p loadStatus string.
 @since 100
 @see AGSLoadStatus
 */
AGS_EXTERN AGSLoadStatus AGSLoadStatusFromString(NSString *loadStatus);

/** Return load status string for  AGSLoadStatus.
 @param loadStatus The load status.
 @return String representation of @p loadStatus.
 @since 100
 @see AGSLoadStatus
 */
AGS_EXTERN NSString *AGSLoadStatusAsString(AGSLoadStatus loadStatus);




#pragma mark - Mapping

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSBasemapType) {
    AGSBasemapTypeImagery = 0,                  /*!< */
    AGSBasemapTypeImageryWithLabels = 1,        /*!< */
    AGSBasemapTypeStreets = 2,                  /*!< */
    AGSBasemapTypeTopographic = 3,              /*!< */
    AGSBasemapTypeTerrainWithLabels = 4,        /*!< */
    AGSBasemapTypeLightGrayCanvas = 5,          /*!< */
    AGSBasemapTypeNationalGeographic = 6,       /*!< */
    AGSBasemapTypeOceans = 7,                   /*!< */
    AGSBasemapTypeImageryWithLabelsVector = 9,  /*!< */
    AGSBasemapTypeStreetsVector = 10,           /*!< */
    AGSBasemapTypeTopographicVector = 11,       /*!< */
    AGSBasemapTypeTerrainWithLabelsVector = 12, /*!< */
    AGSBasemapTypeLightGrayCanvasVector = 13,   /*!< */
    AGSBasemapTypeNavigationVector = 14,        /*!< */
    AGSBasemapTypeStreetsNightVector = 15,      /*!< */
    AGSBasemapTypeStreetsWithReliefVector = 16, /*!< */
    AGSBasemapTypeDarkGrayCanvasVector = 17     /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGridType){
    AGSGridTypeNone = 0,            /*!< */
    AGSGridTypeMGRS = 1,            /*!< */
    AGSGridTypeUnknown = -1         /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSBingMapLayerStyle){
    AGSBingMapLayerStyleAerial = 0,     /*!< */
    AGSBingMapLayerStyleHybrid = 1,     /*!< */
    AGSBingMapLayerStyleRoad = 2        /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSDrawStatus) {
    AGSDrawStatusInProgress = 0,    /*!< */
    AGSDrawStatusCompleted = 1,     /*!< */
};

/** The status could be a combination of any of these individual states
 @since 100
 */
typedef NS_OPTIONS(NSInteger, AGSLayerViewStatus) {
    AGSLayerViewStatusActive = 1 << 0,       /*!< */
    AGSLayerViewStatusNotVisible = 1 << 1,   /*!< */
    AGSLayerViewStatusOutOfScale = 1 << 2,   /*!< */
    AGSLayerViewStatusLoading = 1 << 3,      /*!< */
    AGSLayerViewStatusError = 1 << 4        /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSWrapAroundMode) {
    AGSWrapAroundModeEnabledWhenSupported = 0,  /*!< */
    AGSWrapAroundModeDisabled = 1,              /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSViewpointType) {
    AGSViewpointTypeCenterAndScale = 0,         /*!< */
    AGSViewpointTypeBoundingGeometry = 1,       /*!< */
    AGSViewpointTypeUnknown = -1,               /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSCacheStorageFormat)
{
    AGSCacheStorageFormatCompact = 0,       /*!<  */
    AGSCacheStorageFormatCompactV2 = 1,     /*!<  */
    AGSCacheStorageFormatExploded = 2,      /*!<  */
    AGSCacheStorageFormatUnknown = -1       /*!<  */
};

/** Represents options for positioning grid labels on screen. `AGSGridLabelPositionGeographic`  means labels are anchored to a
 geographical position on the map, whereas the remaining enum values are screen-positioned, with the labels anchored
 relative to the edge of the map.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGridLabelPosition) {
    AGSGridLabelPositionGeographic = 0,     /*!< Labels anchored to a geographical position on the map view. */
    AGSGridLabelPositionBottomLeft = 1,     /*!< x-labels anchored to bottom, y-labels anchored to left of map view.*/
    AGSGridLabelPositionBottomRight = 2,    /*!< x-labels anchored to bottom, y-labels anchored to right of map view.*/
    AGSGridLabelPositionTopLeft = 3,        /*!< x-labels anchored to top, y-labels anchored to left of map view. */
    AGSGridLabelPositionTopRight = 4,       /*!< x-labels anchored to top, y-labels anchored to right of map view.*/
    AGSGridLabelPositionCenter = 5,         /*!< x- and y-labels are anchored in center of map view*/
    AGSGridLabelPositionAllSides = 6,       /*!< Labels are anchored to top, right, bottom and left of map view.*/
};

/** Supported formats for Latitude-Longitude values used in grid labels.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLatitudeLongitudeGridLabelFormat) {
    AGSLatitudeLongitudeGridLabelFormatDecimalDegrees = 0,          /*!< Label the grid lines (graticules) in decimal degrees. */
    AGSLatitudeLongitudeGridLabelFormatDegreesMinutesSeconds = 1,   /*!< Label the grid lines (graticules) in degrees, minutes and seconds. */
};

/** Supported units for values displayed in MGRS grid labels
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSMGRSGridLabelUnit) {
    AGSMGRSGridLabelUnitKilometersMeters = 0,   /*!< Labels are displayed in kilometers or meters based on view's scale */
    AGSMGRSGridLabelUnitMeters = 1,             /*!< Labels are always displayed in meters. */
};

/** Supported units for values displayed in USNG grid labels
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSUSNGGridLabelUnit) {
    AGSUSNGGridLabelUnitKilometersMeters = 0,   /*!< Labels are displayed in kilometers or meters based on view's scale */
    AGSUSNGGridLabelUnitMeters = 1,             /*!< Labels are always displayed in meters. */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSNoDataTileBehavior) {
    AGSNoDataTileBehaviorUpSample = 0,      /*!<  */
    AGSNoDataTileBehaviorBlank = 1,         /*!<  */
    AGSNoDataTileBehaviorShow = 2,          /*!<  */
    AGSNoDataTileBehaviorUnknown = -1       /*!<  */
};

#pragma mark - Symbology

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSMarkerSymbolAngleAlignment)
{
    AGSMarkerSymbolAngleAlignmentMap = 0,       /*!< */
    AGSMarkerSymbolAngleAlignmentScreen = 1    /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSymbolRotationType)
{
    AGSSymbolRotationTypeArithmetic = 0,    /*< Rotation is performed starting from East in a counter-clockwise direction where East is the 0° axis */
    AGSSymbolRotationTypeGeographic = 1     /*< Rotation is performed starting from North in a clockwise direction where North is the 0° axis */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSimpleMarkerSymbolStyle)
{
    AGSSimpleMarkerSymbolStyleCircle = 0,       /*!< */
    AGSSimpleMarkerSymbolStyleCross = 1,        /*!< */
    AGSSimpleMarkerSymbolStyleDiamond = 2,      /*!< */
    AGSSimpleMarkerSymbolStyleSquare = 3,       /*!< */
    AGSSimpleMarkerSymbolStyleTriangle = 4,     /*!< */
    AGSSimpleMarkerSymbolStyleX = 5             /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSimpleLineSymbolStyle) {
    AGSSimpleLineSymbolStyleDash = 0,           /*!< */
    AGSSimpleLineSymbolStyleDashDot = 1,        /*!< */
    AGSSimpleLineSymbolStyleDashDotDot = 2,     /*!< */
    AGSSimpleLineSymbolStyleDot = 3,            /*!< */
    AGSSimpleLineSymbolStyleNull = 4,           /*!< */
    AGSSimpleLineSymbolStyleSolid = 5           /*!< */
};


/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSFontDecoration) {
    AGSFontDecorationLineThrough = 0,           /*!< */
    AGSFontDecorationNone = 1,                  /*!< */
    AGSFontDecorationUnderline = 2              /*!< */
};


/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSFontStyle) {
    AGSFontStyleItalic = 0,     /*!< */
    AGSFontStyleNormal = 1,     /*!< */
    AGSFontStyleOblique = 2    /*!< */
};

/**
 @since 100
 */

typedef NS_ENUM(NSInteger, AGSFontWeight) {
    AGSFontWeightBold = 0,      /*!< */
    AGSFontWeightNormal = 1    /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSHorizontalAlignment) {
    AGSHorizontalAlignmentCenter = 0,       /*!< */
    AGSHorizontalAlignmentJustify = 1,      /*!< */
    AGSHorizontalAlignmentLeft = 2,         /*!< */
    AGSHorizontalAlignmentRight = 3         /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSVerticalAlignment) {
    AGSVerticalAlignmentBaseline = 0,       /*!< */
    AGSVerticalAlignmentBottom = 1,         /*!< */
    AGSVerticalAlignmentMiddle = 2,         /*!< */
    AGSVerticalAlignmentTop = 3             /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSimpleFillSymbolStyle) {
    AGSSimpleFillSymbolStyleBackwardDiagonal = 0,       /*!< */
    AGSSimpleFillSymbolStyleCross = 1,                  /*!< */
    AGSSimpleFillSymbolStyleDiagonalCross = 2,          /*!< */
    AGSSimpleFillSymbolStyleForwardDiagonal = 3,        /*!< */
    AGSSimpleFillSymbolStyleHorizontal = 4,             /*!< */
    AGSSimpleFillSymbolStyleNull = 5,                   /*!< */
    AGSSimpleFillSymbolStyleSolid = 6,                  /*!< */
    AGSSimpleFillSymbolStyleVertical = 7               /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSceneSymbolAnchorPosition) {
    AGSSceneSymbolAnchorPositionTop = 0,        /*!<  */
    AGSSceneSymbolAnchorPositionBottom = 1,     /*!<  */
    AGSSceneSymbolAnchorPositionCenter = 2,     /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSimpleMarkerSceneSymbolStyle) {
    AGSSimpleMarkerSceneSymbolStyleCone = 0,        /*!<  */
    AGSSimpleMarkerSceneSymbolStyleCube = 1,        /*!<  */
    AGSSimpleMarkerSceneSymbolStyleCylinder = 2,    /*!<  */
    AGSSimpleMarkerSceneSymbolStyleDiamond = 3,     /*!<  */
    AGSSimpleMarkerSceneSymbolStyleSphere = 4,      /*!<  */
    AGSSimpleMarkerSceneSymbolStyleTetrahedron = 5  /*!<  */
};

#pragma mark - Renderer

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSRendererNormalizationType) {
    AGSRendererNormalizationTypeByField = 0,            /*!< */
    AGSRendererNormalizationTypeByLog = 1,              /*!< */
    AGSRendererNormalizationTypeByPercentOfTotal = 2,   /*!< */
    AGSRendererNormalizationTypeNone = 3,               /*!< */
    AGSRendererNormalizationTypeUnknown = -1            /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPresetColorRampType) {
    AGSPresetColorRampTypeNone = -1,                          /*!<  */
    AGSPresetColorRampTypeElevation = 0,                      /*!<  */
    AGSPresetColorRampTypeDEMScreen = 1,                      /*!<  */
    AGSPresetColorRampTypeDEMLight = 2,                       /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPansharpenType) {
    AGSPansharpenTypeNone = -1,                         /*!<  */
    AGSPansharpenTypeIHS = 0,                           /*!<  */
    AGSPansharpenTypeBrovey = 1,                        /*!<  */
    AGSPansharpenTypeMean = 2,                          /*!<  */
    AGSPansharpenTypeEsri = 3,                          /*!<  */
    AGSPansharpenTypeGramSchmidt = 4,                   /*!<  */
};

typedef NS_ENUM(NSInteger, AGSSlopeType) {
    AGSSlopeTypeNone = -1,                              /*!<  */
    AGSSlopeTypeDegree = 0,                             /*!<  Inclination of slope is calculated in degrees. The values range from 0 to 90 */
    AGSSlopeTypePercentRise = 1,                        /*!<  Inclination of slope is calculated as percentage values. The values range from 0 to essentially infinity. A flat surface is 0 percent and a 45-degree surface is 100 percent, and as the surface becomes more vertical, the percent rise becomes increasingly larger */
    AGSSlopeTypeScaled = 2,                             /*!<  Same as Degree, but the z-factor is adjusted for scale using Pixel Size Power and Pixel Size Factor */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSExtrusionMode) {
    AGSExtrusionModeNone = 0,                           /*!<  No extrusion */
    AGSExtrusionModeMinimum = 1,                        /*!<  A z-value is calculated by adding the extrusion height to the minimum z-value of the geo-element, and the geo-element is extruded to a flat top at that value.*/
    AGSExtrusionModeMaximum = 2,                        /*!<  A z-value is calculated by adding the extrusion height to the maximum z-value of the geo-element, and the geo-element is extruded to a flat top at that value.*/
    AGSExtrusionModeAbsoluteHeight = 3,                 /*!<  The geo-element is extruded to the specified z-value as a flat top, regardless of the z-values of the geo-element.*/
    AGSExtrusionModeBaseHeight = 4,                     /*!<  A z-value is calculated for each vertex of the geo-element's base, and the geo-element is extruded to the various z-values. This is the only extrusion mode that doesn't have a flat top.*/
};

#pragma mark - Animation

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAnimationCurve) {
    AGSAnimationCurveLinear = 0,                /*!< */
    AGSAnimationCurveEaseInQuad = 1,            /*!< */
    AGSAnimationCurveEaseOutQuad = 2,           /*!< */
    AGSAnimationCurveEaseInOutQuad = 3,         /*!< */
    AGSAnimationCurveEaseInCubic = 4,           /*!< */
    AGSAnimationCurveEaseOutCubic = 5,          /*!< */
    AGSAnimationCurveEaseInOutCubic = 6,        /*!< */
    AGSAnimationCurveEaseInQuart = 7,           /*!< */
    AGSAnimationCurveEaseOutQuart = 8,          /*!< */
    AGSAnimationCurveEaseInOutQuart = 9,        /*!< */
    AGSAnimationCurveEaseInQuint = 10,          /*!< */
    AGSAnimationCurveEaseOutQuint = 11,         /*!< */
    AGSAnimationCurveEaseInOutQuint = 12,       /*!< */
    AGSAnimationCurveEaseInSine = 13,           /*!< */
    AGSAnimationCurveEaseOutSine = 14,          /*!< */
    AGSAnimationCurveEaseInOutSine = 15,        /*!< */
    AGSAnimationCurveEaseInExpo = 16,           /*!< */
    AGSAnimationCurveEaseOutExpo = 17,          /*!< */
    AGSAnimationCurveEaseInOutExpo = 18,        /*!< */
    AGSAnimationCurveEaseInCirc = 19,           /*!< */
    AGSAnimationCurveEaseOutCirc = 20,          /*!< */
    AGSAnimationCurveEaseInOutCirc = 21        /*!< */
};



#pragma mark - Units

/** Supported time units.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSTimeUnit) {
    AGSTimeUnitUnknown = -1,               /*!< Unknown */
    AGSTimeUnitCenturies = 0,              /*!< Centuries */
    AGSTimeUnitDays = 1,                   /*!< Days */
    AGSTimeUnitDecades = 2,                /*!< Decades*/
    AGSTimeUnitHours = 3,                  /*!< Hours */
    AGSTimeUnitMilliseconds = 4,           /*!< Milliseconds */
    AGSTimeUnitMinutes = 5,                /*!< Minutes */
    AGSTimeUnitMonths = 6,                 /*!< Months */
    AGSTimeUnitSeconds = 7,                /*!< Seconds */
    AGSTimeUnitWeeks = 8,                  /*!< Weeks */
    AGSTimeUnitYears = 9                   /*!< Years */
};

/** Supported time relation.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSTimeRelation) {
    AGSTimeRelationUnknown = -1,                /*!<  */
    AGSTimeRelationOverlaps = 0,                /*!<  */
    AGSTimeRelationAfterStartOverlapsEnd = 1,   /*!<  */
    AGSTimeRelationOverlapsStartWithinEnd = 2,  /*!<  */
};

/**
 Angular units.
 
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAngularUnitID)
{
    AGSAngularUnitIDDegrees = 9102,     /*!< Degrees */
    AGSAngularUnitIDGrads = 9105,       /*!< Gradians */
    AGSAngularUnitIDMinutes = 9103,     /*!< Minutes */
    AGSAngularUnitIDRadians = 9101,     /*!< Radians */
    AGSAngularUnitIDSeconds = 9104,     /*!< Seconds */
    AGSAngularUnitIDOther = 0           /*!< Other */
};

/**
 Area units.
 
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAreaUnitID)
{
    AGSAreaUnitIDAcres = 109402,                /*!< Acres */
    AGSAreaUnitIDHectares = 109401,             /*!< Hectares */
    AGSAreaUnitIDSquareCentimeters = 109451,    /*!< Sq. Centimeters */
    AGSAreaUnitIDSquareDecimeters = 109450,     /*!< Sq. Decimeters */
    AGSAreaUnitIDSquareFeet = 109405,           /*!< Sq. Feet */
    AGSAreaUnitIDSquareKilometers = 109414,     /*!< Sq. Kilometers */
    AGSAreaUnitIDSquareMeters = 109404,         /*!< Sq. Meters */
    AGSAreaUnitIDSquareMillimeters = 109452,    /*!< Sq. Millimeters */
    AGSAreaUnitIDSquareMiles = 109439,          /*!< Sq. Miles */
    AGSAreaUnitIDSquareYards = 109442,          /*!< Sq. Yards */
    AGSAreaUnitIDOther = 0                      /*!< Other */
};

/**
 Linear units.
 
 @since 100
 */

typedef NS_ENUM(NSInteger, AGSLinearUnitID)
{
    AGSLinearUnitIDCentimeters = 1033,          /*!< Centimeters. */
    AGSLinearUnitIDFeet = 9002,                 /*!< International foot. */
    AGSLinearUnitIDInches = 109008,             /*!< International inch. */
    AGSLinearUnitIDKilometers = 9036,           /*!< Kilometer. */
    AGSLinearUnitIDMeters = 9001,               /*!< International meter. */
    AGSLinearUnitIDMiles = 9093,                /*!< Statute Miles. */
    AGSLinearUnitIDMillimeters = 1025,          /*!< Millimeters */
    AGSLinearUnitIDNauticalMiles = 9030,		/*!< International nautical mile. */
    AGSLinearUnitIDYards = 9096,                /*!< Yards. */
    AGSLinearUnitIDOther = 0,                   /*!< Other */
};

#pragma mark - Image Format

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSMapServiceImageFormat) {
    AGSMapServiceImageFormatDefault = 0,      /*!< */
    AGSMapServiceImageFormatPNG = 1,          /*!< */
    AGSMapServiceImageFormatPNG8 = 2,         /*!< */
    AGSMapServiceImageFormatPNG24 = 3,        /*!< */
    AGSMapServiceImageFormatPNG32 = 4,        /*!< */
    AGSMapServiceImageFormatJPG = 5,          /*!< */
    AGSMapServiceImageFormatJPGPNG = 6,       /*!< */
    AGSMapServiceImageFormatBMP = 7,          /*!< */
    AGSMapServiceImageFormatGIF = 8,          /*!< */
    AGSMapServiceImageFormatTIFF = 9,         /*!< */
    AGSMapServiceImageFormatUnknown = -1,     /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSTileImageFormat)
{
    AGSTileImageFormatPNG = 0,      /*!<  */
    AGSTileImageFormatPNG8 = 1,     /*!<  */
    AGSTileImageFormatPNG24 = 2,    /*!<  */
    AGSTileImageFormatPNG32 = 3,    /*!<  */
    AGSTileImageFormatJPG = 4,      /*!<  */
    AGSTileImageFormatMIXED = 5,    /*!<  */
    AGSTileImageFormatLERC = 6,     /*!<  */
    AGSTileImageFormatUnknown = -1  /*!<  */
};

#pragma mark - Labeling

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLabelingPlacement) {
    AGSLabelingPlacementUnknown = -1,           /*!< */
    AGSLabelingPlacementLineAboveAfter = 0,     /*!< */
    AGSLabelingPlacementLineAboveAlong = 1,     /*!< */
    AGSLabelingPlacementLineAboveBefore = 2,    /*!< */
    AGSLabelingPlacementLineAboveEnd = 3,       /*!< */
    AGSLabelingPlacementLineAboveStart = 4,     /*!< */
    AGSLabelingPlacementLineBelowAfter = 5,     /*!< */
    AGSLabelingPlacementLineBelowAlong = 6,     /*!< */
    AGSLabelingPlacementLineBelowBefore = 7,    /*!< */
    AGSLabelingPlacementLineBelowEnd = 8,       /*!< */
    AGSLabelingPlacementLineBelowStart = 9,     /*!< */
    AGSLabelingPlacementLineCenterAfter = 10,   /*!< */
    AGSLabelingPlacementLineCenterAlong = 11,   /*!< */
    AGSLabelingPlacementLineCenterBefore = 12,  /*!< */
    AGSLabelingPlacementLineCenterEnd = 13,     /*!< */
    AGSLabelingPlacementLineCenterStart = 14,   /*!< */
    AGSLabelingPlacementPointAboveCenter = 15,  /*!< */
    AGSLabelingPlacementPointAboveLeft = 16,    /*!< */
    AGSLabelingPlacementPointAboveRight = 17,   /*!< */
    AGSLabelingPlacementPointBelowCenter = 18,  /*!< */
    AGSLabelingPlacementPointBelowLeft = 19,    /*!< */
    AGSLabelingPlacementPointBelowRight = 20,   /*!< */
    AGSLabelingPlacementPointCenterCenter = 21, /*!< */
    AGSLabelingPlacementPointCenterLeft = 22,   /*!< */
    AGSLabelingPlacementPointCenterRight = 23,  /*!< */
    AGSLabelingPlacementPolygonAlwaysHorizontal = 24,/*!< */
};



#pragma mark - Feature

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSFieldType) {
    AGSFieldTypeUnknown = -1,       /*!< */
    AGSFieldTypeInt16 = 0,          /*!< */
    AGSFieldTypeInt32 = 1,          /*!< */
    AGSFieldTypeGUID = 3,           /*!< */
    AGSFieldTypeFloat = 4,          /*!< */
    AGSFieldTypeDouble = 5,         /*!< */
    AGSFieldTypeDate = 6,           /*!< */
    AGSFieldTypeText = 7,           /*!< */
    AGSFieldTypeOID = 8,            /*!< */
    AGSFieldTypeGlobalID = 9,       /*!< */
    AGSFieldTypeBlob = 10,          /*!< */
    AGSFieldTypeGeometry = 11,      /*!< */
    AGSFieldTypeRaster = 12,        /*!< */
    AGSFieldTypeXML = 13            /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSpatialRelationship) {
    AGSSpatialRelationshipUnknown = -1,             /*!< */
    AGSSpatialRelationshipRelate = 0,               /*!< */
    AGSSpatialRelationshipEquals = 1,               /*!< */
    AGSSpatialRelationshipDisjoint = 2,             /*!< */
    AGSSpatialRelationshipIntersects = 3,           /*!< */
    AGSSpatialRelationshipTouches = 4,              /*!< */
    AGSSpatialRelationshipCrosses = 5,              /*!< */
    AGSSpatialRelationshipWithin = 6,               /*!< */
    AGSSpatialRelationshipContains = 7,             /*!< */
    AGSSpatialRelationshipOverlaps = 8,             /*!< */
    AGSSpatialRelationshipEnvelopeIntersects = 9,   /*!< */
    AGSSpatialRelationshipIndexIntersects = 10,     /*!< */
};

/** Specifies how `AGSServiceFeatureTable` should retrieve data from its service.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSFeatureRequestMode) {
    AGSFeatureRequestModeUndefined = 0,                 /*!< */
    AGSFeatureRequestModeOnInteractionCache = 1,        /*!< Data is automatically requested as the user navigates and interacts with the map. All data that is requested is cached locally. Cached data is never requested again even when the map is navigated to areas that have been already visited. Suitable for fairly static data that does not change on the server.*/
    AGSFeatureRequestModeOnInteractionNoCache = 2,      /*!< Data is automatically requested as the user navigates and interacts with the map, but it is never cached. The same data may be requested mutliple times when the map is navigated to areas that have been already visited. Suitable for continually updateing data on the server.*/
    AGSFeatureRequestModeManualCache = 3,               /*!< Data is not automatically requested upon map interaction or navigation. The developer needs to explicitly request data using `AGSServiceFeatureTable#populateFromServiceWithParameters:clearCache:completion:` */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSortOrder) {
    AGSSortOrderAscending = 0,      /*!< */
    AGSSortOrderDescending = 1,     /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSEditOperation) {
    AGSEditOperationAdd = 0,        /*!< */
    AGSEditOperationUpdate = 1,     /*!< */
    AGSEditOperationDelete = 2,     /*!< */
    AGSEditOperationUnknown = -1,   /*!< */
};

/** Selection mode for handling results
 @see [`AGSFeatureLayer selectFeaturesWithQuery:mode:completion:`]
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSelectionMode) {
    AGSSelectionModeAdd = 0,            /*!< Add results to the existing set of selected features */
    AGSSelectionModeNew = 1,            /*!< Replace existing set of selected features with the results  */
    AGSSelectionModeSubtract = 2,       /*!< Remove results from the existing set of selected features */
};  

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSQueryFeatureFields) {
    AGSQueryFeatureFieldsIDsOnly = 0,       /*!<  */
    AGSQueryFeatureFieldsMinimum = 1,       /*!<  */
    AGSQueryFeatureFieldsLoadAll = 2,       /*!<  */
};

/** Supported drawing tools.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSDrawingTool) {
    AGSDrawingToolUnknown = -1,             /*!< */
    AGSDrawingToolAutoCompletePolygon = 0,  /*!< */
    AGSDrawingToolCircle = 1,               /*!< */
    AGSDrawingToolDownArrow = 2,            /*!< */
    AGSDrawingToolEllipse = 3,              /*!< */
    AGSDrawingToolFreeHand = 4,             /*!< */
    AGSDrawingToolLeftArrow = 5,            /*!< */
    AGSDrawingToolLine = 6,                 /*!< */
    AGSDrawingToolNone = 7,                 /*!< */
    AGSDrawingToolPoint = 8,                /*!< */
    AGSDrawingToolPolygon = 9,              /*!< */
    AGSDrawingToolRectangle = 10,           /*!< */
    AGSDrawingToolRightArrow = 11,          /*!< */
    AGSDrawingToolText = 12,                /*!< */
    AGSDrawingToolTriangle = 13,            /*!< */
    AGSDrawingToolUpArrow = 14,             /*!< */
};

/** Supported service type of feature layer info.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSArcGISFeatureLayerInfoServiceType) {
    AGSArcGISFeatureLayerInfoServiceTypeLayer = 0,          /*!<  */
    AGSArcGISFeatureLayerInfoServiceTypeTable = 1,          /*!<  */
    AGSArcGISFeatureLayerInfoServiceTypeGroupLayer = 2,     /*!<  */
    AGSArcGISFeatureLayerInfoServiceTypeUnknown = -1,       /*!<  */
};

#pragma mark - Location Display

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLocationDisplayAutoPanMode) {
    AGSLocationDisplayAutoPanModeOff = 0,                   /*!< */
    AGSLocationDisplayAutoPanModeRecenter = 1,               /*!< */
    AGSLocationDisplayAutoPanModeNavigation = 2,            /*!< */
    AGSLocationDisplayAutoPanModeCompassNavigation = 3     /*!< */
};

#pragma mark - Layer

#pragma mark Service Info

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSTextAntialiasingMode) {
    AGSTextAntialiasingModeNone = 0,                /*!<  */
    AGSTextAntialiasingModeNormal = 1,              /*!<  */
    AGSTextAntialiasingModeForce = 2,               /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAntialiasingMode) {
    AGSAntialiasingModeNone = 0,                    /*!<  */
    AGSAntialiasingModeFastest = 1,                 /*!<  */
    AGSAntialiasingModeFast = 2,                    /*!<  */
    AGSAntialiasingModeNormal = 3,                  /*!<  */
    AGSAntialiasingModeBest = 4,                    /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSServiceType) {
    AGSServiceTypeUnknown = -1,             /*!<  */
    AGSServiceTypeFeatureService = 0,       /*!<  */
    AGSServiceTypeImageService = 1,         /*!<  */
    AGSServiceTypeMapService = 2,           /*!<  */
};

#pragma mark - Graphics Overlay

/**  Specifies how the `AGSGraphicsOverlay` renders its content.
 Dynamic mode is better suited for a small number of graphics that are constantly changing or moving and need to
 be redrawn frequently.
 If your content is more static then use static mode. Static mode does not provide the same level
 of interactiveness or user experience as dynamic mode,
 but it allows the overlay to render a larger number of graphics.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGraphicsRenderingMode) {
    AGSGraphicsRenderingModeDynamic = 0,    /*!< */
    AGSGraphicsRenderingModeStatic = 1,     /*!< */
};

#pragma mark - Network Tasks

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSBarrierType) {
    AGSBarrierTypeRestriction = 0,          /*!<  */
    AGSBarrierTypeCostAdjustment = 1,       /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSCurbApproach) {
    AGSCurbApproachEitherSide = 0,      /*!<  */
    AGSCurbApproachLeftSide = 1,        /*!<  */
    AGSCurbApproachRightSide = 2,       /*!<  */
    AGSCurbApproachNoUTurn = 3,         /*!<  */
    AGSCurbApproachUnknown = 4          /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLocationStatus) {
    AGSLocationStatusNotLocated = 0,                /*!<  */
    AGSLocationStatusOnClosest = 1,                 /*!<  */
    AGSLocationStatusOnClosestNotRestricted = 2,    /*!<  */
    AGSLocationStatusNotReached = 3,                /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSUTurnPolicy) {
    AGSUTurnPolicyNotAllowed = 0,                           /*!<  */
    AGSUTurnPolicyAllowedAtDeadEnds = 1,                    /*!<  */
    AGSUTurnPolicyAllowedAtIntersections = 2,               /*!<  */
    AGSUTurnPolicyAllowedAtDeadEndsAndIntersections = 3,    /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSDirectionManeuverType) {
    AGSDirectionManeuverTypeUnknown = 0,			/*!<  */
    AGSDirectionManeuverTypeStop = 1,               /*!<  */
    AGSDirectionManeuverTypeStraight = 2,			/*!<  */
    AGSDirectionManeuverTypeBearLeft = 3,			/*!<  */
    AGSDirectionManeuverTypeBearRight = 4,			/*!<  */
    AGSDirectionManeuverTypeTurnLeft = 5,			/*!<  */
    AGSDirectionManeuverTypeTurnRight = 6,			/*!<  */
    AGSDirectionManeuverTypeSharpLeft = 7,			/*!<  */
    AGSDirectionManeuverTypeSharpRight = 8,			/*!<  */
    AGSDirectionManeuverTypeUTurn = 9,              /*!<  */
    AGSDirectionManeuverTypeFerry = 10,             /*!<  */
    AGSDirectionManeuverTypeRoundabout = 11,		/*!<  */
    AGSDirectionManeuverTypeHighwayMerge = 12,		/*!<  */
    AGSDirectionManeuverTypeHighwayExit = 13,		/*!<  */
    AGSDirectionManeuverTypeHighwayChange = 14,		/*!<  */
    AGSDirectionManeuverTypeForkCenter = 15,		/*!<  */
    AGSDirectionManeuverTypeForkLeft = 16,			/*!<  */
    AGSDirectionManeuverTypeForkRight = 17,			/*!<  */
    AGSDirectionManeuverTypeDepart = 18,			/*!<  */
    AGSDirectionManeuverTypeTripItem = 19,			/*!<  */
    AGSDirectionManeuverTypeEndOfFerry = 20,		/*!<  */
    AGSDirectionManeuverTypeRampRight = 21,			/*!<  */
    AGSDirectionManeuverTypeRampLeft = 22,			/*!<  */
    AGSDirectionManeuverTypeTurnLeftRight = 23,		/*!<  */
    AGSDirectionManeuverTypeTurnRightLeft = 24,		/*!<  */
    AGSDirectionManeuverTypeTurnRightRight = 25,	/*!<  */
    AGSDirectionManeuverTypeTurnLeftLeft = 26,		/*!<  */
    AGSDirectionManeuverTypePedestrianRamp = 27,	/*!<  */
    AGSDirectionManeuverTypeElevator = 28,			/*!<  */
    AGSDirectionManeuverTypeEscalator = 29,			/*!<  */
    AGSDirectionManeuverTypeStairs = 30,			/*!<  */
    AGSDirectionManeuverTypeDoorPassage = 31,		/*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSUnitSystem) {
    AGSUnitSystemImperial = 0,                      /*!<  */
    AGSUnitSystemMetric = 1,                        /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSDirectionsStyle) {
    AGSDirectionsStyleDesktop = 0,      /*!<  */
    AGSDirectionsStyleNavigation = 1,   /*!<  */
    AGSDirectionsStyleCampus = 2,       /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSRouteShapeType) {
    AGSRouteShapeTypeNone = 0,                      /*!<  */
    AGSRouteShapeTypeStraightLine = 1,              /*!<  */
    AGSRouteShapeTypeTrueShapeWithMeasures = 2,     /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAttributeUnit) {
    AGSAttributeUnitUnknown = 0,              /*!<  */
    AGSAttributeUnitInches = 1,               /*!<  */
    AGSAttributeUnitFeet = 2,                 /*!<  */
    AGSAttributeUnitYards = 3,                /*!<  */
    AGSAttributeUnitMiles = 4,                /*!<  */
    AGSAttributeUnitMillimeters = 5,          /*!<  */
    AGSAttributeUnitCentimeters = 6,          /*!<  */
    AGSAttributeUnitDecimeters = 7,           /*!<  */
    AGSAttributeUnitMeters = 8,               /*!<  */
    AGSAttributeUnitKilometers = 9,           /*!<  */
    AGSAttributeUnitNauticalMiles = 10,       /*!<  */
    AGSAttributeUnitDecimalDegrees = 11,      /*!<  */
    AGSAttributeUnitSeconds = 12,             /*!<  */
    AGSAttributeUnitMinutes = 13,             /*!<  */
    AGSAttributeUnitHours = 14,               /*!<  */
    AGSAttributeUnitDays = 15,                /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSDirectionMessageType) {
    AGSDirectionMessageTypeLength = 0,                  /*!<  */
    AGSDirectionMessageTypeTime = 1,                    /*!<  */
    AGSDirectionMessageTypeSummary = 2,                 /*!<  */
    AGSDirectionMessageTypeTimeWindow = 3,              /*!<  */
    AGSDirectionMessageTypeViolationTime = 4,			/*!<  */
    AGSDirectionMessageTypeWaitTime = 5,                /*!<  */
    AGSDirectionMessageTypeServiceTime = 6,             /*!<  */
    AGSDirectionMessageTypeEstimatedArrivalTime = 7,	/*!<  */
    AGSDirectionMessageTypeCumulativeLength = 8,		/*!<  */
    AGSDirectionMessageTypeStreetName = 9,              /*!<  */
    AGSDirectionMessageTypeAlternativeName = 10,		/*!<  */
    AGSDirectionMessageTypeBranch = 11,                 /*!<  */
    AGSDirectionMessageTypeToward = 12,                 /*!<  */
    AGSDirectionMessageTypeCrossStreet = 13,			/*!<  */
    AGSDirectionMessageTypeExit = 14,                   /*!<  */
};

#pragma mark Geodatabase

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSyncModel) {
    AGSSyncModelNone = 0,           /*!< Not a valid value */
    AGSSyncModelGeodatabase = 1,    /*!< Layers within a geodatabase cannot be synchronized independently, the whole geodatabase must be synced. The sync operation and sync direction applies to all the layers in the geodatabase. */
    AGSSyncModelLayer = 2,          /*!< Layers within a geodatabase can be synchronized independently of one another. Any subset of the layers can be synchronized when running the sync operation. Also, each layer can independently choose its sync direction */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSyncDirection) {
    AGSSyncDirectionNone = 0,           /*!<  */
    AGSSyncDirectionDownload = 1,       /*!<  */
    AGSSyncDirectionUpload = 2,         /*!<  */
    AGSSyncDirectionBidirectional = 3,  /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAttachmentSyncDirection) {
    AGSAttachmentSyncDirectionNone = 0,             /*!< Data may not be uploaded or downloaded */
    AGSAttachmentSyncDirectionUpload = 1,           /*!< Data may only be uploaded to the service, but not downloaded */
    AGSAttachmentSyncDirectionBidirectional = 2,    /*!< Data may either be uploaded or downloaded */
};

#pragma mark - Authentication

/** Supported authentication challenge types.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAuthenticationChallengeType) {
    AGSAuthenticationChallengeTypeUsernamePassword = 0,          /*!<  */
    AGSAuthenticationChallengeTypeOAuth,                         /*!<  */
    AGSAuthenticationChallengeTypeClientCertificate,             /*!<  */
    AGSAuthenticationChallengeTypeUntrustedHost,                 /*!<  */
    AGSAuthenticationChallengeTypeUnknown,                       /*!<  */
} ;

/** Error types returned
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSCredentialErrorType) {
    AGSCredentialErrorTypeNone = 0,                 /*!<  */
    AGSCredentialErrorTypeInvalidCredentials,       /*!<  */
    AGSCredentialErrorTypeSSLRequired,              /*!<  */
    AGSCredentialErrorTypeUnknown                   /*!<  */
} ;

#pragma mark AGSJob

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSJobType) {
    AGSJobTypeGenerateGeodatabase = 0,      /*!<  */
    AGSJobTypeSyncGeodatabase = 1,          /*!<  */
    AGSJobTypeExportTileCache = 2,          /*!<  */
    AGSJobTypeEstimateTileCacheSize = 3,    /*!<  */
    AGSJobTypeGeoprocessingJob = 4          /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSJobStatus) {
    AGSJobStatusNotStarted = 0,             /*!<  */
    AGSJobStatusStarted = 1,                /*!<  */
    AGSJobStatusPaused = 2,                 /*!<  */
    AGSJobStatusSucceeded = 3,              /*!<  */
    AGSJobStatusFailed = 4                  /*!<  */
};

#pragma mark AGSScene

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAtmosphereEffect) {
    AGSAtmosphereEffectNone = 0,            /*!<  */
    AGSAtmosphereEffectHorizonOnly = 1,     /*!<  */
    AGSAtmosphereEffectRealistic = 2        /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLightingMode) {
    AGSLightingModeNoLight = 0,             /*!<  */
    AGSLightingModeLight = 1,               /*!<  */
    AGSLightingModeLightAndShadows = 2      /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSurfacePlacement) {
    AGSSurfacePlacementDraped = 0,          /*!< Altitude is based on the underlying surface elevation. Object's Z value is ignored. */
    AGSSurfacePlacementAbsolute = 1,        /*!< Altitude is based on object's Z value and doesn't take surface elevation into consideration. */
    AGSSurfacePlacementRelative = 2,        /*!< Altitude is based on a combination of object's Z value and the underlying surface elevation */
};

#pragma mark Raster

#pragma mark - KML
/**
 @since 100
 */

typedef NS_ENUM(NSInteger, AGSKMLAltitudeMode)
{
    AGSKMLAltitudeModeClampToGround = 0,        /*!<  */
    AGSKMLAltitudeModeRelativeToGround = 1,     /*!<  */
    AGSKMLAltitudeModeAbsolute = 2,             /*!<  */
    AGSKMLAltitudeModeUnknown = -1              /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSKMLColorMode)
{
    AGSKMLColorModeNormal = 0,      /*!<  */
    AGSKMLColorModeRandom = 1,      /*!<  */
    AGSKMLColorModeUnknown = -1     /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSKMLGeometryType)
{
    AGSKMLGeometryTypeNone = 0,             /*!<  */
    AGSKMLGeometryTypePoint = 1,            /*!<  */
    AGSKMLGeometryTypePolyline = 2,         /*!<  */
    AGSKMLGeometryTypePolygon = 3,          /*!<  */
    AGSKMLGeometryTypeModel = 4,            /*!<  */
    AGSKMLGeometryTypeMultiGeometry = 5,    /*!<  */
    AGSKMLGeometryTypeUnknown = -1          /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSKMLListItemType)
{
    AGSKMLListItemTypeCheck = 0,                /*!<  */
    AGSKMLListItemTypeRadioFolder = 1,          /*!<  */
    AGSKMLListItemTypeCheckOffOnly = 2,         /*!<  */
    AGSKMLListItemTypeCheckHideChildren = 3,    /*!<  */
    AGSKMLListItemTypeUnknown = -1              /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSKMLNetworkLinkRefreshStatus)
{
    AGSKMLNetworkLinkRefreshStatusError = 0,        /*!<  */
    AGSKMLNetworkLinkRefreshStatusDone = 1,         /*!<  */
    AGSKMLNetworkLinkRefreshStatusFetching = 2,     /*!<  */
    AGSKMLNetworkLinkRefreshStatusUnknown = -1      /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSScreenLocationVisibility) {
    AGSScreenLocationVisibilityVisible = 0,                /*!<  */
    AGSScreenLocationVisibilityHiddenByBaseSurface = 1,    /*!<  */
    AGSScreenLocationVisibilityHiddenByEarth = 2,          /*!<  */
    AGSScreenLocationVisibilityHiddenByElevation = 3,      /*!<  */
    AGSScreenLocationVisibilityNotOnScreen = 4,            /*!<  */
};

#pragma mark Sketch

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSketchCreationMode) {
    AGSSketchCreationModeUnset = -1,            /*!<  */
    AGSSketchCreationModePoint,                 /*!< Create Point geometry */
    AGSSketchCreationModeMultipoint,            /*!< Create Multipoint geometry */
    AGSSketchCreationModePolyline,              /*!< Create Polyline geometry incrementally one vertex at a time */
    AGSSketchCreationModePolygon,               /*!< Create Polygon geometry incrementally one vertex at a time */
    AGSSketchCreationModeFreehandPolyline,      /*!< Create Polyline geometry in one shot using freehand gesture */
    AGSSketchCreationModeFreehandPolygon,       /*!< Create Polygon geometry in one shot using freehand gesture*/
};

#pragma mark Geoprocessing

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGeoprocessingParameterType) {
    AGSGeoprocessingParameterTypeBoolean = 0,       /*!<  */
    AGSGeoprocessingParameterTypeDataFile = 1,      /*!<  */
    AGSGeoprocessingParameterTypeDate = 2,          /*!<  */
    AGSGeoprocessingParameterTypeDouble = 3,        /*!<  */
    AGSGeoprocessingParameterTypeFeatures = 4,      /*!<  */
    AGSGeoprocessingParameterTypeLinearUnit = 5,    /*!<  */
    AGSGeoprocessingParameterTypeLong = 6,          /*!<  */
    AGSGeoprocessingParameterTypeMultiValue = 7,    /*!<  */
    AGSGeoprocessingParameterTypeRaster = 8,        /*!<  */
    AGSGeoprocessingParameterTypeString = 9,        /*!<  */
    AGSGeoprocessingParameterTypeUnknown = 10,      /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGeoprocessingLinearUnits) {
    AGSGeoprocessingLinearUnitsCentimeter = 0,      /*!<  */
    AGSGeoprocessingLinearUnitsDecimeter = 1,       /*!<  */
    AGSGeoprocessingLinearUnitsKilometer = 2,       /*!<  */
    AGSGeoprocessingLinearUnitsMeter = 3,           /*!<  */
    AGSGeoprocessingLinearUnitsMillimeter = 4,      /*!<  */
    AGSGeoprocessingLinearUnitsPoint = 5,           /*!<  */
    AGSGeoprocessingLinearUnitsUSNauticalMile = 6,  /*!<  */
    AGSGeoprocessingLinearUnitsUSSurveyFoot = 7,    /*!<  */
    AGSGeoprocessingLinearUnitsUSSurveyInch = 8,    /*!<  */
    AGSGeoprocessingLinearUnitsUSSurveyMile = 9,    /*!<  */
    AGSGeoprocessingLinearUnitsUSSurveyYard = 10,   /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGeoprocessingExecutionType) {
    AGSGeoprocessingExecutionTypeAsynchronousSubmit = 0,    /*!<  */
    AGSGeoprocessingExecutionTypeSynchronousExecute = 1,    /*!<  */
};

NS_ASSUME_NONNULL_END

