//
//  PredixGoReferenceAppUITests.swift
//  PredixGoReferenceAppUITests
//
//  Created by Johns, Andy (GE Corporate) on 8/10/15.
//  Copyright © 2015 GE. All rights reserved.
//

import XCTest

class PredixMobileiOSUITests: XCTestCase {
        
    override func setUp() {
        super.setUp()
        
        // Put setup code here. This method is called before the invocation of each test method in the class.
        
        // In UI tests it is usually best to stop immediately when a failure occurs.
        continueAfterFailure = false

        // if system notification pops up, dismiss
        addUIInterruptionMonitor(withDescription: "Allow Notifications Dialog") { (alert) -> Bool in
            alert.buttons["Don\u{2019}t Allow"].tap()
            XCUIApplication().tap()
            return true
        }

        // UI tests must launch the application that they test. Doing this in setup will make sure it happens for each test method.
        let app = XCUIApplication()
        app.launch()
        app.tap()
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testExample() {
        // Use recording to get started writing UI tests.
        // Use XCTAssert and related functions to verify your tests produce the correct results.


    }

    
}
