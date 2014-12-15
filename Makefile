CC=gcc
CFLAGS=-c -Wall -Werror 
MYSQL=`mysql_config --cflags --libs`

all: mathera

mathera: main.o db.o utilities.o
	$(CC) $(MYSQL) main.o db.o utilities.o -o mathera

main.o: main.c
	$(CC) $(CFLAGS) $(MYSQL) main.c

db.o: db.c
	$(CC) $(CFLAGS) $(MYSQL) db.c

utilities.o: utilities.c
	$(CC) $(CFLAGS) utilities.c

clean:
	rm -rf *o mathera
