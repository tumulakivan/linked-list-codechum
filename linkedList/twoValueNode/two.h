typedef struct Node {
    int a;
    int b;
    struct Node* next;
} node;

node* create(int num1, int num2);
node* append(node* list, node* new);
void print(node* list);