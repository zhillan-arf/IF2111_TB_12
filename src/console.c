/*
    TUBES IF2111 K2 KELOMPOK 12
    PERMAINAN "SNEK AND MADDER"
    Versi: 2021-11-22 23:00
*/

// DEKLARASI MODULE2 DASAR
#include <stdlib.h>
#include <stdio.h>
#include "console.h"
#include "ADT/state.h"
#include "ADT/player.h"
#include "ADT/stack_state.h"
#include "boolean.h"

// DEKLARASI COMMAND
#include "commands/inspect.h"
#include "commands/gacha_skill.h"
#include "commands/roll.h"
#include "commands/skills.h"
#include "commands/start_display.h"

// ALGORITMA PROGRAM UTAMA
int main() {
    // KAMUS
    int choice, i, JumPetak, MaxRoll, JumTP, JumPlayer, TurnPemainKe, Roll;
    boolean TakeUndo, HaveRolled, EndTurn, WinnerFound, EndGame, is_valid = false;
    char *filename, *InputCmd, *playername;
    TabPeta Peta;
    TabTP arrTP;
    player WinnerPlayer;
    Stack stackState;
    State currentState;

    // ALGORITMA
    // MULAI PERMAINAN "SNEK AND MADDER!"
    start_display();
    printf("\n/============================/\n");
    printf("  PERMAINAN 'SNEK AND MADDER'\n");
    printf("/============================/\n");
    printf("             MENU             \n");
    printf("1) New Game\n");
    printf("2) Exit\n");
    printf("3) Help\n");
    printf("/============================/\n");
    
    // Inisialisasi State Permainan
    CreateEmptyStack(&stackState);
    MakeEmpty(&currentState);
    currentState.Round = 0;
    // Loop input
    while (!is_valid)
    {
        printf("\n>> ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                // 1. INPUT nama file
                printf("Masukkan nama file : ");
                scanf("%s", filename);
                // 2. INPUT jumlah player
                printf("Masukkan jumlah pemain : ");
                scanf("%d", &JumPlayer);
                ReadConfigFile(&JumPetak, &MaxRoll, &JumTP, &Peta, &arrTP, filename);
                // 3. INPUT nama-nama player
                SetNeff(&currentState, JumPlayer);
                /* Disini harusnya ada fungsi buat mengisi currentState dengan 
                player. (Mungkin dibuat di ADT player(?))
                < Atribut2 state yag lain kayak round ke-berapa sekarang 
                juga harus diinisialisasi awal >
                */
                SetRound(&currentState, 1);
                for (int i = 0; i < JumPlayer; i++) {
                    printf("Masukkan nama pemain : ");
                    scanf("%s", &playername);
                    currentState.TabPlayer[i].current_petak = 1;
                    CreateEmpty(&currentState.TabPlayer[i].skill);
                    ResetTabBuff(&currentState.TabPlayer[i].buff);
                }
                // 4. INPUT2 selesai.
                printf("\nStarting the game...");
                EndGame = false;
                break;
            case 2:
                printf("See you later!");
            case 3:
                /* <Sesuatu sehingga display help. Mungkin
                di sinilah baru print lagi command2 yang tersedia,
                mayhaps dengan petunjuk format dll> */
                printf("Masukkan '1' untuk mulai bermain\n");
                printf("Masukkan '2' untuk keluar dari permainan\n");
                printf("List Command\n");
                printf("1) SKILL   : Menampilkan daftar skill yang dimiliki dan menanyakan apakah ingin menggunakan skill\n");
                printf("2) MAP     : Menampilkan state peta saat ini\n");
                printf("3) BUFF    : Menampilkan daftar buff yang dimiliki\n");
                printf("4) INSPECT : Meminta suatu peta X dan melihat apakah tersedia teleporter di sana\n");
                printf("5) ROLL    : Memutar dadu dan mendapatkan nilai di antar 1 dan MaxRoll. Pemain memilih antara maju dan mundur\n");
                printf("6) ENDTURN : Digunakan untuk mengakhiri giliran permainan. Hanya dapat digunakan setelah pemain bergerak (ROLL)\n");
                printf("7) UNDO    : Digunakan untuk mengulang suatu ronde dan mengembalikan permainan ke state akhir satu ronde sebelumnya\n");

            default: printf("Tetot! Invalid input, masukkan '3' untuk help\n");
        }
    }

    printf("------------------------- GAME DIMULAI! -------------------------\n");
    while (!EndGame) {
        // Mulai ROUND
        // Inisialisai permulaaan ROUND
        TurnPemainKe = 1;
        Roll = 0;
        TakeUndo = false;
        HaveRolled = false;
        EndTurn = false;
        WinnerFound = false;
        currentState.Round++;
        printf("Memulai ROUND ke-%d...", currentState.Round);
        //Memperlihatkan peta setiap pemain
        for (int i = 0; i < JumPlayer; i++) {
            DisplayPetaPemain(Peta, currentState.TabPlayer[i].current_petak, JumPetak);
        }
        while ((TurnPemainKe != (JumPlayer+1)) && (!TakeUndo) && (!EndGame)) {
            //Mulai TURN tiap pemain
            printf("********** GILIRAN %s! **********\n", currentState.TabPlayer[TurnPemainKe - 1].nama);
            gacha_skill(&currentState.TabPlayer[TurnPemainKe - 1].skill);
            while ((!EndTurn) && (!WinnerFound) && (!TakeUndo)) {
                printf("Masukkan command: ");
                scanf("%s", &InputCmd);
                // Kondisional tergantung InputCmd
                if (compareString(InputCmd,"SKILL")) {
                    if (HaveRolled) {
                        printf("Anda tidak dapat menggunakan skill karena sudah melakukan roll!");
                    } 
                    else {
                        menuSkill(&currentState, &currentState.TabPlayer[TurnPemainKe - 1], MaxRoll, JumPetak, Peta, arrTP, namaSkill);
                    } 
                } 
                else if (compareString(InputCmd,"MAP")) {
                    for (int i = 0; i < JumPlayer; i++) {
                        DisplayPetaPemain(Peta, currentState.TabPlayer[i].current_petak, JumPetak);
                    }
                    // Seluruh pemain selesai di-display
                } 
                else if (compareString(InputCmd,"BUFF")) {
                    displayBuff(buff(currentState.TabPlayer[TurnPemainKe - 1]), namaBuff); // namaBuff berasal dari array_buff.h
                } 
                else if (compareString(InputCmd,"INSPECT")) {
                    inspect(Peta, arrTP);
                } 
                else if (compareString(InputCmd,"UNDO")) {
                    Pop(&stackState, &currentState); // currentState diganti ke state ronde sebelumnya
                    //Balik ke state sebelumnya.
                    TakeUndo = true; //Keluar loop, dan mulai lagi ke pemain pertama karena variabel TurnPemainKe kembali di set ke 1
                } 
                else if (compareString(InputCmd, "ROLL")) {
                    roll(&Roll, MaxRoll, Peta, arrTP, JumPlayer, &currentState.TabPlayer[TurnPemainKe - 1]);
                    HaveRolled = true;
                    if (currentState.TabPlayer[TurnPemainKe - 1].current_petak == JumPetak) { 
                        // Player menang
                        WinnerPlayer = currentState.TabPlayer[TurnPemainKe - 1];
                        WinnerFound = true;
                    }
                } 
                else if (compareString(InputCmd, "ENDTURN")) {
                    if (!HaveRolled) {
                        printf("ENDTURN hanya dapat digunakan setelah ROLL");
                    } 
                    else {
                        EndTurn = true;
                    }
                } 
                else {
                    printf("Masukan command tidak valid! Silahkan coba lagi.\n");
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
    printf("------------------------- GAME BERAKHIR -------------------------");
    printf("%s telah mencapai ujung.\nPemenang game ini adalah %s\n", currentState.TabPlayer[TurnPemainKe - 1].nama, currentState.TabPlayer[TurnPemainKe - 1].nama);
    displayPeringkat(currentState, JumPlayer);
    printf("Terima kasih telah memenangkan permainan '<TBD!>'!\n");
    return 0;   // EOP
}


// DEIFNISI FUNGSI PROSEDUR TAMBAHAN
void displayPeringkat(State currentState, int JumPlayer) {
    // KAMUS LOKAL
    State orderState;
    player maxPlayer;
    int ctr = 0, i, i_max;
    // ALGORITMA
    while (ctr < JumPlayer)
    {
        i = 0;
        maxPlayer = currentState.TabPlayer[0];
        while (i < JumPlayer)
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
        ++ctr;
    }
    // orderState selesai terisi, terurut berdasar current_petak
    printf("------------------------- PERINGKAT PEMAIN -------------------------\n");
    for (i = 1; i <= JumPlayer; ++i)
    {
        printf("    %d. %s", i, orderState.TabPlayer[i - 1].nama);
        if (i == 1)
        {
            printf(" <- orz");
        }
        printf("\n");
    }
}


int charToInt(char c){
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

void ReadConfigFile(int *JPetak, int *MRoll, int *JTP, TabPeta *P, TabTP *ARTP, char *filename){

    //Menyimpan value jumlah petak ke sebuah variabel
    STARTKATA(filename);
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
    for (int i = 0; i < (*JTP); i++){
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