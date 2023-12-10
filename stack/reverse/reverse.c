#include <stdio.h>
#include <stdlib.h>
#include "reverse.h"

stack* initializeStack(stack* base_stack) {
    base_stack->top = NULL;
    return base_stack;
}

stack* push(stack* my_stack, char data) {
    node* new_node = malloc(sizeof(node));
    if(new_node == NULL) {
        fprintf(stderr, "mem alloc failure\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->next = my_stack->top;
    my_stack->top = new_node;

    return my_stack;
}

int peek(stack* my_stack) {
    if(isEmpty(my_stack) == 1) {
        printf("stack empty\n");
        return 0;
    }

    return my_stack->top->data;
}

int pop(stack* my_stack) {
    if(isEmpty(my_stack) == 1) {
        fprintf(stderr, "stack underflow\n");
        exit(EXIT_FAILURE);
    }

    node* temp_node = my_stack->top;
    my_stack->top = my_stack->top->next;

    int temp = temp_node->data;
    free(temp_node);
    return temp;
}

int isEmpty(stack* my_stack) {
    if(my_stack->top == NULL) return 1;

    return 0;
}