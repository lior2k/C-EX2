FLAGS = -Wall -g

main.o: main.c my_mat.h
	gcc $(FLAGS) -c main.c

my_mat.o: my_mat.c my_mat.h
	gcc $(FLAGS) -c my_mat.c

libmy_mat.a: my_mat.o
	ar -rcs libmy_mat.a my_mat.o

connections: main.o my_mat.o libmy_mat.a
	gcc $(FLAGS) -o connections main.o my_mat.o libmy_mat.a

all: connections libmy_mat.a

clean:
	rm -f *.o *.a *.so connections