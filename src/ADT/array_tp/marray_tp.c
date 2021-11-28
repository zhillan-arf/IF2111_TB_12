/*
File driver untuk ADT array_tp
Deksripsi: Membuat array teleportasi yang kosong ditandai dengan seluruh elemennya
adalah 0. Lalu melakukan insert pada array di indeks Y dengan nilai X. Selanjutnya
akan dilakukan traversal untuk memeriksa indeks 1 - 10 merupakan pintu teleport
atau bukan. Jika value di indeks Y bukan 0, maka dapat diartikan bahwa pada 
petak Y, pemain akan bertelportasi ke petak X. Panjang masimal array teleportasi 
adalah 99 dan indeks terkecil yang digunakan adalah 1.
*/

#include <stdio.h>
#include <stdlib.h>

#include "../../boolean.h"
#include "array_tp.h"

int main(){

    TabTP ArrTP;
    int JumlahTeleport, X, Y;

    //Membuat array teleportasi kosong (semua elemennya 0)
    MakeEmptyArrTP(&ArrTP);

    //Mengisi array teleportasi
    scanf("%d", &JumlahTeleport);
    for (int i = 0; i < JumlahTeleport; i++){
        printf("Pintu masuk teleportasi (indeks): ");
        scanf("%d", &Y);
        printf("Tujuan teleportasi: ");
        scanf("%d", &X);
        ArrTP.TTP[Y] = X;
    }

    //Mengecek apakah indeks ke 1 hingga 10 merupakan pintu masuk teleport atau bukan
    for (int i = 1; i <= 10; i++){
        if(IsPetakTP(i, ArrTP)){
            printf("Petak ke-%d merupakan pintu masuk teleport\n", i);
        } else{
            printf("Petak ke-%d bukan pintu masuk teleport\n", i);
        }
    }

    return 0;
}