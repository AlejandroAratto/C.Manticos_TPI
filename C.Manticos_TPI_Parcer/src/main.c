#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declaraciones externas necesarias */
extern int yyparse();
extern FILE *yyin;
extern int cant_errores;
int cant_errores = 0;

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
    printf("--- Analizando archivo: %s ---\n", argv[1]);

    // Ejecutamos el parser guardando su resultado
    int resultado_parseo = yyparse(); 

    // Evaluamos el resultado final
    if (resultado_parseo == 0 && cant_errores == 0) {
        // Exito total: Bison devolvió 0 (llegó al final) y nuestro contador está en 0
        printf("\n[OK] Compilacion exitosa: El archivo script es valido.\n");
    } else {
        // Hubo errores: Ya sea porque Bison abortó o porque nuestro contador sumó errores
        printf("\n[FAIL] La compilacion finalizo con %d errores.\n", cant_errores);
    }

    fclose(yyin);
    return 0;
}