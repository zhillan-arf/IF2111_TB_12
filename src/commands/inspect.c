/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND INSPECT - IMPLEMENTASI
    Versi: 2021-11-15 11:30
*/

#include "inspect.h"
#include <stdio.h>
#include "../boolean.h"

void inspect (TabPeta Peta, TabTP arrtp, int JumPetak) {
    // I.S. Peta dari file config terbaca, turn sembarang
    // F.S. Teroutput hal2 yang diinginkan player, jika ada
    // KAMUS LOKAL
    int NoPetak;
    boolean is_valid = false;
    // ALGORITMA
    while (!is_valid)
    {
        printf("Masukkan petak (range dari 1 hingga %d):\n>> ", JumPetak);
        scanf("%d", &NoPetak);
        if (IsPetakKosong(Peta, NoPetak))
        {
            is_valid = true;
            printf("Petak %d adalah petak kosong. Aman!\n", NoPetak);
        }
        else if (IsPetakTerlarang(Peta, NoPetak))
        {
            is_valid = true;
            printf("Petak %d adalah petak terlarang. ¡No Pasaran!\n", NoPetak);
        }
        else if (1 <= NoPetak && NoPetak <= JumPetak)
        {
            is_valid = true;
            printf("Awas! Petak %d memiliki teleporter ke petak %d!\n", NoPetak, arrtp.TTP[NoPetak]);
        }
        else
        {
            printf("Tetot! Input invalid atau melebihi range (1 hingga %d).\n", JumPetak);
        }
    }
}