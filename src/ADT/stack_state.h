#ifndef _STACKLIST_H
#define _STACKLIST_H

#include "../boolean.h"
#include "player.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef player infoplayer;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * addressSt;
typedef struct tElmtStack { 
  infoplayer InfoSt;
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
void AlokasiStack (addressSt *P, infoplayer X);
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
void Push (Stack * S, infoplayer X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop (Stack * S, infoplayer * X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

#endif