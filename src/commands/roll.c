/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND ROLL - IMPLEMENTASI
    Versi: 2021-11-14 23:45
*/

#include "roll.h"
#include <stdlib.h>

void command_roll (int *Roll, int MaxRoll, boolean isSenterBesar, boolean isSenterKecil) {
    // I.S. Roll di console sembarang
    // F.S. Roll berisi angka random sesuai buff2
    // KAMUS LOKAL
    int MinRoll = 1;
    int rolled;
    // ALGORITMA
    if (isSenterBesar)
    {
        rolled = (rand() % (MaxRoll/2)) + 1 + (MaxRoll/2);
    }
    else if (isSenterKecil)
    {
        rolled = (rand() % (MaxRoll/2)) + 1;
    }
    else
    {
        rolled = (rand() % (MaxRoll)) + 1;
    }
    (*Roll) = rolled;

}