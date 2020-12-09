CC = g++
CFLAGS = -g -Wall

LIBS = -lncurses
INCLUDES = -I lib

SRC_DIR = src
DEP_DIR = lib

all:
	$(CC) $(CFLAGS) -o ncsnake $(SRC_DIR)/* $(DEP_DIR)/* $(LIBS) $(INCLUDES)
