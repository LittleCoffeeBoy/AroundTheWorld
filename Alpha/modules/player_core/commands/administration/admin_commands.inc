cmd:createroute(playerid, params[])
{
	if (strlen(params) != 0)
	{
		SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Usage: /createroute");
		return 0;
	}

	/*
	-* Steps to create a route of the server:
	-* 1. Define a truck for the delivery.
	-* 2. Check if the delivery needs a trailer, if it needs, define it. Otherwise, just proceed.
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