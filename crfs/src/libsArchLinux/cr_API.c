#include "cr_API.h"
#include "graph.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


/* VARIABLES GLOBALES */
char* DISKNAME;


/* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # */

/* FUNCIONES GENERALES */
void cr_mount(char* diskname){
    /* Funcion para montar el disco. Establece como variable global laruta local donde se encuentra el archivo.bincorrespondiente al disco */
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

int cr_exists(char* path){
    /*Funcion para ver si un archivo o carpeta existe en la ruta especificada porpath. Retorna 1 si el archivo o carpeta existe y 0 en caso contrario. */
    return 0;
}

void cr_ls(char* path){
    /*Funcion para listar los elementos de un directorio del disco. Imprime en pan-talla los nombres de todos los archivos y directorios contenidos en el directorio indicado porpath. */
}

int cr_mkdir(char* foldername){
    /* Funcion para crear directorios. Crea el directorio vac ́ıo referidoporfoldername. */
    return 0;
}


/* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # */

/* FUNCIONES DE MANEJO DE ARCHIVOS */
crFILE*cr_open(char* path, char mode){
    /* Funci ́on para abrir un archivo. Simodees‘r’, buscael archivo en la rutapathy retorna uncrFILE*que lo representa. Simodees‘w’, se verifica que el archivono exista en la ruta especificada y se retorna un nuevocrFILE*que lo representa.*/
    crFILE crfile;
    if (mode =="r"){
        printf("FALTA IMPLEMENTAR R EN cr_open\n");
    }
    else if (mode == "w")
    {
        printf("FALTA IMPLEMENTAR W EN cr_open\n");
    }
    return &crfile;
}
 
int cr_read(crFILE* file_desc, void* buffer, int nbytes){
    /* Función para leer archivos. Leelos siguientes n bytes desde el archivo descrito porfiledescy los guarda en la direcci ́on apuntadaporbuffer. Debe retornar la cantidad de Byte efectivamente le ́ıdos desde el archivo. Esto es importante sinbyteses mayor a la cantidad de Byte restantes en el archivo. La lectura dereadse efect ́ua desde la posici ́ondel archivo inmediatamente posterior a la ́ultima posici ́on le ́ıda por un llamado aread.*/
	// FILE *test = fopen(DISKNAME, "r");
    int i = 0;
    // while (fread(&buffer[i], nbytes, 1, test))
	//     i++;
    // }
    return i;
}

int cr_write(crFILE* file_desc, void* buffer, int nbytes){
    /* Funci ́on para escribir ar-chivos. Escribe en el archivo descrito porfiledesclosnbytesque se encuentren en la direcci ́on indicadaporbuffer. Retorna la cantidad de Byte escritos en el archivo. Si se produjo un error porque no pudo seguirescribiendo, ya sea porque el disco se llen ́o o porque el archivo no puede crecer m ́as, este n ́umero puede sermenor anbytes(incluso0).*/
    return 0;
}

int cr_close(crFILE* file_desc){
    /* Funci ́on  para  cerrar  archivos.  Cierra  el  archivo  indicado  porfiledesc. Debe garantizar que cuando esta funci ́on retorna, el archivo se encuentra actualizado en disco.*/
    return 0;
}

int cr_rm(char* path){
    /* Funci ́on para borrar archivos. Elimina el archivo referenciado por la rutapathdel directorio correspondiente. Los bloques que estaban siendo usados por el archivo deben quedar libres.*/
    return 0;
}

int cr_unload(char* orig, char* dest){
    /* Funci ́on que se encarga de copiar un archivo o un ́arbolde directorios (es decir, un directorio ytodossus contenidos) del disco, referenciado pororig, hacia un nuevo archivo o directorio de rutadesten su computador.*/
    return 0;
}

int cr_load(char* orig){
    /* Funci ́on que se encarga de copiar un archivo o ́arbol de directorios, referen-ciado pororigal disco. En caso de que un archivo sea demasiado pesado para el disco, se debe escribir todo lo posible hasta acabar el espacio disponible.*/
    return 0;
}

