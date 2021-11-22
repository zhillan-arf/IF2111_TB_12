/*
    TUBES IF2111 K2 KELOMPOK 12
    PERMAINAN "<LOREM IPSUM DOLOR>"
    Versi: 2021-11-22 19:00
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

/* RECENT UPDATEs &/ Qs
1. Aight beda2 puts (otomatis ngasih 1 buah \n) dan printf (nggak
ngasih) tbh bikin ambigu, jadi harus mikir kayak gimana \n nya bakal 
keluar di temrinal, diganti jadi printf semua gapapa ya :kekw:
2. Invalid mending ga usah ngulang Menunya ga sih (?) biar ga spam (?), 
kan tinggal scroll atas buat liat (?) jadi loop nya pindah ke bawah menu
3. mesinkar dan mesinkata diubah2 biar bisa nerima inputan filename yaa
4. Ner uga tapi: mesinkar sama tempat nyimpen file kan beda directory, itu
perlu penanganan khusus ga sih?
5. exit(0) tuh fungsinya apa sih?
6. Kalo yang di sini dah oke pasti, tolong deletin main_menu.c
7. Tbh inisialisasi2 di bawah lebih baik digabung sama bagian atas, soalnya
kan harus input2in nama2 players dsb
8. semua currloc1 diganti jadi sehingga ngakses player sekarang lagi siapa
*/

