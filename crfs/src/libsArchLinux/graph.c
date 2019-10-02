#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include "./graph.h"


Node* find_node2(char** path, Node* tree, int n){
    if (!path){
        return tree;
    }
    if (n == 255){
        printf("PATH MUY LARGO");
        return NULL;
    }
    Node* actual = tree;
    char* target = path[n];
    if (!strcmp (target, actual->name))
    {
        return find_node2(path, actual, n+1);
    }
    else{
        actual = actual -> child;
        uint8_t* child_name = actual->name;
        while (strcmp (child_name, actual->name))
        {
            if (!strcmp (target, actual->name)){
                return find_node2(path, actual, n+1);
            }
            actual = actual ->next;
        }
    }    
    return NULL;
}

Node* find_node(char* path, Node* tree){
    char *array[255]; //array para cada linea
    int i = 0;
    array[i] = strtok(path,"/");
    while(array[i]!=NULL)
    {
        array[++i] = strtok(NULL,"/");
    } 
    return find_node2(&array, tree, 0);
}

Node* create_node(uint8_t val, uint8_t *name, uint32_t pointer, Node* father){
    Node* self = calloc(1, sizeof(Node));
    self->father = father;
    self->name = name;
    self->type = val;
    self->pointer->pointer; // error: invalid type argument of ‘->’ (have ‘uint32_t’ {aka ‘unsigned int’})
    self->next = NULL;
    self->before = NULL;
    self->child = NULL;
    return self;
}

Node* node_init(FILE* harddrive, Node* self){
    uint8_t val;
	uint8_t name[27];
	int32_t pointer;
    int valid = 1;
    while(valid){// #include "tree.h"
        fread(&val, sizeof(uint8_t), 1, test);  // error: ‘test’ undeclared (first use in this function)
	    fread(&name, sizeof(uint8_t)*27, 1, test);
	    fread(&pointer, sizeof(uint8_t)*4, 1, test);
        if(val!=2 || val!=4 || val!=8 ||val!=16 || val!=32){
            valid = 0;
        }
        else{
            Node* current_child = create_node(val, name, pointer, self);
            if(self->child){
                Node* curr_child = self->child;
                while(curr_child->next){
                    curr_child = curr_child->next;
                }
                curr_child->next = current_child;
                current_child->before = curr_child;
            }
            else{
                self->child->next = current_child;
                current_child->before = self->child;
            }            
        }
    }
    
    
    self->next = NULL;
    Node* before = calloc(1, sizeof(Node));
    Node* child = calloc(1, sizeof(Node));
}
