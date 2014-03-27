//
//  SensusRotateGestureRecognizer.h
//  Sensus Gestures
//

#import <SensusSDK/SensusGestureRecognizer.h>

@interface SensusRotationGestureRecognizer : SensusGestureRecognizer
@property (nonatomic) CGFloat rotation;             // rotation in radians
@property (nonatomic,readonly) CGFloat velocity;    // velocity of the pinch in radians/second
@end
