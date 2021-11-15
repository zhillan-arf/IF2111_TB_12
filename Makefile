# TUBES IF2111 K2 KELOMPOK 12
# MAKEFILE - Eksekusi dilakukan dari dir yang mengandung README

# CONSOLE

# ADT UNIT TESTS
mlist :
	gcc -o mlist src/ADT/mlist.c src/ADT/list.c

# OTHER UNIT TESTS
minspect :
	gcc -o minspect src/unit_tests/minspect.c src/commands/inspect.c

mroll :
	gcc -o mroll src/unit_tests/mroll.c src/commands/roll.c

# CLEANER
clean:
	rm mlist mroll