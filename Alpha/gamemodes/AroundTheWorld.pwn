/* --- Native Includes --- */
#include <natives/a_samp>
#include <natives/crashdetect>
#include <natives/Pawn.CMD>
#include <natives/sscanf2>
#include <natives/bcrypt>
#include <natives/fixes2>
/*
enum(<<=1)
{
	cmdMod = 1,
	cmdAdmin,
	cmdOwner
};

flags:createroute(cmdOwner);
*/
/* --------- Core Modules --------- */
#include <server/core/s_core>
#include <player/core/p_core>

#if defined MAX_PLAYERS
	#undef MAX_PLAYERS
#endif

#define MAX_PLAYERS 5

main()
{
}

public OnGameModeInit()
{
	// Hook (1)
	// Opening the player database.
	#if defined OPDB_OnGameModeInit
		OPDB_OnGameModeInit();
	#endif

	// Hook (2)
	// Opening the routes database.
	#if defined OSDB_OnGameModeInit
		OSDB_OnGameModeInit();
	#endif

	// Hook (3)
	// Setting up the defaults options.
	#if defined SetDO_OnGameModeInit
		SetDO_OnGameModeInit();
	#endif

	// Hook (4)
	// Adding player class.
	#if defined AddPC_OnGameModeInit
		AddPC_OnGameModeInit();
	#endif

	// Hook (5)
	// Creating vehicles.
	#if defined CV_OnGameModeInit
		CV_OnGameModeInit();
	#endif

	// Hook (6)
	// Creating objects.
	#if defined CO_OnGameModeInit
		CO_OnGameModeInit();
	#endif

	// Hook (7)
	// Adding 3d text labels.
	#if defined Add3DL_OnGameModeInit
		Add3DL_OnGameModeInit();
	#endif

	// Hook (8)
	// Setting up the login panel.
	#if defined SetOTD_OnGameModeInit
		SetOTD_OnGameModeInit();
	#endif

	return 1;
}

//------------------------------
// Hooking: OPDB_OnGameModeInit
// Hook (1)
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit OPDB_OnGameModeInit

#if defined OPDB_OnGameModeInit
	forward OPDB_OnGameModeInit();
#endif
//------------------------------

//------------------------------
// Hooking: OSDB_OnGameModeInit
// Hook: (2)
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit OSDB_OnGameModeInit

#if defined OSDB_OnGameModeInit
	forward OSDB_OnGameModeInit();
#endif
//------------------------------

//------------------------------
// Hooking: SetDO_OnGameModeInit
// Hook (3)
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit SetDO_OnGameModeInit

#if defined SetDO_OnGameModeInit
	forward SetDO_OnGameModeInit();
#endif
//------------------------------

//------------------------------
// Hooking: AddPC_OnGameModeInit
// Hook (4)
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit AddPC_OnGameModeInit

#if defined AddPC_OnGameModeInit
	forward AddPC_OnGameModeInit();
#endif
//------------------------------

//------------------------------
// Hooking: CV_OnGameModeInit
// Hook (5)
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit CV_OnGameModeInit

#if defined CV_OnGameModeInit
	forward CV_OnGameModeInit();
#endif
//------------------------------

//------------------------------
// Hooking: CO_OnGameModeInit
// Hook (6)
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit CO_OnGameModeInit

#if defined CO_OnGameModeInit
	forward CO_OnGameModeInit();
#endif
//------------------------------

//------------------------------
// Hooking: Add3DL_OnGameModeInit
// Hook (7)
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit Add3DL_OnGameModeInit

#if defined Add3DL_OnGameModeInit
	forward Add3DL_OnGameModeInit();
#endif
//------------------------------

//------------------------------
// Hooking: SetOTD_OnGameModeInit
// Hook (8)
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit SetOTD_OnGameModeInit

#if defined SetOTD_OnGameModeInit
	forward SetOTD_OnGameModeInit();
#endif
//------------------------------

public OnGameModeExit()
{
	// Hook (1)
	// Closing the player database.
	#if defined CPDB_OnGameModeExit
		CPDB_OnGameModeExit();
	#endif

	// Hook (2)
	// Closing the routes database.
	#if defined CSDB_OnGameModeExit
		CSDB_OnGameModeExit();
	#endif

	return 1;
}

//------------------------------
// Hooking: CPDB_OnGameModeExit
// Hook (1)
#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif

#define OnGameModeExit CPDB_OnGameModeExit

#if defined CPDB_OnGameModeExit
	forward CPDB_OnGameModeExit();
#endif
//------------------------------

//------------------------------
// Hooking: CSDB_OnGameModeExit
// Hook (2)
#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif

#define OnGameModeExit CSDB_OnGameModeExit

#if defined CSDB_OnGameModeExit
	forward CSDB_OnGameModeExit();
#endif
//------------------------------

