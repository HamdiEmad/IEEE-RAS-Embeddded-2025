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

void swap(node_t **head) {
    if (*head == NULL || (*head)->next == NULL)
        return;
    node_t *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    int temp = current->next->data;
    current->next->data = current->data;
    current->data = temp;
}

int main() {
    node_t *node1 = createNode(10);
    node_t *node2 = createNode(20);
    node_t *node3 = createNode(30);
    node_t *node4 = createNode(40);

    link(&node1, node2);
    link(&node2, node3);
    link(&node3, node4);
    
    // Print the list before swapping
    printList(node1);

    // Swap the last two nodes
    swap(&node1);
    printList(node1);
}