// ALGORITMA PROGRAM UTAMA
int main() {
    // KAMUS
    int JumPetak, MaxRoll, JumTP, choice, i, JumPlayer;
    boolean TakeUndo, HaveRolled, EndTurn, WinnerFound, EndGame, is_valid = false;
    TabPeta Peta;
    TabTP arrTP;
    player WinnerPlayer;
    char *filename;
    Stack stackState;
    State currentState;

    // ALGORITMA
    // MULAI PERMAINAN "<TBD>!"
    printf("\n/============================/\n");
    printf("             MENU             \n");
    printf("/============================/\n");
    printf("1) New Game\n");
    printf("2) Exit\n");
    printf("3) Help\n");
    printf("/============================/\n");

    // Inisialisasi State Permainan
    CreateEmptyStack(&stackState);
    MakeEmpty(&currentState);

    // Loop input
    while (!is_valid)
    {
        printf("\n>> ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                // 1. INPUT nama file
                printf("Enter a file name : ");
                scanf("%s", filename);
                // 2. INPUT jumlah player
                printf("Enter number of player : ");
                scanf("%d", &JumPlayer);
                ReadConfigFile(&JumPetak, &MaxRoll, &JumTP, &Peta, &arrTP, filename);
                // 3. INPUT nama-nama player
                SetNeff(&currentState, JumPlayer);
                /* Disini harusnya ada fungsi buat mengisi currentState dengan 
                player. (Mungkin dibuat di ADT player(?))
                Misal:
                for (int i=0;i < JumPlayer;i++) 
                {
                     
                    <scanf untuk nama player saat ini, yang jelas deklarasiin dulu
                    var nya>
                    SetPlayer(&currentState, i, <variabel isi nama player>);
                }
                */
                // 4. INPUT2 selesai.
                printf("\nStarting the game...");
                EndGame = false;
                break;
                exit(0);    // eh ini apa :monkaHmm:

            case 2:
                printf("See you later!");
                exit(0);    // eh ini apa :monkaHmm:
            
            case 3:
                /* <Sesuatu sehingga display help. Mungkin
                di sinilah baru print lagi command2 yang tersedia,
                mayhaps dengan petunjuk format dll> */

            default: printf("Invalid Input!\n");
        }
    }

    printf("------------------------- GAME DIMULAI! -------------------------\n");

    while (!EndGame) {

        // Menyimpan value 1 sebagai turn pemain pertama. Karena tiap ronde pasti dimulai pemain pertama.
        int TurnPemainKe = 1;

        //Untuk menyimpan hasil roll dari pemain. Di-set ke 0 ketika ganti giliran pemain
        int Roll = 0;

        //Untuk menyimpang masukan command
        char InputCmd[10];

        //Untuk mengetahui apakah ada pemain yang memanggil UNDO. Jika ya maka akan true dan kembali ke state sebelumnya
        TakeUndo = false;

        //Untuk mengetahui apakah roll sudah dilakukan sehingga dapat endturn
        HaveRolled = false;

        //Untuk mengetahui apakah endturn sudah dilakukan
        EndTurn = false;

        //Untuk mengetahui apakah sudah ada yang sampai ujung peta
        WinnerFound = false;

        //Setiap awal ronde harus memperlihatkan peta setiap pemain
        for (int i = 0; i < JumPlayer; i++) //Ini JumPlayer menyesuaikan yang ada di ADT Player
            DisplayPetaPemain(Peta, currentState.TabPlayer[i].current_petak, JumPetak);

        //Mulai turn tiap pemain
        while((TurnPemainKe != (JumPlayer+1)) && (!TakeUndo) && (!EndGame)){
            gacha_skill(&currentState.TabPlayer[TurnPemainKe - 1].skill);
            printf("********** GILIRAN %s! **********\n", currentState.TabPlayer[TurnPemainKe - 1].nama);
            printf("Masukkan command: ");
            scanf("%s", &InputCmd);
            
            while ((!EndTurn) && (!WinnerFound) && (!TakeUndo)){
                
                if (compareString(InputCmd,"SKILL")) {
                    // Bagian Vito, Annel, dan Zhillan
                    if (HaveRolled) {
                        printf("Anda tidak dapat menggunakan skill karena sudah melakukan roll!");
                    } else {
                        //Ini diisi display skill dan kemanisme penggunaan skill dan penghapusan skill sesuai ADT Skill!
                        menuSkill(&currentState, &currentState.TabPlayer[TurnPemainKe - 1], MaxRoll, JumPetak, Peta, arrTP, namaSkill);
                    } 
                } else if (compareString(InputCmd,"MAP")) {
                    for(int i = 0; i < JumPlayer; i++){
                        DisplayPetaPemain(Peta, currentState.TabPlayer[i].current_petak, JumPetak);
                    }
                } else if (compareString(InputCmd,"BUFF")) {
                    displayBuff(buff(currentState.TabPlayer[TurnPemainKe - 1]), namaBuff); // namaBuff berasal dari array_buff.h
                } else if (compareString(InputCmd,"INSPECT")) {
                    inspect(&Peta);

                } else if (compareString(InputCmd,"UNDO")) {
                    // Bagian Modan
                    Pop(&stackState, &currentState); // currentState diganti ke state ronde sebelumnya
                    //Balik ke state sebelumnya.
                    TakeUndo = true; //Keluar loop, dan mulai lagi ke pemain pertama karena variabel TurnPemainKe kembali di set ke 1

                } else if (compareString(InputCmd, "ROLL")) {
                    roll(&Roll, MaxRoll, Peta, arrTP, JumPlayer, &currentState.TabPlayer[TurnPemainKe - 1]);
                    HaveRolled = true;
                    if (currentState.TabPlayer[TurnPemainKe - 1].current_petak == JumPetak) { 
                        // Player menang
                        WinnerPlayer = currentState.TabPlayer[TurnPemainKe - 1];
                        WinnerFound = true;
                    }
                } else if (compareString(InputCmd, "ENDTURN")) {
                    //Bagian Modan
                    if (!HaveRolled) {
                        //Kasitau harus roll dulu
                        printf("ENDTURN hanya dapat digunakan setelah ROLL");
                    } else {
                        EndTurn = true;
                    }
                } else {
                    printf("Masukan command tidak valid! Silahkan coba lagi.\n");

                }
                printf("Masukkan command: ");
                scanf("%s", &InputCmd);
            }


            if (WinnerFound) { //Ini harus loc pemain yang sedang turn-nya. Sesuaikan dengan ADT Player
                printf("------------------------- GAME BERAKHIR -------------------------");
                printf("Mobita telah mencapai ujung.\nPemenang game ini adalah Mobita\n");
                EndGame = true;
            }

            TurnPemainKe++; //Lanjut turn ke pemain selanjutnya
            //(KOMEN: ini nggak kasih mod sesuai jumlah player? Turn kan, bukan round? -dialah_zhillanku)
            //tapi buat apa kasih mod??  -umar
        }

        //Ini gini gak si harusnya? -umar
        if (!TakeUndo) {
            Push(&stackState, currentState);   // Push state ke stack saat ronde selesai
        }

    }

    //Ini nanti bisa ditaro di prosedur sendiri. Tapi karna masih harus diotak-atik, aku masih taro disini.
    printf("------------------------- PERINGKAT PEMAIN -------------------------");
    char ExNamaPemain[20] = "Itti Hililintir"; //Misal. Harusnya sesuai array daftar nama pemain
    for(int i = 1; i <= JumPlayer; i++){
        //printf("%d. %s [Pemain berada di petak %d]", i, ExNamaPemain, currlocp1);
         /*Ini harusnya format %s diisi berdasarkan array pemain yang sudah di-sort
         berdasarkan currloc. Seharusnya ada di ADT Pemain*/
    }

    return 0;
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