all: main.o list.o
	gcc main.o list.o -o all
main.o: main.c
	gcc -c main.c -o main.o
liste.o: list.c
	gcc -c list.c -o list.o
clean:
	rm -rf *.o
