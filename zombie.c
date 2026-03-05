/* ZOMBIE 5-3-26 */

#include "objeto.h"

int con(objeto_t o) {
    return o[0]==6;
}

int main() {
    objnew("Caca",1);
    objnew("Pipi",2);
    objnew("Zurullo",3);
    objnew("Caca",3);
    objeto_t od[objsiz()];
    uint ods=objfnd(od,con);
    for(int k=0;k<ods;k++) {
        objprt(od[k]);
    }
    objdel();
    caddel();
    return 0;
}
