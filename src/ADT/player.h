/*
    TUBES IF2111 K2 KELOMPOK 12
    ADT PLAYER - HEADER
    Versi: 2021-11-16 20:30
*/

/* KOMEN: Ini untuk kegunaan SEMENTARA, biar ku ga sakit mata liat 
pesan merah2 error gara2 nyoba make ADT player sebelum dibikin :kekw:.
Kalo lu dah jadi, kalo perlu ni hapus aja, ganti yang lu vit -dialah_zhillanku */
/* EH TAPI *nama* macronya sendiri jangan ganti (isImunTele, dll), repot
kalo ku harus ganti2 lagi tar :kekw: */

#include "list.h"
#include "array_buff.h"

#ifndef player_H
#define player_H

#define MAX_NAMA 100
typedef struct play {
    char *Nama;
    int Current_petak;
    List Skill;
    array_buff Buff;
} player;

#define nama(p) (p).Nama
#define current_petak(p) (p).Current_petak
#define skill(p) (p).Skill
#define buff(p) (p).Buff

#endif
