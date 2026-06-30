#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

/* Vinculamos las variables y puntos de entrada globales de Flex y Bison */
extern FILE *yyin;
extern int yyparse();
int cant_errores = 0;

/* para el modo interactivo */
typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(const char *str);
extern void yy_delete_buffer(YY_BUFFER_STATE b);

FILE *f_html = NULL;
#define MAX_LINE_SIZE 1024
char linea_actual[MAX_LINE_SIZE] = {0};

/* Valida que el archivo recibido tenga extension .smart */
int es_archivo_valido(const char *nombre)
{
    const char *punto = strrchr(nombre, '.');
    if (punto == NULL)
    {
        return 0; /* No tiene extension */
    }
    return strcmp(punto, ".smart") == 0;
}

int main(int argc, char *argv[])
{
#ifdef _WIN32
    /* Configuración exclusiva si se corre bajo Windows nativo */
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    if (argc == 2)
    {
        if (!es_archivo_valido(argv[1]))
        {
            printf("Error: El archivo '%s' no tiene extension .smart\n", argv[1]);
            return -1;
        }

        yyin = fopen(argv[1], "rt");
        if (yyin == NULL)
        {
            printf("Error: No se pudo abrir el archivo de prueba '%s'\n", argv[1]);
            return -1;
        }

        /* creacion de varaible para nombre dinamico del archivo html */
        char nombre_html[1024];
        strncpy(nombre_html, argv[1], sizeof(nombre_html) - 1);
        nombre_html[sizeof(nombre_html) - 1] = '\0';
        char *punto = strrchr(nombre_html, '.');

        if (punto != NULL)
        {
            *punto = '\0'; /* Cortamos la palabra ahí "rutina.smart" -> "rutina" */
        }
        strcat(nombre_html, ".html"); /* Le pegamos la nueva extension: "rutina" -> "rutina.html" */

        /* parcer crea archivo temporal */
        f_html = fopen("borrador.tmp", "wt");
        if (f_html == NULL)
        {
            printf("Error: No se pudo crear el bufer temporal de salida.\n");
            fclose(yyin);
            return -1;
        }

        printf("--------------------------------------------------------\n");
        printf("Iniciando Analizador Sintáctico de: %s\n", argv[1]);
        printf("--------------------------------------------------------\n");

        fprintf(f_html, "<!DOCTYPE html>\n<html lang=\"es\">\n<head>\n");
        fprintf(f_html, "  <meta charset=\"UTF-8\">\n  <title>Smart Home - Interprete</title>\n</head>\n<body>\n");

        cant_errores = 0;

        yyparse(); // analisis sintactico

        fclose(f_html); // para liberar recursos

        /* ver si no hay errores traducir finalmente al html  */
        if (cant_errores == 0)
        {

            FILE *oficial = fopen(nombre_html, "wt");
            FILE *tmp = fopen("borrador.tmp", "rt");

            if (oficial != NULL && tmp != NULL)
            {
                int c;
                while ((c = fgetc(tmp)) != EOF)
                {
                    fputc(c, oficial);
                }

                fprintf(oficial, "\n</body>\n</html>");

                fclose(tmp);
                fclose(oficial);

                printf("\n[COMPILACION EXITOSA]: Traducido con exito a '%s'.\n", nombre_html);
            }
            else
            {
                printf("\n[ERROR]: Al crear archivo HTML\n");
            }
        }
        else
        {
            printf("\n[FALLA DE COMPILACION]: Se detectaron %d errores sintácticos.\n", cant_errores);
            printf("[INFO]: El archivo '%s' no fue generado.\n", nombre_html);
        }

        remove("borrador.tmp");
        fclose(yyin);
    }
    else
    {
        /* Nace el HTML oficial con su cabecera */
        FILE *oficial = fopen("Resultado.html", "wt");
        fprintf(oficial, "<!DOCTYPE html><html lang=\"es\"><head><meta charset=\"UTF-8\"><title>Smart Home - Interprete</title></head><body>\n");
        fclose(oficial);

        printf("------------------ Modo Interactivo Smart Home ------------------\n");
        printf("Escriba sentencias y precionar ENTER para evaluar. Tipee 'salir' para finalizar.\n");
        printf("Tipee 'salir' o 'quit' para finalizar.\n");
        printf("-----------------------------------------------------------------\n\n");

        char linea_repl[2048]; /* mem temporal para lo que ingrase el usuario */

        while (1)
        {
            printf("> ");

            if (!fgets(linea_repl, sizeof(linea_repl), stdin)) /* lectura segura */
                break;

            if (linea_repl[0] == '\n' || linea_repl[0] == '\r') /* filtrado de espacios vacios */
                continue;

            /* interpretacion de salida */
            if (strncmp(linea_repl, "salir", 5) == 0 || strncmp(linea_repl, "quit", 4) == 0)
            {
                printf("Generando archivo HTML y saliendo...\n");

                oficial = fopen("Resultado.html", "at"); /* "at" = Append Text (Añadir al final) */
                fprintf(oficial, "\n</body></html>");
                fclose(oficial);
                break;
            }

            /* tolerancia a fallos */
            f_html = fopen("borrador.tmp", "wt");
            cant_errores = 0;

            /* memoria virtual para el escaneo de ingreso*/
            YY_BUFFER_STATE buffer_virtual = yy_scan_string(linea_repl);
            yyparse(); /* Bison escribe todo en borrador.tmp */
            yy_delete_buffer(buffer_virtual);

            fclose(f_html);

            /* Verificacion si hay errores o no copiar en el html */
            if (cant_errores == 0)
            {
                /* si es correcto, copiamos el borrador adentro del HTML oficial */
                oficial = fopen("Resultado.html", "at");
                FILE *tmp = fopen("borrador.tmp", "rt");

                int c;
                while ((c = fgetc(tmp)) != EOF)
                {
                    fputc(c, oficial);
                }

                fclose(tmp);
                fclose(oficial);

                printf("  [Sentencia correcta --> Traduccion a HTML]\n\n");
            }
            else
            {
                printf("  [Error de sintaxis - Linea descartada]\n\n");
            }

            remove("borrador.tmp");
        }
    }
}