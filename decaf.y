%{
    #include <stdio.h>
    #include "lex.yy.c"
%}

%token IDENTIFIER KINT KBOOL KSTRING KVOID KCLASS PLBB PRBB PCOMMA KSTATIC OLB ORB KEXTENDS PLBBB PRBBB PSEP KFOR KWHILE KIF KELSE KRETURN KBREAK KPRINT KTHIS
%token OADD OSUB OMUL ODIV OIDIV OLT OLE OGT OGE OEQU ONE OAND OOR ONOT KREADINTEGER KREADLINE KNEW KINSTANCEOF INTCONST BOOLCONST STRINGCONST KNULL
%token OASSIGN PPOINT

%nonassoc LOWER_THAN_KELSE
%nonassoc KELSE
%right OASSIGN 
%left OOR
%left OAND
%left OEQU ONE
%left OLT OLE OGT OGE
%left OADD OSUB
%left OMUL ODIV OIDIV
%right ONOT
%left OLB ORB PLBB PRBB PPOINT


%%
Program : 
		ClassDef ClassDefList
        ;
ClassDefList : 
		ClassDef ClassDefList
        |
        ;
VariableDef : 
		Variable PSEP
        ;
Variable : 
		Type IDENTIFIER
		;
Type : 
		KINT
		|KBOOL
		|KSTRING
		|KVOID
		|KCLASS IDENTIFIER
		|Type PLBB PRBB 
		;
Formals :
		Variable VariableList
		|
		;
VariableList :
		PCOMMA Variable VariableList
		|
		;
FunctionDef : 
		KSTATIC Type IDENTIFIER OLB Formals ORB StmtBlock
		|Type IDENTIFIER OLB Formals ORB StmtBlock
		;
ClassDef :
		KCLASS IDENTIFIER KEXTENDS IDENTIFIER PLBBB FieldList PRBBB
		|KCLASS IDENTIFIER PLBBB FieldList PRBBB
		;
FieldList :
		Field FieldList
		|
		;
Field :
		VariableDef
		|FunctionDef
		;
StmtBlock :
		PLBBB StmtList PRBBB
		;
StmtList :
		Stmt StmtList
		|
		;
Stmt :
		VariableDef
		|SimpleStmt PSEP
		|IfStmt
		|WhileStmt
		|ForStmt
		|BreakStmt PSEP
		|ReturnStmt PSEP
		|PrintStmt PSEP
		|StmtBlock
		;
SimpleStmt :
		LValue OASSIGN Expr
		|Call
		|
		;
LValue :
		Expr PPOINT IDENTIFIER
		|IDENTIFIER
		|Expr PLBB Expr PRBB
		;

Call :
		Expr PPOINT IDENTIFIER OLB Actuals ORB
		|IDENTIFIER OLB Actuals ORB
Actuals :
		Expr ExprList
		|
		;
ExprList :
		PCOMMA Expr ExprList
		|
		;
ForStmt :
		KFOR OLB SimpleStmt PSEP BoolExpr PSEP SimpleStmt ORB Stmt
		;
WhileStmt :
		KWHILE OLB BoolExpr ORB Stmt
		;
IfStmt :
		KIF OLB BoolExpr ORB Stmt KELSE Stmt
		|KIF OLB BoolExpr ORB Stmt %prec LOWER_THAN_KELSE
		;
ReturnStmt :
		KRETURN
		|KRETURN Expr
		;
BreakStmt :
		KBREAK
		;
PrintStmt :
		KPRINT OLB Expr ExprList ORB
		;
BoolExpr :
		Expr
		;
Expr :
		Constant
		|LValue
		|KTHIS
		|Call
		|OLB Expr ORB
		|Expr OADD Expr
		|Expr OSUB Expr
		|Expr OMUL Expr
		|Expr ODIV Expr
		|Expr OIDIV Expr
		|OSUB Expr %prec OMUL
		|Expr OLT Expr
		|Expr OLE Expr
		|Expr OGT Expr
		|Expr OGE Expr
		|Expr OEQU Expr
		|Expr ONE Expr
		|Expr OAND Expr
		|Expr OOR Expr
		|ONOT Expr
		|KREADINTEGER OLB ORB
		|KREADLINE OLB ORB
		|KNEW IDENTIFIER OLB ORB
		|KNEW Type PLBB Expr PRBB
		|KINSTANCEOF OLB Expr PCOMMA IDENTIFIER ORB
		|OLB KCLASS IDENTIFIER ORB Expr
		;
Constant :
		INTCONST
		|BOOLCONST
		|STRINGCONST
		|KNULL
		;

%%

yyerror(char *s)
{
    printf("type B at Line %d:%s\n",yylineno,s);
}
