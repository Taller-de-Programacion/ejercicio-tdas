/// Como primer paso vamos a leer de entrada estándar, ver que el código
/// compile y que podamos ejecutarlo
/// <p>
/// hint: Ver man fread
/// <p>
/// Compilar:
///   gcc -pedantic -Wall -Werror paso1.c
/// <p>
/// Ejecutar:
///   ./a.out

int main(int argc, char const *argv[]) {
	return 0;
}

///
/// Notas:
/// <p>
///   - ¿Por qué no hacemos fopen() ni fclose()? Porque los flujos estándar son
///       manejados por el proceso que nos llama (aka la consola)
/// <p>
///   - ¿Y por qué no fscanf() o fprintf()?
///       Porque dijimos bytes, no texto.
///
