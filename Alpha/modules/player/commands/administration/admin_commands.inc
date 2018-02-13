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