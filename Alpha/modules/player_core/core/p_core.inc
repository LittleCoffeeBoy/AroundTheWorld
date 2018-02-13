#include <player_core/colors/cp_dracula>
#include <player_core/colors/cp_tomorrow>
#include <player_core/characters/p_characters>
#include <player_core/r_building/r_building>
#include <player_core/p_information/p_information>
#include <player_core/commands/normal/player_commands>
#include <player_core/commands/administration/admin_commands>
#include <server_core/routes/routes>

forward SMWD_SendClientMessage(playerid, hexColor, msg[]);
forward DefineJoinCamera(playerid);

// DJC: DefineJoinCamera
public DJC_OnPlayerConnect(playerid)
{
	SetTimerEx("DefineJoinCamera", 100, false, "i", playerid);

	return 1;
}

public DefineJoinCamera(playerid)
{
	// Configura a câmera do jogador para o primeiro resgate em Las Venturas.
	InterpolateCameraPos(playerid, 2901.6531, 895.2303, 43.1143, 2901.6531, 895.2303, 43.1143, 1000, CAMERA_CUT);
	InterpolateCameraLookAt(playerid, 2853.6677, 945.5969, 10.7500, 2853.6677, 945.5969, 10.7500, 1000, CAMERA_CUT);

	return 1;
}

// SMWD: SendMessageWithDelay
public SMWD_SendClientMessage(playerid, hexColor, msg[])
{
	SendClientMessage(playerid, hexColor, msg);

	return 1;
}

//------------------------------
// Hooking Function: SMWD_SendClientMessage
#if defined _ALS_SendClientMessage
	#undef SendClientMessage
#else
	#define _ALS_SendClientMessage
#endif

#define SendClientMessage SMWD_SendClientMessage
//------------------------------

public ToggleSpectating(playerid, isSpectating)
{
	TogglePlayerSpectating(playerid, isSpectating);

	return 1;
}

//------------------------------
// Hooking Function: ToggleSpectating
#if defined _ALS_TogglePlayerSpectating
	#undef TogglePlayerSpectating
#else
	#define _ALS_TogglePlayerSpectating
#endif

#define TogglePlayerSpectating ToggleSpectating
//------------------------------

public KickThePlayer(playerid)
{
	Kick(playerid);
	return 1;
}

//------------------------------
// Hooking Function: KickThePlayer
#if defined _ALS_Kick
	#undef Kick
#else
	#define _ALS_Kick
#endif

#define Kick KickThePlayer
//------------------------------