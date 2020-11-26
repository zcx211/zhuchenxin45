all:list sort compute
list:listtest.c
	gcc -g listtest.c -o list
sort:sorttest.c
	gcc sorttest.c -o sort
compute:computetest.c
	gcc computetest.c -o compute
clean:
	rm list
	rm sort
	rm compute
