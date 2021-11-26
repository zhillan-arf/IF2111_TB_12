/*
    TUBES IF2111 K2 KELOMPOK 12
    ADT PLAYER - HEADER
    Versi: 2021-11-16 20:30
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../boolean.h"
#include "../ADT/array_buff.h"
#include "../ADT/player.h"
#include "../ADT/list.h"
#include "../ADT/state.h"
#include "../commands/roll.h"
#include "start_display.h"
#include "gacha_skill.h"
#include "skills.h"

// DEFINISI VARIABEL KONSTAN
char *namaSkill[] = {
    "Pintu Ga Ke Mana Mana",
    "Mesin Waktu",
    "Baling Baling Jambu",
    "Cermin Pengganda",
    "Senter Pembesar Hoki", 
    "Senter Pengecil Hoki", 
    "Mesin Penukar Posisi"
};

// DEFINISI FUNGSI PROSEDUR SKILL UTAMA
void displaySkill(List S, char *namaSkill[]) {
    // KAMUS LOKAL
    address loc;
    int count, tempinfo;
    // ALGORITMA
    printf("\nDaftar skill yang kamu punya:\n");
    if (!IsEmpty(S)) {
        loc = First(S);
        count = 0;
        while (loc != Nil) {
            count++;
            tempinfo = Info(loc) - 1;
            printf("    %d. %s", count, namaSkill[tempinfo]);
            if (tempinfo == 1)
            {
                printf(" (<< %d petak)", Value(loc));
            }
            else if (tempinfo == 2)
            {
                printf(" (>> %d petak)", Value(loc));
            }
            printf("\n");
            loc = Next(loc);
        }
    }
    else 
    {
        printf("    0. Kamu tidak memiliki skill.\n");
    }
}
void menuSkill(
        State *state, 
        player *P, 
        int MaxRoll, 
        int JumPetak, 
        TabPeta peta, 
        TabTP arrtp, 
        char *namaSkill[]
    ) {
    // KAMUS LOKAL
    int idx_choice, choiceToSkill, ctr, val, idx_player;
    address loc;
    boolean is_valid = false;
    // ALGORITMA
    idx_player = GetPlayerIdx((*state), (*P));
    if (!IsEmpty((*state).TabPlayer[idx_player].skill)) 
    {
        while (!is_valid)
        {
            displaySkill((*state).TabPlayer[idx_player].skill, namaSkill);
            printf("\nPilih Skill yang mau diakftifkan! (Pilih 0 untuk keluar)\n>> ");
            scanf("%d", &idx_choice);
            // Didapat no urut di terminal yang dipilih
            if (valid_menuSkill(idx_choice, NbElmt((*state).TabPlayer[idx_player].skill)))  // idx_choice = antara 1 sampe NbElmt(list skill)
            {
                ctr = 0;
                loc = First((*state).TabPlayer[idx_player].skill);
                while (loc != NULL && ctr < idx_choice) {
                    choiceToSkill = Info(loc);
                    val = Value(loc);
                    loc = Next(loc);
                    ctr++;
                }
                // ctr == idx_choice
                // Didapat nomor skill betulan (bukan nomor urut di terminal)
                switch (choiceToSkill) {
                    case 1:
                        PintuGaKemanaSaja(P);
                        printf("Jumlah skill yang sekarang dimiliki: (%d/10).\n", NbElmt((*state).TabPlayer[idx_player].skill));
                        break;
                    case 2:
                        MesinWaktu(state, P, JumPetak, peta, arrtp, val);
                        printf("Jumlah skill yang sekarang dimiliki: (%d/10).\n", NbElmt((*state).TabPlayer[idx_player].skill));
                        break;
                    case 3:
                        BalingBalingJambu(state, P, JumPetak, peta, arrtp, val);
                        printf("Jumlah skill yang sekarang dimiliki: (%d/10).\n", NbElmt((*state).TabPlayer[idx_player].skill));
                        break;
                    case 4:
                        CerminPengganda(P, MaxRoll);
                        break;
                    case 5: 
                        SenterPembesarHoki(P);
                        printf("Jumlah skill yang sekarang dimiliki: (%d/10).\n", NbElmt((*state).TabPlayer[idx_player].skill));
                        break;
                    case 6:
                        SenterPengecilHoki(P);
                        printf("Jumlah skill yang sekarang dimiliki: (%d/10).\n", NbElmt((*state).TabPlayer[idx_player].skill));
                        break;
                    case 7:
                        MesinTukar(state, P);
                        printf("Jumlah skill yang sekarang dimiliki: (%d/10).\n", NbElmt((*state).TabPlayer[idx_player].skill));
                        break;  
                }
            }
            else if (idx_choice == 0)
            {
                is_valid = true;
                printf("Kembali ke turn...\n");
                // Selesai
            }
            else
            {
                printf("Tetot! Input invalid. Mohon masukkan nomor skill yang tertera (misal '1').");
            }
        }
    }
    else
    {
        printf("Kamu tidak memiliki skill.\n");
    }  
}

// DEFINISI FUNGSI PROSEDUR TIAP SKILL
void PintuGaKemanaSaja(player* P) {
    // ALGORITMA
    if (BUFF(buff(*P), 1))
    {
        printf("!!! Kamu sudah punya buff 'Imunitas Teleport'! \nMembatalkan penggunaan skill...\n");
    }
    else
    {
        BUFF(buff(*P), 1) = true;
        printf("Buff 'Imunitas Teleport' diaktifkan oleh %s.\n", (*P).nama);
        DelP(&skill(*P), 1);
        printf("Skill 'Pintu Ga Kemana Saja' terpakai (-1) dan dihapus dari slot.\n");
    }
}

void MesinWaktu (
        State *state, 
        player *P, 
        int JumPetak, 
        TabPeta peta, 
        TabTP arrtp, 
        int val
    ) {
    // Skill ke-2
    // KAMUS LOKAL
    int past_idx, input, idx_player, nEff;
    boolean is_valid = false;
    // ALGORITMA
    idx_player = GetPlayerIdx((*state), (*P));
    nEff = GetLastIdx(*state) + 1;
    printf("\nSiapa yang mau dimundurkan %d petak?\n", val);
    print_players((*state), (*P));
    while (!is_valid)
    {
        printf(">> ");
        scanf("%d", &input);
        input--;    // idx array = urutan - 1
        if (valid(input, idx_player, nEff))
        {
            is_valid = true;
        }
        else
        {
            printf("Tetot! Input invalid. Masukkan '1', '2' sesuai nomor.\n");
        }
    }
    // input valid dan sudah didecrement 1
    printf("Kamu mengaktifkan mesin waktu untuk menculik %s.\n", (*state).TabPlayer[input].nama);
    delay(1);
    past_idx = (*state).TabPlayer[input].current_petak - val;
    if (past_idx >= 0)
    {
        if (!IsPetakTerlarang(peta, past_idx))
        {
            mundur(&(*state).TabPlayer[input], past_idx, peta, arrtp);
            DelP(&skill(*P), 2);
            printf("Skill 'Mesin Waktu (<< %d petak) terpakai (-1) dan dihapus dari slot.\n", val);
        }
        else
        {
            printf("%s akan mendarat di tempat terlarang - tidak boleh!\nMesin waktu error dan batal dipakai...\n", nama((*state).TabPlayer[input]));
        }
    }
    else
    {
        printf("%s akan mendarat di luar map - tidak boleh!\nMesin waktu error dan batal dipakai...\n", nama((*state).TabPlayer[input]));
    }
}


void BalingBalingJambu (
        State *state, 
        player *P, 
        int JumPetak, 
        TabPeta peta, 
        TabTP arrtp, 
        int val
    ) {
    // Skill ke-3
    // KAMUS LOKAL
    int next_idx, input, idx_player, nEff;
    boolean is_valid = false;
    // ALGORITMA
    idx_player = GetPlayerIdx((*state), (*P));
    nEff = GetLastIdx(*state) + 1;
    printf("\nSiapa yang mau dimajukan %d petak?\n", val);
    print_players((*state), (*P));
    while (!is_valid)   // input user masuk
    {
        printf(">> ");
        scanf("%d", &input);
        input--;    // idx array = urutan - 1
        if (valid(input, idx_player, nEff))
        {
            is_valid = true;
        }
        else
        {
            printf("Tetot! Input invalid. Masukkan '1', '2' sesuai yang ditampilkan.\n");
        }
    }
    // input valid dan sudah didecrement 1
    printf("Kamu mengaktifkan baling-baling jambu untuk menculik %s.\n", (*state).TabPlayer[input].nama);
    delay(1);
    next_idx = (*state).TabPlayer[input].current_petak + val;
    if (next_idx <= JumPetak)
    {
        if (!IsPetakTerlarang(peta, next_idx))
        {
            maju(&(*state).TabPlayer[input], next_idx, peta, arrtp);
            DelP(&skill(*P), 3);
            printf("Skill 'Baling-Baling Jambu (>> %d petak) terpakai (-1) dan dihapus dari slot.\n", val);
        }
        else
        {
            printf("%s akan mendarat di tempat terlarang - tidak boleh!\nBaling-baling jambu error, mogok, dan batal dipakai.\n", nama((*state).TabPlayer[input]));
        }
    }
    else
    {
        printf("%s akan mendarat di luar map - tidak boleh!\nBaling-baling jambu error, mogok, dan batal dipakai.\n", nama((*state).TabPlayer[input]));
    }
}

void CerminPengganda(player *P, int MaxRoll){
    //Cermin pengganda
    if (!isCerminGanda((*P).buff) && NbElmt(skill(*P)) < 9) {
        gacha_skill(&skill(*P), MaxRoll);
        printf("\n");
        gacha_skill(&skill(*P), MaxRoll);
        isCerminGanda((*P).buff) = true;
        printf("Buff 'Cermin Pengganda' diaktifkan oleh %s, sehingga \nia dilarang pakai skill ini lagi sampai ganti round.\n", (*P).nama);
        DelP(&skill(*P), 4);
        printf("Skill 'Cermin Pengganda' terpakai (-1) dan dihapus dari slot.\n");
    }
    else if (isCerminGanda((*P).buff))
    {
        printf("Kamu cuma boleh pakai skill ini sekali per round. \nMembatalkan pengguaan skill...\n");
    }
    else
    {
        printf("Kapasitas slot skill kamu tidak cukup! \nMembatalkan penggunaan skill...\n");
    }
}

void SenterPembesarHoki(player *P) {
    // ALGORITMA
    if (!isSenterBesar(buff(*P))) {
        isSenterBesar(buff(*P)) = true;
        printf("Buff 'Senter Pembesar Hoki' diaktifkan oleh %s!\n", (*P).nama);
        DelP(&skill(*P), 5);
        printf("Skill 'Senter Pembesar Hoki' terpakai (-1) dan dihapus dari slot.\n");
    }
    else
    {
        printf("!!! Kamu sudah punya buff 'Senter Pembesar Hoki'! \nMembatalkan penggunaan skill...\n");
    }
}


void SenterPengecilHoki(player *P) {
    // ALGORITMA
    if (!isSenterKecil(buff(*P))) {
        isSenterKecil(buff(*P)) = true;
        printf("Buff 'Senter Pengecil Hoki' diaktifkan oleh %s!\n", (*P).nama);
        DelP(&skill(*P), 6);
        printf("Skill 'Senter Pengecil Hoki' terpakai (-1) dan dihapus dari slot.\n");
    }
    else
    {
        printf("!!! Kamu sudah punya buff 'Senter Pengecil Hoki'! \nMembatalkan penggunaan skill...\n");
    }
}


void MesinTukar(State *state, player *P) {
    int input, idx_player, nEff, petakP, petakP2;
    boolean is_valid = false;
    // ALGORITMA
    idx_player = GetPlayerIdx((*state), (*P));
    nEff = GetLastIdx(*state) + 1;
    printf("\nMau tukar sama siapa?\n");
    print_players((*state), (*P));
    while (!is_valid)   // input user masuk
    {
        printf(">> ");
        scanf("%d", &input);
        input--;    // idx array = urutan - 1
        if (valid(input, idx_player, nEff))
        {
            is_valid = true;
        }
        else
        {
            printf("Tetot! Input invalid. Masukkan '1', '2' sesuai yang ditampilkan.\n");
        }
    }
    // is_valid
    printf("Kamu mengaktifkan mesin tukar untuk menculik %s.\n", (*state).TabPlayer[input].nama);
    delay(1);
    petakP = (*P).current_petak;
    petakP2 = (*state).TabPlayer[input].current_petak;
    (*P).current_petak = petakP2;
    (*state).TabPlayer[input].current_petak = petakP;
    printf("%s berpindah dari petak %d ke petak %d.\n", (*P).nama, petakP, petakP2);
    printf("%s berpindah dari petak %d ke petak %d.\n", (*state).TabPlayer[input].nama, petakP2, petakP);
    printf("Tidak ada teleporter yang teraktivasi.\n");
    DelP(&skill(*P), 7);
    printf("Skill 'Mesin Tukar' terpakai (-1) dan dihapus dari slot.\n");
}

// DEFINISI FUNGSI PROSEDUR TAMBAHAN
void print_players (State state, player cplayer) {
    // KAMUS
    int i = 1;
    // ALGORITMA
    while (i < state.Neff)
    {
        if (state.TabPlayer[i].nama != cplayer.nama)
        {
            printf("    %d. %s\n", (i + 1), state.TabPlayer[i].nama);
        }
        i++;
    }
    // i = Neff
}

boolean valid (int idx, int idx_player, int nEff) {
    // KAMUS
    boolean is_in_array = false;
    int i = 0;
    // ALGORITMA
    while (i < nEff && !is_in_array)
    {
        if (idx == i)
        {
            is_in_array = true;
        }
        i++;
    }
    if (idx == idx_player)
    {
        printf("Kamu tidak bisa menggunakan alat terhadap diri sendiri!\n");
    }
    return (is_in_array && (idx != idx_player));
}

boolean valid_menuSkill (int idx_choice, int nbelmt) {
    // KAMUS
    int i = 1;
    boolean found = false;
    // ALGORITMA
    while (i <= nbelmt && !found)
    {
        if (idx_choice == i)
        {
            found = true;
        }
        i++;
    }
    return found;
}