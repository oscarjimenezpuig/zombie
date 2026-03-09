/* creacion de organismos celulares para reproducir un mapa */

#define frl(V,I,L) for(V=(I);V<(L);(V)++)

static int _vecinos(int valor,int r,int c) {
    /* calcula el numero de vecinos que tiene r,c */
    int vec=0;
    int rr,cc;
    frl(rr,r-1,r+2) {
        frl(cc,c-1,c+2) {
            if((rr!=r || cc!=c) && rr>0 && rr<CR && cc>0 && cc<CC) {
                if(malla[rr][cc]==valor) vec++;
            }
        }
    }
    return vec;
}

static void _genera(int base,int valor,int r,int c) {
    /* si la base esta presente en la posicion, miraremos si puede generar el valor */
    if((malla[r][c] & base) != 0) {
        int vec=_vecinos(valor,r,c);
        if(rand()%9<vec) malla[r][c]=valor;
    }
}

static void _reproduccion(int valor,int ciclos,int base) {
    /* da el desarrollo celular */
    int ci;
    frl(ci,0,ciclos) {
        int r,c;
        frl(r,0,CR) {
            frl(c,0,CC) {
                _genera(base,valor,r,c);
            }
        }
    }
}

static int _inicial(int valor,int inicial,int base) {
    /* inicio de la reproduccion celular con un numero y la base */
    int real=0;
    int n;
    frl(n,0,inicial) {
        int r=rand()%CR;
        int c=rand()%CC;
        if(malla[r][c] & base) {
            malla[r][c]=valor;
            real++;
        }
    }
    return real;
}

void celset(int v,int i,int b,int c) {
    /* reproduccion celular de un valor */
    if(_inicial(v,i,b)==0) printf("Valor %i no presente",v);
    _reproduccion(v,c,b);
}

void celini(int v) {
    int r,c;
    frl(r,0,CR) {
        frl(c,0,CC) {
            malla[r][c]=v;
        }
    }
}

static int col(char* s) {
    printf("\033[%sm",s);
    return 1;
}

static int color(int v) {
    char cad[20];
    int vv=0;
    while(v) {
        vv++;
        v=v>>1;
    }
    sprintf(cad,"%i",vv+40);
    return col(cad);
}

void celprt() {
    int r,c;
    frl(r,0,CR) {
        frl(c,0,CC) {
            color(malla[r][c]);
            printf(" ");
            printf("\033[0m");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    celini(1);
    celset(2,100,1,5);
    celset(4,20,2,5);
    celset(8,50,1,5);
    celset(16,20,8,5);
    celprt();
}






    
