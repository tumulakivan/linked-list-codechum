#include "two.h"
#include <stdio.h>
#include <stdlib.h>

node* create(int num1, int num2) {
    node* new_node = malloc(sizeof(node));
    if(new_node == NULL) {
        fprintf(stderr, "mem alloc failure\n");
        exit(EXIT_FAILURE);
    }

    new_node->a = num1;
    new_node->b = num2;
    new_node->next = NULL;

    return new_node;
}

node* append(node* list, node* new) {
    node* current = list;
    
    if(list != NULL) {
        new->next = list;
        return new;
    }

    list = new;
    return new;
}

void print(node* list) {
    node* current = list;
    while(current != NULL) {
        printf("(%d, %d)\n", current->a, current->b);
        current = current->next;
    }
}