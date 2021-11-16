/*
File driver untuk ADT array_map
Deksripsi: Program ini akan membuat map dan mengisi map tersebut dengan
'.' sebagai tanda bahwa petak pada map merupakan 'kosong'/dapat ditempati dan 
'#' memberi tanda bahwa petak pada map adalah petak terlarang. Selanjutnya 
akan diperlihatkan juga contoh jika ada seorang pemain yang ada di petak 
tertentu yang ditandai dengan '*'. Maksimal banyaknya petak adalah 100.
Map kosong ditandai dengan seluruh elemennya merupakan '-'.
*/

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "array_map.h"

int main(){

    TabPeta Map;
    int JumlahPetak;
    int PosisiPemain;

    //Membuat peta kosong yang ditandai dengan seluruh elemennya berupa '-'
    MakeEmptyPeta(&Map);

    /*Proses mengisi peta. Asumsi input selalu benar yaitu '.' atau '#' dengan
    petak terakhir tidak sama dengan '#'*/
    printf("Jumlah petak: ");
    scanf("%d", &JumlahPetak);
    for(int i = 1; i <= JumlahPetak; i++){
        getchar();
        printf("Petak ke-%d: ", i);
        scanf("%c", &Map.Peta[i]);
    }

    //Menentukan posisi pemain pada map
    printf("Posisi pemain: ");
    scanf("%d", &PosisiPemain);

    /*Memeriksa apakah posisi pemain petak terlarang atau bukan. Jika ya, operasi
    input akan dilakukan kembali hingga menempati petak kosong*/
    while (IsPetakTerlarang(Map, PosisiPemain)){
        printf("Posisi tersebut merupakan petak terlarang. Silahkan coba lagi\n");
        printf("Posisi pemain: ");
        scanf("%d", &PosisiPemain);
    }

    //Memberikan output peta yang dimiliki oleh pemain
    DisplayPetaPemain(Map, PosisiPemain, JumlahPetak);

    if (IsPetakKosong(Map, PosisiPemain)){
        printf("Petak yang ada tempati adalah petak kosong.\n");
    }

    return 0;
}