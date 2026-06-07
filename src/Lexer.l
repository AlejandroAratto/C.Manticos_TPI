/* Lexer - Equipo C.mánticos
   UTN FRRE - SSL 2026
*/ 
%option noyywrap
%option case-insensitive
%option 8bit

%{
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#endif

int linea = 1;
%}

/*----- Definiciones Regulares Básicas -----*/
DIGITO      [0-9]
LETRA       [a-zA-Z]
ALFANUM     [a-zA-Z0-9_]

/*----- Literales y Unidades -----*/
TEMPERATURA -?{DIGITO}+(\.{DIGITO}+)?([\xB0\xBA\xF8]|\xC2[\xB0\xBA])"C"
PORCENTAJE  {DIGITO}+"%"
ILUMINANCIA {DIGITO}+"lux"
TIEMPO      {DIGITO}+[smh]
HORA        ([01][0-9]|2[0-3])":"[0-5][0-9]
FECHA       (0[1-9]|[12][0-9]|3[01])"/"(0[1-9]|1[0-2])"/"(19[0-9]{2}|20[0-9]{2})
EMAIL       [a-zA-Z0-9_\.\+\-]+@[a-zA-Z0-9_\.\+\-]+\.[a-zA-Z]{2,4}
TEXTO       \"[^\"]*\"

/*----- Identificadores de Actuadores (Prefijos Obligatorios, sufijos opcionales) -----*/
FOCO        foco(_[a-zA-Z0-9_]+)?
AIRE        aire(_[a-zA-Z0-9_]+)?
PERSIANA    persiana(_[a-zA-Z0-9_]+)?
CERRADURA   cerradura(_[a-zA-Z0-9_]+)?
ALTAVOZ     altavoz(_[a-zA-Z0-9_]+)?
ALARMA      alarma(_[a-zA-Z0-9_]+)?

%%
	/*----- Sección de Reglas ----------------*/

"//".* { /* Ignoramos comentarios de una linea */ }
[ \t\r]+                { /* Ignoramos espacios en blanco */ }
\n                      { linea++; }
"salir"|"quit"|"q"      { printf("Terminando modo interactivo\n"); exit(0); }

	/* Palabras Reservadas */
"WHEN"                  { printf("Token: TK_WHEN | Lexema: WHEN\n"); /* return WHEN; */ }
"IF"                    { printf("Token: TK_IF | Lexema: IF\n"); /* return IF; */ }
"THEN"                  { printf("Token: TK_THEN | Lexema: THEN\n"); /* return THEN; */ }
"ELSE"                  { printf("Token: TK_ELSE | Lexema: ELSE\n"); /* return ELSE; */ }
"DO"                    { printf("Token: TK_DO | Lexema: DO\n"); /* return DO; */ }
"END"                   { printf("Token: TK_END | Lexema: END\n"); /* return END; */ }
"EVERY"                 { printf("Token: TK_EVERY | Lexema: EVERY\n"); /* return EVERY; */ }
"AND"                   { printf("Token: OP_LOGICO | Lexema: AND\n"); /* return AND; */ }
"OR"                    { printf("Token: OP_LOGICO | Lexema: OR\n"); /* return OR; */ }
"NOT"                   { printf("Token: OP_LOGICO | Lexema: NOT\n"); /* return NOT; */ }

	/* Booleanos, Modos y Colores */
"TRUE"|"FALSE"|"ON"|"OFF" { printf("Token: BOOLEANO | Lexema:  %s\n", yytext); /* return BOOLEANO; */ }
"FRIO"|"CALOR"|"VENT"     { printf("Token: MODO_AIRE | Lexema:  %s\n", yytext); /* return MODO_AIRE; */ }
"blanco"|"rojo"|"azul"    { printf("Token: VALOR_COLOR | Lexema:  %s\n", yytext); /* return VALOR_COLOR; */ }

	/* Atributos Dispositivos (Notación de punto) */
".estado"               { printf("Token: ATRIBUTO | Lexema:  estado\n"); /* return ESTADO; */ }
".brillo"               { printf("Token: ATRIBUTO | Lexema:  brillo\n"); /* return BRILLO; */ }
".color"                { printf("Token: ATRIBUTO | Lexema:  color\n"); /* return COLOR; */ }
".modo"                 { printf("Token: ATRIBUTO | Lexema:  modo\n"); /* return MODO; */ }
".temp_obj"             { printf("Token: ATRIBUTO | Lexema:  temp_obj\n"); /* return TEMP_OBJ; */ }
".temp_objetivo"        { printf("Token: ATRIBUTO | Lexema:  temp_objetivo\n"); /* return TEMP_OBJETIVO; */ }
".temp_act"             { printf("Token: ATRIBUTO | Lexema:  temp_act\n"); /* return TEMP_ACT; */ }
".posicion"             { printf("Token: ATRIBUTO | Lexema:  posicion\n"); /* return POSICION; */ }
".volumen"              { printf("Token: ATRIBUTO | Lexema:  volumen\n"); /* return VOLUMEN; */ }
".mute"                 { printf("Token: ATRIBUTO | Lexema:  mute\n"); /* return MUTE; */ }
".mensaje"              { printf("Token: ATRIBUTO | Lexema:  mensaje\n"); /* return MENSAJE; */ }
".email_notif"          { printf("Token: ATRIBUTO | Lexema:  email_notif\n"); /* return EMAIL_NOTIF; */ }
".email"                { printf("Token: ATRIBUTO | Lexema:  email\n"); /* return ATTR_EMAIL; */ }
".activada"             { printf("Token: ATRIBUTO | Lexema:  activada\n"); /* return ACTIVADA; */ }
".hora"                 { printf("Token: ATRIBUTO | Lexema:  hora\n"); /* return ATTR_HORA; */ }
".fecha"                { printf("Token: ATRIBUTO | Lexema:  fecha\n"); /* return ATTR_FECHA; */ }

    /* Sensores (Dispositivos de Entrada) */
