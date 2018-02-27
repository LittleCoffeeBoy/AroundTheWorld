cmd:createroute(playerid, params[])
{
	if (strlen(params) != 0)
	{
		SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Usage: /createroute");
		return 0;
	}

	ShowPlayerDialog(playerid, createRoute0, DIALOG_STYLE_MSGBOX, ""TOMORROW_BLUE"Create a route for the server.", "\
	"TOMORROW_ORANGE"In the next dialogs, you will have to:\n\
	"TOMORROW_WHITE"1. Define a truck for the deliver.\n\
	"TOMORROW_WHITE"2. If delivery requires a trailer, set it. Otherwise, just proceed.\n\
	"TOMORROW_WHITE"3. Define the average delivery time.\n\
	"TOMORROW_WHITE"4. Define what will be delivered.\n\
	"TOMORROW_WHITE"5. Set the load value that will be sended to the server global bank.\n\
	"TOMORROW_WHITE"6. Define the type of load through.\n\
	"TOMORROW_WHITE"7. Define the name of the place of departure.\n\
	"TOMORROW_WHITE"8. Define the positions for the place of departure.\n\
	"TOMORROW_WHITE"9. Define the name of the delivery place.\n\
	"TOMORROW_WHITE"10. Define the positions for the delivery place.\n\
	"TOMORROW_RED"Note: The reward in cash is the load value / 3.325.\n", "Continue", "Cancel");

	return 1;
}

cmd:vehicle(playerid, params[]) {
	//if(player[playerid][adminLevel] < 1) return SendClientMessage(playerid, HEX_DRACULA_RED, "[Server » You] Unknown command.");

	new targetId, vehicleIdCache, vehicleColor1, vehicleColor2;

	if(sscanf(params, "uiii", targetId, vehicleIdCache, vehicleColor1, vehicleColor2)) return SendClientMessage(playerid, HEX_DRACULA_ORANGE, "[Server » You] Usage: /vehicle <target_id> <vehicle_id> <color> <color>");//<(true/false)put_player_in_vehicle>
	if(!IsPlayerConnected(targetId)) return SendClientMessage(playerid, HEX_DRACULA_RED, "[Server » You] Player not connected!");
	if(vehicleIdCache < 400 ||  vehicleIdCache > 611) return SendClientMessage(playerid, HEX_DRACULA_RED, "[Server » You] Invalid Vehicle ID. Available vehicles id (400 - 611)!");
	if((vehicleColor1 < 0 || vehicleColor1 > 255) || (vehicleColor2 < 0 || vehicleColor2 > 255)) return SendClientMessage(playerid, HEX_DRACULA_RED, "[Server » You] Invalid colors. Available vehicle colors (000 - 255)!");

	new Float:playerPosX, Float:playerPosY, Float:playerPosZ, Float:playerAngle, distanceFromPlayer;

	distanceFromPlayer = 8;

	GetPlayerPos(targetId, playerPosX, playerPosY, playerPosZ);
	GetPlayerFacingAngle(targetId, playerAngle);

	new Float:vehicleX, Float:vehicleY;

	vehicleX = distanceFromPlayer * floatcos(playerAngle + 90, degrees) + playerPosX;
	vehicleY = distanceFromPlayer * floatsin(playerAngle + 90, degrees) + playerPosY;

	CreateVehicle(vehicleIdCache, vehicleX, vehicleY, playerPosZ, playerAngle, vehicleColor1, vehicleColor2, -1);

	if(playerid == targetId) {
		SendClientMessage(playerid, HEX_DRACULA_GREEN, "[Server » You] You created a vehicle.");
	} else {
		new msg[86];
		format(msg, sizeof(msg), "[Server » You] You received a vehicle from %s (Staff Member).", player[playerid][pName]);
		SendClientMessage(targetId, HEX_DRACULA_GREEN, msg);
	}

	return 1;
}