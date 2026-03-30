%{
#include <stdio.h>
#include <stdlib.h>
#include "treenode.h"
extern int yylex();
extern int yyparse();
extern TreeNode *root;
extern int error_num;
extern int yylineno;

/* Line number of the most recently detected, not-yet-resolved parser error.
   Cleared by yyerror_missing() when a specific recovery rule handles it, or
   printed as a generic "Syntax error" by generic recovery rules / main(). */
int pending_error_line = 0;

static void yyerror_missing(const char *what, int lineno) {
    pending_error_line = 0;  /* resolved by a specific rule */
    fprintf(stderr, "Error type B at Line %d: Missing \"%s\".\n", lineno, what);
    error_num++;
}
void yyerror(const char *msg) {
    (void)msg;
    /* Save the error location; the recovery rule (or main) will decide
       whether to print a specific message or the generic "Syntax error". */
    pending_error_line = yylineno;
}
%}

%union {
    TreeNode *node;
}

/* 关键：为所有 token 指定语义类型 <node> */
%token <node> SEMI COMMA ASSIGNOP RELOP PLUS MINUS STAR DIV AND OR DOT NOT
%token <node> TYPE ID INT FLOAT STRUCT RETURN IF ELSE WHILE
%token <node> LP RP LB RB LC RC

%locations

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT UMINUS
%left DOT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

/* 关键：为所有会用到 $$/$n 的非终结符声明类型 */
%type <node> Program ExtDefList ExtDef
%type <node> Specifier StructSpecifier OptTag Tag
%type <node> ExtDecList Dec DecList Def DefList
%type <node> VarDec FunDec VarList ParamDec
%type <node> CompSt StmtList Stmt
%type <node> Exp Args

%%

Program
    : ExtDefList {
        root = createTreeNode("Program", 1, "");
        insertChild(root, $1);
      }
    ;

ExtDefList
    : ExtDef ExtDefList {
        TreeNode *p = createTreeNode("ExtDefList", $1->lineno, "");
        insertChild(p, $1);
        if ($2) insertChild(p, $2);
        $$ = p;
      }
    | /* empty */ {
        $$ = NULL;
      }
    ;

