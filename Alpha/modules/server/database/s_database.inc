new DB:sdbConnection;
new nBuildnumber;

// OSDB: Open server database.
public OSDB_OnGameModeInit()
{
	if ((sdbConnection = db_open("AWServer.db")) == DB:0)
	{
		print("[Routes:Database] The connection with the server database falied.");
	}
	else
	{
		print("[Routes:Database] The server is connected with the server database.");

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

		db_query(sdbConnection, "CREATE TABLE IF NOT EXISTS sversion (vid INTEGER PRIMARY KEY AUTOINCREMENT, version VARCHAR(29) DEFAULT Alpha, buildnumber INTEGER DEFAULT 0)");

//		INSERT INTO players (pName, acceptedRules) VALUES ('%q', %i)

		new dbQuery[99], DBResult:dbResult;

		format(dbQuery, sizeof(dbQuery), "SELECT * FROM sversion WHERE vid = %i", 1);
		dbResult = db_query(sdbConnection, dbQuery);

		if (db_num_rows(dbResult) == 1)
		{
			nBuildnumber = db_get_field_int(dbResult, 2);
			nBuildnumber++;

			format(dbQuery, sizeof(dbQuery), "UPDATE sversion SET buildnumber = %i", nBuildnumber);
			db_query(sdbConnection, dbQuery);
		}
		else
		{
			format(dbQuery, sizeof(dbQuery), "INSERT INTO sversion (version, buildnumber) VALUES ('%s', %i)", "Alpha", 1);
			db_query(sdbConnection, dbQuery);
		}

		db_free_result(dbResult);
	}

	return 1;
}

// CRDB: Close server database.
public CSDB_OnGameModeExit()
{
	db_close(sdbConnection);

	return 1;
}