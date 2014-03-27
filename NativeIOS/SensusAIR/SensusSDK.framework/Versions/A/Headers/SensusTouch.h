//
//  SensusTouch
//  Sensus SDK
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

typedef enum {
    SensusTouchPhaseBegan,             // whenever a finger touches the surface
    SensusTouchPhaseUpdated,           // whenever a finger moves on the surface
    SensusTouchPhaseEnded,             // whenever a finger leaves the surface
} SensusTouchPhase;

typedef enum {
    SensusSensorZoneMain = 0,
    SensusSensorZoneLeft = 1,
    SensusSensorZoneRight = 2,
} SensusSensorZone;

typedef enum {
    SensusTouchForceTypeLight,
    SensusTouchForceTypeMedium,
    SensusTouchForceTypeHard
} SensusTouchForceType;

@interface SensusTouch : NSObject <NSCopying>

// Persistent Identifier for this Touch
@property (nonatomic, readonly) NSUInteger identifier;

// The time this Touch was created
@property (nonatomic, readonly) NSTimeInterval timestamp;

// The current phase of the Touch
@property (nonatomic, readonly) SensusTouchPhase phase;

// Location of Touch. Accounts for interface orientation.
@property (nonatomic, readonly) CGPoint location;

// The previous location of this Touch
@property (nonatomic, readonly) CGPoint previousLocation;

// The very first location of this Touch
@property (nonatomic, readonly) CGPoint startLocation;

// The translation (location - previousLocation) of this Touch
@property (nonatomic, readonly) CGPoint translation;

// The total translation (location - startLocation) of this Touch
@property (nonatomic, readonly) CGPoint totalTranslation;

// The velocity vector (translation / time delta from last Touch)
@property (nonatomic, readonly) CGPoint velocity;

// The speed (sqrt(velocity.x ^ 2 + velocity.y ^ 2))
@property (nonatomic, readonly) CGFloat speed;

// The intensity of the touch pressure (0 to 1)
@property (nonatomic, readonly) CGFloat force;

// A simplified force type for the touch (Light, Normal, Hard)
@property (nonatomic, readonly) SensusTouchForceType forceType;

// The number of times this Touch has been reported
@property (nonatomic, readonly) NSUInteger reports;

// The part of the Sensus where the touch occurred: main (back), left, or right
@property (nonatomic, readonly) SensusSensorZone zone;

// The location of this touch in a particular UIView
- (CGPoint)locationInView:(UIView *)view;

@end
