/*
    TUBES IF2111 K2 KELOMPOK 12
    ADT ARRAY_BUFF - HEADER
    Versi: 2021-11-16 20:30
*/

/* KOMEN: Ini untuk kegunaan SEMENTARA, biar ku ga sakit mata liat 
pesan merah2 error gara2 nyoba make ADT array_buff sebelum dibikin :kekw:.
Kalo lu dah jadi, kalo perlu ni hapus aja, ganti yang lu nel -dialah_zhillanku */
/* EH TAPI *nama* macronya sendiri jangan ganti (isImunTele, dll), repot
kalo ku harus ganti2 lagi tar :kekw: */

#include "../../boolean.h"

#ifndef array_buff_H
#define array_buff_H
#define MaxBuff 4

typedef struct arr_buff {
    boolean buff[MaxBuff];
} array_buff;

extern char *namaBuff[];

void ResetTabBuff(array_buff *B);

void displayBuff(array_buff B, char *namaBuff[], char *nama);

#define BUFF(arrb, i) (arrb).buff[i]
#define isImunTele(arrb) (arrb).buff[0]
#define isCerminGanda(arrb) (arrb).buff[1]
#define isSenterBesar(arrb) (arrb).buff[2]
#define isSenterKecil(arrb) (arrb).buff[3]

#endif
