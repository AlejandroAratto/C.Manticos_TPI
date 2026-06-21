/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "Parser.y"

#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int linea;
extern char linea_actual[];
extern int cant_errores;
extern FILE *f_html;
int cant_errores = 0;

void yyerror(const char *s);

#line 84 "Parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "Parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SENSOR_TEMPERATURA_ID = 3,      /* SENSOR_TEMPERATURA_ID  */
  YYSYMBOL_SENSOR_HUMEDAD_ID = 4,          /* SENSOR_HUMEDAD_ID  */
  YYSYMBOL_SENSOR_LUZ_ID = 5,              /* SENSOR_LUZ_ID  */
  YYSYMBOL_SENSOR_MOVIMIENTO_ID = 6,       /* SENSOR_MOVIMIENTO_ID  */
  YYSYMBOL_SENSOR_HUMO_ID = 7,             /* SENSOR_HUMO_ID  */
  YYSYMBOL_RELOJ_ID = 8,                   /* RELOJ_ID  */
  YYSYMBOL_FOCO_ID = 9,                    /* FOCO_ID  */
  YYSYMBOL_AIRE_ID = 10,                   /* AIRE_ID  */
  YYSYMBOL_PERSIANA_ID = 11,               /* PERSIANA_ID  */
  YYSYMBOL_CERRADURA_ID = 12,              /* CERRADURA_ID  */
  YYSYMBOL_ALTAVOZ_ID = 13,                /* ALTAVOZ_ID  */
  YYSYMBOL_ALARMA_ID = 14,                 /* ALARMA_ID  */
  YYSYMBOL_TK_WHEN = 15,                   /* TK_WHEN  */
  YYSYMBOL_TK_IF = 16,                     /* TK_IF  */
  YYSYMBOL_TK_THEN = 17,                   /* TK_THEN  */
  YYSYMBOL_TK_ELSE = 18,                   /* TK_ELSE  */
  YYSYMBOL_TK_DO = 19,                     /* TK_DO  */
  YYSYMBOL_TK_END = 20,                    /* TK_END  */
  YYSYMBOL_TK_EVERY = 21,                  /* TK_EVERY  */
  YYSYMBOL_TK_ESTADO = 22,                 /* TK_ESTADO  */
  YYSYMBOL_TK_BRILLO = 23,                 /* TK_BRILLO  */
  YYSYMBOL_TK_COLOR = 24,                  /* TK_COLOR  */
  YYSYMBOL_TK_MODO = 25,                   /* TK_MODO  */
  YYSYMBOL_TK_TEMP_OBJ = 26,               /* TK_TEMP_OBJ  */
  YYSYMBOL_TK_TEMP_OBJETIVO = 27,          /* TK_TEMP_OBJETIVO  */
  YYSYMBOL_TK_TEMP_ACT = 28,               /* TK_TEMP_ACT  */
  YYSYMBOL_TK_POSICION = 29,               /* TK_POSICION  */
  YYSYMBOL_TK_VOLUMEN = 30,                /* TK_VOLUMEN  */
  YYSYMBOL_TK_MUTE = 31,                   /* TK_MUTE  */
  YYSYMBOL_TK_MENSAJE = 32,                /* TK_MENSAJE  */
  YYSYMBOL_TK_EMAIL_NOTIF = 33,            /* TK_EMAIL_NOTIF  */
  YYSYMBOL_TK_EMAIL = 34,                  /* TK_EMAIL  */
  YYSYMBOL_TK_ACTIVADA = 35,               /* TK_ACTIVADA  */
  YYSYMBOL_TK_HORA = 36,                   /* TK_HORA  */
  YYSYMBOL_TK_FECHA = 37,                  /* TK_FECHA  */
  YYSYMBOL_OP_PUNTO = 38,                  /* OP_PUNTO  */
  YYSYMBOL_OP_IGUALDAD = 39,               /* OP_IGUALDAD  */
  YYSYMBOL_OP_RELACIONAL = 40,             /* OP_RELACIONAL  */
  YYSYMBOL_ASIGNACION = 41,                /* ASIGNACION  */
  YYSYMBOL_BOOLEANO = 42,                  /* BOOLEANO  */
  YYSYMBOL_PORCENTAJE = 43,                /* PORCENTAJE  */
  YYSYMBOL_TEMPERATURA = 44,               /* TEMPERATURA  */
  YYSYMBOL_ILUMINANCIA = 45,               /* ILUMINANCIA  */
  YYSYMBOL_TIEMPO = 46,                    /* TIEMPO  */
  YYSYMBOL_VALOR_HORA = 47,                /* VALOR_HORA  */
  YYSYMBOL_VALOR_FECHA = 48,               /* VALOR_FECHA  */
  YYSYMBOL_MODO_AIRE = 49,                 /* MODO_AIRE  */
  YYSYMBOL_VALOR_COLOR = 50,               /* VALOR_COLOR  */
  YYSYMBOL_EMAIL = 51,                     /* EMAIL  */
  YYSYMBOL_TEXTO = 52,                     /* TEXTO  */
  YYSYMBOL_TK_AND = 53,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 54,                     /* TK_OR  */
  YYSYMBOL_TK_NOT = 55,                    /* TK_NOT  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_programa = 57,                  /* programa  */
  YYSYMBOL_lista_sentencias = 58,          /* lista_sentencias  */
  YYSYMBOL_sentencia = 59,                 /* sentencia  */
  YYSYMBOL_when = 60,                      /* when  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_every = 63,                     /* every  */
  YYSYMBOL_64_3 = 64,                      /* $@3  */
  YYSYMBOL_65_4 = 65,                      /* $@4  */
  YYSYMBOL_if_sentencia = 66,              /* if_sentencia  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_if_inicio = 68,                 /* if_inicio  */
  YYSYMBOL_69_6 = 69,                      /* $@6  */
  YYSYMBOL_then_parte = 70,                /* then_parte  */
  YYSYMBOL_71_7 = 71,                      /* $@7  */
  YYSYMBOL_asignacion = 72,                /* asignacion  */
  YYSYMBOL_asignacion_foco = 73,           /* asignacion_foco  */
  YYSYMBOL_asignacion_aire = 74,           /* asignacion_aire  */
  YYSYMBOL_asignacion_persiana = 75,       /* asignacion_persiana  */
  YYSYMBOL_asignacion_altavoz = 76,        /* asignacion_altavoz  */
  YYSYMBOL_asignacion_alarma = 77,         /* asignacion_alarma  */
  YYSYMBOL_asignacion_cerradura = 78,      /* asignacion_cerradura  */
  YYSYMBOL_bloque = 79,                    /* bloque  */
  YYSYMBOL_condicion = 80,                 /* condicion  */
  YYSYMBOL_expresion_or = 81,              /* expresion_or  */
  YYSYMBOL_expresion_and = 82,             /* expresion_and  */
  YYSYMBOL_expresion_not = 83,             /* expresion_not  */
  YYSYMBOL_primaria_condicion = 84,        /* primaria_condicion  */
  YYSYMBOL_comparacion = 85,               /* comparacion  */
  YYSYMBOL_comparacion_temp = 86,          /* comparacion_temp  */
  YYSYMBOL_comparacion_hum = 87,           /* comparacion_hum  */
  YYSYMBOL_comparacion_luz = 88,           /* comparacion_luz  */
  YYSYMBOL_comparacion_mov = 89,           /* comparacion_mov  */
  YYSYMBOL_comparacion_humo = 90,          /* comparacion_humo  */
  YYSYMBOL_comparacion_reloj = 91,         /* comparacion_reloj  */
  YYSYMBOL_comparacion_actuador = 92,      /* comparacion_actuador  */
  YYSYMBOL_operador_comp = 93              /* operador_comp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    43,    43,    47,    48,    49,    53,    60,    61,    62,
      63,    68,    73,    68,    87,    91,    87,   108,   112,   112,
     125,   125,   133,   133,   141,   142,   143,   144,   145,   146,
     150,   157,   164,   174,   181,   188,   195,   205,   212,   222,
     229,   236,   243,   250,   260,   267,   277,   287,   288,   292,
     294,   295,   298,   299,   302,   303,   307,   308,   312,   313,
     314,   315,   316,   317,   318,   322,   331,   340,   349,   358,
     367,   373,   382,   388,   394,   400,   406,   412,   418,   424,
     430,   436,   442,   448,   454,   463,   464
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"",
  "SENSOR_TEMPERATURA_ID", "SENSOR_HUMEDAD_ID", "SENSOR_LUZ_ID",
  "SENSOR_MOVIMIENTO_ID", "SENSOR_HUMO_ID", "RELOJ_ID", "FOCO_ID",
  "AIRE_ID", "PERSIANA_ID", "CERRADURA_ID", "ALTAVOZ_ID", "ALARMA_ID",
  "TK_WHEN", "TK_IF", "TK_THEN", "TK_ELSE", "TK_DO", "TK_END", "TK_EVERY",
  "TK_ESTADO", "TK_BRILLO", "TK_COLOR", "TK_MODO", "TK_TEMP_OBJ",
  "TK_TEMP_OBJETIVO", "TK_TEMP_ACT", "TK_POSICION", "TK_VOLUMEN",
  "TK_MUTE", "TK_MENSAJE", "TK_EMAIL_NOTIF", "TK_EMAIL", "TK_ACTIVADA",
  "TK_HORA", "TK_FECHA", "OP_PUNTO", "OP_IGUALDAD", "OP_RELACIONAL",
  "ASIGNACION", "BOOLEANO", "PORCENTAJE", "TEMPERATURA", "ILUMINANCIA",
  "TIEMPO", "VALOR_HORA", "VALOR_FECHA", "MODO_AIRE", "VALOR_COLOR",
  "EMAIL", "TEXTO", "TK_AND", "TK_OR", "TK_NOT", "$accept", "programa",
  "lista_sentencias", "sentencia", "when", "$@1", "$@2", "every", "$@3",
  "$@4", "if_sentencia", "$@5", "if_inicio", "$@6", "then_parte", "$@7",
  "asignacion", "asignacion_foco", "asignacion_aire",
  "asignacion_persiana", "asignacion_altavoz", "asignacion_alarma",
  "asignacion_cerradura", "bloque", "condicion", "expresion_or",
  "expresion_and", "expresion_not", "primaria_condicion", "comparacion",
  "comparacion_temp", "comparacion_hum", "comparacion_luz",
  "comparacion_mov", "comparacion_humo", "comparacion_reloj",
  "comparacion_actuador", "operador_comp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      35,  -110,   -13,    19,    29,    30,    32,    38,  -110,  -110,
    -110,    80,    18,  -110,  -110,  -110,  -110,    77,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,    64,    52,    -6,    74,    51,
       0,    -1,    -1,    56,  -110,  -110,  -110,  -110,    20,    57,
      63,    65,    66,    68,    69,    70,    71,    72,    73,    75,
      76,    78,    79,    81,    82,    83,   -19,   -19,   -19,    58,
      86,    88,    89,    90,    91,    92,    93,    94,  -110,    -1,
    -110,  -110,    54,    62,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,    50,  -110,  -110,    95,    96,
      55,    98,    84,    97,    99,   100,   101,   103,   104,   106,
     102,    85,    87,   107,   108,  -110,  -110,   109,   112,   111,
     110,   115,     6,    67,    47,   105,   113,    22,     2,  -110,
     127,    -1,    -1,   132,    50,  -110,    50,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,   -19,
     -19,   119,   -19,   120,   121,   122,   -19,   -19,   -19,   123,
     -19,   124,   125,   126,    50,  -110,  -110,    50,  -110,   146,
     128,   129,   130,   131,   117,   134,   133,   135,   136,   138,
     141,   142,   144,   145,   147,   148,   149,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     0,     0,     0,     0,     0,     0,    11,    20,
      14,     0,     0,     3,     7,     8,     9,     0,    10,    24,
      25,    26,    28,    29,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     6,     4,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
      12,    49,    51,    53,    55,    56,    58,    59,    60,    61,
      62,    63,    64,    21,    15,     0,    18,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,    48,    23,     0,    31,    32,    30,
      35,    36,    33,    34,    38,    37,    46,    39,    40,    41,
      42,    43,    44,    45,    65,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    52,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    13,    16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -110,    14,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -109,   139,    -3,    48,   137,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,   -57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,   124,    14,    31,   120,    15,    33,   123,
      16,   126,    17,    32,    38,    85,    18,    19,    20,    21,
      22,    23,    24,   125,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,   107
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   109,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    13,   168,    46,   169,    -2,    35,
     105,   106,    54,    47,   162,    25,    36,     2,     3,     4,
       5,     6,     7,     8,     9,    55,     1,   163,    86,    10,
      87,    68,   149,   150,     2,     3,     4,     5,     6,     7,
       8,     9,   160,   161,    69,   185,    10,    26,   186,     2,
       3,     4,     5,     6,     7,     8,     9,    27,    28,   154,
      29,    10,   155,   156,    42,   157,    30,    43,    44,    45,
      34,    49,    50,    51,    52,    53,    39,    40,    41,   151,
     152,   153,   170,   171,    37,   173,    48,   110,    88,   177,
     178,   179,    84,   181,    89,   129,    90,    91,   121,    92,
      93,    94,    95,    96,    97,   122,    98,    99,   165,   100,
     101,     0,   102,   103,   104,   111,   112,   113,   114,   115,
     116,   117,   118,   131,   158,   159,   140,   127,   141,   128,
     130,   132,   134,   133,   135,   136,   164,   137,   138,   142,
     143,   167,   147,   144,   139,   145,   146,   148,   172,   174,
     175,   176,   180,   182,   183,   184,   187,   192,   203,   204,
     166,    83,   190,     0,   191,   188,   193,   189,     0,   195,
     196,   197,   194,   198,     0,   199,   200,   201,     0,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119
};

static const yytype_int16 yycheck[] =
{
      57,    58,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,   124,    22,   126,     0,     1,
      39,    40,    22,    29,    22,    38,    12,     9,    10,    11,
      12,    13,    14,    15,    16,    35,     1,    35,    18,    21,
      20,    42,    36,    37,     9,    10,    11,    12,    13,    14,
      15,    16,    30,    31,    55,   164,    21,    38,   167,     9,
      10,    11,    12,    13,    14,    15,    16,    38,    38,    22,
      38,    21,    25,    26,    22,    28,    38,    25,    26,    27,
       0,    30,    31,    32,    33,    34,    22,    23,    24,    22,
      23,    24,   149,   150,    17,   152,    22,    39,    41,   156,
     157,   158,    46,   160,    41,    50,    41,    41,    54,    41,
      41,    41,    41,    41,    41,    53,    41,    41,   121,    41,
      41,    -1,    41,    41,    41,    39,    38,    38,    38,    38,
      38,    38,    38,    49,    29,    22,    51,    42,    51,    43,
      42,    44,    42,    44,    43,    42,    19,    43,    42,    42,
      42,    19,    42,    44,    52,    43,    45,    42,    39,    39,
      39,    39,    39,    39,    39,    39,    20,    50,    20,    20,
     122,    32,    42,    -1,    43,    47,    42,    48,    -1,    44,
      44,    43,    49,    42,    -1,    43,    42,    42,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     9,    10,    11,    12,    13,    14,    15,    16,
      21,    57,    58,    59,    60,    63,    66,    68,    72,    73,
      74,    75,    76,    77,    78,    38,    38,    38,    38,    38,
      38,    61,    69,    64,     0,     1,    59,    17,    70,    22,
      23,    24,    22,    25,    26,    27,    22,    29,    22,    30,
      31,    32,    33,    34,    22,    35,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    42,    55,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    80,    46,    71,    18,    20,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    39,    40,    93,    93,    93,
      39,    39,    38,    38,    38,    38,    38,    38,    38,    83,
      62,    54,    53,    65,    59,    79,    67,    42,    43,    50,
      42,    49,    44,    44,    42,    43,    42,    43,    42,    52,
      51,    51,    42,    42,    44,    43,    45,    42,    42,    36,
      37,    22,    23,    24,    22,    25,    26,    28,    29,    22,
      30,    31,    22,    35,    19,    81,    82,    19,    79,    79,
      93,    93,    39,    93,    39,    39,    39,    93,    93,    93,
      39,    93,    39,    39,    39,    79,    79,    20,    47,    48,
      42,    43,    50,    42,    49,    44,    44,    43,    42,    43,
      42,    42,    42,    20,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    58,    59,    59,    59,
      59,    61,    62,    60,    64,    65,    63,    66,    67,    66,
      69,    68,    71,    70,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    77,    77,    78,    79,    79,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    86,    87,    88,    89,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     1,     1,
       1,     0,     0,     7,     0,     0,     7,     3,     0,     6,
       0,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     2,     1,     1,
       3,     1,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* lista_sentencias: error  */
