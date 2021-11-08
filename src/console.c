/* INI MASIH DALAM BENTUK PERCOBAAN DAN MASIH BELUM RAPIH. MOHON SAAT MENGERJAKAN JANGAN SAMPAI BERANTAKAN AGAR NANTI SAAT
SUDAH JADI TIDAK PERLU ADA BANYAK YANG HARUS DIRAPIHKAN LAGI. DISINI MASIH PAKAI INT MAIN() UNTUK KEPERLUAN PENGETESAN. SEHARUSNYA
YANG ADA PADA INT MAIN() DIJADIKAN SUATU FUNGSI SEPERTI MULAI_GAME()*/

#include <stdlib.h>
#include <stdio.h>
#include "console.h"

int JumPetak, MaxRoll, JumTP, KeluarTP, MasukTP;
TabPeta Peta;
TabTP arrTP;

int main(){

    //Menyimpan value jumlah petak ke sebuah variabel
    STARTKATA();
    JumPetak = strToInt(CKata.TabKata);

    // Menyimpan peta ke sebuah tabel
    ADVKATA();
    MakeEmptyPeta(&Peta);
    KataToTabPeta(CKata, &Peta);
    
    //Menyimpan value jumlah maksimal roll ke sebuah variabel
    ADVKATA();
    MaxRoll = strToInt(CKata.TabKata);

    //Menyimpan value jumlah teleport ke sebuah variabel
    ADVKATA();
    JumTP = strToInt(CKata.TabKata);

    //Membuat tabel untuk keperluan informasi teleport
    MakeEmptyArrTP(&arrTP);
    for (int i = 0; i < JumTP; i++){
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

        InsertTP(&arrTP, KeluarTP, MasukTP);
    }

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
        // Menyimpan value 1 sebagai turn pemain pertama
        int TurnPemainKe = 1;
        int Roll = 0;

        char InputCmd[10];
        int InputInspect;

        boolean TakeUndo = false;

        for (int i = 0; i < JumlahPemain; i++) //Ini JumlahPemain menyesuaikan yang ada di ADT Player
            DisplayPetaPemain(Peta, currlocp1, JumPetak); //Ini currloc menyesuaikan posisi player dgn masukan sesuai yang ada di ADT Player

        while((TurnPemainKe != (JumlahPemain+1)) && (!TakeUndo) && (!EndGame)){

            if (NbElmt(LSkillP1) != 10){ //Ini cuma harusnya ngisi skill pemain yang sedang turn-nya. Harus diisi sesuai ADT Skill & Player
                int SkillNum = rand() % 100;
                InsVLast(&LSkillP1, SkillNum);
            }

            printf("********** GILIRAN PEMAIN KE-%d **********\n", TurnPemainKe);
            scanf("Masukkan command: %s\n", &InputCmd);
            while (InputCmd != "ROLL"){
                if (InputCmd == "SKILL"){
                    // Bagian Vito, Annel, dan Zhillan
                    int MasukanSkill;
                    if (NbElmt(LSkillP1) == 0){ //Ini LSkillP1 harusnya sesuai masukan list skill pada ADT Player
                        printf("Kamu tidak memiliki skill!\n");
                    } else{
                        printf("Kamu memiliki skill:\n");
                        for (int i = 0; i < NbElmt(LSkillP1); i++){ //Ini LSkillP1 harusnya sesuai masukan list skill pada ADT Player
                            printf("%d. [INFO ELEMEN LIST INDEKS KE-i]\n", (i+1)); //Harus sesuai ADT Player
                        }
                        printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\n");
                        scanf("Masukkan skill: %d\n", &MasukanSkill);
                        while ((MasukanSkill < -(NbElmt(LSkillP1))) && (MasukanSkill > NbElmt(LSkillP1))){ //Ini LSkillP1 harusnya sesuai masukan list skill pada ADT Player
                            printf("Masukan tidak valid!\nSilahkan coba lagi.\n");
                            scanf("Masukkan skill: %d\n", &MasukanSkill);
                        }
                        if (MasukanSkill > 0) {
                            printf("[NAMA PEMAIN YANG SEDANG GILIRAN] memakai skill [INFO ELEMEN LIST INDEKS KE-MasukanSkill]\n"); //Harus sesuai ADT Player
                            printf("[EFEK DARI SKILL YANG DIGUNAKAN]\n"); //Harus sesuai ADT skill dan kalo skill bonus tambahin scanf untuk masukan
                            //MENGAKTIFKAN BUFF (JADIIN TRUE) BERDASARKAN SKILL YANG DIGUNAKAN MENGIKUTI ADT BUFF
                        } else if (MasukanSkill < 0) {
                            printf("[NAMA PEMAIN YANG SEDANG GILIRAN] membuang skill [INFO ELEMEN LIST INDEKS KE-MasukanSkill]\n"); //Harus sesuai ADT Player
                        } else if (MasukanSkill < 0) {
                            //Nothing happen
                        }

                    }
                } else if (InputCmd == "MAP"){
                    for(int i = 0; i < JumlahPemain; i++){
                        DisplayPetaPemain(Peta, currlocp1, JumPetak); //ini harusnya setiap pemain.
                    }

                }else if (InputCmd == "BUFF"){
                    //Bagian Annel
                    //Display buff untuk TurnPemainKe (berapa). Kalo true brarti buff aktif kalau false ga aktif. Harus sesuai ADT Buff

                }else if (InputCmd == "INSPECT"){
                    scanf("Masukkan petak: %d\n", &InputInspect);
                    //Bagian Zhillan
                    //Kasitau teleport, terlarang, atau kosong berdasarkan masukan InputInspect. Bisa pakai IsPetakTP, IsPetakTerlarang, IsPetakKosong dari ADT map & tp

                } else if (InputCmd == "UNDO"){
                    // Bagian Modan
                    //Balik ke state sebelumnya.
                    TakeUndo = true;

                } else {
                    printf("Masukan command tidak valid! Silahkan coba lagi.\n");

                }
                scanf("Masukkan command: %s\n", &InputCmd);
            }

            // Input = ROLL
            // Lakukan ROLL dengan Random lalu simpan ke variabel Roll


            if (IsPetakKosong(Peta, currlocp1 + Roll)){ //Ini harusnya loc pemain yang sedang turn-nya. Harus disesuaikan ADT Player
                //Bagian Zhillan

            } // Cek juga lainnya kalau petak terlarang dan TP


            if (currlocp1 == JumPetak){ //Ini harus loc pemain yang sedang turn-nya. Sesuaikan dengan ADT Player
                printf("------------------------- GAME BERAKHIR -------------------------");
                printf("Mobita telah mencapai ujung.\nPemenang game ini adalah Mobita\n");
                EndGame = true;
            }

            TurnPemainKe++; //Lanjut turn ke pemain selanjutnya
        }

    }

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