%{
	#include "libpart.h"

	extern FILE *yyin;
	void yyerror( char *s );
	extern int yylex( void );
	extern char *yytext;
	FILE *primario = NULL;
	FILE *secundario = NULL;
	float contador_freq = 0;
		
%}

%union
{
	char 	symbol;
	int 	digit;
}

%start START

%token <symbol>	NOTA
%token <symbol>	OCTAVA
%token <symbol>	SILENCIO
%token <symbol>	SOSTENIDO

%%

START: 	value START 
	| value

value: 	NOTA			{
					printf( "Nota: %c\n", $1 );
					escribir( primario, $1, '\0', '\0', '\0', contador_freq );
					escribir_partitura( secundario, $1, '\0', '\0', '\0', contador_freq );
					contador_freq = contador_freq + 1.01;
				}

	| NOTA OCTAVA		{
					printf( "Nota: %c, Octava: %c\n", $1, $2 );
					escribir( primario, $1, $2, '\0', '\0', contador_freq );
					escribir_partitura_octava( secundario, $1, $2, '\0', '\0', contador_freq );
					contador_freq = contador_freq + 1.01;
				}

	| NOTA SILENCIO		{
					printf( "Nota: %c, Silencio: %c\n", $1, $2);
					escribir( primario, $1, '\0', $2, '\0', contador_freq );
					escribir_partitura_silencio( secundario, $1, '\0', $2, '\0', contador_freq );
					contador_freq = contador_freq + 1.01;
				}
	
	| NOTA OCTAVA SOSTENIDO	{
					printf( "Nota: %c, Octava:  %c, Sostenido: %c\n", $1, $2, $3 );
					escribir( primario, $1, $2, '\0', $3, contador_freq );
					escribir_partitura_sostenida( secundario, $1, $2, '\0', $3, contador_freq );
					contador_freq = contador_freq + 1.01;
				}

%%

void yyerror( char *s )
{
	printf( "Error sintactico %s \n", s );
}

int main( int argc, char **argv )
{
	primario = fopen( "musica.csd", "w" );
	secundario = fopen( "partitura.ly", "w" );
	escribir_encabezado_partitura( secundario );
	escribir_encabezado( primario );
	if( argc > 1 )
	{
		yyin = fopen( argv[1], "rt" );
	}else{
		yyin = stdin;
		yyin = fopen( "file.txt", "rt" );
	}
	yyparse();
	escribir_fin( primario );
	escribir_fin_partitura( secundario );
	return 0;
}
