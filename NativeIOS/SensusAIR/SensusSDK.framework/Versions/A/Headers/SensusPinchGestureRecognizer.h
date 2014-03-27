//
//  SensusPinchGestureRecognizer.h
//  Sensus Gestures
//

#import <SensusSDK/SensusGestureRecognizer.h>


@interface SensusPinchGestureRecognizer : SensusGestureRecognizer

@property (nonatomic) CGFloat scale;               // scale relative to the touch points in screen coordinates
@property (nonatomic,readonly) CGFloat velocity;   // velocity of the pinch in scale/second

@end
