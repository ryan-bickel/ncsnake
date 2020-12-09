CC = gcc
CFLAGS = -g -Wall

LIBS = -lncurses

all: ncsnake

ncsnake: ncsnake.o
	$(CC) $(CFLAGS) -o ncsnake ncsnake.o $(LIBS)

ncsnake.o: ncsnake.cpp
	$(CC) $(CFLAGS) -c ncsnake.cpp

clean:
	$(RM) ncsnake *.o