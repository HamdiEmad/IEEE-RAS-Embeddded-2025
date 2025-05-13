#include <stdio.h>
#include <stdlib.h>

typedef struct doubleNode {
    int data;
    struct doubleNode *next;
    struct doubleNode *prev;
} dnode_t;


dnode_t* createDNode(int data) {
    dnode_t *newNode = (dnode_t *)malloc(sizeof(dnode_t));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void linkD(dnode_t *prev, dnode_t *current, dnode_t *next) {
    if (current == NULL) {
        printf("The current node is null\n");
        return;
    }
    current -> prev = prev;
    current -> next = next;
}

void printListD(dnode_t *head) {
    if (head == NULL) {
        printf("The List is empty\n");
        return;
    }
    int count = 0;
    dnode_t *current = head;
    while (current != NULL) {
        count++;
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\nThe List length is %d\n", count);
}

void addFirstD(dnode_t **head, dnode_t *newNode) {
    if (newNode == NULL) {
        return;
    }
    if (*head == NULL) {
        *head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        return;
    }
    newNode->next = *head;
    newNode->prev = NULL;
    (*head)->prev = newNode;
    *head = newNode;
}

int main() {
    dnode_t *dnode1 = createDNode(1);
    dnode_t *dnode2 = createDNode(2);
    dnode_t *dnode3 = createDNode(3);

    linkD(NULL, dnode1, dnode2);
    linkD(dnode1, dnode2, dnode3);
    linkD(dnode2, dnode3, NULL);
    printListD(dnode1);

    dnode_t *dnode0 = createDNode(0);
    addFirstD(&dnode1, dnode0);
    printListD(dnode1);
}