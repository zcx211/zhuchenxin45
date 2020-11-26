all:list sort compute
list:list.c listtest.c
	gcc -g list.c listtest.c -o list
sort:sort.c sorttest.c
	gcc sort.c sorttest.c -o sort
compute:compute.c computetest.c
	gcc compute.c computetest.c -o compute
clean:
	rm list
	rm sort
	rm compute
