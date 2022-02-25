/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "grammars/svf.y"

#include <stdio.h>
#include "lexer.h"
#include "parser.h"

extern FILE* yyin;
//int yydebug=1;

int yyerror(char* s)
{
    fprintf(stderr, "%s\n",s);
    return 0;
}

static int parse_enddr(int stable_state)
{
    SVF_Instruction* instruction = create_empty_instruction();
    instruction->type = SVF_INSTRUCTION_ENDDR;
    instruction->stable_state = stable_state;
    add_instruction(instruction);
    return 0;
}

static int parse_endir(int stable_state)
{
    SVF_Instruction* instruction = create_empty_instruction();
    instruction->type = SVF_INSTRUCTION_ENDIR;
    instruction->stable_state = stable_state;
    add_instruction(instruction);
    return 0;
}

static int parse_frequency(double cycles)
{
    SVF_Instruction* instruction = create_empty_instruction();
    instruction->type = SVF_INSTRUCTION_FREQUENCY;
    instruction->cycles = cycles;
    add_instruction(instruction);
    return 0;
}

static int parse_hdr(SVF_Shift_Data shift_data)
{
    SVF_Instruction* instruction = create_empty_instruction();
    instruction->type = SVF_INSTRUCTION_HDR;
    instruction->shift_data = shift_data;
    add_instruction(instruction);
    return 0;
}

static int parse_hir(SVF_Shift_Data shift_data)
{
    SVF_Instruction* instruction = create_empty_instruction();
    instruction->type = SVF_INSTRUCTION_HIR;
    instruction->shift_data = shift_data;
    add_instruction(instruction);
    return 0;
}

static int parse_pio()
{
    printf("PIO is currently not implemented!\n");
    return 1;
}

static int parse_piomap()
{
    printf("PIOMAP is currently not implemented!\n");
    return 1;
}

static int parse_runtest(int run_state, unsigned int run_count, int run_clk, double min_time, double max_time, int end_state)
{
    SVF_Instruction* instruction = create_empty_instruction();
    instruction->type = SVF_INSTRUCTION_RUNTEST;
    instruction->run_state = run_state;
    instruction->run_count = run_count;
    instruction->run_clk = run_clk;
    instruction->min_time = min_time;
    instruction->max_time = max_time;
    instruction->end_state = end_state;
    add_instruction(instruction);
    return 0;
}

static int parse_sdr(SVF_Shift_Data shift_data)
{
    SVF_Instruction* instruction = create_empty_instruction();
    instruction->type = SVF_INSTRUCTION_SDR;
    instruction->shift_data = shift_data;
    add_instruction(instruction);
    return 0;
}

static int parse_sir(SVF_Shift_Data shift_data)
{
    SVF_Instruction* instruction = create_empty_instruction();
    instruction->type = SVF_INSTRUCTION_SIR;
    instruction->shift_data = shift_data;
    add_instruction(instruction);
    return 0;
}

static int parse_state(List* path_states, int stable_state)
{
    SVF_Instruction* instruction = create_empty_instruction();
    instruction->type = SVF_INSTRUCTION_STATE;
    instruction->path_states = path_states;
    instruction->stable_state = stable_state;
    add_instruction(instruction);
    return 0;
}

static int parse_tdr(SVF_Shift_Data shift_data)
{
    SVF_Instruction* instruction = create_empty_instruction();
    instruction->type = SVF_INSTRUCTION_TDR;
    instruction->shift_data = shift_data;
    add_instruction(instruction);
    return 0;
}

static int parse_tir(SVF_Shift_Data shift_data)
{
    SVF_Instruction* instruction = create_empty_instruction();
    instruction->type = SVF_INSTRUCTION_TIR;
    instruction->shift_data = shift_data;
    add_instruction(instruction);
    return 0;
}

static int parse_trst(int trst_mode)
{
    SVF_Instruction* instruction = create_empty_instruction();
    instruction->type = SVF_INSTRUCTION_TRST;
    instruction->trst_mode = trst_mode;
    add_instruction(instruction);
    return 0;
}


#line 212 "src/parser.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "grammars/svf.y"

#include "util.h"
#include "execute.h"

