#include <stdio.h>
#include <stdlib.h>

#include "array_map.h"

void MakeEmptyPeta(TabPeta *P){
    for(int i = 0; i <= IdxMaxPetak; i++){
        (*P).Peta[i] = UNDEF_PETAK;
    }
}

void DisplayPetaPemain(TabPeta P, int PosPemain, int JumPetak, char *nama) {
    printf(">> %s: \n  ", nama);
    for(int i = 1; i <= JumPetak; i++) {
        if (i == PosPemain){
            printf("%c", '*');
        } else {
            printf("%c", P.Peta[i]);
        }
    }
    printf(" (petak %d)\n", PosPemain);
}

boolean IsPetakKosong (TabPeta P, int NoPetak){
    return (P.Peta[NoPetak] == '.');
}

boolean IsPetakTerlarang (TabPeta P, int NoPetak){
    return (P.Peta[NoPetak] == '#');
}