mlist : # Driver ADT list
	gcc -o mlist src/ADT/mlist.c src/ADT/list.c

clean:
	rm mlist