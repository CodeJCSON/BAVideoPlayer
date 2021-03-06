
/*!
 *  @header BAKit.h
 *          BABaseProject
 *
 *  @brief  BAKit
 *
 *  @author 博爱
 *  @copyright    Copyright © 2016年 博爱. All rights reserved.
 *  @version    V1.0
 */

//                            _ooOoo_
//                           o8888888o
//                           88" . "88
//                           (| -_- |)
//                            O\ = /O
//                        ____/`---'\____
//                      .   ' \\| |// `.
//                       / \\||| : |||// \
//                     / _||||| -:- |||||- \
//                       | | \\\ - /// | |
//                     | \_| ''\---/'' | |
//                      \ .-\__ `-` ___/-. /
//                   ___`. .' /--.--\ `. . __
//                ."" '< `.___\_<|>_/___.' >'"".
//               | | : `- \`.;`\ _ /`;.`/ - ` : | |
//                 \ \ `-. \_ __\ /__ _/ .-` / /
//         ======`-.____`-.___\_____/___.-`____.-'======
//                            `=---='
//
//         .............................................
//                  佛祖镇楼                  BUG辟易
//          佛曰:
//                  写字楼里写字间，写字间里程序员；
//                  程序人员写程序，又拿程序换酒钱。
//                  酒醒只在网上坐，酒醉还来网下眠；
//                  酒醉酒醒日复日，网上网下年复年。
//                  但愿老死电脑间，不愿鞠躬老板前；
//                  奔驰宝马贵者趣，公交自行程序员。
//                  别人笑我忒疯癫，我笑自己命太贱；
//                  不见满街漂亮妹，哪个归得程序员？

/*
 
 *********************************************************************************
 *
 * 在使用BAKit的过程中如果出现bug请及时以以下任意一种方式联系我，我会及时修复bug
 *
 * QQ     : 可以添加SDAutoLayout群 497140713 在这里找到我(博爱1616【137361770】)
 * 微博    : 博爱1616
 * Email  : 137361770@qq.com
 * GitHub : https://github.com/boai
 * 博客园  : http://www.cnblogs.com/boai/
 * 博客    : http://boai.github.io
 
 *********************************************************************************
 
 */


#import <UIKit/UIKit.h>

/*! 全屏按钮被点击的通知 */
#define BAPlayerFullScreenButtonClickedNotification @"BAPlayerFullScreenButtonClickedNotification"

/*! 关闭播放器的通知 */
//#define BAPlayerClosedNotification @"BAPlayerClosedNotification"

/*! 播放完成的通知 */
#define BAPlayerFinishedPlayNotification @"BAPlayerFinishedPlayNotification"


/*! 播放器的几种状态 */
typedef NS_ENUM(NSInteger, BAPlayerState) {
    BAPlayerStateFailed,     // 播放失败
    BAPlayerStateBuffering,  // 缓冲中
    BAPlayerStatePlaying,    // 播放中
    BAPlayerStateStopped,    // 停止播放
    BAPlayerStatePause       // 暂停播放
};

/*! 返回按钮的block */
typedef void(^BAPlayerGoBackBlock)(void);

@import MediaPlayer;
@import AVFoundation;
@interface BAVideoPlayerView : UIView

@property (nonatomic ,strong) AVPlayer             *player;
@property (nonatomic ,strong) AVPlayerItem         *playerItem;
@property (nonatomic,strong ) AVPlayerLayer        *playerLayer;
/** 视频URL */
@property (nonatomic, strong) NSURL                *videoURL;
/** 全屏按钮 */
@property (nonatomic, strong) UIButton             *fullScreenBtn;
@property (nonatomic, assign) BOOL                  isFullScreen;

@property (nonatomic, assign) BOOL                  isPlaying;
/** bottomView*/
@property (nonatomic, strong) UIImageView          *bottomImageView;
/** topView */
@property (nonatomic, strong) UIImageView          *topImageView;
/** 返回按钮*/
@property (nonatomic, strong) UIButton             *backBtn;
/*! 返回按钮Block */
@property (nonatomic, copy  ) BAPlayerGoBackBlock   goBackBlock;



/*! 播放并判断是否重新加载当前url资源 */
- (void)play;

/*! 播放并判断是否重新加载当前url资源 */
-(void)pause;

/*! 关闭播放器并销毁当前播放view, 一定要在退出时使用,否则内存可能释放不了 */
-(void)close;

- (instancetype)initWithFrame:(CGRect)frame WithUrlString:(NSString *)urlString;

@end
