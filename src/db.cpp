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
#include "bnfs.h"
#include "db.h"

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

void exit_on_database_failure(const char *errstr_format)
{
	if (con == NULL) {
		sampgdk::logprintf(errstr_format, "unknown, couldn't init");
	} else {
		sampgdk::logprintf(errstr_format, mysql_error(con));
		mysql_close(con);
	}
	exit(1);
}

