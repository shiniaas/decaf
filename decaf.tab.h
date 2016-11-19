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
     IDENTIFIER = 258,
     KINT = 259,
     KBOOL = 260,
     KSTRING = 261,
     KVOID = 262,
     KCLASS = 263,
     PLBB = 264,
     PRBB = 265,
     PCOMMA = 266,
     KSTATIC = 267,
     OLB = 268,
     ORB = 269,
     KEXTENDS = 270,
     PLBBB = 271,
     PRBBB = 272,
     PSEP = 273,
     KFOR = 274,
     KWHILE = 275,
     KIF = 276,
     KELSE = 277,
     KRETURN = 278,
     KBREAK = 279,
     KPRINT = 280,
     KTHIS = 281,
     OADD = 282,
     OSUB = 283,
     OMUL = 284,
     ODIV = 285,
     OIDIV = 286,
     OLT = 287,
     OLE = 288,
     OGT = 289,
     OGE = 290,
     OEQU = 291,
     ONE = 292,
     OAND = 293,
     OOR = 294,
     ONOT = 295,
     KREADINTEGER = 296,
     KREADLINE = 297,
     KNEW = 298,
     KINSTANCEOF = 299,
     INTCONST = 300,
     BOOLCONST = 301,
     STRINGCONST = 302,
     KNULL = 303,
     OASSIGN = 304,
     PPOINT = 305,
     LOWER_THAN_KELSE = 306
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define KINT 259
#define KBOOL 260
#define KSTRING 261
#define KVOID 262
#define KCLASS 263
#define PLBB 264
#define PRBB 265
#define PCOMMA 266
#define KSTATIC 267
#define OLB 268
#define ORB 269
#define KEXTENDS 270
#define PLBBB 271
#define PRBBB 272
#define PSEP 273
#define KFOR 274
#define KWHILE 275
#define KIF 276
#define KELSE 277
#define KRETURN 278
#define KBREAK 279
#define KPRINT 280
#define KTHIS 281
#define OADD 282
#define OSUB 283
#define OMUL 284
#define ODIV 285
#define OIDIV 286
#define OLT 287
#define OLE 288
#define OGT 289
#define OGE 290
#define OEQU 291
#define ONE 292
#define OAND 293
#define OOR 294
#define ONOT 295
#define KREADINTEGER 296
#define KREADLINE 297
#define KNEW 298
#define KINSTANCEOF 299
#define INTCONST 300
#define BOOLCONST 301
#define STRINGCONST 302
#define KNULL 303
#define OASSIGN 304
#define PPOINT 305
#define LOWER_THAN_KELSE 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

