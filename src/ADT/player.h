/*
    TUBES IF2111 K2 KELOMPOK 12
    ADT PLAYER - HEADER
    Versi: 2021-11-16 20:30
*/

#include "list.h"
#include "array_buff.h"

#ifndef player_H
#define player_H

typedef struct play {
    char *nama;
    int current_petak;
    List skill;
    array_buff buff;
} player;

#define nama(p) (p).nama
#define current_petak(p) (p).current_petak
#define skill(p) (p).skill
#define buff(p) (p).buff

#endif
