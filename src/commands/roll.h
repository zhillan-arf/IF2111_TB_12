/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND ROLL - HEADER
    Versi: 2021-11-15 11:30
*/

#include "../ADT/array_map.h"
#include "../ADT/array_buff.h"
#include "../ADT/player.h"

void roll (
        int *Roll,
        int MaxRoll,
        TabPeta peta,
        int JumlahPemain,
        player *p
    );
// I.S. Roll di console sembarang
// F.S. Roll berisi angka random sesuai buff2


void maju(player *p, int nexts);
    // I.S. Player P berada di tempatnya, nexts + tempat saat ini ada di peta dan tidak kosong
    // F.S. Player P pindah ke nexts. Jika is_teleport dan not immune dan ketemu teleporter, teleport.
    // Jika immune, kasih pilihan mau ga teleport ga

void mundur(player *p, int pasts);
    // I.S. Player P berada di tempatnya, nexts + tempat saat ini ada di peta dan tidak kosong
    // F.S. Player P pindah ke pasts. Jika is_teleport dan not immune dan ketemu teleporter, teleport.
    // Jika immune, kasih pilihan mau ga teleport ga. P diupdate.

void teleport(player *p, int new_petak);
    // I.S. Player P berada di tempatnya, new_petak adalah petak kosong di peta
    // F.S. Player P pindah ke tempat kosong tersebut. P diupdate.