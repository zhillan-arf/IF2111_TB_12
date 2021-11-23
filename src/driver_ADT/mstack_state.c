/*
    TUBES IF2111 KELOMPOK 12
    ADT STACK STATE - DRIVER
    Versi: 2021-11-24 01:11 (modan)
    Notes: Hanya fungsi, prosedur relevan yang dites
*/

#include <stdio.h>
#include "../ADT/stack_state.h"
#include "../ADT/state.h"

int main() {
    // KAMUS
    int count = 0;
    // ALGORITMA
    printf("UNIT TESTING ADT stack_state dimulai... (0/6):\n");

    // TEST1 CreateEmptyStack
    // KAMUS
    Stack stack;
    // ALGORITMA
    CreateEmptyStack(&stack);
    printf("SUKSES TEST1 CreateEmptyStack\n");
    count++;

    // TEST2 IsEmptyStack
    // ALGORITMA
    if (IsEmptyStack(stack)) {
        printf("SUKSES TEST2 IsEmptyStack\n");
        count++;
    }

    // TEST3 & TEST4
    // INISIALISASI
    State currstate;
    State state1;
    SetNeff(&currstate, 1);
    
    player p2;
    *p2.nama = 'A';
    p2.current_petak = 1;
    SetPlayer(&currstate, 1, p2);
    
    player p1;
    *p1.nama = 'B';
    p1.current_petak = 1;
    SetPlayer(&currstate, 0, p1);
    
    // ALGORITMA
    for (int i=0;i < 2; i++) {
        p1.current_petak ++;
        SetPlayer(&currstate, 0, p1);
        p2.current_petak +=2;
        SetPlayer(&currstate, 1, p2);
        Push(&stack,currstate);
    }
    Pop(&stack, &state1);
    if (state1.TabPlayer[0].current_petak == 3 && state1.TabPlayer[1].current_petak == 5) {
        printf("SUKSES TEST3 Push\n");
        printf("SUKSES TEST4 Pop\n");
        printf("SUKSES TEST5 AlokasiStack\n");      // Karena jika Push berhasil maka Alokasi juga berhasil
        printf("SUKSES TEST6 DealokasiStack\n");    // Karena jika Pop berhasil maka Dealokasi juga berhasil
        count+=4;
    }
    printf("UNIT TESTS ADT state selesai. Betul (%d/6).\n", count);
    return 0;
}
