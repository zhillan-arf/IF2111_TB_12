/*
    TUBES IF2111 K2 KELOMPOK 12
    CONVERT - IMPLEMENTASI
    Versi: 2021-11-27
*/

#include "convert.h"
#include "../boolean.h"
#include <stdio.h>

int str_to_int_idx0(char s[]) {
    //KAMUS LOKAL
    int i, n = 0;
    boolean illegal;
    //ALGORITMA 
    for(i = 0; (s[i] >= '0') && (s[i] <= '9'); i++) {
        n = 10*n + (s[i] - '0');
        if (!((s[i + 1] >= '0') && (s[i + 1] <= '9')) && (s[i + 1] != '\0'))
        {
            illegal = true;
        }
    }
    if (illegal || !((s[0] >= '0') && (s[0] <= '9')))
    {
        return ILLEGAL;
    }
    else
    {
        return n;
    }
}