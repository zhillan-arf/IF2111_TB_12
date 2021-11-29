/*
    TUBES IF2111 K2 KELOMPOK 12
    PERMAINAN "SNEK AND MADDER"
    Versi: 2021-11-27
*/

// DEKLARASI MODULE2 DASAR
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// DEKLARASI ADT
#include "ADT/state/state.h"
#include "ADT/player/player.h"
#include "ADT/stack_state/stack_state.h"
#include "ADT/array_buff/array_buff.h"
#include "ADT/list/list.h"

// DEKLARASI COMMAND
#include "commands/inspect/inspect.h"
#include "commands/skill/gacha_skill.h"
#include "commands/roll/roll.h"
#include "commands/skill/skills.h"

// DEKLARASI LAIN
#include "console.h"
#include "boolean.h"
#include "misc/convert.h"
#include "misc/start_display.h"

// ALGORITMA PROGRAM UTAMA
int main() {
    // KAMUS
    int choice, i, JumPetak, MaxRoll, JumTP, JumPlayer, TurnPemainKe;
    boolean TakeUndo, HaveRolled, EndTurn, WinnerFound, EndGame, is_valid = false;
    char InputCmd[MAXC], in_choice[MAXC], file_dir[MAXC];
    TabPeta Peta;
    TabTP arrTP;
    player WinnerPlayer;
    Stack stackState;
    State currentState;

    // ALGORITMA
    print_start();
    
    // Inisialisasi State Permainan
    CreateEmptyStack(&stackState);
    MakeEmpty(&currentState);
    while (!is_valid)
    {
        printf("\n>> ");
        scanf("%s", in_choice);
        choice = str_to_int_idx0(in_choice);
        switch (choice) 
        {
            case 1:
                is_valid = true;
                insert_file(file_dir);
                JumPlayer = insert_jumplayer();
                ReadConfigFile(
                    &JumPetak, 
                    &MaxRoll, 
                    &JumTP, 
                    &Peta, 
                    &arrTP, 
                    file_dir
                );
                SetNeff(&currentState, JumPlayer);
                SetRound(&currentState, 0);
                insert_players(&currentState, JumPlayer);
                printf("\nStarting the game...\n");
                delay(1);
                EndGame = false;
                break;

            case 2:
                is_valid = true;
                EndGame = true;
                printf("See you later!");
                exit(0);
                break;

            case 3:
                print_help();
                break;

            default: 
                printf("Tetot! Invalid input, masukkan '3' untuk HELP!\n");
                break;
        }
    }

    printf("------------------------- GAME DIMULAI! -------------------------\n");
    while (!EndGame) {
        // Mulai ROUND
        // Inisialisai permulaaan ROUND
        TurnPemainKe = 1;
        TakeUndo = false;
        HaveRolled = false;
        EndTurn = false;
        WinnerFound = false;
        currentState.Round++;
        printf("\nMemulai ROUND ke-%d...\n", currentState.Round);
        delay(1);
        while ((TurnPemainKe != (JumPlayer+1)) && (!TakeUndo) && (!EndGame)) {
            // Reset variable
            TakeUndo = false;
            HaveRolled = false;
            EndTurn = false;
            //Mulai TURN tiap pemain
            printf("\n********** GILIRAN: %s! **********\n", currentState.TabPlayer[TurnPemainKe - 1].nama);
            //Memperlihatkan peta setiap pemain
            printf("State of the World (posisi pemain ditandai '*'):\n");
            for (i = 0; i < JumPlayer; i++) {
                DisplayPetaPemain (
                    Peta, 
                    currentState.TabPlayer[i].current_petak, 
                    JumPetak, 
                    currentState.TabPlayer[i].nama
                );
            }
            gacha_skill(&currentState.TabPlayer[TurnPemainKe - 1].skill, MaxRoll);
            while ((!EndTurn) && (!WinnerFound) && (!TakeUndo)) {
                printf("\nMasukkan command: ");
                scanf("%s", &InputCmd);
                // Kondisional tergantung InputCmd
                if (compareString(InputCmd,"SKILL")) 
                {
                    if (HaveRolled) {
                        printf("\nOi! Kamu sudah ROLL! SKILL tidak lagi bisa diakses.");
                    } else {
                        menuSkill (
                            &currentState, 
                            &currentState.TabPlayer[TurnPemainKe - 1], 
                            MaxRoll, 
                            JumPetak, 
                            Peta, 
                            arrTP, 
                            namaSkill
                        );
                    } 
                } 
                else if (compareString(InputCmd,"MAP")) 
                {
                    for (int i = 0; i < JumPlayer; i++) {
                        DisplayPetaPemain (
                            Peta, 
                            currentState.TabPlayer[i].current_petak, 
                            JumPetak, 
                            currentState.TabPlayer[i].nama
                        );
                    } // Seluruh pemain selesai di-display
                } 
                else if (compareString(InputCmd,"BUFF")) 
                {
                    displayBuff(
                        buff(currentState.TabPlayer[TurnPemainKe - 1]), 
                        namaBuff, 
                        currentState.TabPlayer[TurnPemainKe - 1].nama
                    ); // namaBuff berasal dari array_buff.h
                } 
                else if (compareString(InputCmd,"INSPECT")) 
                {
                    inspect(Peta, arrTP, JumPetak);
                } 
                else if (compareString(InputCmd,"UNDO")) 
                {
                     if (IsEmptyStack(stackState)) {
                        // Reset state ke sebelum round 1
                        SetRound(&currentState,0);
                        for (int i=0;i < JumPlayer;i++) {
                            currentState.TabPlayer[i].current_petak=1;
                            CreateEmpty(&currentState.TabPlayer[i].skill);
                            ResetTabBuff(&currentState.TabPlayer[i].buff);
                        }
                    } else {
                        Pop(&stackState, &currentState); // currentState diganti ke state ronde sebelumnya
                    }
                    TakeUndo = true; //Keluar loop, dan mulai lagi ke pemain pertama
                } 
                else if (compareString(InputCmd, "ROLL")) 
                {
                    if (!HaveRolled){
                        roll (
                            MaxRoll, 
                            Peta, 
                            arrTP, 
                            JumPetak,
                            &currentState.TabPlayer[TurnPemainKe - 1]
                        );
                        HaveRolled = true;
                    } else {
                        printf("Oi, kamu sudah melakukan ROLL, jangan maruk!\n");
                    }
                    
                    if (currentState.TabPlayer[TurnPemainKe - 1].current_petak == JumPetak) { 
                        // Player menang
                        WinnerPlayer = currentState.TabPlayer[TurnPemainKe - 1];
                        WinnerFound = true;
                    }
                } 
                else if (compareString(InputCmd, "ENDTURN")) 
                {
                    if (!HaveRolled) {
                        printf("ENDTURN hanya dapat digunakan setelah ROLL.\n");
                    } else {
                        EndTurn = true;
                    }
                } 
                else 
                {
                    printf("Tetot! Inputan tidak valid. ");
                    print_help2();
                }
            }
            // TURN player ke-sekian selesai

            if (WinnerFound) { 
                EndGame = true;
                // GAME selesai...
            }
            else {
                TurnPemainKe++;
                // Mulai TURN player ke-berikutnya
            }
        }
        // ROUND ke-sekian selesai
        if (!TakeUndo) {
            Push(&stackState, currentState);   // Push state ke stack saat ronde selesai
        }
    }
    // ...GAME selesai
    printf("\n------------------------- GAME BERAKHIR -------------------------\n");
    printf("%s telah mencapai ujung dan memenangkan game!\n\n", currentState.TabPlayer[TurnPemainKe - 1].nama);
    displayPeringkat(currentState, JumPlayer);
    printf("\nTerima kasih telah memainkan 'SNEK AND MADDER'! Bye-onara!\n");
    return 0;   // EOP
}


