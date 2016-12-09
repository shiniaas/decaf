%{
    #include <stdio.h>
    #include "lex.yy.c"
    #ifndef Tree
    	#include "tree.h"
    #endif
    void yyerror (char const *);
    extern FILE* yyin;
%}

%union{
	struct Ast* a;
}
/* declared types */
%token <a> INTCONST BOOLCONST STRINGCONST
%token <a> IDENTIFIER
%token <a> KINT KBOOL KSTRING KVOID KCLASS KSTATIC KEXTENDS KFOR KWHILE KIF KELSE KRETURN KBREAK KPRINT KTHIS KREADINTEGER KREADLINE KNEW KINSTANCEOF KNULL
%token <a> OLB ORB OADD OSUB OMUL ODIV OIDIV OLT OLE OGT OGE OEQU ONE OAND OOR ONOT OASSIGN
%token <a> PLBB PRBB PCOMMA PLBBB PRBBB PSEP PPOINT
%type <a> Program ClassDefList VariableDef Variable Type Formals VariableList FunctionDef ClassDef FieldList Field StmtBlock StmtList Stmt
%type <a> SimpleStmt LValue Call Actuals ExprList ForStmt WhileStmt IfStmt ReturnStmt BreakStmt PrintStmt BoolExpr Expr Constant

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

%start Program
%%
Program : 
		ClassDef ClassDefList {$$=new_ast("Program", 2, $1, $2); print_tree($$, 0); print_symtable();}
        ;
ClassDefList : 
		ClassDef ClassDefList {$$=new_ast("ClassDefList", 2, $1, $2);}
        | {$$=new_ast("ExtClassDefList", 0, -1);}
        ;
VariableDef : 
		Variable PSEP {$$=new_ast("VariableDef", 2, $1, $2);}
        ;
Variable : 
		Type IDENTIFIER {$$=new_ast("Variable", 2, $1, $2);}
		;
Type : 
		KINT {$$=new_ast("Type", 1, $1);}
		|KBOOL {$$=new_ast("Type", 1, $1);}
		|KSTRING {$$=new_ast("Type", 1, $1);}
		|KVOID {$$=new_ast("Type", 1, $1);}
		|KCLASS IDENTIFIER {$$=new_ast("Type", 2, $1, $2);}
		|Type PLBB PRBB {$$=new_ast("Type", 3, $1, $2, $3);}
		;
Formals :
		Variable VariableList {$$=new_ast("Formals", 2, $1, $2);}
		| {$$=new_ast("ExtFormals", 0, -1);}
		;
VariableList :
		PCOMMA Variable VariableList {$$=new_ast("VariableList", 3, $1, $2, $3);}
		| {$$=new_ast("ExtVariableList", 0, -1);}
		;
FunctionDef : 
		KSTATIC Type IDENTIFIER OLB Formals ORB StmtBlock {$$=new_ast("FunctionDef", 7, $1, $2, $3, $4, $5, $6, $7);}
		|Type IDENTIFIER OLB Formals ORB StmtBlock {$$=new_ast("FunctionDef", 6, $1, $2, $3, $4, $5, $6);}
		;
ClassDef :
		KCLASS IDENTIFIER KEXTENDS IDENTIFIER PLBBB FieldList PRBBB {$$=new_ast("ClassDef", 7, $1, $2, $3, $4, $5, $6, $7);}
		|KCLASS IDENTIFIER PLBBB FieldList PRBBB {$$=new_ast("ClassDef", 5, $1, $2, $3, $4, $5);}
		;
FieldList :
		Field FieldList {$$=new_ast("FieldList", 2, $1, $2);}
		| {$$=new_ast("ExtFieldList", 0, -1);}
		;
Field :
		VariableDef {$$=new_ast("Field", 1, $1);}
		|FunctionDef {$$=new_ast("Field", 1, $1);}
		;
StmtBlock :
		PLBBB StmtList PRBBB {$$=new_ast("StmtBlock", 3, $1, $2, $3);}
		;
StmtList :
		Stmt StmtList {$$=new_ast("StmtList", 2, $1, $2);}
		| {$$=new_ast("ExtStmtList", 0, -1);}
		;
Stmt :
		VariableDef {$$=new_ast("Stmt", 1, $1);}
		|SimpleStmt PSEP {$$=new_ast("Stmt", 2, $1, $2);}
		|IfStmt {$$=new_ast("Stmt", 1, $1);}
		|WhileStmt {$$=new_ast("Stmt", 1, $1);}
		|ForStmt {$$=new_ast("Stmt", 1, $1);}
		|BreakStmt PSEP {$$=new_ast("Stmt", 2, $1, $2);}
		|ReturnStmt PSEP {$$=new_ast("Stmt", 2, $1, $2);}
		|PrintStmt PSEP {$$=new_ast("Stmt", 2, $1, $2);}
		|StmtBlock {$$=new_ast("Stmt", 1, $1);}
		;
