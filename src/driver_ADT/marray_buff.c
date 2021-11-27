#include <stdio.h>
#include "../ADT/array_buff.h"

int main(){
    char name[] = "Azami";
    array_buff B;
    ResetTabBuff(&B);
    displayBuff(B, namaBuff, name); //seharusnya masi kosong
    BUFF(B, 0) = !BUFF(B, 0); //membuat BUFF ke 0 jadi true
    displayBuff(B, namaBuff, name); //seharusnya memiliki buff imunitas telport
    BUFF(B, 1) = !BUFF(B, 1); //membuat BUFF ke 1 jadi true
    BUFF(B, 2) = !BUFF(B, 2); //membuat BUFF ke 2 jadi true
    BUFF(B, 3) = !BUFF(B, 3); //membuat BUFF ke 3 jadi true
    displayBuff(B, namaBuff, name); //seharusnya memiliki buff imunitas telport, cerming pengganda, senter pembesar
    ResetTabBuff(&B);
    displayBuff(B, namaBuff, name); //seharusnya kosong kembali

}