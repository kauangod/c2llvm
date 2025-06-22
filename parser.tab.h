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
    DOUBLE = 258,                  /* DOUBLE  */
    INT = 259,                     /* INT  */
    CHARACTER = 260,               /* CHARACTER  */
    PLUS = 261,                    /* PLUS  */
    MINUS = 262,                   /* MINUS  */
    DIVIDE = 263,                  /* DIVIDE  */
    TIMES = 264,                   /* TIMES  */
    LEFT = 265,                    /* LEFT  */
    RIGHT = 266,                   /* RIGHT  */
    DONE = 267,                    /* DONE  */
    ID = 268,                      /* ID  */
    STRING = 269,                  /* STRING  */
    EQUALS = 270,                  /* EQUALS  */
    AND = 271,                     /* AND  */
    OR = 272,                      /* OR  */
    GT = 273,                      /* GT  */
    GE = 274,                      /* GE  */
    LT = 275,                      /* LT  */
    LE = 276,                      /* LE  */
    l_EQUALS = 277,                /* l_EQUALS  */
    DIF = 278,                     /* DIF  */
    NOT = 279,                     /* NOT  */
    B_LEFT = 280,                  /* B_LEFT  */
    B_RIGHT = 281,                 /* B_RIGHT  */
    IF = 282,                      /* IF  */
    ELSE = 283,                    /* ELSE  */
    WHILE = 284,                   /* WHILE  */
    INTtype = 285,                 /* INTtype  */
    FLOATtype = 286,               /* FLOATtype  */
    BOOLEANtype = 287,             /* BOOLEANtype  */
    CHARtype = 288,                /* CHARtype  */
    writeCommand = 289,            /* writeCommand  */
    readCommand = 290,             /* readCommand  */
    returnCommand = 291            /* returnCommand  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "parser.y"

  char character;
  char* name;
  double doubleValue;
  int intValue;

#line 107 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
