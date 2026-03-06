/* ZOMBIE 6-3-26 */

#include "mapa.h"

static u8 mapa[MAPR][MAPC];

#define frr FOR(r,0,MAPR)
#define frc FOR(c,0,MAPC)

#define INMAP(R,C) ((R)>=0 && (R)<MAPR && (C)>=0 && (C)<MAPC)

static void mapinsdec(int r,int c,u8 v) {
    /* introduccion del decorado en una localidad */
    map[r][c]=v;
}

static void mapclr() {
    /* pone todos los decorados del mapa en agua profunda */
    frr {
        frc {
            mapa[r][c]=DIDAP;
        }
    }
}




void mapsetloc(int r,int c,u8 f) {
    if(INMAP(r,c)) map[r][c]|=f;
}

void mapunsetloc(int r,int c,u8 f) {
    if(INMAP(r,c)) map[r][c]&=(~f);
}

int mapisin(int r,int c) {
    return INMAP(r,c);
}

