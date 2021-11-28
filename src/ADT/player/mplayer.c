/*
    TUBES IF2111 K2 KELOMPOK 12
    ADT PLAYER - UNIT TEST
    Versi: 2021-11-27
*/

#include <stdio.h>
#include "player.h"
#include "../../misc/convert.h"
#include "../list/list.h"

int main () {
    // KAMUS
    player P;
    char name[] = "Azami";
    // ALGORITMA
    P.nama = name;
    P.buff.buff[0] = true;
    P.current_petak = 42;
    P.skill.First = Nil;
    printf("Nama player: %s\n", P.nama);
    printf("Current petak: %d", P.current_petak);
}