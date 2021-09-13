/// Ahora queremos hacer un cliente TCP, que no tiene nada que ver con leer
/// un archivo!
/// <p>
/// Entonces empecemos una nueva prueba de concepto from scratch...
/// <p>
///
/// hints:
/// <p>
///   Ver las páginas de manual:
/// <p>
///     man socket
/// <p>
///     man send
/// <p>
///     man recv
/// <p>
///     man listen
/// <p>
///     man accept
/// <p>
///     etc...
///
/// <p>
/// Compilar:
///   gcc -pedantic -Wall -Werror sock.o paso4.c
/// <p>
/// Para que exista un server:
///   nc -l localhost -p 7777
/// <p>
/// Ejecutar:
///   echo "Hola mundo" | ./a.out
///

#include "socket.h"

int main(int argc, char const *argv[]) {
	return 0;
}

/// Notas:
/// <p>
///   - ¿Dónde se tocan este código y el que maneja archivos?
/// <p>
///   - Nos parece más fácil esta idea de programar por bloques, y que cada bloque sea igual de difícil.
