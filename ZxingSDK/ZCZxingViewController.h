//
//  ZCZxingViewController.h
//  ZxingDemo1125
//
//  Created by ZhangCheng on 14-4-18.
//  Copyright (c) 2014年 ZhangCheng. All rights reserved.
//
/*
 版本说明 iOS中国开发者2群 305044955
 1.2版本 ZC封装的Zxing二维码SDK
 1、更新类名从CustomViewController更改为ZCZxingViewController
 2、删除掉代理的相关代码
 1.1版本 ZC封装的Zxing二维码SDK~
 1、增加block回调
 2、取消代理
 3、增加适配IOS7（ios7在AVFoundation中增加了扫描二维码功能）
 1.0版本 ZC封装的Zxing二维码SDK~1.0版本初始建立

 */


/*
 二维码编译顺序
 把zxing目录整个移动到iOS项目的目录下（不是拖到工程里），把ZXingWidget.xcodeproj文件（只有这一个单一文件）拖进工程内
 然后增加 Target Dependencies 和 Link binary（与自己工程建立连接）
 在header Search path添加以下路径
 ./zxing/iphone/ZXingWidget/Classes/**  ./zxing/cpp/core/src
 添加以下框架    AVFoundation、Audio Toolbox、CoreVideo、CoreMedia、libiconv、AddressBook、AddressBookUI
 需要注意：
 1、TARGETS -> Build Settings -> Apple LLVM compiler 4.1 - Language
 设置C++ Standard Library的值为Compiler Default
 设置C++ Language Dialect的值为Compiler Default
 设置C Language Dialect的值为C99[-std=c99]
 2、Zxing库为C++库，所以必须有一个文件支持C++，即至少有一个文件后缀名为.mm文件
 如果出现找不到#import <Decoder.h>文件，请检查以上步骤
 
//示例代码
扫描
ZCZxingViewController*vc=[[ZCZxingViewController alloc]initWithBlock:^(NSString *str, BOOL isScceed) {
 if (isScceed) {
 NSLog(@"扫描成功~%@",str);
 }else{
 NSLog(@"扫描失败");
 }
 }];
 
 [self presentViewController:vc animated:YES completion:nil];
 
 
 
生成二维码
 拖拽libqrencode包进入工程，注意点copy
 添加头文件#import "QRCodeGenerator.h"
imageView.image=[QRCodeGenerator qrImageForString:@"这个是什么" imageSize:imageView.bounds.size.width];
 */
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <Decoder.h>

#define IOS7 [[[UIDevice currentDevice] systemVersion]floatValue]>=7
@interface ZCZxingViewController : UIViewController<UIAlertViewDelegate, DecoderDelegate, AVCaptureVideoDataOutputSampleBufferDelegate, UINavigationControllerDelegate, UIImagePickerControllerDelegate,AVCaptureMetadataOutputObjectsDelegate>

@property (nonatomic,strong) AVCaptureVideoPreviewLayer *captureVideoPreviewLayer;
@property (nonatomic, strong) AVCaptureSession *captureSession;
@property (nonatomic, assign) BOOL isScanning;
@property (nonatomic,copy)void(^ScanResult)(NSString*result,BOOL isSucceed);
//初始化函数
-(id)initWithBlock:(void(^)(NSString*,BOOL))a;
//正则表达式
+(NSString*)zhengze:(NSString*)str;

@end
