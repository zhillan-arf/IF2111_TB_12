#ifndef CONSOLE_H
#define CONSOLE_H

#include "boolean.h"
#include "ADT/mesin_kata.h"
#include "ADT/mesin_kar.h"
#include "ADT/list.h"
#include "ADT/array_tp.h"
#include "ADT/array_map.h"
#include "ADT/state.h"

extern int JumPetak, MaxRoll, JumTP;
extern TabPeta Peta;
extern TabTP arrTP;

void print_start();
// I.S. sembarang
// F.S. pesan2 start terprint

void print_help();
// I.S. Sembarang
// F.S. HELP (pilihan 3) printed

void insert_players(State *currentState, int JumPlayer);
// I.S. currentState kosong
// F.S. currentState terisi player2 seusia jumlah

void displayPeringkat(State currentState, int JumPlayer);
// I.S. currentState berisi data seluruh pemain ketika GAME berakhir
// F.S. Terdisplay siapa yang menang, dan leaderbord

void KataToTabPeta(Kata TabKata, TabPeta *P);
/* I.S. TabKata dan P terdefinisi */
/* F.S. Tabel P memuat peta sesuai file config berdasarkan tabel kata hasil pembacaan*/

int charToInt(char c);
/* Mengembalikan nilai pada karakter dalam bentuk integer */

int strToInt(char s[]);
/* Mengembalikan nilai pada string dalam bentuk integer */

void ReadConfigFile(int *JPetak, int *MRoll, int *JTP, TabPeta *P, TabTP *ARTP, char filename[]);
/* Membaca file konfigurasi dan menyimpan keperluan informasi kepada masing-masing variabel*/
/* I.S. Seluruh variabel pada input terdefinisi*/
/* F.S. Seluruh variabel menyimpan value yang sesuai berdasarkan file konfigurasi */

boolean compareString(char a[], char b[]);
/* Mengembalikan true jika string a dan string b bernilai sama dan false jika tidak */


#endif