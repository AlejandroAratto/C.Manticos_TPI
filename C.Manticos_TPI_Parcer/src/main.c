#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declaraciones externas necesarias */
extern int yyparse();
extern FILE *yyin;
extern int cant_errores;

/* Definición global del puntero al archivo HTML de salida */
FILE *f_html = NULL;


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

    // 2. Abrir el archivo de entrada (.smart)
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    // 3. Abrir el archivo HTML de salida
    f_html = fopen("resultado.html", "w");
    if (!f_html) {
        perror("Error al crear el archivo HTML de salida");
        fclose(yyin);
        return 1;
    }

    printf("--- Analizando archivo: %s ---\n", argv[1]);

    // 4. Escribir el encabezado estructural del documento HTML
    fprintf(f_html, "<!DOCTYPE html>\n<html lang=\"es\">\n<head>\n");
    fprintf(f_html, "  <meta charset=\"UTF-8\">\n");
    fprintf(f_html, "  <title>Smart Home - Panel de Control</title>\n");
    fprintf(f_html, "  <style>\n");
    fprintf(f_html, "    body { font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background-color: #f0f2f5; padding: 30px; color: #333; }\n");
    fprintf(f_html, "    h1 { color: #1a73e8; border-bottom: 2px solid #1a73e8; padding-bottom: 10px; }\n");
    fprintf(f_html, "    .bloque-evento { background: white; border-radius: 8px; border-left: 6px solid #1a73e8; padding: 20px; margin-bottom: 20px; box-shadow: 0 4px 6px rgba(0,0,0,0.05); }\n");
    fprintf(f_html, "    .bloque-every { background: white; border-radius: 8px; border-left: 6px solid #f4b400; padding: 20px; margin-bottom: 20px; box-shadow: 0 4px 6px rgba(0,0,0,0.05); }\n");
    fprintf(f_html, "    .condicion { font-weight: bold; color: #5f6368; margin-bottom: 15px; font-size: 1.1em; }\n");
    fprintf(f_html, "    ul { list-style-type: none; padding-left: 0; }\n");
    fprintf(f_html, "    li { background: #f8f9fa; padding: 10px 15px; margin: 5px 0; border-radius: 4px; border: 1px solid #dadce0; }\n");
    fprintf(f_html, "    .accion-foco { border-left: 4px solid #4285f4; }\n");
    fprintf(f_html, "    .accion-aire { border-left: 4px solid #0f9d58; }\n");
    fprintf(f_html, "    .accion-altavoz { border-left: 4px solid #ab47bc; }\n");
    fprintf(f_html, "  </style>\n</head>\n<body>\n");
    fprintf(f_html, "  <h1>Panel de Control Smart Home</h1>\n");

    // 5. Iniciar el parseo sintáctico
    int resultado_parseo = yyparse(); 

    // 6. Evaluar estrictamente el resultado final
    if (resultado_parseo == 0 && cant_errores == 0) {
        printf("\n[OK] Compilacion exitosa: El archivo script es valido.\n");
    } else {
        printf("\n[FAIL] La compilacion finalizo con %d errores detectados.\n", cant_errores);
    }

    // 7. Cerrar las etiquetas del documento HTML y liberar recursos
    fprintf(f_html, "</body>\n</html>\n");
    
    fclose(f_html);
    fclose(yyin);
    
    printf("Traduccion finalizada. Archivo de salida generado: 'resultado.html'\n");
    return 0;
}