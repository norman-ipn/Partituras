run: musica.csd partitura.ly 
	csound musica.csd
	lilypond partitura.ly
	evince partitura.pdf

musica.csd: a.out acorde.txt
	./a.out "acorde.txt"

a.out: lex.yy.c gramatica_acorde.tab.c libpart.c
	    gcc lex.yy.c gramatica_acorde.tab.c libpart.c -lfl -lm

lex.yy.c: analizador_acorde.l
	  flex analizador_acorde.l

gramatica_acorde.tab.c: gramatica_acorde.y
	      bison -d gramatica_acorde.y

editar: acorde.txt
	vi acorde.txt

mostrar_fuente: partitura.ly
	vi partitura.ly

partitura: partitura.pdf
	evince partitura.pdf
clean:
	rm lex.yy.c
	rm gramatica_acorde.tab.c
	rm gramatica_acorde.tab.h
	rm a.out
	rm musica.csd
	rm partitura.ly
	rm partitura.pdf
