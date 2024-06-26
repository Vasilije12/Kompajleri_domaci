
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     THEN = 259,
     ELSE = 260,
     CONTINUE = 261,
     WHILE = 262,
     FOR = 263,
     BREAK = 264,
     INT = 265,
     DOUBLE = 266,
     STRING = 267,
     T_TRUE = 268,
     T_FALSE = 269,
     T_ID = 270,
     T_INT = 271,
     T_DOUBLE = 272,
     T_STRING = 273,
     T_PLUS = 274,
     T_MINUS = 275,
     T_MNOZENJE = 276,
     T_DIJELJENJE = 277,
     T_MOD = 278,
     T_BACKSLASH = 279,
     T_MANJE = 280,
     T_MANJE_JEDNAKO = 281,
     T_VECE = 282,
     T_VECE_JEDNAKO = 283,
     T_DODJELE = 284,
     T_JEDNAKOSTI = 285,
     T_NEJEDNAKOSTI = 286,
     T_AND = 287,
     T_OR = 288,
     T_NOT = 289,
     T_SC = 290,
     T_ZAREZ = 291,
     T_TACKA = 292,
     T_DESNAZ = 293,
     T_LIJEVAZ = 294,
     LET = 295,
     IN = 296,
     END = 297,
     FI = 298,
     DO = 299,
     READ = 300,
     WRITE = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 21 "Pmf0.y"

    int int_value;
    double double_value;
    char* string_value;
    char* ident;
    int bool_value;
    




/* Line 1676 of yacc.c  */
#line 110 "Pmf0.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