#line 260 "src/parser.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SVF_INSTRUCTION_ENDDR = 258,
    SVF_INSTRUCTION_ENDIR = 259,
    SVF_INSTRUCTION_FREQUENCY = 260,
    SVF_INSTRUCTION_HDR = 261,
    SVF_INSTRUCTION_HIR = 262,
    SVF_INSTRUCTION_PIO = 263,
    SVF_INSTRUCTION_PIOMAP = 264,
    SVF_INSTRUCTION_RUNTEST = 265,
    SVF_INSTRUCTION_SDR = 266,
    SVF_INSTRUCTION_SIR = 267,
    SVF_INSTRUCTION_STATE = 268,
    SVF_INSTRUCTION_TDR = 269,
    SVF_INSTRUCTION_TIR = 270,
    SVF_INSTRUCTION_TRST = 271,
    SVF_STATE_RESET = 272,
    SVF_STATE_IDLE = 273,
    SVF_STATE_DRSELECT = 274,
    SVF_STATE_DRCAPTURE = 275,
    SVF_STATE_DRSHIFT = 276,
    SVF_STATE_DREXIT1 = 277,
    SVF_STATE_DRPAUSE = 278,
    SVF_STATE_DREXIT2 = 279,
    SVF_STATE_DRUPDATE = 280,
    SVF_STATE_IRSELECT = 281,
    SVF_STATE_IRCAPTURE = 282,
    SVF_STATE_IRSHIFT = 283,
    SVF_STATE_IREXIT1 = 284,
    SVF_STATE_IRPAUSE = 285,
    SVF_STATE_IREXIT2 = 286,
    SVF_STATE_IRUPDATE = 287,
    SVF_REAL_NUMBER = 288,
    SVF_UNSIGNED_INT = 289,
    SVF_HEXSTRING = 290,
    SVF_RUN_CLK_TCK = 291,
    SVF_RUN_CLK_SCK = 292,
    SVF_TRST_MODE_ON = 293,
    SVF_TRST_MODE_OFF = 294,
    SVF_TRST_MODE_Z = 295,
    SVF_TRST_MODE_ABSENT = 296,
    SVF_HZ = 297,
    SVF_MAXIMUM = 298,
    SVF_SEC = 299,
    SVF_ENDSTATE = 300,
    SVF_TDI = 301,
    SVF_TDO = 302,
    SVF_MASK = 303,
    SVF_SMASK = 304,
    SVF_INSTRUCTION_END = 305
  };
#endif
/* Tokens.  */
#define SVF_INSTRUCTION_ENDDR 258
#define SVF_INSTRUCTION_ENDIR 259
#define SVF_INSTRUCTION_FREQUENCY 260
#define SVF_INSTRUCTION_HDR 261
#define SVF_INSTRUCTION_HIR 262
#define SVF_INSTRUCTION_PIO 263
#define SVF_INSTRUCTION_PIOMAP 264
#define SVF_INSTRUCTION_RUNTEST 265
#define SVF_INSTRUCTION_SDR 266
#define SVF_INSTRUCTION_SIR 267
#define SVF_INSTRUCTION_STATE 268
#define SVF_INSTRUCTION_TDR 269
#define SVF_INSTRUCTION_TIR 270
#define SVF_INSTRUCTION_TRST 271
#define SVF_STATE_RESET 272
#define SVF_STATE_IDLE 273
#define SVF_STATE_DRSELECT 274
#define SVF_STATE_DRCAPTURE 275
#define SVF_STATE_DRSHIFT 276
#define SVF_STATE_DREXIT1 277
#define SVF_STATE_DRPAUSE 278
#define SVF_STATE_DREXIT2 279
#define SVF_STATE_DRUPDATE 280
#define SVF_STATE_IRSELECT 281
#define SVF_STATE_IRCAPTURE 282
#define SVF_STATE_IRSHIFT 283
#define SVF_STATE_IREXIT1 284
#define SVF_STATE_IRPAUSE 285
#define SVF_STATE_IREXIT2 286
#define SVF_STATE_IRUPDATE 287
#define SVF_REAL_NUMBER 288
#define SVF_UNSIGNED_INT 289
#define SVF_HEXSTRING 290
#define SVF_RUN_CLK_TCK 291
#define SVF_RUN_CLK_SCK 292
#define SVF_TRST_MODE_ON 293
#define SVF_TRST_MODE_OFF 294
#define SVF_TRST_MODE_Z 295
#define SVF_TRST_MODE_ABSENT 296
#define SVF_HZ 297
#define SVF_MAXIMUM 298
#define SVF_SEC 299
#define SVF_ENDSTATE 300
#define SVF_TDI 301
#define SVF_TDO 302
#define SVF_MASK 303
#define SVF_SMASK 304
#define SVF_INSTRUCTION_END 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 151 "grammars/svf.y"

    double d;
    List* list;
    char* string; 
    unsigned int u;
    SVF_Shift_Data shift_data;

