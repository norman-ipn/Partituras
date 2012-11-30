%{
   #include "Gramatica.h"
%}

NOTE	do|re|mi|fa|sol|la|si|do
LENGTH	[0-9]+
SILENT	r
NOTEMOD	b|s
BLANKS	[\t]+


%%

	
{NOTEMOD}+		{
			   yylval.sval = malloc(strlen(yytext));
		  	   strncpy(yylval.sval, yytext, strlen(yytext));
			   return (NOTEMOD);
			}

{NOTE}			{
			   yylval.sval = malloc(strlen(yytext));
		  	   strncpy(yylval.sval, yytext, strlen(yytext));
			   return (NOTE);
			}

{SILENT}+		{
			   yylval.sval = malloc(strlen(yytext));
		  	   strncpy(yylval.sval, yytext, strlen(yytext));
			   return (SILENT);
			}

{LENGTH}+		{
			   yylval.ival = atoi(yytext);
			   return (NUM);
			}

{BLANKS}		{}

\n			{return 0;}
