//
//  UIView+SensusGestureRecognizers.h
//  Sensus Gestures
//

#import <SensusSDK/SensusGestureRecognizer.h>


@interface UIView (SensusGestureRecognizers)

@property (nonatomic, copy) NSArray *sensusGestureRecognizers;

- (void)addSensusGestureRecognizer:(SensusGestureRecognizer *)gestureRecognizer;
- (void)removeSensusGestureRecognizer:(SensusGestureRecognizer *)gestureRecognizer;

- (BOOL)sensusGestureRecognizerShouldBegin:(SensusGestureRecognizer *)gestureRecognizer;

@end
