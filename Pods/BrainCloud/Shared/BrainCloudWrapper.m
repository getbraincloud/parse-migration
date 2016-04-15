#import "BrainCloudWrapper.hh"

#import "BrainCloudSaveDataHelper.h"

@interface BrainCloudWrapper ()

@property (strong, nonatomic) BrainCloudSaveDataHelper *helper;

@property (copy, nonatomic) NSString *lastGameId;
@property (copy, nonatomic) NSString *lastGameVersion;
@property (copy, nonatomic) NSString *lastSecretKey;
@property (strong, nonatomic) NSString *lastServerUrl;

@property (copy) BCCompletionBlock authSuccessCompletionBlock;
@property (copy) BCErrorCompletionBlock authErrorCompletionBlock;

@end


@implementation BrainCloudWrapper

NSString * const kAuthenticationAnonymous          = @"anonymous";
NSString * const kPersistenceKeyAnonymousId        = @"anonymousId";
NSString * const kPersistenceKeyAuthenticationType = @"authenticationType";
NSString * const kPersistenceKeyProfileId          = @"profileId";


#pragma mark - Getters & Setters

+ (BrainCloudWrapper *) getInstance
{
    static BrainCloudWrapper *sharedWrapper = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedWrapper = [[self alloc] init];
        
        // the generic authentication completion blocks
        
        sharedWrapper.authSuccessCompletionBlock = ^(NSString *serviceName, NSString *serviceOperation, NSString *jsonData, BCCallbackObject cbObject)
        {
            NSData *data = [jsonData dataUsingEncoding:NSUTF8StringEncoding];
            NSDictionary *jsonObj = [NSJSONSerialization JSONObjectWithData:data
                                                                    options:NSJSONReadingMutableContainers
                                                                      error:nil];
            
            sharedWrapper.storedProfileId = [(NSDictionary *)[jsonObj objectForKey:@"data"] objectForKey:@"profileId"];
            NSArray *aco = (NSArray*) cbObject;
            if (aco[0] != nil)
            {
                void (^completionBlock)(NSString *serviceName, NSString *serviceOperation, NSString *jsonData, BCCallbackObject cbObject) = aco[0];
                completionBlock(serviceName, serviceOperation, jsonData, aco[2]);
            }
        };
        
        sharedWrapper.authErrorCompletionBlock = ^(NSString *serviceName, NSString *serviceOperation, NSInteger statusCode, NSInteger returnCode, NSString *jsonError, BCCallbackObject cbObject)
        {
            NSArray *aco = (NSArray*) cbObject;
            void (^errorCompletionBlock)(NSString *serviceName, NSString *serviceOperation, NSInteger statusCode, NSInteger returnCode, NSString *jsonError, BCCallbackObject cbObject) = aco[1];
            errorCompletionBlock(serviceName, serviceOperation, statusCode, returnCode, jsonError, aco[2]);
        };
    });
    return sharedWrapper;
}

+ (BrainCloudClient *) getBC
{
    return [BrainCloudClient getInstance];
}

- (BrainCloudClient *)client
{
    return [BrainCloudClient getInstance];
}


- (void)setStoredAnonymousId:(NSString *)storedAnonymousId
{
    [self.helper saveString:storedAnonymousId forKey:kPersistenceKeyAnonymousId];
}

- (NSString *)storedAnonymousId
{
    return [self.helper stringForKey:kPersistenceKeyAnonymousId];
}

- (void)setStoredAuthenticationType:(NSString *)storedAuthenticationType
{
    [self.helper saveString:storedAuthenticationType forKey:kPersistenceKeyAuthenticationType];
}

- (NSString *)storedAuthenticationType
{
    return [self.helper stringForKey:kPersistenceKeyAuthenticationType];
}

- (void)setStoredProfileId:(NSString *)storedProfileId
{
    [self.helper saveString:storedProfileId forKey:kPersistenceKeyProfileId];
}

- (NSString *)storedProfileId
{
    return [self.helper stringForKey:kPersistenceKeyProfileId];
}

- (void)setAlwaysAllowProfileSwitch:(BOOL)alwaysAllowProfileSwitch
{
    self.alwaysAllowProfileSwitch = alwaysAllowProfileSwitch;
}

- (BOOL)alwaysAllowProfileSwitch
{
    return self.alwaysAllowProfileSwitch;
}

#pragma mark - C++ Initialization



