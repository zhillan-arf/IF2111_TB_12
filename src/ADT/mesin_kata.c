#include "mesin_kata.h"
#include "mesin_kar.h"
#include "../boolean.h"
#include <stdio.h>

boolean EndKata ;
Kata CKata ;

void IgnoreBlank(){
    while ((CC == BLANK) && (CC != MARK)) {
        ADV() ;
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void IgnoreBlank2(){
    while ((CC == BLANK2) && (CC != MARK)) {
        ADV() ;
    }
}
/* Mengabaikan satu atau beberapa new line
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK2 atau CC = MARK */


void SalinKata(){
    int i = 1;
    while ((CC != BLANK) && (CC != MARK) && (i <= NMaxChar) && (CC != BLANK2)) {
        CKata.TabKata[i] = CC ;
        ADV() ;
        i++ ;
    }
    CKata.Length = i - 1;
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMaxChar, maka sisa kata "dipotong" */
          
void STARTKATA() {
    START() ;
    IgnoreBlank();
    IgnoreBlank2();
    if (CC == MARK) {
        EndKata = true ;
    }
    else {
        EndKata = false ;
        SalinKata() ;
    }
}
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
    IgnoreBlank();
    IgnoreBlank2();
    if (CC == MARK) {
        EndKata = true ;
    }
    else {
        SalinKata() ;
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */