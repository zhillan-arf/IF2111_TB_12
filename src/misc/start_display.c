/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND START_DISPLAY - HEADER
    Versi: 2021-11-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "start_display.h"

void start_display()
{
    
    
    FILE *fptr;
    char c;

    // Open file
    fptr = fopen("data/start_display_text.txt", "r");    // Menjalankan program harus dari README.md
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
  
    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
  
    fclose(fptr);
}

void delay(int s) {
    // KAMUS LOKAL
    int milisec;
    clock_t start_time;
    // ALGORITMA
    milisec = 1000 * s;
    start_time = clock();
    while (clock() < start_time + milisec)
    {
        // Menunggu 1 DETIK
    }
}