/* ************************************************* *
 * file_reader.h
 * ************************************************* */
#include <stdio.h>

typedef struct {
	FILE *file;
} file_reader_t;

int file_reader_init(file_reader_t *self, const char *file_name);
int file_reader_uninit(file_reader_t *self);
int file_reader_foreach_chunk(file_reader_t *self);


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

int file_reader_iterate(file_reader_t *self) {
	char chunk[CHUNK_SIZE];

	while (!feof(self->file)) {
		size_t result = fread(chunk, 1, CHUNK_SIZE, self->file);

		printf("\033[0;31m");
		fwrite(chunk, 1, result, stdout);
		printf("\033[0m");
	}
	return 0;
}


/* ************************************************* *
 * main.c
 * ************************************************* */

//#include "file_reader.h"

int main(int argc, char const *argv[]) {
	file_reader_t file_reader;
	file_reader_init(&file_reader, NULL);
	
	file_reader_iterate(&file_reader);

	file_reader_uninit(&file_reader);
	return 0;
}
