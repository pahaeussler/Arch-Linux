#include "./cr_API.h"
// #include "./graph.h"
#include "./utils.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


/* VARIABLES GLOBALES */
char* DISKNAME;


/* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # */

/* FUNCIONES GENERALES */
void cr_mount(char* diskname){
    /* Funcion para montar el disco. Establece como variable global laruta local donde se encuentra el archivo.bincorrespondiente al disco */
	DISKNAME = diskname;
	/* TODO-> Atender CASOS BORDE:
	 * archivo diskname no existe
	 */
}

void cr_bitmap(unsigned block, bool hex){
    /* Función  para  imprimir  elbitmap.  Cada  vez  quese llama esta funci ón, imprime enstderrel estado actual del bloque debitmapcorrespondiente ablock(bitmapblock∈{1, ...,129}), ya sea en binario (sihexesfalse) o en hexadecimal (sihexestrue). Sise ingresablock= 0, se debe imprimirel bitmap completo, imprimiendo ademas una linea con la cantidad de bloques ocupados, y una segunda linea con la cantidad de bloques libres.*/
    FILE* disk = fopen(DISKNAME, "rb");
    fseek(disk, 1024, SEEK_SET);
    if (hex){
        uint16_t bitmap;
        if((130 > block) && (block > 0))
        {
            fprintf(stderr,"%d \n", block);
            fseek(disk, 1024*(block-1), SEEK_CUR);
            for(int i = 0; i < 1024; i++){
                fread(&bitmap, 1, 1, disk);
                for(int j = 1; j > -1; j--){
                    uint16_t bitmap2 = bitmap;
                    fprintf(stderr, "%x", (bitmap2>>j*4)&0x0F);
                }

                if(i%2){
                    fprintf(stderr, "\n");
                }
            }
        }
        else if(block == 0)
        {
            fprintf(stderr, "pass");
            for(int i = 0; i < 1024*128; i++){
                fread(&bitmap, 1, 1, disk);
                for(int j = 1; j > -1; j--){
                    uint16_t bitmap2 = bitmap;
                    fprintf(stderr, "%x", (bitmap2>>j*4)&0x0F);
                }

                if(i%2){
                    fprintf(stderr, "\n");
                }
            }
        }

    }
    else{
        uint16_t bitmap;
        if((130 > block) && (block > 0))
        {
            fseek(disk, 1024*(block - 1), SEEK_CUR);
            for(int i = 0; i < 1024; i++){
                fread(&bitmap, 1, 1, disk);

                for(int j = 7; j > -1; j--){
                    uint16_t bitmap2 = bitmap;
                    fprintf(stderr, "%d", (bitmap2>>j)&1);
                }

                if(i%2){
                    fprintf(stderr, "\n");
                }
            }
        }
        /* Bloque directorio */
        else if(block == 0)
        {
            for(int i = 0; i < 1024*128; i++){
                fread(&bitmap, 1, 1, disk);

                for(int j = 7; j > -1; j--){
                    uint16_t bitmap2 = bitmap;
                    fprintf(stderr, "%d", (bitmap2>>j)&1);
                }
                if(i%2){
                    fprintf(stderr, "\n");
                }
            }
        }
    }
    fclose(disk);
}

uint8_t get_valid_dir(FILE* pos){
    uint8_t dato;
	uint8_t name[27];
	int32_t pointer;
	fread(&dato, sizeof(uint8_t), 1, pos);
	fseek(pos, -1, SEEK_CUR);
    return dato;

}


int get_pointer(FILE* pos){
	uint32_t pointer;
    // fseek(pos, 28, SEEK_CUR);
	int result = 0;
	for(int i = 0; i < 4; i++)
	{
		fread(&pointer, 1, 1, pos);
		result += pointer * pow(16, 2*(3-i));
	}
	// fseek(pos, -32, SEEK_CUR);
	return result;
}

int cr_exists_recur(FILE* disk, char** path, int len, int my_dir){
    printf("mi dir %d\n", my_dir);
    for(int i = 0; i < 32; i++){
        uint8_t valid;
	    uint8_t name[27];
	    uint32_t pointer;
        fread(&valid, sizeof(uint8_t), 1, disk);
	    printf("%x \n", valid);
        fread(&name, sizeof(uint8_t)*27, 1, disk);
        int direction = get_pointer(disk);
        
        printf("value: %d, name: %s, dir: %d\n", valid, name, direction);
    //     if(valid == 32){
    //         fseek(disk, direction*1024, SEEK_SET);
    //         cr_exists_recur(disk, path, len);
    //         fseek(disk, my_dir*1024, SEEK_SET);
    //     }
    //     else if(valid == 2 && strcmp(name, path[0]))
    //     {
    //         if(len == 1) return 1;
    //         char **new_path = calloc(len-1, sizeof(char*));
    //         for(int i = 0; i < len-1; i++){
    //             new_path[i] = calloc(20, sizeof(char));
    //             strcpy(new_path[i], path[i+1]);
    //         }
    //         fseek(disk, direction*1024, SEEK_SET);
    //         if(cr_exists_recur(disk, new_path, len-1)) return 1;
    //         fseek(disk, my_dir*1024, SEEK_SET);
    //     }
    }
    
    return 0;
}

