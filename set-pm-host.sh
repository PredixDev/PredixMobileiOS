#!/bin/bash

PM_HOST=$(pm api | cut -d "/" -f 3)
echo "Host identified as: ${PM_HOST}"

VERIFY_SETTINGS=$(/usr/libexec/PlistBuddy "PredixMobileiOS/Settings.bundle/Root.plist" -c "print PreferenceSpecifiers:3:Title")
if [ ${VERIFY_SETTINGS} != "Server" ]; then
  echo "Settings plist structure different from expected. Unable to set pm host"
  exit 1
fi 

/usr/libexec/PlistBuddy "PredixMobileiOS/Settings.bundle/Root.plist" -c "set PreferenceSpecifiers:3:DefaultValue ${PM_HOST}"
echo "pm host set to: ${PM_HOST}"
