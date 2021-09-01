all: exe
	
exe: main.o list.o
	gcc main.o list.o -o exe

main.o: main.c
	gcc -c main.c

list.o: list.c
	gcc -c list.c

clean:
	rm *.o exe
