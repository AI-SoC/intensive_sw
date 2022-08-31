help:
	@echo "make help"
	@echo "make all"

# pre-processing only
pre: hello.c
	cpp hello.c > hello.i

# compilation only
comp: hello.i
	gcc -S hello.i

# assembling only
asm: hello.s
	as -o hello.o hello.s

hello.o: hello.c
	gcc -c hello.c

foo.o: foo.c 
	gcc -c foo.c 

#linking 
all: hello.o foo.o
	gcc -o hello hello.o foo.o 
	./hello

clean: 
	rm -rf *.o

cleanup: clean
	rm -rf hello

	

