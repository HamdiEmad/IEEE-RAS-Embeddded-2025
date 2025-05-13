#include <stdio.h>
#include "node.c"

int main() {
    node_t *node1 = createNode(1);
    node_t *node2 = createNode(2);
    node_t *node3 = createNode(3);
    
    link(&node1, node2);
    link(&node2, node3);
    printList(node1);

    freeList(&node1);
    printList(node1);
}