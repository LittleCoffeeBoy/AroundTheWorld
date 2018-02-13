forward CreateRoute(playerid, truck, trailer, averageDeliveryTime[], companyName[], companyOwner[], whatWillBeDelivered[], loadValue, loadType, from[], Float:posFromX, Float:posFromY, Float:posFromZ, to[], Float:posToX, Float:posToY, Float:posToZ, rewardCash);
forward SearchRoutes(playerid);

/*
enum sTrucks
{
	Linerunner = 403,
	Bobcat = 422,
	Rumpo = 440,
	Packer = 443,
	Flatbed = 455,
	Yankee = 456,
	Walton = 478,
	Benson = 499,
	Tanker = 514, // like Linerunner but for oil
	Roadtrain = 515, // like Linerunner but for ore
	Cement_Truck = 524,
	Sadler = 543,
	Yosemite = 554,
	DFT_30 = 578,
	Boxville = 609
};
*/

new sTrucks[] = {
	403,
	422,
	440,
	443,
	455,
	456,
	478,
	499,
	514,
	515,
	524,
	543,
	554,
	578,
	609
};

/*
enum sTrailers
{
	Article_Trailer_1 = 435,
	Article_Trailer_2 = 450,
	Petrol_Trailer = 584,
	Article_Trailer_3 = 591,
	Baggage_Trailer_A = 606,
	Baggage_Trailer_B = 607
};
*/
new sTrailers[] = {
	435,
	450,
	584,
	591,
	606,
	607
};

public CreateRoute(playerid, truck, trailer, averageDeliveryTime[], companyName[], companyOwner[], whatWillBeDelivered[], loadValue, loadType, from[], Float:posFromX, Float:posFromY, Float:posFromZ, to[], Float:posToX, Float:posToY, Float:posToZ, rewardCash)
{
	new dbQuery2[579];
	format(dbQuery2, sizeof(dbQuery2), "INSERT INTO routes (rTruck, rTrailer, rAverageDeliveryTime, rCompanyName, rCompanyOwner, rWhatWillBeDelivered, rLoadValue, rLoadType, rFrom, rPosFromX, rPosFromY, rPosFromZ, rTo, rPosToX, rPosToY, rPosToZ, rRewardCash) VALUES (%i, %i, '%q', '%q', '%q', '%q', %i, %i, '%q', %f, %f, %f, '%q', %f, %f, %f, %i)",\
	truck, trailer, averageDeliveryTime, companyName, companyOwner, whatWillBeDelivered, loadValue, loadType, from, posFromX, posFromY, posFromZ, to, posToX, posToY, posToZ, rewardCash);
	db_query(sdbConnection, dbQuery2);

	SendClientMessage(playerid, HEX_TOMORROW_BLUE, "[Server » You] Route created successfuly.");

	return 1;
}

