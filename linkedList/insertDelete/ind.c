#include <stdio.h>
#include <stdlib.h>
#include "ind.h"

struct Node* addNode(struct Node* node, int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = node->next;
    node->next = newNode;

    return newNode;
}

struct Node* deleteAt(struct Node* node, int pos) {
    if(pos == 0) {
        struct Node* temp = node->next;
        node->next = node->next->next;
        free(temp);
        return node;
    }

    int counter = 0;
    struct Node* current = node;
    while(counter != pos) {
        current = current->next;
        counter++;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return node;
}

void print(struct Node* head) {
    struct Node* current = head->next;
    while(current != NULL) {
        if(current->next == NULL) {
            printf("%d", current->value);
            break;
        }
        printf("%d, ", current->value);

        current = current->next;
    }
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}