/*
    TUBES IF2111 K2 KELOMPOK 12
    PERMAINAN "SNEK AND MADDER"
    Versi: 2021-11-27
*/

#ifndef CONSOLE_H
#define CONSOLE_H

// DEKLARASI MODULE2 DASAR
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// DEKLARASI ADT
#include "ADT/state/state.h"
#include "ADT/player/player.h"
#include "ADT/stack_state/stack_state.h"
#include "ADT/array_buff/array_buff.h"
#include "ADT/list/list.h"

// DEKLARASI COMMAND
#include "commands/inspect/inspect.h"
#include "commands/skill/gacha_skill.h"
#include "commands/roll/roll.h"
#include "commands/skill/skills.h"

// DEKLARASI LAIN
#include "console.h"
#include "boolean.h"
#include "misc/convert.h"
#include "misc/start_display.h"

extern int JumPetak, MaxRoll, JumTP;
extern TabPeta Peta;
extern TabTP arrTP;

void print_start();
// I.S. sembarang
// F.S. pesan2 start terprint

void print_help();
// I.S. Sembarang
// F.S. HELP (pilihan 3) printed

void print_help2();
// I.S. Sembarang
// F.S. HELP pada turn printed

void insert_file (char *file_dir);
// I.S. Menerima string sembarang
// F.S. file_dir = data<string inputan> dan file di alamat tersebut ada

int insert_jumplayer();
// I.S. Menerima inputan string
// F.S. JumPlayer adalah angka yang valid kemudian disimpan

void insert_players(State *currentState, int JumPlayer);
// I.S. currentState kosong
// F.S. currentState terisi player2 seusia jumlah

void displayPeringkat(State currentState, int JumPlayer);
// I.S. currentState berisi data seluruh pemain ketika GAME berakhir
// F.S. Terdisplay siapa yang menang, dan leaderbord

void KataToTabPeta(Kata TabKata, TabPeta *P);
/* I.S. TabKata dan P terdefinisi */
/* F.S. Tabel P memuat peta sesuai file config berdasarkan tabel kata hasil pembacaan*/

int charToInt(char c);
/* Mengembalikan nilai pada karakter dalam bentuk integer */

int strToInt(char s[]);
/* Mengembalikan nilai pada string dalam bentuk integer */

void ReadConfigFile(int *JPetak, int *MRoll, int *JTP, TabPeta *P, TabTP *ARTP, char filename[]);
/* Membaca file konfigurasi dan menyimpan keperluan informasi kepada masing-masing variabel*/
/* I.S. Seluruh variabel pada input terdefinisi*/
/* F.S. Seluruh variabel menyimpan value yang sesuai berdasarkan file konfigurasi */

boolean compareString(char a[], char b[]);
/* Mengembalikan true jika string a dan string b bernilai sama dan false jika tidak */


#endif