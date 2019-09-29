// #include <stdio.h>
// #include <stdlib.h>
#include <stdint.h>
// #include <math.h>


#pragma once

typedef struct node{
    Node* father;
    Node* next;
    Node* before;
    Node* child;
    uint8_t *name;
    uint8_t type;
    uint32_t pointer;
} Node;
