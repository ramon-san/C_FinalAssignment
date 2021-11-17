#Este es el archivo de makefile para compilar, encadenar y obtener la aplicación encuestar.out
encuestar.out: encuestar.o funEncuestar.o
	gcc encuestar.o funEncuestar.o -o encuestar.out `pkg-config --libs gtk+-2.0`

#En estos comandos se compilan los módulos necesarios, este es encuestar.c
encuestar.o: encuestar.c
	gcc -c encuestar.c `pkg-config --cflags gtk+-2.0`

#En estos comandos se compilan los módulos necesarios, este es funEncuestar.c
funEncuestar.o: funEncuestar.c
	gcc -c funEncuestar.c `pkg-config --cflags gtk+-2.0`

#Este comando elimina los archivos .o
clean:
	rm *.o
	rm *.out
