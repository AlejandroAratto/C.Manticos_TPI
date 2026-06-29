/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SENSOR_TEMPERATURA_ID = 258,   /* SENSOR_TEMPERATURA_ID  */
    SENSOR_HUMEDAD_ID = 259,       /* SENSOR_HUMEDAD_ID  */
    SENSOR_LUZ_ID = 260,           /* SENSOR_LUZ_ID  */
    SENSOR_MOVIMIENTO_ID = 261,    /* SENSOR_MOVIMIENTO_ID  */
    SENSOR_HUMO_ID = 262,          /* SENSOR_HUMO_ID  */
    RELOJ_ID = 263,                /* RELOJ_ID  */
    FOCO_ID = 264,                 /* FOCO_ID  */
    AIRE_ID = 265,                 /* AIRE_ID  */
    PERSIANA_ID = 266,             /* PERSIANA_ID  */
    CERRADURA_ID = 267,            /* CERRADURA_ID  */
    ALTAVOZ_ID = 268,              /* ALTAVOZ_ID  */
    ALARMA_ID = 269,               /* ALARMA_ID  */
    TK_WHEN = 270,                 /* TK_WHEN  */
    TK_IF = 271,                   /* TK_IF  */
    TK_THEN = 272,                 /* TK_THEN  */
    TK_ELSE = 273,                 /* TK_ELSE  */
    TK_DO = 274,                   /* TK_DO  */
    TK_END = 275,                  /* TK_END  */
    TK_EVERY = 276,                /* TK_EVERY  */
    TK_ESTADO = 277,               /* TK_ESTADO  */
    TK_BRILLO = 278,               /* TK_BRILLO  */
    TK_COLOR = 279,                /* TK_COLOR  */
    TK_MODO = 280,                 /* TK_MODO  */
    TK_TEMP_OBJ = 281,             /* TK_TEMP_OBJ  */
    TK_TEMP_OBJETIVO = 282,        /* TK_TEMP_OBJETIVO  */
    TK_TEMP_ACT = 283,             /* TK_TEMP_ACT  */
    TK_POSICION = 284,             /* TK_POSICION  */
    TK_VOLUMEN = 285,              /* TK_VOLUMEN  */
    TK_MUTE = 286,                 /* TK_MUTE  */
    TK_MENSAJE = 287,              /* TK_MENSAJE  */
    TK_EMAIL_NOTIF = 288,          /* TK_EMAIL_NOTIF  */
    TK_EMAIL = 289,                /* TK_EMAIL  */
    TK_ACTIVADA = 290,             /* TK_ACTIVADA  */
    TK_HORA = 291,                 /* TK_HORA  */
    TK_FECHA = 292,                /* TK_FECHA  */
    OP_PUNTO = 293,                /* OP_PUNTO  */
    OP_IGUALDAD = 294,             /* OP_IGUALDAD  */
    OP_RELACIONAL = 295,           /* OP_RELACIONAL  */
    ASIGNACION = 296,              /* ASIGNACION  */
    BOOLEANO = 297,                /* BOOLEANO  */
    PORCENTAJE = 298,              /* PORCENTAJE  */
    TEMPERATURA = 299,             /* TEMPERATURA  */
    ILUMINANCIA = 300,             /* ILUMINANCIA  */
    TIEMPO = 301,                  /* TIEMPO  */
    VALOR_HORA = 302,              /* VALOR_HORA  */
    VALOR_FECHA = 303,             /* VALOR_FECHA  */
    MODO_AIRE = 304,               /* MODO_AIRE  */
    VALOR_COLOR = 305,             /* VALOR_COLOR  */
    EMAIL = 306,                   /* EMAIL  */
    TEXTO = 307,                   /* TEXTO  */
    TK_AND = 308,                  /* TK_AND  */
    TK_OR = 309,                   /* TK_OR  */
    TK_NOT = 310                   /* TK_NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "Parser.y"

    char* str;  /* Variable para guardar el lexema (texto) */

#line 123 "Parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
