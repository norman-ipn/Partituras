%{
	#include "libpart.h"
	#include "gramatica_acorde.tab.h"

%}

NOTA		[c|d|e|f|g|a|b]
OCTAVA		[1|2|4|8]
SOSTENIDO	["."]
SILENCIO	["\'"]

%%

{OCTAVA}	{
			yylval.symbol = *yytext;
			return (OCTAVA);
		}

{NOTA}		{
			yylval.symbol = *yytext;
			return (NOTA);
		}

{SILENCIO}	{
			yylval.symbol = *yytext;
			return (SILENCIO);
		}
	
{SOSTENIDO}	{
			yylval.symbol = *yytext;
			return (SOSTENIDO);
		}

%%
