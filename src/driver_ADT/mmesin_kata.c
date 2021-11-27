/*
File driver untuk ADT mesin_kar dan mesin_kata
Deksripsi: Menampilkan seluruh karakter seperti yang ada pada file config.txt dengan
asumsi pada file config.txt tidak terdapat MARK dan batas penulisan outputnya berdasarkan
baris ke-4 yang ada di file config.txt. Misal baris ke-4 merupakan angka 4 maka proses
penampilan outputnya adalah seperti berikut
1. Baris ke-1
2. Baris ke-2
3. Baris ke-3
4. Baris ke-4
5. Traversal yang dilakukan sebanyak "Baris ke-4" kali dengan format x x perbarisnya
*/

#include <stdio.h>
#include <stdlib.h>

#include "../ADT/mesin_kar.h"
#include "../ADT/mesin_kata.h"
#include "../ADT/mesin_kar.c"
#include "../ADT/mesin_kata.c"

int main() {

    //Menuliskan output 3 baris pertama
    STARTKATA("../../data/config.txt");
    for (int i = 0; i < 3; i++){
        for (int i = 1; i <= CKata.Length; i++){
            printf("%c", CKata.TabKata[i]);
        }
        printf("\n");
        ADVKATA();
    }
    
    //Menuliskan output baris ke-4
    for (int i = 1; i <= CKata.Length; i++){
        printf("%c", CKata.TabKata[i]);
    }
    printf("\n");

    //Menyimpan nilai baris ke-4 ke sebuah variabel untuk kebutuhan traversal
    //Karena type yang ada pada file config.txt adalah char, maka perlu dikonversi ke integer
    int Line4, n = 0;
    for(int i = 1; CKata.TabKata[i]>='0' && CKata.TabKata[i]<='9'; i++){
        n = 10*n + (CKata.TabKata[i] - '0');
    }
    Line4 = n;
    
    //Menampilkan output sisanya dengan kententuan dan format yang ada pada deskripsi
    for(int i = 0; i < Line4; i++){
        ADVKATA();
        for (int i = 1; i <= CKata.Length; i++){
            printf("%c", CKata.TabKata[i]);
        }
        ADVKATA();
        printf(" ");
        for (int i = 1; i <= CKata.Length; i++){
            printf("%c", CKata.TabKata[i]);
        }
        printf("\n");
    }

    return 0;
}