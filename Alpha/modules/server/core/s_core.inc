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

// SetDO: SetDefaultOptions
public SetDO_OnGameModeInit()
{
	SetGameModeText("[RPG] Trucker");
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
	ShowNameTags(1);
	EnableStuntBonusForAll(0);
	UsePlayerPedAnims();

	return 1;
}