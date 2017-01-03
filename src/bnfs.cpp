/*
 * basdon-nfs - a sa-mp cpp gamemode inspired by need for speed etc.
 * Copyright (C) 2017  robin_be
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <string.h>

#include "db.h"
#include "bnfs.h"
#include "defs.h"

int g_playercount;
MYSQL *con;

/*
void SAMPGDK_CALL PrintTickCountTimer(int timerid, void *params)
{
	sampgdk::logprintf("Tick count: %d", GetTickCount());
}
*/

void init_database()
{
	con = mysql_init(NULL);

	if(con == NULL)
		exit_on_database_failure("MySQL panic: %s\n");

	if(mysql_real_connect(con, DB_HOST, DB_USR, DB_PW, NULL, 0, NULL, 0) == NULL)
		exit_on_database_failure("MySQL: could not login: %s\n");

	if(mysql_query(con, "USE "DB_DBNAME))
		exit_on_database_failure("MySQL: could not use db: %s\n");

	sampgdk::logprintf("mysql info: %s\n", mysql_get_client_info());
}

void exit_on_database_failure(const char *errstr_format) {
	if (con == NULL) {
		sampgdk::logprintf(errstr_format, "unknown, couldn't init");
	} else {
		sampgdk::logprintf(errstr_format, mysql_error(con));
		mysql_close(con);
	}
	exit(1);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit()
{
	init_database();

	SetGameModeText(MMPG_VERSION);
	UsePlayerPedAnims();
	AddPlayerClass(0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
	//SetTimer(1000, true, PrintTickCountTimer, 0);

	return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerConnect(int playerid)
{
	SendClientMessage(playerid, COLOR_WARN, MSG_PREFIX_WARN"Please keep in mind this is an alpha version.");
	SendClientMessage(playerid, COLOR_WARN, MSG_PREFIX_WARN"This version may not represent final product.");

	DisablePlayerCheckpoint(playerid);
	DisablePlayerRaceCheckpoint(playerid);
	ShowPlayerDialog(playerid, -1, DIALOG_STYLE_MSGBOX, "_", "_", "_", "_");

	SetSpawnInfo(playerid, 0, 0, 1375.04f, -920.53f, 34.46f, 0.0, 0, 0, 0, 0, 0, 0);
	return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerCommandText(int playerid, const char *cmdtext)
{
	return SendClientMessage(playerid, COLOR_WARN, MSG_PREFIX_WARN "Command not found");
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerSpawn(int playerid)
{
	return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerClickTextDraw(int playerid, int clickedid)
{
	return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnDialogResponse(int playerid, int dialogid, int response,
                                                int listitem, const char *inputtext)
{
	return true;
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return sampgdk::Supports() | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	return sampgdk::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	mysql_close(con);
	sampgdk::Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick()
{
	sampgdk::ProcessTick();
}

