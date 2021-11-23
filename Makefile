FLAGS = -Wall -g

main.o: main.c my_mat.h
	gcc $(FLAGS) -c main.c

mat.o: my_mat.c my_mat.h
	gcc $(FLAGS) -c my_mat.c

connections: main.o my_mat.o
	gcc $(FLAGS) -o connections main.o my_mat.o

all: connections

clean:
	rm -f *.o *.a *.so connections