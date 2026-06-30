/* 
   Parser - Smart Home Interpreter
   UTN FRRe - SSL 2026
 */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/* Declaraciones necesarias para el enlace con el Lexer */
extern int yylex();
extern int linea;
extern char linea_actual[];
extern int cant_errores;
extern FILE *f_html;

void yyerror(const char *s);
%}

/* Union para definir los tipos de datos de los valores semánticos. */
%union {
    char* str;  
}

/* -------- Definicion de Tokens -------- */

%define parse.error verbose     /* Bison reportará errores detallados de sintaxis */

/* ----Tokens de Sensores y Actuadores---- */

%token <str> SENSOR_TEMPERATURA_ID SENSOR_HUMEDAD_ID SENSOR_LUZ_ID 
%token <str> SENSOR_MOVIMIENTO_ID SENSOR_HUMO_ID RELOJ_ID
%token <str> FOCO_ID AIRE_ID PERSIANA_ID CERRADURA_ID ALTAVOZ_ID ALARMA_ID

/* ----Tokens de Control y Lógica---- */
%token TK_WHEN TK_IF TK_THEN TK_ELSE TK_DO TK_END TK_EVERY
%token TK_ESTADO TK_BRILLO TK_COLOR TK_MODO TK_TEMP_OBJ TK_TEMP_OBJETIVO 
%token TK_TEMP_ACT TK_POSICION TK_VOLUMEN TK_MUTE TK_MENSAJE 
%token TK_EMAIL_NOTIF TK_EMAIL TK_ACTIVADA TK_HORA TK_FECHA
%token OP_PUNTO OP_IGUALDAD OP_RELACIONAL ASIGNACION
%token <str> BOOLEANO PORCENTAJE TEMPERATURA ILUMINANCIA TIEMPO
%token <str> VALOR_HORA VALOR_FECHA MODO_AIRE VALOR_COLOR EMAIL TEXTO
%token TK_AND TK_OR TK_NOT

%%

/* --------Definicion de reglas de produccion-------- */
/* Traduccion a HTML y CSS automaticamente */

/* 4.3.1 Regla inicial */
programa: lista_sentencias
        ;

/* 4.3.2 Lista de sentencias */
lista_sentencias: sentencia
    | lista_sentencias sentencia 
    ;

/* 4.3.3 Tipos de sentencia */
sentencia: when
         | every
         | if_sentencia
         | asignacion
         ;

/* 4.3.4 Estructura del bloque WHEN */
when:
    TK_WHEN { 
        fprintf(f_html, "<div class='bloque-evento' style='margin-bottom: 30px;'>\n");
        fprintf(f_html, "  <h3 style='color: #1a73e8;'> -Evento Condicional (WHEN)</h3>\n");
        fprintf(f_html, "  <div class='condicion'>Si se cumple la condicion:</div>\n"); 
    }
    condicion { 
        fprintf(f_html, "  <div style='margin-top: 15px;'>\n");
        fprintf(f_html, "    <h4 style='color: #333;'>Acciones a ejecutar (DO):</h4>\n");
        fprintf(f_html, "    <div class='acciones-lista' style='padding-left: 20px;'>\n"); 
    }
    TK_DO bloque TK_END { 
        fprintf(f_html, "    </div>\n"); /* Cierra .acciones-lista */
        fprintf(f_html, "  </div>\n");
        fprintf(f_html, "</div>\n");   /* Cierra .bloque-evento */
    }
    ;

/* 4.3.5 Estructura del bloque EVERY */
every:
    TK_EVERY {
        fprintf(f_html, "<div class='bloque-every' style='margin-bottom: 30px;'>\n");
        fprintf(f_html, "  <h3 style='color: #f4b400;'> -Evento Iterativo (EVERY)</h3>\n");
    }
    TIEMPO {
        fprintf(f_html, "  <div class='condicion'>Repetir cada: <strong>%s</strong></div>\n", $3);
        fprintf(f_html, "  <div style='margin-top: 15px;'>\n");
        fprintf(f_html, "    <h4 style='color: #333;'>Acciones a ejecutar (DO):</h4>\n");
        fprintf(f_html, "    <div class='acciones-lista' style='padding-left: 20px;'>\n");
        free($3);
    }
    TK_DO bloque TK_END {
        fprintf(f_html, "    </div>\n");
        fprintf(f_html, "  </div>\n");
        fprintf(f_html, "</div>\n");
    }
    ;

