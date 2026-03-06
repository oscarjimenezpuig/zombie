/* ZOMBIE 5-3-26 */

#include "objeto.h"

static objeto_t* objeto=NULL;
static u16 objetos=0;

objeto_t objnew(char* n,u8 t,u8 c) {
    objeto_t no=malloc(3+c);
    if(no) {
        *no=4+c;
        int nc=cadset(n);
        if(nc!=-1) {
            *(no+1)=nc%256;
            *(no+2)=nc/256;
            *(no+3)=t;
            u8* p=no+4;
            while(p!=no+4+c) *p++=0;
            void* ptr=realloc(objeto,sizeof(objeto_t)*(objetos+1));
            if(ptr) {
                objeto=ptr;
                *(objeto+objetos++)=no;
                return no;
            }
        }
        free(no);
    }
    return NULL;
}

u16 objsiz() {
    return objetos;
}

int objset(objeto_t o,u8 n,u8 v) {
    if(o && n<o[0] && n>0) {
        o[n]=v; 
        return 1;
    }
    return 0;
}

int objget(objeto_t o,u8 n,u8* v) {
    if(o && n<o[0] && n>0) {
        *v=o[n]; 
        return 1;
    }
    return 0;
}

int objnom(objeto_t o,char* n) {
    if(o) {
        u16 id=o[1]+o[2]*256;
        return cadget(id,n);
    }
    return 0;
}

u16 objfnd(objeto_t* o,condicion_t c) {
    objeto_t* pod=o;
    objeto_t* pos=objeto;
    while(pos!=objeto+objetos) {
        if(c(*pos)) *pod++=*pos;
        pos++;
    }
    return pod-o;
}

void objdel() {
    if(objeto) {
        objeto_t* p=objeto;
        while(p!=objeto+objetos) {
            free(*p);
            p++;
        }
        free(objeto);
        objeto=NULL;
        objetos=0;
    }
}

void objprt(objeto_t o) {
    if(o) {
        int dim=o[0];
        for(int k=0;k<dim;k++) printf("%03i ",o[k]);
        printf("\n");
    } else {
        for(int k=0;k<objetos;k++) {
            objprt(objeto[k]);
        }
    }
}

pobjeto_t pobjnew(u16 pos) {
    if(pos<objetos) {
        return objeto+pos;
    }
    return NULL;
}

int pobjinc(pobjeto_t* pobj) {
    if(!pobj || *pobj+1==objeto+objetos) {
        *pobj=NULL;
        return 0;
    } else {
        *pobj=*pobj+1;
        return 1;
    }
}

int pobjdec(pobjeto_t* pobj) {
    if(!pobj || *pobj==objeto) {
        *pobj=NULL;
        return 0;
    } else {
        *pobj=*pobj-1;
        return 1;
    }
}
                
