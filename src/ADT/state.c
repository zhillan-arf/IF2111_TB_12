#include <stdio.h>
#include "state.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (State *T) {
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
   (*T).Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbPlayer (State T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    return (T).Neff;
}
/* *** Daya tampung container *** */
int MaxNbEl (State T) {
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return IdxMax-IdxMin+1;
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (State T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
    return IdxMin;
}
IdxType GetLastIdx (State T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
    return (T).Neff;
}
IdxType GetPlayerIdx (State T, ElType P) {
    /* Prekondisi : Tabel T tidak kosong, P ada di tabel, tiap nama berbeda */
    /* Mengirimkan idx player P dalam array */
    // KAMUS
    int idx = 1;
    // ALGORITMA
    while (*P.nama != *T.TabPlayer[idx].nama && idx < T.Neff)
    {
        idx++;
    }
    // P found at idx
    return idx;
}
/* *** Menghasilkan sebuah elemen *** */
ElType GetPlayer (State T, IdxType i) {
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
    return (T).TabPlayer[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (State Tin, State *Tout) {
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
    IdxType i;
    for(i=IdxMin; i <= IdxMax; i++){
        (*Tout).TabPlayer[i] = (Tin).TabPlayer[i];
    }
}
void SetPlayer (State *T, IdxType i, ElType v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
    (*T).TabPlayer[i] = v;
}
void SetNeff (State *T, IdxType N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    (*T).Neff = N;
}

void SetRound (State *T, IdxType N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Current Round T bernilai N */
/* Mengeset nilai Round sehingga bernilai N */
    (*T).Round = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (State T, IdxType i) {
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i>=GetFirstIdx(T) && i<=IdxMax);
}
boolean IsIdxEff (State T, IdxType i) {
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return (i>=GetFirstIdx(T) && i<=GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyTab (State T) {
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return (NbPlayer(T)==0);
}
/* *** Test tabel penuh *** */
boolean IsFull (State T) {
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return (NbPlayer(T)==MaxNbEl(T));
}