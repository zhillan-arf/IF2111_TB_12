#ifndef CONSOLE_H
#define CONSOLE_H

#include "mesin_kata.h"
#include "mesin_kar.h"
#include "listlinier.h"
#include "array_tp.h"
#include "array_map.h"
#include "boolean.h"

extern int JumPetak, MaxRoll, JumTP, KeluarTP, MasukTP;
extern TabPeta Peta;
extern TabTP arrTP;

void KataToTabPeta(Kata TabKata, TabPeta *P);
/* I.S. TabKata dan P terdefinisi */
/* F.S. Tabel P memuat peta sesuai file config berdasarkan tabel kata hasil pembacaan*/

int charToInt(char c);
/* Mengembalikan nilai pada karakter dalam bentuk integer */

int strToInt(char s[]);
/* Mengembalikan nilai pada string dalam bentuk integer */

#endif