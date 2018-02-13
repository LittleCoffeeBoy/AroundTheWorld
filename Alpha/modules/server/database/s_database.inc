new DB:sdbConnection;

// OSDB: Open server database.
public OSDB_OnGameModeInit()
{
	if ((sdbConnection = db_open("AWServer.db")) == DB:0)
	{
		print("[Routes:Database] The connection with the routes database falied.");
	}
	else
	{
		print("[Routes:Database] The server is connected with the routes database.");

		db_query(sdbConnection, "CREATE TABLE IF NOT EXISTS routes (rid INTEGER PRIMARY KEY AUTOINCREMENT,\
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

// CRDB: Close server database.
public CSDB_OnGameModeExit()
{
	db_close(sdbConnection);

	return 1;
}