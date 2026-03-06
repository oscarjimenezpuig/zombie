/* ZOMBIE 5-3-26 */

#include "zombie.h"

/* generales */
#define EOS 0 /* final de un string */
#define EOC 1 /* final de la cadena */

#define NULO 0 /* valor nulo */

/* macros */
#define COLV(I,P) ((I)+(P)*8) /* codigo correspondiente al color */
#define COLGI(V) ((V)%8) /* tinta a partir del codigo de color */
#define COLGP(V) ((V)/8) /* paper a partir del codigo de color */
#define FOR(V,I,L) for(int V=(I);V<(L);V++) /* bucle for */

/* objeto */
#define ONCS 0 /* numero de caracteristica que nos da el tamaño del objeto */
#define ONCN 1 /* numero de caracteristica donde empieza el nombre (tiene dimension 2) */
#define ONCT 3 /* numero de caracteristica donde esta el tipo del objeto */

/* tipos objeto */
#define TIPDEC 1 /* decorado */

/* decorado */
/* tipos de caracteristicas */
#define DNC 3 /* numero de caracteristicas que tiene un decorado */
#define DID 3 /* identidad del decorado */
#define DCR 4 /* caracter del decorado */
#define DCL 5 /* color del decorado */
/* valores de caracteristicas */
#define NUMDEC 6 /* numero de decorados */
/* agua poco profunda */
#define AGNO "agua poco profunda"
#define DIDAG 1
#define DCRAG  '~'
#define DCLAG COLV(BLUE,CYAN)
/* agua profunda */
#define APNO "agua profunda"
#define DIDAP 2
#define DCRAP '~'
#define DCLAP COLV(CYAN,BLUE)
/* prado */
#define PRNO "prado"
#define DIDPR 3
#define DCRPR ' '
#define DCLPR COLV(GREEN,GREEN)
/* bosque */
#define BSNO "bosque"
#define DIDBS 4
#define DCRBS '|'
#define DCLBS COLV(RED,GREEN)
/* monte */
#define MNNO "monte"
#define DIDMO 5
#define DCRMO ' '
#define DCLMO COLV(MAGENTA,MAGENTA)
/* monte alto */
#define MANO "pico"
#define DIDMA 6
#define DCRMA ' '
#define DCLMA COLV(WHITE,WHITE)

/* mapa */
#define MAPC 240 /* columnas totales del mapa */ 
#define MAPR 240 /* filas totales del mapa */

#define LFVIS 7 /* localidad bandera que dice el obstaculo */
#define LFVST 8 /* localidad, bandera que dice si es visto */
#define LFVIS 16 /* localidad, bandera que dice si es visible acutalmente */






