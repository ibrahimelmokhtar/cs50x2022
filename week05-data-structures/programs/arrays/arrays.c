#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int stack_arr[3];
    stack_arr[0] = 1;
    stack_arr[1] = 2;
    stack_arr[2] = 3;

    printf(">>> Stack: ");
    for (int i=0; i<3; i++) {
        printf("%i ", stack_arr[i]);
    }
    printf("\n");

    int* heap_arr = malloc(3*sizeof(int));
    heap_arr[0] = 1;
    heap_arr[1] = 2;
    heap_arr[2] = 3;

    printf(">>> Heap:  ");
    for (int i=0; i<3; i++) {
        printf("%i ", heap_arr[i]);
    }
    printf("\n");

    // Time passes ...
    // Ops! I need more memory ...

    int* temp = malloc(4*sizeof(int));
    for(int i=0; i<3; i++) {
        temp[i] = heap_arr[i];
    }
    temp[3] = 4;

    free(heap_arr);
    heap_arr = temp;

    printf(">>> Heap:  ");
    for (int i=0; i<4; i++) {
        printf("%i ", heap_arr[i]);
    }
    printf("\n");

    free(heap_arr);

    return 0;
}
