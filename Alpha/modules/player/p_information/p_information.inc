#define TIME_TO_READ_RULES (22000)

forward OnPassIsHashed(playerid);
forward OnPassChecked(playerid);

enum PlayerInfo {
	dbid,
	pName[MAX_PLAYER_NAME],
	pass[BCRYPT_HASH_LENGTH],
	bool:acceptedRules,
	gender[7],
	genderColor[9],
	bool:isChatLocked,
	adminLevel,
	staffTag[6],
	money,
	bool:isWorking
};

new player[MAX_PLAYERS][PlayerInfo];
new readingTimer[MAX_PLAYERS];
new readingTolerance[MAX_PLAYERS];
new bool:isReadyToLogin[MAX_PLAYERS];
new bool:hasTextdrawOpened[MAX_PLAYERS];


// VPI: VerifyPlayerInformation
public VPI_OnPlayerConnect(playerid)
{
	TogglePlayerSpectating(playerid, 1);

	// When a player connect to the server, take the old information in its id and clean them.
	new tempInfo[PlayerInfo];
	player[playerid] = tempInfo;

	// Then, verify the information of the player connected.
	isReadyToLogin[playerid] = false;

	readingTolerance[playerid] = 0;

	player[playerid][isChatLocked] = true;
	SetTimerEx("SMWD_SendClientMessage", 100, false, "iis", playerid, HEX_TOMORROW_ORANGE, "[Server » You] Your chat is locked until you spawn your character.");

	GetPlayerName(playerid, player[playerid][pName], MAX_PLAYER_NAME);

	new dbQuery[71], DBResult:dbResult;
	format(dbQuery, sizeof(dbQuery), "SELECT * FROM players WHERE pName = '%q' LIMIT 1", player[playerid][pName]);
	dbResult = db_query(pdbConnection, dbQuery);

	// If the number of rows in the database is 1 (limit 1), so this player, at least has read the rules.
	if (db_num_rows(dbResult) == 1)
	{
		hasTextdrawOpened[playerid] = true;
		ShowOpeningTDPanel(playerid);
	}
	// Otherwise, if there is no rows with the name of the player, so this player is has no register in the database.
	else
	{
		readingTimer[playerid] = GetTickCount();

		ShowPlayerDialog(playerid, rulesDialog, DIALOG_STYLE_MSGBOX, ""TOMORROW_AQUA"Rules to play in our server:", "\
		"TOMORROW_ORANGE"Note: Rules must be accepted by anyone that wants to play in our server.\n\
		\n\
		"TOMORROW_WHITE"1. Respect all players.\n\
		"TOMORROW_WHITE"2. Do not disturb players verbally and/or through actions.\n\
		"TOMORROW_WHITE"3. Do not use any kind of modification and/or program that affect other players and/or the server.\n\
		"TOMORROW_WHITE"4. Do not use any kind of hack and/or modification in you SA-MP and/or SA client that gives you benefits in our server.\n\
		"TOMORROW_WHITE"5. Do not benefit from bugs (instead, report the bug to administrators through the command: /rbug or /reportbug <details_about_the_bug>).\n\
		\n\
		"TOMORROW_YELLOW"Note: Try to always play very carefully and be curious about our server systems. I'm sure this will help you a lot in your journey!\n\
		"TOMORROW_GREEN"Have a great experience on our server, thank you for your time and understanding. "TOMORROW_AQUA"-End [Server Owner and Founder].", "Accept", "Deny");
	}

	db_free_result(dbResult);

	return 1;
}

//------------------------------
// Hooking Function: ShowOpeningTDPanel
#if defined _ALS_TextDrawShowForPlayer
	#undef TextDrawShowForPlayer
#else
	#define _ALS_TextDrawShowForPlayer
#endif

#define TextDrawShowForPlayer ShowOpeningTDPanel(playerid)
//------------------------------

