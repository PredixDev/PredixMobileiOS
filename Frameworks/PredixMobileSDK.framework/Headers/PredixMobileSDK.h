//
//  PredixMobileSDK.h
//  PredixMobileSDK
//
//  Created by Johns, Andy (GE Corporate) on 5/19/15.
//  Copyright (c) 2015 GE. All rights reserved.
//
#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#else
#import <AppKit/AppKit.h>
#endif

#ifndef PredixMobileSDK_h
#define PredixMobileSDK_h

//! Project version number for PredixMobileSDK.
FOUNDATION_EXPORT double PredixMobileSDKVersionNumber;

//! Project version string for PredixMobileSDK.
FOUNDATION_EXPORT const unsigned char PredixMobileSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <PredixMobileSDK/PublicHeader.h>

/*
#import <PredixMobileSDK/PGSDKConstants.h>
#import <PredixMobileSDK/PGSDKLogProvider.h>
#import <PredixMobileSDK/PGSDKLogger.h>
#import <PredixMobileSDK/SSZipArchive.h>
*/
#import "PGSDKConstants.h"
#import "PGSDKLogProvider.h"
#import "PGSDKLogger.h"
#import "SSZipArchive.h"
#endif