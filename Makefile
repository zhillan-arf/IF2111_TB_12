# TUBES IF2111 K2 KELOMPOK 12
# MAKEFILE - Eksekusi dilakukan dari dir yang mengandung README

# CONSOLE
console :
	gcc -o console src/console.c src/ADT/array_buff.c src/ADT/array_map.c src/ADT/array_tp.c src/ADT/list.c src/ADT/mesin_kar.c src/ADT/mesin_kata.c src/ADT/stack_state.c src/ADT/state.c src/commands/gacha_skill.c src/commands/inspect.c src/commands/roll.c src/commands/skills.c src/commands/start_display.c src/misc/convert.c

# ADT UNIT TESTS
marray_buff :
	gcc -o marray_buff src/driver_ADT/marray_buff.c src/ADT/array_buff.c

marray_map :
	gcc -o marray_map src/driver_ADT/marray_map.c src/ADT/array_map.c

marray_tp :
	gcc -o marray_tp src/driver_ADT/marray_tp.c src/ADT/array_tp.c

mlist :
	gcc -o mlist src/driver_ADT/mlist.c src/ADT/list.c

mmesin_kata :
	gcc -o mmesin_kata src/driver_ADT/mmesin_kata.c src/ADT/mesin_kata.c

mplayer :
	gcc -o mplayer src/driver_ADT/mplayer.c

mstack_state :
	gcc -o mstack_state src/driver_ADT/mstack_state.c src/ADT/stack_state.c

mstate :
	gcc -o mstate src/driver_ADT/mstate.c src/ADT/state.c

# CLEANER
clean:
	rm mlist minspect mroll