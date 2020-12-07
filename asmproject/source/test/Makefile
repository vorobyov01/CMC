all: main clean
main: main.o asm.o
	gcc -m32 -o main main.o asm.o

main.o: main.c
	gcc -m32 -std=c99 -c main.c

asm.o: asm.asm
	nasm -felf32 asm.asm

clean:
	rm *.o
