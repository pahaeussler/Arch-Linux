#pragma once
#include <stdbool.h>

void cr_mount(char*diskname);
void cr_bitmap(unsigned block, bool hex);
int cr_exists(char*path);
void cr_ls(char*path);
int cr_mkdir(char*foldername);
void print_block(FILE * db);