/* 4.3.6 Estructura del bloque IF */
if_sentencia: 
      if_inicio then_parte TK_END {
          fprintf(f_html, "  </div>\n"); /* Cierra bloque THEN */
          fprintf(f_html, "</div>\n");   /* Cierra bloque IF */
      }
    | if_inicio then_parte TK_ELSE {
          fprintf(f_html, "  </div>\n"); /* Cierra bloque THEN */
          fprintf(f_html, "  <div style='margin-top: 10px;'><strong>ELSE (Sino):</strong></div>\n");
          fprintf(f_html, "  <div class='bloque-else' style='padding-left: 15px; border-left: 2px solid #ccc; margin-left: 10px;'>\n");
      } 
      bloque TK_END {
          fprintf(f_html, "  </div>\n"); /* Cierra bloque ELSE */
          fprintf(f_html, "</div>\n");   /* Cierra bloque IF */
      }
    ;

/* Sub-reglas auxiliares para compartir el código sin confundir a Bison */
if_inicio:
    TK_IF {
        fprintf(f_html, "<div class='bloque-if' style='background: #e9ecef; padding: 15px; margin-top: 10px; border-left: 4px solid #17a2b8;'>\n");
        fprintf(f_html, "  <h4 style='color: #17a2b8; margin-top: 0;'> Sub-Condición (IF)</h4>\n");
    } 
    condicion
    ;

then_parte:
    TK_THEN {
        fprintf(f_html, "  <div style='margin-top: 10px;'><strong>THEN (Ejecutar):</strong></div>\n");
        fprintf(f_html, "  <div class='bloque-then' style='padding-left: 15px; border-left: 2px solid #ccc; margin-left: 10px;'>\n");
    } 
    bloque
    ;

/* 4.3.7 Reglas de asignación */
asignacion: asignacion_foco
          | asignacion_aire
          | asignacion_persiana
          | asignacion_cerradura
          | asignacion_altavoz
          | asignacion_alarma
          ;

