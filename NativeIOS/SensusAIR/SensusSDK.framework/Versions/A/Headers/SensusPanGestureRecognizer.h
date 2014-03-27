//
//  SensusPanGestureRecognizer.h
//  Sensus Gestures
//

#import <SensusSDK/SensusGestureRecognizer.h>

@interface SensusPanGestureRecognizer : SensusGestureRecognizer
@property (nonatomic) NSUInteger minimumNumberOfTouches;   // default is 1. the minimum number of touches required to match
@property (nonatomic) NSUInteger maximumNumberOfTouches;   // default is UINT_MAX. the maximum number of touches that can be down

- (CGPoint)translationInView:(UIView *)view;               // translation in the coordinate system of the specified view
- (void)setTranslation:(CGPoint)translation inView:(UIView *)view;

- (CGPoint)velocityInView:(UIView *)view;                  // velocity of the pan in pixels/second in the coordinate system of the specified view
@end