#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "cr_API.h"


void print_block(FILE *db){  // Si se necesita en alguna función puntual mover al archivo de la función, En otro caso declarar en functions.h
    uint8_t bitmap;
    for(int i = 0; i < 16; i++){
		fread(&bitmap, 1, 1, db);
		int k = 7;
		for(int j = 7; j > -1; j--){
			printf("%d ", (bitmap<<j)&1);
			k++;
		}
		printf("\n");
	}
	printf("\n");
}
