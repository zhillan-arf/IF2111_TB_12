#include "../boolean.h"
#include "array_buff.h"

void ResetTabBuff(array_buff * B ){
    for (int i = 0; i < MaxBuff; i++) BUFF(B, i) = true;
}
