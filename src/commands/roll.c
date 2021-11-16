/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND ROLL - IMPLEMENTASI
    Versi: 2021-11-15 11:30
*/

#include "roll.h"
#include <stdlib.h>
#include <stdio.h>
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
    int rolled, nexts, pasts, idx_now, input;
    boolean is_valid;
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
    is_valid = false;
    idx_now = current_petak(*p);
    nexts = (current_petak(*p)) + rolled;
    pasts = (current_petak(*p)) - rolled;
    if ((0 < pasts) && (nexts < JumlahPemain))
    {
        if (IsPetakKosong(peta, pasts) && IsPetakKosong(peta, nexts))
        {
            printf("%s bisa maju, bisa mundur. Mau ke mana?\n1. Maju ke %d.\n2.Mundur ke %d.", (idx_now + nexts), (idx_now - pasts));
            scanf("%s", &input);
            while (!is_valid)
            {
                if (input == 1)
                {
                    maju(p, nexts, peta);
                    is_valid = true;
                }
                else if (input == 2)
                {
                    mundur(p, pasts, peta);
                    is_valid = true;
                }
                else    // Input invalid
                {
                    printf("Tetot! Input tidak valid. Ulangi!\nInput '1' untuk maju, '2' untuk mundur: ");
                }
            }
        }
        else if (IsPetakKosong(peta, pasts))
        {
            printf("%s bisa mundur.\n");
            mundur(p, pasts, peta);
        }
        else if (IsPetakKosong(peta, nexts))
        {
            printf("%s bisa maju.\n");
            maju(p, nexts, peta);
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
            mundur(p, pasts, peta);
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
            maju(p, nexts, peta);
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


void maju(player *p, int nexts, TabPeta Peta) {
    // I.S. Player P berada di tempatnya, nexts + tempat saat ini ada di peta dan tidak kosong
    // F.S. Player P pindah ke nexts. Jika is_teleport dan not immune dan ketemu teleporter, teleport.
    // Jika immune, kasih pilihan mau ga teleport ga
    // KAMUS LOKAL
    int idx_prev, idx_now;
    // ALGORITMA
    idx_prev = current_petak(*p);
    idx_now = idx_prev + nexts;
    current_petak(*p) = idx_now;
    printf("%s maju %d langkah, dari petak %d ke petak %d.\n", nama(*p), nexts, idx_prev, idx_now);
    if (!IsPetakKosong(Peta, idx_now) && !IsPetakTerlarang(Peta, idx_now))    // ikz Teleport
    {
        teleport(p, GetPetak(Peta, idx_now));
    }
}

void mundur(player *p, int pasts, TabPeta Peta) {
    // I.S. Player P berada di tempatnya, nexts + tempat saat ini ada di peta dan tidak kosong
    // F.S. Player P pindah ke pasts. Jika is_teleport dan not immune dan ketemu teleporter, teleport.
    // Jika immune, kasih pilihan mau ga teleport ga. P diupdate.
    // KAMUS LOKAL
    int idx_prev, idx_now;
    // ALGORITMA
    idx_prev = current_petak(*p);
    idx_now = idx_prev + pasts;
    current_petak(*p) = idx_now;
    printf("%s mundur %d langkah, dari petak %d ke petak %d.\n", nama(*p), pasts, idx_prev, idx_now);
    if (!IsPetakKosong(Peta, idx_now) && !IsPetakTerlarang(Peta, idx_now))    // ikz Teleport
    {
        teleport(p, GetPetak(Peta, idx_now));
    }
}

void teleport(player *p, int new_petak) {
    // I.S. Player P berada di tempatnya, new_petak adalah petak kosong di peta
    // F.S. Player P pindah ke tempat kosong tersebut. P diupdate.
    // KAMUS LOKAL
    char input;
    boolean is_valid;
    // ALGORITMA
    printf("!!! Mendadak sobekan dimensional menuju petak %d terbuka!\n");
    if (isImunTele(buff(*p)))
    {
        printf("NOTICE: Kamu punya buff 'Imunitas Teleport'.\nPakai untuk menghindari teleport? (Y/N): ");
        scanf("%s", &input);
        is_valid = false;
        while (!is_valid)
        {
            if (input == "Y" || input == "y")
            {
                is_valid = true;
                printf("Klep! Sobekan menutup. Kamu tidak berpindah.\n");
            }
            else if (input == "N" || input == "n")
            {
                is_valid = true;
                current_petak(*p) = new_petak;
                printf("Swoosh! Kamu terhisap dan diteleport keluar ke petak %d. Aduduh!\n", new_petak);
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
        printf("Swoosh! Kamu terhisap dan diteleport keluar ke petak %d. Aduduh!\n", new_petak);
    }
}