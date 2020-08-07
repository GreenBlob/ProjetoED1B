siguel:  main.o argsort.o makesvg.o qryF.o
	gcc main.c argsort.c makesvg.c qryF.c -o siguel

qryF: qryF.c
	gcc -c qryF.c

main.o: main.c
	gcc -c main.c

argsort.o: argsort.c
	gcc -c argsort.c

makesvg.o: makesvg.c
	gcc -c makesvg.c

clean: 
	rm *.o siguel