SimpleStmt :
		LValue OASSIGN Expr {$$=new_ast("SimpleStmt", 3, $1, $2, $3);}
		|Call {$$=new_ast("SimpleStmt", 1, $1);}
		| {$$=new_ast("ExtSimpleStmt", 0, -1);}
		;
LValue :
		Expr PPOINT IDENTIFIER {$$=new_ast("LValue", 3, $1, $2, $3);}
		|IDENTIFIER {$$=new_ast("LValue", 1, $1);}
		|Expr PLBB Expr PRBB {$$=new_ast("LValue", 4, $1, $2, $3, $4);}
		;

Call :
		Expr PPOINT IDENTIFIER OLB Actuals ORB {$$=new_ast("Call", 6, $1, $2, $3, $4, $5, $6);}
		|IDENTIFIER OLB Actuals ORB {$$=new_ast("Call", 4, $1, $2, $3, $4);}
Actuals :
		Expr ExprList {$$=new_ast("Actuals", 2, $1, $2);}
		| {$$=new_ast("ExtActuals", 0, -1);}
		;
ExprList :
		PCOMMA Expr ExprList {$$=new_ast("ExprList", 3, $1, $2, $3);}
		| {$$=new_ast("ExtExprList", 0, -1);}
		;
ForStmt :
		KFOR OLB SimpleStmt PSEP BoolExpr PSEP SimpleStmt ORB Stmt {$$=new_ast("ForStmt", 9, $1, $2, $3, $4, $5, $6, $7, $8, $9);}
		;
WhileStmt :
		KWHILE OLB BoolExpr ORB Stmt {$$=new_ast("WhileStmt", 5, $1, $2, $3, $4, $5);}
		;
IfStmt :
		KIF OLB BoolExpr ORB Stmt KELSE Stmt {$$=new_ast("IfStmt", 7, $1, $2, $3, $4, $5, $6, $7);}
		|KIF OLB BoolExpr ORB Stmt %prec LOWER_THAN_KELSE {$$=new_ast("IfStmt", 5, $1, $2, $3, $4, $5);}
		;
ReturnStmt :
		KRETURN {$$=new_ast("ReturnStmt", 1, $1);}
		|KRETURN Expr {$$=new_ast("ReturnStmt", 2, $1, $2);}
		;
BreakStmt :
		KBREAK {$$=new_ast("BreakStmt", 1, $1);}
		;
PrintStmt :
		KPRINT OLB Expr ExprList ORB {$$=new_ast("PrintStmt", 5, $1, $2, $3, $4, $5);}
		;
BoolExpr :
		Expr {$$=new_ast("BoolExpr", 1, $1);}
		;
Expr :
		Constant {$$=new_ast("Expr", 1, $1);}
		|LValue {$$=new_ast("Expr", 1, $1);}
		|KTHIS {$$=new_ast("Expr", 1, $1);}
		|Call {$$=new_ast("Expr", 1, $1);}
		|OLB Expr ORB {$$=new_ast("Expr", 3, $1, $2, $3);}
		|Expr OADD Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|Expr OSUB Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|Expr OMUL Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|Expr ODIV Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|Expr OIDIV Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|OSUB Expr %prec OMUL {$$=new_ast("Expr", 2, $1, $2);}
		|Expr OLT Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|Expr OLE Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|Expr OGT Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|Expr OGE Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|Expr OEQU Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|Expr ONE Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|Expr OAND Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|Expr OOR Expr {$$=new_ast("Expr", 3, $1, $2, $3);}
		|ONOT Expr {$$=new_ast("Expr", 2, $1, $2);}
		|KREADINTEGER OLB ORB {$$=new_ast("Expr", 3, $1, $2, $3);}
		|KREADLINE OLB ORB {$$=new_ast("Expr", 3, $1, $2, $3);}
		|KNEW IDENTIFIER OLB ORB {$$=new_ast("Expr", 4, $1, $2, $3, $4);}
		|KNEW Type PLBB Expr PRBB {$$=new_ast("Expr", 5, $1, $2, $3, $4, $5);}
		|KINSTANCEOF OLB Expr PCOMMA IDENTIFIER ORB {$$=new_ast("Expr", 6, $1, $2, $3, $4, $5, $6);}
		|OLB KCLASS IDENTIFIER ORB Expr {$$=new_ast("Expr", 5, $1, $2, $3, $4, $5);}
		;
Constant :
		INTCONST {$$=new_ast("Constant", 1, $1);}
		|BOOLCONST {$$=new_ast("Constant", 1, $1);}
		|STRINGCONST {$$=new_ast("Constant", 1, $1);}
		|KNULL {$$=new_ast("Constant", 1, $1);}
		;

%%

int main(int argc, char **argv)
{
	if(argc <= 1)
	{
		return 1;
	}
	FILE* f = fopen(argv[1], "r");
	if(!f)
	{
		perror(argv[1]);
		return 1;
	}
	//yydebug = 1;
	yyrestart(f);
	yyparse();
    return 0;
}

void yyerror(const char *s)
{
    printf("Line %d:%s\n",yylineno,s);
}
