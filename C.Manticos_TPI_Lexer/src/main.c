#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

/* Funciones externas definidas en el archivo generado por Flex (lex.yy.c) */
extern FILE *yyin;
extern void analizar_cadena_windows(const char *buffer, int longitud);
extern void ejecutar_analisis_archivo();

int main(int argc, char *argv[])
{

#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    /* Si recibimos un argumento (nombre del archivo).smart */
    if (argc == 2)
    {
        yyin = fopen(argv[1], "rt"); // 'rt' abre el archivo en modo texto
        if (yyin == NULL)
        {
            printf("Error: No se pudo abrir el archivo %s\n", argv[1]);
            return -1;
        }
        printf("Analizando archivo: %s\n\n", argv[1]);

        // Ejeutamos al analizador para procesar el archivo
        ejecutar_analisis_archivo();

        fclose(yyin);

        /* Pausa necesaria para que la consola no se cierre
            instantáneamente al terminar la ejecución */
        printf("\n[Presiona ENTER para salir]");
        getchar();
    }
    /* MODO INTERACTIVO: no hay argumentos*/
    else
    {
        printf("------------ Modo Interactivo Smart Home ------------\n");
        printf("Escribe comandos 'quit', 'q' o 'salir' para terminar.\n");
#ifdef _WIN32
        HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
        wchar_t wbuf[1024]; // Buffer para caracteres anchos
        char ubuf[4096];    // Buffer para convertir a UTF-8
        while (1)
        {
            DWORD nread = 0;
            // Lectura directa desde consola Windows
            if (!ReadConsoleW(hIn, wbuf, 1023, &nread, NULL) || nread == 0)
                break;
            wbuf[nread] = L'\0';

            // Conversión de caracteres anchos (UTF-16) a UTF-8 (compatibilidad Flex)
            int ulen = WideCharToMultiByte(CP_UTF8, 0, wbuf, -1, ubuf, sizeof(ubuf), NULL, NULL);
            if (ulen <= 0)
                continue;

            // Procesamos la cadena ingresada línea por línea
            analizar_cadena_windows(ubuf, ulen - 1);
        }
#else
        // MODO LINUX/POSIX: Usamos la entrada estándar directamente.
        yyin = stdin;
        ejecutar_analisis_archivo();
#endif
    }
    return 0;
}