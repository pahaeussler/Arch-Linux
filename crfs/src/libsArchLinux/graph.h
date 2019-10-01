#pragma once
// #include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// #include <math.h>


typedef struct node{
    struct node* father;
    struct node* next;
    struct node* before;
    struct node* child;
    uint8_t *name;
    uint8_t type;
    uint32_t pointer;
} Node;

Node* find_node2(char** path, Node* tree, int n);
Node* find_node(char* path, Node* tree);
Node* create_node(uint8_t val, uint8_t *name, uint32_t pointer, Node* father);
Node* node_init(FILE* harddrive, Node* self);
