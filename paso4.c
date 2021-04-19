// Ahora queremos hacer un cliente TCP, que no tiene nada que ver con leer
// un archivo!
// Entonces empecemos una nueva prueba de concepto from scratch...
//
// hints:
//   Ver las páginas de manual:
//     man socket
//     man send
//     man recv
//     man listen
//     man accept
//     etc...
// 
// Compilar:
//   gcc -pedantic -Wall -Werror sock.o paso4.c
// Para que exista un server:  
//   nc -l localhost -p 7777
// Ejecutar:
//   echo "Hola mundo" | ./a.out
//

#include "socket.h"

int main(int argc, char const *argv[]) {
	return 0;
}
