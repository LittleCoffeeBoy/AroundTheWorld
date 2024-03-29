new DB:pdbConnection;

// DBP: OpenPlayerDatabase
public OPDB_OnGameModeInit()
{
	if ((pdbConnection = db_open("AWPlayers.db")) == DB:0)
	{
		print("[AW:Database] The connection with database falied.");
	}
	else
	{
		print("[Database] The server is connected with the players database correctly.");

		//db_query(pdbConnection, "PRAGMA synchronous = OFF");
		db_query(pdbConnection, "CREATE TABLE IF NOT EXISTS players (dbid INTEGER PRIMARY KEY AUTOINCREMENT,\
		pName VARCHAR(25) COLLATE NOCASE,\
		pass VARCHAR(61),\
		acceptedRules INTEGER,\
		gender VARCHAR(7),\
		genderColor VARCHAR(9),\
		isChatLocked INTEGER DEFAULT 0,\
		adminLevel INTEGER DEFAULT 0,\
		staffTag VARCHAR(9),\
		money INTEGER DEFAULT 0)");
	}

	return 1;
}

// CPDB: ClosePlayerDatabase
public CPDB_OnGameModeExit()
{
	db_close(pdbConnection);
	
	return 1;
}