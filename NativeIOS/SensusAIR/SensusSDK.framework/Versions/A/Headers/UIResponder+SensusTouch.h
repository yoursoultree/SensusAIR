//
//  UIResponder+SensusTouch.h
//  Sensus SDK
//

#import <UIKit/UIKit.h>
#import <SensusSDK/Sensus.h>


@interface UIResponder (SensusTouch)

- (void)sensusTouchBegan:(SensusTouch *)touch;
- (void)sensusTouchUpdated:(SensusTouch *)touch;
- (void)sensusTouchEnded:(SensusTouch *)touch;

@end
