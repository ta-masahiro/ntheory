#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int trial_div(unsigned long n) {
    if (n<0) n=-n;
    if (n==2||n==3||n==5) return TRUE;
    if (n==1||n==4) return FALSE;
    unsigned long i=7;
    switch (n%30) {
        case 1:  case 7: case 11: case 13: case 17: case 19: case 23:  case 29:
            while (i*i<=n) {
                    if (n%i==0) return FALSE;
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
            return TRUE;
        default: return FALSE;
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