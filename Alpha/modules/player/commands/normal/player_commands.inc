public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
	if (player[playerid][isChatLocked])
	{
		SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Chat locked, you can't type anything until it unlock.");
		return 0;
	}

	/*
	if ((flags & cmdOwner) && player[playerid][adminLevel] != cmdOwner)
    {
    	SendClientMessage(playerid, HEX_DRACULA_RED, "[Server » You] Only for the Owner.");
        return 0;
    }
	*/

	return 1;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags) {
	if (result == -1) {
		SendClientMessage(playerid, HEX_TOMORROW_RED, "[Server » You] Unknown command.");
		return 0;
	}

	return 1;
}