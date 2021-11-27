/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND INSPECT - IMPLEMENTASI
    Versi: 2021-11-15 11:30
*/

#include "inspect.h"
#include <stdio.h>
#include "../boolean.h"
#include "../misc/convert.h"

void inspect (TabPeta Peta, TabTP arrtp, int JumPetak) {
    // I.S. Peta dari file config terbaca, turn sembarang
    // F.S. Teroutput hal2 yang diinginkan player, jika ada
    // KAMUS LOKAL
    int NoPetak;
    char in_NoPetak[MAXC];
    boolean is_valid = false;
    // ALGORITMA
    while (!is_valid)
    {
        printf("Masukkan petak (range dari 1 hingga %d):\n>> ", JumPetak);
        scanf("%d", in_NoPetak);
        NoPetak = str_to_int_idx0(in_NoPetak);
        if (1 <= NoPetak && NoPetak <= JumPetak)
        {
            if (IsPetakTP(NoPetak, arrtp))
            {
                is_valid = true;
                printf("Awas! Petak %d memiliki teleporter ke petak %d!\n", NoPetak, arrtp.TTP[NoPetak]);
            }
            else if (IsPetakTerlarang(Peta, NoPetak))
            {
                is_valid = true;
                printf("Petak %d adalah petak terlarang. ¡No Pasaran!\n", NoPetak);
            }
            else
            {
                is_valid = true;
                printf("Petak %d adalah petak kosong. Aman!\n", NoPetak);
            }
        }
        else
        {
            printf("Tetot! Input invalid atau melebihi range (1 hingga %d).\n", JumPetak);
        }
    }
}