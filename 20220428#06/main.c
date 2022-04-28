/*
 * Copyright (C) 2022 Heptazhou <zhou@0h7z.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define flush(stream)    ((stream)->_IO_read_ptr = (stream)->_IO_read_end)
#define trimcrlf(string) ((string)[strcspn((string), "\r\n")] = 0)

int main(int argc, const char *argv[])
{
	int   ss = 81;
	char *si = (char *) malloc(ss),
		 *so = (char *) malloc(ss);

	puts("\ecInput any string:");
	fgets(si, ss, stdin), trimcrlf(si), flush(stdin);
	int sl = strlen(si);

	for (int i = 0; i < sl; i++)
		*(so + sl - i - 1) = *(si + i);
	*(so + sl) = 0;

	printf("\ec%d character(s)\n", sl);
	puts(si);
	puts(so);
}
