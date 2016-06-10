//
//  TestViewController.swift
//  PredixMobileiOS
//
//  Created by Johns, Andy (GE Corporate) on 10/22/15.
//  Copyright © 2015 GE. All rights reserved.
//

import Foundation
import UIKit
import PredixMobileSDK

class TestViewController : UIViewController, PredixAppWindowProtocol
{
    var loadedURL : NSURL?
    var loadedParameters : [NSObject : AnyObject]?
    var savedWaitState :WaitState = WaitState.NotWaiting
    var savedWaitStateMessage : String?
    
    var viewController: UIViewController {get{ return self}}
    
    func loadURL(URL: NSURL, parameters: [NSObject : AnyObject]?, onComplete: (()->())?)
    {
        self.loadedURL = URL
        self.loadedParameters = parameters
        let notificationName = "TestViewController.LoadedURL"
        PGSDKLogger.info("Posting notification: \(notificationName)")
        NSNotificationCenter.defaultCenter().postNotificationName(notificationName, object: self)
        
        if let onComplete = onComplete
        {
            onComplete()
        }
    }
    
    func updateWaitState(state: WaitState, message: String?)
    {
        self.savedWaitState = state
        self.savedWaitStateMessage = message
    }
    
    func waitState()->(WaitStateReturn)
    {
        return WaitStateReturn(self.savedWaitState, self.savedWaitStateMessage)
    }

}