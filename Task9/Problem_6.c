#include <stdio.h>
#include <stdbool.h>
#include "node.c"

void printListC(node_t *head) {
    if (head == NULL) {
        printf("The List is empty\n");
        return;
    }
    node_t *current = head;
    while (current -> next != head) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}

void circle(node_t *head) {
    if (head == NULL) {
        printf("The List is empty\n");
        return;
    }
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head;
}

void addNode(node_t **head, node_t *newNode, int position, bool isCircular) {
    if (*head == NULL) {
        *head = newNode;
        newNode->next = NULL;
        return;
    }
    if (position == 0) {
        addFirst(head, newNode);
        return;
    }
    if (position == size(*head)) {
        addLast(head, newNode);
        return;
    }
    if (position < 0 || position > size(*head)) {
        printf("Invalid position\n");
        return;
    }
    node_t *current = *head;
    for (int i = 1; i < position; i++) {
        current = current -> next;
    }
    newNode->next = current->next;
    current->next = newNode;
    if (isCircular)
        circle(*head);
}

int main() {
    node_t *node1 = createNode(1);
    node_t *node2 = createNode(2);
    node_t *node3 = createNode(3);
    

    link(&node1, node2);
    link(&node2, node3);
    printList(node1);
    
    node_t *mid = createNode(51);
    addNode(&node1, mid, 1, true);
    printListC(node1);

    //make sure the list is circular by getting the first node data through the last node.
    printf("Node 1 data is : %d\n", node3->next->data);
}