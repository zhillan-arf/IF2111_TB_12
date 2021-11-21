/*
    TUBES IF2111 K2 KELOMPOK 12
    GACHA SKILL - HEADER
    Versi: 2021-11-15 11:30
*/

#include "gacha_skill.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void gacha_skill(List *LSkillCurrentP) {
    // I.S. List Skill si player kosong atau berisi <= 10 skill
    // F.S. List Skill bertambah 1 skill random atau tidak nambah jika penuh
    // KAMUS
    int rolled, newskill, nbelmt;
    time_t t;
    // ALGORITMA
    printf("Memulai gacha skil...");
    srand((unsigned) time(&t)); // Inisialisasi rand
    nbelmt = NbElmt(*LSkillCurrentP);
    if (nbelmt <= 10)
    {
        printf("Slot skill baru terisi (%d/10). Kamu mendapat gacha skill...\n", nbelmt);
        rolled = rand() % 100;
        if (0 <= rolled && rolled <= 10)
        {
            // Pintu Ga Kemana Saja
            newskill = 1;
            printf("\n>>> 'Pintu Ga Kemana Saja' (+1) <<<\n\nGunakan untuk menghindari teleport.\n");
        }
        else if (11 <= rolled && rolled <= 20)
        {
            // Mesin Waktu
            newskill = 2;
            printf("\n>>> SKILL BONUS 'Mesin Waktu' (+1) <<<\n\nGunakan untuk memundurkan pemain lain.\n");
        }
        else if (21 <= rolled <= 30)
        {
            // Baling-Baling Jambu
            newskill = 3;
            printf("\n>>> SKILL BONUS 'Baling-Baling Jambu' (+1) <<<\n\nGunakan untuk memajukan pemain lain.\n");
        }
        else if (31 <= rolled <= 36)
        {
            // Cermin Pengganda
            newskill = 4;
            printf("\n>>> SKILL ULTRA RARE 'Cermin Pengganda' (+1) <<<\n\nGunakan untuk mendapatkan 2 skill baru.\n");
        }
        else if (36 <= rolled < 51)
        {
            // Senter Pembesar Hoki
            newskill = 5;
            printf("\n>>> 'Senter Pembesar Hoki' (+1) <<<\n\nGunakan untuk memperbesar roll dadu.\n");
        }
        else if (52 <= rolled <= 66)
        {
            // Senter Pengecil Hoki
            newskill = 6;
            printf("\n>>> 'Senter Pengecil Hoki' (+1) <<<\n\nGunakan untuk memperkecil roll dadu.\n");
        }
        else if (67 <= rolled <= 70)
        {
            // Mesin Penukar Posisi
            newskill = 7;
            printf("\n>>> SKILL ULTRA RARE 'Mesin Penukar Posisi' (+1) <<<\n\nGunakan untuk bertukar dengan player lain (tidak memicu teleport kok).\n");
        }
        else    // (71 <= rolled <= 99)
        {
            newskill = 0;
            printf("...Duar! Teknologi gacha gagal. Tidak ada skill yang didapat :sadge:.\n");
        }

        if (newskill != 0)
        {
            nbelmt++;
            InsVLast(LSkillCurrentP, newskill);
            printf("Skill berhasil disimpan di slot skill (%d/10)\n", nbelmt);
        }
    }
    else
    {
        printf("Tetot! Slot skill kamu penuh (%d/10). Gacha skill gagal.\n", nbelmt);
    }
}