#line 49 "Parser.y"
            { 
        yyerrok;     /* Le dice a Bison 'ya me recuperé del error' */
        yyclearin;   /* Limpia el token problemático para no ciclarse */
      }
#line 1578 "Parser.tab.c"
    break;

  case 6: /* lista_sentencias: lista_sentencias error  */
#line 53 "Parser.y"
                             { 
        yyerrok; 
        yyclearin; 
      }
#line 1587 "Parser.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 68 "Parser.y"
            { 
        fprintf(f_html, "<div class='bloque-evento' style='margin-bottom: 30px;'>\n");
        fprintf(f_html, "  <h3 style='color: #1a73e8;'>⚡ Evento Condicional (WHEN)</h3>\n");
        fprintf(f_html, "  <div class='condicion'>Si se cumple la condicion:</div>\n"); 
    }
#line 1597 "Parser.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 73 "Parser.y"
              { 
        fprintf(f_html, "  <div style='margin-top: 15px;'>\n");
        fprintf(f_html, "    <h4 style='color: #333;'>Acciones a ejecutar (DO):</h4>\n");
        fprintf(f_html, "    <div class='acciones-lista' style='padding-left: 20px;'>\n"); 
    }
#line 1607 "Parser.tab.c"
    break;

  case 13: /* when: TK_WHEN $@1 condicion $@2 TK_DO bloque TK_END  */
