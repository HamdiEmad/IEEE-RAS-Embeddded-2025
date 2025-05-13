#include <stdio.h>
#include "node.c"

void enqueue(node_t **head, node_t *newNode) {
    if (*head == NULL) {
        *head = newNode;
        newNode->next = NULL;
        return;
    }
    node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = NULL;
}

void dequeue(node_t **head) {
    if (*head == NULL) {
        printf("The Queue is empty\n");
        return;
    }
    node_t *temp = *head;
    *head = temp->next;
    free(temp);
}

int main() {
    node_t *node1 = createNode('A');        //65    
    node_t *node2 = createNode('B');        //66
    node_t *node3 = createNode('C');        //67

    link(&node1, node2);
    link(&node2, node3);
    printList(node1);

    dequeue(&node1);
    printList(node1);
}