ExtDef
    : Specifier SEMI {
        TreeNode *p = createTreeNode("ExtDef", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        $$ = p;
      }
    | Specifier ExtDecList SEMI {
        TreeNode *p = createTreeNode("ExtDef", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        $$ = p;
      }
    | Specifier FunDec CompSt {
        TreeNode *p = createTreeNode("ExtDef", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        $$ = p;
      }
    ;

Specifier
    : TYPE {
        TreeNode *p = createTreeNode("Specifier", yylineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    | StructSpecifier {
        TreeNode *p = createTreeNode("Specifier", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    ;

StructSpecifier
    : STRUCT OptTag LC DefList RC {
        TreeNode *p = createTreeNode("StructSpecifier", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        insertChild(p, $4);
        insertChild(p, $5);
        $$ = p;
      }
    | STRUCT Tag {
        TreeNode *p = createTreeNode("StructSpecifier", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        $$ = p;
      }
    ;

OptTag
    : ID {
        TreeNode *p = createTreeNode("OptTag", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    | /* empty */ {
        $$ = createTreeNode("OptTag", yylineno, "");
      }
    ;

Tag
    : ID {
        TreeNode *p = createTreeNode("Tag", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    ;

ExtDecList
    : Dec {
        TreeNode *p = createTreeNode("ExtDecList", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    | Dec COMMA ExtDecList {
        TreeNode *p = createTreeNode("ExtDecList", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        $$ = p;
      }
    ;

Dec
    : VarDec {
        TreeNode *p = createTreeNode("Dec", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    | VarDec ASSIGNOP Exp {
        TreeNode *p = createTreeNode("Dec", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        $$ = p;
      }
    ;

/* 补：复合语句 CompSt（你原来缺失） */
CompSt
    : LC DefList StmtList RC {
        TreeNode *p = createTreeNode("CompSt", $1->lineno, "");
        insertChild(p, $1);
         if ($2) insertChild(p, $2);
        if ($3) insertChild(p, $3);
        insertChild(p, $4);
        $$ = p;
      }
    ;

FunDec
    : ID LP RP {
        TreeNode *p = createTreeNode("FunDec", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        $$ = p;
      }
    | ID LP VarList RP {
        TreeNode *p = createTreeNode("FunDec", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        insertChild(p, $4);
        $$ = p;
      }
    ;

/* 补：形参列表 VarList/ParamDec（你原来缺失） */
VarList
    : ParamDec COMMA VarList {
        TreeNode *p = createTreeNode("VarList", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        $$ = p;
      }
    | ParamDec {
        TreeNode *p = createTreeNode("VarList", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    ;

ParamDec
    : Specifier VarDec {
        TreeNode *p = createTreeNode("ParamDec", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        $$ = p;
      }
    ;

VarDec
    : ID {
        TreeNode *p = createTreeNode("VarDec", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    | VarDec LB INT RB {
        TreeNode *p = createTreeNode("VarDec", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        insertChild(p, $4);
        $$ = p;
      }
    ;

DefList
    : Def DefList {
        TreeNode *p = createTreeNode("DefList", $1->lineno, "");
        insertChild(p, $1);
        if ($2) insertChild(p, $2);
        $$ = p;
      }
    | /* empty */ {
        $$ =NULL;
      }
    ;

Def
    : Specifier DecList SEMI {
        TreeNode *p = createTreeNode("Def", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        $$ = p;
      }
    | Specifier error SEMI {
        /* e.g. "float i = 1.05e;" — lexer splits "1.05e" into FLOAT + ID */
        if (pending_error_line > 0) {
            fprintf(stderr, "Error type B at Line %d: Syntax error\n", pending_error_line);
            error_num++;
            pending_error_line = 0;
        }
        yyerrok;
        TreeNode *p = createTreeNode("Def", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    ;

DecList
    : Dec {
        TreeNode *p = createTreeNode("DecList", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    | Dec COMMA DecList {
        TreeNode *p = createTreeNode("DecList", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        $$ = p;
      }
    ;

StmtList
    : Stmt StmtList {
        TreeNode *p = createTreeNode("StmtList", $1->lineno, "");
        insertChild(p, $1);
        if ($2) insertChild(p, $2);
        $$ = p;
      }
    | /* empty */ {
        $$ =  NULL;
      }
       | error SEMI StmtList {
        if (pending_error_line > 0) {
            fprintf(stderr, "Error type B at Line %d: Syntax error\n", pending_error_line);
            error_num++;
            pending_error_line = 0;
        }
        yyerrok;
        $$ = $3;  /* 不构造空 StmtList/Stmt 节点，避免输出垃圾节点 */
      }
    ;

Stmt
    : Exp SEMI {
        TreeNode *p = createTreeNode("Stmt", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        $$ = p;
      }
    | CompSt {
        TreeNode *p = createTreeNode("Stmt", $1->lineno, "");
        insertChild(p, $1);
        
        $$ = p;
      }
    | RETURN Exp SEMI {
        TreeNode *p = createTreeNode("Stmt", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        $$ = p;
      }
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {
        TreeNode *p = createTreeNode("Stmt", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        insertChild(p, $4);
        insertChild(p, $5);
        $$ = p;
      }
       | IF LP Exp RP Stmt ELSE error Stmt {
        yyerror_missing(";", $6->lineno); /* $6 is the ELSE token */
        yyerrok;

        TreeNode *p = createTreeNode("Stmt", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        insertChild(p, $4);
        insertChild(p, $5);
        insertChild(p, $6);  /* ELSE */
        insertChild(p, $8);  /* else: Stmt */
        $$ = p;
      }
    | IF LP Exp RP Stmt ELSE Stmt {
        TreeNode *p = createTreeNode("Stmt", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        insertChild(p, $4);
        insertChild(p, $5);
        insertChild(p, $6);
        insertChild(p, $7);
        $$ = p;
      }
       | IF LP Exp RP Stmt error ELSE Stmt {
        yyerror_missing(";", $7->lineno); /* $7 is the ELSE token */
        yyerrok;
       

        TreeNode *p = createTreeNode("Stmt", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        insertChild(p, $4);
        insertChild(p, $5);
        insertChild(p, $7);
        insertChild(p, $8);
        $$ = p;
      }
      | IF LP Exp RP Exp error ELSE Stmt {
        yyerror_missing(";", $7->lineno); /* $7 is the ELSE token */
        yyerrok;

        TreeNode *p = createTreeNode("Stmt", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        insertChild(p, $4);
        insertChild(p, $5); /* then: Exp */
        insertChild(p, $7); /* ELSE */
        insertChild(p, $8); /* else: Stmt */
        $$ = p;
      }
    | WHILE LP Exp RP Stmt {
        TreeNode *p = createTreeNode("Stmt", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        insertChild(p, $4);
        insertChild(p, $5);
        $$ = p;
      }
        
    ;

Exp
    :  ID {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    | INT {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    | FLOAT {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
        | Exp DOT ID {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1);
         insertChild(p, $2); 
         insertChild(p, $3);
        $$ = p;
      }
      | Exp LB Exp RB {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1); insertChild(p, $2); insertChild(p, $3); insertChild(p, $4);
        $$ = p;
      }
      
    | Exp ASSIGNOP Exp {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        $$ = p;
      }
    | Exp AND Exp {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1); insertChild(p, $2); insertChild(p, $3);
        $$ = p;
      }
    | Exp OR Exp {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1); insertChild(p, $2); insertChild(p, $3);
        $$ = p;
      }
    | Exp RELOP Exp {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1); insertChild(p, $2); insertChild(p, $3);
        $$ = p;
      }
    | Exp PLUS Exp {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1); insertChild(p, $2); insertChild(p, $3);
        $$ = p;
      }
    | Exp MINUS Exp {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1); insertChild(p, $2); insertChild(p, $3);
        $$ = p;
      }
    | Exp STAR Exp {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1); insertChild(p, $2); insertChild(p, $3);
        $$ = p;
      }
    | Exp DIV Exp {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1); insertChild(p, $2); insertChild(p, $3);
        $$ = p;
      }
    | LP Exp RP {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1); insertChild(p, $2); insertChild(p, $3);
        $$ = p;
      }
    | MINUS Exp %prec UMINUS{
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        $$ = p;
      }
    | NOT Exp {
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        $$ = p;
      }
    
  
    
    | Exp LB error RB {
        yyerror_missing("]", $2->lineno); /* $2 is the LB token */
        /* 错误恢复：丢弃当前 lookahead，继续 */
        yyerrok;
      

        /* 仍然构建一个节点，避免后续空指针（可选） */
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $4);
        $$ = p;
      }
       | Exp LB error SEMI {
        yyerror_missing("]", $2->lineno); /* $2 is the LB token */
        yyerrok;

        /* 这里消耗掉 SEMI，相当于跳过这条错误语句的剩余部分 */
        TreeNode *p = createTreeNode("Exp", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $4); /* SEMI 作为同步点 */
        $$ = p;
      }
  
    ;

Args
    : Exp {
        TreeNode *p = createTreeNode("Args", $1->lineno, "");
        insertChild(p, $1);
        $$ = p;
      }
    | Exp COMMA Args {
        TreeNode *p = createTreeNode("Args", $1->lineno, "");
        insertChild(p, $1);
        insertChild(p, $2);
        insertChild(p, $3);
        $$ = p;
      }
    ;

%%

