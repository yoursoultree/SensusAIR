//
//  SensusLongPressGestureRecognizer.h
//  Sensus Gestures
//

#import <SensusSDK/SensusGestureRecognizer.h>


@interface SensusLongPressGestureRecognizer : SensusGestureRecognizer

@property (nonatomic) NSUInteger numberOfTapsRequired;      // Default is 0. The number of full taps required before the press for gesture to be recognized
@property (nonatomic) NSUInteger numberOfTouchesRequired;   // Default is 1. Number of fingers that must be held down for the gesture to be recognized
@property (nonatomic) CFTimeInterval minimumPressDuration; // Default is 0.5. Time in seconds the fingers must be held down for the gesture to be recognized
@property (nonatomic) CGFloat allowableMovement;           // Default is 20. Maximum movement in points allowed before the gesture fails. Once recognized (after minimumPressDuration) there is no limit on finger movement for the remainder of the touch tracking

@end