// DEFINISI FUNGSI PROSEDUR TAMBAHAN
void print_start() {
    // ALGORITMA
    start_display();
    delay(1);
    printf("\nBy Mobita & Borakemon (2021). All rights reserved.\nLoading...");
    delay(1);
    printf("\n/=============================/\n");
    printf("       'SNEK AND MADDER'\n");
    printf("/=============================/\n");
    printf("             MENU             \n");
    printf("1) New Game\n");
    printf("2) Exit\n");
    printf("3) Help\n");
}


void print_help() {
    // ALGORITMA
    printf("Masukkan '1' untuk mulai bermain.\n");
    printf("Masukkan '2' untuk keluar dari permainan.\n");
}

void print_help2() {
    // ALGORITMA
    printf("List Command:\n");
    printf("SKILL   : Menampilkan daftar skill yang dimiliki dan menanyakan apakah ingin menggunakan skill\n");
    printf("MAP     : Menampilkan state peta saat ini\n");
    printf("BUFF    : Menampilkan daftar buff yang dimiliki\n");
    printf("INSPECT : Meminta suatu peta X dan melihat apakah tersedia teleporter di sana\n");
    printf("ROLL    : Memutar dadu dan mendapatkan nilai di antar 1 dan MaxRoll. Pemain memilih antara maju dan mundur\n");
    printf("ENDTURN : Digunakan untuk mengakhiri giliran permainan. Hanya dapat digunakan setelah pemain bergerak (ROLL)\n");
    printf("UNDO    : Digunakan untuk mengulang suatu ronde dan mengembalikan permainan ke state akhir satu ronde sebelumnya\n");
}

void insert_file (char *file_dir) {
    // KAMUS
    boolean is_valid = false;
    char filename[MAXC];
    // ALGORITMA
    while (!is_valid)
    {
        printf("Masukkan nama file : ");
        scanf("%s", filename);
        strcpy(file_dir, "data/");
        strcat(file_dir, filename);
        printf("Mencari file...\n");
        delay(1);
        if (access(file_dir, F_OK) != -1)
        {
            printf("File ditemukan di %s.\n\n", file_dir);
            is_valid = true;
        }
        else
        {
            printf("Tetot! File di %s tidak ditemukan, coba cek lagi!\n", file_dir);
        }
    }
}

