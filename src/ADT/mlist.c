/*
    TUBES IF2111 K2 KELOMPOK 12
    ADT LIST LINEAR - DRIVER
    Versi: 2021-11-14 08:40 (zhillan)
    Notes: Hanya fungsi, prosedur relevan yang dites
*/

#include <stdio.h>
#include "list.h"

// METODE PENGETESAN

// ALGORITMA PROGRAM UTAMA
int main () {
    // KAMUS
    int count = 0;
    // ALGORITMA
    printf("(UNIT TESTING ADT list dimulai... (0/15):\n");

    // TEST1 CreateEmpty
        // KAMUS
        List L1;
        // ALGORITMA
        CreateEmpty(&L1);
        printf("SUKSES TEST1 CreateEmpty\n");
        count++;

    // TEST2 IsEmpty
        // KAMUS
        List L2;
        // ALGORITMA
        CreateEmpty(&L2);
        if (IsEmpty(L2))
        {
            printf("SUKSES TEST2 IsEmpty\n");
            count++;
        }
    
    // TEST3 Alokasi
        // KAMUS
        int X3 = 177013;
        address P3;
        // ALGORITMA
        P3 = Alokasi(X3);
        if (P3 != Nil)
        {
            if (Info(P3) == X3)
            {
                printf("SUKSES TEST3 Alokasi X = %d\n", Info(P3));
                count++;
            }
            else
            {
                printf("GAGAL TEST3 X != X3");
            }
        }
        else if (P3 == Nil)
        {
            printf("TEST3 Gagal Alokasi X\n");
        }

    // TEST4 Dealokasi
        // KAMUS
        int X4 = 348673;
        address P4;
        // ALGORITMA
        P4 = Alokasi(X4);
        if (P4 != Nil)
        {
            Dealokasi(&P4);
            printf("SUKSES TEST4 Dealokasi\n");
            count++;
            Dealokasi(&P3);
        }
        else
        {
            printf("TEST4 Dealokasi Gagal Alokasi X\n");
        }

    // TEST5 InsertFirst
        // KAMUS 
        // KAMUS
        List L5;
        address P5a, P5b, loc5;
        int X5a = 300110;
        int X5b = 271048;
        // ALGORITMA
        P5a = Alokasi(X5a);
        P5b = Alokasi(X5b);
        CreateEmpty(&L5);
        if ((P5a != Nil) && (P5b != Nil))  // Kedua alokasi berhasil
        {
            // Test list kosong
            InsertFirst(&L5, P5a);
            // L5 = [X5a]
            printf("TEST7a X = %d\n", Info(First(L5)));
            if (Info(First(L5)) == X5a)
            {
                printf("SUKSES TEST5a InsertLast\n");
                count++;
            }
            else
            {
                printf("GAGAL TEST5a InsertLast\n");
            }

            // Test list isi
            InsertFirst(&L5, P5b);
            // L5 = [X5b, X5a]
            printf("TEST5b X = %d\n", Info(First(L5)));
            if (Info(First(L5)) == X5b)
            {
                printf("SUKSES TEST5b InsertLast\n");
                count++;
            }
            else
            {
                printf("GAGAL TEST5b InsertLast\n");
            }
            
        }
        else
        {
            printf("TEST5 InsertLast Gagal Alokasi X\n");
        }

    // TEST6 InsertAfter
        // KAMUS
        // List L5 = [X5b, X5a]
        address P6; // P5b
        int X6 = 314351;
        // ALGORITMA
        P6 = Alokasi(X6);
        if (P6 != Nil)
        {
            InsertAfter(&L5, P6, P5b);
            // L5 = [X5b, X6, X5a]
            printf("TEST6 X = %d\n", Info(Next(First(L5))));
            if (Info(Next(First(L5))) == X6)
            {
                printf("SUKSES TEST6 InserAfter\n");
                count++;
            }
            else
            {
                printf("GAGAL TEST6 InsertAfter\n");
            }
        }
        else
        {
            printf("TEST6 InsertLast Gagal Alokasi X\n");
        }

    // TEST7 InsertLast
        // KAMUS
        List L7;
        address P7a, P7b, loc7;
        int X7a = 265534;
        int X7b = 130835;
        // ALGORITMA
        P7a = Alokasi(X7a);
        P7b = Alokasi(X7b);
        CreateEmpty(&L7);
        if ((P7a != Nil) && (P7b != Nil))  // Kedua alokasi berhasil
        {
            // Test list kosong
            InsertLast(&L7, P7a);
            // L7 = [X7a]
            printf("TEST7a X = %d\n", Info(First(L7)));
            if (Info(First(L7)) == X7a)
            {
                printf("SUKSES TEST7a InsertLast\n");
                count++;
            }
            else
            {
                printf("GAGAL TEST7a InsertLast\n");
            }

            // Test list isi
            InsertLast(&L7, P7b);
            // L7 = [X7a, X7b]
            loc7 = Next(First(L7));
            printf("TEST7b X = %d\n", Info(loc7));
            if (Info(loc7) == X7b)
            {
                printf("SUKSES TEST7b InsertLast\n");
                count++;
            }
            else
            {
                printf("GAGAL TEST7b InsertLast\n");
            }
            
        }
        else
        {
            printf("TEST7 InsertLast Gagal Alokasi X\n");
        }

    // TEST8 InsVFirst
        // KAMUS
        List L8;
        int X8a = 235879;
        int X8b = 159324;
        // ALGORITMA
        CreateEmpty(&L8);

        // Test list kosong
        InsVFirst(&L8, X8a);
        // L8 = [X8a]
        printf("TEST8a X = %d\n", Info(First(L8)));
        if (Info(First(L8)) == X8a)
        {
            printf("SUKSES TEST8a InsVFirst\n");
            count++;
        }
        else
        {
            printf("GAGAL TEST8a InsVFirst\n");
        }

        // Test list isi
        InsVFirst(&L8, X8b);
        // L8 = [X8b, X8a]
        printf("TEST8b X = %d\n", Info(First(L8)));
        if (Info(First(L8)) == X8b)
        {
            printf("SUKSES TEST8b InsVFirst\n");
            count++;
        }
        else
        {
            printf("GAGAL TEST9b InsVFirst\n");
        }

    // TEST9 InsVLast
        // KAMUS
        List L9;
        address loc9;
        int X9a = 338495;
        int X9b = 336644;
        // ALGORITMA
        CreateEmpty(&L9);
        // Test list kosong
        InsVLast(&L9, X9a);
        // L9 = [X9a]
        printf("TEST9a X = %d\n", First(L9));
        if (Info(First(L9)) == X9a)
        {
            printf("SUKSES TEST9a InsertLast\n");
            count++;
        }
        else
        {
            printf("GAGAL TEST9a InsertLast\n");
        }
        // Test list isi
        InsVLast(&L9, X9b);
        // L9 = [X9a, X9b]
        loc9 = Next(First(L9));
        printf("TEST9b X = %d\n", Info(loc9));
        if (Info(loc9) == X9b)
        {
            printf("SUKSES TEST9b InsertLast\n");
            count++;
        }
        else
        {
            printf("GAGAL TEST9b InsertLast\n");
        }
    
    // TEST10 DelElmtKe
        // KAMUS
        List L10;
        int X10;
        int X10a = 159324;
        int X10b = 255662;
        int X10c = 123378;
        int X10d = 205367;
        // ALGORITMA
        CreateEmpty(&L10);
        InsVLast(&L10, X10b);
        InsVLast(&L10, X10d);
        InsVLast(&L10, X10a);
        InsVLast(&L10, X10c);
        // L10 = [X10b, X10d, X10a, X10c]

        DelElmtKe(&L10, 3, &X10);
        // L10 = [X10b, X10d, X10c]
        printf("TEST10a X = %d\n", X10);
        if (X10 == X10a)
        {
            printf("SUKSES TEST10a DelElmtKe\n");
            DelElmtKe(&L10, 1, &X10);
            // L10 = [X10d, X10c]
            printf("TEST10b X = %d\n", X10);
            if (X10 == X10b)
            {
                printf("SUKSES TEST10b DelElmtKe\n");
                DelElmtKe(&L10, 2, &X10);
                // L10 = [X10d]
                printf("TEST10c X = %d\n", X10);
                if (X10 == X10c)
                {
                    printf("SUKSES TEST10c DelElmtKe\n");
                    DelElmtKe(&L10, 1, &X10);
                    // L=10 = []
                    printf("TEST10d X = %d\n", X10);
                    if (X10 == X10d)
                    {
                        printf("SUKSES TEST10d DelElmtKe\n");
                        count++;
                    }
                    else
                    {
                        printf("GAGAL TEST10d DelElmtKe\n");
                    }
                }
                else
                {
                    printf("GAGAL TEST10c DelElmtKe\n");
                }
            }
            else
            {
                printf("GAGAL TEST10b DelElmtKe\n");
            }
        }
        else
        {
            printf("GAGAL TEST10a DelElmtKe\n");
        }
    
    // TEST 11 NbElmt
        // KAMUS
        // L7 = [X7a, X7b]
        int X11;
        // ALGORITMA
        X11 = NbElmt(L7);
        printf("SUKSES TEST11 NbElmt = %d\n", X11);
        count++;

    printf("UNIT TESTS ADT list selesai. Betul (%d/15).\n", count);
    return 0;
}