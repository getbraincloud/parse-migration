#include "ServiceOperation.h"

namespace BrainCloud
{
    const ServiceOperation ServiceOperation::None = ServiceOperation("NONE");

	const ServiceOperation ServiceOperation::Authenticate = ServiceOperation("AUTHENTICATE");
	const ServiceOperation ServiceOperation::Attach = ServiceOperation("ATTACH");
	const ServiceOperation ServiceOperation::Merge = ServiceOperation("MERGE");
	const ServiceOperation ServiceOperation::Detach = ServiceOperation("DETACH");
	const ServiceOperation ServiceOperation::ResetEmailPassword = ServiceOperation("RESET_EMAIL_PASSWORD");
    const ServiceOperation ServiceOperation::SwitchToChildProfile = ServiceOperation("SWITCH_TO_CHILD_PROFILE");
    const ServiceOperation ServiceOperation::SwitchToParentProfile = ServiceOperation("SWITCH_TO_PARENT_PROFILE");
    const ServiceOperation ServiceOperation::GetChildProfiles = ServiceOperation("GET_CHILD_PROFILES");

	const ServiceOperation ServiceOperation::Create = ServiceOperation("CREATE");
	const ServiceOperation ServiceOperation::CreateWithIndexedId = ServiceOperation("CREATE_WITH_INDEXED_ID");
	const ServiceOperation ServiceOperation::Reset = ServiceOperation("RESET");
	const ServiceOperation ServiceOperation::Read = ServiceOperation("READ");
    const ServiceOperation ServiceOperation::ReadSingleton = ServiceOperation("READ_SINGLETON");
	const ServiceOperation ServiceOperation::ReadByType = ServiceOperation("READ_BY_TYPE");
	const ServiceOperation ServiceOperation::Verify = ServiceOperation("VERIFY");
	const ServiceOperation ServiceOperation::ReadShared = ServiceOperation("READ_SHARED");
    const ServiceOperation ServiceOperation::ReadSharedEntity = ServiceOperation("READ_SHARED_ENTITY");
    
    // push notification
	const ServiceOperation ServiceOperation::Deregister = ServiceOperation("DEREGISTER");
	const ServiceOperation ServiceOperation::DeregisterAll = ServiceOperation("DEREGISTER_ALL");
	const ServiceOperation ServiceOperation::Register = ServiceOperation("REGISTER");
	const ServiceOperation ServiceOperation::SendSimple = ServiceOperation("SEND_SIMPLE");
	const ServiceOperation ServiceOperation::SendRich = ServiceOperation("SEND_RICH");
	
	const ServiceOperation ServiceOperation::Trigger = ServiceOperation("TRIGGER");
	const ServiceOperation ServiceOperation::TriggerMultiple = ServiceOperation("TRIGGER_MULTIPLE");
	const ServiceOperation ServiceOperation::TriggerGrantExperience = ServiceOperation("TRIGGER_GRANT_EXPERIENCE");
	
	const ServiceOperation ServiceOperation::FullReset = ServiceOperation("FULL_PLAYER_RESET");
	const ServiceOperation ServiceOperation::DataReset = ServiceOperation("GAME_DATA_RESET");

	const ServiceOperation ServiceOperation::Update = ServiceOperation("UPDATE");
	const ServiceOperation ServiceOperation::UpdatePartial = ServiceOperation("UPDATE_PARTIAL");
	const ServiceOperation ServiceOperation::UpdateShared = ServiceOperation("UPDATE_SHARED");
	const ServiceOperation ServiceOperation::UpdateSingleton = ServiceOperation("UPDATE_SINGLETON");
	const ServiceOperation ServiceOperation::UpdateAcl = ServiceOperation("UPDATE_ACL");
	const ServiceOperation ServiceOperation::UpdateTimeToLive = ServiceOperation("UPDATE_TIME_TO_LIVE");
	const ServiceOperation ServiceOperation::Delete = ServiceOperation("DELETE");
	const ServiceOperation ServiceOperation::DeleteSingleton = ServiceOperation("DELETE_SINGLETON");
	const ServiceOperation ServiceOperation::UpdateSummary = ServiceOperation("UPDATE_SUMMARY");
	const ServiceOperation ServiceOperation::UpdateSetMinimum = ServiceOperation("UPDATE_SET_MINIMUM");
	const ServiceOperation ServiceOperation::UpdateIncrementToMaximum = ServiceOperation("UPDATE_INCREMENT_TO_MAXIMUM");

