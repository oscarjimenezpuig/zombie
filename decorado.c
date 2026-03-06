/* ZOMBIE 6-3-26 */

#include "decorado.h"

objeto_t d_agua,d_aguap,d_prado,d_bosque,d_monte,d_pico;

#define lopd FOR(k,0,NUMDEC)

static int decnew(objeto_t* obj,char* n,u8 id,char c,u8 col) {
    if((*obj=objnew(n,TIPDEC,DNC))) {
        objset(*obj,DID,id);
        objset(*obj,DCR,c);
        objset(*obj,DCL,col);
        return 1;
    }
    return 0;
}


void decini() {
    objeto_t obs[]={d_agua,d_aguap,d_prado,d_bosque,d_monte,d_pico};
    char* nom[]={AGNO,APNO,PRNO,BSNO,MNNO,MANO};
    char chr[]={DCRAG,DCRAP,DCRPR,DCRBS,DCRMO,DCRMA};
    u8 col[]={DCLAG,DCLAP,DCLPR,DCLBS,DCLMO,DCLMA};
    lopd {
        if(!decnew(obs+k,nom[k],k+1,chr[k],col[k])) printf("%s no definido",nom[k]);
    }
}

#undef lopd
    
    
    
    
