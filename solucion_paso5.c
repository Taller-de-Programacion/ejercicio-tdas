/* ************************************************* *
 * file_reader.h
 * ************************************************* */
#include <stdio.h>

typedef struct {
	FILE *file;
} file_reader_t;

typedef void (*file_reader_callback_t)(const char *chunk, 
	                                   size_t chunk_size,
	                                   void *callback_ctx);

int file_reader_init(file_reader_t *self, const char *file_name);
int file_reader_uninit(file_reader_t *self);
int file_reader_iterate(file_reader_t *self,
	                    file_reader_callback_t callback,
	                    void *callback_ctx);


/* ************************************************* *
 * file_reader.c
 * ************************************************* */

#include <stdio.h>
//#include "file_reader.h"

#define CHUNK_SIZE 4

int file_reader_init(file_reader_t *self, const char *file_name) {
	self->file = file_name ? fopen(file_name, "rb") : stdin;
	return 0;
}

int file_reader_uninit(file_reader_t *self) {
	if (self->file != stdin) {
		fclose(self->file);
	}
	return 0;
}

int file_reader_iterate(file_reader_t *self,
	                    file_reader_callback_t callback,
	                    void *callback_ctx) {
	char chunk[CHUNK_SIZE];

	while (!feof(self->file)) {
		size_t result = fread(chunk, 1, CHUNK_SIZE, self->file);
		callback(chunk, result, callback_ctx);
	}

	return 0;
}


/* ************************************************* *
 * main.c
 * ************************************************* */

//#include "file_reader.h"
#include "socket.h"


static void _send_chunk(const char *chunk, 
	                    size_t chunk_size,
	                    void *callback_ctx) {
	socket_t *socket = callback_ctx;
	socket_send(socket, chunk, chunk_size);
}


int main(int argc, char const *argv[]) {
	file_reader_t file_reader;
	socket_t socket;

	file_reader_init(&file_reader, NULL);
	socket_init(&socket);

	socket_connect(&socket, "localhost", "7777");
	file_reader_iterate(&file_reader, _send_chunk, &socket);

	socket_uninit(&socket);
	file_reader_uninit(&file_reader);
	return 0;
}


// Qué le falta a esto?
//   Ese main quedó muy verboso! Hacer un TDA Client
//   Recibir por parámetro el host:service
//   Recibir el nombre del archivo
//
