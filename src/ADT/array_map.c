#include <stdio.h>
#include <stdlib.h>

#include "array_map.h"

void MakeEmptyPeta(TabPeta *P){
    for(int i = 0; i <= IdxMaxPetak; i++){
        (*P).Peta[i] = '-';
    }
}

void DisplayPetaPemain(TabPeta P, int PosPemain, int JumPetak){
    for(int i = 1; i <= JumPetak; i++){
        if (i == PosPemain){
            printf("%c", '*');
        } else {
            printf("%c", P.Peta[i]);
        }
    }
    printf(" %d", PosPemain);
}

/* KOMEN: NoPetak itu nomor petak apa idx array di C? Soalnya idx array
di C mulainya dari 0 ga sih, sehingga NoPetak harus di - 1 (?) (Di bawah 
ini dah ku - 1, tapi balikkin lagi aja kalo ternyata ku salah :kekw: */

boolean IsPetakKosong (TabPeta P, int NoPetak){
    return (P.Peta[NoPetak - 1] == '.');
}

boolean IsPetakTerlarang (TabPeta P, int NoPetak){
    return (P.Peta[NoPetak - 1] == '#');
}

int GetPetak(TabPeta P, int NoPetak) {
    /* Mengembalikan isi petak di nomor ke-sekian*/
    // ALGORITMA
    return (int) P.Peta[NoPetak - 1];
}