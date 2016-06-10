//
//  AppDelegate.swift
//  PredixMobileiOS
//
//  Created by Johns, Andy (GE Corporate) on 8/10/15.
//  Copyright © 2015 GE. All rights reserved.
//

import UIKit
import PredixMobileSDK

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    var authenticationViewController : UIViewController?


    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        // Override point for customization after application launch.

        #if DEBUG
            if NSProcessInfo.processInfo().environment["XCInjectBundle"] != nil {
                // Exit if we're running unit tests...
                PGSDKLogger.debug("Detected running functional unit tests, not starting normal services or running normal UI processes")
                return true
            }
        #endif
        
        //Disable requirement to have a passcode set on the device. This is not recommended for production systems. A device passcode is a critical security feature of iOS devices.
        //PredixMobilityConfiguration.requireDevicePasscodeSet = false
        
        // Pre-load configuration. This will load any Settings bundles into NSUserDefaults and set default logging levels
        PredixMobilityConfiguration.loadConfiguration()
        
        // Add optional and custom services to the system if required
        //PredixMobilityConfiguration.additionalBootServicesToRegister = [OpenURLService.self]

        // Example of creating a view for full text search, assuming "body" is a property in some documents that contains a large amount of text.
        /*
        PredixMobilityConfiguration.appendDataViewDefinition("views/searchtext", version: "1") { (properties: [String : AnyObject], emit: (AnyObject, AnyObject?) -> ()) -> () in
            
            if let body = properties["body"] as? String
            {
                emit(FullTextSearch.createKey(body), nil)
            }
        }
        */
        
        // create the PredixMobilityManager object. This object coordinates the application state, interacts with the various services, and holds closures called during authentication.
        
        let vc : ViewController = self.window?.rootViewController as! ViewController
        unowned let unownedSelf = self
        let pmm = PredixMobilityManager(packageWindow: vc, presentAuthentication: { (packageWindow) -> (PredixAppWindowProtocol) in
            
            // for this example we're using a new instance of the primary view controller to host the authentication pages.
            let authVC = vc.storyboard!.instantiateViewControllerWithIdentifier("ViewController") as! ViewController
            authVC.isAuthenticationView = true
            unownedSelf.authenticationViewController = authVC
            unownedSelf.window?.rootViewController!.presentViewController(authVC, animated: true, completion: nil)
            return authVC as PredixAppWindowProtocol
            
            }, dismissAuthentication: { (authenticationWindow) -> () in
                
                if let authVC = unownedSelf.authenticationViewController
                {
                    unownedSelf.authenticationViewController = nil
                    authVC.dismissViewControllerAnimated(true, completion: nil)
                }

        })

        // logging our current running environment
        PGSDKLogger.debug("Started app with launchOptions: \(launchOptions)")
        
        let versionInfo = PredixMobilityConfiguration.getVersionInfo()
        
        let processInfo = NSProcessInfo.processInfo()
        let device = UIDevice.currentDevice()

        PGSDKLogger.info("Running Environment:\n     locale: \(versionInfo[VersionInfoKeys.Locale] ?? "")\n     device model:\(versionInfo[VersionInfoKeys.DeviceModel] ?? "")\n     device system name:\(versionInfo[VersionInfoKeys.DeviceOS] ?? "")\n     device system version:\(versionInfo[VersionInfoKeys.DeviceOSVersion] ?? "")\n     device vendor identifier:\(device.identifierForVendor!.UUIDString)\n     iOS Version/Build: \(processInfo.operatingSystemVersionString)\n     app bundle id: \(versionInfo[VersionInfoKeys.ApplicationBundleId] ?? "")\n     app version: \(versionInfo[VersionInfoKeys.ApplicationVersion] ?? "")\n     app build version: \(versionInfo[VersionInfoKeys.ApplicationBuildVersion] ?? "")\n     \(PredixMobilityConfiguration.versionInfo)")
        
        if TARGET_IPHONE_SIMULATOR == 1
        {
            //This will help you find where the build lives when running in the simulator
            PGSDKLogger.info("Simulator build running from:\n \(NSBundle.mainBundle().bundlePath)")
            let applicationSupportDirectory = NSSearchPathForDirectoriesInDomains(.ApplicationSupportDirectory,.UserDomainMask,true).first!
            PGSDKLogger.info("Simulator Application Support dir is here:\n \(applicationSupportDirectory))")
        }
        
        if let launchOptions = launchOptions, notification = launchOptions[UIApplicationLaunchOptionsLocalNotificationKey] as? UILocalNotification
        {
            PGSDKLogger.debug("Startup with local notification")
            PGSDKLogger.trace("Startup local notification info: \(notification.userInfo)")
            PredixMobilityManager.sharedInstance.application(application, didReceiveLocalNotification: notification)
        }
        
        if let launchOptions = launchOptions, userInfo = launchOptions[UIApplicationLaunchOptionsRemoteNotificationKey] as? [NSObject : AnyObject]
        {
            PGSDKLogger.debug("Startup with remote notification")
            PGSDKLogger.trace("Startup remote notification info: \(userInfo)")
            PredixMobilityManager.sharedInstance.application(application, didReceiveRemoteNotification: userInfo)
        }

        // start the application. This will spin up the PredixMobile environment and call the Boot service to start the application.
        pmm.startApp()
        
        self.setupRemoteNotifications()
        
        return true
    }

    // Registers for Remote (Push) Notifications.
    func setupRemoteNotifications()
    {
        self.setupUserNotificationSettings()
        UIApplication.sharedApplication().registerForRemoteNotifications()
    }

    // sets up the User Notification Settings, if those settings haven't already been setup.
    func setupUserNotificationSettings()
    {
        // get the current settings
        let settings = UIApplication.sharedApplication().currentUserNotificationSettings()
        if settings == nil || settings!.categories == nil || settings!.categories!.isEmpty || settings!.types.isEmpty
        {
            // ensure the current settings have what we're expecting. If not, add what we want
            let action = UIMutableUserNotificationAction()
            action.activationMode = .Foreground
            
            let actionCategory = UIMutableUserNotificationCategory()
            actionCategory.setActions([action], forContext: UIUserNotificationActionContext.Default)
            
            let categorySet = Set<UIMutableUserNotificationCategory>(arrayLiteral: actionCategory)
            
            let settings = UIUserNotificationSettings(forTypes: [.Alert, .Badge, .Sound] , categories: categorySet)
            UIApplication.sharedApplication().registerUserNotificationSettings(settings)
        }
    }

    
    func applicationDidBecomeActive(application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
        
        #if DEBUG
            if NSProcessInfo.processInfo().environment["XCInjectBundle"] != nil {
                // Exit if we're running unit tests...
                PGSDKLogger.debug("Detected running functional unit tests, not starting normal services or running normal UI processes")
                return
            }
        #endif
    }
    
    //MARK: Notification handlers to pass to PredixMobilityManager
    
    func application(application: UIApplication, didReceiveLocalNotification notification: UILocalNotification) {
        
        PredixMobilityManager.sharedInstance.application(application, didReceiveLocalNotification: notification)
    }
    
    func application(application: UIApplication, didReceiveRemoteNotification userInfo: [NSObject : AnyObject]) {
        PredixMobilityManager.sharedInstance.application(application, didReceiveRemoteNotification: userInfo)
    }
    
    func application(application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: NSData) {
        PredixMobilityManager.sharedInstance.application(application, didRegisterForRemoteNotificationsWithDeviceToken: deviceToken)
    }

    func application(application: UIApplication, didFailToRegisterForRemoteNotificationsWithError error: NSError) {
        PredixMobilityManager.sharedInstance.application(application, didFailToRegisterForRemoteNotificationsWithError: error)
    }


}


