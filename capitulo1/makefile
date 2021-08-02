# Podemos ver que para generar los .o necesitamos de main.o y reciprocal.o
#CFLAGS ES UNA VARIABLE DE LAS BANDERAS ASOCIADAS 
reciprocal: main.o reciprocal.o
	g++ $(CFLAGS) -o reciprocal main.o reciprocal.o

# Para generar el main.o necesitamos del main.c y reciprocal.hpp
main.o: main.c reciprocal.hpp
	gcc $(CFLAGS) -c main.c

# Para generar el reciprocal.o necesitamos del reciprocal.c y reciprocal.hpp
reciprocal.o: reciprocal.cpp reciprocal.hpp
	g++ $(CFLAGS) -c reciprocal.cpp

#Finalmente limpiamos todo los .o y ejecutables
clean:
	rm -f *.o reciprocal