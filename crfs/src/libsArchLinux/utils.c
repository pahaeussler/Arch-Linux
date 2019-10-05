/* 

CODE ADAPTED FROM: https://www.techiedelight.com/trie-implementation-insert-search-delete/

*/
#include "./utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>


/* Definicio  de Funciones */
void utilsLS(char *path, FILE *disk){
    uint8_t *data = calloc(ENTRY_SIZE, sizeof(uint8_t));
    if(!strcmp(path, "/") || !strcmp(path, "./" || !strcmp(path, "")){  // Path en Root
        for(int i=0; i<BLOCK_ENTR; i++){
            fseek(disk, ENTRY_SIZE*i, SEEK_SET);
            fread(data, sizeof(uint8_t), ENTRY_SIZE, disk);
            readDirEntry(data);
        }
    }
    else{
        unsigned int idx = 0x00;
        char *dir = malloc(sizeof(path));
        strcopy(dir, path);
        const char *delim = "/";  // Delimiter for paths
        char ptr[DIR_NAME] = strtok(path, delim);
        while(ptr != NULL){
            idx = getPointer(idx, ptr, disk);
            if(!idx){  // Directory does not exists
                printf("%s Does not exists, Missing Dir: %s\n", path, ptr);
                free(dir);
                free(data);
                return;
            }
            ptr = strtok(NULL, delim);
        }
        for(unsigned int i=0; i<BLOCK_ENTR; i++){
            fseek(disk, ENTRY_SIZE*i + BLOCK_SIZE*idx, SEEK_SET);
            fread(data, sizeof(uint8_t), ENTRY_SIZE, disk);
            readDirEntry(data);
        }
        free(dir);
    }
    free(data);
}


int readDirEntry(uint8_t *data){
    char entry[DIR_NAME];
    if(data[0] == (uint8_t)0x01) return 0;  // Entrada Inválida
    else if(data[0] == (uint8_t)0x02){   // Subdirectorio Válido
        strcopy(entry, &data[1], DIR_NAME);
        printf("%s\n", &entry);
    }
    else if(data[0] == (uint8_t)0x04){  // Archivo Válido
        strcopy(entry, &data[1], DIR_NAME);
        printf("%s\n", &entry);
    }
    else if(data[0] == (uint8_t)0x08){  // Directorio actual
        strcopy(entry, &data[1], DIR_NAME);
        printf("%s\n", &entry);
    }
    else if(data[0] == (uint8_t)0x10){  // Directorio padre
        strcopy(entry, &data[1], DIR_NAME);
        printf("%s\n", &entry);
    }
}


unsigned int getPointer(unsigned int start, char *name, FILE *disk){
    uint8_t *data = calloc(ENTRY_SIZE, sizeof(uint8_t));
    uint8_t entry[DIR_NAME];
    unsigned int idx = 0;
    for(int i=0; i<BLOCK_ENTR; i++){
        fseek(disk, ENTRY_SIZE*i + BLOCK_SIZE*idx, SEEK_SET);
        fread(data, sizeof(uint8_t), ENTRY_SIZE, disk);
        if(data[0] == (uint8_t)0x02 || data[0] == (uint8_t)0x04){
            strcopy(entry, &data[1], DIR_NAME);
            if(!strcmp(entry, name)){
                idx = (unsigned int)((unsigned int)(data[30] * 256) + (unsigned int)(data[31]));
                break;
            }
        }
    }
    free(data);
    return idx;
}
