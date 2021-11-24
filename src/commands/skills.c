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
    int count;
    // ALGORITMA
    if (!IsEmpty(S)) {
        loc = First(S);
        count = 0;
        printf("Daftar Skill yang dimiliki pemain:\n");
        while (loc != Nil) {
            count++;
            /*
            printf("%d. ");
            switch (namaSkill[Info(loc)]) {
            case 1:
                printf("Pintu Ga Ke Mana Mana");
                break;
            case 2:
                printf("Mesin Waktu");
                break;
            case 3:
                printf("Baling Baling Jambu");
                break;
            case 4:
                printf("Cermin Pengganda");
                break;
            case 5:
                printf("Senter Pembesar Hoki");
                break;
            case 6:
                printf("Senter Pengecil Hoki");
                break;
            case 7:
                printf("Mesin Penukar Posisi");
                break;
            }
            */
            printf("%d. %s\n", count, namaSkill[Info(loc)]);
            loc = Next(loc);
        }
    }
    else printf("Pemain belum memiliki skill.");
}
void menuSkill(State *state, player *P, int MaxRoll, int JumPetak, TabPeta peta, TabTP arrtp, char *namaSkill[]) {
    // KAMUS LOKAL
    List S;
    int idx_choice, choiceToSkill, ctr;
    address loc;
    boolean is_valid = false;
    // ALGORITMA
    S = skill(*P);
    displaySkill(S, namaSkill);
    if (!IsEmpty(S)) {
        loc = First(S);
        while (!is_valid)
        {
            printf("Pilih Skill yang mau diakftifkan! (pilih 0 untuk keluar)");
            scanf("%d", &idx_choice);
            // Didapat no urut di terminal yang dipilih
            if (valid_menuSkill(idx_choice, NbElmt(S)))  // idx_choice = antara 1 sampe NbElmt(S)
            {
                is_valid = true;
                ctr = 0;
                while (loc != NULL && ctr < idx_choice) {
                    ctr++;
                    choiceToSkill = Info(loc);
                    loc = Next(loc);
                }
                // ctr == idx_choice
                // Didapat nomor skill betulan (bukan nomor urut di terminal)  
                switch (choiceToSkill) {
                    case 1:
                        PintuGaKemanaSaja(P);
                        break;
                    case 2:
                        MesinWaktu(state, P, MaxRoll, JumPetak, peta, arrtp);
                        break;
                    case 3:
                        BalingBalingJambu(state, P, MaxRoll, JumPetak, peta, arrtp);
                        break;
                    case 4:
                        CerminPengganda(P);
                        break;
                    case 5: 
                        SenterPembesarHoki(P);
                        break;
                    case 6:
                        SenterPengecilHoki(P);
                        break;
                    case 7:
                        MesinTukar(state,P);
                        break;  
                }
            }
            else if (idx_choice = 0)
            {
                is_valid = true;
                printf("Command SKILL diterminasi. Kembali ke turn.\n");
                // Selesai
            }
            else
            {
                printf("Tetot! Input invalid. Mohon masukkan nomor skill yang tertera (misal '1').");
            }
        }
    }       
}

// DEFINISI FUNGSI PROSEDUR TIAP SKILL
void PintuGaKemanaSaja(player* P) {
    //Pintu gak kemana mana
    if (Search(skill(*P), 1) != Nil){
        BUFF(buff(*P), 1) = true;
        DelP(&skill(*P), 1);
    }
}

void MesinWaktu (State *state, player *P, int MaxRoll, int JumPetak, TabPeta peta, TabTP arrtp) {
    // Skill ke-2
    // KAMUS LOKAL
    int next_idx, rolled, input, player_idx, nEff;
    boolean is_valid = false;
    time_t t;
    player *chosenP;
    // ALGORITMA
    player_idx = GetPlayerIdx((*state), (*P));
    nEff = GetLastIdx(*state);
    srand((unsigned) time(&t)); // Inisialisasi rand()
    rolled = (rand() % (MaxRoll)) + 1;  // roll
    printf("%s me-roll %d. Siapa yang mau dimajukan %d petak?\n", nama(*P), rolled, rolled);
    print_players((*state), (*P));
    while (!is_valid)   // input user masuk
    {
        scanf("Masukkan pemain-ke: %d", input);
        input--;    // idx array = urutan - 1
        if (valid(input, player_idx, nEff))
        {
            is_valid = true;
        }
        else
        {
            printf("Tetot! Input invalid. Masukkan '1', '2' sesuai nomor.\n");
        }
    }
    // input valid
    (*chosenP) = (*state).TabPlayer[input]; // Pemrosesan maju
    next_idx = (current_petak(*chosenP)) + rolled;
    if (next_idx >= JumPetak)
    {
        if (!IsPetakTerlarang(peta, next_idx))
        {
            maju(chosenP, next_idx, peta, arrtp);
        }
        else
        {
            printf("%s akan mendarat di tempat terlarang - tidak boleh!\nMesin waktu error, mogok, dan batal dipakai.\n", nama(*chosenP));
        }
    }
    else
    {
        printf("%s akan mendarat di luar map - tidak boleh!\nMesin waktu error, mogok, dan batal dipakai.\n", nama(*chosenP));
    }
}

