#include "..boolean.h"
#include "../ADT/array_buff.h"
#include "../ADT/player.h"
#include "gacha_skill.h"
#include "skills.h"

void skillSatu(Player* P){
    //Pintu gak kemana mana
    if (Search(List(*P), 1) != NULL){
        BUFF(buff(*P), 1) = true;
        DelP(List(*P), 1);
    }
}
void skillEmpat(Player *P){
    //Cermin pengganda
    if (Search(List(*P), 4) != NULL && length(List(*P)) < 9){
        DelP(List(*P), 4);
        gacha_skill(List(P));
        gacha_skill(List(P));
    }
}

void skillLima(Player * P){
    // Senter Pembesar Hoki
    if (Search(List(*P), 5) != NULL) {
        DelP(List(*P), 5);
        BUFF(buff(*P), 3);
    }
}
void skillEnam(Player *P){
    // Senter Pengecil Hoki
    if (Search(List(*P), 6) != NULL) {
        DelP(List(*P), 6);
        BUFF(buff(*P), 4);
    } 
}