int cr_exists(char* path){
    /*Funcion para ver si un archivo o carpeta existe en la ruta especificada porpath. Retorna 1 si el archivo o carpeta existe y 0 en caso contrario. */
    FILE *disk = fopen(DISKNAME, "rb");
    char **dir_arr = calloc(10, sizeof(char*));
    for(int i = 0; i < 10; i++){
        dir_arr[i] = calloc(20, sizeof(char));
    }
    char *dirname = malloc(strlen(path));
    strcpy(dirname, path);
    int val = 0;
    char *stok = strtok(dirname, "/");
    while(stok != NULL && val < 10){
        strcpy(dir_arr[val], stok);
        stok = strtok(NULL, "/");
        val++;
    }
    cr_exists_recur(disk, dir_arr, val, 0);
    for(int i = 0; i < 10; i++){
        free(dir_arr[i]);
    }
    free(dir_arr);
    
}

void cr_ls(char* path){
    /*Funcion para listar los elementos de un directorio del disco. Imprime en pan-talla los nombres de todos los archivos y directorios contenidos en el directorio indicado porpath. */
    /* Henry */
    FILE* disk = fopen(DISKNAME, "rb");
    

}

int cr_mkdir(char* foldername){
    /* Funcion para crear directorios. Crea el directorio vacio referido por foldername. */

    char *dirname = malloc(strlen(foldername));
    char *dirname2 = malloc(strlen(foldername));
    strcpy(dirname2, foldername);
    char *stok = strtok(dirname2, "/");
    char *copy = malloc(strlen(foldername));
    while(stok != NULL){
        strcpy(copy, stok);
        printf("%s\n", stok);
        stok = strtok(NULL, "/");
        if(stok != NULL)
        {
            strcat(dirname, "/");
            strcat(dirname, copy);
        }
    }
    if(cr_exists(dirname)){

    }
    free(dirname);
    free(dirname2);
    free(copy);
    return 0;
}


/* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # */

/* FUNCIONES DE MANEJO DE ARCHIVOS */
// crFILE*cr_open(char* path, char mode){
//     /* Función para abrir un archivo. Si mode es‘r’, busca el archivo en la rutapathy retorna uncrFILE*que lo representa. Simodees‘w’, se verifica que el archivono exista en la ruta especificada y se retorna un nuevocrFILE*que lo representa.*/
//     crFILE crfile;
//     if (mode =="rb"){
//         printf("FALTA IMPLEMENTAR R EN cr_open\n");
//     }
//     else if (mode == "wb")
//     {
//         printf("FALTA IMPLEMENTAR W EN cr_open\n");
//     }
//     return &crfile;
// }
 
int cr_read(crFILE* file_desc, void* buffer, int nbytes){
    /* Función para leer archivos. Leelos siguientes n bytes desde el archivo descrito porfiledescy los guarda en la dirección apuntadaporbuffer. Debe retornar la cantidad de Byte efectivamente le ́ıdos desde el archivo. Esto es importante sinbyteses mayor a la cantidad de Byte restantes en el archivo. La lectura dereadse efect ́ua desde la posici óndel archivo inmediatamente posterior a la ́ultima posici ón le ́ıda por un llamado aread.*/
	// FILE *test = fopen(DISKNAME, "r");
    int i = 0;
    // while (fread(&buffer[i], nbytes, 1, test))
	//     i++;
    // }
    return i;
}

int cr_write(crFILE* file_desc, void* buffer, int nbytes){
    /* Función para escribir archivos. Escribe en el archivo descrito por filedesc los nbytes que se encuentren en la dirección indicada por buffer. Retorna la cantidad de Byte escritos en el archivo. Si se produjo un error porque no pudo seguirescribiendo, ya sea porque el disco se llen ó o porque el archivo no puede crecer m ́as, este n ́umero puede sermenor anbytes(incluso0).*/
    return 0;
}

int cr_close(crFILE* file_desc){
    /* Función para cerrar archivos.  Cierra el archivo  indicado  por filedesc. Debe garantizar que cuando esta funci ón retorna, el archivo se encuentra actualizado en disco.*/
    return 0;
}

int cr_rm(char* path){
    /* Función para borrar archivos. Elimina el archivo referenciado por la rutapathdel directorio correspondiente. Los bloques que estaban siendo usados por el archivo deben quedar libres.*/
    return 0;
}

int cr_unload(char* orig, char* dest){
    /* Función que se encarga de copiar un archivo o un ́arbolde directorios (es decir, un directorio ytodossus contenidos) del disco, referenciado por orig, hacia un nuevo archivo o directorio de rutadesten su computador.*/
    return 0;
}

int cr_load(char* orig){
    /* Función que se encarga de copiar un archivo o ́arbol de directorios, referenciado por origal disco. En caso de que un archivo sea demasiado pesado para el disco, se debe escribir todo lo posible hasta acabar el espacio disponible.*/
    return 0;
}

