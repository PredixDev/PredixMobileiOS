//
//  ServiceProtocolTestHelper.swift
//  PredixMobileiOS
//
//  Created by Johns, Andy (GE Corporate) on 8/12/15.
//  Copyright © 2015 GE. All rights reserved.
//

import Foundation
import PredixMobileiOS
import PredixMobileSDK
import XCTest

extension XCTestCase
{
    func setupPMM()
    {
        // ensure clean slate
        let testViewController = TestViewController()
        
        _ = PredixMobilityManager(packageWindow: testViewController, presentAuthentication: { (packageWindow) -> (PredixAppWindowProtocol) in
            
            let authVC = TestViewController()
            return authVC as PredixAppWindowProtocol
            
            }, dismissAuthentication: { (authenticationWindow) -> () in
                
        })
    }
    
    func serviceTester(service: ServiceProtocol.Type, path: String, expectedStatusCode: HTTPStatusCode, testResponse testResponseOptional: ((NSURLResponse) -> Void)?, testData testDataOptional: ((NSData) -> Void)?)
    {
        let request = NSURLRequest(URL: NSURL(string: path)!)
        serviceTester(service, request: request, expectedStatusCode: expectedStatusCode, testResponse: testResponseOptional, testData: testDataOptional)
    }
    
    func serviceTester(service: ServiceProtocol.Type, request: NSURLRequest, expectedStatusCode: HTTPStatusCode, testResponse testResponseOptional: ((NSURLResponse) -> Void)?, testData testDataOptional: ((NSData) -> Void)?)
    {
        ServiceRouter.sharedInstance.registerService(service)
        let serviceName = NSStringFromClass(service)
        let testExpectation = self.expectationWithDescription("\(#function):\(serviceName)")
        
        ServiceRouter.sharedInstance.processRequest(request, responseBlock: { (responseOptional : NSURLResponse?) -> Void in
            
            if let response = responseOptional as? NSHTTPURLResponse
            {
                XCTAssertEqual(response.statusCode, expectedStatusCode.rawValue, "Response status code was different from expected")
                if let testResponse = testResponseOptional
                {
                    testResponse(response)
                }
            }
            else
            {
                XCTAssert(false, "\(serviceName) service returned nil response")
            }
            
            }, dataBlock: { (dataOptional : NSData?) -> Void in
                
                if let testData = testDataOptional
                {
                    if let data = dataOptional
                    {
                        testData(data)
                    }
                    else
                    {
                        XCTAssert(false, "Data test function supplied, but no test data was returned from call.")
                    }
                }
                
            }, completionBlock: { () -> Void in
                testExpectation.fulfill()
        })
        
        self.waitForExpectationsWithTimeout(20, handler: nil)
        ServiceRouter.sharedInstance.unregisterService(service)
    }
    
    func userDataURL() -> NSURL
    {
        var appSupportURL = NSFileManager.defaultManager().URLsForDirectory(.ApplicationSupportDirectory, inDomains: .UserDomainMask)[0]
        
        if let bundleId = NSBundle.mainBundle().bundleIdentifier
        {
            appSupportURL = appSupportURL.URLByAppendingPathComponent(bundleId)
        }
        
        return appSupportURL.URLByAppendingPathComponent("UserData")
    }
}