#line 78 "Parser.y"
                        { 
        fprintf(f_html, "    </div>\n"); /* Cierra .acciones-lista */
        fprintf(f_html, "  </div>\n");
        fprintf(f_html, "</div>\n");   /* Cierra .bloque-evento */
    }
#line 1617 "Parser.tab.c"
    break;

  case 14: /* $@3: %empty  */
#line 87 "Parser.y"
             {
        fprintf(f_html, "<div class='bloque-every' style='margin-bottom: 30px;'>\n");
        fprintf(f_html, "  <h3 style='color: #f4b400;'>⏱️ Evento Iterativo (EVERY)</h3>\n");
    }
#line 1626 "Parser.tab.c"
    break;

  case 15: /* $@4: %empty  */
#line 91 "Parser.y"
           {
        /* ¡AHORA ES $3! (porque el bloque {} de arriba cuenta como $2) */
        fprintf(f_html, "  <div class='condicion'>Repetir cada: <strong>%s</strong></div>\n", (yyvsp[0].str));
        fprintf(f_html, "  <div style='margin-top: 15px;'>\n");
        fprintf(f_html, "    <h4 style='color: #333;'>Acciones a ejecutar (DO):</h4>\n");
        fprintf(f_html, "    <div class='acciones-lista' style='padding-left: 20px;'>\n");
        free((yyvsp[0].str));
    }
