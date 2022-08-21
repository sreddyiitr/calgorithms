/******************************************************************************
 * Binary Search Tree - Search, Insert and Delete
 * 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node * new_node(int key) {
    // Let's create a node that can be used in tree later
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->left = NULL;
    temp->key = key;
    temp->right = NULL;
    return temp; 
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
    return node; 
}

void inorder(struct Node *root) {
    
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void postorder(struct Node *root) {

        
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
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
    
    return root;

}

void main() {
    struct Node *root = new_node(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    inorder(root);
    printf("\n");
    postorder(root);
    
    delete_node(root, 50);
    printf("\n");
    inorder(root);

}
