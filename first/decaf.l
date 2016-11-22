
%{
    
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
INTCONSTDEC [+-]?{DIGIT}+
INTCONSTHEX [+-]?0[Xx]([0-9a-fA-F])+
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
{KBOOL} {printf("keyword %s\n", yytext);}
{KBREAK} {printf("keyword %s\n", yytext);}
{KCLASS} {printf("keyword %s\n", yytext);}
{KELSE} {printf("keyword %s\n", yytext);}
{KEXTENDS} {printf("keyword %s\n", yytext);}
{KFOR} {printf("keyword %s\n", yytext);}
{KIF} {printf("keyword %s\n", yytext);}
{KINT} {printf("keyword %s\n", yytext);}
{KNEW} {printf("keyword %s\n", yytext);}
{KNULL} {printf("keyword %s\n", yytext);}
{KRETURN} {printf("keyword %s\n", yytext);}
{KSTRING} {printf("keyword %s\n", yytext);}
{KTHIS} {printf("keyword %s\n", yytext);}
{KVOID} {printf("keyword %s\n", yytext);}
{KWHILE} {printf("keyword %s\n", yytext);}
{KSTATIC} {printf("keyword %s\n", yytext);}
{KPRINT} {printf("keyword %s\n", yytext);}
{KREADINTEGER} {printf("keyword %s\n", yytext);}
{KINSTANCEOF} {printf("keyword %s\n", yytext);}
{BOOLCONST} {printf("boolconst %s\n", yytext);}
{IDENTIFIER} {printf("identifier %s\n", yytext);}
{INTCONSTDEC} {printf("intconstdec %s\n", yytext);}
{INTCONSTHEX} {printf("intconsthex %s\n", yytext);}
{STRINGCONST} {printf("stringconst %s\n", yytext);}
{OADD} {printf("operator %s\n", yytext);}
{OSUB} {printf("operator %s\n", yytext);}
{OMUL} {printf("operator %s\n", yytext);}
{ODIV} {printf("operator %s\n", yytext);}
{OIDIV} {printf("operator %s\n", yytext);}
{OLE} {printf("operator %s\n", yytext);}
{OLT} {printf("operator %s\n", yytext);}
{OGE} {printf("operator %s\n", yytext);}
{OGT} {printf("operator %s\n", yytext);}
{OEQU} {printf("operator %s\n", yytext);}
{OASSIGN} {printf("operator %s\n", yytext);}
{ONE} {printf("operator %s\n", yytext);}
{OAND} {printf("operator %s\n", yytext);}
{OOR} {printf("operator %s\n", yytext);}
{ONOT} {printf("operator %s\n", yytext);}
{OLB} {printf("operator %s\n", yytext);}
{ORB} {printf("operator %s\n", yytext);}
{PPOINT} {printf("punctuation %s\n", yytext);}
{PSEP} {printf("punctuation %s\n", yytext);}
{PCOMMA} {printf("punctuation %s\n", yytext);}
{PLBB} {printf("punctuation %s\n", yytext);}
{PRBB} {printf("punctuation %s\n", yytext);}
{PLBBB} {printf("punctuation %s\n", yytext);}
{PRBBB} {printf("punctuation %s\n", yytext);}
{COMMENT} {printf("comment %s\n",yytext);}
{SPACE} {;}
. {printf("Error type at line %d:Mysterious characters \'%s\'\n",yylineno, yytext);}
%%