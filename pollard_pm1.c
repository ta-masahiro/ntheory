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
    mpz_t m; mpz_set_init_ui(m, b); 
    mpz_t mm1; mpz_init(mm1); 
    mpz_t g; mpz_init(g); 

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
    int b=atoi(argv[2]);
    int maxC=atoi(argv[3]);
    if (mpz_probab_prime_p (n,20)) 
        printf("%s is prime\n",mpz_get_str(NULL,10,n));
    //else if (pollard_rho(n,d)) {
    else if (pollard_pm1(n, d, b, maxC)) {
        mpz_tdiv_q(n,n,d);
        printf("%s is  %s * %s\n",  argv[1], mpz_get_str(NULL,10,d), mpz_get_str(NULL,10,n));
    } else printf("pollard p-1 method fail!\n");
}
