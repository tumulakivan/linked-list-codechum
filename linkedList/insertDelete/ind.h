struct Node {
    int value;
    struct Node* next;
};

struct Node* addNode(struct Node* node, int value);
struct Node* deleteAt(struct Node* node, int pos);
void swap(int *num1, int *num2);
void print(struct Node* head);