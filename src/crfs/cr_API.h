#pragma once


typedef struct crfile crFILE;

struct crfile{
    
};


crFILE*cr_open(char*path, char mode);
int cr_read(crFILE*file_desc, void*buffer, int nbytes);
int cr_write(crFILE*file_desc, void*buffer, int nbytes);
int cr_close(crFILE*file_desc);
int cr_rm(char*path);
int cr_unload(char*orig, char*dest);
int cr_load(char*orig);