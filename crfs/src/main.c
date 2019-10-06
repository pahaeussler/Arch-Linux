/*

Main Code testing de Functionality of crfs.
To Run: ./crfs $PWD/dsk/simdiskfilled.bin

*/
#include "libsArchLinux/cr_API.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


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
    
    // char diskname = "simdiskformat.bin";
    printf("TEST cr_mount:\n\n");
	cr_mount(argv[1]);
	printf("%s Montado en %s\n\n", argv[1], getName(DISKNAME));
	
	
	/* LS test: Por ahora sólo están descomentados los tests que fallan */
	
	/*printf("TEST cr_ls:\n");
	printf("\n\nCon input ./\n");
	cr_ls("./");         // DONE
	printf("\n\nCon input /\n");
	cr_ls("/");          // DONE
	printf("\n\nCon input vacío\n");
	cr_ls("");           // DONE
	printf("\n\nCon input archivo de root\n");
	cr_ls("intro.txt");  // DONE
	printf("\n\nCon input carpetas de root\n");
	cr_ls("dir");       // DONE
	printf("\n\nCon input archivo de carpeta de root\n");
	cr_ls("memes/loops.jpg");  // DONE */
	printf("\n\nCon input carpeta de carpeta de root\n");
    cr_ls("dir/subdir/.");  // TODO: no hay display, no muestra nada
    /*printf("\n\nCon input padre de root simple\n");
    cr_ls("..");        // DONE
    printf("\n\nCon input padre de root con slash\n");
    cr_ls("/..");       // DONE
    printf("\n\nCon input padre de root con punto y slash\n");
    cr_ls("./..");/*    // DONE*/
    printf("\n\nCon input padre de carpeta de root\n");
    cr_ls("memes/..");  // TODO: arreglar, muestra ls para /memes (carpeta de root, debería mostrar root))
    printf("\n\nCon input padre de carpeta de carpeta de root\n");
    cr_ls("dir/subdir/..");  // TODO: no hay display, no muestra nada
    
    printf("\n\n\n\n");
    return 0;
}

