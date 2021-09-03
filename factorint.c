#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

Vector * factor_int(unsigned long n) {
    Vector * v = vector_init(3); 
    if (n == 1||n==2||n==3||n==5) {push(v, (void * )n) ;return v; }
    if (n==4) {push(v, (void * )2L); push(v, (void * )2L); return v;
    unsigned long i=7;
    switch (n%30) {
        case  0: case  2: case  4: case  6: case  8: case 10: case 12: case 14 
        case 16: case 18: case 20: case 22: case 24: case 26: case 28:
            return push(factor_int(n / 2), 2L);  
        case  3: case  9: case 15: case 21: case 27: 
            return push(factor_int(n / 3), 3L); 
        case  5: case 25: 
            return push(factor_int(b / 5), 5L); 
        default: 
            while (i*i<=n) {
                    if (n%i==0) {return vector_append(factor_int(n /i),factor_int(n);}
                    i+=4;
                    if (n%i==0) return FALSE;
                    i+=2;
                    if (n%i==0) return FALSE;
                    i+=4;
                    if (n%i==0) return FALSE;
                    i+=2;
                    if (n%i==0) return FALSE;
                    i+=4;
                    if (n%i==0) return FALSE;
                    i+=6;
                    if (n%i==0) return FALSE;
                    i+=2;
                    if (n%i==0) return FALSE;
                    i+=6;
            }
            push(v, (void * )n); return v;  
    }
}
int main(int argc, char* argv[]) {
    unsigned long n=atol(argv[1]);
    unsigned long m=atol(argv[2]);
    unsigned long l=atol(argv[3]);
    unsigned long c=0;
    for(;n<m;n++) {
        if (trial_div(n)) {c++;if (l) printf("%lu ",n);}
    }
    printf("\n");
    printf("%lu\n",c);
}
