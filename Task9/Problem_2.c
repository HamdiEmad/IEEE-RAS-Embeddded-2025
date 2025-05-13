#include <stdio.h>
#include "node.c"

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

    node_t *first = createNode(0);
    addFirst(&node1, first);
    printList(node1);

    node_t *last = createNode(6);
    addLast(&node1, last);
    printList(node1);

    delete(&node1, node1);
    printList(node1);

    delete(&node1, last);
    printList(node1);

    delete(&node1, node3);
    printList(node1);
}