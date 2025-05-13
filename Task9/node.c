#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node_t* createNode(int data) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void link(node_t **head, node_t *newNode) {
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

void printList(node_t *head) {
    if (head == NULL) {
        printf("The List is empty\n");
        return;
    }
    int count = 0;
    node_t *current = head;
    while (current != NULL) {
        count++;
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\nThe List length is %d\n", count);
}

void addFirst(node_t **head, node_t *newNode) {
    if (newNode == NULL) {
        return;
    }
    if (*head == NULL) {
        *head = newNode;
        newNode->next = NULL;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void addLast(node_t **head, node_t *newNode) {
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    if (newNode == NULL) {
        return;
    }
    node_t *current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = NULL;
}

void delete(node_t **head, node_t *node) {
    if (*head == NULL || node == NULL) {
        return;
    }
    if (*head == node) {
        *head = node->next;
        return;
    }
    node_t *current = *head;
    while (current->next != NULL) {
        if (current->next == node) {
            current->next = node->next;
            return;
        }
        current = current->next;
    }
}

void freeList(node_t **head) {
    node_t *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int size(node_t *head) {
    int count = 0;
    node_t *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int returnData(node_t *head) {
    if (head == NULL) {
        return -1;
    }
    return head->data;
}