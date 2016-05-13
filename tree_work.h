#ifndef TREE_WORK_H
#define TREE_WORK_H

#include <stdio.h>
#include <malloc.h>

//#define ANY_NODE_LEAF

typedef struct TTreeNode {
    int value;
    struct TTreeNode *left, *right;
} TTreeNode;

void tree_print(TTreeNode *root);
TTreeNode *tree_add_number(TTreeNode **root, int value);

void tree_cut(TTreeNode **root);

#endif // TREE_WORK_H
