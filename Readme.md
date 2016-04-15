# ParseBrainCloudMigrationSample

This is a sample app that demonstrate the work involved in migrating users from Parse to brainCloud progressively on an app per app basis.

## Application flow

* Attempt to sign-in using brainCloud
 * If that succed then proceed to the game screen. (the user has already been migrated)
 * If that fails then sign-in with Parse
 * Once signed-in authenticate with brainCloud using Parse as authentication server
 * Then run a CloudCode script to migrate the desired user data over to brainCloud.
 * Finnaly create a brainCloud identity using the user email/password associated with the current session.

After these steps the user has been completely migrated to brainCloud.



## Running the sample

First run 

```
pod install
```

Edit `Configuration.swift` and add your Parse and brainCloud information. 

Modify the `SyncUser.js` by adding with your Parse information and then add it to the CloudCode/Script seciton of the brainCloud portal for the desired game.



