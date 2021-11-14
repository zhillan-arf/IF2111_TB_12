# Eksekusi dilakukan dari dir yang mengandung README

mlist : # Driver ADT list
	gcc -o mlist src/ADT/mlist.c src/ADT/list.c

mroll :
	gcc -o mroll src/unit_tests/mroll.c src/commands/roll.c

clean:
	rm mlist mroll