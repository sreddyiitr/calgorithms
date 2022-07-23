
#include <stdio.h>
#include <stdlib.h>

int *print_input() {
    int *ptr = (int *) malloc(5 * sizeof(int));
    int i;
    printf("Enter 5 integers \n");
    for(i=0; i<5; i++ ) {
        scanf("%d", ptr+i);
    }
    return ptr;
}

void main()
{
    int i, sum = 0;
    
    int *ptr = print_input();
    
    for(i=0; i<5; i++) {
        sum += *(ptr+i);
    }
    
    printf("Sum is: %d", sum);
    
    free(ptr);
    ptr=NULL;
}
