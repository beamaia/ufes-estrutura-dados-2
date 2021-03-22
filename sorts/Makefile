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

.PHONY: clean

full: select_sort insert_sort 

select_sort: 
	gcc main.c insert_sort.c -o select_sort

insert_sort:
	gcc main.c insert_sort.c -o insert_sort

shaker_sort:
	gcc main.c shaker_sort.c -o shaker_sort

bubble_sort:
	gcc main.c bubble_sort.c -o bubble_sort

mergev1:
	gcc main.c mergev1.c mergev1

clean:
	-$(RM) $(OBJECTS)

run1_nearly: 
	./$(EXECUTABLE) 1000 < in/nearly_sorted/1Knearly_sorted.txt

run1_reverse: 
	./$(EXECUTABLE) 1000 < in/reverse_sorted/1Kreverse_sorted.txt

run1_sorted: 
	./$(EXECUTABLE) 1000 < in/sorted/1Ksorted.txt

run1_rand: 
	./$(EXECUTABLE) 1000 < in/unif_rand/1Kunif_rand.txt

run10_nearly: 
	./$(EXECUTABLE) 10000 < in/nearly_sorted/10Knearly_sorted.txt

run10_reverse: 
	./$(EXECUTABLE) 10000 < in/reverse_sorted/10Kreverse_sorted.txt

run10_sorted: 
	./$(EXECUTABLE) 10000 < in/sorted/10Ksorted.txt

run10_rand: 
	./$(EXECUTABLE) 10000 < in/unif_rand/10Kunif_rand.txt

run100_nearly: 
	./$(EXECUTABLE) 100000 < in/nearly_sorted/100Knearly_sorted.txt

run100_reverse: 
	./$(EXECUTABLE) 100000 < in/reverse_sorted/100Kreverse_sorted.txt

run100_sorted: 
	./$(EXECUTABLE) 100000 < in/sorted/100Ksorted.txt

run100_rand: 
	./$(EXECUTABLE) 100000 < in/unif_rand/100Kunif_rand.txt


run1000_nearly: 
	./$(EXECUTABLE) 1000000 < in/nearly_sorted/1Mnearly_sorted.txt

run1000_reverse: 
	./$(EXECUTABLE) 100000 < in/reverse_sorted/1Mreverse_sorted.txt

run1000_sorted: 
	./$(EXECUTABLE) 100000 < in/sorted/1Msorted.txt

run1000_rand: 
	./$(EXECUTABLE) 100000 < in/unif_rand/1Munif_rand.txt