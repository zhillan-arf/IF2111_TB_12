#ifndef CONSOLE_H
#define CONSOLE_H

#include "boolean.h"
#include "mesin_kata.h"
#include "mesin_kar.h"
#include "list.h"
#include "array_tp.h"
#include "array_map.h"

extern int JumPetak, MaxRoll, JumTP;
extern TabPeta Peta;
extern TabTP arrTP;

void KataToTabPeta(Kata TabKata, TabPeta *P);
/* I.S. TabKata dan P terdefinisi */
/* F.S. Tabel P memuat peta sesuai file config berdasarkan tabel kata hasil pembacaan*/

int charToInt(char c);
/* Mengembalikan nilai pada karakter dalam bentuk integer */

int strToInt(char s[]);
/* Mengembalikan nilai pada string dalam bentuk integer */

void ReadConfigFile(int *JPetak, int *MRoll, int *JTP, TabPeta *P, TabTP *ARTP);
/* Membaca file konfigurasi dan menyimpan keperluan informasi kepada masing-masing variabel*/
/* I.S. Seluruh variabel pada input terdefinisi*/
/* F.S. Seluruh variabel menyimpan value yang sesuai berdasarkan file konfigurasi */

boolean compareString(char a[], char b[]);
/* Mengembalikan true jika string a dan string b bernilai sama dan false jika tidak */


#endif