#line 1639 "Parser.tab.c"
    break;

  case 16: /* every: TK_EVERY $@3 TIEMPO $@4 TK_DO bloque TK_END  */
#line 99 "Parser.y"
                        {
        fprintf(f_html, "    </div>\n");
        fprintf(f_html, "  </div>\n");
        fprintf(f_html, "</div>\n");
    }
#line 1649 "Parser.tab.c"
    break;

  case 17: /* if_sentencia: if_inicio then_parte TK_END  */
#line 108 "Parser.y"
                                  {
          fprintf(f_html, "  </div>\n"); /* Cierra bloque THEN */
          fprintf(f_html, "</div>\n");   /* Cierra bloque IF */
      }
#line 1658 "Parser.tab.c"
    break;

  case 18: /* $@5: %empty  */
#line 112 "Parser.y"
                                   {
          fprintf(f_html, "  </div>\n"); /* Cierra bloque THEN */
          fprintf(f_html, "  <div style='margin-top: 10px;'><strong>ELSE (Sino):</strong></div>\n");
          fprintf(f_html, "  <div class='bloque-else' style='padding-left: 15px; border-left: 2px solid #ccc; margin-left: 10px;'>\n");
      }
#line 1668 "Parser.tab.c"
    break;

  case 19: /* if_sentencia: if_inicio then_parte TK_ELSE $@5 bloque TK_END  */
