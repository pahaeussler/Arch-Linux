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


#define getName(var) #var


extern char* DISKNAME;

int main(int argc, char **argv){
    /*
    Checking Correct Usage
    */ 
    if(argc != 2){
    printf("Error: Wrong number of arguments: %d\n", argc);
    printf("Usage: ./crfs <disk path>\n");
    }
	cr_mount(argv[1]);

	// // char* path = "/memes/yoda.jpg";
	// char* path = "/intro.txt";
	// char mode = "r";
	// // cr_ls("/memes");
	// // printf("%d\n", cr_ls("/"));
	// crFILE* file_desc = cr_open(path, mode);
	// int nbytes = 32;
	// char buffer[nbytes+1];
	// buffer[nbytes] = '\0';
	// printf("size: %d\n", file_desc->size);
	// for (int i = 0; i < 1021; i++)
	// {
	// 	cr_read(file_desc, buffer, nbytes);
	// 	// buffer[nbytes]=NULL;
	// 	printf("%s", buffer);
	// 	// printf("pos index: %d\tpos data: %d\n", file_desc->pos_index, file_desc->pos_data);
	// }
	// printf("\n");

	char* orig = "intro.txt";
	// char* orig = "/memes/yoda.jpg";

	cr_unload(orig, orig);
	// cr_close(file_desc);
  return 0;
}