asignacion_foco: 
    FOCO_ID OP_PUNTO TK_COLOR ASIGNACION VALOR_COLOR {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>color</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | FOCO_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>estado</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | FOCO_ID OP_PUNTO TK_BRILLO ASIGNACION PORCENTAJE {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>brillo</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
;

asignacion_aire: 
    AIRE_ID OP_PUNTO TK_TEMP_OBJ ASIGNACION TEMPERATURA {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>temp_obj</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | AIRE_ID OP_PUNTO TK_TEMP_OBJETIVO ASIGNACION TEMPERATURA {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>temp_objetivo</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | AIRE_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>estado</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | AIRE_ID OP_PUNTO TK_MODO ASIGNACION MODO_AIRE {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>modo</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
;

asignacion_persiana: 
    PERSIANA_ID OP_PUNTO TK_POSICION ASIGNACION PORCENTAJE {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>posicion</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | PERSIANA_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>estado</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
;

asignacion_altavoz: 
    ALTAVOZ_ID OP_PUNTO TK_VOLUMEN ASIGNACION PORCENTAJE {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>volumen</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | ALTAVOZ_ID OP_PUNTO TK_MUTE ASIGNACION BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>mute</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | ALTAVOZ_ID OP_PUNTO TK_MENSAJE ASIGNACION TEXTO {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>mensaje</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | ALTAVOZ_ID OP_PUNTO TK_EMAIL_NOTIF ASIGNACION EMAIL {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <ul>\n    <li>email_notif = <a href='mailto:%s'>Contactar a %s</a></li>\n  </ul>\n", $5, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | ALTAVOZ_ID OP_PUNTO TK_EMAIL ASIGNACION EMAIL {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <ul>\n    <li>email = <a href='mailto:%s'>Contactar a %s</a></li>\n  </ul>\n", $5, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
;

asignacion_alarma: 
    ALARMA_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>estado</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | ALARMA_ID OP_PUNTO TK_ACTIVADA ASIGNACION BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>activada</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
;

asignacion_cerradura: 
    CERRADURA_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", $1);
        fprintf(f_html, "  <p>Atributo: <b>estado</b></p>\n");
        fprintf(f_html, "  <ul>\n    <li>%s</li>\n  </ul>\n", $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
;

/* 4.3.8 Estructura de bloque */
bloque: sentencia bloque
      | sentencia
      ;

/* 4.3.9 a 4.3.12 Lógica (OR -> AND -> NOT) */
condicion: expresion_or ;

expresion_or: expresion_and TK_OR expresion_or
            | expresion_and
            ;

expresion_and: expresion_not TK_AND expresion_and
             | expresion_not
             ;

expresion_not: TK_NOT expresion_not
             | primaria_condicion
             ;

/* 4.3.13 Condiciones primarias */
primaria_condicion: comparacion
                  | BOOLEANO
                  ;

/* 4.3.14 Reglas de comparacion */
comparacion: comparacion_temp
           | comparacion_humedad
           | comparacion_luz
           | comparacion_mov
           | comparacion_humo
           | comparacion_reloj
           | comparacion_actuador
           ;

comparacion_temp: 
    SENSOR_TEMPERATURA_ID operador_comp TEMPERATURA {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> valor actual frente a: <span>%s</span>\n", $1, $3);
        fprintf(f_html, "</div>\n");
        free($1); free($3);
    }
;

comparacion_humedad: 
    SENSOR_HUMEDAD_ID operador_comp PORCENTAJE {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> valor actual frente a: <span>%s</span>\n", $1, $3);
        fprintf(f_html, "</div>\n");
        free($1); free($3);
    }
;

comparacion_luz: 
    SENSOR_LUZ_ID operador_comp ILUMINANCIA {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> valor actual frente a: <span>%s</span>\n", $1, $3);
        fprintf(f_html, "</div>\n");
        free($1); free($3);
    }
;

comparacion_mov: 
    SENSOR_MOVIMIENTO_ID OP_IGUALDAD BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> valor actual frente a: <span>%s</span>\n", $1, $3);
        fprintf(f_html, "</div>\n");
        free($1); free($3);
    }
;

comparacion_humo: 
    SENSOR_HUMO_ID OP_IGUALDAD BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> valor actual frente a: <span>%s</span>\n", $1, $3);
        fprintf(f_html, "</div>\n");
        free($1); free($3);
    }
;

comparacion_reloj: 
    RELOJ_ID OP_PUNTO TK_HORA operador_comp VALOR_HORA {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (hora) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | RELOJ_ID OP_PUNTO TK_FECHA operador_comp VALOR_FECHA {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (fecha) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
;

comparacion_actuador: 
    FOCO_ID OP_PUNTO TK_ESTADO OP_IGUALDAD BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (estado) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | FOCO_ID OP_PUNTO TK_BRILLO operador_comp PORCENTAJE {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (brillo) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | FOCO_ID OP_PUNTO TK_COLOR OP_IGUALDAD VALOR_COLOR {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (color) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | AIRE_ID OP_PUNTO TK_ESTADO OP_IGUALDAD BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (estado) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | AIRE_ID OP_PUNTO TK_MODO OP_IGUALDAD MODO_AIRE {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (modo) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | AIRE_ID OP_PUNTO TK_TEMP_OBJ operador_comp TEMPERATURA {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (temp_obj) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | AIRE_ID OP_PUNTO TK_TEMP_ACT operador_comp TEMPERATURA {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (temp_act) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | PERSIANA_ID OP_PUNTO TK_POSICION operador_comp PORCENTAJE {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (posicion) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | CERRADURA_ID OP_PUNTO TK_ESTADO OP_IGUALDAD BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (estado) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | ALTAVOZ_ID OP_PUNTO TK_VOLUMEN operador_comp PORCENTAJE {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (volumen) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | ALTAVOZ_ID OP_PUNTO TK_MUTE OP_IGUALDAD BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (mute) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | ALARMA_ID OP_PUNTO TK_ESTADO OP_IGUALDAD BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (estado) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
  | ALARMA_ID OP_PUNTO TK_ACTIVADA OP_IGUALDAD BOOLEANO {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (activada) valor actual frente a: <span>%s</span>\n", $1, $5);
        fprintf(f_html, "</div>\n");
        free($1); free($5);
    }
;

/* 4.3.16 Operadores auxiliares */
operador_comp: OP_IGUALDAD 
             | OP_RELACIONAL 
             ;


%%

/* --- Implementación de yyerror --- */
void yyerror(const char *s) {
    cant_errores++; /* <--- SUMAMOS EL ERROR REAL */
    printf("[-]: Error sintáctico en línea %d: %s\n", linea, s);
    printf("[-]: Código: %s\n", linea_actual);
}