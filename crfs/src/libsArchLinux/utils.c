#include "./utils.h"
#include "./cr_API.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>


/* Definicio  de Funciones */
uint8_t disk_exists(char *disk_path){
    FILE *f = fopen(disk_path, "r");
    uint8_t ok;
    if(!f) ok = 0;
    else ok = 1;
    fclose(f); 
    return ok;
}


uint32_t path2Ptr(char *path, FILE *disk){
    char *dir = calloc(strlen(path)+1, sizeof(char));
    strcpy(dir, path);
    uint32_t idx = 0x00;
    uint32_t aux = 0x00;
    char *delim = "/";  // Delimiter for paths
    char *ptr = strtok(dir, delim);
    while(ptr != NULL){
        idx = pointerGetter(idx, ptr, disk);
        if(!idx){  // Directory does not exists
            printf("%s Does not exists, Missing Dir: %s\n", path, ptr);
            break;
        }
        ptr = strtok(NULL, delim);
        aux = idx;
    }
    free(dir);
    return idx;
}


uint32_t pointerGetter(uint32_t start, const char *name, FILE *disk){
    uint8_t entry[DIR_NAME];
    uint8_t valid;
    for(int i=0; i<BLOCK_ENTR; i++){
        fread(&valid, sizeof(uint8_t), DIR__VAL, disk);
        if(valid == (uint8_t)0x02 || valid == (uint8_t)0x04){
            fread(&entry, sizeof(uint8_t), DIR_NAME, disk);
            if(!strcmp(entry, name)){
                start = get_pointer(disk);
                break;
            }
            else fseek(disk, DIR__VAL, SEEK_CUR);
            //printf("\n%s: %ld\n%s: %ld\n", entry, strlen(entry), name, strlen(name));
        }
        else fseek(disk, DIR_NAME + DIR__POS, SEEK_CUR);
    }
    return start;
}


uint32_t readDirEntry(FILE *disk){
    uint8_t valid;
    uint8_t name[DIR_NAME];
    fread(&valid, sizeof(uint8_t), DIR__VAL, disk);
    if(valid == (uint8_t)0x02){   // Subdirectorio Válido
        fread(&name, sizeof(uint8_t), DIR_NAME, disk);
        printf("%s\n", name);
        //return get_pointer(disk);
    }
    else if(valid == (uint8_t)0x04){  // Archivo Válido
        fread(&name, sizeof(uint8_t), DIR_NAME, disk);
        fseek(disk, DIR__POS, SEEK_CUR);
        printf("%s\n", name);
    }
    else if(valid == (uint8_t)0x08){  // Directorio actual
        fread(&name, sizeof(uint8_t), DIR_NAME, disk);
        fseek(disk, DIR__POS, SEEK_CUR);
        printf("%s\n", name);
    }
    else if(valid == (uint8_t)0x10){  // Directorio padre
        fread(&name, sizeof(uint8_t), DIR_NAME, disk);
        fseek(disk, DIR__POS, SEEK_CUR);
        printf("%s\n", name);
    }
    else if(valid == (uint8_t)0x20){
        fread(&name, sizeof(uint8_t), DIR_NAME, disk);
        return get_pointer(disk);
    }
    fseek(disk, ENTRY_SIZE, SEEK_CUR);
    return 0xFFFF;
}


void utilsLS(char *path, FILE *disk){
    unsigned int next_pos;
    if(!strcmp(path, "/..") || !strcmp(path, "./..") || !strcmp(path, "..")){
        printf("ERROR(%s): Root no tiene directorio padre [%s]", __func__, path);
        return;
    } 
    else if(!strcmp(path, "./") || !strcmp(path, "/") || !strcmp(path, ".") || !strcmp(path, "")){  // Path en Root
        for(int i=0; i<BLOCK_ENTR; i++){
            fseek(disk, ENTRY_SIZE*i, SEEK_SET);
            next_pos = readDirEntry(disk);
            if(next_pos!=0xFFFF){
                for(int i=0; i<BLOCK_ENTR; i++){
                    fseek(disk, next_pos*BLOCK_SIZE + ENTRY_SIZE*i, SEEK_SET);
                    readDirEntry(disk);
                }
            }
        }
    }
    else{
        for(int i=1; i<strlen(path); i++){
            if(path[i] == '.' && !(path[i-1] == '/' || path[i-1] == '.')){
                printf("ERROR(%s): %s es un Archivo", __func__, path);
                return;
            }    
        }
        unsigned int idx = path2Ptr(path, disk);
        if(!idx){
            printf("ERROR(%s): %s Path does not exists:\n", __func__, path);
            return;
        }
        for(unsigned int i=0; i<BLOCK_ENTR; i++){
            fseek(disk, ENTRY_SIZE*i + BLOCK_SIZE*idx, SEEK_SET);
            next_pos = readDirEntry(disk);
            if(next_pos!=0xFFFF){
                // printf("%s: NUEVAS ENTRADAS!!\n", __func__);
                for(int i=0; i<BLOCK_ENTR; i++){
                    fseek(disk, next_pos*BLOCK_SIZE + ENTRY_SIZE*i, SEEK_SET);
                    readDirEntry(disk);
                }
            }
        }
    }
    return;
}
