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

all:
	gcc -o hello hello.c
	./hello

clean: 
	rm -rf *.o

cleanup: clean
	rm -rf hello

	

