/* ZOMBIE 5-3-26 */

#include "tipos.h"

void caddel();
/* libera el espacio de la cadena */

int cadset(char* cad);
/* se introduce una nueva cadena, se devuelve el valor o -1 si hay error */

int cadget(u16 pos,char* str);
/* copia la cadena en posicion pos en str, devuelve 0 si no puede */

void cadprt();
/* imprime todo el archivo cadena hasta el final, separaciones marcadas por saltos de linea */
