#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declaraciones externas necesarias */
extern int yyparse();
extern FILE *yyin;

/* Función para validar la extensión .smart */
int es_archivo_valido(const char *nombre) {
    const char *extension = strrchr(nombre, '.');
    if (extension != NULL && strcmp(extension, ".smart") == 0) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    // Verificamos si se pasó un argumento
    if (argc < 2) {
        printf("Uso: %s <archivo.smart>\n", argv[0]);
        return 1;
    }

    // 1. Validar extensión
    if (!es_archivo_valido(argv[1])) {
        printf("Error: El archivo debe tener la extension '.smart'.\n");
        return 1;
    }

    // 2. Abrir el archivo
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error al abrir el archivo");
        return 1;
    }

    printf("--- Analizando archivo: %s ---\n", argv[1]);

    // 3. Iniciar el parseo
    // yyparse() utilizará automáticamente yyin, que ahora apunta al archivo
    if (yyparse() == 0) {
        printf("¡Compilacion exitosa!\n");
    } else {
        printf("Error: Fallo en la compilacion.\n");
    }

    // 4. Cerrar el archivo
    fclose(yyin);

    return 0;
}