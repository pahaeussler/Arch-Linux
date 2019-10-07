# Arch Linux Project

 proyectos del curso Sistemas Operativos y Redes.

## Miembros

| Nombre | N° de Alumno | Mail |
| :----- | :----------: | :--: |
| Pablo Haeussler* | 14620138 | pahaeussler@uc.cl |
| Cristobal Poblete | 15623688 | cmpoblete@uc.cl |
| Alfonso Aguirre |15621863 | aaguirrebena@uc.cl |
| Henry Blair González | 13634372 | hblair1@uc.cl |

*Este proyecto se subirá en la carpeta de este usuario del servidor

## Proyectos

### **Sistemas Operativos:** *Cruz FileSystem*

Lectura y Escritura de archivos en disco virtual.

| [Foro](https://github.com/IIC2333/foro-2019-2/issues?q=is%3Aissue+is%3Aopen+label%3AP1) | [Enunciado](https://github.com/pahaeussler/Arch-Linux/blob/alternative-main/crfs/dcs/Enunciado.pdf) | [Documentacion(En OverLeaf)](https://www.overleaf.com/1931382199kdckjfyqtqrt) |
| :--: | :--: | :--: |
|| [Ayudantía](https://github.com/pahaeussler/Arch-Linux/blob/alternative-main/crfs/dcs/AyudantiaP1.pdf) ||

#### Desiciones de Diseño

#### Supuestos Adicionales

#### Información Relevante

Para usar el script de rápida compilación y ejecución del main escribir en consola `chmod +xwr tst`, finalmente para correrlo: `./tst [num_op]`

| num_op | comando |
| :--: | :-- |
| `0` | ./crfs dsk/simdiskfilled.bin |
| `1` | valgrind --leak-check=full --show-leak-kinds=all ./crfs dsk/simdiskfilled.bin |
| `2` | time ./crfs dsk/simdiskfilled.bin |
| `3` | valgrind --track-origins=yes ./crfs dsk/simdiskformat.bin |
| `4` | valgrind ./crfs dsk/simdiskformat.bin |
| `5` | make clean |



#### [Documentación Oficial](https://github.com/pahaeussler/Arch-Linux/blob/alternative-main/crfs/dcs/ArchLinux_crfs_man.pdf)
****
