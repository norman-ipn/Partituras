#ifndef __LIBPART_H__
#define __LIBPART_H__
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int escribir_encabezado( FILE *fp );
int escrbir_fin( FILE *fp );
int escribir( FILE *fp, char nota, char octava, char silencio, char sostenido, float start );
int escribir_encabezado_partitura( FILE *secundario );
int escrbir_fin_partitura( FILE *secundario );
int escribir_partitura( FILE *secundario, char nota, char octava, char silencio, char sostenido, float start );
int escribir_partitura_sostenida( FILE *secundario, char nota, char octava, char silencio, char sostenido, float start );
int escribir_partitura_octava( FILE *secundario, char nota, char octava, char silencio, char sostenido, float start );
int escribir_partitura_silencio( FILE *secundario, char nota, char octava, char silencio, char sostenido, float start );
#endif
