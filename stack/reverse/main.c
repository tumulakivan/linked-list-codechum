#include <stdio.h>
#include <stdlib.h>
#include "reverse.h"
#define MAX 100

int main() {
    char test, popped, str_input[MAX];
    stack *my_stack = initializeStack(my_stack);

    printf("Enter a string: ");
    scanf(" %[^\n]s", str_input);
    
    int index = 0;
    char current = str_input[index];
    while(current != '\0') {
        printf("%c", current);
        my_stack = push(my_stack, current);
        index++;
        current = str_input[index];
    }

    while(isEmpty(my_stack) == 0) {
        popped = pop(my_stack);
        printf("%c", popped);
    }

    return 0;
}