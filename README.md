##Predix Mobile iOS Container sample app

This project is the sample reference application for the Predix Mobile Container on the iOS platform.

##Getting Started
It is assumed you already have a Predix Mobile cloud services installation, have installed the Predix Mobile command line tool, and have completed the steps in the following topics to publish your initial Predix Mobile webapp, define your Predix Mobile app, and import the sample data:

* [Get Started with the Mobile Service and Mobile SDK] (https://www.predix.io/docs#rae4EfJ6) 
* [Running the Predix Mobile Sample App] (https://www.predix.io/docs#EGUzWwcC)
* [Creating a Mobile Hello World Web App] (https://www.predix.io/docs#DrBWuHkl) 

It is also assumed you're running on a Mac, with XCode version 8.2 installed.

## Download the Container and Start the App

* [Downloading the iOS Predix Mobile App Container] (https://www.predix.io/docs#F30gVeYB)
* [Starting your iOS Sample App] (https://www.predix.io/docs/?r=205683#cKwF3PlW)


## TroubleShooting:

### Enabling increased logging:

Logging by default is set at "Info" level. There are two more informative levels that can give you more information for debugging problems: Debug, and Trace.

To increase the logging level, in the iOS Simulator, go to the Settings app, scroll down to the PredixUp application, and tap on the Logging level.

You must have run the container application at least once in order for the PredixUp App to appear in Settings.

### I see a sad looking kitten:

The sad kitty is this sample app's serious error page. While whimsical, it lets you know that something is configured incorrectly, or some other error prevented the app from starting. Use the error message on this page, and the console logs in XCode to determine the problem.

### Sad Kitty says: "Authentication failed" but I never saw the authentication page.

Reviewing the logs you will see various network error messages, and messages indicating you cannot connect to the backend.

First, ensure your Mac is online. Then, review the Server setting in the Settings app. It would appear your server host setting is not correct. Either a problem occured in Step 2, or the setting was changed so the system could never load the initial login page.

### Sad Kitty says: "Authentication failed" after I correctly entered my username and password

Reviewing the logs you may see a line like:

    Online authentication completed successfully

Then immediately afterwards:

     Error requesting user data:

And other networking related error messages.

In this case you successfully logged in, but then the system was unable to download your user information. Either due to a suddenly occuring network interuption, or some problem with the backend services.

### Sad Kitty says: "Unable to determine initial startup PredixMobile App"

This will occur if the pmapp_name, and pmapp_version configured in Step 4 is not found. Confirm that these settings match what was in your app.json file defined using the command line (pm tool) "define" command.




