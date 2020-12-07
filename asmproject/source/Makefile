all: main clean
main: main.o func.o
	gcc -m32 -o main main.o func.o -lm

main.o: main.c
	gcc -m32 -std=c99 -c main.c

func.o: func.asm
	nasm -felf32 func.asm

clean:
	rm *.o