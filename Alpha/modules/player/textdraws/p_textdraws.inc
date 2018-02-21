forward ShowOpeningTDPanel(playerid);
forward CloseOpeningTDPanel(playerid);

public ShowOpeningTDPanel(playerid)
{
	TextDrawShowForPlayer(playerid, tdBoxBackground);
	TextDrawShowForPlayer(playerid, tdDesignPanel);
	TextDrawShowForPlayer(playerid, tdBoxPanel);
	TextDrawShowForPlayer(playerid, tdBtnLogin);
	TextDrawShowForPlayer(playerid, tdBtnRegister);
	TextDrawShowForPlayer(playerid, tdBtnExit);
	TextDrawShowForPlayer(playerid, tdDesignLogin);
	TextDrawShowForPlayer(playerid, tdDesignRegister);
	TextDrawShowForPlayer(playerid, tdServerVersion);
	TextDrawShowForPlayer(playerid, tdVersionLabel);
	TextDrawShowForPlayer(playerid, tdBuildLabel);
	TextDrawShowForPlayer(playerid, tdBuildVersion);
	TextDrawShowForPlayer(playerid, tdPanelTitle1);
	TextDrawShowForPlayer(playerid, tdPanelTitle2);
	TextDrawShowForPlayer(playerid, tdPanelTitle3);
	TextDrawShowForPlayer(playerid, tdPanelTitle4);
	TextDrawShowForPlayer(playerid, tdPanelTitle5);

	SelectTextDraw(playerid, 0xf6f6f6ff);

	return 1;
}

public CloseOpeningTDPanel(playerid)
{
	TextDrawHideForPlayer(playerid, tdBoxBackground);
	TextDrawHideForPlayer(playerid, tdDesignPanel);
	TextDrawHideForPlayer(playerid, tdBoxPanel);
	TextDrawHideForPlayer(playerid, tdBtnLogin);
	TextDrawHideForPlayer(playerid, tdBtnRegister);
	TextDrawHideForPlayer(playerid, tdBtnExit);
	TextDrawHideForPlayer(playerid, tdDesignLogin);
	TextDrawHideForPlayer(playerid, tdDesignRegister);
	TextDrawHideForPlayer(playerid, tdServerVersion);
	TextDrawHideForPlayer(playerid, tdVersionLabel);
	TextDrawHideForPlayer(playerid, tdBuildLabel);
	TextDrawHideForPlayer(playerid, tdBuildVersion);
	TextDrawHideForPlayer(playerid, tdPanelTitle1);
	TextDrawHideForPlayer(playerid, tdPanelTitle2);
	TextDrawHideForPlayer(playerid, tdPanelTitle3);
	TextDrawHideForPlayer(playerid, tdPanelTitle4);
	TextDrawHideForPlayer(playerid, tdPanelTitle5);

	CancelSelectTextDraw(playerid);

	return 1;
}