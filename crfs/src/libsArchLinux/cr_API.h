#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


/* Definiciones de Constantes importantes */
#define BLOCKSIZE 1024


/* Definición de Structs */
typedef struct crfile{
    
} crFILE;


/* Declaraciones de funciones generales */
void cr_mount(char*diskname);             // DONE
void cr_bitmap(unsigned block, bool hex); // DONE
int cr_exists(char*path);                 // Cristobal ON IT
void cr_ls(char*path);                    // DONE
int cr_mkdir(char*foldername);            // TODO: faltaa

// Funciones miscelaneas
void print_block(FILE * db);


/* Declaraciones de funciones de manejo de archivos */
crFILE*cr_open(char*path, char mode);                     // TODO
int cr_read(crFILE*file_desc, void*buffer, int nbytes);   // TODO
int cr_write(crFILE*file_desc, void*buffer, int nbytes);  // TODO
int cr_close(crFILE*file_desc);                           // TODO
int cr_rm(char*path);                                     // TODO
int cr_unload(char*orig, char*dest);                      // TODO
int cr_load(char*orig);                                   // TODO

