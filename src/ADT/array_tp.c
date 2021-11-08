#include <stdlib.h>
#include <stdio.h>

#include "array_tp.h"

void MakeEmptyArrTP(TabTP *TabelTP){
    for(int i = 1; i <= IdxMaxTP; i++){
        (*TabelTP).TTP[i] = 0;
    }
}

void InsertTP(TabTP *TabelTP, int X, int Y){
    (*TabelTP).TTP[Y] = X;
}

boolean IsPetakTP(int NoPetak, TabTP TabelTP){
    return (TabelTP.TTP[NoPetak] != 0);
}
