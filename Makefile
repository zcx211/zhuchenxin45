all:shiyan1 dlist
shiyan1:shiyan1test.c
	gcc -g shiyan1test.c -o shiyan1
dlist:dlisttest.c
	gcc dlisttest.c -o dlist
clean:
	rm shiyan1
	rm dlist
