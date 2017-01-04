/*
 * basdon-nfs - a sa-mp cpp racing gamemode
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
#ifndef MMPG_BNFS
#define MMPG_BNFS

#ifdef __WIN
	#define WIN32_LEAN_AND_MEAN
#endif

//#define sprintf sprintf_s

#include <mysql.h>

#include "sampgdk.h"
#ifdef MAX_PLAYERS_OVERRIDE
#undef MAX_PLAYERS
#define MAX_PLAYERS (MAX_PLAYERS_OVERRIDE)
#endif

extern MYSQL *con;

#endif /* MMPG_BNFS */
