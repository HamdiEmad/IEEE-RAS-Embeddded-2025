#include <stdio.h>
#include <stdbool.h>
#include "node.c"

bool isEmpty(node_t *head) {
    return head == NULL;
}

bool isFull(node_t *head) {
    // Assuming the max size is 20
    return size(head) == 20;
}

int getRear(node_t *head) {
    if (head == NULL) {
        return -1;
    }
    if (isEmpty(head)) {
        return -1;
    }
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current->data;
}

int getFront(node_t *head) {
    if (isEmpty(head)) {
        return -1;
    }
    return head->data;
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

    printf("Is the list empty? %s\n", isEmpty(node1) ? "Yes" : "No");
    printf("Is the list full? %s\n", isFull(node1) ? "Yes" : "No");
    printf("The rear element is : %d\n", getRear(node1));
    printf("The front element is : %d\n", getFront(node1));
}

