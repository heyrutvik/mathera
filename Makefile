CC=gcc
CFLAGS=-c -Wall -Werror

all: mathera

mathera: main.o db.o
	$(CC) main.o db.o -o mathera

main.o: main.c
	$(CC) $(CFLAGS) main.c

db.o: db.c
	$(CC) $(CFLAGS) db.c

clean:
	rm -rf *o mathera
