//
//  IAPManager.h
//
//  Created by Mr. on 2019/6/11.
//  Copyright 哆来咪(北京)科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@protocol IAPManagerDelegate <NSObject>

/*
 -1 不允许内购
 1000 苹果APP上注册的产品ID列表没有找到请求内购的产品id。
 1001 SKRequest请求失败
 2000 交易失败
 2001 交易取消
 3000 交易凭证为空
 */
-(void)iapRequestFailedCode:(NSInteger)code didFailWithError:(NSError *_Nullable)error;
/// 购买成功将交易凭证发送给服务端进行再次校验
-(void)iapRequestSucceedWithTransactionReceipt:(NSData*)receipt;
/*
 NSNumber: 4000 苹果服务器验证失败
           4001 苹果服务器验证返回为空
 NSDictionary :返回结果
 */
-(void)iapAppstoreValidateResult:(id)result didFailWithError:(NSError *_Nullable)error;

@end


@interface IAPManager : NSObject

+ (instancetype)share;
-(void)iapRequestWithProductId:(NSString* _Nullable)productId handleDelegate:(id<IAPManagerDelegate> _Nullable)delegate;
@end

NS_ASSUME_NONNULL_END
