#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Stack {
    int top;
    char value;
    struct Stack* next;
};

struct Stack* createEmptyStack(void) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (!isFull(stack)) {
        struct Stack* nextNode = stack->next;
        
        struct Stack* newNode = (struct Stack*) malloc(sizeof(struct Stack));
        stack->next = newNode;
		newNode->value = item;
        newNode->next = nextNode;
        
        stack->top++;
    }
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        struct Stack* firstNode = stack->next;
        struct Stack* secondNode = firstNode->next;
        
        stack->next = secondNode;
        stack->top--;
        
        return firstNode->value;
    }
    
    return '\0';
}

char peek(struct Stack* stack) {
    if(!isEmpty(stack)) return stack->next->value;
    else return '\0';
}

void display(struct Stack* stack) {
	struct Stack* current = stack->next;
	while (current != NULL) {
        printf("%c\n", current->value);
        current = current->next;
    }
}

int main(void) {
    char str_input[MAX_SIZE], current;
    struct Stack* my_stack = createEmptyStack();

    printf("Enter a string: ");
    scanf(" %[^\n]s", str_input);

    if(isFull(my_stack) == 1) {
        fprintf(stderr, "stack overflow\n");
        return 1;
    }

    int index = 0;
    current = str_input[index];
    while(current != '\0') {
        push(my_stack, str_input[index]);
        index++;

        current = str_input[index];
    }

    char popped;
    while(isEmpty(my_stack) == 0) {
        popped = pop(my_stack);
        printf("%c", popped);
    }
    
    return 0;
}