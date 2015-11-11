#import <Foundation/Foundation.h>
#import "WMFPageCollectionViewController.h"

NS_ASSUME_NONNULL_BEGIN

@class MWKArticle;

@class WMFArticleHeaderImageGalleryViewController;
@protocol WMFArticleHeaderImageGalleryViewControllerDelegate <NSObject>

- (void)headerImageGallery:(WMFArticleHeaderImageGalleryViewController*)gallery didSelectImageAtIndex:(NSUInteger)index;

@end

/**
 *  Simple image gallery using image URLs extracted from the article content.
 *
 *  Designed to show the lead image or thumbnail while article content is being downloaded.  Once article content is
 *  available, this becomes a miniature scrolling gallery of all article images.
 */
@interface WMFArticleHeaderImageGalleryViewController : WMFPageCollectionViewController

@property (nonatomic, weak) id<WMFArticleHeaderImageGalleryViewControllerDelegate> delegate;

/**
 *  Reset the images displayed by the receiver to those in the given article.
 *
 *  If @c article is not cached, the receiver will attempt to show single image view with either @c article.image or
 *  @c article.thumbnailImage.
 *
 *  @param article The article whose images should populate the gallery.
 */
- (void)setImagesFromArticle:(MWKArticle*)article;

@end

NS_ASSUME_NONNULL_END
