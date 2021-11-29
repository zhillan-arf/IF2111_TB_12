# TUBES IF2111 K2 KELOMPOK 12
# MAKEFILE - Eksekusi dilakukan dari dir yang mengandung README

# CONSOLE
console :
	gcc -o console src/console.c src/ADT/array_buff/array_buff.c src/ADT/array_map/array_map.c src/ADT/array_tp/array_tp.c src/ADT/list/list.c src/ADT/mesin_kar/mesin_kar.c src/ADT/mesin_kata/mesin_kata.c src/ADT/stack_state/stack_state.c src/ADT/state/state.c src/commands/skill/gacha_skill.c src/commands/inspect/inspect.c src/commands/roll/roll.c src/commands/skill/skills.c src/misc/start_display.c src/misc/convert.c

# ADT UNIT TESTS
marray_buff :
	gcc -o marray_buff src/ADT/array_buff/marray_buff.c src/ADT/array_buff/array_buff.c

marray_map :
	gcc -o marray_map src/ADT/array_map/marray_map.c src/ADT/array_map/array_map.c

marray_tp :
	gcc -o marray_tp src/ADT/array_tp/marray_tp.c src/ADT/array_tp/array_tp.c

mlist :
	gcc -o mlist src/ADT/list/mlist.c src/ADT/list/list.c

#mmesin_kata
#	Untuk menjalankan driver mesin_kata, hanya perlu melakukan run code yang ada di path src/driver_ADT/mmesin_kata.c

mplayer :
	gcc -o mplayer src/ADT/player/mplayer.c

mstack_state :
	gcc -o mstack_state src/ADT/stack_state/mstack_state.c src/ADT/stack_state/stack_state.c

mstate :
	gcc -o mstate src/ADT/state/mstate.c src/ADT/state/state.c