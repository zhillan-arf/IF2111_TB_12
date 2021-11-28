/*
    TUBES IF2111 K2 KELOMPOK 12
    GACHA SKILL - HEADER
    Versi: 2021-11-15 11:30
*/

#include "gacha_skill.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../../misc/start_display.h"

void gacha_skill(List *LSkillCurrentP, int MaxRoll) {
    // I.S. List Skill si player kosong atau berisi <= 10 skill
    // F.S. List Skill bertambah 1 skill random atau tidak nambah jika penuh
    // KAMUS
    int rolled, newskill, nbelmt, newvalue = VALUE_UNDEF;
    time_t t;
    // ALGORITMA
    printf("Memulai gacha skill... ");
    delay(1);
    srand((unsigned) time(&t)); // Inisialisasi rand
    nbelmt = NbElmt(*LSkillCurrentP);
    if (nbelmt < 10)
    {
        printf("Jumlah skill yang sekarang dimiliki: (%d/10). \nKamu mendapat gacha... ", nbelmt);
        delay(1);
        rolled = rand() % 100;
        if (rolled == 69)
        {
            printf("\n(@GACHA.SYSTEM: rolled seed '69'. Nice.)\n");
        }
        if (0 <= rolled && rolled <= 10)
        {
            // Pintu Ga Kemana Saja
            newskill = 1;
            printf("'Pintu Ga Kemana Saja' (+1)! \nGunakan untuk menghindari teleport.\n");
        }
        else if (11 <= rolled && rolled <= 20)
        {
            // Mesin Waktu
            newskill = 2;
            srand((unsigned) time(&t) + 177013);
            newvalue = (rand() % (MaxRoll)) + 1;
            printf("'Mesin Waktu (<< %d petak)' (+1)! \nGunakan untuk memundurkan pemain lain.\n", newvalue);
        }
        else if (21 <= rolled && rolled <= 30)
        {
            // Baling-Baling Jambu
            newskill = 3;
            srand((unsigned) time(&t) + 271048);
            newvalue = (rand() % (MaxRoll)) + 1;
            printf("'Baling-Baling Jambu (>> %d petak)' (+1)! \nGunakan untuk mamajukan pemain lain.\n", newvalue);
        }
        else if (31 <= rolled && rolled <= 36)
        {
            // Cermin Pengganda
            newskill = 4;
            printf("SKILL ULTRA RARE 'Cermin Pengganda' (+1)! \nGunakan untuk mendapatkan 2 skill baru.\n");
        }
        else if (36 <= rolled && rolled < 51)
        {
            // Senter Pembesar Hoki
            newskill = 5;
            printf("'Senter Pembesar Hoki' (+1)! \nGunakan untuk memperbesar roll dadu.\n");
        }
        else if (52 <= rolled && rolled <= 66)
        {
            // Senter Pengecil Hoki
            newskill = 6;
            printf("'Senter Pengecil Hoki' (+1)! \nGunakan untuk memperkecil roll dadu.\n");
        }
        else if (67 <= rolled && rolled <= 70)
        {
            // Mesin Penukar Posisi
            newskill = 7;
            printf("SKILL ULTRA RARE 'Mesin Penukar Posisi' (+1)! \nGunakan untuk bertukar dengan player lain (tidak memicu teleport kok).\n");
        }
        else    // (71 <= rolled && rolled <= 99)
        {
            newskill = 0;
            printf("!!! Server gacha lagi down. Gagal dapat skill. :sadge:.\n");
        }

        if (newskill != 0)
        {
            InsVLast(LSkillCurrentP, newskill, newvalue);
            nbelmt = NbElmt(*LSkillCurrentP);
            printf("Skill berhasil disimpan di slot skill (%d/10).\n", nbelmt);
        }
    }
    else
    {
        printf("Tetot! Slot skill kamu penuh (%d/10). Gacha skill gagal.\n", nbelmt);
    }
}