#include <player/colors/cp_dracula>
#include <player/colors/cp_tomorrow>
#include <player/textdraws/p_textdraws>
#include <player/characters/p_characters>
#include <player/r_building/r_building>
#include <player/p_information/p_information>
#include <player/commands/normal/player_commands>
#include <player/commands/administration/admin_commands>
#include <server/routes/routes>

forward SMWD_SendClientMessage(playerid, hexColor, msg[]);
forward DefineJoinCamera(playerid);
forward UpdateVI(playerid, vehicleid);

public SetVI_OnPlayerConnect(playerid)
{
	boxInterfaceDesign1[playerid] = CreatePlayerTextDraw(playerid, 88.000000, 240.000000, "_");
	PlayerTextDrawFont(playerid, boxInterfaceDesign1[playerid], 1);
	PlayerTextDrawLetterSize(playerid, boxInterfaceDesign1[playerid], 0.600000, 0.000000);
	PlayerTextDrawTextSize(playerid, boxInterfaceDesign1[playerid], 289.500000, 172.500000);
	PlayerTextDrawSetOutline(playerid, boxInterfaceDesign1[playerid], 0);
	PlayerTextDrawSetShadow(playerid, boxInterfaceDesign1[playerid], 0);
	PlayerTextDrawAlignment(playerid, boxInterfaceDesign1[playerid], 2);
	PlayerTextDrawColor(playerid, boxInterfaceDesign1[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, boxInterfaceDesign1[playerid], 255);
	PlayerTextDrawBoxColor(playerid, boxInterfaceDesign1[playerid], -156);
	PlayerTextDrawUseBox(playerid, boxInterfaceDesign1[playerid], 1);
	PlayerTextDrawSetProportional(playerid, boxInterfaceDesign1[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, boxInterfaceDesign1[playerid], 0);

	boxDeliveryInterface1[playerid] = CreatePlayerTextDraw(playerid, 88.000000, 243.000000, "_");
	PlayerTextDrawFont(playerid, boxDeliveryInterface1[playerid], 1);
	PlayerTextDrawLetterSize(playerid, boxDeliveryInterface1[playerid], 0.600000, 10.300003);
	PlayerTextDrawTextSize(playerid, boxDeliveryInterface1[playerid], 298.500000, 172.500000);
	PlayerTextDrawSetOutline(playerid, boxDeliveryInterface1[playerid], 0);
	PlayerTextDrawSetShadow(playerid, boxDeliveryInterface1[playerid], 0);
	PlayerTextDrawAlignment(playerid, boxDeliveryInterface1[playerid], 2);
	PlayerTextDrawColor(playerid, boxDeliveryInterface1[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, boxDeliveryInterface1[playerid], 255);
	PlayerTextDrawBoxColor(playerid, boxDeliveryInterface1[playerid], 100);
	PlayerTextDrawUseBox(playerid, boxDeliveryInterface1[playerid], 1);
	PlayerTextDrawSetProportional(playerid, boxDeliveryInterface1[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, boxDeliveryInterface1[playerid], 0);

	boxDeliveryInterface2[playerid] = CreatePlayerTextDraw(playerid, 88.000000, 243.000000, "_");
	PlayerTextDrawFont(playerid, boxDeliveryInterface2[playerid], 1);
	PlayerTextDrawLetterSize(playerid, boxDeliveryInterface2[playerid], 0.600000, 6.299984);
	PlayerTextDrawTextSize(playerid, boxDeliveryInterface2[playerid], 298.500000, 172.500000);
	PlayerTextDrawSetOutline(playerid, boxDeliveryInterface2[playerid], 0);
	PlayerTextDrawSetShadow(playerid, boxDeliveryInterface2[playerid], 0);
	PlayerTextDrawAlignment(playerid, boxDeliveryInterface2[playerid], 2);
	PlayerTextDrawColor(playerid, boxDeliveryInterface2[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, boxDeliveryInterface2[playerid], 255);
	PlayerTextDrawBoxColor(playerid, boxDeliveryInterface2[playerid], 100);
	PlayerTextDrawUseBox(playerid, boxDeliveryInterface2[playerid], 1);
	PlayerTextDrawSetProportional(playerid, boxDeliveryInterface2[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, boxDeliveryInterface2[playerid], 0);

	boxVehicleImage[playerid] = CreatePlayerTextDraw(playerid, 1.000000, 241.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, boxVehicleImage[playerid], 5);
	PlayerTextDrawLetterSize(playerid, boxVehicleImage[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, boxVehicleImage[playerid], 50.000000, 50.000000);
	PlayerTextDrawSetOutline(playerid, boxVehicleImage[playerid], 0);
	PlayerTextDrawSetShadow(playerid, boxVehicleImage[playerid], 0);
	PlayerTextDrawAlignment(playerid, boxVehicleImage[playerid], 2);
	PlayerTextDrawColor(playerid, boxVehicleImage[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, boxVehicleImage[playerid], 0);
	PlayerTextDrawBoxColor(playerid, boxVehicleImage[playerid], 255);
	PlayerTextDrawUseBox(playerid, boxVehicleImage[playerid], 0);
	PlayerTextDrawSetProportional(playerid, boxVehicleImage[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, boxVehicleImage[playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, boxVehicleImage[playerid], -1);
	PlayerTextDrawSetPreviewRot(playerid, boxVehicleImage[playerid], -10.000000, 2.000000, -26.000000, 0.929997);
	PlayerTextDrawSetPreviewVehCol(playerid, boxVehicleImage[playerid], 1, 1);

	textVehicleName[playerid] = CreatePlayerTextDraw(playerid, 26.000000, 293.000000, "-");
	PlayerTextDrawFont(playerid, textVehicleName[playerid], 2);
	PlayerTextDrawLetterSize(playerid, textVehicleName[playerid], 0.095833, 0.750000);
	PlayerTextDrawTextSize(playerid, textVehicleName[playerid], 50.000000, 47.500000);
	PlayerTextDrawSetOutline(playerid, textVehicleName[playerid], 0);
	PlayerTextDrawSetShadow(playerid, textVehicleName[playerid], 0);
	PlayerTextDrawAlignment(playerid, textVehicleName[playerid], 2);
	PlayerTextDrawColor(playerid, textVehicleName[playerid], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, textVehicleName[playerid], 255);
	PlayerTextDrawBoxColor(playerid, textVehicleName[playerid], 50);
	PlayerTextDrawUseBox(playerid, textVehicleName[playerid], 0);
	PlayerTextDrawSetProportional(playerid, textVehicleName[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, textVehicleName[playerid], 0);

	textVehicleSpeed[playerid] = CreatePlayerTextDraw(playerid, 52.000000, 258.000000, "Speed:");
	PlayerTextDrawFont(playerid, textVehicleSpeed[playerid], 2);
	PlayerTextDrawLetterSize(playerid, textVehicleSpeed[playerid], 0.154164, 1.299998);
	PlayerTextDrawTextSize(playerid, textVehicleSpeed[playerid], 74.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, textVehicleSpeed[playerid], 0);
	PlayerTextDrawSetShadow(playerid, textVehicleSpeed[playerid], 0);
	PlayerTextDrawAlignment(playerid, textVehicleSpeed[playerid], 1);
	PlayerTextDrawColor(playerid, textVehicleSpeed[playerid], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, textVehicleSpeed[playerid], 255);
	PlayerTextDrawBoxColor(playerid, textVehicleSpeed[playerid], 50);
	PlayerTextDrawUseBox(playerid, textVehicleSpeed[playerid], 0);
	PlayerTextDrawSetProportional(playerid, textVehicleSpeed[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, textVehicleSpeed[playerid], 0);

	labelVehicleSpeed[playerid] = CreatePlayerTextDraw(playerid, 77.000000, 258.000000, "0 KM/H");
	PlayerTextDrawFont(playerid, labelVehicleSpeed[playerid], 2);
	PlayerTextDrawLetterSize(playerid, labelVehicleSpeed[playerid], 0.154164, 1.299998);
	PlayerTextDrawTextSize(playerid, labelVehicleSpeed[playerid], 174.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, labelVehicleSpeed[playerid], 0);
	PlayerTextDrawSetShadow(playerid, labelVehicleSpeed[playerid], 0);
	PlayerTextDrawAlignment(playerid, labelVehicleSpeed[playerid], 1);
	PlayerTextDrawColor(playerid, labelVehicleSpeed[playerid], -2016478465);
	PlayerTextDrawBackgroundColor(playerid, labelVehicleSpeed[playerid], 255);
	PlayerTextDrawBoxColor(playerid, labelVehicleSpeed[playerid], 50);
	PlayerTextDrawUseBox(playerid, labelVehicleSpeed[playerid], 0);
	PlayerTextDrawSetProportional(playerid, labelVehicleSpeed[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, labelVehicleSpeed[playerid], 0);

	textVehicleCondition[playerid] = CreatePlayerTextDraw(playerid, 52.000000, 243.000000, "Vehicle condition:");
	PlayerTextDrawFont(playerid, textVehicleCondition[playerid], 2);
	PlayerTextDrawLetterSize(playerid, textVehicleCondition[playerid], 0.154164, 1.299998);
	PlayerTextDrawTextSize(playerid, textVehicleCondition[playerid], 115.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, textVehicleCondition[playerid], 0);
	PlayerTextDrawSetShadow(playerid, textVehicleCondition[playerid], 0);
	PlayerTextDrawAlignment(playerid, textVehicleCondition[playerid], 1);
	PlayerTextDrawColor(playerid, textVehicleCondition[playerid], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, textVehicleCondition[playerid], 255);
	PlayerTextDrawBoxColor(playerid, textVehicleCondition[playerid], 50);
	PlayerTextDrawUseBox(playerid, textVehicleCondition[playerid], 0);
	PlayerTextDrawSetProportional(playerid, textVehicleCondition[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, textVehicleCondition[playerid], 0);

	labelVehicleCondition[playerid] = CreatePlayerTextDraw(playerid, 117.000000, 243.000000, "-");
	PlayerTextDrawFont(playerid, labelVehicleCondition[playerid], 2);
	PlayerTextDrawLetterSize(playerid, labelVehicleCondition[playerid], 0.154164, 1.299998);
	PlayerTextDrawTextSize(playerid, labelVehicleCondition[playerid], 174.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, labelVehicleCondition[playerid], 0);
	PlayerTextDrawSetShadow(playerid, labelVehicleCondition[playerid], 0);
	PlayerTextDrawAlignment(playerid, labelVehicleCondition[playerid], 1);
	PlayerTextDrawColor(playerid, labelVehicleCondition[playerid], -2016478465);
	PlayerTextDrawBackgroundColor(playerid, labelVehicleCondition[playerid], 255);
	PlayerTextDrawBoxColor(playerid, labelVehicleCondition[playerid], 50);
	PlayerTextDrawUseBox(playerid, labelVehicleCondition[playerid], 0);
	PlayerTextDrawSetProportional(playerid, labelVehicleCondition[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, labelVehicleCondition[playerid], 0);

	textVehicleFuel[playerid] = CreatePlayerTextDraw(playerid, 52.000000, 273.000000, "Fuel:");
	PlayerTextDrawFont(playerid, textVehicleFuel[playerid], 2);
	PlayerTextDrawLetterSize(playerid, textVehicleFuel[playerid], 0.154164, 1.299998);
	PlayerTextDrawTextSize(playerid, textVehicleFuel[playerid], 69.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, textVehicleFuel[playerid], 0);
	PlayerTextDrawSetShadow(playerid, textVehicleFuel[playerid], 0);
	PlayerTextDrawAlignment(playerid, textVehicleFuel[playerid], 1);
	PlayerTextDrawColor(playerid, textVehicleFuel[playerid], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, textVehicleFuel[playerid], 255);
	PlayerTextDrawBoxColor(playerid, textVehicleFuel[playerid], 50);
	PlayerTextDrawUseBox(playerid, textVehicleFuel[playerid], 0);
	PlayerTextDrawSetProportional(playerid, textVehicleFuel[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, textVehicleFuel[playerid], 0);

	labelVehicleFuel[playerid] = CreatePlayerTextDraw(playerid, 72.000000, 273.000000, "0L");
	PlayerTextDrawFont(playerid, labelVehicleFuel[playerid], 2);
	PlayerTextDrawLetterSize(playerid, labelVehicleFuel[playerid], 0.154164, 1.299998);
	PlayerTextDrawTextSize(playerid, labelVehicleFuel[playerid], 174.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, labelVehicleFuel[playerid], 0);
	PlayerTextDrawSetShadow(playerid, labelVehicleFuel[playerid], 0);
	PlayerTextDrawAlignment(playerid, labelVehicleFuel[playerid], 1);
	PlayerTextDrawColor(playerid, labelVehicleFuel[playerid], -2016478465);
	PlayerTextDrawBackgroundColor(playerid, labelVehicleFuel[playerid], 255);
	PlayerTextDrawBoxColor(playerid, labelVehicleFuel[playerid], 50);
	PlayerTextDrawUseBox(playerid, labelVehicleFuel[playerid], 0);
	PlayerTextDrawSetProportional(playerid, labelVehicleFuel[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, labelVehicleFuel[playerid], 0);

	textLoadInfo[playerid] = CreatePlayerTextDraw(playerid, 106.000000, 293.000000, "Load:");
	PlayerTextDrawFont(playerid, textLoadInfo[playerid], 2);
	PlayerTextDrawLetterSize(playerid, textLoadInfo[playerid], 0.095833, 0.750000);
	PlayerTextDrawTextSize(playerid, textLoadInfo[playerid], 117.500000, 47.500000);
	PlayerTextDrawSetOutline(playerid, textLoadInfo[playerid], 0);
	PlayerTextDrawSetShadow(playerid, textLoadInfo[playerid], 0);
	PlayerTextDrawAlignment(playerid, textLoadInfo[playerid], 1);
	PlayerTextDrawColor(playerid, textLoadInfo[playerid], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, textLoadInfo[playerid], 255);
	PlayerTextDrawBoxColor(playerid, textLoadInfo[playerid], 50);
	PlayerTextDrawUseBox(playerid, textLoadInfo[playerid], 0);
	PlayerTextDrawSetProportional(playerid, textLoadInfo[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, textLoadInfo[playerid], 0);

	labelLoadInfo[playerid] = CreatePlayerTextDraw(playerid, 120.000000, 293.000000, "-");
	PlayerTextDrawFont(playerid, labelLoadInfo[playerid], 2);
	PlayerTextDrawLetterSize(playerid, labelLoadInfo[playerid], 0.095833, 0.750000);
	PlayerTextDrawTextSize(playerid, labelLoadInfo[playerid], 174.000000, 47.500000);
	PlayerTextDrawSetOutline(playerid, labelLoadInfo[playerid], 0);
	PlayerTextDrawSetShadow(playerid, labelLoadInfo[playerid], 0);
	PlayerTextDrawAlignment(playerid, labelLoadInfo[playerid], 1);
	PlayerTextDrawColor(playerid, labelLoadInfo[playerid], -2016478465);
	PlayerTextDrawBackgroundColor(playerid, labelLoadInfo[playerid], 255);
	PlayerTextDrawBoxColor(playerid, labelLoadInfo[playerid], 50);
	PlayerTextDrawUseBox(playerid, labelLoadInfo[playerid], 0);
	PlayerTextDrawSetProportional(playerid, labelLoadInfo[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, labelLoadInfo[playerid], 0);

	textFrom[playerid] = CreatePlayerTextDraw(playerid, 2.000000, 304.000000, "From:");
	PlayerTextDrawFont(playerid, textFrom[playerid], 2);
	PlayerTextDrawLetterSize(playerid, textFrom[playerid], 0.095833, 0.750000);
	PlayerTextDrawTextSize(playerid, textFrom[playerid], 13.000000, 47.500000);
	PlayerTextDrawSetOutline(playerid, textFrom[playerid], 0);
	PlayerTextDrawSetShadow(playerid, textFrom[playerid], 0);
	PlayerTextDrawAlignment(playerid, textFrom[playerid], 1);
	PlayerTextDrawColor(playerid, textFrom[playerid], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, textFrom[playerid], 255);
	PlayerTextDrawBoxColor(playerid, textFrom[playerid], 50);
	PlayerTextDrawUseBox(playerid, textFrom[playerid], 0);
	PlayerTextDrawSetProportional(playerid, textFrom[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, textFrom[playerid], 0);

	labelFrom[playerid] = CreatePlayerTextDraw(playerid, 16.000000, 304.000000, "-");
	PlayerTextDrawFont(playerid, labelFrom[playerid], 2);
	PlayerTextDrawLetterSize(playerid, labelFrom[playerid], 0.095833, 0.750000);
	PlayerTextDrawTextSize(playerid, labelFrom[playerid], 95.000000, 47.500000);
	PlayerTextDrawSetOutline(playerid, labelFrom[playerid], 0);
	PlayerTextDrawSetShadow(playerid, labelFrom[playerid], 0);
	PlayerTextDrawAlignment(playerid, labelFrom[playerid], 1);
	PlayerTextDrawColor(playerid, labelFrom[playerid], -2016478465);
	PlayerTextDrawBackgroundColor(playerid, labelFrom[playerid], 255);
	PlayerTextDrawBoxColor(playerid, labelFrom[playerid], 50);
	PlayerTextDrawUseBox(playerid, labelFrom[playerid], 0);
	PlayerTextDrawSetProportional(playerid, labelFrom[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, labelFrom[playerid], 0);

	textTo[playerid] = CreatePlayerTextDraw(playerid, 2.000000, 315.000000, "To:");
	PlayerTextDrawFont(playerid, textTo[playerid], 2);
	PlayerTextDrawLetterSize(playerid, textTo[playerid], 0.095833, 0.750000);
	PlayerTextDrawTextSize(playerid, textTo[playerid], 8.500000, 47.500000);
	PlayerTextDrawSetOutline(playerid, textTo[playerid], 0);
	PlayerTextDrawSetShadow(playerid, textTo[playerid], 0);
	PlayerTextDrawAlignment(playerid, textTo[playerid], 1);
	PlayerTextDrawColor(playerid, textTo[playerid], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, textTo[playerid], 255);
	PlayerTextDrawBoxColor(playerid, textTo[playerid], 50);
	PlayerTextDrawUseBox(playerid, textTo[playerid], 0);
	PlayerTextDrawSetProportional(playerid, textTo[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, textTo[playerid], 0);

	labelTo[playerid] = CreatePlayerTextDraw(playerid, 11.000000, 315.000000, "-");
	PlayerTextDrawFont(playerid, labelTo[playerid], 2);
	PlayerTextDrawLetterSize(playerid, labelTo[playerid], 0.095833, 0.750000);
	PlayerTextDrawTextSize(playerid, labelTo[playerid], 95.000000, 47.500000);
	PlayerTextDrawSetOutline(playerid, labelTo[playerid], 0);
	PlayerTextDrawSetShadow(playerid, labelTo[playerid], 0);
	PlayerTextDrawAlignment(playerid, labelTo[playerid], 1);
	PlayerTextDrawColor(playerid, labelTo[playerid], -2016478465);
	PlayerTextDrawBackgroundColor(playerid, labelTo[playerid], 255);
	PlayerTextDrawBoxColor(playerid, labelTo[playerid], 50);
	PlayerTextDrawUseBox(playerid, labelTo[playerid], 0);
	PlayerTextDrawSetProportional(playerid, labelTo[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, labelTo[playerid], 0);

	textVehicleLoaded[playerid] = CreatePlayerTextDraw(playerid, 53.000000, 293.000000, "Vehicle loaded:");
	PlayerTextDrawFont(playerid, textVehicleLoaded[playerid], 2);
	PlayerTextDrawLetterSize(playerid, textVehicleLoaded[playerid], 0.095833, 0.750000);
	PlayerTextDrawTextSize(playerid, textVehicleLoaded[playerid], 87.500000, 47.500000);
	PlayerTextDrawSetOutline(playerid, textVehicleLoaded[playerid], 0);
	PlayerTextDrawSetShadow(playerid, textVehicleLoaded[playerid], 0);
	PlayerTextDrawAlignment(playerid, textVehicleLoaded[playerid], 1);
	PlayerTextDrawColor(playerid, textVehicleLoaded[playerid], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, textVehicleLoaded[playerid], 255);
	PlayerTextDrawBoxColor(playerid, textVehicleLoaded[playerid], 50);
	PlayerTextDrawUseBox(playerid, textVehicleLoaded[playerid], 0);
	PlayerTextDrawSetProportional(playerid, textVehicleLoaded[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, textVehicleLoaded[playerid], 0);

	labelVehicleLoaded[playerid] = CreatePlayerTextDraw(playerid, 90.000000, 293.000000, "No");
	PlayerTextDrawFont(playerid, labelVehicleLoaded[playerid], 2);
	PlayerTextDrawLetterSize(playerid, labelVehicleLoaded[playerid], 0.095833, 0.750000);
	PlayerTextDrawTextSize(playerid, labelVehicleLoaded[playerid], 103.000000, 49.500000);
	PlayerTextDrawSetOutline(playerid, labelVehicleLoaded[playerid], 0);
	PlayerTextDrawSetShadow(playerid, labelVehicleLoaded[playerid], 0);
	PlayerTextDrawAlignment(playerid, labelVehicleLoaded[playerid], 1);
	PlayerTextDrawColor(playerid, labelVehicleLoaded[playerid], -1962934017);
	PlayerTextDrawBackgroundColor(playerid, labelVehicleLoaded[playerid], 255);
	PlayerTextDrawBoxColor(playerid, labelVehicleLoaded[playerid], 50);
	PlayerTextDrawUseBox(playerid, labelVehicleLoaded[playerid], 0);
	PlayerTextDrawSetProportional(playerid, labelVehicleLoaded[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, labelVehicleLoaded[playerid], 0);

	textReward[playerid] = CreatePlayerTextDraw(playerid, 2.000000, 326.000000, "Reward:");
	PlayerTextDrawFont(playerid, textReward[playerid], 2);
	PlayerTextDrawLetterSize(playerid, textReward[playerid], 0.095833, 0.750000);
	PlayerTextDrawTextSize(playerid, textReward[playerid], 19.000000, 47.500000);
	PlayerTextDrawSetOutline(playerid, textReward[playerid], 0);
	PlayerTextDrawSetShadow(playerid, textReward[playerid], 0);
	PlayerTextDrawAlignment(playerid, textReward[playerid], 1);
	PlayerTextDrawColor(playerid, textReward[playerid], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, textReward[playerid], 255);
	PlayerTextDrawBoxColor(playerid, textReward[playerid], 50);
	PlayerTextDrawUseBox(playerid, textReward[playerid], 0);
	PlayerTextDrawSetProportional(playerid, textReward[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, textReward[playerid], 0);

	labelReward[playerid] = CreatePlayerTextDraw(playerid, 21.000000, 326.000000, "$0");
	PlayerTextDrawFont(playerid, labelReward[playerid], 2);
	PlayerTextDrawLetterSize(playerid, labelReward[playerid], 0.095833, 0.750000);
	PlayerTextDrawTextSize(playerid, labelReward[playerid], 61.500000, 47.500000);
	PlayerTextDrawSetOutline(playerid, labelReward[playerid], 0);
	PlayerTextDrawSetShadow(playerid, labelReward[playerid], 0);
	PlayerTextDrawAlignment(playerid, labelReward[playerid], 1);
	PlayerTextDrawColor(playerid, labelReward[playerid], 9109759);
	PlayerTextDrawBackgroundColor(playerid, labelReward[playerid], 255);
	PlayerTextDrawBoxColor(playerid, labelReward[playerid], 50);
	PlayerTextDrawUseBox(playerid, labelReward[playerid], 0);
	PlayerTextDrawSetProportional(playerid, labelReward[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, labelReward[playerid], 0);

	return 1;
}

public DestroyVI_OnPlayerDisconnect(playerid, reason)
{
	PlayerTextDrawDestroy(playerid, boxInterfaceDesign1[playerid]);
	PlayerTextDrawDestroy(playerid, boxDeliveryInterface1[playerid]);
	PlayerTextDrawDestroy(playerid, boxDeliveryInterface2[playerid]);

	PlayerTextDrawDestroy(playerid, boxVehicleImage[playerid]);
	PlayerTextDrawDestroy(playerid, textVehicleName[playerid]);

	PlayerTextDrawDestroy(playerid, textVehicleSpeed[playerid]);
	PlayerTextDrawDestroy(playerid, labelVehicleSpeed[playerid]);

	PlayerTextDrawDestroy(playerid, textVehicleCondition[playerid]);
	PlayerTextDrawDestroy(playerid, labelVehicleCondition[playerid]);

	PlayerTextDrawDestroy(playerid, textVehicleFuel[playerid]);
	PlayerTextDrawDestroy(playerid, labelVehicleFuel[playerid]);

	PlayerTextDrawDestroy(playerid, textLoadInfo[playerid]);
	PlayerTextDrawDestroy(playerid, labelLoadInfo[playerid]);

	PlayerTextDrawDestroy(playerid, textFrom[playerid]);
	PlayerTextDrawDestroy(playerid, labelFrom[playerid]);

	PlayerTextDrawDestroy(playerid, textTo[playerid]);
	PlayerTextDrawDestroy(playerid, labelTo[playerid]);

	PlayerTextDrawDestroy(playerid, textVehicleLoaded[playerid]);
	PlayerTextDrawDestroy(playerid, labelVehicleLoaded[playerid]);

	PlayerTextDrawDestroy(playerid, textReward[playerid]);
	PlayerTextDrawDestroy(playerid, labelReward[playerid]);

	return 1;
}

public UpdateVI(playerid, vehicleid)
{
	new hmphInfo[17];

	format(hmphInfo, sizeof(hmphInfo), "%i KM/H", GetVehicleSpeed(vehicleid));

	PlayerTextDrawSetString(playerid, labelVehicleSpeed[playerid], hmphInfo);

	//PlayerTextDrawDestroy(playerid, labelVehicleSpeed[playerid]);
	//labelVehicleSpeed[playerid] = CreatePlayerTextDraw(playerid, 77.000000, 258.000000, hmphInfo);

	return 1;	
}

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