/*

Main Code testing de Functionality of crfs.
To Run: ./crfs $PWD/dsk/simdiskfilled.bin

*/
#include "libsArchLinux/cr_API.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


extern char* DISKNAME;

int main(int argc, char **argv){
    /*
    Checking Correct Usage
    */ 
    if(argc != 2){
    printf("Error: Wrong number of arguments: %d\n", argc);
    printf("Usage: ./crfs <disk path>\n");
    }
    
    // char diskname = "simdiskformat.bin";
	cr_mount(argv[1]);
	// uint8_t val;
	// uint8_t name[27];
	// uint32_t pointer;
	// // // int block[128];
	char* path = "/memes/yoda.jpg";
	char mode = "r";
	// printf("%d\n", cr_exists("/memes/yodas.jpg"));
	// printf("%d\n", cr_exists_direction(path));
	crFILE* file_desc = cr_open(path, mode);

	int nbytes = 1;
	// void* buffer;
	char buffer[nbytes+1];
	for (int i = 0; i < 10; i++)
	{
		cr_read(file_desc, buffer, nbytes);
		// buffer[nbytes]=NULL;
		printf("%s\n", buffer);
		printf("pos: %d\n", file_desc->pos);
	}



	printf("dir: %d\n", file_desc->block);
	cr_close(file_desc);
	// void* buffer;
	// int nbytes;
	// crFILE* file_desc,
	// FILE *test = fopen(DISKNAME, "r");
	// // cr_mkdir("hola/chao/nosVimo/adios");
	// fread(&val, sizeof(uint8_t), 1, test);
	// printf("%d ", val);
	// fread(&name, sizeof(uint8_t)*27, 1, test);
	// printf("%s ", (char*)name);
	// fread(&pointer, sizeof(uint8_t)*4, 1, test);
	// printf("%x\n", pointer);

	// fread(&val, sizeof(uint8_t), 1, test);
	// printf("%d ", val);
	// fread(&name, sizeof(uint8_t)*27, 1, test);
	// printf("%s ", name);
	// int result = 0;
	// for(int i = 0; i < 4; i++)
	// {
	// 	fread(&pointer, sizeof(uint8_t), 1, test);
		
	// 	result += ((pointer>>4)&(0xF)) * pow(16, 2*(3-i)+1) + ((pointer)&(0xF)) * pow(16, 2*(3-i));
	// 	// printf("%x\n", pointer);
	// }
	// printf("%d\n", result);

	// fread(&val, sizeof(uint8_t), 1, test);
	// printf("%d ", val);
	// fread(&name, sizeof(uint8_t)*27, 1, test);
	// printf("%s ", name);
	// fread(&pointer, sizeof(uint32_t), 1, test);
	// printf("%d\n", pointer);
	// int result2 = 0;
	// for(int i = 0; i < 4; i++)
	// {
	// 	fread(&pointer, sizeof(uint8_t), 1, test);
		
	// 	result2 += ((pointer>>4)&(0xF)) * pow(16, 2*(3-i)+1) + ((pointer)&(0xF)) * pow(16, 2*(3-i));
	// 	// printf("%x\n", pointer);
	// }
	// printf("%d\n", result2);
	// Retornar 0 significa que el programa termina sin errores

	// // fread(&block, 128, 1, test);
	// // printf("bloque 1\n");
	// // for (int i = 0; i < 128; i++)
	// // {
	// // 	// printf("%x\t", block[i]);
	// // 	printf(BYTE_TO_BINARY_PATTERN"\t", BYTE_TO_BINARY(block[i]));
	// // }
	// // printf("\n");

	// uint8_t bitmap;
	// for(int i = 0; i < 992; i++){
	// 	fread(&bitmap, sizeof(uint8_t), 1, test);
	// }

	// unsigned block;
	// bool hex=0;
	// fread(&block, sizeof(unsigned), 1, test);
	// cr_bitmap(block, hex);

	// char dir[32];
	// int i = 0;
	// while (i<10)
	// {
	// 	printf("Linea: %d\n", i);
	// 	fread(&block, sizeof(uint8_t)*96, 1, test);
	// 	fread(&val, sizeof(uint8_t), 1, test);
	// 	printf("%x\n", val);
	// 	fread(&name, sizeof(uint8_t)*27, 1, test);
	// 	printf("%s\n", name);
	// 	fread(&pointer, sizeof(uint8_t)*4, 1, test);
	// 	printf("%x\n", pointer);
	// 	i++;
	// 	printf("\n\n\n");
	// }

	printf("End\n");
    
    return 0;
}

