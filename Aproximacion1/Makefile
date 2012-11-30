default:
	gcc -c funciones.c	
	bison -d Gramatica.y		#Compila el archivo bison
	mv Gramatica.tab.h Gramatica.h  #Renombrar el archivo encabezado a Gramatica.h
	mv Gramatica.tab.c Parser.y.c	#Renombrar el archivo código a Parser.y.c
	flex Expresiones.l		#Compilar archivo Flex
	mv lex.yy.c Parser.lex.c	#Renombrar a Parser.lex.c
	gcc -g -c Parser.lex.c -o Parser.lex.o
	gcc -g -c Parser.y.c -o Parser.y.o
	gcc -g -o Partitura Parser.lex.o Parser.y.o funciones.o -lfl

clean:
	rm Gramatica.h
	rm Parser.lex.c
	rm Parser.y.c
	rm Parser.lex.o
	rm funciones.o
	rm Parser.y.o
	rm Partitura
	rm Partitura.l

