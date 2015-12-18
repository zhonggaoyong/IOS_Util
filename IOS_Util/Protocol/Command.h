//
//  Command.h
//  Lottery_JiangXi
//
//  Created by 钟高勇 on 15/3/17.
//  Copyright (c) 2015年 WZL. All rights reserved.
//

#import <Foundation/Foundation.h>



//指令 CMD
typedef NS_ENUM (NSInteger,Commands){
    //H5模块网络状态
    H5_MODULE_STATE,
    H5_MODULE_DOWN,
    //开奖
    LOTTERYDRAW,
    //开奖详情
    LOTTERYDRAW_INFO,
    //近期开奖
    LATELYLOTTERYDRAW,
    //竞彩赛事信息
    LOTTERY_IFNO,
    //竞彩赔率
    LOTTERY_SP,
    //获取验证码
    GETCODE,
    //退出登录
    LOGOUT,
    //注册
    REGISTER,
    //登陆
    LOGIN,
    //验证/绑定手机
    BINDPHONE,
    //修改用户名
    RENAME,
    //修改资料
    SETDATA,
    //修改密码
    SETNEWPWD,
    //验证手机
    VERIFYCODE,
    //找回密码
    BACKPASSWORD,
    //获取已绑定银行列表
    BANKLIST,
    //退出登录
    USER_LOGOUT,
    //绑定银行
    BINDBANK,
    //获取验证码
    FINDCODE,
    //查询用户信息
    USERINFO,
    //投注详情
    ALLBETTING,
    //足彩期次
    FOOTBALLLOTTERYPERIOD,
    //进行投注
    FOOTBALLBETTING,
    // 数字彩投注
    SZCBALLBETTING,
    //获取预售期
    PRELOTTERYDRAW,
    //号码遗漏
    CHARTMALL,
    //大乐透开奖记录
    LOTTERYDRAW_DLT,
    //获取开奖记录详情
    ORDERDETAIL,
    //获取中奖号码
    ORDERCODE,
    //获取追号中奖号码
    ZHORDERCODE,
    //获取追号记录详情
    ZHORDERDETAIL,
    //支付宝支付
    ALIPAYRECHARGE,
    //银联支付
    UNION,
    //彩金充值卡
    WZLCARDCHARGE,
    //微信支付
    WXRECHAREG,
    //账户明细、全部
    ACCOUNTDETAILALL,
    //账户明细 充值
    ACCOUNTDETAILRECHARGE,
    //账户明细 提现
    ACCOUNTDETAILWITHDRAWAL,
    //账户明细 返奖
    ACCOUNTDETAILRETURNAWARD,
    //账户明细 投注
    ACCOUNTDETAILBETTING,
    //提现
    OUTCASH,
    //彩票状态(停售、在售)
    GETSTATUS,
    //首页广告
    GETIMAGE,
    //支持充值、提现的所有版本
    VERSIONS

};

@interface Command : NSObject

@end
