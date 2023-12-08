#include <stdio.h>
#include <stdlib.h>
#include "ind.h"

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

    struct Node* current;

    // Hey there, start typing your C code here...
    int num1, num2, pos, posToDelete, counter = 0;
    struct Node* first;
    struct Node* second;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter position to delete: ");
    scanf("%d", &posToDelete);

    if(num1 > num2) swap(&num1, &num2);

    switch(pos) {
        case 0: 
            first = addNode(linkedList, num1);
            second = addNode(first, num2);
            break;
        default:
            current = linkedList;
            while(counter != pos && current != NULL) {
                current = current->next;
                counter++;
            }
            first = addNode(current, num1);
            second = addNode(first, num2);
            break;
    }

    deleteAt(linkedList, posToDelete);
    print(linkedList);

    // free block
    current = linkedList->next;
    while(current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(linkedList);

    return 0;
}