//
//  ViewController.swift
//  PredixMobileiOS
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

    internal var isAuthenticationView = false

    var webViewFinishedLoad : (() -> Void)?

    func loadURL(_ url: URL, parameters: [AnyHashable: Any]?, onComplete: (() -> Void)?) {

        if let onComplete = onComplete {
            self.webViewFinishedLoad = onComplete
        }

        self.loadViewIfNeeded()

        self.webView.scrollView.isScrollEnabled = true
        if let params = parameters, let scrollStateString = params["nativeScroll"] as? String, scrollStateString == "false" {
            self.webView.scrollView.isScrollEnabled = false
        }

        self.webView.loadRequest(URLRequest(url: url))
    }

    func updateWaitState(_ state: WaitState, message: String?) {
        switch state {
        case .notWaiting :
            self.spinner.stopAnimating()
            self.spinner.isHidden = true
            self.spinnerLabel.text = nil
            self.spinnerLabel.isHidden = true

        case .waiting :

            self.spinner.isHidden = false
            self.spinnerLabel.isHidden = false
            self.spinner.startAnimating()
            self.spinnerLabel.text = message
        }
    }

    func waitState() -> (WaitStateReturn) {
        return WaitStateReturn(state: self.spinner.isHidden ? .notWaiting : .waiting, message: self.spinnerLabel.text)
    }

    func receiveAppNotification(_ script: String) {
        self.webView.stringByEvaluatingJavaScript(from: script)
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        self.webView.delegate = self
        
        if #available(iOS 11.0, *) {
            self.webView.scrollView.contentInsetAdjustmentBehavior = .never
        }
        Logger.debug("\(NSStringFromClass(type(of: self))).\(#function)")
    }

    func webViewDidStartLoad(_ webView: UIWebView) {
        Logger.trace("Web view starting load")
        self.spinner.startAnimating()
    }

    func webViewDidFinishLoad(_ webView: UIWebView) {

        if let request = webView.request, let cachedResponse = URLCache.shared.cachedResponse(for: request), let response = cachedResponse.response as? HTTPURLResponse {
            if response.statusCode > 399 {
                Logger.error("Web view response error code: \(response.statusCode)")
                if self.isAuthenticationView {
                    Logger.error("Web view page load error (\(response.statusCode)) while autheticating. Aborting authentication")
                    PredixMobilityManager.sharedInstance.authenticationComplete()
                }
            }
        }

        Logger.trace("Web view finished load")
        self.spinner.stopAnimating()
        if let webViewFinishedLoad = self.webViewFinishedLoad {
            self.webViewFinishedLoad = nil
            webViewFinishedLoad()
        }
    }

    func webView(_ webView: UIWebView, didFailLoadWithError err: Error) {
        self.spinner.stopAnimating()

        let error = err as NSError

        // Ignore cancelled and "Frame Load Interrupted" errors
        if error.code == NSURLErrorCancelled {return}
        if error.code == 102 && error.domain == "WebKitErrorDomain" {return}

        if(isAuthenticationView) {
            Logger.error("Web view page load error (\(error)) while autheticating. Aborting authentication")
            PredixMobilityManager.sharedInstance.authenticationComplete()
        }
        Logger.debug("Web view encountered loading error: \(error.description)")
        ShowSeriousErrorHelper.ShowUserError(error.localizedDescription)
    }

    override func dismiss(animated flag: Bool, completion: (() -> Void)? = nil) {
        self.webView.delegate = nil
        super.dismiss(animated: flag, completion: completion)
    }

}
