//
// Created by Johns, Andy (GE Corporate) on 3/26/15.
// Copyright (c) 2015 General Electric Company. All rights reserved.
//

//
// Swift-defined typealias is not usable in ObjC, so we'll keep these definitions in ObjC for interoperability.
//
typedef void (^dataReturnBlock) (NSData* __nullable responseData);
typedef void (^responseReturnBlock) (NSURLResponse* __nullable response);
typedef void (^requestCompleteBlock) ();
typedef void (^taskCompleteBlock) (bool success, NSError* __nullable error);
typedef void (^taskReturnDictionaryBlock) (bool success, NSError* __nullable error, NSDictionary* __nullable dictionary);
typedef void (^taskReturnDictionaryArrayBlock) (bool success, NSError* __nullable error, NSArray <NSDictionary*> * __nullable dictionaryArray);

@interface NSString(SHA512)
- (NSString * _Nonnull)getSHA512Hash;
@end
