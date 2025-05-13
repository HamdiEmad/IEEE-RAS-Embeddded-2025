#include <stdio.h>
#include "node.c"

void reverse(node_t **head) {
    node_t *prev = NULL;
    node_t *current = *head;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev; 
        prev = current;       
        current = next;      
    }
    (*head)->next = NULL;
    *head = prev;
}

int main() {
    node_t *node1 = createNode(1);
    node_t *node2 = createNode(2);
    node_t *node3 = createNode(3);
    node_t *node4 = createNode(4);
    node_t *node5 = createNode(5);
    
    link(&node1, node2);
    link(&node2, node3);
    link(&node3, node4);
    link(&node4, node5);
    printList(node1);

    reverse(&node1);
    printList(node1);
}