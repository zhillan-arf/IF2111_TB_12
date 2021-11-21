/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND ROLL - IMPLEMENTASI
    Versi: 2021-11-17 21:30
*/

#include "roll.h"
#include <stdlib.h>
#include <stdio.h>
#include "../ADT/array_map.h"
#include "../ADT/array_tp.h"
#include "../ADT/array_buff.h"
#include "../ADT/player.h"
#include <time.h>

void roll (
        int *Roll,
        int MaxRoll,
        TabPeta peta,
        TabTP arrtp,
        int JumPetak,
        player *p
    ) {
    // I.S. Tiap player berada di posisinya masing-masing
    // F.S. Posisi palyer yang meng-roll bisa jadi berubah
    // KAMUS LOKAL
    int rolled, next_idx, past_idx, idx_now, input;
    boolean is_valid;
    time_t t;
    // ALGORITMA
    // Dice Roll
    srand((unsigned) time(&t)); // Inisialisasi rand
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
    is_valid = false;
    idx_now = current_petak(*p);
    next_idx = (current_petak(*p)) + rolled;
    past_idx = (current_petak(*p)) - rolled;
    if ((0 < past_idx) && (next_idx < JumPetak))
    {
        if (IsPetakKosong(peta, past_idx) && IsPetakKosong(peta, next_idx))
        {
            printf("%s bisa maju, bisa mundur. Mau ke mana?\n1. Maju ke %d.\n2.Mundur ke %d.", (idx_now + next_idx), (idx_now - past_idx));
            scanf("%s", &input);
            while (!is_valid)
            {
                if (input == 1)
                {
                    maju(p, next_idx, peta, arrtp);
                    is_valid = true;
                }
                else if (input == 2)
                {
                    mundur(p, past_idx, peta, arrtp);
                    is_valid = true;
                }
                else    // Input invalid
                {
                    printf("Tetot! Input tidak valid. Ulangi!\nInput '1' untuk maju, '2' untuk mundur: ");
                }
            }
        }
        else if (IsPetakKosong(peta, past_idx))
        {
            printf("%s bisa mundur.\n");
            mundur(p, past_idx, peta, arrtp);
        }
        else if (IsPetakKosong(peta, next_idx))
        {
            printf("%s bisa maju.\n");
            maju(p, next_idx, peta, arrtp);
        }
        else
        {
            printf("%s ngestuck, tidak bisa ke manapun.\n");
        }
    }
    else if ((0 < past_idx))
    {
        if (IsPetakKosong(peta, past_idx))
        {
            printf("%s bisa mundur.\n");
            mundur(p, past_idx, peta, arrtp);
        }
        else
        {
            printf("%s ngestuck, tidak bisa ke manapun.\n");
        }
    }
    else if (next_idx < JumPetak)
    {
        if (IsPetakKosong(peta, next_idx))
        {
            printf("%s bisa maju.\n");
            maju(p, next_idx, peta, arrtp);
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


void maju(player *p, int next_idx, TabPeta Peta, TabTP arrtp) {
    // I.S. Player P berada di tempatnya, next_idx + tempat saat ini ada di peta dan tidak kosong
    // F.S. Player P pindah ke next_idx. Jika is_teleport dan not immune dan ketemu teleporter, teleport.
    // Jika immune, kasih pilihan mau ga teleport ga
    // ALGORITMA
    printf("%s maju ke petak %d.\n", nama(*p), next_idx);
    if (!IsPetakKosong(Peta, next_idx) && !IsPetakTerlarang(Peta, next_idx))    // ikz Teleport
    {
        teleport(p, arrtp.TTP[next_idx]);
    }
    else
    {
        printf("Tidak ada apa-apa pada petak %d\n", next_idx);
    }
}

void mundur(player *p, int past_idx, TabPeta Peta, TabTP arrtp) {
    // I.S. Player P berada di tempatnya, next_idx + tempat saat ini ada di peta dan tidak kosong
    // F.S. Player P pindah ke past_idx. Jika is_teleport dan not immune dan ketemu teleporter, teleport.
    // Jika immune, kasih pilihan mau ga teleport ga. P diupdate.
    // ALGORITMA
    printf("%s mundur ke petak %d.\n", nama(*p), past_idx);
    if (!IsPetakKosong(Peta, past_idx) && !IsPetakTerlarang(Peta, past_idx))    // ikz Teleport
    {
        teleport(p, arrtp.TTP[past_idx]);
    }
    else
    {
        printf("Tidak ada apa-apa pada petak %d\n", past_idx);
    }
}

void teleport(player *p, int new_petak) {
    // I.S. Player P berada di tempatnya, new_petak adalah petak kosong di peta
    // F.S. Player P pindah ke tempat kosong tersebut. P diupdate.
    // KAMUS LOKAL
    char input;
    boolean is_valid;
    // ALGORITMA
    printf("!!! Sobekan dimensional menuju petak %d terdeteksi!\n");
    if (isImunTele(buff(*p)))
    {
        printf("%s! Kamu punya buff 'Imunitas Teleport'.\nPakai untuk menghindari teleport? (Y/N): ");
        scanf("%s", &input);
        is_valid = false;
        while (!is_valid)
        {
            if (input == "Y" || input == "y")
            {
                is_valid = true;
                printf("Klep! Sobekan ditutup sementara.\nKamu menemukan tempat berlindung dan tidak berpindah.\n");
                isImunTele(buff(*p)) = false;
                printf("Kamu kehilangan buff 'Imunitas Teleport'.\n");
            }
            else if (input == "N" || input == "n")
            {
                is_valid = true;
                current_petak(*p) = new_petak;
                printf("Swoosh! Kamu terhisap dan diteleport ke petak %d. Aduduh!\n", new_petak);
            }
            else
            {
                printf("Tetot! Input tidak valid. Ulangi!\nInput 'Y' untuk memakai buff, 'N' untuk sekip: ");
            }
        }
    }
    else    // Tidak imun
    {
        current_petak(*p) = new_petak;
        printf("Swoosh! Kamu terhisap dan diteleport ke petak %d. Aduduh!\n", new_petak);
    }
}