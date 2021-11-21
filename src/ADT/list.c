/*
    TUBES IF2111 K2 KELOMPOK 12
    ADT LIST LINEAR - IMPLEMENTASI
    Versi: 2021-11-14 08:30
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
    /* Mengirim true jika list kosong */
    // ALGORITMA
    return (First(L) == Nil);
}


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
    // ALGORITMA
    First(*L) = Nil;
}


/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
    /* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */
    // KAMUS
    address P;
    // ALGORITMA
    P = (address) malloc(sizeof(ElmtList));
    if (P != Nil)   // Alokasi berhasil
    {
        Info(P) = X;
        Next(P) = Nil;
    }
    else    // Alokasi gagal
    {
        P = Nil;
    }
    return P;
}


void Dealokasi (address *P) {
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */
    // ALGORITMA
    free (*P);
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
    /* Mencari apakah ada elemen list dengan Info(P)= X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */
    // KAMUS LOKAL
    address loc;
    boolean found;
    // ALGORITMA
    found = false;
    loc = First(L);
    if (!IsEmpty(L))
    {
        while ((loc != Nil) && (!found))
        {
            if (Info(loc) == X)
            {
                found = true;
            }
            else
            {
                loc = Next(loc);
            }
        }
        // loc == Nil or found
        return loc;
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    // ALGORITMA
    if (P != Nil)
    {
        Next(P) = First(*L);
        First(*L) = P;
    }
}


void InsertLast (List *L, address P) {
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    // KAMUS LOKAL
    address prevp;
    // ALGORITMA
    if (IsEmpty(*L))
    {
        InsertFirst(L, P);
    }
    else
    {
        prevp = First(*L);
        while (Next(prevp) != Nil)
        {
            prevp = Next(prevp);
        }
        InsertAfter(L, P, prevp);
    }
}


void InsertAfter (List *L, address P, address Prec) {
    /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
    /*      P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    // ALGORITMA
    if (P != Nil)
    {
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    // KAMUS LOKAL
    address P;
    // ALGORITMA
    P = Alokasi(X);
    if (P != Nil)
    {
        InsertFirst(L, P);
    }     
}


void InsVLast (List *L, infotype X) {
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P = Alokasi(X);
    if (P != Nil)
    {
        InsertLast(L, P);
    }
}


/*** PENGHAPUSAN ELEMEN, MAIN ***/
void DelElmtKe (List *L, infotype idx, infotype *X) {
    /* I.S. List L tidak kosong dan memiliki banyak elemen <= idx. Indeks list dimulai dari 1 */
    /* F.S. Elemen ke-idx dihapus */
    // KAMUS
    int ctr = 1;
    address loc, prevloc;
    // ALGORITMA
    loc = First(*L);
    prevloc = Nil;
    while (ctr < idx)
    {
        prevloc = loc;
        loc = Next(loc);
        ctr++;
    }
    // ctr = idx
    if ((prevloc == Nil) && (Next(loc) == Nil))         // List 1 Elmt
    {
        CreateEmpty(L);
    }
    else if ((prevloc == Nil) && (Next(loc) != Nil))    // Ujung awal
    {

        First(*L) = Next(loc);
    }
    else if ((prevloc != Nil) && (Next(loc) == Nil))    // Ujung akhir
    {
        Next(prevloc) = Nil;
    }
    else    // (prevloc 1= Nil) && (Next(loc) != Nil)      Tengah list
    {
        Next(prevloc) = Next(loc);
    }
    Next(loc) = Nil;
    (*X) = Info(loc);
    Dealokasi(&loc);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    // KAMUS LOKAL
    address loc;
    // ALGORITMA
    printf("[");
    if (!IsEmpty(L))
    {
        loc = First(L);
        while (loc != Nil)
        {
            printf("%d", Info(loc));
            if (Next(loc) != Nil)
            {
                printf(",");
            }
            loc = Next(loc);
        }
        // loc == Nil
    }
    printf("]");
}


int NbElmt (List L) {
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    // KAMUS LOKAL
    int count;
    address loc;
    // ALGORITMA
    count = 0;
    loc = First(L);
    while (loc != Nil)
    {
        count++;
        loc = Next(loc);
    }
    // loc = Nil;
    return count;
}


/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L) {
    /* Mengirimkan nilai Info(P) yang maksimum */
    // KAMUS LOKAL
    int maxInfo;
    address loc;
    // ALGORITMA
    loc = First(L);
    maxInfo = Info(loc);
    while (loc != Nil)
    {
        if (Info(loc) > maxInfo)
        {
            maxInfo = Info(loc);
        }
        loc = Next(loc);
    }
    // loc = Nil
    return maxInfo;
}


/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3) {
    /* I.S. L1 dan L2 sembarang */
    /* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
    /* Konkatenasi dua buah list : L1 dan L2    */
    /* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
    /* dan L1 serta L2 menjadi list kosong.*/
    /* Tidak ada alokasi/dealokasi pada prosedur ini */
    // KAMUS LOKAL
    address loc;
    // ALGORITMA
    CreateEmpty(L3);
    if (!IsEmpty(*L1))
    {
        loc = First(*L1);
        First(*L3) = loc;
        while (Next(loc) != Nil)
        {
            loc = Next(loc);
        }
        Next(loc) = First(*L2);
    }
    else
    {
        First(*L3) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}

/*** PENGHAPUSAN ELEMEN, PRIMITIF ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    // KAMUS LOKAL
    address loc;
    // ALGORITMA
    loc = First(*L);
    if (Next(loc) == Nil)
    {
        CreateEmpty(L);
    }
    else
    {
        First(*L) = Next(loc);
    }
    *P = loc;
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    // KAMUS LOKAL
    address P, prevp;
    // ALGORITMA
    P = Search(*L, X);
    if (P != Nil)
    {
        prevp = First(*L);
        if (prevp == P)
        {
            DelFirst(L, &P);
        }
        else
        {
            while (Next(prevp) != P)
            {
                prevp = Next(prevp);
            }
            // Next(prevP) == P
            DelAfter(L, &P, prevp);
        }
    }
    Dealokasi(&P);
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    // KAMUS LOKAL
    address prevp;
    *P = First(*L);
    if (Next(*P) == Nil)
    {
        CreateEmpty(L);
    }
    else
    {
        prevp = *P;
        while (Next(Next(prevp)) != Nil)
        {
            prevp = Next(prevp);
        }
        DelAfter(L, P, prevp);    
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    if (*Pdel != Nil)
    {
        Next(Prec) = Next(Next(Prec));
    }
}