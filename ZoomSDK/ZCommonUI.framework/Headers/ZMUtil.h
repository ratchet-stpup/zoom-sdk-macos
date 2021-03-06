//
//  ZMUtil.h
//  ZCommonUI
//
//  Created by John on 10/26/16.
//  Copyright (c) 2016 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

#define RGB(r,g,b)      [NSColor colorWithCalibratedRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define RGBA(r,g,b,a)   [NSColor colorWithCalibratedRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define SRGB(r,g,b)     [NSColor colorWithSRGBRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define SRGBA(r,g,b,a)  [NSColor colorWithSRGBRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define DRGB(r,g,b)     [NSColor colorWithDeviceRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define DRGBA(r,g,b,a)  [NSColor colorWithDeviceRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
typedef enum
{
    ID_Unknow_Language = 0,
    ID_English_Language,
    ID_Chinese_Simplified_Language,
    ID_Chinese_Traditional_Language,
    ID_Italian_Language,
    ID_French_Language,
    ID_German_Language,
    ID_Spanish_Language,
    ID_Japanese_Language,
} ID_CLIENT_LANGUAGE;

@interface ZMUtil : NSObject

//change key event to mouse event, change menu location
+ (NSEvent*)zmEventWithEvent:(NSEvent*)inOldEvent newLocation:(NSPoint)inNewLocation;
+ (ID_CLIENT_LANGUAGE)getCurrentLaguageIdentifer;
+ (NSString*)getCurrentLaguageCodeForTele;

//get view rect at screen coordinates
+ (NSRect)getScreenCoordinatesRectForView:(NSView*)inView;

//check if email is valid
+ (BOOL)isValidEmail:(NSString*)inEmail;

//string width/height
+(CGFloat)heightForWidth:(CGFloat)inWidth attributeString:(NSAttributedString*)inAttString;
+(CGFloat)widthForHeight:(CGFloat)inHeight attributeString:(NSAttributedString*)inAttString;
@end
