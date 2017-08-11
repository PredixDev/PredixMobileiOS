## Predix Mobile iOS Container sample app

This project is the sample reference application for the Predix Mobile Container on the iOS platform.
 
## Getting Started
Install the Predix Mobile cloud services and the Predix Mobile command line tool. You must also complete the steps listed below to publish your initial Predix Mobile webapp, define your Predix Mobile app, and import the sample data:

Step 1. [Get Started with the Mobile Service and Mobile SDK](https://www.predix.io/docs#rae4EfJ6)

Step 2. [Running the Predix Mobile Sample App](https://www.predix.io/docs#EGUzWwcC)

Step 3. [Creating a Mobile Hello World Web App](https://www.predix.io/docs#DrBWuHkl) 

Note: This sample reference app runs on a Mac with an XCode version 8.3.3 installed on it.

## Download the Container and Start the App

Step 4. [Downloading the iOS Predix Mobile App Container](https://www.predix.io/docs#F30gVeYB)

Step 5. [Starting your iOS Sample App](https://www.predix.io/docs/?r=205683#cKwF3PlW)


## Troubleshooting

### Enabling increased logging

The error logging is set to "Info" level by default. There are two more informative levels that can give you more information for debugging problems: Debug and Trace.

To increase the logging level in the iOS Simulator, go to the Settings app, scroll down to the PredixUp application and tap on the Logging level.

You must run the container application at least once in order for the PredixUp App to appear in the Settings app.

## Error Messages FAQ

### Why do I see a sad looking kitten ?

The sad looking kitten (Sad Kitty) represents this sample app's serious error page. While whimsical, it lets you know that something is configured incorrectly, or some other error prevented the app from starting. Use the error messages displayed at the bottom on the Sad Kitty page along with the console logs in XCode to determine the problem.

### Why is the Sad Kitty saying, "Authentication failed",  I never saw the authentication page?

When you review the logs you may see various network error messages and messages indicating that you cannot connect to the backend.

First, ensure that your Mac is online. Then, review the Server setting in the Settings app. You may want to check the following:

* Your server host setting is correct. 
* A problem that may have occured in Step 2
* Any settings that were changed, changes in setting can prevent the system fron loading the initial login page.

### I entered the correct username and password, why is the Sad Kitty saying, "Authentication failed" ? 

While reviewing the logs you may see the following message:

    Online authentication completed successfully

Then immediately afterwards:

     Error requesting user data:

Followed by other networking related error messages.

The above mentioned messages indicate that you successfully logged in, but the system was unable to download your user information. This can happen because of a sudden network interuption or an issue with the backend services.

### Why is the Sad Kitty saying, "Unable to determine initial startup PredixMobile App" ?

This error message is displayed when the `pmapp_name`, and `pmapp_version` configured in Step 4 is not found. Make sure that these settings match to the settings that you defined in your `app.json` file using the `pm define`command (pm command line tool).




