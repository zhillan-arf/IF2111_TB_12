/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include "../../boolean.h"
#include "../mesin_kar/mesin_kar.h"

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#define NMaxChar 100
#define BLANK '\n'
#define BLANK2 ' '

typedef struct {
   char TabKata[NMaxChar+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
   int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void IgnoreBlank2();
/* Mengabaikan satu atau beberapa new line
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
          
void STARTKATA(char filename[]);
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */


#endif