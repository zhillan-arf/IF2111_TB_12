/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND ROLL - IMPLEMENTASI
    Versi: 2021-11-15 11:30
*/

#include "roll.h"
#include "../ADT/array_map.h"
#include <stdlib.h>

void roll (
        int *Roll,
        int MaxRoll,
        TabPeta peta,
        int JumlahPemain,
        // Hal2 ini ada di dalam ADT player. Kalo ADT nya dah jadi, ubah:
        char *nama_pemain,
        boolean *is_sbesar, 
        boolean *is_skecil, 
        boolean *is_immune, 
        int *currentpetak
    ) {
    // I.S. Tiap player berada di posisinya masing-masing
    // F.S. Posisi palyer yang meng-roll bisa jadi berubah
    // KAMUS LOKAL
    int rolled, nexts, pasts;
    // ALGORITMA
    // Dice Roll
    if (*is_sbesar)
    {
        printf("Buff Senter Pembesar Hoki terpakai.\n");
        rolled = (rand() % (MaxRoll/2)) + 1 + (MaxRoll/2);
        (*is_sbesar) = false;   // Reset buff
    }
    else if (*is_skecil)
    {
        printf("Buff Senter Pengecil Hoki terpakai.\n");
        rolled = (rand() % (MaxRoll/2)) + 1;
        (*is_skecil) = false;   // Reset buff
    }
    else    // Tidak ada buff
    {
        rolled = (rand() % (MaxRoll)) + 1;
    }
    (*Roll) = rolled;
    printf("%s meng-roll dan mendapat %d\n", *nama_pemain);
    
    // Kondisional
    nexts = (*currentpetak) + rolled;
    pasts = (*currentpetak) - rolled;
    if ((0 < pasts) && (nexts < JumlahPemain))
    {
        if (IsPetakKosong(peta, pasts) && IsPetakKosong(peta, nexts))
        {
            printf("%s bisa maju, bisa mundur.\n");
            // pilihan mo yang mana
            // kondisional dengan maju(), mundur()
        }
        else if (IsPetakKosong(peta, pasts))
        {
            printf("%s bisa mundur.\n");
            // mundur()
        }
        else if (IsPetakKosong(peta, nexts))
        {
            printf("%s bisa maju.\n");
            // maju()
        }
        else
        {
            printf("%s ngestuck, tidak bisa ke manapun.\n");
        }
    }
    else if ((0 < pasts))
    {
        if (IsPetakKosong(peta, pasts))
        {
            printf("%s bisa mundur.\n");
            // mundur()
        }
        else
        {
            printf("%s ngestuck, tidak bisa ke manapun.\n");
        }
    }
    else if (nexts < JumlahPemain)
    {
        if (IsPetakKosong(peta, nexts))
        {
            printf("%s bisa maju.\n");
            // maju()
        }
        else
        {
            printf("%s ngestuck, tidak bisa ke manapun.\n");
        }
    }
    else
    {
        printf("%s ngestuck, tidak bisa ke manapun.\n");
    }
}