public OnPlayerConnect(playerid)
{
	// Hook (1)
	// Remove bulding for player.
	#if defined RBFP_OnPlayerConnect
		RBFP_OnPlayerConnect(playerid);
	#endif

	// Hook (2)
	// Define join camera.
	#if defined DJC_OnPlayerConnect
		DJC_OnPlayerConnect(playerid);
	#endif

	// Hook (3)
	// Verify player information.
	#if defined VPI_OnPlayerConnect
		VPI_OnPlayerConnect(playerid);
	#endif

	return 1;
}

//------------------------------
// Hooking: RBFP_OnPlayerConnect
// Hook (1)
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect RBFP_OnPlayerConnect

#if defined RBFP_OnPlayerConnect
	forward RBFP_OnPlayerConnect(playerid);
#endif
//------------------------------

//------------------------------
// Hooking: DJC_OnPlayerConnect
// Hook (2)
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect DJC_OnPlayerConnect

#if defined DJC_OnPlayerConnect
	forward DJC_OnPlayerConnect(playerid);
#endif
//------------------------------

//------------------------------
// Hooking: VPI_OnPlayerConnect
// Hook (3)
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect VPI_OnPlayerConnect

#if defined VPI_OnPlayerConnect
	forward VPI_OnPlayerConnect(playerid);
#endif
//------------------------------

public OnPlayerDisconnect(playerid, reason)
{
	#if defined SPI_OnPlayerDisconnect
		SPI_OnPlayerDisconnect(playerid, reason);
	#endif

	return 1;
}

//------------------------------
// Hooking: SPI_OnPlayerDisconnect
// Hook (1)
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect SPI_OnPlayerDisconnect

#if defined SPI_OnPlayerDisconnect
	forward SPI_OnPlayerDisconnect(playerid, reason);
#endif
//------------------------------

