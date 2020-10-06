#include <stdio.h>
#include "stdin_streamer.h"
#include "socket.h"

void my_callback(char *buffer, size_t len, void *ctx) {
	socket_t *s = ctx;
	socket_send(s, buffer, len);
}

void do_something_with_socket(socket_t *socket) {
	stdin_streamer_t stdin_streamer;
	stdin_streamer_create(&stdin_streamer, my_callback);
	stdin_streamer_run(&stdin_streamer, socket);
	stdin_streamer_destroy(&stdin_streamer);
}

int main(int argc, char const *argv[]) {
	socket_t socket;
	socket_create(&socket);
	socket_connect(&socket, "localhost", "7777");
	do_something_with_socket(&socket);
	socket_destroy(&socket);
	return 0;
}