#line 379 "src/parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   226,   226,   226,   228,   232,   236,   240,   244,   248,
     252,   256,   260,   264,   268,   272,   276,   280,   284,   288,
     292,   296,   300,   304,   308,   312,   316,   320,   324,   328,
     332,   336,   340,   345,   349,   353,   357,   361,   365,   369,
     374,   374,   374,   374,   375,   375,   375,   375,   375,   376,
     376,   376,   376,   376,   377,   377,   377,   377,   377,   378,
     380,   382,   386,   390,   394,   399,   404,   409,   414,   419,
     424,   429,   434,   439,   445,   451,   458,   463,   463,   464,
     468,   473,   478,   478,   478,   478
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SVF_INSTRUCTION_ENDDR",
  "SVF_INSTRUCTION_ENDIR", "SVF_INSTRUCTION_FREQUENCY",
  "SVF_INSTRUCTION_HDR", "SVF_INSTRUCTION_HIR", "SVF_INSTRUCTION_PIO",
  "SVF_INSTRUCTION_PIOMAP", "SVF_INSTRUCTION_RUNTEST",
  "SVF_INSTRUCTION_SDR", "SVF_INSTRUCTION_SIR", "SVF_INSTRUCTION_STATE",
  "SVF_INSTRUCTION_TDR", "SVF_INSTRUCTION_TIR", "SVF_INSTRUCTION_TRST",
  "SVF_STATE_RESET", "SVF_STATE_IDLE", "SVF_STATE_DRSELECT",
  "SVF_STATE_DRCAPTURE", "SVF_STATE_DRSHIFT", "SVF_STATE_DREXIT1",
  "SVF_STATE_DRPAUSE", "SVF_STATE_DREXIT2", "SVF_STATE_DRUPDATE",
  "SVF_STATE_IRSELECT", "SVF_STATE_IRCAPTURE", "SVF_STATE_IRSHIFT",
  "SVF_STATE_IREXIT1", "SVF_STATE_IRPAUSE", "SVF_STATE_IREXIT2",
  "SVF_STATE_IRUPDATE", "SVF_REAL_NUMBER", "SVF_UNSIGNED_INT",
  "SVF_HEXSTRING", "SVF_RUN_CLK_TCK", "SVF_RUN_CLK_SCK",
  "SVF_TRST_MODE_ON", "SVF_TRST_MODE_OFF", "SVF_TRST_MODE_Z",
  "SVF_TRST_MODE_ABSENT", "SVF_HZ", "SVF_MAXIMUM", "SVF_SEC",
  "SVF_ENDSTATE", "SVF_TDI", "SVF_TDO", "SVF_MASK", "SVF_SMASK",
  "SVF_INSTRUCTION_END", "$accept", "program", "command", "stable_state",
  "state", "end", "tdi", "tdo", "mask", "smask", "common", "statelist",
  "cycles", "run_clk", "min", "max", "end_state", "trst_mode", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-44)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     135,    30,    30,   -17,   -24,   -24,   -78,   -78,    75,   -15,
     -24,   105,   -24,   -24,    56,    25,   135,   -78,   -78,   -78,
     -78,   -19,   -19,     0,   -78,   -78,   -19,    -9,   -19,   -19,
       7,    -8,    10,    -5,    19,   -19,   -19,     6,     8,   -78,
     -78,   -78,   -78,    14,   -78,   -78,   -78,   -78,   -78,   -78,
      20,   -78,   -78,   -19,   105,   -19,   -19,   -19,   -78,   -78,
     -78,   -78,   -19,   -78,   -78,   -78,   -78,   -78,   -78,    24,
      70,   -78,   -78,   -78,   -78,   -78,   -27,    -8,    -5,    40,
      30,   -78,   -41,   -19,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,    42,    45,    52,    18,    39,
     -78,   -78,    -5,   -19,   -27,   -78,   -41,   -19,    47,   -78,
     -78,   -19,   -78,   -78,   -78,   -78,    39,   -78,   -78,   -78,
     -41,   -19,   -78,   -78,    -5,   -19,   -78,   -19,   -78,   -78,
     -78,   -78,   -78,   -19,   -78,   -78,   -41,   -19,   -78,   -78,
     -78,   -78,   -19,   -78,   -78
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     2,    40,    41,    42,
      43,     0,     0,     0,    60,     6,     0,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     0,    82,    83,
      84,    85,     0,     1,     3,     4,     5,    76,     7,     0,
      66,     8,     9,    79,    77,    78,     0,     0,     0,     0,
       0,    24,     0,     0,    32,    33,    34,    35,    74,    75,
      36,    37,    38,    39,    61,     0,     0,     0,    67,    68,
      69,    12,     0,     0,     0,    28,     0,     0,     0,    81,
      25,     0,    26,    62,    63,    64,    70,    71,    72,    13,
       0,     0,    15,    18,     0,     0,    29,     0,    30,    80,
      27,    73,    14,     0,    16,    19,     0,     0,    21,    31,
      17,    20,     0,    22,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,    85,   -78,     9,   -78,   -21,   -78,   -78,     4,   -77,
      66,    53,   -78,    33,   -30,   -75,   -52,   -78
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    16,    21,    54,    25,    70,    98,    99,   100,
      28,    55,    26,    76,    33,    82,    83,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    66,    78,   106,    80,    68,    30,    71,    72,    24,
      27,    22,    81,    84,    85,    86,    23,    32,    80,    34,
      53,   117,   118,    24,   103,    63,   107,   120,    74,    75,
     111,    24,    87,    24,    90,    91,    92,    69,    79,   131,
      80,    93,    67,    30,    77,    24,   102,    17,    18,   136,
     121,    73,   125,    19,   127,   101,   -40,   105,   -41,    94,
      20,   110,   112,    88,   -42,    69,    96,    97,   133,    24,
     -43,    29,   137,   108,   124,    35,    36,   113,    56,    57,
     114,   119,   122,   123,   142,   126,   128,   115,    97,   109,
     130,   129,    17,    18,    58,    59,    60,    61,    19,   132,
     134,    64,   116,   135,   138,    20,   139,    89,    30,    31,
     104,     0,   140,     0,     0,   141,   143,    95,    96,    97,
       0,   144,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14
};

