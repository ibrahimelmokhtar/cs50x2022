#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* next;
} node;

void free_list(node* list) {
    while (list != NULL) {
        node* curr = list->next;
        free(list);
        list = curr;
    }
}

void print_list(node* list) {
    for (node* curr = list; curr != NULL; curr = curr->next) {
        printf("%i  ", curr->number);
    }
    printf("\n");
}

int main(void) {
    // Create new list:
    node* list=NULL;

    // Add new node to list:
    node* n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    list = n;

    // Add new node to list:
    n = malloc(sizeof(node));
    if (n == NULL) {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    // Add new node to list:
    n = malloc(sizeof(node));
    if (n == NULL) {
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 6;
    n->next = NULL;
    list->next->next = n;

    // Print whole list:
    print_list(list);

    // Free all nodes within list:
    free_list(list);

    return 0;
}
