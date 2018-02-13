new DB:rdbConnection;

/*
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
}
*/

// ORDB: Open routes database.
public ORDB_OnGameModeInit()
{
	if ((rdbConnection = db_open("RoutesAroundTheWorld.db")) == DB:0)
	{
		print("[Routes:Database] The connection with the routes database falied.");
	}
	else
	{
		print("[Routes:Database] The server is connected with the routes database.");

		db_query(rdbConnection, "CREATE TABLE IF NOT EXISTS routes (rid INTEGER PRIMARY KEY AUTOINCREMENT,\
		rTruck INTEGER,\
		rTrailer INTEGER,\
		rAverageDeliveryTime VARCHAR(37),\
		rCompanyName VARCHAR(26) COLLATE NOCASE,\
		rCompanyOwner VARCHAR(25),\
		rWhatWillBeDelivered VARCHAR(21),\
		rLoadValue INTEGER,\
		rLoadType INTEGER,\
		rFrom VARCHAR(31),\
		rPosFromX FLOAT,\
		rPosFromY FLOAT,\
		rPosFromZ FLOAT,\
		rTo VARCHAR(31),\
		rPosToX FLOAT,\
		rPosToY FLOAT,\
		rPosToZ FLOAT,\
		rRewardCash INTEGER)");
	}

	return 1;
}

// CRDB: Close routes database.
public CRDB_OnGameModeExit()
{
	db_close(rdbConnection);

	return 1;
}