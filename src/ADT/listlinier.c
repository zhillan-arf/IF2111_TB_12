//INI HANYA UNTUK SEMENTARA, KALAU SUDAH ADA ADT LIST SILAHKAN DIHAPUS
/* File : listlinier.c */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
/* Mengirim true jika list kosong */
    return First(L) == Nil;
}


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}


/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    address P = (address) malloc (sizeof(ElmtList));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
void Dealokasi (address *P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(*P);
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address P = First(L);
    boolean found = false;
    while ((P != Nil) && (found == false)){
        if (Info(P) == X) {
            found = true;
        } else{
            P = Next(P);
        }
    }
    if (found == true) {
        return P;
    } else {
        return Nil;
    }
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
	address P = Alokasi(X);
	Next(P) = First(*L);
	First(*L) = P;
}
void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (IsEmpty(*L)) {
        InsVFirst(L, X);
    } else{
        if (Alokasi(X) != Nil) {
            address last = First(*L);
            while (Next(last) != Nil){
                last = Next(last);
            }
            Next(last) = Alokasi(X);
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address p = First(*L);
    *X = Info(First(*L));
    First(*L) = Next(p);
}
void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address loc = Nil;
    address last = First(*L);
    while (Next(last) != Nil){
        loc = last;
        last = Next(last);
    }
    if (loc == Nil){
        First(*L) = Nil;
    } else {
        Next(loc) = Nil;
    }
    *X = Info(last);
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec) {
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (P == Nil) return;

    if (IsEmpty(*L)){
        First(*L) = P;
    } else {
        address now = First(*L);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(P) = Nil;
        Next(now) = P;
    }
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    address loc = First(*L);
    *P = First(*L);
    First(*L) = Next(loc);
}
void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    if(!IsEmpty(*L)){
        address now = First(*L);
        address dummy;
        if(Info(now) == X){
            DelFirst(L, &dummy);
        }else{
            while(Next(now) != Nil && Info(Next(now)) != X){
                now = Next(now);
            }
            if(Next(now) != Nil){
                DelAfter(L, &dummy, now);
            }
        }
    }
}
void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    address now = First(*L);
    if(Next(now) == Nil){
        DelFirst(L, P);
    }else{
        while(Next(Next(now)) != Nil){
            now = Next(now);
        }
        DelAfter(L, P, now);
    }
}
void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");
    if (!IsEmpty(L)){
        address now = First(L);
        while (now != Nil) {
            printf("%d", Info(now));
            now = Next(now);

            if (now != Nil)
                printf(",");
        }
    }
    printf("]");
}
int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    if (IsEmpty(L)){
        return 0;
    } else {
        int ctr = 1;
        address P = First(L);
        while (Next(P) != Nil){
            ctr++;
            P = Next(P);
        }
        return ctr;
    }
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
/* Mengirimkan nilai Info(P) yang maksimum */
    address P = First(L);
    infotype maks = Info(P);
    while (Next(P) != Nil){
        P = Next(P);
        if (Info(P) > maks){
            maks = Info(P);
        }
    }
    return maks;
}
/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    CreateEmpty(L3);
    First(*L3) = First(*L1);
    First(*L1) = Nil;
    if (IsEmpty(*L3)){
        First(*L3) = First(*L2);
    } else {
        address now = First(*L3);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(now) = First(*L2);
    }
    First(*L2) = Nil;
}

address AdrMax (List L){
    Search(L, Max(L));
}

infotype Min (List L){
    address P = First(L);
    infotype minim = Info(P);
    while (Next(P) != Nil){
        P = Next(P);
        if (Info(P) < minim){
            minim = Info(P);
        }
    }
    return minim;
}

address AdrMin (List L){
    Search(L, Min(L));
}

float Average (List L){
    float total = 0;
    float jumlah = 0;
    address p;
    p = First(L);
    while (p != Nil) {
        total++;
        jumlah += Info(p);
        p = Next(p);
    }
    return jumlah/total;
}

void InversList (List *L){
	if (!IsEmpty(*L)){
		address P = First(*L);
		while (Next(P) != Nil){
			P = Next(P);
		}
		address last = P;
		address Prec;
		while (P != First(*L)){
			Prec = First(*L);
			while (Next(Prec) != P){
				Prec = Next(Prec);
			}
			Next(P) = Prec;
			P = Next(P);
		}
		Next(P) = Nil;
		First(*L) = last;
	}
}