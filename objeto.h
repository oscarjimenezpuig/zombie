/* ZOMBIE 5-3-26 */

#include "cadena.h"

objeto_t objnew(char* nombre,u8 caracteristicas);
/* cuando se define el objeto se define con dimension 2 para el nombre + el numero de caracteristicas */

u16 objsiz();
/* numero de objetos definidos hasta el momento */

int objset(objeto_t o,u8 num_car,u8 val);
/* se cambia el valor de una caracteristica del objeto */
/* nunca se puede cambiar la 0 donde esta la dimension del objeto */

int objget(objeto_t o,u8 num_car,u8* val);
/* se consigue el valor de una caracteristica concreta */

int objnom(objeto_t o,char* nom);
/* se consigue el nombre del objeto */

u16 objfnd(objeto_t* o,condicion_t c);
/* bajo una condicion se da un array de objetos que la cumplen */

void objdel();
/* se liberan todos los objetos */

void objprt(objeto_t o);
/* se imprime las caracteristicas de un objeto, si NULL de todos los objetos */

pobjeto_t pobjnew(u16 pos);
/* se crea un puntero que apunta al objeto de la posicion pos (si no existe, NULL) */

int pobjinc(pobjeto_t* pobj);
/* se incrementa en uno la posicion (si se puede) */

int pobjdec(pobjeto_t* pobj);
/* se decrementa la posicion (si se puede) */
