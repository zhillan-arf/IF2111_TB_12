/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND ROLL - IMPLEMENTASI
    Versi: 2021-11-28
*/

#include "../../boolean.h"
#include "../player/player.h"
#include "../state/state.h"
#include <stdlib.h>

#ifndef _STACKLIST_H
#define _STACKLIST_H

/* Konstanta */
#define Nil NULL
#define MaxPlayer 100 //Ini contoh aja, nanti sesuaikan sama array_player aslinya

/* Deklarasi infotype */
typedef State roundState;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * addressSt;
typedef struct tElmtStack { 
  roundState InfoSt;
  addressSt NextSt; 
} ElmtStack; 

/* Type stack dengan ciri TOP : */
typedef struct { 
  addressSt TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->InfoSt
#define NextSt(P) (P)->NextSt
#define InfoSt(P) (P)->InfoSt

/* Prototype manajemen memori */
void AlokasiStack (addressSt *P, roundState X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        NextSt(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiStack (addressSt P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmptyStack (Stack S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmptyStack (Stack * S);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
void Push (Stack * S, roundState X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop (Stack * S, roundState * X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

#endif