public SearchRoutes(playerid)
{
	
	new dbQuery[56], DBResult:dbResult;
	format(dbQuery, sizeof(dbQuery), "SELECT * FROM routes ORDER BY rRewardCash DESC LIMIT 10");
	dbResult = db_query(sdbConnection, dbQuery);

	new i = 0;

	do
	{
		// For int fields:
		RoutesInformation[playerid][i][iTruck] = db_get_field_int(dbResult, 1);
		RoutesInformation[playerid][i][iTrailer] = db_get_field_int(dbResult, 2);
		RoutesInformation[playerid][i][iLoadValue] = db_get_field_int(dbResult, 7);
		RoutesInformation[playerid][i][iLoadType] = db_get_field_int(dbResult, 8);
		RoutesInformation[playerid][i][iRewardCash] = db_get_field_int(dbResult, 17);
		//printf("%i", RoutesInformation[playerid][i][iTruck]);

		// For string fields:
		db_get_field(dbResult, 3, RoutesInformation[playerid][i][iAverageDeliveryTime], 37);
		db_get_field(dbResult, 4, RoutesInformation[playerid][i][iCompanyName], 26);
		db_get_field(dbResult, 5, RoutesInformation[playerid][i][iCompanyOwner], 25);
		db_get_field(dbResult, 6, RoutesInformation[playerid][i][iWhatWillBeDelivered], 21);
		db_get_field(dbResult, 9, RoutesInformation[playerid][i][iFrom], 31);
		db_get_field(dbResult, 13, RoutesInformation[playerid][i][iTo], 31);
		//printf("%s", RoutesInformation[playerid][i][iAverageDeliveryTime]);

		// For float fields:
		RoutesInformation[playerid][i][iPosFromX] = db_get_field_float(dbResult, 10);
		RoutesInformation[playerid][i][iPosFromY] = db_get_field_float(dbResult, 11);
		RoutesInformation[playerid][i][iPosFromZ] = db_get_field_float(dbResult, 12);
		RoutesInformation[playerid][i][iPosToX] = db_get_field_float(dbResult, 14);
		RoutesInformation[playerid][i][iPosToY] = db_get_field_float(dbResult, 15);
		RoutesInformation[playerid][i][iPosToZ] = db_get_field_float(dbResult, 16);
		//printf("%f", RoutesInformation[playerid][i][iPosFromX]);

		i++;
	}
	while(db_next_row(dbResult));

	//printf("Quantidade de rotas encontradas para o jogador %s: %i", player[playerid][pName], i-1);

	db_free_result(dbResult);

	new strRoutes[1076], strHeaderRoutesFormat[26], strRoutesFormat[105];

	format(strHeaderRoutesFormat, sizeof(strHeaderRoutesFormat), "Truck\t From\t To\t Reward");
	strins(strRoutes, strHeaderRoutesFormat, 0);

	new j = 0;

	do
	{
		new routeTruck[13];
		format(routeTruck, 13, "%s", GetTruckName(RoutesInformation[playerid][j][iTruck]));

		format(strRoutesFormat, sizeof(strRoutesFormat), "\n%s\t %s\t %s\t $%i\n", routeTruck, RoutesInformation[playerid][j][iFrom], RoutesInformation[playerid][j][iTo], RoutesInformation[playerid][j][iRewardCash]);
		strins(strRoutes, strRoutesFormat, strlen(strRoutes));
		
		j++;
	}
	while(j < i);

	//printf("Quantidade de rotas adicionandas para o jogador %s: %i", player[playerid][pName], j-1);
	
	ShowPlayerDialog(playerid, routesDialog, DIALOG_STYLE_TABLIST_HEADERS, "Server Routes", strRoutes, "Select", "Cancel");

	return 1;
}

stock GetTruckName(truckid)
{
	new truckName[12];

	switch (truckid)
	{
		case 403:
		{
			format(truckName, 12, "Linerunner");
		}

		case 422:
		{
			format(truckName, 12, "Bobcat");
		}

		case 440:
		{
			format(truckName, 12, "Rumpo");
		}

		case 443:
		{
			format(truckName, 12, "Packer");
		}

		case 455:
		{
			format(truckName, 12, "Flatbed");
		}

		case 456:
		{
			format(truckName, 12, "Yankee");
		}

		case 478:
		{
			format(truckName, 12, "Walton");
		}

		case 499:
		{
			format(truckName, 12, "Benson");
		}

		case 514:
		{
			format(truckName, 12, "Tanker");
		}

		case 515:
		{
			format(truckName, 12, "Roadtrain");
		}

		case 524:
		{
			format(truckName, 12, "Cement Truck");
		}

		case 543:
		{
			format(truckName, 12, "Sadler");
		}

		case 554:
		{
			format(truckName, 12, "Yosemite");
		}

		case 578:
		{
			format(truckName, 12, "DFT-30");
		}

		case 609:
		{
			format(truckName, 12, "Boxville");
		}

		default: format(truckName, 12, "-");
	}

	return truckName;
}