//
//  SensusSwipeGestureRecognizer.h
//  Sensus Gestures
//

#import <SensusSDK/SensusGestureRecognizer.h>

typedef NS_OPTIONS(NSUInteger, SensusSwipeGestureRecognizerDirection) {
  SensusSwipeGestureRecognizerDirectionRight = 1 << 0,
  SensusSwipeGestureRecognizerDirectionLeft  = 1 << 1,
  SensusSwipeGestureRecognizerDirectionUp    = 1 << 2,
  SensusSwipeGestureRecognizerDirectionDown  = 1 << 3
};


@interface SensusSwipeGestureRecognizer : SensusGestureRecognizer

@property (nonatomic) NSUInteger numberOfTouchesRequired; // default is 1. the number of fingers that must swipe
@property (nonatomic) SensusSwipeGestureRecognizerDirection direction;               // default is SensusSwipeGestureRecognizerDirectionRight. the desired direction of the swipe. multiple directions may be specified if they will result in the same behavior (for example, UITableView swipe delete)

@end
