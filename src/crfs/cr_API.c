#include "cr_API.h"
#include <stdio.h>
#include <stdlib.h>

#include "globals.h"

// crFILE*cr_open(char*path, char mode){
    /* Funci ́on para abrir un archivo. Simodees‘r’, buscael archivo en la rutapathy retorna uncrFILE*que lo representa. Simodees‘w’, se verifica que el archivono exista en la ruta especificada y se retorna un nuevocrFILE*que lo representa.*/
    // crFILE crfile;
    // if (mode =="r"){
    //     printf("FALTA IMPLEMENTAR R EN cr_open\n");
    // }
    // else if (mode == "w")
    // {
    //     printf("FALTA IMPLEMENTAR W EN cr_open\n");
    // }
    // return crfile;
// }


int cr_read(crFILE*file_desc, void*buffer, int nbytes){
    /* Función para leer archivos. Leelos siguientes n bytes desde el archivo descrito porfiledescy los guarda en la direcci ́on apuntadaporbuffer. Debe retornar la cantidad de Byte efectivamente le ́ıdos desde el archivo. Esto es importante sinbyteses mayor a la cantidad de Byte restantes en el archivo. La lectura dereadse efect ́ua desde la posici ́ondel archivo inmediatamente posterior a la ́ultima posici ́on le ́ıda por un llamado aread.*/
	// FILE *test = fopen(DISKNAME, "r");
    int i = 0;
    // while (fread(&buffer[i], nbytes, 1, test))
	//     i++;
    // }
    return i;
}

int cr_write(crFILE*file_desc, void*buffer, int nbytes){
    /* Funci ́on para escribir ar-chivos. Escribe en el archivo descrito porfiledesclosnbytesque se encuentren en la direcci ́on indicadaporbuffer. Retorna la cantidad de Byte escritos en el archivo. Si se produjo un error porque no pudo seguirescribiendo, ya sea porque el disco se llen ́o o porque el archivo no puede crecer m ́as, este n ́umero puede sermenor anbytes(incluso0).*/
    return 0;
}

int cr_close(crFILE*file_desc){
    /* Funci ́on  para  cerrar  archivos.  Cierra  el  archivo  indicado  porfiledesc. Debe garantizar que cuando esta funci ́on retorna, el archivo se encuentra actualizado en disco.*/
    return 0;
}

int cr_rm(char*path){
    /* Funci ́on para borrar archivos. Elimina el archivo referenciado por la rutapathdel directorio correspondiente. Los bloques que estaban siendo usados por el archivo deben quedar libres.*/
    return 0;
}

int cr_unload(char*orig, char*dest){
    /* Funci ́on que se encarga de copiar un archivo o un ́arbolde directorios (es decir, un directorio ytodossus contenidos) del disco, referenciado pororig, hacia un nuevo archivo o directorio de rutadesten su computador.*/
    return 0;
}

int cr_load(char*orig){
    /* Funci ́on que se encarga de copiar un archivo o ́arbol de directorios, referen-ciado pororigal disco. En caso de que un archivo sea demasiado pesado para el disco, se debe escribir todo lo posible hasta acabar el espacio disponible.*/
    return 0;
}