#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


/* Definición de Structs */
typedef struct crfile{
    bool mode; /* r=0 && w==1 */
    bool overright;
    int block;
    char* path;
    int pos;
    int size;
} crFILE;

#define min(a, b) (((a) < (b)) ? (a) : (b))

/* Declaraciones de funciones generales */
void cr_mount(char*diskname);
void cr_bitmap(unsigned block, bool hex);
int cr_exists(char*path);
void cr_ls(char*path);
int cr_mkdir(char*foldername);
// Funciones miscelaneas
void print_block(FILE * db);


/* Declaraciones de funciones de manejo de archivos */
crFILE*cr_open(char*path, char mode);
int cr_read(crFILE*file_desc, void*buffer, int nbytes);
int cr_write(crFILE*file_desc, void*buffer, int nbytes);
int cr_close(crFILE*file_desc);
int cr_rm(char*path);
int cr_unload(char*orig, char*dest);
int cr_load(char*orig);
uint32_t cr_exists_direction(char* path);