	const ServiceOperation ServiceOperation::GetFriendProfileInfoForExternalId = ServiceOperation("GET_FRIEND_PROFILE_INFO_FOR_EXTERNAL_ID");
    const ServiceOperation ServiceOperation::GetExternalIdForProfileId = ServiceOperation("GET_EXTERNAL_ID_FOR_PROFILE_ID");
	const ServiceOperation ServiceOperation::ReadFriendEntity = ServiceOperation("READ_FRIEND_ENTITY");
	const ServiceOperation ServiceOperation::ReadFriendsEntities = ServiceOperation("READ_FRIENDS_ENTITIES");
	const ServiceOperation ServiceOperation::ReadFriendsWithApplication = ServiceOperation("READ_FRIENDS_WITH_APPLICATION");
	const ServiceOperation ServiceOperation::ReadFriends = ServiceOperation("READ_FRIENDS");
	const ServiceOperation ServiceOperation::ReadFriendsPlayerState = ServiceOperation("READ_FRIEND_PLAYER_STATE");
    const ServiceOperation ServiceOperation::FindPlayerByName = ServiceOperation("FIND_PLAYER_BY_NAME");
    const ServiceOperation ServiceOperation::ListFriends = ServiceOperation("LIST_FRIENDS");
    const ServiceOperation ServiceOperation::AddFriends = ServiceOperation("ADD_FRIENDS");
    const ServiceOperation ServiceOperation::RemoveFriends = ServiceOperation("REMOVE_FRIENDS");
    const ServiceOperation ServiceOperation::FindPlayerByUniversalId = ServiceOperation("FIND_PLAYER_BY_UNIVERSAL_ID");
	const ServiceOperation ServiceOperation::GetSocialLeaderboard = ServiceOperation("GET_SOCIAL_LEADERBOARD");
    const ServiceOperation ServiceOperation::GetMultiSocialLeaderboard = ServiceOperation("GET_MULTI_SOCIAL_LEADERBOARD");
	const ServiceOperation ServiceOperation::GetGlobalLeaderboard = ServiceOperation("GET_GLOBAL_LEADERBOARD");
	const ServiceOperation ServiceOperation::GetGlobalLeaderboardPage = ServiceOperation("GET_GLOBAL_LEADERBOARD_PAGE");
	const ServiceOperation ServiceOperation::GetGlobalLeaderboardView = ServiceOperation("GET_GLOBAL_LEADERBOARD_VIEW");
    const ServiceOperation ServiceOperation::GetGlobalLeaderboardVersions = ServiceOperation("GET_GLOBAL_LEADERBOARD_VERSIONS");
	const ServiceOperation ServiceOperation::GetCompletedTournament = ServiceOperation("GET_COMPLETED_TOURNAMENT");
	const ServiceOperation ServiceOperation::RewardTournament = ServiceOperation("REWARD_TOURNAMENT");
	const ServiceOperation ServiceOperation::PostScore = ServiceOperation("POST_SCORE");
	const ServiceOperation ServiceOperation::PostScoreDynamic = ServiceOperation("POST_SCORE_DYNAMIC");
	
	const ServiceOperation ServiceOperation::InitThirdParty = ServiceOperation("initThirdParty");
	const ServiceOperation ServiceOperation::PostThirdPartyLeaderboardScore = ServiceOperation("postThirdPartyLeaderboardScore");
	const ServiceOperation ServiceOperation::IncrementThirdPartyLeaderboardScore = ServiceOperation("incrementThirdPartyLeaderboardScore");
	const ServiceOperation ServiceOperation::LaunchAchievementUI = ServiceOperation("launchAchievementUI");
	const ServiceOperation ServiceOperation::PostThirdPartyLeaderboardAchievement = ServiceOperation("postThirdPartyLeaderboardAchievement");
	const ServiceOperation ServiceOperation::IsThirdPartyAchievementComplete = ServiceOperation("isThirdPartyAchievementComplete");
	const ServiceOperation ServiceOperation::ResetThirdPartyAchievements = ServiceOperation("resetThirdPartyAchievements");
	const ServiceOperation ServiceOperation::QueryThirdPartyAchievements = ServiceOperation("queryThirdPartyAchievements");
	
