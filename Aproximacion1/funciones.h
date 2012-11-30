#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__
#include <stdio.h>
#include <string.h>

int escribir_encabezado(FILE *fp);
int escribir_piePagina(FILE *fp);
int escribir(FILE *fp, char *cadena);
int escribirTiempo(FILE *fp, char *cadena);

#endif
