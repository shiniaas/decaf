
%{
    #include "decaf.tab.h"
    #include "tree.h"
%}
%option yylineno
KEYWORD bool|break|class|else|extends|for|if|int|new|null|return|string|this|void|while|static|Print|ReadInteger|instanceof
KBOOL bool
KBREAK break
KCLASS class
KELSE else
KEXTENDS extends
KFOR for
KIF if
KINT int
KNEW new
KNULL null
KRETURN return
KSTRING string
KTHIS this
KVOID void
KWHILE while
KSTATIC static
KPRINT Print
KREADINTEGER ReadInteger
KINSTANCEOF instanceof
DIGIT [0-9]
LETTER [a-zA-Z]
IDENTIFIER {LETTER}[_0-9a-zA-Z]*
SPACE [ \t\n]
BOOLCONST true|false
INTCONSTDEC {DIGIT}+
INTCONSTHEX 0[Xx]([0-9a-fA-F])+
INTCONST {INTCONSTDEC}|{INTCONSTHEX}
STRINGCONST \"[^(\n\")]*\"
OPERATOR \+|\-|\*|\/|\%|\<|\<\=|\>|\>\=|\=|\=\=|\!\=|\&\&|\|\||\!|\(|\)
OADD \+
OSUB \-
OMUL \*
ODIV \/
OIDIV \%
OLT \<
OLE \<\=
OGT \>
OGE \>\=
OASSIGN \=
OEQU \=\=
ONE \!\=
OAND \&\&
OOR \|\|
ONOT \!
OLB \(
ORB \)
PUNCTUATION [\.\;\,\[\]\{\}]
PPOINT \.
PSEP \;
PCOMMA \,
PLBB \[
PRBB \]     
PLBBB \{
PRBBB \}
COMMENT \/\/.*

%%
{KBOOL} {yylval.a = new_ast("TYPE", 0, yylineno);return KBOOL;}
{KBREAK} {yylval.a = new_ast("KBREAK", 0, yylineno);return KBREAK;}
{KCLASS} {yylval.a = new_ast("KCLASS", 0, yylineno);return KCLASS;}
{KELSE} {yylval.a = new_ast("KELSE", 0, yylineno);return KELSE;}
{KEXTENDS} {yylval.a = new_ast("KEXTENDS", 0, yylineno);return KEXTENDS;}
{KFOR} {yylval.a = new_ast("KFOR", 0, yylineno);return KFOR;}
{KIF} {yylval.a = new_ast("KIF", 0, yylineno);return KIF;}
{KINT} {yylval.a = new_ast("TYPE", 0, yylineno);return KINT;}
{KNEW} {yylval.a = new_ast("KNEW", 0, yylineno);return KNEW;}
{KNULL} {yylval.a = new_ast("KNULL", 0, yylineno);return KNULL;}
{KRETURN} {yylval.a = new_ast("KRETURN", 0, yylineno);return KRETURN;}
{KSTRING} {yylval.a = new_ast("TYPE", 0, yylineno);return KSTRING;}
{KTHIS} {yylval.a = new_ast("KTHIS", 0, yylineno);return KTHIS;}
{KVOID} {yylval.a = new_ast("TYPE", 0, yylineno);return KVOID;}
{KWHILE} {yylval.a = new_ast("KWHILE", 0, yylineno);return KWHILE;}
{KSTATIC} {yylval.a = new_ast("KSTATIC", 0, yylineno);return KSTATIC;}
{KPRINT} {yylval.a = new_ast("KPRINT", 0, yylineno);return KPRINT;}
{KREADINTEGER} {yylval.a = new_ast("KREADINTEGER", 0, yylineno);return KREADINTEGER;}
{KINSTANCEOF} {yylval.a = new_ast("KINSTANCEOF", 0, yylineno);return KINSTANCEOF;}
{OADD} {yylval.a = new_ast("OADD", 0, yylineno);return OADD;}
{OSUB} {yylval.a = new_ast("OSUB", 0, yylineno);return OSUB;}
{OMUL} {yylval.a = new_ast("OMUL", 0, yylineno);return OMUL;}
{ODIV} {yylval.a = new_ast("ODIV", 0, yylineno);return ODIV;}
{OIDIV} {yylval.a = new_ast("OIDIV", 0, yylineno);return OIDIV;}
{OLE} {yylval.a = new_ast("OLE", 0, yylineno);return OLE;}
{OLT} {yylval.a = new_ast("OLT", 0, yylineno);return OLT;}
{OGE} {yylval.a = new_ast("OGE", 0, yylineno);return OGE;}
{OGT} {yylval.a = new_ast("OGT", 0, yylineno);return OGT;}
{OEQU} {yylval.a = new_ast("OEQU", 0, yylineno);return OEQU;}
{OASSIGN} {yylval.a = new_ast("OASSIGN", 0, yylineno);return OASSIGN;}
{ONE} {yylval.a = new_ast("ONE", 0, yylineno);return ONE;}
{OAND} {yylval.a = new_ast("OAND", 0, yylineno);return OAND;}
{OOR} {yylval.a = new_ast("OOR", 0, yylineno);return OOR;}
{ONOT} {yylval.a = new_ast("ONOT", 0, yylineno);return ONOT;}
{OLB} {yylval.a = new_ast("OLB", 0, yylineno);return OLB;}
{ORB} {yylval.a = new_ast("ORB", 0, yylineno);return ORB;}
{BOOLCONST} {yylval.a = new_ast("bool", 0, yylineno);return BOOLCONST;}
{IDENTIFIER} {yylval.a = new_ast("IDENTIFIER", 0, yylineno);return IDENTIFIER;}
{INTCONST} {yylval.a = new_ast("int", 0, yylineno);return INTCONST;}
{STRINGCONST} {yylval.a = new_ast("string", 0, yylineno);return STRINGCONST;}
{PPOINT} {yylval.a = new_ast("PPOINT", 0, yylineno);return PPOINT;}
{PSEP} {yylval.a = new_ast("PSEP", 0, yylineno);return PSEP;}
{PCOMMA} {yylval.a = new_ast("PCOMMA", 0, yylineno);return PCOMMA;}
{PLBB} {yylval.a = new_ast("PLBB", 0, yylineno);return PLBB;}
{PRBB} {yylval.a = new_ast("PRBB", 0, yylineno);return PRBB;}
{PLBBB} {yylval.a = new_ast("PLBBB", 0, yylineno);return PLBBB;}
{PRBBB} {yylval.a = new_ast("PRBBB", 0, yylineno);return PRBBB;}
{SPACE} {;}
{COMMENT} {;}
. {printf("Error type at line %d:Mysterious characters \'%s\'\n",yylineno, yytext);}
%%


