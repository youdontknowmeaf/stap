CC	= gcc
CLIBS	= -lpthread -lm
CFLAGS	= -Wall

SRC	= main.c
OUT	= -o stap

all:
	$(CC) $(SRC) $(OUT) $(CLIBS) $(CFLAGS)
