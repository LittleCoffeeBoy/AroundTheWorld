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

forward CreateRoute(playerid, truck, trailer, averageDeliveryTime[], companyName[], companyOwner[], whatWillBeDelivered[], loadValue, loadType, from[], Float:posFromX, Float:posFromY, Float:posFromZ, to[], Float:posToX, Float:posToY, Float:posToZ, rewardCash);

public CreateRoute(playerid, truck, trailer, averageDeliveryTime[], companyName[], companyOwner[], whatWillBeDelivered[], loadValue, loadType, from[], Float:posFromX, Float:posFromY, Float:posFromZ, to[], Float:posToX, Float:posToY, Float:posToZ, rewardCash)
{
	new dbQuery2[579];
	format(dbQuery2, sizeof(dbQuery2), "INSERT INTO routes (rTruck, rTrailer, rAverageDeliveryTime, rCompanyName, rCompanyOwner, rWhatWillBeDelivered, rLoadValue, rLoadType, rFrom, rPosFromX, rPosFromY, rPosFromZ, rTo, rPosToX, rPosToY, rPosToZ, rRewardCash) VALUES (%i, %i, '%q', '%q', '%q', '%q', %i, %i, '%q', %f, %f, %f, '%q', %f, %f, %f, %i)",\
	truck, trailer, averageDeliveryTime, companyName, companyOwner, whatWillBeDelivered, loadValue, loadType, from, posFromX, posFromY, posFromZ, to, posToX, posToY, posToZ, rewardCash);
	db_query(rdbConnection, dbQuery2);

	SendClientMessage(playerid, HEX_TOMORROW_BLUE, "[Server » You] Route created successfuly.");

	return 1;
}

public SearchRoutes()
{
	/*
	new dbQuery[71], DBResult:dbResult;
	format(dbQuery, sizeof(dbQuery), "SELECT * FROM routes WHERE rid = %i ORDER BY rRewardCash DESC LIMIT 10", player[playerid][pName]);
	dbResult = db_query(rdbConnection, dbQuery);

	if (db_num_rows(dbResult) >= 1)
	{
		for ()
		{

		}
	}
	*/
	
	return 1;
}