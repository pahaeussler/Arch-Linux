
#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


// #pragma once
// #include <stdlib.h>
// #include <stdio.h>
/* Definiciones de Macros */
/*bytes*/
#define DISK__SIZE  1048576
#define BLOCK_SIZE  1024
/* numero de entradas por bloque */
#define BLOCK_ENTR  32
/* Tamaño de la entrada */
#define ENTRY_SIZE  32

#define DIR__VAL  1
#define DIR__POS  4
#define DIR_NAME  27

/* Numero de bits por bloque */
#define BIT_BLKS  128

/* Tamaño numero de bloque */
#define IDX_SIZE  4
#define IDX_PTRS  1008
#define IDX_DSIM  4
#define IDX_DDOB  4
#define IDX_DTRI  4


// typedef struct T{
// 	int isLeaf;	// 1 when node is a leaf node
// 	int        disk_addr;
//     fsClass   blk_type;
// 	struct T* character[CHAR_SIZE];
// } Trie;

/* Definiciones de Funciones */
/* Funciones de LS */
int readDirEntry(uint8_t *data);
void utilsLS(char *path, FILE *disk);
unsigned int getPointer(unsigned int start, char *name, FILE *disk);
