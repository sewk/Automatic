/*
 * Copyright (C) 2008 Frank Aurich (1100101+automatic@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#define TIME_STR_SIZE     25

#define dbg_printf( n, ... ) am_printf( __FILE__, __LINE__, n, 0, __VA_ARGS__ )
/* with time */
#define dbg_printft( n, ... ) am_printf( __FILE__, __LINE__, n, 1, __VA_ARGS__ )

enum debug_type {
	P_NONE = -1,
	P_ERROR = 0,
	P_MSG = 1,
	P_INFO = 2,
	P_INFO2 = 3,
	P_DBG = 4,
  P_MEM = 5
};

typedef enum debug_type debug_type;

unsigned char log_init(const char *logfile, char msglevel, char append_log);
void  log_close(void);
unsigned char pid_create(const char *pidfile, int pid);
void pid_close();
char* getlogtime_str(char *buf);
void  am_printf( const char * file, int line, debug_type type, int withTime, const char * format, ... );
