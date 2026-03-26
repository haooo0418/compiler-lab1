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
#line 1 "syntax.y"

#include <stdio.h>
#include <stdlib.h>
#include "treenode.h"
extern int yylex();
extern int yyparse();
extern TreeNode *root;
extern int error_num;
extern int yylineno;

static int pending_syntax_error = 0;
static void yyerror_missing(const char *what, int lineno) {
    pending_syntax_error = 0;

    fprintf(stderr, "Error type B at Line %d: Missing \"%s\".\n", lineno, what);
    error_num++;
}
void yyerror(const char *msg) {
    if (msg && strcmp(msg, "syntax error") == 0) {
        pending_syntax_error = 1;
        return;
    }

    /* 其它错误照常打印 */
    pending_syntax_error = 0;
    fprintf(stderr, "Error type B at Line %d: %s\n", yylineno, msg ? msg : "syntax error");
    error_num++;
}

#line 101 "syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMI = 3,                       /* SEMI  */
  YYSYMBOL_COMMA = 4,                      /* COMMA  */
  YYSYMBOL_ASSIGNOP = 5,                   /* ASSIGNOP  */
  YYSYMBOL_RELOP = 6,                      /* RELOP  */
  YYSYMBOL_PLUS = 7,                       /* PLUS  */
  YYSYMBOL_MINUS = 8,                      /* MINUS  */
  YYSYMBOL_STAR = 9,                       /* STAR  */
  YYSYMBOL_DIV = 10,                       /* DIV  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_DOT = 13,                       /* DOT  */
  YYSYMBOL_NOT = 14,                       /* NOT  */
  YYSYMBOL_TYPE = 15,                      /* TYPE  */
  YYSYMBOL_ID = 16,                        /* ID  */
  YYSYMBOL_INT = 17,                       /* INT  */
  YYSYMBOL_FLOAT = 18,                     /* FLOAT  */
  YYSYMBOL_STRUCT = 19,                    /* STRUCT  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_LP = 24,                        /* LP  */
  YYSYMBOL_RP = 25,                        /* RP  */
  YYSYMBOL_LB = 26,                        /* LB  */
  YYSYMBOL_RB = 27,                        /* RB  */
  YYSYMBOL_LC = 28,                        /* LC  */
  YYSYMBOL_RC = 29,                        /* RC  */
  YYSYMBOL_UMINUS = 30,                    /* UMINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 31,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_Program = 33,                   /* Program  */
  YYSYMBOL_ExtDefList = 34,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 35,                    /* ExtDef  */
  YYSYMBOL_Specifier = 36,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 37,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 38,                    /* OptTag  */
  YYSYMBOL_Tag = 39,                       /* Tag  */
  YYSYMBOL_ExtDecList = 40,                /* ExtDecList  */
  YYSYMBOL_Dec = 41,                       /* Dec  */
  YYSYMBOL_CompSt = 42,                    /* CompSt  */
  YYSYMBOL_FunDec = 43,                    /* FunDec  */
  YYSYMBOL_VarList = 44,                   /* VarList  */
  YYSYMBOL_ParamDec = 45,                  /* ParamDec  */
  YYSYMBOL_VarDec = 46,                    /* VarDec  */
  YYSYMBOL_DefList = 47,                   /* DefList  */
  YYSYMBOL_Def = 48,                       /* Def  */
  YYSYMBOL_DecList = 49,                   /* DecList  */
  YYSYMBOL_StmtList = 50,                  /* StmtList  */
  YYSYMBOL_Stmt = 51,                      /* Stmt  */
  YYSYMBOL_Exp = 52                        /* Exp  */
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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   281

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    72,    78,    84,    90,    97,   107,   112,
     120,   129,   138,   143,   149,   157,   162,   172,   177,   188,
     199,   206,   218,   225,   233,   242,   247,   258,   264,   270,
     280,   285,   295,   301,   304,   311,   317,   323,   330,   339,
     353,   364,   379,   393,   406,   411,   416,   421,   428,   434,
     441,   446,   451,   456,   461,   466,   471,   476,   481,   487,
     496,   509
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMI", "COMMA",
  "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV", "AND", "OR", "DOT",
  "NOT", "TYPE", "ID", "INT", "FLOAT", "STRUCT", "RETURN", "IF", "ELSE",
  "WHILE", "LP", "RP", "LB", "RB", "LC", "RC", "UMINUS", "LOWER_THAN_ELSE",
  "$accept", "Program", "ExtDefList", "ExtDef", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "ExtDecList", "Dec", "CompSt",
  "FunDec", "VarList", "ParamDec", "VarDec", "DefList", "Def", "DecList",
  "StmtList", "Stmt", "Exp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-39)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      41,   -41,    -7,    10,   -41,    41,    33,   -41,   -12,    -9,
     -41,   -41,   -41,   -41,     7,    30,    44,    23,    -1,    41,
     124,   -41,    42,    41,   -41,   251,    40,    42,    35,    41,
     -41,    42,    51,    74,   -41,   -41,     6,   251,   251,   -41,
     -41,   -41,   251,   210,    53,    77,    79,   -41,   -41,    58,
     -41,    41,    88,   251,    71,    84,   -41,   108,     6,   104,
     -11,   -11,   157,   251,   251,   251,   251,   251,   251,   251,
     251,   131,   128,   -41,    42,   -41,   -41,     6,   115,   251,
     251,   -41,   -41,   -41,   -41,   210,   247,    62,    62,   -11,
     -11,   125,   240,   -41,     5,   148,   -41,   -41,   -41,   179,
     188,   -41,   -41,   -41,   217,   217,    45,    93,   -41,   118,
      69,   126,   217,   217,   -41,   217,   -41,   -41,   -41
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     8,    13,     0,     2,     4,     0,     9,    14,     0,
      11,     1,     3,     5,    25,     0,    15,     0,    17,    28,
       0,     6,     0,    28,     7,     0,     0,     0,     0,    28,
      20,     0,     0,    23,    25,    16,     0,     0,     0,    44,
      45,    46,     0,    18,     0,    30,     0,    10,    27,    24,
      21,     0,     0,     0,     0,     0,    36,     0,     0,     0,
      58,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    29,    22,     0,     0,     0,
       0,    19,    32,    35,    57,    49,    52,    53,    54,    55,
      56,    50,    51,    47,     0,     0,    31,    34,    37,     0,
       0,    61,    60,    48,     0,     0,     0,     0,    43,     0,
       0,     0,     0,     0,    40,     0,    41,    39,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,   145,   -41,     1,   -41,   -41,   -41,   149,   -24,
     155,   -41,   122,   -41,   146,   -18,   -41,   102,   -40,   166,
     -25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    27,     7,     9,    10,    15,    16,
      56,    17,    32,    33,    18,    28,    29,    46,    57,    58,
      59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      43,     6,    71,    45,    25,    36,     6,    52,   101,     8,
      11,    48,    60,    61,    37,    72,   -12,    62,    82,    19,
      38,    31,    39,    40,    41,    26,    53,    54,    78,    55,
      42,    20,   102,    21,    23,   -33,    13,    97,    85,    86,
      87,    88,    89,    90,    91,    92,   109,    95,    22,    14,
      45,    23,    31,   -38,    99,   100,     1,    44,    34,   -38,
       2,   -38,   -38,   -38,    47,   -38,   -38,   110,   -38,   -38,
     113,    67,    68,   -38,   -38,    71,    50,    37,    51,   107,
      73,    74,    75,    38,    26,    39,    40,    41,    72,    53,
      54,    77,    55,    42,   111,    79,    83,    23,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    83,    80,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    98,    72,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    94,
      72,    64,    65,    66,    67,    68,    37,    81,    71,     1,
     112,    72,    38,     2,    39,    40,    41,    93,   115,    30,
      12,    72,    42,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    35,    24,    76,    72,   103,    96,    49,     0,     0,
       0,     0,    84,    72,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,   104,    72,     0,     0,     0,     0,
       0,     0,     0,   105,    72,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    37,     0,     0,     0,     0,
       0,    38,     0,    39,    40,    41,    72,    53,    54,     0,
      55,    42,     0,     0,     0,    23,    64,    65,    66,    67,
      68,    69,     0,    71,    65,    66,    67,    68,     0,    37,
      71,     0,     0,     0,     0,    38,    72,    39,    40,    41,
     106,   108,     0,    72,     0,    42,   114,     0,   116,   117,
       0,   118
};

