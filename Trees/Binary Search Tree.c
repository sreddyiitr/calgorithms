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

int max(int a, int b) {

    return a>b?a:b;    
}

int get_height(struct Node *node) {
    if(node==NULL) {
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

/*
    Insertion of a new node in Binary Search tree 
    1. Create new node
    2. Find the position to add this node
        a. Check if new node key is less than the current node, then go to left
        b. Check if new node key is greater than the current node, then go to right
*/
struct Node * insert(struct Node * node, int key) {
    
    if(node == NULL) {
        return new_node(key);
    } else if(key < node->key) {
        node->left = insert(node->left, key);
    } else if(key > node->key) {
        node->right = insert(node->right, key);
    }
    
    node->height = 1 + max(get_height(node->left) , get_height(node->right));
    int balanceFactor = get_balance_factor(node);
    
    // Left Left 
    if(balanceFactor > 1 && key < node->left->key) {
        return right_rotate(node);
    }
    // Right Right
    if(balanceFactor < -1 && key > node->right->key) {
        return left_rotate(node);
    }
    // Left Right
    if(balanceFactor > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    // Right Left
    if(balanceFactor < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node; 
}

void preOrder(struct Node * root) {
    
    if(root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }    
}

void inOrder(struct Node * root) {
    
    if(root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }    
}

void postOrder(struct Node * root) {

    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }    
}

struct Node * inorderPrecessor(struct Node * root) {
    root = root->left;
    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct Node * delete_node(struct Node * root, int key) {
    
    struct Node * temp;
    if(root == NULL) {
        return NULL;
    }
    if(key < root->key) {
       root->left = delete_node(root->left, key); 
    } 
    else if(key > root->key) {
        root->right = delete_node(root->right, key); 
    } else {
        if(root->left != NULL && root->right != NULL) {
            temp = inorderPrecessor(root);
            root->key = temp->key;
            root->left = delete_node(root->left, temp->key); 
            return root;
        }
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }    
        if(root->left == NULL && root->right != NULL) {
            temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        if(root->left != NULL && root->right == NULL) {
            temp = root;
            root = root->left;
            free(temp);
            return root;
        }
          
    }
    
    root->height = 1 + max(get_height(root->left) , get_height(root->right));
    int balanceFactor = get_balance_factor(root);
    
    // Left Left 
    if(balanceFactor > 1 && key < root->left->key) {
        return right_rotate(root);
    }
    // Right Right
    if(balanceFactor < -1 && key > root->right->key) {
        return left_rotate(root);
    }
    // Left Right
    if(balanceFactor > 1 && key > root->left->key) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    // Right Left
    if(balanceFactor < -1 && key < root->right->key) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;

}

int main() {
    
    struct Node * root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    printf("\npostOrder | ");
    postOrder(root);
    printf("\npreOrder  | ");
    preOrder(root);
    int delete_node_key = 4;
    printf("\nDeleting node with key: %d ", delete_node_key);
    delete_node(root, delete_node_key);
    printf("\npostOrder | ");
    postOrder(root);
    return 0;
}
