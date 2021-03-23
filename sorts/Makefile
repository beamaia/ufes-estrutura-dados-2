CC		:= gcc
CFLAGS	:= -w

EXE := main

.PHONY: clean

select_sort: 
	$(CC) $(CFLAGS) main.c insert_sort.c -o $(EXE)

insert_sort:
	$(CC) $(CFLAGS) main.c insert_sort.c -o $(EXE)

shaker_sort:
	$(CC) $(CFLAGS) main.c shaker_sort.c -o $(EXE)

bubble_sort:
	$(CC) $(CFLAGS) main.c bubble_sort.c -o $(EXE)

mergev1:
	$(CC) $(CFLAGS) main.c mergev1.c -o $(EXE)

mergev2:
	$(CC) $(CFLAGS) main.c mergev2.c -o $(EXE)

mergev3:
	$(CC) $(CFLAGS) main.c mergev3.c -o $(EXE)

mergev4:
	$(CC) $(CFLAGS) main.c mergev4.c -o $(EXE)

mergev5:
	$(CC) $(CFLAGS) main.c mergev5.c -o $(EXE)

mergev6:
	$(CC) $(CFLAGS) main.c mergev6.c -o $(EXE)

mergev7:
	$(CC) $(CFLAGS) main.c mergev7.c -o $(EXE)

clean:
	-$(RM) $(OBJECTS)

run1_nearly: 
	./$(EXE) 1000 < in/nearly_sorted/1Knearly_sorted.txt

run1_reverse: 
	./$(EXE) 1000 < in/reverse_sorted/1Kreverse_sorted.txt

run1_sorted: 
	./$(EXE) 1000 < in/sorted/1Ksorted.txt

run1_rand: 
	./$(EXE) 1000 < in/unif_rand/1Kunif_rand.txt

run10_nearly: 
	./$(EXE) 10000 < in/nearly_sorted/10Knearly_sorted.txt

run10_reverse: 
	./$(EXE) 10000 < in/reverse_sorted/10Kreverse_sorted.txt

run10_sorted: 
	./$(EXE) 10000 < in/sorted/10Ksorted.txt

run10_rand: 
	./$(EXE) 10000 < in/unif_rand/10Kunif_rand.txt

run100_nearly: 
	./$(EXE) 100000 < in/nearly_sorted/100Knearly_sorted.txt

run100_reverse: 
	./$(EXE) 100000 < in/reverse_sorted/100Kreverse_sorted.txt

run100_sorted: 
	./$(EXE) 100000 < in/sorted/100Ksorted.txt

run100_rand: 
	./$(EXE) 100000 < in/unif_rand/100Kunif_rand.txt

run1000_nearly: 
	./$(EXE) 1000000 < in/nearly_sorted/1Mnearly_sorted.txt

run1000_reverse: 
	./$(EXE) 1000000 < in/reverse_sorted/1Mreverse_sorted.txt

run1000_sorted: 
	./$(EXE) 1000000 < in/sorted/1Msorted.txt

run1000_rand: 
	./$(EXE) 1000000 < in/unif_rand/1Munif_rand.txt

diff100:
	diff --suppress-common-lines saida.txt ./in/sorted/100Ksorted.txt