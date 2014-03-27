//
//  Sensus
//  Sensus SDK
//

#import <SensusSDK/SensusTouch.h>
#import <SensusSDK/SensusForceFrame.h>

// Make sure to add this protocol to your Info.plist file for the Application
#define ExternalAccessoryProtocolSensus @"com.canopy.sensus"

// Use this as your App UUID when developing your apps.
// You will need to obtain a unique UUID from the Dev Portal before release.
extern NSString *const SensusDevelopmentAppUUID;



@protocol SensusObserver;
@protocol SensusLogDelegate;

@interface Sensus : NSObject

/// Is Sensus connected?
@property (nonatomic, readonly) BOOL connected;

/// Current SensusTouch objects by identifier
@property (nonatomic, readonly) NSDictionary *touches;

/// Sensus Serial Number
@property (nonatomic, readonly) NSString *serialNumber;

/// Logging Delegate
@property (nonatomic, assign) id<SensusLogDelegate> logDelegate;

/// Single point of entry to interact with Sensus
///
/// \returns single instance of Sensus
+ (Sensus *)sharedInstance;

// You must set the App UUID before Sensus will activate
- (void)setAppUUID:(NSString *)appUUID;

- (void)addSensusObserver:(id<SensusObserver>)observer;
- (void)removeSensusObserver:(id<SensusObserver>)observer;

/// Enable DEBUG Mode for Sensus (requires Sensus to be attached independently to your computer)
- (void)debug;

@end


@protocol SensusObserver <NSObject>

@optional
- (void)sensusAccessoryConnected;
- (void)sensusAccessoryDisconnected;
- (void)sensusTouchObserved:(SensusTouch *)touch;
- (void)sensusForceFrame:(SensusForceFrame *)frame;

@end


@protocol SensusLogDelegate <NSObject>

- (void)sensusLogStatement:(NSString *)logStatement;

@end
