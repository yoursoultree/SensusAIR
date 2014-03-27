//
//  SensusForceFrame
//  Sensus SDK
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#import <SensusSDK/SensusTouch.h>

@interface SensusForceFrame : NSObject <NSCopying>

// Frame Identifier
@property (nonatomic, readonly) NSUInteger identifier;

// The time this Frame was created
@property (nonatomic, readonly) NSTimeInterval timestamp;

// Query the Force Map. Location is a position within top left (0,0) to bottom right (1,1) in Portrait Orientation
// Returns a value from 0.0 (no force) to 1.0 (max force)
- (CGFloat)forceAtLocation:(CGPoint)location forArea:(SensusSensorZone)sensusArea;

// Averages the force data for an area. This value will typically be very close to 0.f
// Returns a value from 0.0 (no force) to 1.0 (max force)
- (CGFloat)averageForceForArea:(SensusSensorZone)sensusArea;

// Returns the total force for an area. See maxTotalForceForArea.
- (CGFloat)totalForceForArea:(SensusSensorZone)sensusArea;

// Returns a maximum total force value for an area.
- (CGFloat)maxTotalForceForArea:(SensusSensorZone)sensusArea;

@end
