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

struct Node * inorderPrecessor(struct Node * node) {
    node = node->left;
    while(node->right != NULL) {
        node = node->right;
    }
    return node;
}

struct Node * delete_node(struct Node * node, int key) {
    
    struct Node * temp;
    
    if(node == NULL) {
        return NULL;
    }
    if(key < node->key) {
       node->left = delete_node(node->left, key); 
    } 
    else if(key > node->key) {
        node->right = delete_node(node->right, key); 
    } else {
        // Found the node to be deleted
        
        // There are left and right children for the node to be deleted
        if(node->left != NULL && node->right != NULL) {
            temp = inorderPrecessor(node);
            node->key = temp->key;  //assigning only key, not address
            node->left = delete_node(node->left, temp->key); 
            return node;
        }
        // No children for the node to be deleted
        if(node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        }    
        // There is only right child for the node to be deleted
        if(node->left == NULL && node->right != NULL) {
            temp = node;
            node = node->right;
            free(temp);
            return node;
        }
        // There is only left child for the node to be deleted
        if(node->left != NULL && node->right == NULL) {
            temp = node;
            node = node->left;
            free(temp);
            return node;
        }
          
    }
    
    return node;

}

void main() {
    struct Node *root = new_node(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("inOrder: ");
    inorder(root);
    printf("\n");
    printf("postOrder: ");
    postorder(root);
    
    printf("\nDeleting 50: ");
    delete_node(root, 50);
    printf("\n");
    printf("postOrder: ");
    postorder(root);
}
