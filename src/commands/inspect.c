/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND INSPECT - IMPLEMENTASI
    Versi: 2021-11-15 11:30
*/

#include "inspect.h"

void inspect (TabPeta *Peta) {
    // I.S. Peta dari file config terbaca, turn sembarang
    // F.S. Teroutput hal2 yang diinginkan player, jika ada
    // KAMUS LOKAL
    int NoPetak;
    // ALGORITMA
    printf("Masukkan petak: ");
    scanf("%d", &NoPetak);
    if (IsPetakKosong((*Peta), NoPetak))
    {
        printf("Petak %d adalah petak kosong!\n", NoPetak);
    }
    else if (IsPetakTerlarang((*Peta), NoPetak))
    {
        printf("Petak %d adalah petak terlarang. ¡No Pasaran!\n", NoPetak);
    }
    else
    {
        printf("Awas! Petak %d memiliki teleporter ke petak %d!\n", NoPetak, GetPetak((*Peta), NoPetak));
    }
}