
TARGET = shuffle
CC = gcc
CFLAGS  = -Wall -O2 -std=gnu11 -Wall -pedantic

OBJ = main.o
LDFLAGS =

$TARGET: $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f main.o *.~ $(TARGET) *~
