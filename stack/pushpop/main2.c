#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Stack {
    int top;
    int value;
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

void push(struct Stack* stack, int item) {
    if (!isFull(stack)) {
        struct Stack* nextNode = stack->next;
        
        struct Stack* newNode = (struct Stack*) malloc(sizeof(struct Stack));
        stack->next = newNode;
		newNode->value = item;
        newNode->next = nextNode;
        
        stack->top++;
    }
}

int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        struct Stack* firstNode = stack->next;
        struct Stack* secondNode = firstNode->next;
        
        stack->next = secondNode;
        stack->top--;
        
        return firstNode->value;
    }
    
    return 0;
}

int peek(struct Stack* stack) {
    if(!isEmpty(stack)) return stack->next->value;
    else return 0;
}

void display(struct Stack* stack) {
	struct Stack* current = stack->next;
	while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

int main(void) {
    char op;
    int item, popped, minimum, test, ui_ctr = 1;
    struct Stack* my_stack = createEmptyStack();

    while(op != '#') {
        printf("Enter operation %d: ", ui_ctr);
        scanf(" %c", &op);
        if(op == '+') scanf(" %d", &item);

        switch(op) {
            case '+':
                push(my_stack, item);
                break;
            case '-':
                popped = pop(my_stack);
                break;
            case '#':
                while(!isEmpty(my_stack)) {
                    popped = pop(my_stack);
                    if(popped < minimum) minimum = popped;
                }
                printf("Minimum element: %d", minimum);
                break;
            default:
                printf("invalid option.\n");
                break;
        }

        ui_ctr++;
    }
    
    return 0;
}