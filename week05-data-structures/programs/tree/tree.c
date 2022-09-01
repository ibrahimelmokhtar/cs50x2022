#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* left;
    struct node* right;
} node;

void free_tree(node* root) {
    if (root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_tree(node* root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%i  ", root->number);
    print_tree(root->right);
}

int main(void) {
    // Create new tree:
    node* tree=NULL;

    // Add new node to tree:
    node* n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    // Add new node to tree:
    n = malloc(sizeof(node));
    if (n == NULL) {
        free(tree);
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    // Add new node to tree:
    n = malloc(sizeof(node));
    if (n == NULL) {
        free(tree->left);
        free(tree);
        return 1;
    }
    n->number = 6;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    // Print whole tree:
    print_tree(tree);
    printf("\n");

    // Free all nodes within tree:
    free_tree(tree);

    return 0;
}