"sensor_temp"(_[a-zA-Z0-9_]+)?           { printf("Token: SENSOR_TEMPERATURA_ID | Lexema: %s\n", yytext); }
"sensor_humedad"(_[a-zA-Z0-9_]+)?        { printf("Token: SENSOR_HUMEDAD_ID | Lexema: %s\n", yytext); }
"sensor_luz"(_[a-zA-Z0-9_]+)?            { printf("Token: SENSOR_LUZ_ID | Lexema: %s\n", yytext); }
"sensor_movimiento"(_[a-zA-Z0-9_]+)?     { printf("Token: SENSOR_MOVIMIENTO_ID | Lexema: %s\n", yytext); }
"sensor_humo"(_[a-zA-Z0-9_]+)?           { printf("Token: SENSOR_HUMO_ID | Lexema: %s\n", yytext); }
"reloj"(_[a-zA-Z0-9_]+)?                 { printf("Token: RELOJ_ID | Lexema: %s\n", yytext); }

	/* Actuadores (Dispositivos de Salida) */
{FOCO}                  { printf("Token: FOCO_ID | Lexema: %s\n", yytext); }
{AIRE}                  { printf("Token: AIRE_ID | Lexema: %s\n", yytext); }
{PERSIANA}              { printf("Token: PERSIANA_ID | Lexema: %s\n", yytext); }
{CERRADURA}             { printf("Token: CERRADURA_ID | Lexema: %s\n", yytext); }
{ALTAVOZ}               { printf("Token: ALTAVOZ_ID | Lexema: %s\n", yytext); }
{ALARMA}                { printf("Token: ALARMA_ID | Lexema: %s\n", yytext); }

	/* Literales y Unidades Compuestas */
{TEMPERATURA} { 
    DWORD written;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    char msg[512];
    int len = snprintf(msg, sizeof(msg), "Token: TEMPERATURA | Lexema: %s\n", yytext);
    WriteConsoleA(hOut, msg, len, &written, NULL);
}
{PORCENTAJE}            { printf("Token: PORCENTAJE | Lexema: %s\n", yytext); }
{ILUMINANCIA}           { printf("Token: ILUMINANCIA | Lexema: %s\n", yytext); }
{TIEMPO}                { printf("Token: TIEMPO | Lexema: %s\n", yytext); }
{HORA}                  { printf("Token: VALOR_HORA | Lexema: %s\n", yytext); }
{FECHA}                 { printf("Token: VALOR_FECHA | Lexema: %s\n", yytext); }
{EMAIL}                 { printf("Token: EMAIL | Lexema: %s\n", yytext); }
{TEXTO}                 { printf("Token: TEXTO | Lexema: %s\n", yytext); }

	/* Operadores y Delimitadores */
"=="|"!="               { printf("Token: OP_IGUALDAD | Lexema: %s\n", yytext); }
">"|"<"|">="|"<="       { printf("Token: OP_RELACIONAL | Lexema: %s\n", yytext); }
"="                     { printf("Token: ASIGNACION | Lexema: =\n"); }

    /* Control de errores léxicos unificado */
[a-zA-Z0-9_]+|[\xC2-\xDF][\x80-\xBF]|. { 
#ifdef _WIN32
    DWORD written;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    char msg[512];
    int len = snprintf(msg, sizeof(msg), "TOKEN_ERROR: %s (En linea %d)\n", yytext, linea);
    WriteConsoleA(hOut, msg, len, &written, NULL);
#else
    printf("TOKEN_ERROR: %s (En linea %d)\n", yytext, linea);
#endif
}

%%
	/*----- Sección de Procedimientos --------*/

int main(int argc, char *argv[]) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    setlocale(LC_ALL, "");

    if (argc == 2) {
        yyin = fopen(argv[1], "rt");
        if (yyin == NULL) {
            printf("Error: El archivo %s no se puede abrir\n", argv[1]);
            exit(-1);
        }
        printf("Analizando archivo: %s\n\n", argv[1]);
        yylex();
    } else {
        printf("--- Modo Interactivo Smart Home ---\n");
        printf("Escribe comandos o escribe 'quit', 'q' o 'salir' para terminar.\n");

#ifdef _WIN32
        HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
        wchar_t wbuf[1024];
        char    ubuf[4096];
        SetConsoleOutputCP(65001);
        while (1) {
            DWORD nread = 0;
            if (!ReadConsoleW(hIn, wbuf, 1023, &nread, NULL) || nread == 0)
                break;
            wbuf[nread] = L'\0';

            /* Convertir UTF-16 a UTF-8 */
            int ulen = WideCharToMultiByte(CP_UTF8, 0, wbuf, -1,
                                           ubuf, sizeof(ubuf), NULL, NULL);
            if (ulen <= 0) continue;
            /* ulen incluye el \0 final, lo descartamos */
            ulen--;

            /* Pasarle el buffer a Flex */
            YY_BUFFER_STATE bs = yy_scan_bytes(ubuf, ulen);
            yylex();
            yy_delete_buffer(bs);
        }
#else
        yyin = stdin;
        yylex();
#endif
    }

    return 0;
}