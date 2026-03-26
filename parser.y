%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();

typedef struct Node {
    char* name;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(char* name, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->name = name;
    node->left = left;
    node->right = right;
    return node;
}

Node* root;

%}


%union {
    int num;
    char* id;
    struct Node* node;
}

/* token */


%token <num> NUMBER
%token <id> ID

%type <node> expr stmt program


/* 优先级 */
%left '+' '-'
%left '*' '/'

%%

program:
      program stmt   { $$ = $2; root = $$; }
    | /* empty */    { $$ = NULL; }
    ;

stmt:
    ID '=' expr ';' {
        $$ = newNode("Assign",
                     newNode($1, NULL, NULL),
                     $3);
    }
;

expr:
      expr '+' expr   { $$ = newNode("+", $1, $3); }
    | expr '-' expr   { $$ = newNode("-", $1, $3); }
    | expr '*' expr   { $$ = newNode("*", $1, $3); }
    | expr '/' expr   { $$ = newNode("/", $1, $3); }
    | '(' expr ')'    { $$ = $2; }
    | NUMBER          {
                          char buf[32];
                          sprintf(buf, "%d", $1);
                          $$ = newNode(strdup(buf), NULL, NULL);
                      }
    ;

%%

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}
void printTree(Node* node, int depth) {
    if (!node) return;

    for (int i = 0; i < depth; i++) printf("  ");
    printf("%s\n", node->name);

    printTree(node->left, depth + 1);
    printTree(node->right, depth + 1);
}

int main() {
    yyparse();
    printTree(root, 0);
    return 0;
}