static const yytype_int8 yycheck[] =
{
      25,     0,    13,    27,     5,    23,     5,     1,     3,    16,
       0,    29,    37,    38,     8,    26,    28,    42,    58,    28,
      14,    20,    16,    17,    18,    26,    20,    21,    53,    23,
      24,    24,    27,     3,    28,    29,     3,    77,    63,    64,
      65,    66,    67,    68,    69,    70,     1,    72,     4,    16,
      74,    28,    51,     8,    79,    80,    15,    17,    16,    14,
      19,    16,    17,    18,    29,    20,    21,    22,    23,    24,
       1,     9,    10,    28,    29,    13,    25,     8,     4,   104,
      27,     4,     3,    14,    26,    16,    17,    18,    26,    20,
      21,     3,    23,    24,     1,    24,     3,    28,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     3,    24,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     3,    26,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     1,
      26,     6,     7,     8,     9,    10,     8,    29,    13,    15,
      22,    26,    14,    19,    16,    17,    18,    16,    22,    25,
       5,    26,    24,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    22,    17,    51,    26,    27,    74,    31,    -1,    -1,
      -1,    -1,    25,    26,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    14,    -1,    16,    17,    18,    26,    20,    21,    -1,
      23,    24,    -1,    -1,    -1,    28,     6,     7,     8,     9,
      10,    11,    -1,    13,     7,     8,     9,    10,    -1,     8,
      13,    -1,    -1,    -1,    -1,    14,    26,    16,    17,    18,
     104,   105,    -1,    26,    -1,    24,   110,    -1,   112,   113,
      -1,   115
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    19,    33,    34,    35,    36,    37,    16,    38,
      39,     0,    34,     3,    16,    40,    41,    43,    46,    28,
      24,     3,     4,    28,    42,     5,    26,    36,    47,    48,
      25,    36,    44,    45,    16,    40,    47,     8,    14,    16,
      17,    18,    24,    52,    17,    41,    49,    29,    47,    46,
      25,     4,     1,    20,    21,    23,    42,    50,    51,    52,
      52,    52,    52,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    26,    27,     4,     3,    44,     3,    52,    24,
      24,    29,    50,     3,    25,    52,    52,    52,    52,    52,
      52,    52,    52,    16,     1,    52,    49,    50,     3,    52,
      52,     3,    27,    27,    25,    25,    51,    52,    51,     1,
      22,     1,    22,     1,    51,    22,    51,    51,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    36,    36,
      37,    37,    38,    38,    39,    40,    40,    41,    41,    42,
      43,    43,    44,    44,    45,    46,    46,    47,    47,    48,
      49,    49,    50,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     3,     3,     1,     1,
       5,     2,     1,     0,     1,     1,     3,     1,     3,     4,
       3,     4,     3,     1,     2,     1,     4,     2,     0,     3,
       1,     3,     2,     0,     3,     2,     1,     3,     5,     8,
       7,     8,     8,     5,     1,     1,     1,     3,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       4,     4
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: ExtDefList  */
#line 65 "syntax.y"
                 {
        root = createTreeNode("Program", 1, "");
        insertChild(root, (yyvsp[0].node));
      }
#line 1365 "syntax.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 72 "syntax.y"
                        {
        TreeNode *p = createTreeNode("ExtDefList", (yyvsp[-1].node)->lineno, "");
        insertChild(p, (yyvsp[-1].node));
        if ((yyvsp[0].node)) insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1376 "syntax.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 78 "syntax.y"
                  {
        (yyval.node) = NULL;
      }
#line 1384 "syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier SEMI  */
#line 84 "syntax.y"
                     {
        TreeNode *p = createTreeNode("ExtDef", (yyvsp[-1].node)->lineno, "");
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1395 "syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier ExtDecList SEMI  */
#line 90 "syntax.y"
                                {
        TreeNode *p = createTreeNode("ExtDef", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1407 "syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 97 "syntax.y"
                              {
        TreeNode *p = createTreeNode("ExtDef", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1419 "syntax.tab.c"
    break;

  case 8: /* Specifier: TYPE  */
#line 107 "syntax.y"
           {
        TreeNode *p = createTreeNode("Specifier", yylineno, "");
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1429 "syntax.tab.c"
    break;

  case 9: /* Specifier: StructSpecifier  */
#line 112 "syntax.y"
                      {
        TreeNode *p = createTreeNode("Specifier", (yyvsp[0].node)->lineno, "");
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1439 "syntax.tab.c"
    break;

  case 10: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 120 "syntax.y"
                                  {
        TreeNode *p = createTreeNode("StructSpecifier", (yyvsp[-4].node)->lineno, "");
        insertChild(p, (yyvsp[-4].node));
        insertChild(p, (yyvsp[-3].node));
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1453 "syntax.tab.c"
    break;

  case 11: /* StructSpecifier: STRUCT Tag  */
#line 129 "syntax.y"
                 {
        TreeNode *p = createTreeNode("StructSpecifier", (yyvsp[-1].node)->lineno, "");
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1464 "syntax.tab.c"
    break;

  case 12: /* OptTag: ID  */
#line 138 "syntax.y"
         {
        TreeNode *p = createTreeNode("OptTag", (yyvsp[0].node)->lineno, "");
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1474 "syntax.tab.c"
    break;

  case 13: /* OptTag: %empty  */
#line 143 "syntax.y"
                  {
        (yyval.node) = createTreeNode("OptTag", yylineno, "");
      }
#line 1482 "syntax.tab.c"
    break;

  case 14: /* Tag: ID  */
#line 149 "syntax.y"
         {
        TreeNode *p = createTreeNode("Tag", (yyvsp[0].node)->lineno, "");
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1492 "syntax.tab.c"
    break;

  case 15: /* ExtDecList: Dec  */
#line 157 "syntax.y"
          {
        TreeNode *p = createTreeNode("ExtDecList", (yyvsp[0].node)->lineno, "");
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1502 "syntax.tab.c"
    break;

  case 16: /* ExtDecList: Dec COMMA ExtDecList  */
#line 162 "syntax.y"
                           {
        TreeNode *p = createTreeNode("ExtDecList", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1514 "syntax.tab.c"
    break;

  case 17: /* Dec: VarDec  */
#line 172 "syntax.y"
             {
        TreeNode *p = createTreeNode("Dec", (yyvsp[0].node)->lineno, "");
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1524 "syntax.tab.c"
    break;

  case 18: /* Dec: VarDec ASSIGNOP Exp  */
#line 177 "syntax.y"
                          {
        TreeNode *p = createTreeNode("Dec", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1536 "syntax.tab.c"
    break;

  case 19: /* CompSt: LC DefList StmtList RC  */
#line 188 "syntax.y"
                             {
        TreeNode *p = createTreeNode("CompSt", (yyvsp[-3].node)->lineno, "");
        insertChild(p, (yyvsp[-3].node));
         if ((yyvsp[-2].node)) insertChild(p, (yyvsp[-2].node));
        if ((yyvsp[-1].node)) insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1549 "syntax.tab.c"
    break;

  case 20: /* FunDec: ID LP RP  */
#line 199 "syntax.y"
               {
        TreeNode *p = createTreeNode("FunDec", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1561 "syntax.tab.c"
    break;

  case 21: /* FunDec: ID LP VarList RP  */
#line 206 "syntax.y"
                       {
        TreeNode *p = createTreeNode("FunDec", (yyvsp[-3].node)->lineno, "");
        insertChild(p, (yyvsp[-3].node));
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1574 "syntax.tab.c"
    break;

  case 22: /* VarList: ParamDec COMMA VarList  */
#line 218 "syntax.y"
                             {
        TreeNode *p = createTreeNode("VarList", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1586 "syntax.tab.c"
    break;

  case 23: /* VarList: ParamDec  */
#line 225 "syntax.y"
               {
        TreeNode *p = createTreeNode("VarList", (yyvsp[0].node)->lineno, "");
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1596 "syntax.tab.c"
    break;

  case 24: /* ParamDec: Specifier VarDec  */
#line 233 "syntax.y"
                       {
        TreeNode *p = createTreeNode("ParamDec", (yyvsp[-1].node)->lineno, "");
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1607 "syntax.tab.c"
    break;

  case 25: /* VarDec: ID  */
#line 242 "syntax.y"
         {
        TreeNode *p = createTreeNode("VarDec", (yyvsp[0].node)->lineno, "");
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1617 "syntax.tab.c"
    break;

  case 26: /* VarDec: VarDec LB INT RB  */
#line 247 "syntax.y"
                       {
        TreeNode *p = createTreeNode("VarDec", (yyvsp[-3].node)->lineno, "");
        insertChild(p, (yyvsp[-3].node));
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1630 "syntax.tab.c"
    break;

  case 27: /* DefList: Def DefList  */
#line 258 "syntax.y"
                  {
        TreeNode *p = createTreeNode("DefList", (yyvsp[-1].node)->lineno, "");
        insertChild(p, (yyvsp[-1].node));
        if ((yyvsp[0].node)) insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1641 "syntax.tab.c"
    break;

  case 28: /* DefList: %empty  */
#line 264 "syntax.y"
                  {
        (yyval.node) =NULL;
      }
#line 1649 "syntax.tab.c"
    break;

  case 29: /* Def: Specifier DecList SEMI  */
#line 270 "syntax.y"
                             {
        TreeNode *p = createTreeNode("Def", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1661 "syntax.tab.c"
    break;

  case 30: /* DecList: Dec  */
#line 280 "syntax.y"
          {
        TreeNode *p = createTreeNode("DecList", (yyvsp[0].node)->lineno, "");
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1671 "syntax.tab.c"
    break;

  case 31: /* DecList: Dec COMMA DecList  */
#line 285 "syntax.y"
                        {
        TreeNode *p = createTreeNode("DecList", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1683 "syntax.tab.c"
    break;

  case 32: /* StmtList: Stmt StmtList  */
#line 295 "syntax.y"
                    {
        TreeNode *p = createTreeNode("StmtList", (yyvsp[-1].node)->lineno, "");
        insertChild(p, (yyvsp[-1].node));
        if ((yyvsp[0].node)) insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1694 "syntax.tab.c"
    break;

  case 33: /* StmtList: %empty  */
#line 301 "syntax.y"
                  {
        (yyval.node) =  NULL;
      }
#line 1702 "syntax.tab.c"
    break;

  case 34: /* StmtList: error SEMI StmtList  */
#line 304 "syntax.y"
                             {
        yyerrok;
        (yyval.node) = (yyvsp[0].node);  /* 不构造空 StmtList/Stmt 节点，避免输出垃圾节点 */
      }
#line 1711 "syntax.tab.c"
    break;

  case 35: /* Stmt: Exp SEMI  */
#line 311 "syntax.y"
               {
        TreeNode *p = createTreeNode("Stmt", (yyvsp[-1].node)->lineno, "");
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1722 "syntax.tab.c"
    break;

  case 36: /* Stmt: CompSt  */
#line 317 "syntax.y"
             {
        TreeNode *p = createTreeNode("Stmt", (yyvsp[0].node)->lineno, "");
        insertChild(p, (yyvsp[0].node));
        
        (yyval.node) = p;
      }
#line 1733 "syntax.tab.c"
    break;

  case 37: /* Stmt: RETURN Exp SEMI  */
#line 323 "syntax.y"
                      {
        TreeNode *p = createTreeNode("Stmt", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1745 "syntax.tab.c"
    break;

  case 38: /* Stmt: IF LP Exp RP Stmt  */
#line 330 "syntax.y"
                                              {
        TreeNode *p = createTreeNode("Stmt", (yyvsp[-4].node)->lineno, "");
        insertChild(p, (yyvsp[-4].node));
        insertChild(p, (yyvsp[-3].node));
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1759 "syntax.tab.c"
    break;

  case 39: /* Stmt: IF LP Exp RP Stmt ELSE error Stmt  */
#line 339 "syntax.y"
                                           {
        yyerror_missing(";", (yylsp[-2]).first_line); /* @6 对应 ELSE 的位置 */
        yyerrok;

        TreeNode *p = createTreeNode("Stmt", (yyvsp[-7].node)->lineno, "");
        insertChild(p, (yyvsp[-7].node));
        insertChild(p, (yyvsp[-6].node));
        insertChild(p, (yyvsp[-5].node));
        insertChild(p, (yyvsp[-4].node));
        insertChild(p, (yyvsp[-3].node));
        insertChild(p, (yyvsp[-2].node));  /* ELSE */
        insertChild(p, (yyvsp[0].node));  /* else: Stmt */
        (yyval.node) = p;
      }
#line 1778 "syntax.tab.c"
    break;

  case 40: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 353 "syntax.y"
                                  {
        TreeNode *p = createTreeNode("Stmt", (yyvsp[-6].node)->lineno, "");
        insertChild(p, (yyvsp[-6].node));
        insertChild(p, (yyvsp[-5].node));
        insertChild(p, (yyvsp[-4].node));
        insertChild(p, (yyvsp[-3].node));
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1794 "syntax.tab.c"
    break;

  case 41: /* Stmt: IF LP Exp RP Stmt error ELSE Stmt  */
#line 364 "syntax.y"
                                           {
        yyerror_missing(";", yylineno);
        yyerrok;
       

        TreeNode *p = createTreeNode("Stmt", (yyvsp[-7].node)->lineno, "");
        insertChild(p, (yyvsp[-7].node));
        insertChild(p, (yyvsp[-6].node));
        insertChild(p, (yyvsp[-5].node));
        insertChild(p, (yyvsp[-4].node));
        insertChild(p, (yyvsp[-3].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1814 "syntax.tab.c"
    break;

  case 42: /* Stmt: IF LP Exp RP Exp error ELSE Stmt  */
#line 379 "syntax.y"
                                         {
        yyerror_missing(";", yylineno);
        yyerrok;

        TreeNode *p = createTreeNode("Stmt", (yyvsp[-7].node)->lineno, "");
        insertChild(p, (yyvsp[-7].node));
        insertChild(p, (yyvsp[-6].node));
        insertChild(p, (yyvsp[-5].node));
        insertChild(p, (yyvsp[-4].node));
        insertChild(p, (yyvsp[-3].node)); /* then: Exp */
        insertChild(p, (yyvsp[-1].node)); /* ELSE */
        insertChild(p, (yyvsp[0].node)); /* else: Stmt */
        (yyval.node) = p;
      }
#line 1833 "syntax.tab.c"
    break;

  case 43: /* Stmt: WHILE LP Exp RP Stmt  */
#line 393 "syntax.y"
                           {
        TreeNode *p = createTreeNode("Stmt", (yyvsp[-4].node)->lineno, "");
        insertChild(p, (yyvsp[-4].node));
        insertChild(p, (yyvsp[-3].node));
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1847 "syntax.tab.c"
    break;

  case 44: /* Exp: ID  */
#line 406 "syntax.y"
          {
        TreeNode *p = createTreeNode("Exp", (yyvsp[0].node)->lineno, "");
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1857 "syntax.tab.c"
    break;

  case 45: /* Exp: INT  */
#line 411 "syntax.y"
          {
        TreeNode *p = createTreeNode("Exp", (yyvsp[0].node)->lineno, "");
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1867 "syntax.tab.c"
    break;

  case 46: /* Exp: FLOAT  */
#line 416 "syntax.y"
            {
        TreeNode *p = createTreeNode("Exp", (yyvsp[0].node)->lineno, "");
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1877 "syntax.tab.c"
    break;

  case 47: /* Exp: Exp DOT ID  */
#line 421 "syntax.y"
                     {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node));
         insertChild(p, (yyvsp[-1].node)); 
         insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1889 "syntax.tab.c"
    break;

  case 48: /* Exp: Exp LB Exp RB  */
#line 428 "syntax.y"
                      {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-3].node)->lineno, "");
        insertChild(p, (yyvsp[-3].node)); insertChild(p, (yyvsp[-2].node)); insertChild(p, (yyvsp[-1].node)); insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1899 "syntax.tab.c"
    break;

  case 49: /* Exp: Exp ASSIGNOP Exp  */
#line 434 "syntax.y"
                       {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1911 "syntax.tab.c"
    break;

  case 50: /* Exp: Exp AND Exp  */
#line 441 "syntax.y"
                  {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node)); insertChild(p, (yyvsp[-1].node)); insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1921 "syntax.tab.c"
    break;

  case 51: /* Exp: Exp OR Exp  */
#line 446 "syntax.y"
                 {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node)); insertChild(p, (yyvsp[-1].node)); insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1931 "syntax.tab.c"
    break;

  case 52: /* Exp: Exp RELOP Exp  */
#line 451 "syntax.y"
                    {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node)); insertChild(p, (yyvsp[-1].node)); insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1941 "syntax.tab.c"
    break;

  case 53: /* Exp: Exp PLUS Exp  */
#line 456 "syntax.y"
                   {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node)); insertChild(p, (yyvsp[-1].node)); insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1951 "syntax.tab.c"
    break;

  case 54: /* Exp: Exp MINUS Exp  */
#line 461 "syntax.y"
                    {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node)); insertChild(p, (yyvsp[-1].node)); insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1961 "syntax.tab.c"
    break;

  case 55: /* Exp: Exp STAR Exp  */
#line 466 "syntax.y"
                   {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node)); insertChild(p, (yyvsp[-1].node)); insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1971 "syntax.tab.c"
    break;

  case 56: /* Exp: Exp DIV Exp  */
#line 471 "syntax.y"
                  {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node)); insertChild(p, (yyvsp[-1].node)); insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1981 "syntax.tab.c"
    break;

  case 57: /* Exp: LP Exp RP  */
#line 476 "syntax.y"
                {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-2].node)->lineno, "");
        insertChild(p, (yyvsp[-2].node)); insertChild(p, (yyvsp[-1].node)); insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 1991 "syntax.tab.c"
    break;

  case 58: /* Exp: MINUS Exp  */
#line 481 "syntax.y"
                            {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-1].node)->lineno, "");
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 2002 "syntax.tab.c"
    break;

  case 59: /* Exp: NOT Exp  */
#line 487 "syntax.y"
              {
        TreeNode *p = createTreeNode("Exp", (yyvsp[-1].node)->lineno, "");
        insertChild(p, (yyvsp[-1].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 2013 "syntax.tab.c"
    break;

  case 60: /* Exp: Exp LB error RB  */
#line 496 "syntax.y"
                      {
        yyerror_missing("]", yylineno);
        /* 错误恢复：丢弃当前 lookahead，继续 */
        yyerrok;
      

        /* 仍然构建一个节点，避免后续空指针（可选） */
        TreeNode *p = createTreeNode("Exp", (yyvsp[-3].node)->lineno, "");
        insertChild(p, (yyvsp[-3].node));
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[0].node));
        (yyval.node) = p;
      }
#line 2031 "syntax.tab.c"
    break;

  case 61: /* Exp: Exp LB error SEMI  */
#line 509 "syntax.y"
                           {
        yyerror_missing("]", yylineno);
        yyerrok;

        /* 这里消耗掉 SEMI，相当于跳过这条错误语句的剩余部分 */
        TreeNode *p = createTreeNode("Exp", (yyvsp[-3].node)->lineno, "");
        insertChild(p, (yyvsp[-3].node));
        insertChild(p, (yyvsp[-2].node));
        insertChild(p, (yyvsp[0].node)); /* SEMI 作为同步点 */
        (yyval.node) = p;
      }
#line 2047 "syntax.tab.c"
    break;


#line 2051 "syntax.tab.c"

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
  *++yylsp = yyloc;

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
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 538 "syntax.y"


