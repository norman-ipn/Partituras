#include "libpart.h"

int escribir_encabezado_partitura(FILE *secundario){
	fprintf(secundario,"\\version \"2.12.3\" {\n");
	return 0;
}

int escribir_partitura( FILE *secundario, char note, char octave, char flat, char sharp, float start ){
	fprintf(secundario,"\t%c\n",note);
	return 0;
}

int escribir_partitura_silencio( FILE *secundario, char note, char octave, char flat, char sharp, float start ){
	fprintf(secundario,"\t%c%c\n",note,flat);
	return 0;
}

int escribir_partitura_octava( FILE *secundario, char note, char octave, char flat, char sharp, float start ){
	fprintf(secundario,"\t%c%c\n",note,octave);
	return 0;
}

int escribir_partitura_sostenida( FILE *secundario, char note, char octave, char flat, char sharp, float start ){
	fprintf(secundario,"\t%c%c%c\n",note,octave,sharp);
	return 0;
}

int escribir_fin_partitura(FILE *secundario){
	fprintf(secundario,"}");
	return 0;
}
int escribir_encabezado( FILE *fp )
{
	fprintf( fp, "<CSoundSynthesizer>\n\n" );
	fprintf( fp, "\t<CsOptions>\n" );
	fprintf( fp, "\t\t-odac\n" );
	fprintf( fp, "\t</CsOptions>\n" );
	fprintf( fp, "\t<CsInstruments>\n" );
	fprintf( fp, "\t\tsr = 44100\n" );
	fprintf( fp, "\t\tksmps = 32\n" );
	fprintf( fp, "\t\tnchnls = 2\n" );
	fprintf( fp, "\t\t0dbfs = 1\n\n" );
	fprintf( fp, "\t\tinstr 1\n" );
	fprintf( fp, "\t\t\tasig oscils .2, p4, 0\n" );
	fprintf( fp, "\t\t\t\touts asig, asig\n" );
	fprintf( fp, "\t\tendin\n\n" );
	fprintf( fp, "\t</CsInstruments>\n\n" );
	fprintf( fp, "\t<CsScore>\n\n" );
}

int escribir_fin( FILE *fp )
{
	fprintf( fp, "\t</CsScore>\n\n" );
	fprintf( fp, "</CsoundSynthesizer>\n" );
}

int escribir( FILE *fp, char note, char octave, char flat, char sharp, float start )
{
	float frequency = 0;
	
	float frequency_list[] =	{ 65.406, 69.296, 73.416, 77.782, 82.407, 87.307, 92.499, 97.999, 103.826, 110.0, 116.541, 123.471 };			
					  /*Do */ /*Do#*/ /*Re */ /*Re#*/ /*Mi */ /*Fa */ /*Fa#*/ /*Sol*/ /*Sol#*/ /*La*/ /*La# */ /*Si  */
					  /*Si#*/ /*Reb*/ 	  /*Mib*/ /*Fab*/ /*Mi#*/ /*Solb*/	  /*Lab */   	  /*Sib */ /*Dob */ 
	int octaven = 0;
	switch ( octave )
	{
		case 1:
			octaven = 1;
			break;
		case 2:
			octaven = 2;
			break;
		case 4:
			octaven = 4;
			break;
		case 8:
			octaven = 8;
			break;
		default:
			octaven = 7;		
	}
	
	switch( note )
	{
	
		case 'c':
			if( sharp == '\0' && flat == '\0' )
			{
				frequency = frequency_list[0];
			}
			else
			{
				if( sharp != '\0' )
				{
					frequency = frequency_list[1];
				}
				else
				{
					frequency = frequency_list[11];
				}
			}
			break;
		case 'd':
			if( sharp == '\0' && flat == '\0' )
			{
				frequency = frequency_list[2];
			}
			else
			{
				if( sharp != '\0' )
				{
					frequency = frequency_list[3];
				}
				else
				{
					frequency = frequency_list[1];
				}
			}
			break;
		case 'e':
			if( sharp == '\0' && flat == '\0' )
			{
				frequency = frequency_list[4];
			}
			else
			{
				if( sharp != '\0' )
				{
					frequency = frequency_list[5];
				}
				else
				{
					frequency = frequency_list[3];
				}
			}
			break;
		case 'f':
			if( sharp == '\0' && flat == '\0' )
			{
				frequency = frequency_list[5];
			}
			else
			{
				if( sharp != '\0' )
				{
					frequency = frequency_list[6];
				}
				else
				{
					frequency = frequency_list[4];
				}
			}
			break;
		case 'g':		
			if( sharp == '\0' && flat == '\0' )
			{
				frequency = frequency_list[7];
			}
			else
			{
				if( sharp != '\0' )
				{
					frequency = frequency_list[8];
				}
				else
				{
					frequency = frequency_list[6];
				}
			}
			break;
		case 'a':
			if( sharp == '\0' && flat == '\0' )
			{
				frequency = frequency_list[9];
			}
			else
			{
				if( sharp != '\0' )
				{
					frequency = frequency_list[10];
				}
				else
				{
					frequency = frequency_list[8];
				}
			}
			break;
		case 'b':
			if( sharp == '\0' && flat == '\0' )
			{
				frequency = frequency_list[11];
			}
			else
			{
				if( sharp != '\0' )
				{
					frequency = frequency_list[1];
				}
				else
				{
					frequency = frequency_list[10];
				}
			}
			break;
	}

	frequency = frequency * pow( 2, octaven - 1 );

	fprintf( fp, "\t\ti1\t%f\t1\t%f\n", start, frequency );
}
