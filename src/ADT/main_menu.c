#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

int main () {
    int choice, i; 
    TabInt player [4];
    char file[99];
    char Pname1[99];
    char Pname2[99];

    do {
        puts("\n/============================/");
        puts("             MENU             ");
        puts("/============================/");
        printf("1) New Game\n");
        printf("2) Exit\n");
        printf("3) Help\n");
        puts("/============================/\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a file name : ");
                scanf("%s", file);
                printf("Enter number of player : ");
                scanf("%d", player);
                printf("Enter player 1 name : ");
                scanf("%s", Pname1);
                printf("Enter player 2 name : ");
                scanf("%s", Pname2);
                printf("\nStarting the game...");
                break;
                exit(0);
                /* belum diinisialisasi */

            case 2:
                printf("See you later!");
                exit(0);

            default: printf("Invalid Input!\n");

        }
    } while (choice != 1);
    return 0;
}