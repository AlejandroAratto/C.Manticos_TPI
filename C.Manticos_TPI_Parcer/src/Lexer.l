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

#include "Parser.tab.h"

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
"WHEN"                  { return TK_WHEN; }
"IF"                    { return TK_IF; }
"THEN"                  { return TK_THEN; }
"ELSE"                  { return TK_ELSE; }
"DO"                    { return TK_DO; }
"END"                   { return TK_END; }
"EVERY"                 { return TK_EVERY; }
"AND"                   { return TK_AND; }
"OR"                    { return TK_OR; }
"NOT"                   { return TK_NOT; }

	/* Booleanos, Modos y Colores */
"TRUE"|"FALSE"|"ON"|"OFF" { return BOOLEANO; }
"FRIO"|"CALOR"|"VENT"     { return MODO_AIRE; }
"blanco"|"rojo"|"azul"    { return VALOR_COLOR; }

	/* Atributos Dispositivos (Notación de punto) */
"estado"                { return TK_ESTADO; }
"brillo"                { return TK_BRILLO; }
"color"                 { return TK_COLOR; }
"modo"                  { return TK_MODO; }
"temp_obj"              { return TK_TEMP_OBJ; }
"temp_objetivo"         { return TK_TEMP_OBJETIVO; }
"temp_act"              { return TK_TEMP_ACT; }
"posicion"              { return TK_POSICION; }
"volumen"               { return TK_VOLUMEN; }
"mute"                  { return TK_MUTE; }
"mensaje"               { return TK_MENSAJE; }
"email_notif"           { return TK_EMAIL_NOTIF; }
"email"                 { return TK_EMAIL; }
"activada"              { return TK_ACTIVADA; }
"hora"                  { return TK_HORA; }
"fecha"                 { return TK_FECHA; }

    /* Sensores (Dispositivos de Entrada) */
"sensor_temp"(_[a-zA-Z0-9_]+)?          { return SENSOR_TEMPERATURA_ID; }
"sensor_humedad"(_[a-zA-Z0-9_]+)?       { return SENSOR_HUMEDAD_ID; }
"sensor_luz"(_[a-zA-Z0-9_]+)?           { return SENSOR_LUZ_ID; }
"sensor_movimiento"(_[a-zA-Z0-9_]+)?    { return SENSOR_MOVIMIENTO_ID; }
"sensor_humo"(_[a-zA-Z0-9_]+)?          { return SENSOR_HUMO_ID; }
"reloj"(_[a-zA-Z0-9_]+)?                { return RELOJ_ID; }

	/* Actuadores (Dispositivos de Salida) */
{FOCO}                    { return FOCO_ID; }
{AIRE}                    { return AIRE_ID; }
{PERSIANA}                { return PERSIANA_ID; }
{CERRADURA}               { return CERRADURA_ID; }
{ALTAVOZ}                 { return ALTAVOZ_ID; }
{ALARMA}                  { return ALARMA_ID; }

	/* Literales y Unidades Compuestas */
{TEMPERATURA}             { return TEMPERATURA; }
{PORCENTAJE}              { return PORCENTAJE; }
{ILUMINANCIA}             { return ILUMINANCIA; }
{TIEMPO}                  { return TIEMPO; }
{HORA}                    { return VALOR_HORA; }
{FECHA}                   { return VALOR_FECHA; }
{EMAIL}                   { return EMAIL; }
{TEXTO}                   { return TEXTO; }

	/* Operadores y Delimitadores */
"."                     { return OP_PUNTO; }
"=="|"!="               { return OP_IGUALDAD; }
">"|"<"|">="|"<="       { return OP_RELACIONAL; }
"="                     { return ASIGNACION; }

    /* Control de errores léxicos unificado */
[a-zA-Z0-9_]+|[\xC2-\xDF][\x80-\xBF]|. { 
#ifdef _WIN32
    /* Tu código de Windows para errores... */
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