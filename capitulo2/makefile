ARGS = a b c d

arglist: arglist.o
	gcc -o arglist arglist.o

arglist.o: arglist.c
	gcc -c arglist.c

exce:
	./arglist $(ARGS)

clean:
	rm -f *.o arglist

getopt_long: getopt_long.o
	gcc -o getopt_long getopt_long.o

getopt_long.o: getopt_long.c
	gcc -c getopt_long.c



