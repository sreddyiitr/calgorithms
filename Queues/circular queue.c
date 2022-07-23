#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node * add_at_end(struct Node *ptr, int data) {
    
    // Let's create a node that can be linked to the original linked list
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    
    //Assign the address of last element in the linked list to temp node
    ptr->next = temp;
    return temp; // here, we are returning the address of temp node (which is the last node)
}

void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}
