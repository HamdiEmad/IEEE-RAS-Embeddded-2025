#include <stdio.h>
#include "node.c"

int main() {
    node_t *node1 = createNode(0);
    node_t *node2 = createNode(1);
    node_t *node3 = createNode(2);
    node_t *node4 = createNode(3);
    node_t *node5 = createNode(4);

    link(&node1, node2);
    link(&node1, node3);
    link(&node1, node4);
    link(&node1, node5);
    
    printList(node1);
}