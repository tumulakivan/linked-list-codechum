#include <stdio.h>
#include <stdlib.h>

struct Node {
    double value;
    struct Node* next;
};

struct Node* addNode(struct Node* node, double value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = node->next;
    node->next = newNode;

    return newNode;
}

int main(void) {
    // create the head node
    struct Node* linkedList = malloc(sizeof(struct Node));
    linkedList->value = 0;
    linkedList->next = NULL;
    struct Node* node1 = addNode(linkedList, 5);
    struct Node* node2 = addNode(node1, 35.5);
    struct Node* node3 = addNode(node2, 22.13);
    struct Node* node4 = addNode(node3, 100.123);
    struct Node* node5 = addNode(node4, -10.55);

    double sum = 0.0;

    struct Node* current = linkedList->next;
    while(current != NULL) {
        sum += current->value;
        current = current->next;
    }

    printf("%.2f", sum);

    current = linkedList->next;
    while(current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(linkedList);
}