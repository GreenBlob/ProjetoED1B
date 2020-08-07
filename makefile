siguel:  main.o argsort.o makesvg.o 
	gcc main.c argsort.c makesvg.c  -o siguel

main.o: main.c
	gcc -c main.c -std=c99

argsort.o: argsort.c
	gcc -c argsort.c-std=c99

makesvg.o: makesvg.c
	gcc -c makesvg.c-std=c99

clean: 
	rm *.o siguel