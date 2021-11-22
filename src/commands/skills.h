#include "../boolean.h"
#include "../ADT/array_buff.h"
#include "gacha_skill.h"
#include "../ADT/array_tp.h"
#include "../ADT/array_map.h"
#include "../ADT/state.h"

void displaySkill(List S, char namaSkill);

void menuSkill(State *state, player *P);

void pintuGaKemanaSaja(player* P);
//Pintu gak kemana mana
//I.S player memanggil skill 1 dan skill 1 terdapat pada list skill player, 
//F.S buff telport palyer immune akan aktif dan skill 1 dihapus dari list skill palyer.

void MesinWaktu (State *state, player *P, int MaxRoll, int JumPetak, TabPeta peta, TabTP arrtp);
// Skill ke-2
/*  I.S.    Player memangiil skill 2 "Mesin waktu" dan skill 2 terdapat dalam list skill player.
            Sebelumnya, pada opsi2, tertulis "X. Mesin Waktu (?? langkah)"
    F.S.    1. Dadu untuk menentukan nexts ter-roll
            2. Pemain antara maju() atau gagal. Jika gagal, output pesan dan list skill tidak berubah.
            Vice versa berhasil, hapus salah satu skill 2 dari list skill player itu, laksanakan perintah
*/

void BalingBalingJambu (State *state, player *P, int MaxRoll, int JumPetak, TabPeta peta, TabTP arrtp);
// Skill ke-3
/*  I.S.    Player memangiil skill 3 "Baling-Baling Jambu" dan skill 3 terdapat dalam list skill player.
            Sebelumnya, pada opsi2, tertulis "X. Baling-Baling Jambu (?? langkah)"
    F.S.    1. Dadu untuk menentukan pasts ter-roll
            2. Pemain antara mundur() atau gagal. Jika gagal, output pesan dan list skill tidak berubah.
            Vice versa berhasil, hapus salah satu skill 2 dari list skill player itu, laksanakan perintah
*/

void cerminPengganda(player *P);
//Cermin pengganda
//I.S player memanggil skill 4 dan skill 4 terdapat pada list skill player  
//F.S skill 4 pada list player terhapus, dan terdapat penambahan 2 skill baru

void senterPengecil(player * P);
// Senter Pembesar Hoki
//I.S player memanggil skill 5 dan skill 5 terdapat pada list skill player 
//F.S buff senter pembesar hoki aktif

void mesinTukar(State *state,player *P);
// Senter Pengecil Hoki
//I.S player memanggil skill 5 dan skill 5 terdapat pada list skill player 
//F.S buff senter pengecil hoki aktif

void print_players (State state, player current_player);
// I.S. giliran player ke-X
// F.S. ter-print nama semua player kecuali player ke-X

boolean valid (int idx, int player_idx, int nEff);
// return boolean jika anggota dan bukan player sekarang

boolean valid_display (int idx_choice, int nbelmt);
// return booelan apakah input int diantara 0 dan banyak elemen di list