// SPI: SavePlayerInformation
public SPI_OnPlayerDisconnect(playerid, reason)
{
	// After updating all information from the disconnected player, do a cleanup through your id of your information.
	new tempInfo[PlayerInfo];
	player[playerid] = tempInfo;

	readingTimer[playerid] = 0;
	readingTolerance[playerid] = 0;
	hasTextdrawOpened[playerid] = false;

	return 1;
}

public OnPassIsHashed(playerid)
{
	bcrypt_get_hash(player[playerid][pass]);

	new dbQuery[134];
	format(dbQuery, sizeof(dbQuery), "UPDATE players SET pass = '%s' WHERE pName = '%q'", player[playerid][pass], player[playerid][pName]);
	db_query(pdbConnection, dbQuery);
	
	SendClientMessage(playerid, HEX_TOMORROW_GREEN, "[Server » You] Registration completed successfully.");

	new DBResult:dbResult;
	dbResult = db_query(pdbConnection, "SELECT last_insert_rowid()");
	
	player[playerid][dbid] = db_get_field_int(dbResult);

	db_free_result(dbResult);

	readingTolerance[playerid] = 0;

	ShowPlayerDialog(playerid, genderDialog, DIALOG_STYLE_LIST, ""TOMORROW_ORANGE"Select your gender.", ""DRACULA_PINK"Female\n"DRACULA_CYAN"Male\n"TOMORROW_WHITE"Other", "Select", "");

	return 1;
}

public OnPassChecked(playerid)
{
	isReadyToLogin[playerid] = bcrypt_is_equal();

	if (!isReadyToLogin[playerid])
	{
		if (readingTolerance[playerid] == 0)
		{
			SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] incorrect password.");
			readingTolerance[playerid]++;
		}

		ShowPlayerDialog(playerid, loginDialog, DIALOG_STYLE_PASSWORD, ""TOMORROW_GREEN"Login area.", ""TOMORROW_YELLOW"It looks like you're already a registered member, enter your account password to login.", "Login", "Cancel");
		return 1;
	}

	readingTolerance[playerid] = 0;

	new dbQuery[72], DBResult:dbResult;
	format(dbQuery, sizeof(dbQuery), "SELECT * FROM players WHERE pName = '%q' LIMIT 1", player[playerid][pName]);
	dbResult = db_query(pdbConnection, dbQuery);

	if (db_num_rows(dbResult))
	{
		player[playerid][dbid] = db_get_field_assoc_int(dbResult, "dbid");
		new acceptedRulesCache = db_get_field_assoc_int(dbResult, "acceptedRules");
		player[playerid][acceptedRules] = (acceptedRulesCache == 1) ? true : false;
		db_get_field_assoc(dbResult, "gender", player[playerid][gender], 7);
		db_get_field_assoc(dbResult, "genderColor", player[playerid][genderColor], 9);
		player[playerid][adminLevel] = db_get_field_assoc_int(dbResult, "adminLevel");
		db_get_field_assoc(dbResult, "staffTag", player[playerid][staffTag], 6);
		player[playerid][money] = db_get_field_assoc_int(dbResult, "money");
		GivePlayerMoney(playerid, player[playerid][money]);
	}

	db_free_result(dbResult);

	SendClientMessage(playerid, HEX_TOMORROW_GREEN, "[Server » You] Logged in successfully.");

	if(!strcmp(player[playerid][genderColor], DRACULA_PINK))
	{
		SetPlayerColor(playerid, HEX_DRACULA_PINK);
	}
	else
	{
		SetPlayerColor(playerid, HEX_DRACULA_CYAN);
	}

	InterpolateCameraPos(playerid, 2901.6531, 895.2303, 43.1143, 2853.5950, 939.4451, 13.7023, 3500, CAMERA_MOVE);
	InterpolateCameraLookAt(playerid, 2853.6677, 945.5969, 10.7500, 2853.6677, 945.5969, 10.7500, 1000, CAMERA_CUT);

	SetTimerEx("ToggleSpectating", 3500, false, "ii", playerid, 0);

	return 1;
}