/*
ルーカスレーマーテスト
メルセンヌ数(2^p-1;pは素数)が素数か否かを高速で判定する
*/
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#define TRUE -1
#define FALSE 0
int lucasLehmerTest(int p) {
    mpz_t m, s, sq; mpz_init(sq);
    // m = 2^p -1　判定すべきメルセンヌ数
    mpz_init_set_ui(m, 1); mpz_mul_2exp(m, m, p); mpz_sub_ui(m, m, 1);
    // s = 4 
    mpz_init_set_ui(s, 4); 
    for (int i = 2; i < p; i ++ ) {
        // s = (s*s & m) + (s*s)>>p	として、 s >= m なら s = s - m、 そうでないなら s = s - 2 とすれば 
        // 除算を使うことなく s = (s*s-2)%m が計算できる※mはpビットgべてが1dある数なので
        mpz_mul(sq, s, s); 
        mpz_and(s, sq, m); 
        mpz_div_2exp(sq, sq, p);
        mpz_add(s, s, sq);
        // if s >= m then s-=m else s-=2
        if (mpz_cmp(s, m)>=0) mpz_sub(s, s, m);
        mpz_sub_ui(s, s, 2);
    }
    if (mpz_cmp_ui(s, 0) == 0) return TRUE;
    return FALSE;
}
/*
#32 (p=756,839)を約40分で判定
#33 (p=859,433)を約50分で判定
#35 (p=1,398,269)を約140分で判定
core i5 3210M 2.5Ghz RAM 8Gbyte 
WSL ubuntu20.04 gcc 9.40
*/
int main(int argc, char * argv[]) {
    int p = atoi(argv[1]);
    if (lucasLehmerTest(p) == TRUE) printf("2^%d-1 is PRIME\n",p);else printf("2^%d-1 isn't PRIME\n",p);
}
