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

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct sockaddr    sockaddr_t;
typedef struct sockaddr_in sockaddr_in_t;

#define BUF_SIZE 2000
#define COM_PORT 9000
#define MSG_SHDN "shutdown"
#define MSG_QUIT "quit"
#define SERV_ADD "127.0.0.1"

#define flush(stream)    ((stream)->_IO_read_ptr = (stream)->_IO_read_end)
#define trimcrlf(string) ((string)[strcspn((string), "\r\n")] = 0)

int main(int argc, const char *argv[])
{
	int           sock, read_size;
	sockaddr_in_t server;
	char          message[BUF_SIZE / 2], server_reply[BUF_SIZE];

	// Create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		perror("socket create failed"),
			exit(EXIT_FAILURE);
	puts("socket created");

	server.sin_addr.s_addr = inet_addr(SERV_ADD);
	server.sin_family      = AF_INET;
	server.sin_port        = htons(COM_PORT);

	// Connect to remote server
	if (connect(sock, (sockaddr_t *) &server, sizeof(server)) < 0)
		perror("connect failed"),
			exit(EXIT_FAILURE);
	puts("connected"), puts("");

	// Keep communicating with server
	while (1)
	{
		printf("enter a message: ");
		fgets(message, sizeof(message), stdin), trimcrlf(message), flush(stdin);
		if (strlen(message) == 0) continue;

		// Send some data
		if (send(sock, message, strlen(message), 0) < 0)
			perror("send failed"),
				exit(EXIT_FAILURE);

		// Receive a reply from the server
		if ((read_size = recv(sock, server_reply, BUF_SIZE, 0)) < 0)
			perror("recv failed"),
				exit(EXIT_FAILURE);
		server_reply[read_size] = 0;
		if (strcmp(server_reply, MSG_SHDN) == 0)
			puts(""), puts("server closed"), close(sock),
				exit(EXIT_SUCCESS);
		if (strcmp(server_reply, MSG_QUIT) == 0)
			puts(""), puts("client closed"), close(sock),
				exit(EXIT_SUCCESS);
		printf("server reply is: "), puts(server_reply);
	}
}
