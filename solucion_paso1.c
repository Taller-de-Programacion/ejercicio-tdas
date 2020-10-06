#include <stdio.h>

#define BUFFER_SIZE 4

int main(int argc, char const *argv[]) {
	char buffer[BUFFER_SIZE];
	size_t result = fread(buffer, 1, BUFFER_SIZE, stdin);

	printf("\033[0;31m");
	fwrite(buffer, 1, result, stdout);
	printf("\033[0m");
	return 0;
}
