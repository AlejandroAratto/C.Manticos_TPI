%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int linea; // Asegúrate de tener esto para acceder a la variable del Lexer
void yyerror(const char *s); // <--- SOLO EL PROTOTIPO AQUÍ
%}

/* Tokens de Sensores y Actuadores */
%token SENSOR_TEMPERATURA_ID SENSOR_HUMEDAD_ID SENSOR_LUZ_ID 
%token SENSOR_MOVIMIENTO_ID SENSOR_HUMO_ID RELOJ_ID
%token FOCO_ID AIRE_ID PERSIANA_ID CERRADURA_ID ALTAVOZ_ID ALARMA_ID

/* Tokens de Control y Lógica */
%token TK_WHEN TK_IF TK_THEN TK_ELSE TK_DO TK_END TK_EVERY
%token TK_ESTADO TK_BRILLO TK_COLOR TK_MODO TK_TEMP_OBJ TK_TEMP_OBJETIVO 
%token TK_TEMP_ACT TK_POSICION TK_VOLUMEN TK_MUTE TK_MENSAJE 
%token TK_EMAIL_NOTIF TK_EMAIL TK_ACTIVADA TK_HORA TK_FECHA
%token OP_PUNTO OP_IGUALDAD OP_RELACIONAL ASIGNACION
%token BOOLEANO PORCENTAJE TEMPERATURA ILUMINANCIA TIEMPO
%token VALOR_HORA VALOR_FECHA MODO_AIRE VALOR_COLOR EMAIL TEXTO
%token TK_AND TK_OR TK_NOT

%define parse.error verbose

%%

/* 4.3.1 Regla inicial */
programa: lista_sentencias { printf("Compilacion exitosa: Gramatica valida.\n"); }
        ;

/* 4.3.2 Lista de sentencias */
lista_sentencias: sentencia lista_sentencias
                | sentencia
                ;

/* 4.3.3 Tipos de sentencia */
sentencia: when
         | every
         | if_sentencia
         | asignacion
         ;

/* 4.3.4 Estructura del bloque WHEN */
when: TK_WHEN condicion TK_DO bloque TK_END
    ;

/* 4.3.5 Estructura del bloque EVERY */
every: TK_EVERY TIEMPO TK_DO bloque TK_END
    ;

/* 4.3.6 Estructura del bloque IF */
if_sentencia: TK_IF condicion TK_THEN bloque TK_ELSE bloque TK_END
            | TK_IF condicion TK_THEN bloque TK_END
            ;

/* 4.3.7 Reglas de asignación */
asignacion: asignacion_foco
          | asignacion_aire
          | asignacion_persiana
          | asignacion_cerradura
          | asignacion_altavoz
          | asignacion_alarma
          ;

asignacion_foco: FOCO_ID OP_PUNTO TK_COLOR ASIGNACION VALOR_COLOR
               | FOCO_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO
               | FOCO_ID OP_PUNTO TK_BRILLO ASIGNACION PORCENTAJE
               ;

asignacion_aire: AIRE_ID OP_PUNTO TK_TEMP_OBJ ASIGNACION TEMPERATURA
               | AIRE_ID OP_PUNTO TK_TEMP_OBJETIVO ASIGNACION TEMPERATURA
               | AIRE_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO
               | AIRE_ID OP_PUNTO TK_MODO ASIGNACION MODO_AIRE
               ;

asignacion_persiana: PERSIANA_ID OP_PUNTO TK_POSICION ASIGNACION PORCENTAJE
                   | PERSIANA_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO
                   ;

asignacion_altavoz: ALTAVOZ_ID OP_PUNTO TK_VOLUMEN ASIGNACION PORCENTAJE
                  | ALTAVOZ_ID OP_PUNTO TK_MUTE ASIGNACION BOOLEANO
                  | ALTAVOZ_ID OP_PUNTO TK_MENSAJE ASIGNACION TEXTO
                  | ALTAVOZ_ID OP_PUNTO TK_EMAIL_NOTIF ASIGNACION EMAIL
                  | ALTAVOZ_ID OP_PUNTO TK_EMAIL ASIGNACION EMAIL
                  ;

asignacion_alarma: ALARMA_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO
                 | ALARMA_ID OP_PUNTO TK_ACTIVADA ASIGNACION BOOLEANO
                 ;

asignacion_cerradura: CERRADURA_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO
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

/* 4.3.14 reglas de comparacion */

comparacion: comparacion_temp
           | comparacion_hum
           | comparacion_luz
           | comparacion_mov
           | comparacion_humo
           | comparacion_reloj
           | comparacion_actuador
           ;

comparacion_temp: SENSOR_TEMPERATURA_ID operador_comp TEMPERATURA ;

comparacion_hum: SENSOR_HUMEDAD_ID operador_comp PORCENTAJE ;

comparacion_luz: SENSOR_LUZ_ID operador_comp ILUMINANCIA ;

comparacion_mov: SENSOR_MOVIMIENTO_ID OP_IGUALDAD BOOLEANO ;

comparacion_humo: SENSOR_HUMO_ID OP_IGUALDAD BOOLEANO ;

comparacion_reloj: RELOJ_ID OP_PUNTO TK_HORA operador_comp VALOR_HORA
                 | RELOJ_ID OP_PUNTO TK_FECHA operador_comp VALOR_FECHA
                 ;

comparacion_actuador: FOCO_ID OP_PUNTO TK_ESTADO OP_IGUALDAD BOOLEANO
                    | FOCO_ID OP_PUNTO TK_BRILLO operador_comp PORCENTAJE
                    | FOCO_ID OP_PUNTO TK_COLOR OP_IGUALDAD VALOR_COLOR
                    | AIRE_ID OP_PUNTO TK_ESTADO OP_IGUALDAD BOOLEANO
                    | AIRE_ID OP_PUNTO TK_MODO OP_IGUALDAD MODO_AIRE
                    | AIRE_ID OP_PUNTO TK_TEMP_OBJ operador_comp TEMPERATURA
                    | AIRE_ID OP_PUNTO TK_TEMP_ACT operador_comp TEMPERATURA
                    | PERSIANA_ID OP_PUNTO TK_POSICION operador_comp PORCENTAJE
                    | CERRADURA_ID OP_PUNTO TK_ESTADO OP_IGUALDAD BOOLEANO
                    | ALTAVOZ_ID OP_PUNTO TK_VOLUMEN operador_comp PORCENTAJE
                    | ALTAVOZ_ID OP_PUNTO TK_MUTE OP_IGUALDAD BOOLEANO
                    | ALARMA_ID OP_PUNTO TK_ESTADO OP_IGUALDAD BOOLEANO
                    | ALARMA_ID OP_PUNTO TK_ACTIVADA OP_IGUALDAD BOOLEANO
                    ;

/* 4.3.16 Operadores auxiliares */
operador_comp: OP_IGUALDAD 
             | OP_RELACIONAL 
             ;


%%

/* --- Implementación de yyerror --- */
void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis en la linea %d: %s\n", linea, s);
}