/* Lexer - Equipo C.mánticos
   UTN FRRE - 2026
*/ 

/* Configuraciones */
/* Se finaliza al llegar al EOF */
%option noyywrap                
/* Hace que el lenguaje no distinga entre mayusculas y minusculas */
%option case-insensitive        
/* Soporte para caracteres extendidos */
%option 8bit                    

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parser.tab.h" /* definiciones de tokens generadas por Bison */

#define MAX_LINE_SIZE 1024

extern char linea_actual[MAX_LINE_SIZE]; /* Traemos la variable global del main para errores*/

#define YY_USER_ACTION \
    if (strchr(linea_actual, '\n')) linea_actual[0] = '\0'; \
    strncat(linea_actual, yytext, MAX_LINE_SIZE - strlen(linea_actual) - 1);

int linea = 1;
%}

    /*---------- Definiciones Regulares ----------*/
DIGITO      [0-9]
LETRA       [a-zA-Z]
ALFANUM     [a-zA-Z0-9_]

    /*----- Rangos -----*/
PORCENTAJE  ([0-9]|[1-9][0-9]|100)"%"
ILUMINANCIA ([0-9]{1,3}|1000)"lux"
HORA        ([01][0-9]|2[0-3])":"[0-5][0-9]
FECHA       (0[1-9]|[12][0-9]|3[01])\/(0[1-9]|1[0-2])\/(19[0-9]{2}|20[0-9]{2})

    /*----- otros -----*/
TEMPERATURA -?{DIGITO}+(\.{DIGITO}+)?"\302\260""C"
TIEMPO      {DIGITO}+[smh]
EMAIL       [a-zA-Z0-9_\.\+\-]+@[a-zA-Z0-9_\.\+\-]+\.[a-zA-Z]{2,4}
TEXTO       \"[^\"]*\"

    /*----- Identificadores de Actuadores -----*/
FOCO        foco(_[a-zA-Z0-9_]+)?
AIRE        aire(_[a-zA-Z0-9_]+)?
PERSIANA    persiana(_[a-zA-Z0-9_]+)?
CERRADURA   cerradura(_[a-zA-Z0-9_]+)?
ALTAVOZ     altavoz(_[a-zA-Z0-9_]+)?
ALARMA      alarma(_[a-zA-Z0-9_]+)?

%%

    /*---------- Sección de Reglas ----------*/

"//".*                  { /* Ignoramos comentarios */ }
[ \t\r]+                { /* Ignoramos espacios en blanco */ }
\n                      { linea++; }
"salir"|"quit"|"q"      { printf("Terminando intérprete Smart Home.\n"); exit(0); }

    /*----- Palabras Reservadas -----*/
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

    /*----- Constantes y valores -----*/
"TRUE"|"FALSE"|"ON"|"OFF" { yylval.str = strdup(yytext); return BOOLEANO; }
"FRIO"|"CALOR"|"VENT"     { yylval.str = strdup(yytext); return MODO_AIRE; }
"blanco"|"rojo"|"azul"    { yylval.str = strdup(yytext); return VALOR_COLOR; }

    /*----- Atributos -----*/
"estado"               { return TK_ESTADO; }
"brillo"               { return TK_BRILLO; }
"color"                { return TK_COLOR; }
"modo"                 { return TK_MODO; }
"temp_obj"             { return TK_TEMP_OBJ; }
"temp_objetivo"        { return TK_TEMP_OBJETIVO; }
"temp_act"             { return TK_TEMP_ACT; }
"posicion"             { return TK_POSICION; }
"volumen"              { return TK_VOLUMEN; }
"mute"                 { return TK_MUTE; }
"mensaje"              { return TK_MENSAJE; }
"email_notif"          { return TK_EMAIL_NOTIF; }
"email"                { return TK_EMAIL; }
"activada"             { return TK_ACTIVADA; }
"hora"                 { return TK_HORA; }
"fecha"                { return TK_FECHA; }

    /*----- Identificadores de Sensores -----*/
"sensor_temp"(_[a-zA-Z0-9_]+)?           { yylval.str = strdup(yytext); return SENSOR_TEMPERATURA_ID; }
"sensor_humedad"(_[a-zA-Z0-9_]+)?        { yylval.str = strdup(yytext); return SENSOR_HUMEDAD_ID; }
"sensor_luz"(_[a-zA-Z0-9_]+)?            { yylval.str = strdup(yytext); return SENSOR_LUZ_ID; }
"sensor_movimiento"(_[a-zA-Z0-9_]+)?     { yylval.str = strdup(yytext); return SENSOR_MOVIMIENTO_ID; }
"sensor_humo"(_[a-zA-Z0-9_]+)?           { yylval.str = strdup(yytext); return SENSOR_HUMO_ID; }
"reloj"(_[a-zA-Z0-9_]+)?                 { yylval.str = strdup(yytext); return RELOJ_ID; }

    /*----- Actuadores  -----*/
{FOCO}                  { yylval.str = strdup(yytext); return FOCO_ID; }
{AIRE}                  { yylval.str = strdup(yytext); return AIRE_ID; }
{PERSIANA}              { yylval.str = strdup(yytext); return PERSIANA_ID; }
{CERRADURA}             { yylval.str = strdup(yytext); return CERRADURA_ID; }
{ALTAVOZ}               { yylval.str = strdup(yytext); return ALTAVOZ_ID; }
{ALARMA}                { yylval.str = strdup(yytext); return ALARMA_ID; }

    /*----- Tipos de datos -----*/
{TEMPERATURA}           { yylval.str = strdup(yytext); return TEMPERATURA; }
{PORCENTAJE}            { yylval.str = strdup(yytext); return PORCENTAJE; }
{ILUMINANCIA}           { yylval.str = strdup(yytext); return ILUMINANCIA; }
{TIEMPO}                { yylval.str = strdup(yytext); return TIEMPO; }
{HORA}                  { yylval.str = strdup(yytext); return VALOR_HORA; }
{FECHA}                 { yylval.str = strdup(yytext); return VALOR_FECHA; }
{EMAIL}                 { yylval.str = strdup(yytext); return EMAIL; }
{TEXTO}                 { yylval.str = strdup(yytext); return TEXTO; }

    /*----- Operadores -----*/
"."                     { return OP_PUNTO; }
"=="|"!="               { return OP_IGUALDAD; }
">"|"<"|">="|"<="       { return OP_RELACIONAL; }
"="                     { return ASIGNACION; }

    /*----- Control de errores léxicos unificado -----*/
[a-zA-Z0-9_]+|[\xC2-\xDF][\x80-\xBF]|. { 
    printf("LINEA %d - ERROR: %s\n", linea, yytext);
}

%%