#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "cr_API.h"
#include "functions.h"
#include "globals.h"

extern char* DISKNAME;


/** Metodo main del programa */
int main(int argc, char *argv[])
{
	// char diskname = "simdiskformat.bin";
	cr_mount(argv[1]);
	uint8_t val;
	uint8_t name[27];
	int32_t pointer;
	// int block[128];

	FILE *test = fopen(DISKNAME, "r");
	fread(&val, sizeof(uint8_t), 1, test);
	printf("%x ", val);
	fread(&name, sizeof(uint8_t)*27, 1, test);
	printf("%s", name);
	fread(&pointer, sizeof(uint8_t)*4, 1, test);
	printf("%x\n", pointer);
	// Retornar 0 significa que el programa termina sin errores

	// fread(&block, 128, 1, test);
	// printf("bloque 1\n");
	// for (int i = 0; i < 128; i++)
	// {
	// 	// printf("%x\t", block[i]);
	// 	printf(BYTE_TO_BINARY_PATTERN"\t", BYTE_TO_BINARY(block[i]));
	// }
	// printf("\n");

	uint8_t bitmap;
	for(int i = 0; i < 992; i++){
		fread(&bitmap, sizeof(uint8_t), 1, test);
	}

	unsigned block;
	bool hex=0;
	fread(&block, sizeof(unsigned), 1, test);
	cr_bitmap(block, hex);

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
	
	return 0;
}
