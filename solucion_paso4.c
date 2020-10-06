#include "socket.h"

int main(int argc, char const *argv[]) {
	socket_t socket;
	socket_init(&socket);
	
	socket_connect(&socket, "localhost", "7777");
	socket_send(&socket, "hola\n", 5);

	socket_uninit(&socket);
	return 0;
}
