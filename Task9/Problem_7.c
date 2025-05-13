#include <stdio.h>
#include "node.c"

int pop(node_t **head) {
    if (*head == NULL) {
        printf("The Stack is empty\n");
        return -1;
    }
    node_t *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    int data = current->next->data;
    free(current->next);
    current->next = NULL;
    return data;
}

int main() {
    node_t *node1 = createNode(10);
    node_t *node2 = createNode(20);
    node_t *node3 = createNode(30);

    link(&node1, node2);
    link(&node2, node3);
    printList(node1);
    
    int data = pop(&node1);
    printf("Popped data is : %d\n", data);
    printList(node1);
}