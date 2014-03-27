//
//  SensusSqueezeGestureRecognizer
//  Sensus Gestures
//

#import <SensusSDK/Sensus.h>
#import <SensusSDK/SensusGestureRecognizer.h>


typedef NS_OPTIONS(NSUInteger, SensusGestureArea) {
    SensusGestureAreaBack          = 1 << 1,
    SensusGestureAreaEdgeLeft      = 1 << 2,
    SensusGestureAreaEdgeRight     = 1 << 3,
};


@interface SensusSqueezeGestureRecognizer : SensusGestureRecognizer

@property (nonatomic) CGFloat forceRequired;

/// Optional SensusAreas Mask to use for summing force
@property (nonatomic) SensusGestureArea activeAreas;

@end