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
    
    func serviceTester(_ service: ServiceProtocol.Type, path: String, expectedStatusCode: HTTPStatusCode, testResponse testResponseOptional: ((URLResponse) -> Void)?, testData testDataOptional: ((Data) -> Void)?)
    {
        let request = URLRequest(url: URL(string: path)!)
        serviceTester(service, request: request, expectedStatusCode: expectedStatusCode, testResponse: testResponseOptional, testData: testDataOptional)
    }
    
    func serviceTester(_ service: ServiceProtocol.Type, request: URLRequest, expectedStatusCode: HTTPStatusCode, testResponse testResponseOptional: ((URLResponse) -> Void)?, testData testDataOptional: ((Data) -> Void)?)
    {
        ServiceRouter.sharedInstance.registerService(service)
        let serviceName = NSStringFromClass(service)
        let testExpectation = self.expectation(description: "\(#function):\(serviceName)")
        
        ServiceRouter.sharedInstance.processRequest(request, responseBlock: { (responseOptional : URLResponse?) -> Void in
            
            if let response = responseOptional as? HTTPURLResponse
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
            
            }, dataBlock: { (dataOptional : Data?) -> Void in
                
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
        
        self.waitForExpectations(timeout: 20, handler: nil)
        ServiceRouter.sharedInstance.unregisterService(service)
    }
    
    func userDataURL() -> URL
    {
        var appSupportURL = FileManager.default.urls(for: .applicationSupportDirectory, in: .userDomainMask)[0]
        
        if let bundleId = Bundle.main.bundleIdentifier
        {
            appSupportURL = appSupportURL.appendingPathComponent(bundleId)
        }
        
        return appSupportURL.appendingPathComponent("UserData")
    }
}
