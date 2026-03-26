/* main.c：编译驱动程序 */
#include <stdio.h>
#include "treenode.h"

extern int yyparse();
extern void yyrestart(FILE *);
extern int yylineno;
int error_num = 0;     /* 放在这里作为唯一的定义 */
TreeNode *root = NULL; /* 放在这里作为唯一的定义 */

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "请提供要编译的 C-- 源文件！\n");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    yyparse();


    
    /* 若无错误，则先序遍历打印语法树 */
    if (error_num == 0 && root != NULL) {
        printTree(root, 0);
        destroyTree(root);
    }
    return 0;
}