	const ServiceOperation ServiceOperation::GetInventory = ServiceOperation("GET_INVENTORY");
	const ServiceOperation ServiceOperation::CashInReceipt = ServiceOperation("OP_CASH_IN_RECEIPT");
	const ServiceOperation ServiceOperation::AwardVC = ServiceOperation("AWARD_VC");
	const ServiceOperation ServiceOperation::ConsumeVC = ServiceOperation("CONSUME_VC");
	const ServiceOperation ServiceOperation::GetPlayerVC = ServiceOperation("GET_PLAYER_VC");
	const ServiceOperation ServiceOperation::ResetPlayerVC = ServiceOperation("RESET_PLAYER_VC");
    
    const ServiceOperation ServiceOperation::AwardParentVC = ServiceOperation("AWARD_PARENT_VC");
    const ServiceOperation ServiceOperation::ConsumeParentVC = ServiceOperation("CONSUME_PARENT_VC");
    const ServiceOperation ServiceOperation::GetParentVC = ServiceOperation("GET_PARENT_VC");
    const ServiceOperation ServiceOperation::ResetParentVC = ServiceOperation("RESET_PARENT_VC");

	const ServiceOperation ServiceOperation::Send = ServiceOperation("SEND");
	const ServiceOperation ServiceOperation::UpdateEventData = ServiceOperation("UPDATE_EVENT_DATA");
	const ServiceOperation ServiceOperation::DeleteSent = ServiceOperation("DELETE_SENT");
	const ServiceOperation ServiceOperation::DeleteIncoming = ServiceOperation("DELETE_INCOMING");
    const ServiceOperation ServiceOperation::GetEvents = ServiceOperation("GET_EVENTS");

	const ServiceOperation ServiceOperation::UpdateIncrement = ServiceOperation("UPDATE_INCREMENT");
	const ServiceOperation ServiceOperation::ReadNextXplevel = ServiceOperation("READ_NEXT_XPLEVEL");
	const ServiceOperation ServiceOperation::ReadXpLevels = ServiceOperation("READ_XP_LEVELS");
	const ServiceOperation ServiceOperation::SetXpPoints = ServiceOperation("SET_XPPOINTS");
	const ServiceOperation ServiceOperation::ReadSubset = ServiceOperation("READ_SUBSET");
	const ServiceOperation ServiceOperation::ReadForCategory = ServiceOperation("READ_FOR_CATEGORY");

	const ServiceOperation ServiceOperation::Run = ServiceOperation("RUN");
	const ServiceOperation ServiceOperation::Tweet = ServiceOperation("TWEET");

	const ServiceOperation ServiceOperation::AwardAchievements = ServiceOperation("AWARD_ACHIEVEMENTS");
	const ServiceOperation ServiceOperation::ReadAchievements = ServiceOperation("READ_ACHIEVEMENTS");
	const ServiceOperation ServiceOperation::ReadAchievedAchievements = ServiceOperation("READ_ACHIEVED_ACHIEVEMENTS");

	const ServiceOperation ServiceOperation::SetPlayerRating = ServiceOperation("SET_PLAYER_RATING");
	const ServiceOperation ServiceOperation::ResetPlayerRating = ServiceOperation("RESET_PLAYER_RATING");
	const ServiceOperation ServiceOperation::IncrementPlayerRating = ServiceOperation("INCREMENT_PLAYER_RATING");
	const ServiceOperation ServiceOperation::DecrementPlayerRating = ServiceOperation("DECREMENT_PLAYER_RATING");
	const ServiceOperation ServiceOperation::ShieldOn = ServiceOperation("SHIELD_ON");
	const ServiceOperation ServiceOperation::ShieldOnFor = ServiceOperation("SHIELD_ON_FOR");
	const ServiceOperation ServiceOperation::ShieldOff = ServiceOperation("SHIELD_OFF");
    const ServiceOperation ServiceOperation::GetShieldExpiry = ServiceOperation("GET_SHIELD_EXPIRY");
	const ServiceOperation ServiceOperation::FindPlayers = ServiceOperation("FIND_PLAYERS");
	const ServiceOperation ServiceOperation::FindPlayersUsingFilter = ServiceOperation("FIND_PLAYERS_USING_FILTER");

	const ServiceOperation ServiceOperation::SubmitTurn = ServiceOperation("SUBMIT_TURN");
	const ServiceOperation ServiceOperation::UpdateMatchSummary = ServiceOperation("UPDATE_SUMMARY");
	const ServiceOperation ServiceOperation::Abandon = ServiceOperation("ABANDON");
	const ServiceOperation ServiceOperation::Complete = ServiceOperation("COMPLETE");
	const ServiceOperation ServiceOperation::ReadMatch = ServiceOperation("READ_MATCH");
	const ServiceOperation ServiceOperation::ReadMatchHistory = ServiceOperation("READ_MATCH_HISTORY");
	const ServiceOperation ServiceOperation::FindMatches = ServiceOperation("FIND_MATCHES");
	const ServiceOperation ServiceOperation::FindMatchesCompleted = ServiceOperation("FIND_MATCHES_COMPLETED");
	const ServiceOperation ServiceOperation::DeleteMatch = ServiceOperation("DELETE_MATCH");
	
