/******************************************************************************
 * AVL Tree - Search, Insert and Delete
 * 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
    int height;
};

int get_height(struct Node *node) {
    if(n==NULL) {
        return 0;
    }
    return node->height;
}

struct Node * new_node(int key) {
    // Let's create a node that can be used in tree later
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->left = NULL;
    temp->key = key;
    temp->right = NULL;
    temp->height = 1;
    return temp; 
}

int get_balance_factor(struct Node *node) {
    if(node == NULL) {
        return 0;
    }
    return get_height(node->left) - get_height(node->right);
}

/****
 *      --------y-------
 *  ----x----               T3
 *  T1      T2
 * */
struct Node * right_rotate(struct Node* y) {
    
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = 1 + max(get_height(y->right), get_height(y->left));
    x->height = 1 + max(get_height(x->right), get_height(x->left));
    
    return x; // x is the new root
}

/**
*                       x
*           T1                          y
*                               T2              T3
*
*/
struct Node * left_rotate(struct Node* x) {
    
    struct Node * y = x->right;
    struct Node * T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    y->height = 1 + max(get_height(y->right), get_height(y->left));
    x->height = 1 + max(get_height(x->right), get_height(x->left));
    
    return y; // y is the new root
}
