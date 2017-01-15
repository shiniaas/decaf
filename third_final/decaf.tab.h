/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     INTCONST = 258,
     BOOLCONST = 259,
     STRINGCONST = 260,
     IDENTIFIER = 261,
     KINT = 262,
     KBOOL = 263,
     KSTRING = 264,
     KVOID = 265,
     KCLASS = 266,
     KSTATIC = 267,
     KEXTENDS = 268,
     KFOR = 269,
     KWHILE = 270,
     KIF = 271,
     KELSE = 272,
     KRETURN = 273,
     KBREAK = 274,
     KPRINT = 275,
     KTHIS = 276,
     KREADINTEGER = 277,
     KREADLINE = 278,
     KNEW = 279,
     KINSTANCEOF = 280,
     KNULL = 281,
     OLB = 282,
     ORB = 283,
     OADD = 284,
     OSUB = 285,
     OMUL = 286,
     ODIV = 287,
     OIDIV = 288,
     OLT = 289,
     OLE = 290,
     OGT = 291,
     OGE = 292,
     OEQU = 293,
     ONE = 294,
     OAND = 295,
     OOR = 296,
     ONOT = 297,
     OASSIGN = 298,
     PLBB = 299,
     PRBB = 300,
     PCOMMA = 301,
     PLBBB = 302,
     PRBBB = 303,
     PSEP = 304,
     PPOINT = 305,
     LOWER_THAN_KELSE = 306
   };
#endif
/* Tokens.  */
#define INTCONST 258
#define BOOLCONST 259
#define STRINGCONST 260
#define IDENTIFIER 261
#define KINT 262
#define KBOOL 263
#define KSTRING 264
#define KVOID 265
#define KCLASS 266
#define KSTATIC 267
#define KEXTENDS 268
#define KFOR 269
#define KWHILE 270
#define KIF 271
#define KELSE 272
#define KRETURN 273
#define KBREAK 274
#define KPRINT 275
#define KTHIS 276
#define KREADINTEGER 277
#define KREADLINE 278
#define KNEW 279
#define KINSTANCEOF 280
#define KNULL 281
#define OLB 282
#define ORB 283
#define OADD 284
#define OSUB 285
#define OMUL 286
#define ODIV 287
#define OIDIV 288
#define OLT 289
#define OLE 290
#define OGT 291
#define OGE 292
#define OEQU 293
#define ONE 294
#define OAND 295
#define OOR 296
#define ONOT 297
#define OASSIGN 298
#define PLBB 299
#define PRBB 300
#define PCOMMA 301
#define PLBBB 302
#define PRBBB 303
#define PSEP 304
#define PPOINT 305
#define LOWER_THAN_KELSE 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 9 "decaf.y"
{
	struct Ast* a;
}
/* Line 1529 of yacc.c.  */
#line 155 "decaf.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

