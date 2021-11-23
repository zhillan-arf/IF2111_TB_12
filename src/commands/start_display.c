/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND START_DISPLAY - HEADER
    Versi: 2021-11-23
*/

#include <stdio.h>
#include <stdlib.h> // For exit()

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