//
//  SensusGestureRecognizer.h
//  Sensus Gestures
//

#import <Foundation/Foundation.h>
#import <SensusSDK/Sensus.h>

@protocol SensusGestureRecognizerDelegate;

typedef NS_ENUM(NSInteger, SensusGestureRecognizerState) {
    SensusGestureRecognizerStatePossible,   // the recognizer has not yet recognized its gesture, but may be evaluating touch events. this is the default state
    
    SensusGestureRecognizerStateBegan,      // the recognizer has received touches recognized as the gesture. the action method will be called at the next turn of the run loop
    SensusGestureRecognizerStateChanged,    // the recognizer has received touches recognized as a change to the gesture. the action method will be called at the next turn of the run loop
    SensusGestureRecognizerStateEnded,      // the recognizer has received touches recognized as the end of the gesture. the action method will be called at the next turn of the run loop and the recognizer will be reset to SensusGestureRecognizerStatePossible
    SensusGestureRecognizerStateCancelled,  // the recognizer has received touches resulting in the cancellation of the gesture. the action method will be called at the next turn of the run loop. the recognizer will be reset to SensusGestureRecognizerStatePossible
    
    SensusGestureRecognizerStateFailed,     // the recognizer has received a touch sequence that can not be recognized as the gesture. the action method will not be called and the recognizer will be reset to SensusGestureRecognizerStatePossible
    
    // Discrete Gestures – gesture recognizers that recognize a discrete event but do not report changes (for example, a tap) do not transition through the Began and Changed states and can not fail or be cancelled
    SensusGestureRecognizerStateRecognized = SensusGestureRecognizerStateEnded // the recognizer has received touches recognized as the gesture. the action method will be called at the next turn of the run loop and the recognizer will be reset to SensusGestureRecognizerStatePossible
};



@interface SensusGestureRecognizer : NSObject

- (id)initWithTarget:(id)target action:(SEL)action; // default initializer

- (void)addTarget:(id)target action:(SEL)action;    // add a target/action pair. you can call this multiple times to specify multiple target/actions
- (void)removeTarget:(id)target action:(SEL)action; // remove the specified target/action pair. passing nil for target matches all targets, and the same for actions

@property (nonatomic, readonly) SensusGestureRecognizerState state;  // the current state of the gesture recognizer

@property (nonatomic, assign) id <SensusGestureRecognizerDelegate> delegate; // the gesture recognizer's delegate

@property (nonatomic, getter=isEnabled) BOOL enabled;  // default is YES. disabled gesture recognizers will not receive touches. when changed to NO the gesture recognizer will be cancelled if it's currently recognizing a gesture

// a SensusGestureRecognizer receives touches hit-tested to its view and any of that view's subviews
@property (nonatomic, readonly) UIView *view;           // the view the gesture is attached to. set by adding the recognizer to a UIView using the addGestureRecognizer: method

@property (nonatomic) BOOL cancelsTouchesInView;       // default is YES. causes touchesCancelled:withEvent: to be sent to the view for all touches recognized as part of this gesture immediately before the action method is called
@property (nonatomic) BOOL delaysTouchesBegan;         // default is NO.  causes all touch events to be delivered to the target view only after this gesture has failed recognition. set to YES to prevent views from processing any touches that may be recognized as part of this gesture
@property (nonatomic) BOOL delaysTouchesEnded;         // default is YES. causes touchesEnded events to be delivered to the target view only after this gesture has failed recognition. this ensures that a touch that is part of the gesture can be cancelled if the gesture is recognized

// create a relationship with another gesture recognizer that will prevent this gesture's actions from being called until otherGestureRecognizer transitions to SensusGestureRecognizerStateFailed
// if otherGestureRecognizer transitions to SensusGestureRecognizerStateRecognized or SensusGestureRecognizerStateBegan then this recognizer will instead transition to SensusGestureRecognizerStateFailed
// example usage: a single tap may require a double tap to fail
- (void)requireGestureRecognizerToFail:(SensusGestureRecognizer *)otherGestureRecognizer;

// individual SensusGestureRecognizer subclasses may provide subclass-specific location information. see individual subclasses for details
- (CGPoint)locationInView:(UIView *)view;                                // a generic single-point location for the gesture. usually the centroid of the touches involved

- (NSUInteger)numberOfTouches;                                          // number of touches involved for which locations can be queried
- (CGPoint)locationOfTouch:(NSUInteger)touchIndex inView:(UIView *)view; // the location of a particular touch

@end


@protocol SensusGestureRecognizerDelegate <NSObject>
@optional
// called when a gesture recognizer attempts to transition out of SensusGestureRecognizerStatePossible. returning NO causes it to transition to SensusGestureRecognizerStateFailed
- (BOOL)sensusGestureRecognizerShouldBegin:(SensusGestureRecognizer *)gestureRecognizer;

// called when the recognition of one of gestureRecognizer or otherGestureRecognizer would be blocked by the other
// return YES to allow both to recognize simultaneously. the default implementation returns NO (by default no two gestures can be recognized simultaneously)
//
// note: returning YES is guaranteed to allow simultaneous recognition. returning NO is not guaranteed to prevent simultaneous recognition, as the other gesture's delegate may return YES
- (BOOL)sensusGestureRecognizer:(SensusGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(SensusGestureRecognizer *)otherGestureRecognizer;

// called once per attempt to recognize, so failure requirements can be determined lazily and may be set up between recognizers across view hierarchies
// return YES to set up a dynamic failure requirement between gestureRecognizer and otherGestureRecognizer
//
// note: returning YES is guaranteed to set up the failure requirement. returning NO does not guarantee that there will not be a failure requirement as the other gesture's counterpart delegate or subclass methods may return YES
- (BOOL)sensusGestureRecognizer:(SensusGestureRecognizer *)gestureRecognizer shouldRequireFailureOfGestureRecognizer:(SensusGestureRecognizer *)otherGestureRecognizer;
- (BOOL)sensusGestureRecognizer:(SensusGestureRecognizer *)gestureRecognizer shouldBeRequiredToFailByGestureRecognizer:(SensusGestureRecognizer *)otherGestureRecognizer;

// called before touchesBegan:withEvent: is called on the gesture recognizer for a new touch. return NO to prevent the gesture recognizer from seeing this touch
- (BOOL)sensusGestureRecognizer:(SensusGestureRecognizer *)gestureRecognizer shouldReceiveTouch:(UITouch *)touch;

@end
