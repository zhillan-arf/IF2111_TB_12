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

boolean IsPetakKosong (TabPeta P, int NoPetak){
    return (P.Peta[NoPetak] == '.');
}

boolean IsPetakTerlarang (TabPeta P, int NoPetak){
    return (P.Peta[NoPetak] == '#');
}

Petak GetPetak(TabPeta P, int NoPetak) {
    return P.Peta[NoPetak];
}