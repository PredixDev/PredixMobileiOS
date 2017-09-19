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

    // Change to disable dev console
    private var devConsoleEnabled: Bool = true
    // Variables for Dev Console
    var appView: UIWebView!
    var devConsoleWebView: UIWebView!
    var wasFirstDownloaded: Bool! = false
    var devConsoleActive: Bool = false
    var delegate: AppDelegate = UIApplication.shared.delegate as! AppDelegate
    // Specifies the location of relevant files for the application
    var defaultURL : URL! = FileManager.default.urls(for: .applicationSupportDirectory, in: .userDomainMask).first
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
        // Load the main web app as the first webView
        self.appView.loadRequest(URLRequest(url:url))
        
        // Verify that dev console is enabled
        if (self.devConsoleEnabled && delegate.authenticated){
            // Get reference to main web app
            let mainAppURL = retrieveURLForWebApp(webAppName: "main")
            // Get reference to the developer console web app
            let devConsoleURL = retrieveURLForWebApp(webAppName: "dev-console-webapp")
            if (self.wasFirstDownloaded){
                // Reload the main webApp
                self.appView.loadRequest(URLRequest(url: mainAppURL))
                // Show alert on first load of the dev console app
                let alert = self.createVerificationAlert(webAppName: "dev-console-webapp")
                self.present(alert, animated: true, completion: nil)
            }
            // Load the dev console app as the second webView
            self.devConsoleWebView.loadRequest(URLRequest(url: devConsoleURL))
        }
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
        
        // Setup the subviews to take up the whole UIWebView
        self.appView = UIWebView(frame: CGRect(x:0, y:0, width: UIScreen.main.bounds.width, height:UIScreen.main.bounds.height))
        self.devConsoleWebView = UIWebView(frame: CGRect(x:0, y:0, width: UIScreen.main.bounds.width, height:UIScreen.main.bounds.height))
        
        // Add the main web app and developer console web app as subviews to the webView
        self.webView.addSubview(appView)
        self.webView.addSubview(devConsoleWebView)
        
        // Show the first subview (main web app)
        self.webView.bringSubview(toFront: appView)
        
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
    
    // MARK: - Local functions to get the path to another bundled web app
    
    /**
     This function will get the contents of a directory and return the modified URL
     
     - returns:
     A URL which will be either the default URL if an error is found, or the updated URL with the new folder appended
     
     - parameters:
     - path: The file path to a given document/directory
     - desiredFolder: The target folder to be added to the path
     */
    func updateWebAppURL(path: URL, desiredFolder: String) -> URL {
        // Try to open the contents of a directory
        if let contents = try? FileManager.default.contentsOfDirectory(at: path, includingPropertiesForKeys: nil, options: [.skipsHiddenFiles]){
            return getModifiedURL(contents: contents, desiredFolder: desiredFolder)
        }
        
        return defaultURL
    }
    
    /**
     This function will gets the desired folder to be added to the path
     
     - returns:
     A URL which is either the only folder in a directory or the desired folder in a directory
     
     - parameters:
     - contents: The items in the current directory
     - desiredFolder: The target folder to be added to the path
     */
    func getModifiedURL(contents: [URL], desiredFolder: String) -> URL {
        if (desiredFolder == ""){
            return (isDirectory(path: contents[0]) ? contents[0] : defaultURL)!
        }
        if (desiredFolder == "main"){
            return (getMainWebApp(contents: contents))
        }
        else{
            return getSubFolder(contents: contents, desiredFolder: desiredFolder)
        }
    }
    
    /**
     This function determines whether the current path is the main webapp or the dev-console-webapp
     - returns:
     A URL path to the main web app folder
     
     - parameters:
     - contents: The items in the current directory
     */
    func getMainWebApp(contents: [URL]) -> URL {
        // Check all contents of a directory
        for path in contents {
            print(path)
            if (isDirectory(path: path) && path.lastPathComponent != "dev-console-webapp"){
                return path
                
            }
        }
        return defaultURL
    }
    
    /**
     This function will verify the correct subfolder to get from a directory
     
     - returns:
     A URL path to the subfolder
     
     - parameters:
     - contents: The items in the current directory
     - desiredFolder: The target folder to be added to the path
     */
    func getSubFolder(contents: [URL], desiredFolder: String) -> URL {
        // Check all contents of a directory
        for path in contents {
            if (isDirectory(path: path) && isCorrectFolder(path: path, folder: desiredFolder)){
                return path
            }
        }
        
        return defaultURL
    }
    
    /**
     This function checks if the current path is the path that is wanted
     
     - returns:
     A boolean value of true if the folder is correct, false otherwise
     
     - parameters:
     - path: The url to the folder
     - folder: The folder to find
     */
    func isCorrectFolder(path: URL, folder: String) -> Bool {
        return folder == path.lastPathComponent
    }
    
    /**
     This function checks if the current path is a directory or a file
     
     - returns:
     A boolean value of true if the path corresponds to a directory, false otherwise
     
     - parameters:
     - path: The file url to a given item
     */
    func isDirectory(path: URL) -> Bool {
        var isDir: ObjCBool = false
        FileManager.default.fileExists(atPath: path.path, isDirectory: &isDir)
        
        return isDir.boolValue
    }
    
    /**
     This function will build the entire URL to a given web app
     
     - returns:
     A url to a specified web app which is bundled into the current Predix Mobile app
     
     - parameters:
     - webAppName: The desired web app to retrieve
     */
    func retrieveURLForWebApp(webAppName: String) -> URL {
        // Build the URL for the curent Predix Mobile App
        let pathComponents: [String] = ["", "UserData", "", "WebApps", webAppName, ""]
        var newAppURL: URL! = defaultURL
        // Update the url with the path components
        for component in pathComponents {
            newAppURL = updateWebAppURL(path: newAppURL!, desiredFolder: component)
            
            if (webAppName != "main" && component == webAppName && !(newAppURL.absoluteString.range(of: webAppName) != nil)){
                self.wasFirstDownloaded = true
                self.initWebApp(webAppName: webAppName)
            }
        }
        
        // Append index.html, the new page to display
        newAppURL = newAppURL.appendingPathComponent("index.html")
        return newAppURL
    }
    
    private func initWebApp(webAppName: String){
        let url = URL(string: "http://pmapi/window/pane?webapp=\(webAppName)")
        var request = URLRequest(url: url!)
        request.httpMethod = "POST"
        let session = URLSession.shared
        let task = session.dataTask(with: request, completionHandler: { (data, response, error) in
        })
        task.resume()
    }
    
    // MARK - Local functions to handle switching between the main subview and developer console subview
    
    /**
     This function will execute when motion shake has been detected on the device
     */
    override func motionEnded(_ motion: UIEventSubtype, with event: UIEvent?) {
        if motion == .motionShake {
            // Verify uaa has authenticated a user and the web app is not still loading
            if (self.devConsoleEnabled && delegate.authenticated && self.spinner.isHidden){
                var alert: UIAlertController!
                alert = createAlert()
                
                self.present(alert, animated: true, completion: nil)
            }
        }
    }
    
    /**
     This function builds an alert as a response for when a shake is detected
     
     - returns:
     An alert for either opening or closing the developer console
     */
    private func createAlert() -> UIAlertController {
        var message: String!
        if (devConsoleActive) {
            message = "Would you like to close the Developer Console?"
        }
        else {
            message = "Would you like to open the Developer Console?"
        }
        
        let alert = UIAlertController(title: "Shake Detected", message: message, preferredStyle: UIAlertControllerStyle.alert)
        alert.addAction(UIAlertAction(title: "Cancel", style: UIAlertActionStyle.cancel, handler: nil))
        alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: { (action) in
            self.switchWebViews()
        }))
        
        return alert
    }
    
    private func createVerificationAlert(webAppName: String) -> UIAlertController {
        let alert = UIAlertController(title: "Alert", message: "Developer console loaded, shake to open!", preferredStyle: UIAlertControllerStyle.alert)
        alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: nil))
        return alert
    }
    
    /**
     This function will handle switching between subviews for the webView
     */
    private func switchWebViews() {
        if (devConsoleActive) {
            self.webView.bringSubview(toFront: self.appView)
            devConsoleActive = false
        }
        else {
            self.webView.bringSubview(toFront: self.devConsoleWebView)
            devConsoleActive = true
        }
    }
}
