#pragma once

#define NODE_H

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t* createNode(int data);
void link(node_t **head, node_t *newNode);
void printList(node_t *head);
void addFirst(node_t **head, node_t *newNode);
void addLast(node_t **head, node_t *newNode);
void delete(node_t **head, node_t *node);
void freeList(node_t **head);
void reverse(node_t **head);
int size(node_t *head);
int returnData(node_t *head);
