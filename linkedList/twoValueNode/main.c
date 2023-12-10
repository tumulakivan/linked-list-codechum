#include <stdio.h>
#include <stdlib.h>
#include "two.h"

int main() {
    // initialize list
    node* head = NULL;
    node* current;
    node* member;

    // appending/initializing nodes
    int num1, num2, n, count = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    while(count != n) {
        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);

        member = create(num1, num2);
        head = append(head, member);

        count++;
    }

    print(head);

    // free block
    current = head;
    while(current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}