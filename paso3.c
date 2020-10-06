// Ahora que tenemos una prueba de concepto, la tenemos que abstraer en
// un TDA, porque cuando metamos código que no tenga que ver con archivos
// no queremos que quede en el mismo lugar
// 
// Lo vamos a codificar en el mismo archivo porque es una presentación, pero
// en la vida real hay que mandarlo a otro archivo!
//

/* ************************************************* *
 * file_reader.h
 * ************************************************* */


/* ************************************************* *
 * file_reader.c
 * ************************************************* */


/* ************************************************* *
 * main.c
 * ************************************************* */
#include <stdio.h>

#define BUFFER_SIZE 4

int main(int argc, char const *argv[]) {
	char buffer[BUFFER_SIZE];

	while (!feof(stdin)) {
		size_t result = fread(buffer, 1, BUFFER_SIZE, stdin);

		printf("\033[0;31m");
		fwrite(buffer, 1, result, stdout);
		printf("\033[0m");
	}

	return 0;
}
