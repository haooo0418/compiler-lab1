
%option yylineno
%{

#include "treenode.h"
  #include "syntax.tab.h"
#include <string.h>
#include <stdlib.h>
extern int error_num;
%}


SEMI       ";"
COMMA      ","
ASSIGNOP   "="
RELOP      ">"|"<"|">="|"<="|"=="|"!="
PLUS       "+"
MINUS      "-"
STAR       "*"
DIV        "/"
AND        "&&"
OR         "||"
DOT        "."
NOT        "!"

TYPE       int|float
LP         "("
RP         ")"
LB         "["
RB         "]"
LC         "{"
RC         "}"
STRUCT     struct
RETURN     return
IF         if
ELSE       else
WHILE      while


HEXADECIMAL 0[xX][0-9A-Fa-f]+
OCTONARY    0[0-7]+
INT         ([1-9][0-9]*)|0

FLOAT       ([0-9]+\\.[0-9]*|\\.[0-9]+)([Ee][+-]?[0-9]+)?
ID          [_a-zA-Z][_a-zA-Z0-9]*
WHITESPACE  [ \t\r] 

%%

\n              { }  
{WHITESPACE}+  { /* 跳过空格 */ }
{SEMI}         { yylval.node = createTreeNode("SEMI", yylineno, ""); return SEMI; }
{COMMA}        { yylval.node = createTreeNode("COMMA", yylineno, ""); return COMMA; }
{ASSIGNOP}     { yylval.node = createTreeNode("ASSIGNOP", yylineno, ""); return ASSIGNOP; }
{RELOP}        { yylval.node = createTreeNode("RELOP", yylineno, yytext); return RELOP; }
{PLUS}         { yylval.node = createTreeNode("PLUS", yylineno, ""); return PLUS; }
{MINUS}        { yylval.node = createTreeNode("MINUS", yylineno, ""); return MINUS; }
{STAR}         { yylval.node = createTreeNode("STAR", yylineno, ""); return STAR; }
{DIV}          { yylval.node = createTreeNode("DIV", yylineno, ""); return DIV; }
{AND}          { yylval.node = createTreeNode("AND", yylineno, ""); return AND; }
{OR}           { yylval.node = createTreeNode("OR", yylineno, ""); return OR; }
{DOT}          { yylval.node = createTreeNode("DOT", yylineno, ""); return DOT; }
{NOT}          { yylval.node = createTreeNode("NOT", yylineno, ""); return NOT; }

{LP}           { yylval.node = createTreeNode("LP", yylineno, ""); return LP; }
{RP}           { yylval.node = createTreeNode("RP", yylineno, ""); return RP; }
{LB}           { yylval.node = createTreeNode("LB", yylineno, ""); return LB; }
{RB}           { yylval.node = createTreeNode("RB", yylineno, ""); return RB; }
{LC}           { yylval.node = createTreeNode("LC", yylineno, ""); return LC; }
{RC}           { yylval.node = createTreeNode("RC", yylineno, ""); return RC; }
{STRUCT}       { yylval.node = createTreeNode("STRUCT", yylineno, ""); return STRUCT; }
{RETURN}       { yylval.node = createTreeNode("RETURN", yylineno, ""); return RETURN; }
{IF}           { yylval.node = createTreeNode("IF", yylineno, ""); return IF; }
{ELSE}         { yylval.node = createTreeNode("ELSE", yylineno, ""); return ELSE; }
{WHILE}        { yylval.node = createTreeNode("WHILE", yylineno, ""); return WHILE; }
{TYPE}         { yylval.node = createTreeNode("TYPE", yylineno, yytext); return TYPE; }
{ID}           { yylval.node = createTreeNode("ID", yylineno, yytext); return ID; }
{HEXADECIMAL}  {
                 
                  char val[50]; long tmp = strtol(yytext, NULL, 16);
                  sprintf(val, "%ld", tmp);
                  yylval.node = createTreeNode("INT", yylineno, val);
                  return INT;
                }
{OCTONARY}     {
                  
                  char val[50]; long tmp = strtol(yytext, NULL, 8);
                  sprintf(val, "%ld", tmp);
                  yylval.node = createTreeNode("INT", yylineno, val);
                  return INT;
                }
{INT}          { yylval.node = createTreeNode("INT", yylineno, yytext); return INT; }
{FLOAT}        {
                  
                  yylval.node = createTreeNode("FLOAT", yylineno, yytext);
                  return FLOAT;
                }
.              {
                 
                  error_num++;
                  
                  fprintf(stderr, "Error type A at Line %d: Mysterious character \"%s\".\n", yylineno, yytext);
                }
%%

