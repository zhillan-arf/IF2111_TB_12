/* MODUL TABEL STATE (Isi : tab player, ronde) */
/* Berisi definisi dan semua primitif pemrosesan tabel */
/* Penempatan elemen selalu rapat kiri */

#include "../boolean.h"
#include "player.h"

#ifndef ROUND_H 
#define ROUND_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef player ElType;

typedef struct 
{
	ElType TabPlayer [IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* banyaknya elemen efektif */
	int Round; /* Belum tau bakal dipake atau engga */
} State;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah State, cara deklarasi dan akses: */
/* Deklarasi : T : State */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TabPlayer untuk mengakses seluruh nilai elemen tabel
 * T.TabPlayer[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TabPlayer[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TabPlayer[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (State *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbPlayer (State T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElmt (State T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (State T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastIdx (State T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
IdxType GetPlayerIdx (State T, ElType P);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan idx player P dalam array */
/* *** Menghasilkan sebuah elemen *** */
ElType GetPlayer (State T, IdxType i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (State Tin, State *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetPlayer (State *T, IdxType i, ElType v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeff (State *T, IdxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
void SetRound (State *T, IdxType N);

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (State T, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (State T, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyTab (State T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (State T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

#endif