#line 117 "Parser.y"
                    {
          fprintf(f_html, "  </div>\n"); /* Cierra bloque ELSE */
          fprintf(f_html, "</div>\n");   /* Cierra bloque IF */
      }
#line 1677 "Parser.tab.c"
    break;

  case 20: /* $@6: %empty  */
#line 125 "Parser.y"
          {
        fprintf(f_html, "<div class='bloque-if' style='background: #e9ecef; padding: 15px; margin-top: 10px; border-left: 4px solid #17a2b8;'>\n");
        fprintf(f_html, "  <h4 style='color: #17a2b8; margin-top: 0;'>❓ Sub-Condición (IF)</h4>\n");
    }
#line 1686 "Parser.tab.c"
    break;

  case 22: /* $@7: %empty  */
#line 133 "Parser.y"
            {
        fprintf(f_html, "  <div style='margin-top: 10px;'><strong>THEN (Ejecutar):</strong></div>\n");
        fprintf(f_html, "  <div class='bloque-then' style='padding-left: 15px; border-left: 2px solid #ccc; margin-left: 10px;'>\n");
    }
#line 1695 "Parser.tab.c"
    break;

  case 30: /* asignacion_foco: FOCO_ID OP_PUNTO TK_COLOR ASIGNACION VALOR_COLOR  */
