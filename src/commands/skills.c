/*
    TUBES IF2111 K2 KELOMPOK 12
    ADT PLAYER - HEADER
    Versi: 2021-11-16 20:30
*/

#include "../boolean.h"
#include "../ADT/array_buff.h"
#include "../ADT/player.h"
#include "../ADT/list.h"
#include "gacha_skill.h"
#include "skills.h"
#include <stdlib.h>
#include <time.h>
#include "state.h"
#include "../commands/roll.h"

/* KOMEN
0. Nambah2 #include yang lom dimasukkin, ngubah "Player" jadi "player" dan List(*P) jadi skill(*P) 
(soalnya di file ADT player nya gitu kwkwkwk), ngubah DelP(skill(*P), X) jadi DelP(&skill(*P), X))
(soalnya di file ADT list DelP minta alamat kwkwk)

1. Prosedur yang ngeprint skill tuh gimana detailnya? Misal ada misal ada list skill [3, 6, 3, 1, 4].

1A. Apakah dia bakal ngeprint berdasar iterasi list, sehingga ngeprint:

Kamu memiliki skill:
    1. Baling-Baling Jambu
    2. Senter Pengecil Hoki
    3. Baling-Baling Jambu
    4. Pintu Ga Kemana Saja
    5. Cermin Pengganda

sehingga kalau user nginput "2", sistem bakal ngapus baling-baling jambu (yang adalah
skill 3) dan list jadi [6, 3, 1, 4]? 

1B. Atau apakah dia bakal ngitung dulu jumlah tiap skill, sehingga ngeprint:

B. Kamu memiliki skill:
    1. Baling-Baling Jambu (2)
    2. Senter Pengecil Hoki (1)
    3. Pintu Ga Kemana Saja (1)
    4. Cermin Pengganda (1)

sehingga kalo user nginput "1", sistem bakal ngapus baling-baling jambu (yang adalah
skill 3) dan list jadi [3, 6, 1, 4]? 

1C. Atau apakah nggak usah dihitung jumlahnya, cukup "ada" dan tidak ada"? Terus apakah dia bakal 
(1) ngurutin dulu list biar sesuai urutan skill, atau (2) ngasumsiin bahwa list sudah terurut, sehingga
list jadi [1, 3, 3, 4, 6], terus pas ngeprint disesuaiin sama nomor skill betulan (bukan nomor urutan di list),
sehingga ngeprint:

Kamu memiliki skill:
    1. Pintu Ga Kemana Saja
    3. Baling-Baling Jambu
    4. Cermin Pengganda
    6. Senter Pengecil Hoki

sehingga kalo user nginput "3", sistem bakal ngapus baling-baling jambu (yang adalah
skill 3) dan list jadi [1, 3, 4, 6]? 

1D. Atau apakah iterasi biar gampang, tapi nomor yang muncul di sebelah nama skill adalah nomor skillm bukan nomor urutan,
sehingga kalo masuk list skill [3, 6, 3, 1, 4], akan ngeprint:

Kamu memiliki skill:
    3. Baling-Baling Jambu
    6. Senter Pengecil Hoki
    3. Baling-Baling Jambu
    1. Pintu Ga Kemana Saja
    4. Cermin Pengganda

sehingga kalo user nginput "3", sistem bakal ngapus baling-baling jambu (yang adalah
skill 3) dan list jadi [6, 3, 1, 4]? 

(Eh berarti harus ada program validasi berarti buat nyegah user masukkin nomor yang nggak ada :kekw:)

2. Kalo yang lu pilih 1C atau 1D, pake DelP harusnya dah bener. Tapi kalo lu pilih 1A atau 1B (yang, tbh lebih sesuai
ke spesifikasi kalo coba liat), jangan pake DelP ga sih? Soalnya kan ketika user masukkin misal "3",
yang dia maksud bukan "skill 3", tapi "skill urutan ke-3 yang muncul di terminal. Kek di contoh 1A dan 1B,
no urutan bisa != nomor skill. (Ini bisa pake proisedur DelElmtKe yang ku minggu kemaren bikin sih :feelsweirdman: ) 

3. Ketika user masukkin input "SKILL" di console, kan ketrigger bagian skill. Itu lu mau hard-code di console.c langung
atau bikin di file skills.c ini, sehingga di console cuma ada fungsi super panjang skill(<segala input yang diperlukan>) ?

4. skillSatu, skillDua kan sama tuan mor suruh ganti kemaren, ada format namanya? Biar ku bikin fungsi skill bonusnya 
pake format atau aesthetic nama yang sama

-dialah_zhillanku
*/

void skillSatu(player* P) {
    //Pintu gak kemana mana
    if (Search(skill(*P), 1) != Nil){
        BUFF(buff(*P), 1) = true;
        DelP(&skill(*P), 1);
    }
}

