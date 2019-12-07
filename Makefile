
CC=gcc
CFLAGS= -Wall -w -g

INCLUDE:= -I/ 

LINK:= -lm

SOURCES:= $(wildcard *.c)

EXE=out

all: $(EXE)

$(EXE):
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCES) -o $(EXE) $(LINK)

clean:
	rm $(EXE)

c:
	rm $(EXE)

run:
	./$(EXE) &

