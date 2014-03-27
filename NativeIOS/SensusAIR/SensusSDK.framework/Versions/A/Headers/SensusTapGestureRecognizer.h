//
//  SensusTapGestureRecognizer.h
//  Sensus Gestures
//

#import <SensusSDK/SensusGestureRecognizer.h>

// Recognizes: when numberOfTouchesRequired have tapped numberOfTapsRequired times

// Touch Location Behaviors:
//     locationInView:         location of the tap, from the first tap in the sequence if numberOfTapsRequired > 1. this is the centroid if numberOfTouchesRequired > 1
//     locationOfTouch:inView: location of a particular touch, from the first tap in the sequence if numberOfTapsRequired > 1


@interface SensusTapGestureRecognizer : SensusGestureRecognizer

@property (nonatomic) NSUInteger numberOfTapsRequired;       // Default is 1. The number of taps required to match
@property (nonatomic) NSUInteger numberOfTouchesRequired;    // Default is 1. The number of fingers required to match

@end