int insert_jumplayer() {
    // KAMUS LOKAL
    boolean is_valid = false;
    int JumPlayer;
    char in_JumPlayer[MAXC];
    // ALGORITMA
    while (!is_valid)
    {
        printf("Masukkan jumlah pemain : ");
        scanf("%s", in_JumPlayer);
        JumPlayer = str_to_int_idx0(in_JumPlayer);
        if (1 <= JumPlayer && JumPlayer <= 4)
        {
            is_valid = true;
        }
        else if (JumPlayer > 4)
        {
            printf("Maksimum 4 pemain. Kalau kebanyakan, gaakan selesai2!\n");
        }
        else
        {
            printf("Tetot! Input invalid. Mohon masukkan antara 1 hingga 4.\n");
        }
    }
    return JumPlayer;
}

void insert_players(State *currentState, int JumPlayer)  {
    // KAMUS LOKAL
    char *playername;
    int i;
    // ALGORITMA
    for (i = 0; i < JumPlayer; i++) 
    {
        printf("\nMasukkan username pemain ke-%d : ", i + 1);
        playername = (char*) malloc(MAXC * sizeof(char));
        getchar();
        scanf("%[^\n]", playername);
        (*currentState).TabPlayer[i].nama = playername;
        (*currentState).TabPlayer[i].current_petak = 1;
        CreateEmpty(&(*currentState).TabPlayer[i].skill);
        ResetTabBuff(&(*currentState).TabPlayer[i].buff);
        printf(">> %s siap bermain!\n", (*currentState).TabPlayer[i].nama);
    }
}


void displayPeringkat(State currentState, int JumPlayer) {
    // KAMUS LOKAL
    State orderState;
    player maxPlayer;
    int ctr, i, i_max;
    // ALGORITMA
    for (ctr = 0; ctr < JumPlayer; ++ctr)
    {
        i = 0;
        maxPlayer = currentState.TabPlayer[0];
        for (i = 0; i < JumPlayer; ++i)
        {
            if (currentState.TabPlayer[i].current_petak >= maxPlayer.current_petak)
            {
                maxPlayer = currentState.TabPlayer[i];
                i_max = i;
            }
        }
        // Local maxPlayer is found
        orderState.TabPlayer[ctr] = maxPlayer;
        currentState.TabPlayer[i_max].current_petak = -1;   // Burn yang udah masuk
    }
    // orderState selesai terisi, terurut berdasar current_petak
    printf("-------------------------- LEADERBOARD --------------------------\n");
    for (i = 1; i <= JumPlayer; ++i)
    {
        printf("    %d. %s (petak %d).", i, orderState.TabPlayer[i - 1].nama, orderState.TabPlayer[i - 1].current_petak);
        if (i == 1)
        {
            printf(" <-- orz");
        }
        printf("\n");
    }
}

int charToInt(char c) {
	int num = 0;
	num = c - '0';
	return num;
}

void KataToTabPeta(Kata TabKata, TabPeta *P){
    for(int i = 1; i <= TabKata.Length; i++){
        (*P).Peta[i] = TabKata.TabKata[i];
    }
}

int strToInt(char s[]){
    int i, n=0;
    for(i=1; s[i]>='0' && s[i]<='9'; i++){
        n = 10*n + (s[i] - '0');
    }
    return n;
}

void ReadConfigFile(int *JPetak, int *MRoll, int *JTP, TabPeta *P, TabTP *ARTP, char file_dir[]){
    // ALGORITMA
    //Menyimpan value jumlah petak ke sebuah variabel
    STARTKATA(file_dir);
    *JPetak = strToInt(CKata.TabKata);
    // Menyimpan peta ke sebuah tabel
    ADVKATA();
    MakeEmptyPeta(P);
    KataToTabPeta(CKata, P);
    //Menyimpan value jumlah maksimal roll ke sebuah variabel
    ADVKATA();
    *MRoll = strToInt(CKata.TabKata);
    //Menyimpan value jumlah teleport ke sebuah variabel
    ADVKATA();
    *JTP = strToInt(CKata.TabKata);
    //Membuat tabel untuk keperluan informasi teleport
    int KeluarTP, MasukTP;
    MakeEmptyArrTP(ARTP);
    for (int i = 0; i < (*JTP); i++) {
        ADVKATA();
        if (CKata.Length == 1){
            MasukTP = charToInt(CKata.TabKata[1]);
        } else if (CKata.Length == 2){
            MasukTP = charToInt(CKata.TabKata[1]) * 10 + charToInt(CKata.TabKata[2]);
        }
        ADVKATA();
        if (CKata.Length == 1){
            KeluarTP = charToInt(CKata.TabKata[1]);
        } else if (CKata.Length == 2){
            KeluarTP = charToInt(CKata.TabKata[1]) * 10 + charToInt(CKata.TabKata[2]);
        }
        InsertTP(ARTP, KeluarTP, MasukTP);
    }
}

boolean compareString(char a[], char b[]){
    int i = 0;
    boolean isNEq = false;
    while(a[i] != '\0' && b[i] != '\0'){
        if (a[i] != b[i]){
            isNEq = true;
            break;
        }
        i++;
    }
    return (isNEq == false);
}
