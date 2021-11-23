#include "../boolean.h"
#include "mesin_kar.h"
#include "mesin_kata.h"

#ifndef ARRAY_TP_H 
#define ARRAY_TP_H

#define IdxMaxTP 99
#define IdxMinTP 1

typedef int ElTypeTP;

typedef struct tabtp {
	ElTypeTP TTP [IdxMaxTP-IdxMinTP+1+1]; //Yang dipakai adalah [1..IdxMax]
} TabTP;

void MakeEmptyArrTP(TabTP *TabelTP);
/* I.S. Sembarang */
/* F.S. Terbentuk tabel TabelTP yang seluruh valuenya 0*/

void InsertTP(TabTP *TabelTP, int X, int Y);
/* I.S. TabelTP terdefinisi */
/* F.S. Meng-insert nilai X yang merupakan keluaran teleport dengan pintu masuk teleport Y (indeksnya)*/

boolean IsPetakTP(int NoPetak, TabTP TabelTP);
/* Mengembalikan true jika petak ke-NoPetak merupakan pintu masuk teleport
dan false jika bukan */

#endif