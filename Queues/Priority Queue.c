/******************************************************************************

                          Priority Queues in C using Linked List

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node *front = NULL;

void displayPriorityQueue()
{
    printf("\n Priority Queue: ");
    struct Node *temp = front;
    while (temp != NULL) {
        printf(" %d, %d -> ", temp->data, temp->priority);
        temp = temp->next;
    }
}

void enqueue(int data, int priority) {
    
    // Let's create a node that can be linked to the original linked list
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    
     
    if(front == NULL) {
        front = newNode;
    } else {  // Traverse the list until the node with right priority is found 
        struct Node* currentNode = front;
        struct Node* previousNode = NULL;
        
        while(currentNode != NULL && currentNode->priority >= priority) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        
        if(previousNode == NULL) {  // The head node priority is less than new node priority
            front = newNode;
            newNode->next = currentNode;
        } else { // Insert new node after previousNode but before the currentNode
            previousNode->next = newNode;
            newNode->next = currentNode;
        }
        
        //displayPriorityQueue();
    }
}

void dequeue() {
    if(front == NULL) {
        printf("\n Queue is empty");
    } else if(front->next == NULL) {
        printf("\n DeQueue: removed %d, %d", front->data, front->priority);
        struct Node* temp = front; 
        front = NULL;
        free(temp);
    }
    else {
        printf("\n DeQueue: removed %d, %d", front->data, front->priority);
        struct Node* temp = front; 
        front = front->next;
        free(temp);
    }
    
}

void peek() {
    
    if(front == NULL) {
        printf("\n Queue is empty");
    } else {
        printf("\n Peeking Priority Queue: %d", front->data);
    }
}



void main() {
    
    enqueue(2,2);
    enqueue(0,3);
    enqueue(4,1);
    enqueue(5,2);
    displayPriorityQueue();
    dequeue();
    peek();
}
