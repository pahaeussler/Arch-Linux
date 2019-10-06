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
    if(!strcmp(path, "/..") || !strcmp(path, "./..") || !strcmp(path, "..")){
        printf("ERROR: Root no tiene directorio padre [%s]", path);
        free(data);
        return;
    } 
    else if(!strcmp(path, "./") || !strcmp(path, "/") || !strcmp(path, ".") || !strcmp(path, "")){  // Path en Root
        for(int i=0; i<BLOCK_ENTR; i++){
            fseek(disk, ENTRY_SIZE*i, SEEK_SET);
            fread(data, sizeof(uint8_t), ENTRY_SIZE, disk);
            readDirEntry(data);
        }
    }
    else{
        for(int i=1; i<strlen(path); i++){
            if(path[i] == '.' && !(path[i-1] == '/' || path[i-1] == '.')){
                printf("ERROR: %s es un Archivo", path);
                free(data);
                return;
            }    
        }
        unsigned int idx = 0x00;
        char *dir = calloc(strlen(path)+1, sizeof(char));
        strcpy(dir, path);
        char *delim = "/";  // Delimiter for paths
        char *ptr = strtok(dir, delim);
        while(ptr != NULL){
            idx = getPointer(idx, ptr, disk);
            if(!idx){  // Directory does not exists
                printf("%s Does not exists, Missing Dir: %s\n", path, ptr);
                break;
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
    return;
}


int readDirEntry(uint8_t *data){
    char entry[DIR_NAME];
    // if(data[0] == (uint8_t)0x01) return 0;  // Entrada Inválida
    if(data[0] == (uint8_t)0x02){   // Subdirectorio Válido
        strncpy(entry, data+1, DIR_NAME);
        printf("%s\n", entry);
    }
    else if(data[0] == (uint8_t)0x04){  // Archivo Válido
        strncpy(entry, data+1, DIR_NAME);
        printf("%s\n", entry);
    }
    else if(data[0] == (uint8_t)0x08){  // Directorio actual
        strncpy(entry, data+1, DIR_NAME);
        printf("%s\n", entry);
    }
    else if(data[0] == (uint8_t)0x10){  // Directorio padre
        strncpy(entry, data+1, DIR_NAME);
        printf("%s\n", entry);
    }
    //else printf("\nEsto jamás lo habia visto :O\n");
    return 0;
}


unsigned int getPointer(unsigned int start, char *name, FILE *disk){
    uint8_t *data = calloc(ENTRY_SIZE, sizeof(uint8_t));
    uint8_t entry[DIR_NAME];
    uint8_t names[DIR_NAME];
    unsigned int idx = start;
    for(int i=0; i<BLOCK_ENTR; i++){
        fseek(disk, ENTRY_SIZE*i + BLOCK_SIZE*idx, SEEK_SET);
        fread(data, sizeof(uint8_t), ENTRY_SIZE, disk);
        if(data[0] == (uint8_t)0x02 || data[0] == (uint8_t)0x04){
            strncpy(entry, data+1, DIR_NAME);
            strncpy(names, name, DIR_NAME);
            /*printf("\nENTRY: [");
            for (int i = 0; i < sizeof(entry); i ++) {
                printf(" %02x", entry[i]);
            }
            printf("]=> %s\nNAMES: [", entry);
            for (int i = 0; i < sizeof(names); i ++) {
                printf(" %02x", names[i]);
            }
            printf("]=>%s\n", names);*/
            if(!strcmp(entry, names)){
                idx = (unsigned int)((unsigned int)(data[30] * 256) + (unsigned int)(data[31]));
                break;
            }
        }
    }
    free(data);
    return idx;
}
