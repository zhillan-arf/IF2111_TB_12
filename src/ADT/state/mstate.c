/*
    TUBES IF2111 KELOMPOK 12
    ADT STATE - DRIVER
    Versi: 2021-11-24 01:11 (modan)
    Notes: Hanya fungsi, prosedur relevan yang dites
*/

#include <stdio.h>
#include "state.h"

int main() {
    // KAMUS
    int count = 0;
    // ALGORITMA
    printf("UNIT TESTING ADT state dimulai... (0/14):\n");

    // TEST1 MakeEmpty
    // KAMUS
    State S1;
    //ALGORITMA
    MakeEmpty(&S1);
    printf("SUKSES TEST1 MakeEmpty\n");
    count++;
    
    // TEST2 IsEmptyTab
    // ALGORITMA
    if (IsEmptyTab(S1)) {
        printf("SUKSES TEST2 IsEmptyTab\n");
        count++;
    }

    // TEST3 IsFull
    // ALGORITMA
    if (!IsFull(S1)) {
        printf("SUKSES TEST3 IsFull\n");
        count++;
    }

    // TEST4 SetNeff
    SetNeff(&S1, 2);
    if (S1.Neff == 2) {
        printf("SUKSES TEST4 SetNeff\n");
        count++;
    }

    // TEST5 SetRound
    SetRound(&S1,1);
    if (S1.Round == 1) {
        printf("SUKSES TEST5 SetRound\n");
        count++;
    }

    // TEST6 SetPlayer
    player p2;
    p2.current_petak = 1;
    SetPlayer(&S1, 1, p2);
    player p1;
    p1.current_petak = 1;
    SetPlayer(&S1, 0, p1);
    if (S1.TabPlayer[1].current_petak == 1) {
        printf("SUKSES TEST6 SetPlayer\n");
        count++;
    }
    
    // TEST7 GetPlayer
    if (S1.TabPlayer[1].current_petak == GetPlayer(S1, 1).current_petak) {
        printf("SUKSES TEST7 GetPlayer\n");
        count++;
    }

    // TEST8 NbPlayer
    if (NbPlayer(S1) == 2) {
        printf("SUKSES TEST8 NbPlayer\n");
        count++;
    }

    // TEST9 MaxNbElmt
    if (MaxNbElmt(S1) == 100) {
        printf("SUKSES TEST9 MaxNbElmt\n");
        count++;
    }
    
    // TEST10 IsIdxValid
    if (IsIdxValid(S1, 3)) {
        printf("SUKSES TEST10 IsIdxValid\n");
        count++;
    }
    
    // TEST11 IsIdxEff
    if (IsIdxEff(S1, 1)) {
        printf("SUKSES TEST11 IsIdxEff\n");
        count++;
    }
    
    // TEST12 GetFirstIdx
    if (GetFirstIdx(S1) == 1) {
        printf("SUKSES TEST12 GetFirstIdx\n");
        count++;
    }

    // TEST13 GetLasttIdx
    if (GetLastIdx(S1) == 2) {
        printf("SUKSES TEST13 GetLastIdx\n");
        count++;
    }

    // TEST14 GetPlayerIdx
    if (GetPlayerIdx(S1,p1) == 0) {
        printf("SUKSES TEST14 GetLastIdx\n");
        count++;
    }

    printf("UNIT TESTS ADT state selesai. Betul (%d/14).\n", count);
    return 0;
}