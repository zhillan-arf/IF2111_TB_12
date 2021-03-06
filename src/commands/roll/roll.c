/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND ROLL - IMPLEMENTASI
    Versi: 2021-11-28
*/

#include "roll.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../ADT/array_map/array_map.h"
#include "../../ADT/array_tp/array_tp.h"
#include "../../ADT/array_buff/array_buff.h"
#include "../../ADT/player/player.h"
#include "../../misc/start_display.h"
#include <time.h>
#include "../../misc/convert.h"

void roll (
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
    char in_input[MAXC];
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
    printf("Melempar dadu...\n");
    delay(1);
    printf("%s mendapat '%d'.\n", nama(*p), rolled);
    
    // Kondisional
    is_valid = false;
    idx_now = current_petak(*p);
    next_idx = (current_petak(*p)) + rolled;
    past_idx = (current_petak(*p)) - rolled;
    if ((0 < past_idx) && (next_idx < JumPetak))
    {
        if (IsPetakKosong(peta, past_idx) && IsPetakKosong(peta, next_idx))
        {
            while (!is_valid)
            {
                printf("%s bisa maju, bisa mundur. Mau ke mana?\n    1. Maju ke petak %d.\n    2. Mundur ke petak %d.\n>> ", nama(*p), next_idx, past_idx);
                scanf("%s", in_input);
                input = str_to_int_idx0(in_input);
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
                    printf("Tetot! Input tidak valid. Ulangi!\nInput '1' untuk maju, '2' untuk mundur.\n");
                }
            }
        }
        else if (IsPetakKosong(peta, past_idx))
        {
            printf("%s bisa mundur.\n", nama(*p));
            mundur(p, past_idx, peta, arrtp);
        }
        else if (IsPetakKosong(peta, next_idx))
        {
            printf("%s bisa maju.\n", nama(*p));
            maju(p, next_idx, peta, arrtp);
        }
        else
        {
            printf("%s nge-stuck, tidak bisa ke manapun.\n", nama(*p));
        }
    }
    else if ((0 < past_idx))
    {
        if (IsPetakKosong(peta, past_idx))
        {
            printf("%s bisa mundur.\n", nama(*p));
            mundur(p, past_idx, peta, arrtp);
        }
        else
        {
            printf("%s ngestuck, tidak bisa ke manapun.\n", nama(*p));
        }
    }
    else if (next_idx < JumPetak)
    {
        if (IsPetakKosong(peta, next_idx))
        {
            printf("%s bisa maju.\n", nama(*p));
            maju(p, next_idx, peta, arrtp);
        }
        else
        {
            printf("%s ngestuck, tidak bisa ke manapun.\n", nama(*p));
        }
    }
    else
    {
        printf("%s ngestuck, tidak bisa ke manapun.\n", nama(*p));
    }
}


void maju(player *p, int next_idx, TabPeta Peta, TabTP arrtp) {
    // I.S. Player P berada di tempatnya, next_idx + tempat saat ini ada di peta dan tidak kosong
    // F.S. Player P pindah ke next_idx. Jika is_teleport dan not immune dan ketemu teleporter, teleport.
    // Jika immune, kasih pilihan mau ga teleport ga
    // ALGORITMA
    printf("%s maju ke petak %d.\n", nama(*p), next_idx);
    if (IsPetakTP(next_idx, arrtp))    // ikz Teleport
    {
        teleport(p, arrtp.TTP[next_idx]);
    }
    else
    {
        printf("Tidak ada apa-apa pada petak %d\n", next_idx);
        current_petak(*p) = next_idx;
    }
}

void mundur(player *p, int past_idx, TabPeta Peta, TabTP arrtp) {
    // I.S. Player P berada di tempatnya, next_idx + tempat saat ini ada di peta dan tidak kosong
    // F.S. Player P pindah ke past_idx. Jika is_teleport dan not immune dan ketemu teleporter, teleport.
    // Jika immune, kasih pilihan mau ga teleport ga. P diupdate.
    // ALGORITMA
    printf("%s mundur ke petak %d.\n", nama(*p), past_idx);
    if (IsPetakTP(past_idx, arrtp))    // ikz Teleport
    {
        teleport(p, arrtp.TTP[past_idx]);
    }
    else
    {
        printf("Tidak ada apa-apa pada petak %d\n", past_idx);
        current_petak(*p) = past_idx;
    }
}

void teleport(player *p, int new_petak) {
    // I.S. Player P berada di tempatnya, new_petak adalah petak kosong di peta
    // F.S. Player P pindah ke tempat kosong tersebut. P diupdate.
    // KAMUS LOKAL
    char in_input[63];
    int input;
    boolean is_valid;
    // ALGORITMA
    printf("!!! Sobekan dimensional menuju petak %d terdeteksi!\n", new_petak);
    if (isImunTele(buff(*p)))
    {
        is_valid = false;
        while (!is_valid)
        {
            printf("%s! Kamu punya buff 'Imunitas Teleport'.\nPakai untuk menghindari teleport?\n", nama(*p));
            printf("    1. Ya.\n");
            printf("    2. Tidak.\n>> ");
            scanf("%s", in_input);
            input = str_to_int_idx0(in_input);
            if (input == 1)
            {
                printf("Klep! Sobekan ditutup sementara.\nKamu menemukan tempat berlindung dan tidak berpindah.\n");
                isImunTele(buff(*p)) = false;
                printf("Kamu kehilangan buff 'Imunitas Teleport'.\n");
                is_valid = true;
            }
            else if (input == 2)
            {
                current_petak(*p) = new_petak;
                printf("Swoosh! Kamu terhisap dan diteleport ke petak %d. Aduduh!\n", new_petak);
                is_valid = true;
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