	const ServiceOperation ServiceOperation::LastUploadStatus = ServiceOperation("LAST_UPLOAD_STATUS");
	
	const ServiceOperation ServiceOperation::ReadQuests = ServiceOperation("READ_QUESTS");
	const ServiceOperation ServiceOperation::ReadCompletedQuests = ServiceOperation("READ_COMPLETED_QUESTS");
	const ServiceOperation ServiceOperation::ReadInProgressQuests = ServiceOperation("READ_IN_PROGRESS_QUESTS");
	const ServiceOperation ServiceOperation::ReadNotStartedQuests = ServiceOperation("READ_NOT_STARTED_QUESTS");
	const ServiceOperation ServiceOperation::ReadQuestsWithStatus = ServiceOperation("READ_QUESTS_WITH_STATUS");
	const ServiceOperation ServiceOperation::ReadQuestsWithBasicPercentage = ServiceOperation("READ_QUESTS_WITH_BASIC_PERCENTAGE");
	const ServiceOperation ServiceOperation::ReadQuestsWithComplexPercentage = ServiceOperation("READ_QUESTS_WITH_COMPLEX_PERCENTAGE");
	const ServiceOperation ServiceOperation::ReadQuestsByCategory = ServiceOperation("READ_QUESTS_BY_CATEGORY");
	
	const ServiceOperation ServiceOperation::ReadGameStatisticsByCategory = ServiceOperation("READ_GAME_STATISTICS_BY_CATEGORY");
	const ServiceOperation ServiceOperation::ReadPlayerStatisticsByCategory = ServiceOperation("READ_PLAYER_STATISTICS_BY_CATEGORY");
	
	const ServiceOperation ServiceOperation::ReadMilestones = ServiceOperation("READ_MILESTONES");
	const ServiceOperation ServiceOperation::ReadMilestonesByCategory = ServiceOperation("READ_MILESTONES_BY_CATEGORY");
	const ServiceOperation ServiceOperation::ResetMilestones = ServiceOperation("RESET_MILESTONES");
	
	const ServiceOperation ServiceOperation::ReadCompletedMilestones = ServiceOperation("READ_COMPLETED_MILESTONES");
	const ServiceOperation ServiceOperation::ReadInProgressMilestones = ServiceOperation("READ_IN_PROGRESS_MILESTONES");
	
	const ServiceOperation ServiceOperation::Logout = ServiceOperation("LOGOUT");
	const ServiceOperation ServiceOperation::UpdateName = ServiceOperation("UPDATE_NAME");
	
	const ServiceOperation ServiceOperation::StartMatch = ServiceOperation("START_MATCH");
	const ServiceOperation ServiceOperation::CancelMatch = ServiceOperation("CANCEL_MATCH");
	const ServiceOperation ServiceOperation::CompleteMatch = ServiceOperation("COMPLETE_MATCH");
	const ServiceOperation ServiceOperation::EnableMatchMaking = ServiceOperation("ENABLE_FOR_MATCH");

	const ServiceOperation ServiceOperation::StartStream = ServiceOperation("START_STREAM");
	const ServiceOperation ServiceOperation::ReadStream = ServiceOperation("READ_STREAM");
	const ServiceOperation ServiceOperation::EndStream = ServiceOperation("END_STREAM");
	const ServiceOperation ServiceOperation::DeleteStream = ServiceOperation("DELETE_STREAM");
	const ServiceOperation ServiceOperation::AddEvent = ServiceOperation("ADD_EVENT");
	const ServiceOperation ServiceOperation::GetStreamSummariesForInitiatingPlayer = ServiceOperation("GET_STREAM_SUMMARIES_FOR_INITIATING_PLAYER");
	const ServiceOperation ServiceOperation::GetStreamSummariesForTargetPlayer = ServiceOperation("GET_STREAM_SUMMARIES_FOR_TARGET_PLAYER");

	const ServiceOperation ServiceOperation::GetUserInfo = ServiceOperation("GET_USER_INFO");
	
