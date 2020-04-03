#Progject 2 makefile

comp:
	gcc -Wall -g prog2.c -o prog2

copy:
	cp prog2.c p2copy.c

run:
	./prog2

clean:
	clear

open:
	vim prog2.c
stop:
	
