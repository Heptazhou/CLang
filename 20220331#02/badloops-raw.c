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

main()
{
	char word[80];
	int  i, j;

	printf("Enter any word: ");
	scanf("%s", word);
	i = 0;
	while (word[i] != '\0')
	{
		if (word[i] == word[i + 1])
		{
			j = 1;
			while (word[i] == word[i + j])
				j++;
			printf("%d consecutive %c\n", j, word[i]);
		}
		i++;
	}
}
