#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


/* Definiciones de Constantes importantes */
#define BLOCKSIZE 1024


/* Definición de Structs */
typedef struct crfile{
    bool mode; /* r=0 && w==1 */
    bool overright;
    int block;
    char* path;
    int pos_index;
    int pos_data;
    int pos_inSim;
    int pos_inDob;
    int pos_inTri;
    int bytes_readed;
    int bytes_written;
    int size;
} crFILE;

#define min(a, b) (((a) < (b)) ? (a) : (b))

/* Declaraciones de funciones generales */
void cr_mount(char*diskname);             // DONE
void cr_bitmap(unsigned block, bool hex); // DONE
int cr_exists(char*path);                 // DONE
void cr_ls(char*path);                    // DONE
int cr_mkdir(char*foldername);            // DONE

// Funciones miscelaneas
void print_block(FILE * db);


/* Declaraciones de funciones de manejo de archivos */
crFILE*cr_open(char*path, char mode);                     // DONE
int cr_read(crFILE*file_desc, void*buffer, int nbytes);   // Pablo ON IT
int cr_write(crFILE*file_desc, void*buffer, int nbytes);  // Henry ON IT
int cr_close(crFILE*file_desc);                           // DONE
int cr_rm(char*path);                                     // DONE
int cr_unload(char*orig, char*dest);                      // TODO
int cr_load(char*orig);                                   // TODO

