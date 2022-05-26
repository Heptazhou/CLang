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
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int  len, pd[2];
	char buf[BUFSIZ];

	if (pipe(pd) < 0)
		perror("pipe create failed"), exit(EXIT_FAILURE);
	else
		printf("pipe created. pipe descriptor: { %d, %d }\n", pd[0], pd[1]);

	while (fgets(buf, sizeof(buf), stdin))
	{
		if (strcspn(buf, "\r\n") == 0) continue;
		len = strlen(buf);
		if (write(pd[1], buf, len) != len)
			perror("pipe write failed"), exit(EXIT_FAILURE);
		for (int i = 0; i < len; i++) buf[i] = 'X';
		len = read(pd[0], buf, sizeof(buf));
		if (len < 0)
			perror("pipe read failed"), exit(EXIT_FAILURE);
		if (write(STDOUT_FILENO, buf, len) != len)
			perror("stdout write failed"), exit(EXIT_FAILURE);
	}
}