- (void)initialize:(NSString *)serverUrl
         secretKey:(NSString *)secretKey
            gameId:(NSString *)gameId
       gameVersion:(NSString *)gameVersion
       companyName:(NSString *)companyName
          gameName:(NSString *)gameName
{
    self.lastGameId      = gameId;
    self.lastGameVersion = gameVersion;
    self.lastSecretKey   = secretKey;
    self.lastServerUrl   = serverUrl;
    
    [[BrainCloudClient getInstance] initialize:serverUrl
                                     secretKey:secretKey
                                        gameId:gameId
                                   gameVersion:gameVersion];
        
    self.helper = [[BrainCloudSaveDataHelper alloc] initWithCompanyName:companyName gameName:gameName];
}


- (void)_initializeIdentity:(BOOL) isAnonymousAuth
{
    NSString *profileId = self.storedProfileId;
    NSString *anonymousId = self.storedAnonymousId;
    
    if (nil == self.storedAnonymousId || (nil != self.storedAnonymousId && nil == self.storedProfileId))
    {
        self.storedAnonymousId = [[[BrainCloudClient getInstance] authenticationService] generateGUID];
    }
    
    NSString *profileIdToAuthenticateWith = profileId;
    if (!isAnonymousAuth && self.alwaysAllowProfileSwitch)
    {
        profileIdToAuthenticateWith = @"";
    }
    self.storedAuthenticationType = isAnonymousAuth ? kAuthenticationAnonymous : @"";
    
    // send our IDs to brainCloud
    [[BrainCloudClient getInstance] initializeIdentity:profileIdToAuthenticateWith anonymousId:anonymousId];
}

- (void)authenticateAnonymous:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                     cbObject:(BCCallbackObject)cbObject
{
    [self _initializeIdentity:TRUE];
    
    NSArray *aco = @[completionBlock, errorCompletionBlock, cbObject];
    [[[BrainCloudClient getInstance] authenticationService] authenticateAnonymous:TRUE
                                                                  completionBlock:self.authSuccessCompletionBlock
                                                             errorCompletionBlock:self.authErrorCompletionBlock
                                                                         cbObject:aco];
}

- (void)authenticateEmailPassword:(NSString *)email
                         password:(NSString *)password
                      forceCreate:(BOOL)forceCreate
                  completionBlock:(BCCompletionBlock)completionBlock
             errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                         cbObject:(BCCallbackObject)cbObject
{
    [self _initializeIdentity:FALSE];
    
    NSArray *aco = @[completionBlock, errorCompletionBlock, cbObject];
    
    [[[BrainCloudClient getInstance] authenticationService] authenticateEmailPassword:email
                                                                             password:password
                                                                          forceCreate:YES
                                                                      completionBlock:self.authSuccessCompletionBlock
                                                                 errorCompletionBlock:self.authErrorCompletionBlock
                                                                             cbObject:aco];
}

- (void)authenticateExternal:(NSString *)userId
         authenticationToken:(NSString *)authToken
  externalAuthenticationName:(NSString *)externalAuthName
                 forceCreate:(BOOL)forceCreate
             completionBlock:(BCCompletionBlock)completionBlock
        errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                    cbObject:(BCCallbackObject)cbObject
{
    [self _initializeIdentity:FALSE];
    
    NSArray *aco = @[completionBlock, errorCompletionBlock, cbObject];
    
    [[[BrainCloudClient getInstance] authenticationService] authenticateExternal:userId
                                                             authenticationToken:authToken
                                                      externalAuthenticationName:externalAuthName
                                                                     forceCreate:YES
                                                                 completionBlock:self.authSuccessCompletionBlock
                                                            errorCompletionBlock:self.authErrorCompletionBlock
                                                                        cbObject:aco];

}

- (void)authenticateFacebook:(NSString *)fbUserId
         authenticationToken:(NSString *)fbAuthToken
                 forceCreate:(BOOL)forceCreate
             completionBlock:(BCCompletionBlock)completionBlock
        errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                    cbObject:(BCCallbackObject)cbObject
{
    [self _initializeIdentity:FALSE];
    
    NSArray *aco = @[completionBlock, errorCompletionBlock, cbObject];
    
    [[[BrainCloudClient getInstance] authenticationService] authenticateFacebook:fbUserId
                                                             authenticationToken:fbAuthToken
                                                                     forceCreate:YES
                                                                 completionBlock:self.authSuccessCompletionBlock
                                                            errorCompletionBlock:self.authErrorCompletionBlock
                                                                        cbObject:aco];
    
}

