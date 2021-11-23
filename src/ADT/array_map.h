#ifndef ARRAY_MAP_H
#define ARRAY_MAP_H

#include "../boolean.h"
#include "mesin_kar.h"
#include "mesin_kata.h"

#define IdxMaxPetak 100
#define IdxMinPetak 1

typedef char Petak;

typedef struct tabpeta {
	Petak Peta [IdxMaxPetak-IdxMinPetak+1+1]; //Yang dipakai adalah [1..IdxMax]
} TabPeta;

/* Peta kosong didefinisikan sebagai peta yang isi seluruh elemennya adalah '-' */

void MakeEmptyPeta(TabPeta *P);
/* Membetuk sebuah tabel peta P yang kosong dengan mengisi seluruh elemennya '-' */

void DisplayPetaPemain(TabPeta P, int PosPemain, int JumPetak);
/* I.S. Sembarang */
/* F.S. Menampilkan peta untuk player sesuai dengan posisinya.*/

boolean IsPetakKosong (TabPeta P, int NoPetak);
/* Mengembalikan true jika petak kosong ('.') dan false jika tidak */

boolean IsPetakTerlarang (TabPeta P, int NoPetak);
/* Mengembalikan true jika petak terlarang ('#') dan false jika tidak */

#endif