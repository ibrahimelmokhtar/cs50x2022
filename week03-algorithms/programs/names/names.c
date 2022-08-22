#include <cs50.h>
#include <stdio.h>
#include <string.h>

void print_array(string[], int);
int linear_search(string[], int, string);

int main(void) {
    int size = 7;
    string names[] = { "Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron" };
    print_array(names, size);

    linear_search(names, size, "Ron");
    linear_search(names, size, "Mokhtar");
}

void print_array(string names[], int size) {
    printf("{ ");
    for (int i=0; i<size; i++) {
        printf("%s", names[i]);
        if (i != size-1) {
            printf(", ");
        } else {
            printf(" ");
        }
    }
    printf("}\n");
}

int linear_search(string names[], int size, string target) {
    for (int i=0; i<size; i++) {
        if (strcmp(names[i], target) == 0) {
            printf(">>> %s is found\n", target);
            return 0;
        }
    }

    printf(">>> %s is NOT found\n", target);
    return 1;
}
