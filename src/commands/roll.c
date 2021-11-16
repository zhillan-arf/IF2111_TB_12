/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND ROLL - IMPLEMENTASI
    Versi: 2021-11-15 11:30
*/

#include "roll.h"
#include <stdlib.h>
#include "../ADT/array_map.h"
#include "../ADT/array_buff.h"
#include "../ADT/player.h"

void roll (
        int *Roll,
        int MaxRoll,
        TabPeta peta,
        int JumlahPemain,
        player *p
    ) {
    // I.S. Tiap player berada di posisinya masing-masing
    // F.S. Posisi palyer yang meng-roll bisa jadi berubah
    // KAMUS LOKAL
    int rolled, nexts, pasts;
    // ALGORITMA
    // Dice Roll
    if (isSenterBesar(buff(*p)))
    {
        printf("Buff Senter Pembesar Hoki terpakai.\n");
        rolled = (rand() % (MaxRoll/2)) + 1 + (MaxRoll/2);
        (isSenterBesar(buff(*p))) = false;   // Reset buff
    }
    else if (isSenterKecil(buff(*p)))
    {
        printf("Buff Senter Pengecil Hoki terpakai.\n");
        rolled = (rand() % (MaxRoll/2)) + 1;
        (isSenterKecil(buff(*p))) = false;   // Reset buff
    }
    else    // Tidak ada buff
    {
        rolled = (rand() % (MaxRoll)) + 1;
    }
    (*Roll) = rolled;
    printf("%s meng-roll dan mendapat %d\n", nama(*p));
    
    // Kondisional
    nexts = (current_petak(*p)) + rolled;
    pasts = (current_petak(*p)) - rolled;
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