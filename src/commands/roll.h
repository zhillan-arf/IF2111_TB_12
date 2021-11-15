/*
    TUBES IF2111 K2 KELOMPOK 12
    COMMAND ROLL - HEADER
    Versi: 2021-11-15 11:30
*/

#include "../boolean.h"
#include "../ADT/array_map.h"

void roll (
        int *Roll,
        int MaxRoll,
        TabPeta peta,
        int JumlahPemain,
        // Hal2 ini ada di dalam ADT player. Kalo ADT nya dah jadi, ubah:
        char *nama_pemain,
        boolean *is_sbesar, 
        boolean *is_skecil, 
        boolean *is_immune, 
        int *currentpetak
    );
// I.S. Roll di console sembarang
// F.S. Roll berisi angka random sesuai buff2

/*
void maju(Player *P, int nexts, boolean is_teleport, boolean *is_immune);
// I.S. Player P berada di tempatnya, nexts + tempat saat ini ada di peta dan tidak kosong
// F.S. Player P pindah ke nexts. Jika is_teleport dan not immune dan ketemu teleporter, teleport.
// Jika immune, kasih pilihan mau ga teleport ga

void mundur(Player *P, int pasts, boolean is_teleport, boolean *is_immune);
// I.S. Player P berada di tempatnya, nexts + tempat saat ini ada di peta dan tidak kosong
// F.S. Player P pindah ke pasts. Jika is_teleport dan not immune dan ketemu teleporter, teleport.
// Jika immune, kasih pilihan mau ga teleport ga. P diupdate.

void teleport(Player *P, int new_petak);
// I.S. Player P berada di tempatnya, new_petak adalah petak kosong di peta
// F.S. Player P pindah ke tempat kosong tersebut. P diupdate.

*/
