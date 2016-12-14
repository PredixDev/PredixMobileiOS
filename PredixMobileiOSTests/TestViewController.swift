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
    var loadedURL : URL?
    var loadedParameters : [AnyHashable: Any]?
    var savedWaitState :WaitState = WaitState.notWaiting
    var savedWaitStateMessage : String?
    
    var viewController: UIViewController {get{ return self}}
    
    func loadURL(_ URL: Foundation.URL, parameters: [AnyHashable: Any]?, onComplete: (()->())?)
    {
        self.loadedURL = URL
        self.loadedParameters = parameters
        let notificationName = "TestViewController.LoadedURL"
        Logger.info("Posting notification: \(notificationName)")
        NotificationCenter.default.post(name: Notification.Name(rawValue: notificationName), object: self)
        
        if let onComplete = onComplete
        {
            onComplete()
        }
    }
    
    func updateWaitState(_ state: WaitState, message: String?)
    {
        self.savedWaitState = state
        self.savedWaitStateMessage = message
    }
    
    func waitState()->(WaitStateReturn)
    {
        return WaitStateReturn(self.savedWaitState, self.savedWaitStateMessage)
    }

}
