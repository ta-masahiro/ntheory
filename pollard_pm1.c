 //   pollard_pm1 : ポラードの p-1 法を使い素因数分解を行う
 //
 //   n 素因数分解を行う対象の数
 //   g 発見された因数
 //   b 底(初期値として与える)
 //   maxC 最大処理回数(指数の最大値 + 1)
 //
 //   戻り値 : 素因数分解に成功したらTRUEを返す
 #include  <stdio.h>
 #include <stdlib.h>
 #include <gmp.h>
 #define TRUE 1
 #define FALSE 0

int pollard_pm1(mpz_t n, mpz_t g, unsigned long b, unsigned long maxC ) {
    mpz_t m; mpz_init_set_ui(m, b); 
    mpz_t mm1; mpz_init(mm1); 

    for ( unsigned long c = 0 ; c < maxC ; ++c ) {
        mpz_powm_ui(m, m, c + 1, n); 
        mpz_sub_ui(mm1, m, 1); 
        mpz_gcd(g, mm1, n); 
        if (mpz_cmp_ui(g, 1) == 0) continue; 
        if (mpz_cmp(g, n) == 0) return FALSE; 
        return TRUE;
    }
    return FALSE;
}

int main(int argc, char * argv[]) {
    mpz_t  d; mpz_init(d);
    mpz_t  n; mpz_init_set_str(n, argv[1], 10);
    int b=strtoul(argv[2], 0, 10);
    int maxC=strtoul(argv[3], 0, 10);
    while (mpz_probab_prime_p (n,20) == 0) {
        if (pollard_pm1(n,d,b,maxC)) {
            mpz_tdiv_q(n,n,d);
            printf("%s ", mpz_get_str(NULL,10,d));
        } else {
            printf(" pollard p-1 method fail! in %s\n", mpz_get_str(NULL,10,n));
            return 0;
        }    
    }
    printf("%s\n",mpz_get_str(NULL,10,n));
}
