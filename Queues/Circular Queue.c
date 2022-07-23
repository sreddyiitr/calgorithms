/******************************************************************************

                          Circular Queues in C

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int data) {
    
    // Let's create a node that can be linked to the original linked list
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    
    if(front == NULL || rear == NULL) {
        front = rear = temp;
        rear->next = front;  // Next of last node in Circular Quueue points to first node
    } else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

void dequeue() {
    if(front == NULL || rear == NULL) {
        printf("\n Queue is empty");
    } else if(front == rear) {
        printf("\n DeQueue: removed %d", front->data);
        struct Node* temp = front; 
        front = rear = NULL;
        free(temp);
    }
    else {
        printf("\n DeQueue: removed %d", front->data);
        struct Node* temp = front; 
        front = front->next;
        rear->next = front;
        free(temp);
    }
    
}

void peek() {
    
    if(front == NULL || rear == NULL) {
        printf("\n Queue is empty");
    } else {
        printf("\n Peeking Circular Queue: %d", front->data);
    }
}

void displayCircularQueue()
{
    printf(" Circular Queue: ");
    struct Node *temp = front;
    while (front != temp->next) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf(" %d ", temp->data);
}

void main() {
    
    enqueue(2);
    enqueue(0);
    enqueue(4);
    enqueue(5);
    displayCircularQueue();
    dequeue();
    peek();
}
