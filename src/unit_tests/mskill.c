/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND SKILL - UNIT TEST
    Versi: 2021-11-15 11:30
*/

#include <stdio.h>

int main () {
    // KAMUS
    char *namaSkill[] = {
        "Pintu Ga Ke Mana Mana",
        "Mesin Waktu",
        "Baling Baling Jambu",
        "Cermin Pengganda",
        "Senter Pembesar Hoki", 
        "Senter Pengecil Hoki", 
        "Mesin Penukar Posisi"
    };
    int i;
    // ALGORITMA
    for (i=0; i<7; ++i)
    {
        printf("%s", namaSkill[i]);
    }
    return 0;
}