static const yytype_int16 yycheck[] =
{
      21,    22,    32,    78,    45,    26,    33,    28,    29,    50,
      34,     2,    33,    34,    35,    36,    33,     8,    45,    34,
      11,    98,    99,    50,    76,     0,    78,   102,    36,    37,
      82,    50,    53,    50,    55,    56,    57,    46,    43,   116,
      45,    62,    42,    33,    34,    50,    76,    17,    18,   124,
     102,    44,   104,    23,   106,    76,    50,    78,    50,    35,
      30,    82,    83,    54,    50,    46,    48,    49,   120,    50,
      50,     5,   124,    33,   104,     9,    10,    35,    12,    13,
      35,   102,   103,   104,   136,   106,   107,    35,    49,    80,
     111,    44,    17,    18,    38,    39,    40,    41,    23,   120,
     121,    16,    98,   124,   125,    30,   127,    54,    33,    34,
      77,    -1,   133,    -1,    -1,   136,   137,    47,    48,    49,
      -1,   142,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    52,    53,    17,    18,    23,
      30,    54,    54,    33,    50,    56,    63,    34,    61,    61,
      33,    34,    54,    65,    34,    61,    61,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    54,    55,    62,    61,    61,    38,    39,
      40,    41,    68,     0,    52,    56,    56,    42,    56,    46,
      57,    56,    56,    44,    36,    37,    64,    34,    65,    43,
      45,    56,    66,    67,    56,    56,    56,    56,    54,    62,
      56,    56,    56,    56,    35,    47,    48,    49,    58,    59,
      60,    56,    65,    67,    64,    56,    66,    67,    33,    54,
      56,    67,    56,    35,    35,    35,    59,    60,    60,    56,
      66,    67,    56,    56,    65,    67,    56,    67,    56,    44,
      56,    60,    56,    67,    56,    56,    66,    67,    56,    56,
      56,    56,    67,    56,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    57,    58,    59,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    63,    64,    64,    65,
      66,    67,    68,    68,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     2,     3,     3,     3,
       1,     1,     4,     5,     6,     5,     6,     7,     5,     6,
       7,     6,     7,     8,     3,     4,     4,     5,     4,     5,
       5,     6,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     2,     3,     3,     3,
       4,     4,     4,     5,     1,     2,     2,     1,     1,     2,
       3,     2,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 4:
#line 229 "grammars/svf.y"
            {
                parse_enddr((yyvsp[-1].u));
            }
#line 1668 "src/parser.c"
    break;

  case 5:
#line 233 "grammars/svf.y"
            {
                parse_endir((yyvsp[-1].u));
            }
#line 1676 "src/parser.c"
    break;

  case 6:
#line 237 "grammars/svf.y"
            {
                parse_frequency(0);
            }
#line 1684 "src/parser.c"
    break;

  case 7:
#line 241 "grammars/svf.y"
            {
                parse_frequency((yyvsp[-1].d));
            }
#line 1692 "src/parser.c"
    break;

  case 8:
#line 245 "grammars/svf.y"
            {
                parse_hdr((yyvsp[-1].shift_data));
            }
#line 1700 "src/parser.c"
    break;

  case 9:
#line 249 "grammars/svf.y"
            {
                parse_hir((yyvsp[-1].shift_data));
            }
#line 1708 "src/parser.c"
    break;

  case 10:
#line 253 "grammars/svf.y"
            {
                parse_pio();
            }
#line 1716 "src/parser.c"
    break;

  case 11:
#line 257 "grammars/svf.y"
            {
                parse_piomap();
            }
#line 1724 "src/parser.c"
    break;

  case 12:
#line 261 "grammars/svf.y"
            {
                parse_runtest(0,(yyvsp[-2].u),(yyvsp[-1].u),0,0,0);
            }
#line 1732 "src/parser.c"
    break;

  case 13:
#line 265 "grammars/svf.y"
            {
                parse_runtest(0,(yyvsp[-3].u),(yyvsp[-2].u),(yyvsp[-1].d),0,0);
            }
#line 1740 "src/parser.c"
    break;

  case 14:
#line 269 "grammars/svf.y"
            {
                parse_runtest(0,(yyvsp[-4].u),(yyvsp[-3].u),(yyvsp[-2].d),(yyvsp[-1].d),0);
            }
#line 1748 "src/parser.c"
    break;

  case 15:
#line 273 "grammars/svf.y"
            {
                parse_runtest(0,(yyvsp[-3].u),(yyvsp[-2].u),0,0,(yyvsp[-1].u));
            }
#line 1756 "src/parser.c"
    break;

  case 16:
#line 277 "grammars/svf.y"
            {
                parse_runtest(0,(yyvsp[-4].u),(yyvsp[-3].u),(yyvsp[-2].d),0,(yyvsp[-1].u));
            }
#line 1764 "src/parser.c"
    break;

  case 17:
#line 281 "grammars/svf.y"
            {
                parse_runtest(0,(yyvsp[-5].u),(yyvsp[-4].u),(yyvsp[-3].d),(yyvsp[-2].d),(yyvsp[-1].u));
            }
#line 1772 "src/parser.c"
    break;

  case 18:
#line 285 "grammars/svf.y"
            {
                parse_runtest((yyvsp[-3].u),(yyvsp[-2].u),(yyvsp[-1].u),0,0,0);
            }
#line 1780 "src/parser.c"
    break;

  case 19:
#line 289 "grammars/svf.y"
            {
                parse_runtest((yyvsp[-4].u),(yyvsp[-3].u),(yyvsp[-2].u),(yyvsp[-1].d),0,0);
            }
#line 1788 "src/parser.c"
    break;

  case 20:
#line 293 "grammars/svf.y"
            {
                parse_runtest((yyvsp[-5].u),(yyvsp[-4].u),(yyvsp[-3].u),(yyvsp[-2].d),(yyvsp[-1].d),0);
            }
#line 1796 "src/parser.c"
    break;

  case 21:
#line 297 "grammars/svf.y"
            {
                parse_runtest((yyvsp[-4].u),(yyvsp[-3].u),(yyvsp[-2].u),0,0,(yyvsp[-1].u));
            }
#line 1804 "src/parser.c"
    break;

  case 22:
#line 301 "grammars/svf.y"
            {
                parse_runtest((yyvsp[-5].u),(yyvsp[-4].u),(yyvsp[-3].u),(yyvsp[-2].d),0,(yyvsp[-1].u));
            }
#line 1812 "src/parser.c"
    break;

  case 23:
#line 305 "grammars/svf.y"
            {
                parse_runtest((yyvsp[-6].u),(yyvsp[-5].u),(yyvsp[-4].u),(yyvsp[-3].d),(yyvsp[-2].d),(yyvsp[-1].u));
            }
#line 1820 "src/parser.c"
    break;

  case 24:
#line 309 "grammars/svf.y"
            {
                parse_runtest(0,0,0,(yyvsp[-1].d),0,0);
            }
#line 1828 "src/parser.c"
    break;

  case 25:
#line 313 "grammars/svf.y"
            {
                parse_runtest(0,0,0,(yyvsp[-2].d),(yyvsp[-1].d),0);
            }
#line 1836 "src/parser.c"
    break;

  case 26:
#line 317 "grammars/svf.y"
            {
                parse_runtest(0,0,0,(yyvsp[-2].d),0,(yyvsp[-1].u));
            }
#line 1844 "src/parser.c"
    break;

  case 27:
#line 321 "grammars/svf.y"
            {
                parse_runtest(0,0,0,(yyvsp[-3].d),(yyvsp[-2].d),(yyvsp[-1].u));
            }
#line 1852 "src/parser.c"
    break;

  case 28:
#line 325 "grammars/svf.y"
            {
                parse_runtest((yyvsp[-2].u),0,0,(yyvsp[-1].d),0,0);
            }
#line 1860 "src/parser.c"
    break;

  case 29:
#line 329 "grammars/svf.y"
            {
                parse_runtest((yyvsp[-3].u),0,0,(yyvsp[-2].d),(yyvsp[-1].d),0);
            }
#line 1868 "src/parser.c"
    break;

  case 30:
#line 333 "grammars/svf.y"
            {
                parse_runtest((yyvsp[-3].u),0,0,(yyvsp[-2].d),0,(yyvsp[-1].u));
            }
#line 1876 "src/parser.c"
    break;

  case 31:
#line 337 "grammars/svf.y"
            {
                parse_runtest((yyvsp[-4].u),0,0,(yyvsp[-3].d),(yyvsp[-2].d),(yyvsp[-1].u));
            }
#line 1884 "src/parser.c"
    break;

  case 32:
#line 341 "grammars/svf.y"
            {
                SVF_Shift_Data shift_data = {(yyvsp[-1].u), NULL, NULL, NULL, NULL};
                parse_sdr(shift_data);
            }
#line 1893 "src/parser.c"
    break;

  case 33:
#line 346 "grammars/svf.y"
            {
                parse_sdr((yyvsp[-1].shift_data));
            }
#line 1901 "src/parser.c"
    break;

  case 34:
#line 350 "grammars/svf.y"
            {
                parse_sir((yyvsp[-1].shift_data));
            }
#line 1909 "src/parser.c"
    break;

  case 35:
#line 354 "grammars/svf.y"
            {
                parse_state(NULL, (yyvsp[-1].u));
            }
#line 1917 "src/parser.c"
    break;

  case 36:
#line 358 "grammars/svf.y"
            {
                parse_state((yyvsp[-1].list), (yyvsp[0].u));
            }
#line 1925 "src/parser.c"
    break;

  case 37:
#line 362 "grammars/svf.y"
            {
                parse_tdr((yyvsp[-1].shift_data));
            }
#line 1933 "src/parser.c"
    break;

  case 38:
#line 366 "grammars/svf.y"
            {
                parse_tir((yyvsp[-1].shift_data));
            }
#line 1941 "src/parser.c"
    break;

  case 39:
#line 370 "grammars/svf.y"
            {
                parse_trst((yyvsp[-1].u));
            }
#line 1949 "src/parser.c"
    break;

  case 61:
#line 383 "grammars/svf.y"
        {
            (yyval.string) = (yyvsp[0].string);
        }
#line 1957 "src/parser.c"
    break;

  case 62:
#line 387 "grammars/svf.y"
        {
            (yyval.string) = (yyvsp[0].string);
        }
#line 1965 "src/parser.c"
    break;

  case 63:
#line 391 "grammars/svf.y"
        {
            (yyval.string) = (yyvsp[0].string);
        }
#line 1973 "src/parser.c"
    break;

  case 64:
#line 395 "grammars/svf.y"
        {
            (yyval.string) = (yyvsp[0].string);
        }
#line 1981 "src/parser.c"
    break;

  case 65:
#line 400 "grammars/svf.y"
        {
            SVF_Shift_Data shift_data = {(yyvsp[0].u), NULL, NULL, NULL, NULL};
            (yyval.shift_data) = shift_data;
        }
#line 1990 "src/parser.c"
    break;

  case 66:
#line 405 "grammars/svf.y"
        {
            SVF_Shift_Data shift_data = {(yyvsp[-1].u), (yyvsp[0].string), NULL, NULL, NULL};
            (yyval.shift_data) = shift_data;
        }
#line 1999 "src/parser.c"
    break;

  case 67:
#line 410 "grammars/svf.y"
        {
            SVF_Shift_Data shift_data = {(yyvsp[-2].u), (yyvsp[-1].string), (yyvsp[0].string), NULL, NULL};
            (yyval.shift_data) = shift_data;
        }
#line 2008 "src/parser.c"
    break;

  case 68:
#line 415 "grammars/svf.y"
        {
            SVF_Shift_Data shift_data = {(yyvsp[-2].u), (yyvsp[-1].string), NULL, (yyvsp[0].string), NULL};
            (yyval.shift_data) = shift_data;
        }
#line 2017 "src/parser.c"
    break;

  case 69:
#line 420 "grammars/svf.y"
        {
            SVF_Shift_Data shift_data = {(yyvsp[-2].u), (yyvsp[-1].string), NULL, NULL, (yyvsp[0].string)};
            (yyval.shift_data) = shift_data;
        }
#line 2026 "src/parser.c"
    break;

  case 70:
#line 425 "grammars/svf.y"
        {
            SVF_Shift_Data shift_data = {(yyvsp[-3].u), (yyvsp[-2].string), (yyvsp[-1].string), (yyvsp[0].string), NULL};
            (yyval.shift_data) = shift_data;
        }
#line 2035 "src/parser.c"
    break;

  case 71:
#line 430 "grammars/svf.y"
        {
            SVF_Shift_Data shift_data = {(yyvsp[-3].u), (yyvsp[-2].string), (yyvsp[-1].string), NULL, (yyvsp[0].string)};
            (yyval.shift_data) = shift_data;
        }
#line 2044 "src/parser.c"
    break;

  case 72:
#line 435 "grammars/svf.y"
        {
            SVF_Shift_Data shift_data = {(yyvsp[-3].u), (yyvsp[-2].string), NULL, (yyvsp[-1].string), (yyvsp[0].string)};
            (yyval.shift_data) = shift_data;
        }
#line 2053 "src/parser.c"
    break;

  case 73:
#line 440 "grammars/svf.y"
        {
            SVF_Shift_Data shift_data = {(yyvsp[-4].u), (yyvsp[-3].string), (yyvsp[-2].string), (yyvsp[-1].string), (yyvsp[0].string)};
            (yyval.shift_data) = shift_data;
        }
#line 2062 "src/parser.c"
    break;

  case 74:
#line 446 "grammars/svf.y"
            {
                (yyval.list) = create_list();
                unsigned long val = (yyvsp[0].u);
                list_append((yyval.list), (void*) val);
            }
#line 2072 "src/parser.c"
    break;

  case 75:
#line 452 "grammars/svf.y"
            {
                unsigned long val = (yyvsp[-1].u);
                list_append((yyvsp[0].list), (void*) val);
                (yyval.list) = (yyvsp[0].list);
            }
#line 2082 "src/parser.c"
    break;

  case 76:
#line 459 "grammars/svf.y"
        {
            (yyval.d) = (yyvsp[-1].d);
        }
#line 2090 "src/parser.c"
    break;

  case 79:
#line 465 "grammars/svf.y"
        {
            (yyval.d) = (yyvsp[-1].d);
        }
#line 2098 "src/parser.c"
    break;

  case 80:
#line 469 "grammars/svf.y"
        {
            (yyval.d) = (yyvsp[-1].d);
        }
#line 2106 "src/parser.c"
    break;

  case 81:
#line 474 "grammars/svf.y"
            {
                (yyval.u) = (yyvsp[0].u);
            }
#line 2114 "src/parser.c"
    break;


#line 2118 "src/parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 479 "grammars/svf.y"


int yywrap()
{
    return(1);
}
