/*
 * Copyright (C) 2022-2023 Heptazhou <zhou@0h7z.com>
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

#include <iostream>

int main(int argc, const char *argv[])
{
	std::cout << sizeof(bool) << "	bool\n";
	std::cout << sizeof(char) << "	char\n";
	std::cout << sizeof(wchar_t) << "	wchar_t\n";
	std::cout << sizeof(short) << "	short\n";
	std::cout << sizeof(int) << "	int\n";
	std::cout << sizeof(long) << "	long\n";
	std::cout << sizeof(float) << "	float\n";
	std::cout << sizeof(double) << "	double\n";
	std::cout << sizeof(long long) << "	long long\n";
	std::cout << sizeof(long double) << "	long double\n";
}
