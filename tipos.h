/* ZOMBIE 5-3-26 */

#include "constantes.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef u8* objeto_t; 
/* tipo objeto que se define como una matriz de numeros sin signo */
/* el primer numero da la dimension de datos que contiene */
/* el segundo y el tercer numero se corresponde a la posicion que ocupa el nombre */

typedef objeto_t* pobjeto_t;
/* puntero a objeto */

typedef int condicion_t(objeto_t);
/* condicion para encontrar objetos */
