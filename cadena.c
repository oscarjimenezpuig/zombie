/* ZOMBIE 5-3-26 */

#include "cadena.h"

static char* cadena=NULL;

static u16 _len(char* s) {
    /* longitud de una cadena */
    char* p=s;
    while(*p++!=EOS);
    return p-s;
}

static char* _copy(char* d,char* o) {
    /* copia de cadenas */
    char* pd=d;
    char* po=o;
    while(*po!=EOS) {
        *pd++=*po++;
    }
    *pd=EOS;
    return pd;
}

static int _equal(char* d,char* o) {
    /* igualdad entre dos cadenas */
    char* po=o;
    char* pd=d;
    while(*po!=EOS && *po==*pd) {
        po++;
        pd++;
    }
    return (*po==EOS && *pd==EOS);
}

static char* _next(char* p) {
    /* busca la siguiente cadena */
    char* pp=p;
    while(*pp!=EOS && *pp!=EOC) {
        pp++;
    }
    if(*pp==EOS) pp++;
    return pp;
}

static char* _fin(char* c) {
    /* da el puntero al final de la cadena */
    char* p=c;
    while(*p!=EOC) p++;
    return p;
}

static u16 _clen() {
    /* longitud de la cadena */
    char* f=_fin(cadena);
    return f-cadena;
}

void caddel() {
    if(cadena) {
        free(cadena);
        cadena=NULL;
    }
}

int cadset(char* c) {
    if(!cadena) {
        cadena=malloc(2);
        if(cadena) {
            *cadena=EOS;
            *(cadena+1)=EOC;
        }
    }
    if(cadena && c) {
        char* nc=cadena;
        int counter=0;
        while((nc=_next(nc)) && *nc!=EOC) {
            ++counter;
            if(_equal(nc,c)) {
                return counter;
            }
        }
        u16 len=_len(c);
        u16 clen=_clen();
        void* ptr=realloc(cadena,clen+len+2);
        if(ptr) {
            cadena=(char*)ptr;
            char* p=_fin(cadena);
            p=_copy(p,c);
            p++;
            *p=EOC;
            return counter+1;
        }
    }
    return -1;
}

int cadget(u16 p,char* s) {
    int counter=p;
    char* nc=cadena;
    while(counter-->0 &&  *(nc=_next(nc))!=EOC);
    if(*nc!=EOC){
        _copy(s,nc);
        return 1;
    }
    return 0;
}

void cadprt() {
    char* p=cadena;
    while(*p!=EOC) {
        if(*p==EOS) printf("_\n");
        else printf("%c",*p);
        p++;
    }
    printf("\n");
    printf("La longitud es de %i caracteres\n",_clen());
}



        


        


