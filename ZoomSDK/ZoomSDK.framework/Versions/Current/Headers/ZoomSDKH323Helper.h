//
//  ZoomSDKH323Helper.h
//  ZoomSDK
//
//  Created by TOTTI on 1/3/17.
//  Copyright © 2017 TOTTI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"

@protocol ZoomSDKH323HelperDelegate <NSObject>
@optional
/**
 * Designated for ZoomSDK support H323 Device callout response.
 *
 * @param calloutStatus tell user when the callout status changed.
 *
 */
- (void) onCalloutStatusReceived:(H323CalloutStatus)calloutStatus;

/**
 * Designated for ZoomSDK support H323 Device pair meeting response.
 *
 * @param pairResult tell user when the pair status changed.
 *
 */
- (void) onPairCodeResult:(H323PairingResult)pairResult;
@end

@interface H323DeviceInfo : NSObject
{
    NSString* _name;
    NSString* _ip;
    NSString* _e164num;
    H323DeviceType _type;
}

@property(nonatomic, retain)NSString* name;
@property(nonatomic, retain)NSString* ip;
@property(nonatomic, retain)NSString* e164num;
@property(nonatomic, assign)H323DeviceType type;
@end

@interface ZoomSDKH323Helper : NSObject
{
    id<ZoomSDKH323HelperDelegate> _delegate;
}
@property (assign, nonatomic) id<ZoomSDKH323HelperDelegate> delegate;
/**
 * This method is used to Get h323 address for current meeting.
 * @return A NSArray contains addresses if function call successfully.
 */
- (NSArray*)getH323DeviceAddress;

 /**
 * This method is used to Get h323 password for current meeting.
 * @return A NSString contains h323 password if function call successfully.
 */
- (NSString*)getH323Password;

/**
 * This method is used to send Meeting paring code.
 * @param pairCode pair code for specified meeting.
 * @param meetingNum the meeting number u want to pair.
 * @return A ZoomSDKError to tell client whether send pair code successfully or not.
 */
- (ZoomSDKError)sendMeetingPairingCode:(NSString*)pairCode meetingNum:(long long)meetingNum;

/**
 * This method is used to call out a H323 device.
 * @param deviceInfo H323DeviceInfo object specified the H323 device u want to callout.
 * @return A ZoomSDKError to tell client whether callout H323 device successfully or not.
 */
- (ZoomSDKError)calloutH323Device:(H323DeviceInfo*)deviceInfo;

/**
 * This method is used to cancel last callout to a H323 device.
 * @return A ZoomSDKError to tell client whether cancel callout H323 device successfully or not.
 */
- (ZoomSDKError)cancelCallOutH323;

@end
