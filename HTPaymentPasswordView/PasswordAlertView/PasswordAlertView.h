//
//  PasswordAlertView.h
//  自定义密码输入框
//
//  Created by ZXW on 2016/12/15.
//  modified by YoungJeXu 2018/1/23
//

#import <UIKit/UIKit.h>

typedef enum {
    PasswordAlertViewType_default, //从window中间弹出，有确定按钮
    PasswordAlertViewType_Without, //从window中间弹出,没有确定按钮
    PasswordAlertViewType_sheet,   //从底部弹出
    PasswordAlertViewType_withoutlabels
}PasswordAlertViewType;


@protocol PasswordAlertViewDelegate <NSObject>

//点击了确定按钮  或者是完成了6位密码的输入
-(void)PasswordAlertViewCompleteInputWith:(NSString*)password;
//点击了取消按钮
-(void)PasswordAlertViewDidClickCancleButton;
//点击了忘记密码按钮
-(void)PasswordAlertViewDidClickForgetButton;
@end




@interface PasswordAlertView : UIView

@property (nonatomic,weak) id<PasswordAlertViewDelegate> delegate;
@property (nonatomic,strong) UILabel *titleLable;  //标题
@property (nonatomic,strong) UILabel *trasferLable;  //转账标题
@property (nonatomic,strong) UILabel *moneyStatusLable;  //金额标题
@property (nonatomic,strong) UILabel *moneyLable;  //金额标题
@property (nonatomic,strong) UILabel *tipsLalbe;   //输入框下面的提示lable（如提示密码错误) 默认隐藏 当调用密码错误的方法时就显示出来

- (instancetype)initWithType:(PasswordAlertViewType)type;

-(void)show;

//密码正确后调用这个方法
-(void)passwordCorrect;

//密码错误后调用这个方法
-(void)passwordError;

-(void)moneyLess;

@end
