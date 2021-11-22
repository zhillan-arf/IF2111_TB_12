/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND ROLL - HEADER
    Versi: 2021-11-17 21:30
*/

#include "../ADT/array_tp.h"
#include "../ADT/array_map.h"
#include "../ADT/array_buff.h"
#include "../ADT/player.h"

#ifndef ROLL_H
#define ROLL_H

void roll (
        int *Roll,
        int MaxRoll,
        TabPeta peta,
        TabTP arrtp,
        int JumlahPemain,
        player *p
    );
// I.S. Roll di console sembarang
// F.S. Roll berisi angka random sesuai buff2

void maju(player *p, int nexts, TabPeta peta, TabTP arrtp);
    // I.S. Player P berada di tempatnya, nexts + tempat saat ini ada di peta dan tidak kosong
    // F.S. Player P pindah ke nexts. Jika is_teleport dan not immune dan ketemu teleporter, teleport.
    // Jika immune, kasih pilihan mau ga teleport ga

void mundur(player *p, int pasts, TabPeta peta, TabTP arrtp);
    // I.S. Player P berada di tempatnya, nexts + tempat saat ini ada di peta dan tidak kosong
    // F.S. Player P pindah ke pasts. Jika is_teleport dan not immune dan ketemu teleporter, teleport.
    // Jika immune, kasih pilihan mau ga teleport ga. P diupdate.

void teleport(player *p, int new_petak);
    // I.S. Player P berada di tempatnya, new_petak adalah petak kosong di peta
    // F.S. Player P pindah ke tempat kosong tersebut. P diupdate.

#endif