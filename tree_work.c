#include "tree_work.h"

TTreeNode *new_t_node(int value) {
    TTreeNode *result = (TTreeNode*)malloc(sizeof(TTreeNode) );
    result ->left = result ->right = NULL;
    result ->value = value;

    return result;
}   /* new_node */


TTreeNode *add_rec(TTreeNode *root, int value) {
    if (value < root->value) {
        if (root->left == NULL) {
            return (root->left = new_t_node(value) );
        } else {
            return add_rec(root->left, value);
        }
    }

    if (value > root->value) {
        if (root->right == NULL) {
            return (root->right = new_t_node(value) );
        } else {
            return add_rec(root->right, value);
        }
    }

    return root;
}   /* add_rec */


TTreeNode *tree_add_number(TTreeNode **root, int value) {
    if ( (*root) == NULL) {
        return ((*root) = new_t_node(value) );
    }

    return add_rec((*root), value);
}   /* add_number */


typedef void (*process_handler)(TTreeNode* node);

void ABR(TTreeNode *root, process_handler process) {
    if (root != NULL) {
        ABR(root->left, process);
        ABR(root->right, process);
        process(root);
    }
}   /* ABR */

void ARB(TTreeNode *root, process_handler process) {
    if (root != NULL) {
        ARB(root->left, process);
        process(root);
        ARB(root->right, process);
    }
}   /* ARB */


void print_node(TTreeNode *node) {
    printf("%d ", node->value);
}   /* print_node */

void tree_print(TTreeNode *root) {
    ARB(root, &print_node);
}   /* print_tree */


void remove_node(TTreeNode **node) {
    if ( (node != NULL) && ((*node) != NULL)) {
        free(*node);
        (*node) = NULL;
    }
}   /* remove_node */


int has_two(TTreeNode *node) {
    return (node != NULL) && (node->left != NULL) && (node->right != NULL);
}   /* has_two */

int is_leaf(TTreeNode *node) {
    return (node->left == NULL) && (node->right == NULL);
}   /* is_leaf */


void cut_nodes(TTreeNode *node) {
#ifdef ANY_NODE_LEAF  /* leaf = any node */
    if ( (!has_two(node) ) ||
         (!is_leaf(node->left) && !is_leaf(node->right) ) )
            return;

    if (is_leaf(node->left)) {
        remove_node(&(node->left) );
    } else {
        remove_node(&(node->right) );
    }
#else   /* leaf = node without both left and right */
    if (!has_two(node) )
        return;

    if (is_leaf(node->left) && is_leaf(node->right) ) {
        remove_node(&(node->left) );
    }
#endif
}   /* cut_nodes */

void tree_cut(TTreeNode **root) {
    if ( (root != NULL) && is_leaf(*root) ) {
        remove_node(root);
    } else {
        ABR( (*root), cut_nodes);
    }
}   /* cut_tree */