void BalingBalingJambu (State *state, player *P, int MaxRoll, int JumPetak, TabPeta peta, TabTP arrtp) {
    // Skill ke-3
    // KAMUS LOKAL
    int past_idx, rolled, input, player_idx, nEff;
    boolean is_valid = false;
    time_t t;
    player *chosenP;
    // ALGORITMA
    player_idx = GetPlayerIdx((*state), (*P));
    nEff = GetLastIdx(*state);
    srand((unsigned) time(&t)); // Inisialisasi rand()
    rolled = (rand() % (MaxRoll)) + 1;  // roll
    printf("%s me-roll %d. Siapa yang mau dimundurkan %d petak?\n", nama(*P), rolled, rolled);
    print_players((*state), (*P));
    while (!is_valid)   // input user masuk
    {
        scanf("Masukkan pemain-ke: %d", input);
        input--;    // idx array = urutan - 1
        if (valid(input, player_idx, nEff))
        {
            is_valid = true;
        }
        else
        {
            printf("Tetot! Input invalid. Masukkan '1', '2' sesuai yang ditampilkan.\n");
        }
    }
    // input valid dan sudah didecrement 1
    (*chosenP) = (*state).TabPlayer[input]; // Pemrosesan maju
    past_idx = (current_petak(*chosenP)) - rolled;
    if (past_idx >= 0)
    {
        if (!IsPetakTerlarang(peta, past_idx))
        {
            mundur(chosenP, past_idx, peta, arrtp);
        }
        else
        {
            printf("%s akan mendarat di tempat terlarang - tidak boleh!\nMesin waktu error, mogok, dan batal dipakai.\n", nama(*chosenP));
        }
    }
    else
    {
        printf("%s akan mendarat di luar map - tidak boleh!\nMesin waktu error, mogok, dan batal dipakai.\n", nama(*chosenP));
    }
}

void CerminPengganda(player *P){
    //Cermin pengganda
    if (Search(skill(*P), 4) != Nil && NbElmt(skill(*P)) < 9) {
        DelP(&skill(*P), 4);
        gacha_skill(&skill(*P));
        gacha_skill(&skill(*P));
    }
}

void SenterPembesarHoki(player *P){
    // Senter Pembesar Hoki
    if (Search(skill(*P), 5) != Nil) {
        DelP(&skill(*P), 5);
        BUFF(buff(*P), 3);
    }
}
void SenterPengecilHoki(player *P){
    // Senter Pengecil Hoki
    if (Search(skill(*P), 6) != Nil) {
        DelP(&skill(*P), 6);
        BUFF(buff(*P), 4);
    } 
}
void MesinTukar(State *state, player *P) {
    int input, player_idx, nEff, temp;
    boolean is_valid = false;
    player *chosenP;
    // ALGORITMA
    player_idx = GetPlayerIdx((*state), (*P));
    nEff = GetLastIdx(*state);
    printf("Siapa yang mau ditukar posisinya denganmu?\n");
    print_players((*state), (*P));
    while (!is_valid)   // input user masuk
    {
        scanf("Masukkan pemain-ke: %d", input);
        input--;    // idx array = urutan - 1
        if (valid(input, player_idx, nEff))
        {
            is_valid = true;
        }
        else
        {
            printf("Tetot! Input invalid. Masukkan '1', '2' sesuai yang ditampilkan.\n");
        }
    }
    (*chosenP) = (*state).TabPlayer[input];
    int tmp = (*chosenP).current_petak;
    (*chosenP).current_petak=(*P).current_petak ;
    (*P).current_petak = temp;
    printf("Berhasil menukar posisi!\n");
}

// DEFINISI FUNGSI PROSEDUR TAMBAHAN
void print_players (State state, player cplayer) {
    // KAMUS
    int i = 1;
    // ALGORITMA
    while (i <= state.Neff)
    {
        if (state.TabPlayer[i].nama != cplayer.nama)
        {
            printf("    %d. %s\n", (i + 1), cplayer.nama);
        }
        i++;
    }
    // i > Neff
}

boolean valid (int idx, int player_idx, int nEff) {
    // KAMUS
    boolean is_in_array = false;
    int i = 0;
    // ALGORITMA
    while (i < nEff)
    {
        if (idx = i)
        {
            is_in_array = true;
        }
        i++;
    }
    return is_in_array && (idx != player_idx);
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