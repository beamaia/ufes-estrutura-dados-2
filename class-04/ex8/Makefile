CC		:= gcc
CFLAGS	:= -w

BIN		:= bin
SRC		:= .
INCLUDE	:= .

N	:= 10
# Use no terminal make run N=num caso queira mudar o valor

N3	:= 

EXECUTABLE	:= main
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)

VALGRIND	:= 

CINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
SOURCES		:= $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))
OBJECTS		:= $(SOURCES:.c=.o)

all: clean $(EXECUTABLE)

.PHONY: clean
clean:
	-$(RM) $(OBJECTS)

run: 
	./$(EXECUTABLE) $(N)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $@ $(LIBRARIES) -lm

val: all
	valgrind ./$(EXECUTABLE) $(N)

full: all
	- valgrind -v --leak-check=full ./$(EXECUTABLE) $(N)