#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

/* Vinculamos las variables y puntos de entrada globales de Flex y Bison */
extern FILE *yyin;
extern int yyparse();
int cant_errores = 0;

char buffer_staging[65536] = "";

/* --- para el modo interactivo --- */
typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(const char *str);
extern void yy_delete_buffer(YY_BUFFER_STATE b);

FILE *f_html = NULL;
char linea_actual[2048] = "";

int main(int argc, char *argv[])
{
#ifdef _WIN32
    /* Configuración exclusiva si se corre bajo Windows nativo */
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    if (argc == 2)
    {
        yyin = fopen(argv[1], "rt");
        if (yyin == NULL)
        {
            printf("Error: No se pudo abrir el archivo de prueba '%s'\n", argv[1]);
            return -1;
        }

        /* para evitar errores abrimos el HTML antes del parser */
        f_html = fopen("rutinas_hogar.html", "wt");
        if (f_html == NULL)
        {
            printf("Error crítico: No se pudo crear el archivo HTML de salida.\n");
            fclose(yyin);
            return -1;
        }

        printf("Iniciando Analizador Sintáctico de: %s\n", argv[1]);
        printf("--------------------------------------------------\n");

        /* Inyectamos la cabecera del HTML */
        fprintf(f_html, "<!DOCTYPE html>\n<html lang=\"es\">\n<head>\n");
        fprintf(f_html, "  <meta charset=\"UTF-8\">\n  <title>Smart Home - Rutinas</title>\n</head>\n<body>\n");

        /* Retorna 0 si el archivo es gramaticalmente correcto. */
        yyparse();

        if (cant_errores == 0)
        {
            printf("\n[COMPILACIÓN EXITOSA]: El código .smart no contiene errores.\n");
        }
        else
        {
            printf("\n[FALLA DE COMPILACIÓN]: Se detectaron %d errores sintácticos.\n", cant_errores);
        }

        fclose(yyin);
    }
    else
    {
        /* 1. Nace el HTML oficial con su cabecera */
        FILE *oficial = fopen("rutinas_hogar.html", "wt");
        fprintf(oficial, "<!DOCTYPE html><html lang=\"es\"><head><meta charset=\"UTF-8\"><title>Smart Home</title></head><body>\n");
        fclose(oficial);

        printf("--- Modo Interactivo Smart Home ---\n");
        printf("Escriba sentencias. Tipee 'salir' para finalizar.\n");
        printf("-------------------------------------------------------------\n\n");

        char linea_repl[2048];

        while (1)
        {
            printf("smart-home> ");

            if (!fgets(linea_repl, sizeof(linea_repl), stdin))
                break;
            if (linea_repl[0] == '\n' || linea_repl[0] == '\r')
                continue;

            if (strncmp(linea_repl, "salir", 5) == 0 || strncmp(linea_repl, "quit", 4) == 0)
            {
                printf("Guardando archivo HTML oficial y saliendo...\n");

                oficial = fopen("rutinas_hogar.html", "at"); /* "at" = Append Text (Añadir al final) */
                fprintf(oficial, "\n</body></html>");
                fclose(oficial);
                break;
            }

            /* 2. Apuntamos el puntero global hacia el papel borrador */
            f_html = fopen("borrador.tmp", "wt");
            cant_errores = 0;

            YY_BUFFER_STATE buffer_virtual = yy_scan_string(linea_repl);
            yyparse(); /* Bison escribe todo en borrador.tmp */
            yy_delete_buffer(buffer_virtual);

            fclose(f_html); /* Sellamos el borrador */

            /* 3. EL MOMENTO DE LA VERDAD */
            if (cant_errores == 0)
            {
                /* ES VÁLIDA: Copiamos el borrador adentro del HTML oficial */
                oficial = fopen("rutinas_hogar.html", "at");
                FILE *tmp = fopen("borrador.tmp", "rt");

                int c;
                while ((c = fgetc(tmp)) != EOF)
                {
                    fputc(c, oficial);
                }

                fclose(tmp);
                fclose(oficial);

                printf("  [✔ Sentencia correcta - Guardada en rutinas_hogar.html]\n\n");
            }
            else
            {
                /* HUBO ERROR: No tocamos el archivo oficial */
                printf("  [✘ Error de sintaxis - Línea descartada]\n\n");
            }

            remove("borrador.tmp"); /* Destruimos la evidencia */
        }
    }
}