- (void)authenticateGameCenter:(NSString *)gameCenterId
                   forceCreate:(BOOL)forceCreate
               completionBlock:(BCCompletionBlock)completionBlock
          errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                      cbObject:(BCCallbackObject)cbObject
{
    [self _initializeIdentity:FALSE];
    
    NSArray *aco = @[completionBlock, errorCompletionBlock, cbObject];
    
    [[[BrainCloudClient getInstance] authenticationService] authenticateGameCenter:gameCenterId
                                                                     forceCreate:YES
                                                                 completionBlock:self.authSuccessCompletionBlock
                                                            errorCompletionBlock:self.authErrorCompletionBlock
                                                                        cbObject:aco];
    
}

- (void)authenticateGoogle:(NSString *)userID
                     token:(NSString *)token
               forceCreate:(BOOL)forceCreate
           completionBlock:(BCCompletionBlock)completionBlock
      errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                  cbObject:(BCCallbackObject)cbObject
{
    [self _initializeIdentity:FALSE];
    
    NSArray *aco = @[completionBlock, errorCompletionBlock, cbObject];
    
    [[[BrainCloudClient getInstance] authenticationService] authenticateGoogle:userID
                                                                         token:token
                                                                     forceCreate:YES
                                                                 completionBlock:self.authSuccessCompletionBlock
                                                            errorCompletionBlock:self.authErrorCompletionBlock
                                                                        cbObject:aco];
}


- (void)authenticateSteam:(NSString *)userId
            sessionTicket:(NSString *)sessionticket
              forceCreate:(BOOL)forceCreate
          completionBlock:(BCCompletionBlock)completionBlock
     errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                 cbObject:(BCCallbackObject)cbObject
{
    [self _initializeIdentity:FALSE];
    
    NSArray *aco = @[completionBlock, errorCompletionBlock, cbObject];
    
    [[[BrainCloudClient getInstance] authenticationService] authenticateSteam:userId
                                                                sessionTicket:sessionticket
                                                                  forceCreate:YES
                                                              completionBlock:self.authSuccessCompletionBlock
                                                         errorCompletionBlock:self.authErrorCompletionBlock
                                                                     cbObject:aco];
}

- (void)authenticateTwitter:(NSString *)userId
                      token:(NSString *)token
                     secret:(NSString *)secret
                forceCreate:(BOOL)forceCreate
            completionBlock:(BCCompletionBlock)completionBlock
       errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                   cbObject:(BCCallbackObject)cbObject
{
    [self _initializeIdentity:FALSE];
    
    NSArray *aco = @[completionBlock, errorCompletionBlock, cbObject];
    
    [[[BrainCloudClient getInstance] authenticationService] authenticateTwitter:userId
                                                                          token:token
                                                                         secret:secret
                                                                    forceCreate:YES
                                                                completionBlock:self.authSuccessCompletionBlock
                                                           errorCompletionBlock:self.authErrorCompletionBlock
                                                                       cbObject:aco];
}

- (void)authenticateUniversal:(NSString *)userId
                     password:(NSString *)password
                  forceCreate:(BOOL)forceCreate
              completionBlock:(BCCompletionBlock)completionBlock
         errorCompletionBlock:(BCErrorCompletionBlock)errorCompletionBlock
                     cbObject:(BCCallbackObject)cbObject
{
    [self _initializeIdentity:FALSE];
    
    NSArray *aco = @[completionBlock, errorCompletionBlock, cbObject];
    
    [[[BrainCloudClient getInstance] authenticationService] authenticateUniversal:userId
                                                                         password:password
                                                                      forceCreate:YES
                                                                  completionBlock:self.authSuccessCompletionBlock
                                                             errorCompletionBlock:self.authErrorCompletionBlock
                                                                         cbObject:aco];
}

/*
- (void)reauthenticateWithSuccess:(BrainCloudWrapperSuccessfulCompletion)success failure:(BrainCloudWrapperFailedCompletion)failure {
    [self initializeWithURL:self.lastURL
                companyName:nil
                  secretKey:self.lastSecretKey
                     gameID:self.lastGameID
                   gameName:nil
                gameVersion:self.lastGameVersion];
    
    if ([self.storedAuthenticationType isEqualToString:kAuthenticationAnonymous])
        [self authenticateAnonymousWithSuccess:success failure:failure];
    
}
 */

#pragma mark - Updates

- (void)update
{
    [[BrainCloudClient getInstance] runCallBacks];
}

@end
