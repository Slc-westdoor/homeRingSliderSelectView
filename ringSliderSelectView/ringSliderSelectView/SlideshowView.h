//
//  SLGImageSlideshowView.h
//
//  Created by Steven Grace on 1/11/13.
//
//

#import <UIKit/UIKit.h>

@protocol SLGSlideshowViewDatasource;
@protocol SLGSlideshowViewDelegate;


@interface SlideshowView : UIView


/*
  Set the values for the the  behavior for all slides or implement the datasource methods to customize behavior for each slide
*/
// duration of the transition between slides 
@property(nonatomic,readwrite)NSTimeInterval transitionDuration;
// duration to present each item 
@property(nonatomic,readwrite)NSTimeInterval slideDuration;
//  a UIViewAnimationOptionTransition DEFAULT:UIViewAnimationOptionTransitionCrossDissolve
@property(nonatomic,readwrite)NSUInteger transitionOption;


@property(nonatomic,readwrite,weak) id<SLGSlideshowViewDatasource>datasource;
@property(nonatomic,readwrite,weak) id<SLGSlideshowViewDelegate>delegate;


@property(nonatomic,readonly)NSUInteger currentSection;



// repeat slideshow
@property(nonatomic,readwrite)BOOL autoRepeat;

/** PRESENTATION **/
-(void)beginSlideShow;
-(void)stopSlideShow;
-(void)pauseResumeSlideShow;
-(void)previousImage; 
-(void)nextImage;



@end


@protocol SLGSlideshowViewDatasource <NSObject>


-(NSUInteger)numberOfSectionsInSlideshow:(SlideshowView*)slideShowView;
-(NSInteger)numberOfItems:(SlideshowView*)slideShowView inSection:(NSUInteger)section;
-(UIView*)viewForSlideShow:(SlideshowView*)slideShowView atIndexPath:(NSIndexPath*)indexPath;


@optional
-(NSTimeInterval)slideDurationForSlideShow:(SlideshowView*)slideShowView atIndexPath:(NSIndexPath*)indexPath;
-(NSTimeInterval)transitionDurationForSlideShow:(SlideshowView*)slideShowView atIndexPath:(NSIndexPath*)indexPath;

// return a UIViewAnimationOptionTransition
-(NSUInteger)transitionStyleForSlideShow:(SlideshowView*)slideShowView atIndexPath:(NSIndexPath*)indexPath;



@end


@protocol SLGSlideshowViewDelegate <NSObject>

@optional


-(void)slideShowViewDidEnd:(SlideshowView*)slideShowView willRepeat:(BOOL)willRepeat;

-(void)slideShowView:(SlideshowView*)slideShowView willDisplaySlideAtIndexPath:(NSIndexPath*)indexPath;
-(void)slideShowView:(SlideshowView*)slideShowView didDisplaySlideAtIndexPath:(NSIndexPath*)indexPath;

-(void)slideShowView:(SlideshowView*)slideShowView willBeginSection:(NSUInteger)section;
-(void)slideShowView:(SlideshowView*)slideShowView didBeginSection:(NSUInteger)section;


-(void)slideShowViewDidPause:(SlideshowView*)slideShowView;
-(void)slideShowViewDidResume:(SlideshowView*)slideShowView;


@end


