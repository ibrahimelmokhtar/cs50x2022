#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* arr = malloc(3*sizeof(int));
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    printf(">>> arr: ");
    for (int i=0; i<3; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");

    arr = realloc(arr, 4*sizeof(int));
    arr[3] = 4;

    printf(">>> arr: ");
    for (int i=0; i<4; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
