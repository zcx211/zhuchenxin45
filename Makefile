all:list sort compute queue
list:list.c listtest.c
	gcc -g list.c listtest.c -o list
sort:sort.c sorttest.c
	gcc sort.c sorttest.c -o sort
compute:compute.c computetest.c
	gcc compute.c computetest.c -o compute
queue:queue.c queuetest.c
	gcc queue.c queuetest.c -o queue
clean:
	rm list
	rm sort
	rm compute
	rm queue
