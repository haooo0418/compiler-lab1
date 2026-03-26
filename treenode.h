/* treenode.h：语法树节点定义 */
#ifndef __TREENODE_H__
#define __TREENODE_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN_NUM 10

typedef struct node {
    struct node *children[MAX_CHILDREN_NUM];  /* 子节点 */
    char name[32];      /* 节点名称 */
    int lineno;         /* 对应行号 */
    int num;            /* 子节点数量 */
    char info[50];      /* 可选信息（标识符名或数字等） */
} TreeNode;

TreeNode *createTreeNode(char *name, int lineno, char *info);
int insertChild(TreeNode *parent, TreeNode *child);
int insertChildren(int num, TreeNode *parent, ...);
void printTree(TreeNode *p, int tab);
void destroyTree(TreeNode *p);

#endif
