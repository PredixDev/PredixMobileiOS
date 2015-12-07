//
//  ViewController.swift
//  PredixMobileReferenceApp
//
//  Created by Johns, Andy (GE Corporate) on 8/10/15.
//  Copyright © 2015 GE. All rights reserved.
//

import UIKit
import PredixMobileSDK

class ViewController: UIViewController, UIWebViewDelegate, PredixAppWindowProtocol {

    @IBOutlet var webView: UIWebView!
    @IBOutlet var spinner: UIActivityIndicatorView!
    @IBOutlet var spinnerLabel: UILabel!
    
    var webViewFinishedLoad : (()->())?
    
    func loadURL(URL: NSURL, parameters: [NSObject : AnyObject]?, onComplete: (()->())?)
    {
        if let onComplete = onComplete
        {
            self.webViewFinishedLoad = onComplete
        }
        
        self.webView.scrollView.scrollEnabled = true
        if let params = parameters, scrollStateString = params["nativeScroll"] as? String where scrollStateString == "false"
        {
            self.webView.scrollView.scrollEnabled = false
        }
        
        self.webView.loadRequest(NSURLRequest(URL:URL))
    }
    
    func updateWaitState(state: WaitState, message: String?)
    {
        switch state
        {
        case .NotWaiting :
            self.spinner.stopAnimating()
            self.spinner.hidden = true
            self.spinnerLabel.text = nil
            self.spinnerLabel.hidden = true
            
        case .Waiting :
            
            self.spinner.hidden = false
            self.spinnerLabel.hidden = false
            self.spinner.startAnimating()
            self.spinnerLabel.text = message
        }
    }
    
    func waitState()->(WaitStateReturn)
    {
        return WaitStateReturn(state: self.spinner.hidden ? .NotWaiting : .Waiting, message: self.spinnerLabel.text)
    }
    
    func receiveAppNotification(script: String)
    {
        self.webView.stringByEvaluatingJavaScriptFromString(script)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        self.webView.delegate = self
        
        PGSDKLogger.debug("\(NSStringFromClass(self.dynamicType)).\(__FUNCTION__)")
        NSNotificationCenter.defaultCenter().postNotification(NSNotification(name: UIReadyNotification, object: nil))
        
    }

    func webViewDidStartLoad(webView: UIWebView)
    {
        PGSDKLogger.trace("Main web view starting load")
        self.spinner.startAnimating()
    }

    func webViewDidFinishLoad(webView: UIWebView)
    {
        PGSDKLogger.trace("Main web view finished load")
        self.spinner.stopAnimating()
        if let webViewFinishedLoad = self.webViewFinishedLoad
        {
            self.webViewFinishedLoad = nil
            webViewFinishedLoad()
        }
    }
    
    func webView(webView: UIWebView, didFailLoadWithError errorOptional: NSError?)
    {
        self.spinner.stopAnimating()
        
        guard let error = errorOptional else
        {
            // no error object, nothing to do...
            return
        }
        
        // Ignore cancelled and "Frame Load Interrupted" errors
        if error.code == NSURLErrorCancelled {return}
        if error.code == 102 && error.domain == "WebKitErrorDomain" {return}

        PGSDKLogger.debug("Main view encountered loading error: \(error.description)")
        ShowSeriousErrorHelper.ShowUserError(error.localizedDescription)
        

    }

}