void MesinWaktu (State *state, player *P, int MaxRoll, int JumPetak, TabPeta peta, TabTP arrtp) {
    // Skill ke-2
    // KAMUS LOKAL
    int next_idx, rolled, input, player_idx, nEff;
    boolean is_valid = false;
    time_t t;
    player *chosenP;
    // ALGORITMA
    player_idx = GetPlayerIdx((*state), (*P));
    nEff = GetLastIdx(*state);
    srand((unsigned) time(&t)); // Inisialisasi rand()
    rolled = (rand() % (MaxRoll)) + 1;  // roll
    printf("%s me-roll %d. Siapa yang mau dimajukan %d petak?\n", nama(*P), rolled, rolled);
    print_players((*state), (*P));
    while (!is_valid)   // input user masuk
    {
        scanf("Masukkan pemain-ke: %d", input);
        input--;    // idx array = urutan - 1
        if (valid(input, player_idx, nEff))
        {
            is_valid = true;
        }
        else
        {
            printf("Tetot! Input invalid. Masukkan '1', '2' sesuai nomor.\n");
        }
    }
    // input valid
    (*chosenP) = (*state).TabPlayer[input]; // Pemrosesan maju
    next_idx = (current_petak(*chosenP)) + rolled;
    if (next_idx >= JumPetak)
    {
        if (!IsPetakTerlarang(peta, next_idx))
        {
            maju(chosenP, next_idx, peta, arrtp);
        }
        else
        {
            printf("%s akan mendarat di tempat terlarang - tidak boleh!\nMesin waktu error, mogok, dan batal dipakai.\n", nama(*chosenP));
        }
    }
    else
    {
        printf("%s akan mendarat di luar map - tidak boleh!\nMesin waktu error, mogok, dan batal dipakai.\n", nama(*chosenP));
    }
}

void BalingBalingJambu (State *state, player *P, int MaxRoll, int JumPetak, TabPeta peta, TabTP arrtp) {
    // Skill ke-3
    // KAMUS LOKAL
    int past_idx, rolled, input, player_idx, nEff;
    boolean is_valid = false;
    time_t t;
    player *chosenP;
    // ALGORITMA
    player_idx = GetPlayerIdx((*state), (*P));
    nEff = GetLastIdx(*state);
    srand((unsigned) time(&t)); // Inisialisasi rand()
    rolled = (rand() % (MaxRoll)) + 1;  // roll
    printf("%s me-roll %d. Siapa yang mau dimundurkan %d petak?\n", nama(*P), rolled, rolled);
    print_players((*state), (*P));
    while (!is_valid)   // input user masuk
    {
        scanf("Masukkan pemain-ke: %d", input);
        input--;    // idx array = urutan - 1
        if (valid(input, player_idx, nEff))
        {
            is_valid = true;
        }
        else
        {
            printf("Tetot! Input invalid. Masukkan '1', '2' sesuai yang ditampilkan.\n");
        }
    }
    // input valid dan sudah didecrement 1
    (*chosenP) = (*state).TabPlayer[input]; // Pemrosesan maju
    past_idx = (current_petak(*chosenP)) - rolled;
    if (past_idx >= 0)
    {
        if (!IsPetakTerlarang(peta, past_idx))
        {
            mundur(chosenP, past_idx, peta, arrtp);
        }
        else
        {
            printf("%s akan mendarat di tempat terlarang - tidak boleh!\nMesin waktu error, mogok, dan batal dipakai.\n", nama(*chosenP));
        }
    }
    else
    {
        printf("%s akan mendarat di luar map - tidak boleh!\nMesin waktu error, mogok, dan batal dipakai.\n", nama(*chosenP));
    }
}

void skillEmpat(player *P){
    //Cermin pengganda
    if (Search(skill(*P), 4) != Nil && length(skill(*P)) < 9) {
        DelP(&skill(*P), 4);
        gacha_skill(&skill(*P));
        gacha_skill(&skill(*P));
    }
}

void skillLima(player * P){
    // Senter Pembesar Hoki
    if (Search(skill(*P), 5) != Nil) {
        DelP(&skill(*P), 5);
        BUFF(buff(*P), 3);
    }
}
void skillEnam(player *P){
    // Senter Pengecil Hoki
    if (Search(skill(*P), 6) != Nil) {
        DelP(&skill(*P), 6);
        BUFF(buff(*P), 4);
    } 
}

void print_players (State state, player cplayer) {
    // KAMUS
    int i = 1;
    // ALGORITMA
    while (i <= state.Neff)
    {
        if (state.TabPlayer[i].nama != cplayer.nama)
        {
            printf("    %d. %s\n", (i + 1), cplayer.nama);
        }
        i++;
    }
    // i > Neff
}

boolean valid (int idx, int player_idx, int nEff) {
    // KAMUS
    boolean is_in_array = false;
    int i = 0;
    while (i < nEff)
    {
        if (idx = i)
        {
            is_in_array = true;
        }
        i++;
    }
    return is_in_array && (idx != player_idx);
}