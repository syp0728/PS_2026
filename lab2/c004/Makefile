CC=gcc
CFLAGS=-Wall

TARGET=main
OBJ=main.o class.o

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: main.c class.h
	$(CC) $(CFLAGS) -c main.c

class.o: class.c class.h
	$(CC) $(CFLAGS) -c class.c

clean:
	rm -f *.o $(TARGET)