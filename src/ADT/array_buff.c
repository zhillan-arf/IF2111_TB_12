#include "../boolean.h"
#include "array_buff.h"
#include <string.h>
#include <stdio.h>

*namaBuff[] = {
    "Imunitas Teleport", 
    "Cermin Pengganda", 
    "Senter Pembesar Hoki", 
    "Senter Pengecil Hoki"
};

void ResetTabBuff(array_buff * B) {
    for (int i = 0; i < MaxBuff; i++) BUFF((*B), i) = false;
}

void displayBuff(array_buff B, char *namaBuff){
    printf("Daftar Buff yang dimiliki pemain:\n");
    int count =0;
    for (int i = 0; i < 4; i++) if (BUFF(B, i)) {
        count++;
        printf("%d. %s\n", count, namaBuff[i]);
    }
}