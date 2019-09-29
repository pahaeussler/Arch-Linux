#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "functions.h"
#include "globals.h"

extern char* DISKNAME;

void cr_mount(char*diskname){
    /* Funcion para montar el disco. Establece como variable global laruta local donde se encuentra el archivo.bincorrespondiente al disco. */
	DISKNAME = diskname;
}

void cr_bitmap(unsigned block, bool hex){
    /* Función  para  imprimir  elbitmap.  Cada  vez  quese llama esta funci ́on, imprime enstderrel estado actual del bloque debitmapcorrespondiente ablock(bitmapblock∈{1, ...,129}), ya sea en binario (sihexesfalse) o en hexadecimal (sihexestrue). Sise ingresablock= 0, se debe imprimirel bitmap completo, imprimiendo ademas una linea con la cantidad de bloques ocupados, y una segunda linea con la cantidad de bloques libres.*/
    if (hex){

    }
    else{
        // /* 8192 bites */
        // int j;
        // char mask[32*sizeof(unsigned) + 1] = {0};
        // for (j = 0; j < (8*sizeof(unsigned) + 1); j++) {
        // mask[j] = (block << j) & (1 << (8*sizeof(unsigned)-1)) ? '1' : '0';
        // }
        // printf("value is b%s\n", mask);
    }
}

int cr_exists(char*path){
    /*Funcion para ver si un archivo o carpeta existe en la ruta especificada porpath. Retorna 1 si el archivo o carpeta existe y 0 en caso contrario. */
    return 0;
}

void cr_ls(char*path){
    /*Funcion para listar los elementos de un directorio del disco. Imprime en pan-talla los nombres de todos los archivos y directorios contenidos en el directorio indicado porpath. */
}

int cr_mkdir(char*foldername){
    /* Funcion para crear directorios. Crea el directorio vac ́ıo referidoporfoldername. */
    return 0;
}

void print_block(FILE *db){
    uint8_t bitmap;
    for(int i = 0; i < 16; i++){
		fread(&bitmap, 1, 1, db);
		int k = 7;
		for(int j = 0; j < 8; j++){
			printf("%d ", (bitmap<<j)>>k);
			k++;
		}
		printf("\n");
	}
	printf("\n");
}