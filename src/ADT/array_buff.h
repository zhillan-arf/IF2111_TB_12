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

#include "../boolean.h"

#ifndef array_buff_H
#define array_buff_H

typedef struct arr_buff {
    boolean buff [4];
} array_buff;

#define isImunTele(b) (b).buff[0]
#define isSenterBesar(b) (b).buff[1]
#define isSenterKecil(b) (b).buff[2]
#define isCerminGanda(b) (b).buff[3]

#endif