	const ServiceOperation ServiceOperation::StartSteamTransaction = ServiceOperation("START_STEAM_TRANSACTION");
	const ServiceOperation ServiceOperation::FinalizeSteamTransaction = ServiceOperation("FINALIZE_STEAM_TRANSACTION");
	const ServiceOperation ServiceOperation::VerifyMicrosoftReceipt = ServiceOperation("VERIFY_MICROSOFT_RECEIPT");
	const ServiceOperation ServiceOperation::ConfirmGooglePlayPurchase = ServiceOperation("CONFIRM_GOOGLEPLAY_PURCHASE");
	const ServiceOperation ServiceOperation::EligiblePromotions = ServiceOperation("ELIGIBLE_PROMOTIONS");
	
	const ServiceOperation ServiceOperation::GetList = ServiceOperation("GET_LIST");
	const ServiceOperation ServiceOperation::GetListByIndexedId = ServiceOperation("GET_LIST_BY_INDEXED_ID");
	const ServiceOperation ServiceOperation::GetListCount = ServiceOperation("GET_LIST_COUNT");
    const ServiceOperation ServiceOperation::GetPage = ServiceOperation("GET_PAGE");
    const ServiceOperation ServiceOperation::GetPageOffset = ServiceOperation("GET_PAGE_BY_OFFSET");
	
	const ServiceOperation ServiceOperation::GetAttributes = ServiceOperation("GET_ATTRIBUTES");
	const ServiceOperation ServiceOperation::UpdateAttributes = ServiceOperation("UPDATE_ATTRIBUTES");
	const ServiceOperation ServiceOperation::RemoveAttributes = ServiceOperation("REMOVE_ATTRIBUTES");
    const ServiceOperation ServiceOperation::UpdatePlayerPicture = ServiceOperation("UPDATE_PICTURE_URL");
    const ServiceOperation ServiceOperation::UpdateContactEmail = ServiceOperation("UPDATE_CONTACT_EMAIL");

	const ServiceOperation ServiceOperation::ReadProperties = ServiceOperation("READ_PROPERTIES");
    
    const ServiceOperation ServiceOperation::GetUpdatedFiles = ServiceOperation("GET_UPDATED_FILES");
    const ServiceOperation ServiceOperation::GetFileList = ServiceOperation("GET_FILE_LIST");
    
    const ServiceOperation ServiceOperation::ScheduleCloudScript = ServiceOperation("SCHEDULE_CLOUD_SCRIPT");
    const ServiceOperation ServiceOperation::RunParentScript = ServiceOperation("RUN_PARENT_SCRIPT");
    
    const ServiceOperation ServiceOperation::RedeemCode = ServiceOperation("REDEEM_CODE");
    const ServiceOperation ServiceOperation::GetRedeemedCodes = ServiceOperation("GET_REDEEMED_CODES");
    
    const ServiceOperation ServiceOperation::CustomPageEvent = ServiceOperation("CUSTOM_PAGE_EVENT");
    const ServiceOperation ServiceOperation::CustomScreenEvent = ServiceOperation("CUSTOM_SCREEN_EVENT");
    const ServiceOperation ServiceOperation::CustomTrackEvent = ServiceOperation("CUSTOM_TRACK_EVENT");
    
    // profanity
    const ServiceOperation ServiceOperation::ProfanityCheck = ServiceOperation("PROFANITY_CHECK");
    const ServiceOperation ServiceOperation::ProfanityReplaceText = ServiceOperation("PROFANITY_REPLACE_TEXT");
    const ServiceOperation ServiceOperation::ProfanityIdenitfyBadWords = ServiceOperation("PROFANITY_IDENTIFY_BAD_WORDS");
    
    // file
    const ServiceOperation ServiceOperation::PrepareUserUpload = ServiceOperation("PREPARE_USER_UPLOAD");
    const ServiceOperation ServiceOperation::ListUserFiles = ServiceOperation("LIST_USER_FILES");
    const ServiceOperation ServiceOperation::DeleteUserFiles = ServiceOperation("DELETE_USER_FILES");
    
	ServiceOperation::ServiceOperation(const char * value)
	{
		_value = value;
	}
	
	bool ServiceOperation::operator== (const ServiceOperation& s) const
	{
		return _value == s.getValue();
	}
    
    bool ServiceOperation::operator!= (const ServiceOperation& s) const
    {
        return _value != s.getValue();
    }

    void ServiceOperation::operator= (const ServiceOperation& s)
    {
        _value = s.getValue();
    }
    
}
