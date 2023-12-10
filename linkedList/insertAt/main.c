#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* addNode(struct Node* node, int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = node->next;
    node->next = newNode;

    return newNode;
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main(void) {
    // create the head node
    struct Node* linkedList = malloc(sizeof(struct Node));
    linkedList->value = 0;
    linkedList->next = NULL;
    struct Node* node1 = addNode(linkedList, 5);
    struct Node* node2 = addNode(node1, 3);
    struct Node* node3 = addNode(node2, 22);
    struct Node* node4 = addNode(node3, 100);
    struct Node* node5 = addNode(node4, -10);
    struct Node* node6 = addNode(node5, 55);
    struct Node* node7 = addNode(node6, -7);

    // Hey there, start typing your C code here...
    int num1, num2, pos, marker = 0;
    struct Node* first;
    struct Node* second;
    struct Node* currNode;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter position: ");
    scanf("%d", &pos);

    if(num1 > num2) swap(&num1, &num2);

    switch(pos) {
        case 0: 
            first = addNode(linkedList, num1);
            second = addNode(first, num2);
            break;
        default:
            currNode = linkedList;
            while(marker != pos && currNode != NULL) {
                currNode = currNode->next;
                marker++;
            }
            first = addNode(currNode, num1);
            second = addNode(first, num2);
            break;
    }
    
    currNode = linkedList->next;
    while(currNode != NULL) {
        if(currNode->next != NULL)
            printf("%d, ", currNode->value);
        else 
            printf("%d", currNode->value);
        currNode = currNode->next;
    }

    // free block
    currNode = linkedList->next;
    while(currNode != NULL) {
        struct Node* temp = currNode;
        currNode = currNode->next;
        free(temp);
    }
    free(linkedList);
}