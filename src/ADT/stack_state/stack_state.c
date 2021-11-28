#include <stdlib.h>
#include "stack_state.h"

void AlokasiStack (addressSt *P, roundState X){
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        NextSt(P)=Nil */
/*      P=Nil jika alokasi gagal */
    *P = (addressSt) malloc (sizeof(ElmtStack));
    if (P != Nil) {
        InfoSt(*P) = X;
        NextSt(*P) = Nil;
    }
}

void DealokasiStack (addressSt P){
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 
    free(P);
}
boolean IsEmptyStack (Stack S){
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
    return Top(S) == Nil;
}

void CreateEmptyStack (Stack *S){
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
    Top(*S) = Nil;
}

void Push (Stack *S, roundState X){
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
    addressSt P;

    AlokasiStack(&P, X);
    if (P != Nil){
        NextSt(P) = Top(*S);
        Top(*S) = P;
    }
}

void Pop (Stack *S, roundState *X){
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
    addressSt P;

    *X = InfoTop(*S);
    P = Top(*S);
    Top(*S) = NextSt(P);
    DealokasiStack(P);
}