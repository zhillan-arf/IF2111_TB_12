#include <stdio.h>
#include <ctype.h>
#include "../boolean.h"
#include "../misc/convert.h"

int main ()  {
    int idx_choice;
    char in_idx_choice[MAXC];
    
    printf("\nPilih Skill yang mau diakftifkan! (Pilih 0 untuk keluar)\n>> ");
    scanf("%s", in_idx_choice);
    printf("Debug in_idx = %s\n", in_idx_choice);
    idx_choice = str_to_int_idx0(in_idx_choice);
    printf("Debug! idx = %d\n", idx_choice);
}