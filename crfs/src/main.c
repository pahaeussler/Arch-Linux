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
	cr_mount(argv[1]);

	char* orig = "/memes";
	// char* orig = "dir/texto.txt";
	// char* orig = "Withered Leaf.mp3";
	// char* out = "embeces.jpg";
	
	
	// char* orig = "intro.txt";
	// char* out = "out.txt";


	// char* orig = "/embeces.jpg";
	// char* out = "out.jpg";
    char* out = "results";
	
	// char* orig = "memes/sudo1.jpg";

	cr_unload(orig, out);
    // cr_close(file_desc);

  return 0;
}