public OnPlayerRequestClass(playerid, classid)
{
	SetPlayerCameraPos(playerid, 2853.5950, 939.4451, 13.7023);
	SetPlayerCameraLookAt(playerid, 2853.6677, 945.5969, 10.7500);
	SetPlayerPos(playerid, 2853.6677, 945.5969, 10.7500);
	SetPlayerFacingAngle(playerid, 182.1559);

	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch (dialogid)
	{
		case rulesDialog:
		{
			if ((response == 1) && (GetTickCount() - readingTimer[playerid] <= TIME_TO_READ_RULES) || (response == 0) && (GetTickCount() - readingTimer[playerid] <= TIME_TO_READ_RULES))
			{
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

				if (readingTolerance[playerid] == 0)
				{
					SendClientMessage(playerid, HEX_TOMORROW_YELLOW, "[Server » You] Please, take a moment to read the rules.");
					readingTolerance[playerid]++;
				}

				return 1;
			}

			if ((response == 0) && (GetTickCount() - readingTimer[playerid] > TIME_TO_READ_RULES))
			{
				SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] We apologize for kicking you off the server, but you need to read and accept the rules to play with us.");
				SetTimerEx("KickThePlayer", 1000, false, "i", playerid);
				return 1;
			}

			player[playerid][acceptedRules] = true;
			SendClientMessage(playerid, HEX_TOMORROW_GREEN, "[Server » You] Thank you for accept our rules.");

			new dbQuery[85];
			format(dbQuery, sizeof(dbQuery), "INSERT INTO players (pName, acceptedRules) VALUES ('%q', %i)", player[playerid][pName], (player[playerid][acceptedRules] == true) ? 1 : 0);
			db_query(pdbConnection, dbQuery);

			readingTimer[playerid] = 0;
			readingTolerance[playerid] = 0;

			//ShowPlayerDialog(playerid, registerDialog, DIALOG_STYLE_PASSWORD, ""TOMORROW_GREEN"User registration.", ""TOMORROW_ORANGE"Please, register a strong pass for your account. (6 - 25 Chars)", "Done", "Cancel");
			
			hasTextdrawOpened[playerid] = true;
			ShowOpeningTDPanel(playerid);

			return 1;
		}

		case registerDialog:
		{
			if (!response)
			{
				if (readingTolerance[playerid] == 0)
				{
					SendClientMessage(playerid, HEX_TOMORROW_YELLOW, "[Server » You] It's okay, you can register your pass later.");
					SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] But remember, your name and agreement with the rules will be remembered and not reserved.");

					readingTolerance[playerid]++;
				}

				//SetTimerEx("KickThePlayer", 1000, false, "i", playerid);
				
				hasTextdrawOpened[playerid] = true;
				ShowOpeningTDPanel(playerid);
				
				return 1;
			}

			if ((strlen(inputtext) < 6) || strlen(inputtext) > 25)
			{
				if (readingTolerance[playerid] <= 1)
				{
					SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] The pass length should be between 6 and 25 characters.");
					readingTolerance[playerid]++;
				}

				ShowPlayerDialog(playerid, registerDialog, DIALOG_STYLE_PASSWORD, ""TOMORROW_GREEN"User registration.", ""TOMORROW_ORANGE"Please, register a strong pass for your account. (6 - 25 Chars)", "Done", "Cancel");
				
				return 1;
			}

			readingTolerance[playerid] = 0;

			bcrypt_hash(inputtext, BCRYPT_COST, "OnPassIsHashed", "i", playerid);
			
			return 1;
		}

		case genderDialog:
		{
			if (!response)
			{
				if (readingTolerance[playerid] == 0)
				{
					SendClientMessage(playerid, HEX_TOMORROW_YELLOW, "[Server » You] You need to select your gender to play in our server.");
					readingTolerance[playerid]++;
				}
				
				ShowPlayerDialog(playerid, genderDialog, DIALOG_STYLE_LIST, ""TOMORROW_ORANGE"Select your gender.", ""DRACULA_PINK"Female\n"DRACULA_CYAN"Male\n"TOMORROW_WHITE"Other", "Select", "");
				
				return 1;
			}

			switch (listitem)
			{
				case 0:
				{
					format(player[playerid][gender], 7, "Female");
					format(player[playerid][genderColor], 9, DRACULA_PINK);
				}

				case 1:
				{
					format(player[playerid][gender], 7, "Male");
					format(player[playerid][genderColor], 9, DRACULA_CYAN);
				}

				case 2:
				{
					new randNumber = random(2-0)+0; //random(max-min)+min;

					format(player[playerid][gender], 7, "Other");
					format(player[playerid][genderColor], 9, (randNumber == 1) ? DRACULA_CYAN : DRACULA_PINK);

					SendClientMessage(playerid, HEX_TOMORROW_YELLOW, "As you're of other gender, you can change only one time your name color via cmd: \"/changenamecolor\" or \"/changenamecolor <pink/blue>\".");
				}
			}

			new dbQuery[89];
			format(dbQuery, sizeof(dbQuery), "UPDATE players SET gender = '%s', genderColor = '%s' WHERE dbid = %i", player[playerid][gender], player[playerid][genderColor], player[playerid][dbid]);
			db_query(pdbConnection, dbQuery);

			readingTolerance[playerid] = 0;

			//CancelSelectTextDraw(playerid);
			ShowPlayerDialog(playerid, loginDialog, DIALOG_STYLE_PASSWORD, ""TOMORROW_GREEN"Login area.", ""TOMORROW_YELLOW"It looks like you're already a registered member, enter your account password to login.", "Login", "Cancel");
			
			//hasTextdrawOpened[playerid] = true;
			//ShowOpeningTDPanel(playerid);
			

			return 1;
		}

		case loginDialog:
		{
			if (!response)
			{
				//SendClientMessage(playerid, HEX_TOMORROW_YELLOW, "[Server » You] We hope to see you soon. Bye! =)");
				//SetTimerEx("KickThePlayer", 1000, false, "i", playerid);
				
				hasTextdrawOpened[playerid] = true;
				ShowOpeningTDPanel(playerid);
				
				return 1;
			}
			
			//CancelSelectTextDraw(playerid);
			bcrypt_check(inputtext, player[playerid][pass], "OnPassChecked", "i", playerid);

			return 1;
		}

		// CMD: createroute
		case createRoute0:
		{
			if (!response)
			{
				SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Creation of a new route to the server has been canceled.");
				
				return 1;
			}

			// Everytime that I try create a new server route, make the RouteBuffer empty to not use old data.
			new emptyRouteBuffer[CreateRouteBuffer];
			RouteBuffer = emptyRouteBuffer;

			ShowPlayerDialog(playerid, createRoute1, DIALOG_STYLE_INPUT, "New server route (1/11).", "Define the id of a truck for the delivery (e.g., 403 = \"Linerunner\").", "Continue", "Cancel");
			
			return 1;
		}

		// Define a truck for the deliver.
		case createRoute1:
		{
			if (!response)
			{
				// When cancel the creation of a create a new server route, make the RouteBuffer empty again.
				new emptyRouteBuffer[CreateRouteBuffer];
				RouteBuffer = emptyRouteBuffer;

				SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Creation of a new route to the server has been canceled (dialog 1/11).");

				return 1;
			}

			if (isnull(inputtext))
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid input. Please try again!");

				ShowPlayerDialog(playerid, createRoute1, DIALOG_STYLE_INPUT, "New server route (1/11).", "Define the id of a truck for the delivery (e.g., 403 = \"Linerunner\").", "Continue", "Cancel");
				
				return 1;
			}

			new truckForNewRoute = strval(inputtext);

			if (truckForNewRoute == 0)
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid truck id, try again.");
				
				ShowPlayerDialog(playerid, createRoute1, DIALOG_STYLE_INPUT, "New server route (1/11).", "Define the id of a truck for the delivery (e.g., 403 = \"Linerunner\").", "Continue", "Cancel");

				return 1;
			}

			new bool:match;
			for (new i = 0; i < sizeof(sTrucks); i++)
			{
				new test[128];
				format(test, sizeof(test), "listOfTrucks[%i] (%i is equal to %i = [%b]).", i, sTrucks[i], truckForNewRoute, (sTrucks[i] == truckForNewRoute));
				SendClientMessage(playerid, -1, test);
				
				if (sTrucks[i] == truckForNewRoute)
				{
					match = true;
					break;
				}
			}

			if (!match)
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid truck id, try again.");
				
				ShowPlayerDialog(playerid, createRoute1, DIALOG_STYLE_INPUT, "New server route (1/11).", "Define the id of a truck for the delivery (e.g., 403 = \"Linerunner\").", "Continue", "Cancel");
				
				return 1;
			}

			RouteBuffer[rTruck] = truckForNewRoute;

			// Debug:
			new msgDebug[128];
			format(msgDebug, sizeof(msgDebug), "[Server » You] Truck (id %i) defined (dialog 1/11).", RouteBuffer[rTruck]);
			SendClientMessage(playerid, HEX_TOMORROW_YELLOW, msgDebug);

			ShowPlayerDialog(playerid, createRoute2, DIALOG_STYLE_MSGBOX, "New server route (2/11).", "This delivery has a trailer to attach in the truck?", "Yes", "No");

			return 1;
		}

		// Check if the truck needs a trailer, if it needs, define it. If it's not, just proceed.
		case createRoute2:
		{
			if (response)
			{
				ShowPlayerDialog(playerid, createRoute3, DIALOG_STYLE_INPUT, "New server route (3/11).", "Define the id of a trailer for attach in the truck (e.g., 435 = \"Article Trailer\").", "Continue", "Cancel");
			}
			else
			{
				RouteBuffer[rTrailer] = 0;

				SendClientMessage(playerid, HEX_TOMORROW_YELLOW, "[Server » You] No need for a trailer (dialog 2/11), jumping to dialog 4/11.");

				ShowPlayerDialog(playerid, createRoute4, DIALOG_STYLE_INPUT, "New server route (4/11).", "Define the average delivery time (e.g., \"02 Minutes and 54 Seconds\").", "Continue", "Cancel");
			}

			return 1;
		}

		// Defining a trailer to the truck.
		case createRoute3:
		{
			if (!response)
			{
				// When cancel the creation of a create a new server route, make the RouteBuffer empty again.
				new emptyRouteBuffer[CreateRouteBuffer];
				RouteBuffer = emptyRouteBuffer;

				SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Creation of a new route to the server has been canceled (dialog 3/11).");
				
				return 1;
			}

			new trailerForNewRoute = strval(inputtext);

			if (trailerForNewRoute == 0)
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid trailer id, try again.");
				
				ShowPlayerDialog(playerid, createRoute3, DIALOG_STYLE_INPUT, "New server route (3/11).", "Define the id of a trailer for attach in the truck (e.g., 435 = \"Article Trailer\").", "Continue", "Cancel");

				return 1;
			}

			new bool:match;
			for (new i = 0; i < sizeof(sTrailers); i++)
			{
				new test[128];
				format(test, sizeof(test), "listOfTrailers[%i] (%i is equal to %i = [%b]).", i, sTrailers[i], trailerForNewRoute, (sTrailers[i] == trailerForNewRoute));
				SendClientMessage(playerid, -1, test);
				
				if (sTrailers[i] == trailerForNewRoute)
				{
					match = true;
					break;
				}
			}

			if (!match)
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid truck id, try again.");
				
				ShowPlayerDialog(playerid, createRoute1, DIALOG_STYLE_INPUT, "New server route (1/11).", "Define the id of a truck for the delivery (e.g., 403 = \"Linerunner\").", "Continue", "Cancel");
				
				return 1;
			}

			RouteBuffer[rTrailer] = trailerForNewRoute;

			// Debug:
			new msgDebug[128];
			format(msgDebug, sizeof(msgDebug), "[Server » You] Trailer (id %i) defined (dialog 3/11).", RouteBuffer[rTrailer]);
			SendClientMessage(playerid, HEX_TOMORROW_YELLOW, msgDebug);

			ShowPlayerDialog(playerid, createRoute4, DIALOG_STYLE_INPUT, "New server route (4/11).", "Define the average delivery time (e.g., \"02 Minutes and 54 Seconds\").", "Continue", "Cancel");

			return 1;
		}

		// Define the average delivery time.
		case createRoute4:
		{
			if (!response)
			{
				// When cancel the creation of a create a new server route, make the RouteBuffer empty again.
				new emptyRouteBuffer[CreateRouteBuffer];
				RouteBuffer = emptyRouteBuffer;

				SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Creation of a new route to the server has been canceled (dialog 4/11).");
				
				return 1;
			}

			if (isnull(inputtext))
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid input. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute4, DIALOG_STYLE_INPUT, "New server route (4/11).", "Define the average delivery time (e.g., \"02 Minutes and 54 Seconds\").", "Continue", "Cancel");

				return 1;
			}

			if (strlen(inputtext) < 7 || strlen(inputtext) > 36)
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] The input needs to be between 7 - 37 characters. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute4, DIALOG_STYLE_INPUT, "New server route (4/11).", "Define the average delivery time (e.g., \"02 Minutes and 54 Seconds\").", "Continue", "Cancel");

				return 1;
			}

			format(RouteBuffer[rAverageDeliveryTime], 36, inputtext);

			// Debug:
			new msgDebug[128];
			format(msgDebug, sizeof(msgDebug), "[Server » You] Average delivery time defined (%s) (dialog 4/11).", RouteBuffer[rAverageDeliveryTime]);
			SendClientMessage(playerid, HEX_TOMORROW_YELLOW, msgDebug);

			ShowPlayerDialog(playerid, createRoute5, DIALOG_STYLE_INPUT, "New server route (5/11).", "Define what will be delivered (e.g., \"Cardboard boxes\").", "Continue", "Cancel");

			return 1;
		}

		// Define what will be delivered.
		case createRoute5:
		{
			if (!response)
			{
				// When cancel the creation of a create a new server route, make the RouteBuffer empty again.
				new emptyRouteBuffer[CreateRouteBuffer];
				RouteBuffer = emptyRouteBuffer;

				SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Creation of a new route to the server has been canceled (dialog 5/11).");
				
				return 1;
			}

			if (isnull(inputtext))
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid input. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute5, DIALOG_STYLE_INPUT, "New server route (5/11).", "Define what will be delivered (e.g., \"Cardboard boxes\").", "Continue", "Cancel");

				return 1;
			}

			if (strlen(inputtext) < 3 || strlen(inputtext) > 20)
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] The input needs to be between 3 - 20 characters. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute5, DIALOG_STYLE_INPUT, "New server route (5/11).", "Define what will be delivered (e.g., \"Cardboard boxes\").", "Continue", "Cancel");

				return 1;
			}

			format(RouteBuffer[rWhatWillBeDelivered], 20, inputtext);

			// Debug:
			new msgDebug[128];
			format(msgDebug, sizeof(msgDebug), "[Server » You] Defined what will be delivered (%s) (dialog 5/11).", RouteBuffer[rWhatWillBeDelivered]);
			SendClientMessage(playerid, HEX_TOMORROW_YELLOW, msgDebug);

			ShowPlayerDialog(playerid, createRoute6, DIALOG_STYLE_INPUT, "New server route (6/11).", "Set the load value that will be sended to the server global bank (e.g., 1280).", "Continue", "Cancel");

			return 1;
		}

		// Set the load value that will be sended to the server global bank. (The reward in cash is the load value / 3.325)
		case createRoute6:
		{
			if (!response)
			{
				// When cancel the creation of a create a new server route, make the RouteBuffer empty again.
				new emptyRouteBuffer[CreateRouteBuffer];
				RouteBuffer = emptyRouteBuffer;

				SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Creation of a new route to the server has been canceled (dialog 6/11).");
				
				return 1;
			}

			new valueForNewRoute;

			if ((valueForNewRoute = strval(inputtext)) == 0)
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid value, try again.");
				
				ShowPlayerDialog(playerid, createRoute6, DIALOG_STYLE_INPUT, "New server route (6/11).", "Set the load value that will be sended to the server global bank (e.g., 1280).", "Continue", "Cancel");

				return 1;
			}

			if (sscanf(inputtext, "i", valueForNewRoute))
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid value, try again.");
				
				ShowPlayerDialog(playerid, createRoute6, DIALOG_STYLE_INPUT, "New server route (6/11).", "Set the load value that will be sended to the server global bank (e.g., 1280).", "Continue", "Cancel");

				return 1;
			}

			if (strlen(inputtext) < 1 || strlen(inputtext) > 8)
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] The input needs to be between 1 - 8 numbers. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute6, DIALOG_STYLE_INPUT, "New server route (6/11).", "Set the load value that will be sended to the server global bank (e.g., 1280).", "Continue", "Cancel");

				return 1;
			}

			RouteBuffer[rLoadValue] = valueForNewRoute;

			// Debug:
			new msgDebug[128];
			format(msgDebug, sizeof(msgDebug), "[Server » You] Load value (%i) (dialog 6/11).", RouteBuffer[rLoadValue]);
			SendClientMessage(playerid, HEX_TOMORROW_YELLOW, msgDebug);

			ShowPlayerDialog(playerid, createRoute7, DIALOG_STYLE_LIST, "New server route (7/11) (Select the type of load.).", "Light Load\n\
			Normal Load\n\
			Heavy Load\n\
			Super Heavy Load\n\
			Light And Fragile Load\n\
			Normal And Fragile Load\n\
			Heavy And Fragile Load\n\
			Super Heavy And Fragile Load", "Select", "Cancel");

			return 1;
		}

		// Define the type of load through enums.
		case createRoute7:
		{
			if (!response)
			{
				// When cancel the creation of a create a new server route, make the RouteBuffer empty again.
				new emptyRouteBuffer[CreateRouteBuffer];
				RouteBuffer = emptyRouteBuffer;

				SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Creation of a new route to the server has been canceled (dialog 7/11).");
				
				return 1;
			}
			
			switch (listitem)
			{
				case 0: // lightLoad
				{
					RouteBuffer[rLoadType] = lightLoad;
				}

				case 1: // normalLoad
				{
					RouteBuffer[rLoadType] = normalLoad;
				}

				case 2: // heavyLoad
				{
					RouteBuffer[rLoadType] = heavyLoad;
				}

				case 3: // superHeavyLoad
				{
					RouteBuffer[rLoadType] = superHeavyLoad;
				}

				case 4: // lightAndFragileLoad
				{
					RouteBuffer[rLoadType] = lightAndFragileLoad;
				}

				case 5: // normalAndFragileLoad
				{
					RouteBuffer[rLoadType] = normalAndFragileLoad;
				}

				case 6: // heavyAndFragileLoad
				{
					RouteBuffer[rLoadType] = heavyAndFragileLoad;
				}

				case 7: // superHeavyAndFragileLoad
				{
					RouteBuffer[rLoadType] = superHeavyAndFragileLoad;
				}

				default:
				{
					RouteBuffer[rLoadType] = normalLoad;
				}
			}

			// Debug:
			new msgDebug[128];
			format(msgDebug, sizeof(msgDebug), "[Server » You] Load type defined (%i) (dialog 7/11).", RouteBuffer[rLoadType]);
			SendClientMessage(playerid, HEX_TOMORROW_YELLOW, msgDebug);

			ShowPlayerDialog(playerid, createRoute8, DIALOG_STYLE_INPUT, "New server route (8/11).", "Define the name of the place of departure (e.g., \"Global Bank (LV)\").", "Continue", "Cancel");

			return 1;
		}

		// Define the name of the place of departure.
		case createRoute8:
		{
			if (!response)
			{
				// When cancel the creation of a create a new server route, make the RouteBuffer empty again.
				new emptyRouteBuffer[CreateRouteBuffer];
				RouteBuffer = emptyRouteBuffer;

				SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Creation of a new route to the server has been canceled (dialog 8/11).");
				
				return 1;
			}

			if (isnull(inputtext))
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid input. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute8, DIALOG_STYLE_INPUT, "New server route (8/11).", "Define the name of the place of departure (e.g., \"Global Bank (LV)\").", "Continue", "Cancel");

				return 1;
			}

			if (strlen(inputtext) < 4 || strlen(inputtext) > 30)
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] The input needs to be between 4 - 30 characters. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute8, DIALOG_STYLE_INPUT, "New server route (8/11).", "Define the name of the place of departure (e.g., \"Global Bank (LV)\").", "Continue", "Cancel");

				return 1;
			}

			format(RouteBuffer[rFrom], 30, inputtext);

			// Debug:
			new msgDebug[128];
			format(msgDebug, sizeof(msgDebug), "[Server » You] Name of the place of departure defined (%s) (dialog 8/11).", RouteBuffer[rFrom]);
			SendClientMessage(playerid, HEX_TOMORROW_YELLOW, msgDebug);

			ShowPlayerDialog(playerid, createRoute9, DIALOG_STYLE_INPUT, "New server route (9/11).", "Define the positions for the place of departure (e.g., 1.0,-1.0,1.0).", "Continue", "Cancel");

			return 1;
		}

		// Define the positions for the place of departure.
		case createRoute9:
		{
			if (!response)
			{
				// When cancel the creation of a create a new server route, make the RouteBuffer empty again.
				new emptyRouteBuffer[CreateRouteBuffer];
				RouteBuffer = emptyRouteBuffer;

				SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Creation of a new route to the server has been canceled (dialog 9/11).");
				
				return 1;
			}

			if (isnull(inputtext))
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid input. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute9, DIALOG_STYLE_INPUT, "New server route (9/11).", "Define the positions for the place of departure (e.g., 1.0,-1.0,1.0).", "Continue", "Cancel");

				return 1;
			}

			new Float:newRoutePosFromX, Float:newRoutePosFromY, Float:newRoutePosFromZ;
			
			if (sscanf(inputtext, "P<,>fff", newRoutePosFromX, newRoutePosFromY, newRoutePosFromZ))
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid input. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute9, DIALOG_STYLE_INPUT, "New server route (9/11).", "Define the positions for the place of departure (e.g., 1.0,-1.0,1.0).", "Continue", "Cancel");

				return 1;
			}

			RouteBuffer[rPosFromX] = newRoutePosFromX;
			RouteBuffer[rPosFromY] = newRoutePosFromY;
			RouteBuffer[rPosFromZ] = newRoutePosFromZ;

			// Debug:
			new msgDebug[128];
			format(msgDebug, sizeof(msgDebug), "Positions for the place of departure defined (%f, %f, %f) (dialog 9/11).", RouteBuffer[rPosFromX], RouteBuffer[rPosFromY], RouteBuffer[rPosFromZ]);
			SendClientMessage(playerid, HEX_TOMORROW_YELLOW, msgDebug);

			ShowPlayerDialog(playerid, createRoute10, DIALOG_STYLE_INPUT, "New server route (10/11).", "Define the name of the delivery place (e.g., \"Hunter Quarry (LV)\").", "Continue", "Cancel");

			return 1;
		}

		// Define the name of the delivery place.
		case createRoute10:
		{
			if (!response)
			{
				// When cancel the creation of a create a new server route, make the RouteBuffer empty again.
				new emptyRouteBuffer[CreateRouteBuffer];
				RouteBuffer = emptyRouteBuffer;

				SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Creation of a new route to the server has been canceled (dialog 10/11).");
				
				return 1;
			}

			if (isnull(inputtext))
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid input. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute10, DIALOG_STYLE_INPUT, "New server route (10/11).", "Define the name of the delivery place (e.g., \"Hunter Quarry (LV)\").", "Continue", "Cancel");

				return 1;
			}

			if (strlen(inputtext) < 4 || strlen(inputtext) > 30)
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] The input needs to be between 4 - 30 characters. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute10, DIALOG_STYLE_INPUT, "New server route (10/11).", "Define the name of the delivery place (e.g., \"Hunter Quarry (LV)\").", "Continue", "Cancel");

				return 1;
			}

			format(RouteBuffer[rTo], 30, inputtext);

			// Debug:
			new msgDebug[128];
			format(msgDebug, sizeof(msgDebug), "[Server » You] Name of the delivery place defined (%s) (dialog 10/11).", RouteBuffer[rTo]);
			SendClientMessage(playerid, HEX_TOMORROW_YELLOW, msgDebug);

			ShowPlayerDialog(playerid, createRoute11, DIALOG_STYLE_INPUT, "New server route (11/11).", "Define the positions for the delivery place (e.g., -1.0,1.0,-1.0).", "Continue", "Cancel");

			return 1;
		}

		// Define the positions for the delivery place.
		case createRoute11:
		{
			if (!response)
			{
				// When cancel the creation of a create a new server route, make the RouteBuffer empty again.
				new emptyRouteBuffer[CreateRouteBuffer];
				RouteBuffer = emptyRouteBuffer;

				SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Creation of a new route to the server has been canceled (dialog 11/11).");
				
				return 1;
			}

			if (isnull(inputtext))
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid input. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute11, DIALOG_STYLE_INPUT, "New server route (11/11).", "Define the positions for the delivery place (e.g., -1.0,1.0,-1.0).", "Continue", "Cancel");

				return 1;
			}

			new Float:newRoutePosToX, Float:newRoutePosToY, Float:newRoutePosToZ;
			
			if (sscanf(inputtext, "P<,>fff", newRoutePosToX, newRoutePosToY, newRoutePosToZ))
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] Invalid input. Please try again!");
				
				ShowPlayerDialog(playerid, createRoute11, DIALOG_STYLE_INPUT, "New server route (11/11).", "Define the positions for the delivery place (e.g., -1.0,1.0,-1.0).", "Continue", "Cancel");

				return 1;
			}

			RouteBuffer[rPosToX] = newRoutePosToX;
			RouteBuffer[rPosToY] = newRoutePosToY;
			RouteBuffer[rPosToZ] = newRoutePosToZ;

			// Debug:
			new msgDebug[128];
			format(msgDebug, sizeof(msgDebug), "Positions for the delivery place defined (%f, %f, %f) (dialog 11/11).", RouteBuffer[rPosToX], RouteBuffer[rPosToY], RouteBuffer[rPosToZ]);
			SendClientMessage(playerid, HEX_TOMORROW_YELLOW, msgDebug);

			RouteBuffer[rRewardCash] = floatround(RouteBuffer[rLoadValue] / 3.325, floatround_ceil);

			format(msgDebug, sizeof(msgDebug), "Reward in cash calculated (%i) (dialog 11/11).", RouteBuffer[rRewardCash]);
			SendClientMessage(playerid, HEX_TOMORROW_YELLOW, msgDebug);

			CreateRoute(playerid, RouteBuffer[rTruck], RouteBuffer[rTrailer], RouteBuffer[rAverageDeliveryTime], "Around the World", "End", RouteBuffer[rWhatWillBeDelivered], RouteBuffer[rLoadValue], RouteBuffer[rLoadType], RouteBuffer[rFrom], RouteBuffer[rPosFromX], RouteBuffer[rPosFromY], RouteBuffer[rPosFromZ], RouteBuffer[rTo], RouteBuffer[rPosToX], RouteBuffer[rPosToY], RouteBuffer[rPosToZ], RouteBuffer[rRewardCash]);

			return 1;
		}

		case routesDialog:
		{
			return 1;
		}

		default: return 0;
	}

	return 0;
}

