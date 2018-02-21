#include <server/database/p_database>
#include <server/database/s_database>
#include <server/3DTextLabels/3d_tlabels>
#include <server/objects/s_objects>
#include <server/vehicles/s_vehicle>

#define BCRYPT_COST (13)

#define LOCAL_MESSAGE_RADIUS (100)

forward KickThePlayer(playerid);
forward ToggleSpectating(playerid, isSpectating);

enum
{
	rulesDialog,
	registerDialog,
	genderDialog,
	loginDialog,
	createRoute0, // CMD: createroute
	createRoute1, // Define a truck for the deliver.
	createRoute2, // Check if the truck needs a trailer, if it needs, define it. If it's not, just proceed.
	createRoute3, // Defining a trailer to the truck.
	createRoute4, // Define the average delivery time.
	createRoute5, // Define what will be delivered.
	createRoute6, // Set the load value that will be sended to the server global bank. (The reward in cash is the load value / 3.325)
	createRoute7, // Define the type of load through enums.
	createRoute8, // Define the name of the place of departure.
	createRoute9, // Define the positions for the place of departure.
	createRoute10, // Define the name of the delivery place.
	createRoute11, // Define the positions for the delivery place.
	routesDialog
};

enum
{
	lightLoad,
	normalLoad,
	heavyLoad,
	superHeavyLoad,
	lightAndFragileLoad,
	normalAndFragileLoad,
	heavyAndFragileLoad,
	superHeavyAndFragileLoad
};

/*
-* Steps to create a route of the server:
-* 1. Define a truck for the delivery.
-* 2. Check if the delivery needs a trailer, if it needs, define it. If it's not, just proceed.
-* 3. Define the average delivery time.
-* -. Company name (Around the World [AW]).
-* -. Company Owner (End).
-* 4. Define what will be delivered.
-* 5. Set the load value that will be sended to the server global bank.
-* 6. Define the type of load through enums (lightLoad, normalLoad, heavyLoad, superHeavyLoad, fragileLoad).
-* 7. Define the name of the place of departure.
-* 8, 9 and 10. Define the positions for the place of departure.
-* 11. Define the name of the delivery place.
-* 12, 13 and 14. Define the positions for the delivery place.
-* 15. Set the reward in cash.
*/
enum CreateRouteBuffer
{
	rTruck,
	rTrailer,
	rAverageDeliveryTime[37], // maybe remove 1 cell later (37 - 1 = 36)
	rCompanyName[26],
	rCompanyOwner[25],
	rWhatWillBeDelivered[21],
	rLoadValue,
	rLoadType,
	rFrom[31],
	Float:rPosFromX,
	Float:rPosFromY,
	Float:rPosFromZ,
	rTo[31],
	Float:rPosToX,
	Float:rPosToY,
	Float:rPosToZ,
	rRewardCash
};

new RouteBuffer[CreateRouteBuffer];

enum RoutesInfo
{
	iTruck,
	iTrailer,
	iAverageDeliveryTime[37], // maybe remove 1 cell later (37 - 1 = 36)
	iCompanyName[26],
	iCompanyOwner[25],
	iWhatWillBeDelivered[21],
	iLoadValue,
	iLoadType,
	iFrom[31],
	Float:iPosFromX,
	Float:iPosFromY,
	Float:iPosFromZ,
	iTo[31],
	Float:iPosToX,
	Float:iPosToY,
	Float:iPosToZ,
	iRewardCash
};

new RoutesInformation[MAX_PLAYERS][10][RoutesInfo];

new serverVersion[10];
new serverBuildnumber[10];

// Textdraws for the login interface.
new Text:tdBoxBackground;
new Text:tdDesignPanel;
new Text:tdBoxPanel;
new Text:tdBtnLogin;
new Text:tdBtnRegister;
new Text:tdBtnExit;
new Text:tdDesignLogin;
new Text:tdDesignRegister;
new Text:tdServerVersion;
new Text:tdVersionLabel;
new Text:tdBuildLabel;
new Text:tdBuildVersion;
new Text:tdPanelTitle1;
new Text:tdPanelTitle2;
new Text:tdPanelTitle3;
new Text:tdPanelTitle4;
new Text:tdPanelTitle5;