#line 150 "Parser.y"
                                                     {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>color = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1707 "Parser.tab.c"
    break;

  case 31: /* asignacion_foco: FOCO_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO  */
#line 157 "Parser.y"
                                                   {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>estado = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1719 "Parser.tab.c"
    break;

  case 32: /* asignacion_foco: FOCO_ID OP_PUNTO TK_BRILLO ASIGNACION PORCENTAJE  */
#line 164 "Parser.y"
                                                     {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>brillo = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1731 "Parser.tab.c"
    break;

  case 33: /* asignacion_aire: AIRE_ID OP_PUNTO TK_TEMP_OBJ ASIGNACION TEMPERATURA  */
#line 174 "Parser.y"
                                                        {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>temp_obj = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1743 "Parser.tab.c"
    break;

  case 34: /* asignacion_aire: AIRE_ID OP_PUNTO TK_TEMP_OBJETIVO ASIGNACION TEMPERATURA  */
#line 181 "Parser.y"
                                                             {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>temp_objetivo = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1755 "Parser.tab.c"
    break;

  case 35: /* asignacion_aire: AIRE_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO  */
#line 188 "Parser.y"
                                                   {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>estado = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1767 "Parser.tab.c"
    break;

  case 36: /* asignacion_aire: AIRE_ID OP_PUNTO TK_MODO ASIGNACION MODO_AIRE  */
#line 195 "Parser.y"
                                                  {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>modo = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1779 "Parser.tab.c"
    break;

  case 37: /* asignacion_persiana: PERSIANA_ID OP_PUNTO TK_POSICION ASIGNACION PORCENTAJE  */
#line 205 "Parser.y"
                                                           {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>posicion = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1791 "Parser.tab.c"
    break;

  case 38: /* asignacion_persiana: PERSIANA_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO  */
#line 212 "Parser.y"
                                                       {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>estado = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1803 "Parser.tab.c"
    break;

  case 39: /* asignacion_altavoz: ALTAVOZ_ID OP_PUNTO TK_VOLUMEN ASIGNACION PORCENTAJE  */
#line 222 "Parser.y"
                                                         {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>volumen = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1815 "Parser.tab.c"
    break;

  case 40: /* asignacion_altavoz: ALTAVOZ_ID OP_PUNTO TK_MUTE ASIGNACION BOOLEANO  */
#line 229 "Parser.y"
                                                    {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>mute = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1827 "Parser.tab.c"
    break;

  case 41: /* asignacion_altavoz: ALTAVOZ_ID OP_PUNTO TK_MENSAJE ASIGNACION TEXTO  */
#line 236 "Parser.y"
                                                    {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>mensaje = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1839 "Parser.tab.c"
    break;

  case 42: /* asignacion_altavoz: ALTAVOZ_ID OP_PUNTO TK_EMAIL_NOTIF ASIGNACION EMAIL  */
#line 243 "Parser.y"
                                                        {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>email_notif = <a href='mailto:%s'>Contactar a %s</a></li>\n  </ul>\n", (yyvsp[0].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1851 "Parser.tab.c"
    break;

  case 43: /* asignacion_altavoz: ALTAVOZ_ID OP_PUNTO TK_EMAIL ASIGNACION EMAIL  */
#line 250 "Parser.y"
                                                  {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>email = <a href='mailto:%s'>Contactar a %s</a></li>\n  </ul>\n", (yyvsp[0].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1863 "Parser.tab.c"
    break;

  case 44: /* asignacion_alarma: ALARMA_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO  */
#line 260 "Parser.y"
                                                     {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>estado = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1875 "Parser.tab.c"
    break;

  case 45: /* asignacion_alarma: ALARMA_ID OP_PUNTO TK_ACTIVADA ASIGNACION BOOLEANO  */
#line 267 "Parser.y"
                                                       {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>activada = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1887 "Parser.tab.c"
    break;

  case 46: /* asignacion_cerradura: CERRADURA_ID OP_PUNTO TK_ESTADO ASIGNACION BOOLEANO  */
#line 277 "Parser.y"
                                                        {
        fprintf(f_html, "<div style='border: 1px solid gray; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label>\n", (yyvsp[-4].str));
        fprintf(f_html, "  <ul>\n    <li>estado = %s</li>\n  </ul>\n", (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1899 "Parser.tab.c"
    break;

  case 65: /* comparacion_temp: SENSOR_TEMPERATURA_ID operador_comp TEMPERATURA  */
#line 322 "Parser.y"
                                                    {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> valor actual frente a: <span>%s</span>\n", (yyvsp[-2].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1910 "Parser.tab.c"
    break;

  case 66: /* comparacion_hum: SENSOR_HUMEDAD_ID operador_comp PORCENTAJE  */
#line 331 "Parser.y"
                                               {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> valor actual frente a: <span>%s</span>\n", (yyvsp[-2].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1921 "Parser.tab.c"
    break;

  case 67: /* comparacion_luz: SENSOR_LUZ_ID operador_comp ILUMINANCIA  */
#line 340 "Parser.y"
                                            {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> valor actual frente a: <span>%s</span>\n", (yyvsp[-2].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1932 "Parser.tab.c"
    break;

  case 68: /* comparacion_mov: SENSOR_MOVIMIENTO_ID OP_IGUALDAD BOOLEANO  */
#line 349 "Parser.y"
                                              {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> valor actual frente a: <span>%s</span>\n", (yyvsp[-2].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1943 "Parser.tab.c"
    break;

  case 69: /* comparacion_humo: SENSOR_HUMO_ID OP_IGUALDAD BOOLEANO  */
#line 358 "Parser.y"
                                        {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> valor actual frente a: <span>%s</span>\n", (yyvsp[-2].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1954 "Parser.tab.c"
    break;

  case 70: /* comparacion_reloj: RELOJ_ID OP_PUNTO TK_HORA operador_comp VALOR_HORA  */
#line 367 "Parser.y"
                                                       {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (hora) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1965 "Parser.tab.c"
    break;

  case 71: /* comparacion_reloj: RELOJ_ID OP_PUNTO TK_FECHA operador_comp VALOR_FECHA  */
#line 373 "Parser.y"
                                                         {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (fecha) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1976 "Parser.tab.c"
    break;

  case 72: /* comparacion_actuador: FOCO_ID OP_PUNTO TK_ESTADO OP_IGUALDAD BOOLEANO  */
#line 382 "Parser.y"
                                                    {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (estado) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1987 "Parser.tab.c"
    break;

  case 73: /* comparacion_actuador: FOCO_ID OP_PUNTO TK_BRILLO operador_comp PORCENTAJE  */
#line 388 "Parser.y"
                                                        {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (brillo) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 1998 "Parser.tab.c"
    break;

  case 74: /* comparacion_actuador: FOCO_ID OP_PUNTO TK_COLOR OP_IGUALDAD VALOR_COLOR  */
#line 394 "Parser.y"
                                                      {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (color) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 2009 "Parser.tab.c"
    break;

  case 75: /* comparacion_actuador: AIRE_ID OP_PUNTO TK_ESTADO OP_IGUALDAD BOOLEANO  */
#line 400 "Parser.y"
                                                    {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (estado) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 2020 "Parser.tab.c"
    break;

  case 76: /* comparacion_actuador: AIRE_ID OP_PUNTO TK_MODO OP_IGUALDAD MODO_AIRE  */
#line 406 "Parser.y"
                                                   {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (modo) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 2031 "Parser.tab.c"
    break;

  case 77: /* comparacion_actuador: AIRE_ID OP_PUNTO TK_TEMP_OBJ operador_comp TEMPERATURA  */
#line 412 "Parser.y"
                                                           {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (temp_obj) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 2042 "Parser.tab.c"
    break;

  case 78: /* comparacion_actuador: AIRE_ID OP_PUNTO TK_TEMP_ACT operador_comp TEMPERATURA  */
#line 418 "Parser.y"
                                                           {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (temp_act) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 2053 "Parser.tab.c"
    break;

  case 79: /* comparacion_actuador: PERSIANA_ID OP_PUNTO TK_POSICION operador_comp PORCENTAJE  */
#line 424 "Parser.y"
                                                              {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (posicion) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 2064 "Parser.tab.c"
    break;

  case 80: /* comparacion_actuador: CERRADURA_ID OP_PUNTO TK_ESTADO OP_IGUALDAD BOOLEANO  */
#line 430 "Parser.y"
                                                         {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (estado) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 2075 "Parser.tab.c"
    break;

  case 81: /* comparacion_actuador: ALTAVOZ_ID OP_PUNTO TK_VOLUMEN operador_comp PORCENTAJE  */
#line 436 "Parser.y"
                                                            {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (volumen) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 2086 "Parser.tab.c"
    break;

  case 82: /* comparacion_actuador: ALTAVOZ_ID OP_PUNTO TK_MUTE OP_IGUALDAD BOOLEANO  */
#line 442 "Parser.y"
                                                     {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (mute) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 2097 "Parser.tab.c"
    break;

  case 83: /* comparacion_actuador: ALARMA_ID OP_PUNTO TK_ESTADO OP_IGUALDAD BOOLEANO  */
#line 448 "Parser.y"
                                                      {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (estado) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 2108 "Parser.tab.c"
    break;

  case 84: /* comparacion_actuador: ALARMA_ID OP_PUNTO TK_ACTIVADA OP_IGUALDAD BOOLEANO  */
#line 454 "Parser.y"
                                                        {
        fprintf(f_html, "<div style='border: 1px solid green; padding: 20px; margin-bottom: 10px;'>\n");
        fprintf(f_html, "  <label><b>%s</b></label> (activada) valor actual frente a: <span>%s</span>\n", (yyvsp[-4].str), (yyvsp[0].str));
        fprintf(f_html, "</div>\n");
        free((yyvsp[-4].str)); free((yyvsp[0].str));
    }
#line 2119 "Parser.tab.c"
    break;


#line 2123 "Parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 468 "Parser.y"


/* --- Implementación de yyerror --- */
void yyerror(const char *s) {
    cant_errores++;
    fprintf(stderr, "\n[X] Error de sintaxis en la linea %d: %s\n", linea, s);
    fprintf(stderr, "    Codigo: %s\n", linea_actual); // Imprime la línea problemática
}
