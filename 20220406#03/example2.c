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

typedef unsigned short type;

int main(int argc, const char *argv[])
{
	type a;
	int  n, bits = sizeof(type) * 8;

	printf("Input a: 0o"), scanf("%ho", &a);
	printf("Input n (0 < n < %d): ", bits), scanf("%d", &n);
	printf("0o%o \t(%d)\n", a, a);
	if (0 < n && n < bits)
		a = a >> n | a << (bits - n);
	printf("0o%o \t(%d)\n", a, a);
}
