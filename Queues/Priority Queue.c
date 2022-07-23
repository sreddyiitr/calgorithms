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
struct Node *rear = NULL;
