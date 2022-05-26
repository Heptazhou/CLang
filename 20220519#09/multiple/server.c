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
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct sockaddr    sockaddr_t;
typedef struct sockaddr_in sockaddr_in_t;

#define BUF_SIZE 2000
#define COM_PORT 9001
#define MSG_SHDN "shutdown"

int main(int argc, const char *argv[])
{
	void *connection_handler(void *);

	int           socket_desc, client_sock, c_addr_size, *new_sock;
	sockaddr_in_t server, client;

	// Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
		perror("socket create failed"),
			exit(EXIT_FAILURE);
	puts("socket created");

	// Prepare the sockaddr_in structure
	server.sin_family      = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port        = htons(COM_PORT);

	// Bind
	if (bind(socket_desc, (sockaddr_t *) &server, sizeof(server)) < 0)
		perror("socket bind failed"),
			exit(EXIT_FAILURE);
	puts("socket binded");

	// Listen
	listen(socket_desc, 3);

	// Wait for incoming connection
	puts("waiting for incoming connection...");
	c_addr_size = sizeof(sockaddr_in_t);

	while (1)
	{
		// Accept connection from an incoming client
		client_sock = accept(socket_desc, (sockaddr_t *) &client, (socklen_t *) &c_addr_size);
		if (client_sock < 0)
		{
			perror("connection accept failed");
			continue;
		}
		puts("connection accepted");

		pthread_t sniffer_thread;
		new_sock  = (int *) malloc(sizeof(int));
		*new_sock = client_sock;
		if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *) new_sock) < 0)
		{
			perror("handler assign failed");
			continue;
		}
		puts("handler assigned");

		// Now join the thread if you prefer blocking behavior
		// pthread_join(sniffer_thread, NULL);
	}
}

void *connection_handler(void *socket_desc)
{
	// Get the socket descriptor
	int  client_sock = *(int *) socket_desc, read_size;
	char client_message[BUF_SIZE];

	// Receive a message from client
	while (1)
	{
		read_size = recv(client_sock, client_message, BUF_SIZE, 0);
		if (read_size == 0)
		{
			puts("client disconnected");
			break;
		}
		if (read_size <= 0)
		{
			perror("message receive failed");
			continue;
		}
		client_message[read_size] = 0;

		// Send the message back to client
		write(client_sock, client_message, strlen(client_message));
		if (strcmp(client_message, MSG_SHDN) == 0)
			puts(""), puts("shutdown message received"),
				exit(EXIT_SUCCESS);
		printf("message received: "), puts(client_message);
	}

	// Free the socket pointer
	free(socket_desc);

	return 0;
}
