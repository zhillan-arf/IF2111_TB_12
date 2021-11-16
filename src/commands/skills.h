#include "../boolean.h"
#include "../ADT/array_buff.h"
#include "gacha_skill.h"


void skillSatu(Player* P);
//Pintu gak kemana mana
//I.S Player memanggil skill 1 dan skill 1 terdapat pada list skill player, 
//F.S buff telport palyer immune akan aktif dan skill 1 dihapus dari list skill palyer.

void skillEmpat(Player *P);
//Cermin pengganda
//I.S Player memanggil skill 4 dan skill 4 terdapat pada list skill player  
//F.S skill 4 pada list player terhapus, dan terdapat penambahan 2 skill baru

void skillLima(Player * P);
// Senter Pembesar Hoki
//I.S Player memanggil skill 5 dan skill 5 terdapat pada list skill player 
//F.S buff senter pembesar hoki aktif

void skillEnam(Player *P);
// Senter Pengecil Hoki
//I.S Player memanggil skill 5 dan skill 5 terdapat pada list skill player 
//F.S buff senter pengecil hoki aktif