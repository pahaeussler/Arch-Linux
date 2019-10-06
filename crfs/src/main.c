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
    
    // char diskname = "simdiskformat.bin";
	cr_mount(argv[1]);
	// uint8_t val;
	// uint8_t name[27];
	// uint32_t pointer;
// 	// // // int block[128];
// 	char* path = "/memes/yoda.jpg";
// 	char mode = "r";
	// printf("%d\n", cr_exists("/memes/yodas.jpg"));
	// printf("%d\n", cr_exists_direction(path));
// 	crFILE* file_desc = cr_open(path, mode);


// 	int nbytes = 1;
// 	// void* buffer;
// 	char buffer[nbytes+1];
// 	for (int i = 0; i < 10; i++)
// 	{
// 		cr_read(file_desc, buffer, nbytes);
// 		// buffer[nbytes]=NULL;
// 		printf("%s\n", buffer);
// 		printf("pos: %d\n", file_desc->pos);
// 	}
  
  
// 	// printf("%u\n", cr_exists_direction("/memes"));
	// cr_mkdir("/teMeo");
	// printf("---------------------------------\n");
	// printf("%d\n", cr_exists(""));
	//printf("%d\n", (2050/1024));
// 	printf("---------------------------------\n");
// 	printf("%d\n", cr_exists("/memeos"));
// 	// cr_mkdir("buena/choro/comova");


// uint32_t a = reserve_unused_block();
// cr_bitmap(1, 0);
// printf("%u\n", a);
// free_used_block(a);

// printf("------------------------\n");
// cr_bitmap(1, 0);

// 	printf("dir: %d\n", file_desc->block);
// 	cr_close(file_desc);
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
	// cr_bitmap(131, 0);
	// printf("%d\n", 1025/1024);
	cr_exists("/memes/doya");
	cr_rm("memes/sudo1.jpg");
	printf("--------------\n");
	cr_exists("/memes/doya");
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

  //printf("TEST cr_mount:\n\n");
	//cr_mount(argv[1]);
	//printf("%s Montado en %s\n\n", argv[1], getName(DISKNAME));
	
	
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
	//printf("\n\nCon input carpeta de carpeta de root\n");
  //cr_ls("dir/subdir/.");  // TODO: no hay display, no muestra nada
  /*printf("\n\nCon input padre de root simple\n");
  cr_ls("..");        // DONE
  printf("\n\nCon input padre de root con slash\n");
  cr_ls("/..");       // DONE
  printf("\n\nCon input padre de root con punto y slash\n");
  cr_ls("./..");/*    // DONE*/
  //printf("\n\nCon input padre de carpeta de root\n");
  //cr_ls("memes/..");  // TODO: arreglar, muestra ls para /memes (carpeta de root, debería mostrar root))
  //printf("\n\nCon input padre de carpeta de carpeta de root\n");
  //cr_ls("dir/subdir/..");  // TODO: no hay display, no muestra nada
    
  //printf("\n\n\n\n");
  return 0;
}

