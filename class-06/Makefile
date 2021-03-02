CC		:= gcc
CFLAGS	:= -w

BIN		:= bin
SRC		:= .
INCLUDE	:= .

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

run1: 
	./$(EXECUTABLE) 1000

run10:
	./$(EXECUTABLE) 10000

run100:
	./$(EXECUTABLE) 100000

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $@ $(LIBRARIES) -lm

val1: 
	valgrind ./$(EXECUTABLE) 1000

val10: 
	valgrind ./$(EXECUTABLE) 10000

val100: 
	valgrind ./$(EXECUTABLE) 100000

full: all
	- valgrind -v --leak-check=full ./$(EXECUTABLE) 