// SetDO: SetDefaultOptions
public SetDO_OnGameModeInit()
{
	SetGameModeText("[RPG] Trucker");
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
	ShowNameTags(1);
	EnableStuntBonusForAll(0);
	UsePlayerPedAnims();

	valstr(serverBuildnumber, nBuildnumber);
	format(serverVersion, sizeof(serverVersion), "Alpha");

	return 1;
}

// SetOTD: SetOpeningTextdraw
public SetOTD_OnGameModeInit()
{
	tdBoxBackground = TextDrawCreate(320.000000, 0.000000, "_");
	TextDrawFont(tdBoxBackground, 2);
	TextDrawLetterSize(tdBoxBackground, 0.587499, 49.649917);
	TextDrawTextSize(tdBoxBackground, 0.000000, 638.000000);
	TextDrawSetOutline(tdBoxBackground, 1);
	TextDrawSetShadow(tdBoxBackground, 0);
	TextDrawAlignment(tdBoxBackground, 2);
	TextDrawColor(tdBoxBackground, -1);
	TextDrawBackgroundColor(tdBoxBackground, 255);
	TextDrawBoxColor(tdBoxBackground, 120);
	TextDrawUseBox(tdBoxBackground, 1);
	TextDrawSetProportional(tdBoxBackground, 1);
	TextDrawSetSelectable(tdBoxBackground, 0);

	tdBoxPanel = TextDrawCreate(320.000000, 119.000000, "_");
	TextDrawFont(tdBoxPanel, 2);
	TextDrawLetterSize(tdBoxPanel, 0.587499, 19.999883);
	TextDrawTextSize(tdBoxPanel, 0.000000, 196.500000);
	TextDrawSetOutline(tdBoxPanel, 1);
	TextDrawSetShadow(tdBoxPanel, 0);
	TextDrawAlignment(tdBoxPanel, 2);
	TextDrawColor(tdBoxPanel, -1);
	TextDrawBackgroundColor(tdBoxPanel, 255);
	TextDrawBoxColor(tdBoxPanel, 120);
	TextDrawUseBox(tdBoxPanel, 1);
	TextDrawSetProportional(tdBoxPanel, 1);
	TextDrawSetSelectable(tdBoxPanel, 0);

	tdBtnLogin = TextDrawCreate(321.000000, 203.000000, "Login");
	TextDrawFont(tdBtnLogin, 2);
	TextDrawLetterSize(tdBtnLogin, 0.258332, 1.750000);
	TextDrawTextSize(tdBtnLogin, 11.000000, 29.000000);
	TextDrawSetOutline(tdBtnLogin, 1);
	TextDrawSetShadow(tdBtnLogin, 0);
	TextDrawAlignment(tdBtnLogin, 2);
	TextDrawColor(tdBtnLogin, -741092408);
	TextDrawBackgroundColor(tdBtnLogin, 255);
	TextDrawBoxColor(tdBtnLogin, -1);
	TextDrawUseBox(tdBtnLogin, 0);
	TextDrawSetProportional(tdBtnLogin, 1);
	TextDrawSetSelectable(tdBtnLogin, 1);

	tdBtnRegister = TextDrawCreate(321.000000, 237.000000, "Register");
	TextDrawFont(tdBtnRegister, 2);
	TextDrawLetterSize(tdBtnRegister, 0.258331, 1.750002);
	TextDrawTextSize(tdBtnRegister, 11.000000, 49.000000);
	TextDrawSetOutline(tdBtnRegister, 1);
	TextDrawSetShadow(tdBtnRegister, 0);
	TextDrawAlignment(tdBtnRegister, 2);
	TextDrawColor(tdBtnRegister, -741092408);
	TextDrawBackgroundColor(tdBtnRegister, 255);
	TextDrawBoxColor(tdBtnRegister, -1);
	TextDrawUseBox(tdBtnRegister, 0);
	TextDrawSetProportional(tdBtnRegister, 1);
	TextDrawSetSelectable(tdBtnRegister, 1);

	tdDesignLogin = TextDrawCreate(321.000000, 219.000000, "_");
	TextDrawFont(tdDesignLogin, 1);
	TextDrawLetterSize(tdDesignLogin, 0.595833, -0.250000);
	TextDrawTextSize(tdDesignLogin, 312.500000, 28.000000);
	TextDrawSetOutline(tdDesignLogin, 1);
	TextDrawSetShadow(tdDesignLogin, 0);
	TextDrawAlignment(tdDesignLogin, 2);
	TextDrawColor(tdDesignLogin, -1);
	TextDrawBackgroundColor(tdDesignLogin, -151587073);
	TextDrawBoxColor(tdDesignLogin, 1905000703);
	TextDrawUseBox(tdDesignLogin, 1);
	TextDrawSetProportional(tdDesignLogin, 1);
	TextDrawSetSelectable(tdDesignLogin, 0);

	tdDesignRegister = TextDrawCreate(321.000000, 253.000000, "_");
	TextDrawFont(tdDesignRegister, 1);
	TextDrawLetterSize(tdDesignRegister, 0.595833, -0.250000);
	TextDrawTextSize(tdDesignRegister, 308.000000, 48.000000);
	TextDrawSetOutline(tdDesignRegister, 1);
	TextDrawSetShadow(tdDesignRegister, 0);
	TextDrawAlignment(tdDesignRegister, 2);
	TextDrawColor(tdDesignRegister, -1);
	TextDrawBackgroundColor(tdDesignRegister, -151587073);
	TextDrawBoxColor(tdDesignRegister, 1905000703);
	TextDrawUseBox(tdDesignRegister, 1);
	TextDrawSetProportional(tdDesignRegister, 1);
	TextDrawSetSelectable(tdDesignRegister, 0);

	tdDesignPanel = TextDrawCreate(320.000000, 116.000000, "_");
	TextDrawFont(tdDesignPanel, 1);
	TextDrawLetterSize(tdDesignPanel, 0.600000, 0.000003);
	TextDrawTextSize(tdDesignPanel, 300.000000, 196.000000);
	TextDrawSetOutline(tdDesignPanel, 1);
	TextDrawSetShadow(tdDesignPanel, 0);
	TextDrawAlignment(tdDesignPanel, 2);
	TextDrawColor(tdDesignPanel, -1);
	TextDrawBackgroundColor(tdDesignPanel, 255);
	TextDrawBoxColor(tdDesignPanel, -357105409);
	TextDrawUseBox(tdDesignPanel, 1);
	TextDrawSetProportional(tdDesignPanel, 1);
	TextDrawSetSelectable(tdDesignPanel, 0);

	tdServerVersion = TextDrawCreate(248.000000, 289.000000, serverVersion);
	TextDrawFont(tdServerVersion, 1);
	TextDrawLetterSize(tdServerVersion, 0.200000, 1.000000);
	TextDrawTextSize(tdServerVersion, 391.000000, 20.500000);
	TextDrawSetOutline(tdServerVersion, 0);
	TextDrawSetShadow(tdServerVersion, 0);
	TextDrawAlignment(tdServerVersion, 1);
	TextDrawColor(tdServerVersion, 1433087999);
	TextDrawBackgroundColor(tdServerVersion, 255);
	TextDrawBoxColor(tdServerVersion, 50);
	TextDrawUseBox(tdServerVersion, 0);
	TextDrawSetProportional(tdServerVersion, 1);
	TextDrawSetSelectable(tdServerVersion, 0);

	tdVersionLabel = TextDrawCreate(234.000000, 289.000000, "Version:");
	TextDrawFont(tdVersionLabel, 1);
	TextDrawLetterSize(tdVersionLabel, 0.200000, 1.000000);
	TextDrawTextSize(tdVersionLabel, 391.000000, 20.500000);
	TextDrawSetOutline(tdVersionLabel, 0);
	TextDrawSetShadow(tdVersionLabel, 0);
	TextDrawAlignment(tdVersionLabel, 2);
	TextDrawColor(tdVersionLabel, 1296911871);
	TextDrawBackgroundColor(tdVersionLabel, 255);
	TextDrawBoxColor(tdVersionLabel, 50);
	TextDrawUseBox(tdVersionLabel, 0);
	TextDrawSetProportional(tdVersionLabel, 1);
	TextDrawSetSelectable(tdVersionLabel, 0);

	tdBuildLabel = TextDrawCreate(385.000000, 289.000000, "Build:");
	TextDrawFont(tdBuildLabel, 1);
	TextDrawLetterSize(tdBuildLabel, 0.200000, 1.000000);
	TextDrawTextSize(tdBuildLabel, 391.000000, 20.500000);
	TextDrawSetOutline(tdBuildLabel, 0);
	TextDrawSetShadow(tdBuildLabel, 0);
	TextDrawAlignment(tdBuildLabel, 2);
	TextDrawColor(tdBuildLabel, 1296911871);
	TextDrawBackgroundColor(tdBuildLabel, 255);
	TextDrawBoxColor(tdBuildLabel, 50);
	TextDrawUseBox(tdBuildLabel, 0);
	TextDrawSetProportional(tdBuildLabel, 1);
	TextDrawSetSelectable(tdBuildLabel, 0);

	tdBuildVersion = TextDrawCreate(395.000000, 289.000000, serverBuildnumber);
	TextDrawFont(tdBuildVersion, 1);
	TextDrawLetterSize(tdBuildVersion, 0.200000, 1.000000);
	TextDrawTextSize(tdBuildVersion, 391.000000, 20.500000);
	TextDrawSetOutline(tdBuildVersion, 0);
	TextDrawSetShadow(tdBuildVersion, 0);
	TextDrawAlignment(tdBuildVersion, 1);
	TextDrawColor(tdBuildVersion, 1433087999);
	TextDrawBackgroundColor(tdBuildVersion, 255);
	TextDrawBoxColor(tdBuildVersion, 50);
	TextDrawUseBox(tdBuildVersion, 0);
	TextDrawSetProportional(tdBuildVersion, 1);
	TextDrawSetSelectable(tdBuildVersion, 0);

	tdPanelTitle4 = TextDrawCreate(365.000000, 175.000000, "RPG");
	TextDrawFont(tdPanelTitle4, 2);
	TextDrawLetterSize(tdPanelTitle4, 0.125000, 0.750000);
	TextDrawTextSize(tdPanelTitle4, 400.000000, 17.000000);
	TextDrawSetOutline(tdPanelTitle4, 0);
	TextDrawSetShadow(tdPanelTitle4, 0);
	TextDrawAlignment(tdPanelTitle4, 2);
	TextDrawColor(tdPanelTitle4, -357105409);
	TextDrawBackgroundColor(tdPanelTitle4, -357105409);
	TextDrawBoxColor(tdPanelTitle4, 50);
	TextDrawUseBox(tdPanelTitle4, 0);
	TextDrawSetProportional(tdPanelTitle4, 1);
	TextDrawSetSelectable(tdPanelTitle4, 0);

	tdPanelTitle5 = TextDrawCreate(384.000000, 175.000000, "Trucker");
	TextDrawFont(tdPanelTitle5, 2);
	TextDrawLetterSize(tdPanelTitle5, 0.125000, 0.750000);
	TextDrawTextSize(tdPanelTitle5, 400.000000, 17.000000);
	TextDrawSetOutline(tdPanelTitle5, 0);
	TextDrawSetShadow(tdPanelTitle5, 0);
	TextDrawAlignment(tdPanelTitle5, 2);
	TextDrawColor(tdPanelTitle5, -357105409);
	TextDrawBackgroundColor(tdPanelTitle5, -357105409);
	TextDrawBoxColor(tdPanelTitle5, 50);
	TextDrawUseBox(tdPanelTitle5, 0);
	TextDrawSetProportional(tdPanelTitle5, 1);
	TextDrawSetSelectable(tdPanelTitle5, 0);

	tdPanelTitle1 = TextDrawCreate(270.000000, 145.000000, "Around");
	TextDrawFont(tdPanelTitle1, 3);
	TextDrawLetterSize(tdPanelTitle1, 0.499998, 3.499998);
	TextDrawTextSize(tdPanelTitle1, 0.000000, 0.000000);
	TextDrawSetOutline(tdPanelTitle1, 1);
	TextDrawSetShadow(tdPanelTitle1, 0);
	TextDrawAlignment(tdPanelTitle1, 2);
	TextDrawColor(tdPanelTitle1, 1433087999);
	TextDrawBackgroundColor(tdPanelTitle1, 0);
	TextDrawBoxColor(tdPanelTitle1, 50);
	TextDrawUseBox(tdPanelTitle1, 0);
	TextDrawSetProportional(tdPanelTitle1, 1);
	TextDrawSetSelectable(tdPanelTitle1, 0);

	tdPanelTitle2 = TextDrawCreate(321.000000, 145.000000, "The");
	TextDrawFont(tdPanelTitle2, 3);
	TextDrawLetterSize(tdPanelTitle2, 0.499998, 3.499998);
	TextDrawTextSize(tdPanelTitle2, 400.000000, 17.000000);
	TextDrawSetOutline(tdPanelTitle2, 1);
	TextDrawSetShadow(tdPanelTitle2, 0);
	TextDrawAlignment(tdPanelTitle2, 2);
	TextDrawColor(tdPanelTitle2, 1296911871);
	TextDrawBackgroundColor(tdPanelTitle2, 0);
	TextDrawBoxColor(tdPanelTitle2, 50);
	TextDrawUseBox(tdPanelTitle2, 0);
	TextDrawSetProportional(tdPanelTitle2, 1);
	TextDrawSetSelectable(tdPanelTitle2, 0);

	tdPanelTitle3 = TextDrawCreate(370.000000, 145.000000, "World");
	TextDrawFont(tdPanelTitle3, 3);
	TextDrawLetterSize(tdPanelTitle3, 0.499998, 3.499998);
	TextDrawTextSize(tdPanelTitle3, 400.000000, 17.000000);
	TextDrawSetOutline(tdPanelTitle3, 1);
	TextDrawSetShadow(tdPanelTitle3, 0);
	TextDrawAlignment(tdPanelTitle3, 2);
	TextDrawColor(tdPanelTitle3, 1433087999);
	TextDrawBackgroundColor(tdPanelTitle3, 0);
	TextDrawBoxColor(tdPanelTitle3, 50);
	TextDrawUseBox(tdPanelTitle3, 0);
	TextDrawSetProportional(tdPanelTitle3, 1);
	TextDrawSetSelectable(tdPanelTitle3, 0);

	tdBtnExit = TextDrawCreate(411.000000, 120.000000, "x");
	TextDrawFont(tdBtnExit, 2);
	TextDrawLetterSize(tdBtnExit, 0.149994, 0.800000);
	TextDrawTextSize(tdBtnExit, 8.000000, 8.000000);
	TextDrawSetOutline(tdBtnExit, 1);
	TextDrawSetShadow(tdBtnExit, 0);
	TextDrawAlignment(tdBtnExit, 2);
	TextDrawColor(tdBtnExit, -741092408);
	TextDrawBackgroundColor(tdBtnExit, 255);
	TextDrawBoxColor(tdBtnExit, -1);
	TextDrawUseBox(tdBtnExit, 0);
	TextDrawSetProportional(tdBtnExit, 1);
	TextDrawSetSelectable(tdBtnExit, 1);

	return 1;
}