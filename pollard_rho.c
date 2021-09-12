#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#define TRUE 1
#define  FALSE 0

//gmp_randstate_t state1;
//gmp_randstate_t state2;

int pollard_rho(mpz_t n, mpz_t d) {
    mpz_t x, y;
    mpz_init_set_ui(x,2);mpz_init_set_ui(y,2);mpz_set_ui(d,1);
    while (mpz_cmp_ui(d,1)==0) {
        mpz_mul(x,x,x);mpz_add_ui(x,x,1);mpz_tdiv_r(x,x,n);
        //mpz_urandomm(x,state1,n);
        mpz_mul(y,y,y);mpz_add_ui(y,y,1);mpz_tdiv_r(y,y,n);
        //mpz_urandomm(y,state2,n);
        mpz_mul(y,y,y);mpz_add_ui(y,y,1);mpz_tdiv_r(y,y,n);
        mpz_sub(d,x,y);mpz_abs(d,d);
        mpz_gcd(d,d,n);
       // printf("2:%s\n",mpz_get_str(NULL,10,d));
    }
    if (mpz_cmp(d,n) == 0) return FALSE;
    return TRUE;
}

int pollard_rho_(mpz_t n, mpz_t d, unsigned long max, unsigned long maxc) {
    mpz_t x, y;mpz_init(x);mpz_init(y);
    unsigned long trial, c;
    for( c=1;c <=maxc; c++) {
        trial = 0;
        mpz_set_ui(x,2);mpz_set_ui(y,2);mpz_set_ui(d,1);
        while (mpz_cmp_ui(d,1)==0 &&  trial++ < max ) {
            mpz_mul(x,x,x);mpz_add_ui(x,x,c);mpz_tdiv_r(x,x,n);
            mpz_mul(y,y,y);mpz_add_ui(y,y,c);mpz_tdiv_r(y,y,n);
            mpz_mul(y,y,y);mpz_add_ui(y,y,c);mpz_tdiv_r(y,y,n);
            mpz_sub(d,x,y);mpz_abs(d,d);
            mpz_gcd(d,d,n);
        }
        if (mpz_cmp(d,n) == 0) continue;
        if  (trial<max) return TRUE;
    }
    return FALSE;
}
// 8番目のフェルマー数2^256+1=115792089237316195423570985008687907853269984665640564039457584007913129639937
// を1分40秒で因数分解できた(ASUSにて)
// 1238926361552897 * 93461639715357977769163558199606896584051237541638188580280321
int main(int argc, char * argv[]) {
    //gmp_randinit_default(state1);
    //gmp_randinit_default(state2);
    mpz_t  d; mpz_init(d);
    mpz_t  n; mpz_init_set_str(n, argv[1], 10);
    int max=strtoul(argv[2],0,10);
    int maxc=strtoul(argv[3],0,10);
    if (mpz_probab_prime_p (n,20)) 
        printf("%s is prime\n",mpz_get_str(NULL,10,n));
    //else if (pollard_rho(n,d)) {
    else if (pollard_rho_(n,d,max ,maxc)) {
        mpz_tdiv_q(n,n,d);
        printf("%s is  %s * %s\n",  argv[1], mpz_get_str(NULL,10,d), mpz_get_str(NULL,10,n));
    } else printf("pollard_rho method fail!\n");
}