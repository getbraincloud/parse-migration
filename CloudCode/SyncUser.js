// Grab the input parameters
externalId = data['externalId'];
sessionToken = data['sessionToken'];

// Create a proxy to the service
httpProxy = bridge.getHttpClientServiceProxy();
playerProxy = bridge.getPlayerStateServiceProxy();

// Create an empty query object
query = {};

// make the parse call
var parseResponse = httpProxy.parseRequest("1/users/" + externalId, query, sessionToken);

// Evaluate the result and return
var retval = {};

// Did the server call work?
if (parseResponse.status == 200)
{
    var parseJson = parseResponse.data.json;
    var parseUserId = parseJson.objectId;
    
    // If it's the user we expected...
    if (parseUserId == externalId) {
        // Retrive basic player data.
        playerProxy.updatePlayerName(parseJson.username);
        playerProxy.updateContactEmail(parseJson.email);
        
        // Now add any additional properties that we are interested in.
        if (parseJson.displayName.length > 0) {
            var attributes = { "displayName" : parseJson.displayName };
            playerProxy.updateAttributes(attributes,true);
        }
        
        retval = playerProxy.getAttributes(); // return additional
        
    } else {
        retval = false; // Boo!
    }
    
} else {
    
    retval = false; // Call didn't even work!
    
}

retval;