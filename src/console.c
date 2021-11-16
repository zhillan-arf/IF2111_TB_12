/*
    TUBES IF2111 K2 KELOMPOK 12
    PERMAINAN "<LOREM IPSUM DOLOR>"
    Versi: 2021-11-15 11:30
*/

/* INI MASIH DALAM BENTUK PERCOBAAN DAN MASIH BELUM RAPIH. MOHON SAAT MENGERJAKAN JANGAN SAMPAI BERANTAKAN AGAR NANTI SAAT
SUDAH JADI TIDAK PERLU ADA BANYAK YANG HARUS DIRAPIHKAN LAGI. DISINI MASIH PAKAI INT MAIN() UNTUK KEPERLUAN PENGETESAN. SEHARUSNYA
YANG ADA PADA INT MAIN() DIJADIKAN SUATU FUNGSI SEPERTI MULAI_GAME()*/

// DEKLARASI MODULE2 DASAR
#include <stdlib.h>
#include <stdio.h>
#include "console.h"

// DEKLARASI COMMAND
#include "commands/inspect.h"
#include "commands/gacha_skill.h"
#include "commands/roll.h"

int JumPetak, MaxRoll, JumTP;
TabPeta Peta;
TabTP arrTP;

int main(){

    ReadConfigFile(&JumPetak, &MaxRoll, &JumTP, &Peta, &arrTP);

    //Ini untuk keperluan contoh saja
    List LSkillP1;
    List LSkillP2;
    CreateEmpty(&LSkillP1);
    CreateEmpty(&LSkillP2);


    int currlocp1 = 1; //Misalkan ini posisi pemain 1
    int currlocp2 = 1; //Misalkan ini posisi pemain 2
    // Seharusnya loc pemain ada disimpan sesuai ADT Player

    int JumlahPemain = 5; //Misal. Usahakan pada ADT Player, indeks pemainnya dari 1-JumlahPeman (jangan dari 0);

    boolean EndGame = false;

    printf("------------------------- GAME DIMULAI -------------------------\n");

    while (!EndGame){
        // Menyimpan value 1 sebagai turn pemain pertama. Karena tiap ronde pasti dimulai pemain pertama.
        int TurnPemainKe = 1;

        //Untuk menyimpan hasil roll dari pemain. Di-set ke 0 ketika ganti giliran pemain
        int Roll = 0;

        //Untuk menyimpang masukan command
        char InputCmd[10];

        //Untuk mengetahui apakah ada pemain yang memanggil UNDO. Jika ya maka akan true dan kembali ke state sebelumnya
        boolean TakeUndo = false;

        //Setiap awal ronde harus memperlihatkan peta setiap pemain
        for (int i = 0; i < JumlahPemain; i++) //Ini JumlahPemain menyesuaikan yang ada di ADT Player
            DisplayPetaPemain(Peta, currlocp1, JumPetak); //Ini currloc menyesuaikan posisi player dgn masukan sesuai yang ada di ADT Player

        //Mulai turn tiap pemain
        while((TurnPemainKe != (JumlahPemain+1)) && (!TakeUndo) && (!EndGame)){

            // KOMEN: sesuai yang kemaren2 ngobrol, bagian penambahan skill ku ambil yaa -dialah_zhillanku
            // gacha_skill(&<LSkillCurrentPlayer>)

            printf("********** GILIRAN PEMAIN KE-%d **********\n", TurnPemainKe);
            printf("Masukkan command: ");
            scanf("%s", &InputCmd);
            while (!compareString(InputCmd, "ROLL")){
                /* KOMEN -dialah_zhillanku
                1. Ini kan pengecekan berdasarkan value InputCmd. Lebih baik pake switch case daripada
                spageti if else kayak YanderDev nggak sih?
                2. AFAIK, C cuba membaca 1 kali deklarasi variabel. Jadi kalo kita menaruh deklarasi variabel
                di loop is uh... tbh ga tau sih, tapi bakal ga baik ga sih 
                3. Hal2 yang bisa taroh file lain taroh file lain aja ga sih :KEKW: terutama fungsi2 di bawah. Ntar 
                kita tanya aja ke Tuan Mor gimana cara pake Makefile (toh cepet atau lambat kita bakal sering pake), 
                ku dah nyoba Makefile tapi masih gagal total terus */
                if (compareString(InputCmd,"SKILL")){
                    // Bagian Vito, Annel, dan Zhillan
                    // KOMEN: Hal2 skill yang disini sebanyak mungkin taroh tempat/file terpisah, jangan di console -dialah_zhillanku
                    int MasukanSkill;
                    if (NbElmt(LSkillP1) == 0){ //Ini penulisan LSkillP1 harusnya sesuai list skill player yang sedang turn pada ADT Player terkait list player
                        printf("Kamu tidak memiliki skill!\n");
                    } else {
                        printf("Kamu memiliki skill:\n");
                        for (int i = 0; i < NbElmt(LSkillP1); i++){ //Ini penulisan LSkillP1 harusnya sesuai list skill player yang sedang turn pada ADT Player terkait list player
                            printf("%d. [INFO ELEMEN LIST INDEKS KE-i]\n", (i+1)); //Harus sesuai ADT Player untuk mendapat list player yang sedang turn dan ADT ListSkill untuk displayList
                        }
                        printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\nMasukkan skill: ");
                        scanf("%d", &MasukanSkill);
                        while ((MasukanSkill < -(NbElmt(LSkillP1))) && (MasukanSkill > NbElmt(LSkillP1))){ //Ini penulisan LSkillP1 harusnya sesuai list skill player yang sedang turn pada ADT Player terkait list player
                            printf("Masukan tidak valid!\nSilahkan coba lagi.\nMasukkan skill: ");
                            scanf("%d", &MasukanSkill);
                        }
                        if (MasukanSkill > 0) {
                            printf("[NAMA PEMAIN YANG SEDANG GILIRAN] memakai skill [INFO ELEMEN LIST INDEKS KE-MasukanSkill]\n"); //Harus sesuai ADT Player untuk mendapatkan list player yang sedang turn dan ADT ListSkill untuk display skill ke-MasukanSkill
                            printf("[EFEK DARI SKILL YANG DIGUNAKAN]\n"); //Harus sesuai ADT skill dan kalo skill bonus tambahin scanf untuk masukan
                            //MENGAKTIFKAN BUFF (JADIIN TRUE) BERDASARKAN SKILL YANG DIGUNAKAN MENGIKUTI ADT BUFF
                            //DELETE SKILL YANG DIGUNAKAN PADA LIST PLAYER YANG MENGGUNAKANNYA
                        } else if (MasukanSkill < 0) {
                            printf("[NAMA PEMAIN YANG SEDANG GILIRAN] membuang skill [INFO ELEMEN LIST INDEKS KE-MasukanSkill]\n"); //Harus sesuai ADT Player untuk mendapatkan list player yang sedang turn dan ADT ListSkill untuk display skill ke-MasukanSkill
                            //DELETE SKILL YANG DIBUANG PADA LIST PLAYER YANG MENGGUNAKANNYA
                        } else if (MasukanSkill == 0) {
                            //Nothing happen (Balik ke masukin input)
                        }

                    }
                } else if (compareString(InputCmd,"MAP")){
                    for(int i = 0; i < JumlahPemain; i++){
                        DisplayPetaPemain(Peta, currlocp1, JumPetak); //ini harusnya setiap pemain. Hanya perlu replace currlocp1 sesuai dengan ADT Player terkait posisi pemain
                    }

                } else if (compareString(InputCmd,"BUFF")){
                    //Bagian Annel
                    //Display buff untuk TurnPemainKe (berapa). Kalo true brarti buff aktif kalau false ga aktif. Harus sesuai ADT Buff

                } else if (compareString(InputCmd,"INSPECT")){
                    inspect(&Peta);
                    //Kasitau teleport, terlarang, atau kosong berdasarkan masukan InputInspect. Bisa pakai IsPetakTP, IsPetakTerlarang, IsPetakKosong dari ADT map & tp

                } else if (compareString(InputCmd,"UNDO")){
                    // Bagian Modan
                    //Balik ke state sebelumnya.
                    TakeUndo = true; //Keluar loop, dan mulai lagi ke pemain pertama karena variabel TurnPemainKe kembali di set ke 1

                } else {
                    printf("Masukan command tidak valid! Silahkan coba lagi.\n");

                }
                printf("Masukkan command: ");
                scanf("%s", &InputCmd);
            }
            // Input = "ROLL"
            // roll(&Roll, MaxRoll, Peta, JumlahPemain, &ADT Pemain);
            // KOMEN: 
            // 1. Kondisional-kondisional dah perintah maju mundur ku pindah ke roll -dialah_zhillanku
            // 2. Karena itu, variabel Roll mending jadiin boolean yang nentuin dah end game atau belum aja ga sih?
            
            if (currlocp1 == JumPetak){ //Ini harus loc pemain yang sedang turn-nya. Sesuaikan dengan ADT Player
                printf("------------------------- GAME BERAKHIR -------------------------");
                printf("Mobita telah mencapai ujung.\nPemenang game ini adalah Mobita\n");
                EndGame = true;
            }

            TurnPemainKe++; //Lanjut turn ke pemain selanjutnya (KOMEN: ini nggak kasih mod sesuai jumlah player? Turn kan, bukan round? -dialah_zhillanku)
        }

    }

    //Ini nanti bisa ditaro di prosedur sendiri. Tapi karna masih harus diotak-atik, aku masih taro disini.
    printf("------------------------- PERINGKAT PEMAIN -------------------------");
    char ExNamaPemain[20] = "Itti Hililintir"; //Misal. Harusnya sesuai array daftar nama pemain
    for(int i = 1; i <= JumlahPemain; i++){
        printf("%d. %s [Pemain berada di petak %d]", i, ExNamaPemain, currlocp1);
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

void ReadConfigFile(int *JPetak, int *MRoll, int *JTP, TabPeta *P, TabTP *ARTP){

    //Menyimpan value jumlah petak ke sebuah variabel
    STARTKATA();
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