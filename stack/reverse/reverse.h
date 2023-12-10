typedef struct node {
    char data;
    struct node* next;
} node;

typedef struct {
    struct node* top;
} stack;

stack* initializeStack(stack* base_stack);
stack* push(stack* my_stack, char data);
int peek(stack* my_stack);
int pop(stack* my_stack); 
int isEmpty(stack* my_stack);