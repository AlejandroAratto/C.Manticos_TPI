#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#endif

/* Importamos únicamente punteros estándar de C */
extern FILE *yyin;
extern void analizar_cadena_windows(const char *buffer, int longitud);
extern void ejecutar_analisis_archivo();

int main(int argc, char *argv[])
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    if (argc == 2)
    {
        yyin = fopen(argv[1], "rt");
        if (yyin == NULL)
        {
            printf("Error: No se pudo abrir el archivo %s\n", argv[1]);
            return -1;
        }
        printf("Analizando archivo: %s\n\n", argv[1]);

        ejecutar_analisis_archivo();

        fclose(yyin);
#ifdef _WIN32
        printf("\n[Presiona ENTER para salir]");
        getchar();
#endif
    }
    else
    {
        printf("--- Modo Interactivo Smart Home ---\n");
        printf("Escribe comandos 'quit', 'q' o 'salir' para terminar.\n");
#ifdef _WIN32
        HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
        wchar_t wbuf[1024];
        char ubuf[4096];
        while (1)
        {
            DWORD nread = 0;
            if (!ReadConsoleW(hIn, wbuf, 1023, &nread, NULL) || nread == 0)
                break;
            wbuf[nread] = L'\0';
            int ulen = WideCharToMultiByte(CP_UTF8, 0, wbuf, -1, ubuf, sizeof(ubuf), NULL, NULL);
            if (ulen <= 0)
                continue;

            analizar_cadena_windows(ubuf, ulen - 1);
        }
#else
        yyin = stdin;
        ejecutar_analisis_archivo();
#endif
    }
    return 0;
}