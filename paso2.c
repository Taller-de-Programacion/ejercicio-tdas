// Teniendo un código que sabe leer algonos bytes de un archivo,
// es fácil extenderlo para que lo lea completo
//
// hint: feof
//

#include <stdio.h>

#define BUFFER_SIZE 4

int main(int argc, char const *argv[]) {
	char buffer[BUFFER_SIZE];
	size_t result = fread(buffer, 1, BUFFER_SIZE, stdin);

	fwrite(buffer, 1, result, stdout);
	return 0;
}
