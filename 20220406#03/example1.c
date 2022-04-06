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

int main(int argc, const char *argv[])
{
	int pow2(int);

	int a, mask = pow2(4) - 1; // 0b1111

	printf("Input a number: 0o"), scanf("%o", &a);
	printf("0o%o \t(%d)\n", a, a);
	a = a >> 4 & mask;
	printf("0o%o \t(%d)\n", a, a);
}

int pow2(int n) { return n < 1 ? 0 : 2 << (n - 1); } // 2^n
