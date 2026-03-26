/* treenode.c：语法树节点操作与打印 */
#include "treenode.h"
#include <stdarg.h>
/* 辅助打印函数：根据节点名称区别打印格式 */
void print_help_func(TreeNode *p) {
    if (strcmp(p->name, "INT") == 0) {
        printf("%s: %d\n", p->name, atoi(p->info));
    } else if (strcmp(p->name, "FLOAT") == 0) {
        printf("%s: %f\n", p->name, atof(p->info));
    } else if (strcmp(p->name, "TYPE") == 0 ||
               strcmp(p->name, "ID") == 0) {
        printf("%s: %s\n", p->name, p->info);
    } else if (strcmp(p->name, "SEMI") == 0 ||
               strcmp(p->name, "COMMA") == 0 ||
               strcmp(p->name, "ASSIGNOP") == 0 ||
               strcmp(p->name, "RELOP") == 0 ||
               strcmp(p->name, "PLUS") == 0 ||
               strcmp(p->name, "MINUS") == 0 ||
               strcmp(p->name, "STAR") == 0 ||
               strcmp(p->name, "DIV") == 0 ||
               strcmp(p->name, "AND") == 0 ||
               strcmp(p->name, "OR") == 0 ||
               strcmp(p->name, "DOT") == 0 ||
               strcmp(p->name, "NOT") == 0 ||
               strcmp(p->name, "LP") == 0 ||
               strcmp(p->name, "RP") == 0 ||
               strcmp(p->name, "LB") == 0 ||
               strcmp(p->name, "RB") == 0 ||
               strcmp(p->name, "LC") == 0 ||
               strcmp(p->name, "RC") == 0 ||
               strcmp(p->name, "STRUCT") == 0 ||
               strcmp(p->name, "RETURN") == 0 ||
               strcmp(p->name, "IF") == 0 ||
               strcmp(p->name, "ELSE") == 0 ||
               strcmp(p->name, "WHILE") == 0) {
        printf("%s\n", p->name);
    } else {
        /* 非终结符：输出名称和行号 */
        printf("%s (%d)\n", p->name, p->lineno);
    }
}

/* 创建一个语法树节点 */
TreeNode *createTreeNode(char *name, int lineno, char *info) {
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    p->num = 0;
    strcpy(p->name, name);
    strcpy(p->info, info);
    p->lineno = lineno;
    return p;
}

/* 插入单个子节点 */
int insertChild(TreeNode *parent, TreeNode *child) {
    
    if (parent == NULL || child == NULL) return 0;
    if (parent == NULL || child == NULL || parent->num >= MAX_CHILDREN_NUM) return 1;
    parent->children[parent->num++] = child;
    return 0;
}

/* 插入多个子节点 */
int insertChildren(int num, TreeNode *parent, ...) {
    va_list list;
    va_start(list, parent);
    for (int i = 0; i < num; i++) {
        if (insertChild(parent, va_arg(list, TreeNode *))) {
            va_end(list);
            return 1;
        }
    }
    va_end(list);
    return 0;
}

/* 先序遍历打印语法树 */
void printTree(TreeNode *p, int tab) {
    if (p == NULL) return;
    for (int i = 0; i < tab; i++) printf(" ");
    if (p->num == 0) {
        /* 叶子节点（终结符） */
        print_help_func(p);
    } else {
        /* 非叶节点 */
        printf("%s (%d)\n", p->name, p->lineno);
        for (int i = 0; i < p->num; i++) {
            printTree(p->children[i], tab+1);
        }
    }
}

/* 销毁语法树 */
void destroyTree(TreeNode *p) {
    if (p == NULL) return;
    for (int i = 0; i < p->num; i++) {
        destroyTree(p->children[i]);
    }
    free(p);
}
