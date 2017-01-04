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
#ifndef MMPG_DB
#define MMPG_DB

#define DB_HOST "127.0.0.1"
#define DB_DBNAME "mmpgserver"
#define DB_USR "root"
#define DB_PW ""

void init_database();
void exit_on_database_failure(const char *errstr_format);

#endif /* MMPG_DB */
