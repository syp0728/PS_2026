CC = gcc
main : main.c guest.o menu.o
	$(CC) -o $@ $^

guest.o : guest.c guest.h
	$(CC) -c guest.c

menu.o : menu.c menu.h
	$(CC) -c menu.c

clean : 
	rm *.o main