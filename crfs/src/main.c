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
#include <sys/stat.h>
 #include <sys/types.h>


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


	/* Test para cr_mount */

	cr_mount(argv[1]);
	printf("[cr_API/cr_mount]: Disco %s Montado", DISKNAME);
	printf("\n\n\n\n");

	/* Test para ls */
	printf("Test para cr_ls(./memes/../dir/./subdir/../../memes)\n");
	cr_ls("./memes/../dir/./subdir/../../memes");
	printf("\nTest para cr_ls(memes)\n\n");
	cr_ls("memes");

/* Test para exists */
	printf("Test para cr_exists(./memes/../dir/./subdir/../../memes): %d\n", cr_exists("./memes/../dir/./subdir/../../memes"));
	printf("\nTest para cr_ls(memes): %d\n\n", cr__exists("memes"));
	printf("Test para cr_exists(./memes/../dir/./subdir/../../pepes): %d\n", cr_exists("./memes/../dir/./subdir/../../memes"));
	printf("\nTest para cr_ls(memes): %d\n\n", cr__exists("pepes"));



  return 0;
}

