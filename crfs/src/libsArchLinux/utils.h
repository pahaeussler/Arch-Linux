#pragma once
#include <stdlib.h>
#include <stdio.h>


/* Definicion de Macros */
#define CHARSIZE 26 // TODO: Should be more because it will allow numbers, uppercase, lowercase and dots.


/* Definicion de Structs y Enum */
typedef enum C{
    fsFile,
    fsDir
} fsClass;

typedef struct T{
	int isLeaf;	// 1 when node is a leaf node
	int        disk_addr;
    fsClass   blk_type;
	struct T* character[CHAR_SIZE];
} Trie;


/* Definicion de Funciones */
Trie* getNewTrieNode();
void insert(Trie *head, char* str);
int search(Trie* head, char* str);
int haveChildren(Trie* curr);
int deletion(Trie **curr, char* str);
void deleteAll(Trie *head);  //TODO: write function in hbg_utils.c
int getIndex(char letter);   //TODO: obtener indice ASCII apropiado