public OnPlayerSpawn(playerid)
{
	player[playerid][isChatLocked] = false;
	SendClientMessage(playerid, HEX_TOMORROW_GREEN, "[Server » You] Chat enabled.");
	
	return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if (_:clickedid != INVALID_TEXT_DRAW)
	{
		if(clickedid == tdBtnLogin)
		{
			hasTextdrawOpened[playerid] = false;
			CloseOpeningTDPanel(playerid);

			new dbQuery[71], DBResult:dbResult;
			format(dbQuery, sizeof(dbQuery), "SELECT * FROM players WHERE pName = '%q' LIMIT 1", player[playerid][pName]);
			dbResult = db_query(pdbConnection, dbQuery);

			if (db_num_rows(dbResult) == 1)
			{
				player[playerid][dbid] = db_get_field_assoc_int(dbResult, "dbid");
				db_get_field_assoc(dbResult, "pass", player[playerid][pass], 61);
				db_get_field_assoc(dbResult, "gender", player[playerid][gender], 7);

				if (strlen(player[playerid][pass]) == 0)
				{
					ShowPlayerDialog(playerid, registerDialog, DIALOG_STYLE_PASSWORD, ""TOMORROW_GREEN"User registration.", ""TOMORROW_ORANGE"Please, register a strong pass for your account. (6 - 25 Chars)", "Done", "Cancel");
					//SetTimerEx("ShowPlayerDialog", 100, false "iiissss", playerid, registerDialog, DIALOG_STYLE_PASSWORD, ""TOMORROW_GREEN"User registration.", ""TOMORROW_ORANGE"Please, register a strong pass for your account. (6 - 25 Chars)", "Done", "Cancel");
					return 1;
				}

				if (strlen(player[playerid][gender]) == 0)
				{
					SendClientMessage(playerid, HEX_TOMORROW_YELLOW, "[Server » You] This account already have a password registered, please, select your gender.");
					ShowPlayerDialog(playerid, genderDialog, DIALOG_STYLE_LIST, ""TOMORROW_ORANGE"Select your gender.", ""DRACULA_PINK"Female\n"DRACULA_CYAN"Male\n"TOMORROW_WHITE"Other", "Select", "");
					return 1;
				}
			}

			//SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] You are already a registered member, please login.");
			ShowPlayerDialog(playerid, loginDialog, DIALOG_STYLE_PASSWORD, ""TOMORROW_GREEN"Login area.", ""TOMORROW_YELLOW"It looks like you're already a registered member, enter your account password to login.", "Login", "Cancel");

			return 1;
		}

		if(clickedid == tdBtnRegister)
		{
			hasTextdrawOpened[playerid] = false;
			CloseOpeningTDPanel(playerid);

			new dbQuery[71], DBResult:dbResult;
			format(dbQuery, sizeof(dbQuery), "SELECT * FROM players WHERE pName = '%q' LIMIT 1", player[playerid][pName]);
			dbResult = db_query(pdbConnection, dbQuery);

			if (db_num_rows(dbResult) == 1)
			{
				player[playerid][dbid] = db_get_field_assoc_int(dbResult, "dbid");
				db_get_field_assoc(dbResult, "pass", player[playerid][pass], 61);
				db_get_field_assoc(dbResult, "gender", player[playerid][gender], 7);

				if (strlen(player[playerid][pass]) == 0)
				{
					ShowPlayerDialog(playerid, registerDialog, DIALOG_STYLE_PASSWORD, ""TOMORROW_GREEN"User registration.", ""TOMORROW_ORANGE"Please, register a strong pass for your account. (6 - 25 Chars)", "Done", "Cancel");
					//SetTimerEx("ShowPlayerDialog", 100, false "iiissss", playerid, registerDialog, DIALOG_STYLE_PASSWORD, ""TOMORROW_GREEN"User registration.", ""TOMORROW_ORANGE"Please, register a strong pass for your account. (6 - 25 Chars)", "Done", "Cancel");
					return 1;
				}

				if (strlen(player[playerid][gender]) == 0)
				{
					SendClientMessage(playerid, HEX_TOMORROW_YELLOW, "[Server » You] This account already have a password registered, please, select your gender.");
					ShowPlayerDialog(playerid, genderDialog, DIALOG_STYLE_LIST, ""TOMORROW_ORANGE"Select your gender.", ""DRACULA_PINK"Female\n"DRACULA_CYAN"Male\n"TOMORROW_WHITE"Other", "Select", "");
					return 1;
				}
			}

			if (readingTolerance[playerid] == 0)
			{
				SendClientMessage(playerid, HEX_TOMORROW_ORANGE, "[Server » You] You are already a registered member, please login.");
				readingTolerance[playerid]++;
			}
			
			ShowPlayerDialog(playerid, loginDialog, DIALOG_STYLE_PASSWORD, ""TOMORROW_GREEN"Login area.", ""TOMORROW_YELLOW"It looks like you're already a registered member, enter your account password to login.", "Login", "Cancel");

			return 1;
		}

		if(clickedid == tdBtnExit)
		{
			hasTextdrawOpened[playerid] = false;
			CloseOpeningTDPanel(playerid);

			SendClientMessage(playerid, HEX_TOMORROW_YELLOW, "[Server » You] Bye! :)");

			SetTimerEx("KickThePlayer", 1000, false, "%i", playerid);

			return 1;
		}
	}
	else
	{
		if(hasTextdrawOpened[playerid])
		{
			SelectTextDraw(playerid, 0xf6f6f6ff);
		}
		else
		{
			CancelSelectTextDraw(playerid);
		}

		return 1;
	}

	return 0;
}