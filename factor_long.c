#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>
#define MAX_LIST 2048 
#define TRUE 1
#define FALSE 0
int prime_list[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97, \
                    101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,\
                    193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,\
                    293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,\
                    409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,\
                    521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,\
                    641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,\
                    757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,\
                    881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997, 0  }; 

int factor(unsigned long n, unsigned long * factor_list) {
    int count  = 0; int p; 
    while (TRUE) {
        unsigned long sq = sqrt(n) ;
        int i = 0; int ith_prime;p = FALSE;  
        while ((ith_prime = prime_list[i ++ ]) != 0) {
            if (n == 1)  return count; 
            if (ith_prime>sq) {factor_list[count++]=n;return count ;}
            if (n % ith_prime  == 0) {
                factor_list[count ++ ] = (unsigned long)ith_prime; 
                n /= ith_prime;
                p = TRUE ;
                break;   
            }
        }
        if (p) continue;
        p = FALSE; 
        for(unsigned long j = prime_list[i - 2]; j <= sq ;j += 2) {
            if (n % j  == 0 ) {
                factor_list[count ++ ]  = j;
                n /= j;
                //if (n <= 2) return count - 1;   
                // if (count >= MAX_LIST) return - n + 1;
                p = TRUE;   
                break; 
            } 
        }
        if (!p) {
            factor_list[count ++ ] = n; 
            return count;
        }
    }
}

int ifactor(mpz_t n, mpz_ptr * factor_list) {
    int count = 0, p;
    mpz_ptr sq=(mpz_ptr)malloc(sizeof(MP_INT)) ; mpz_init(sq);
    mpz_ptr i=(mpz_ptr) malloc(sizeof(MP_INT));  mpz_init(i);
    mpz_ptr wp=(mpz_ptr)malloc(sizeof(MP_INT)),wm=(mpz_ptr)malloc(sizeof(MP_INT)) ; mpz_init(wp); mpz_init(wm);
    mpz_ptr q=(mpz_ptr)malloc(sizeof(MP_INT)),r=(mpz_ptr)malloc(sizeof(MP_INT));mpz_init(q);mpz_init(r);
    mpz_ptr L_TWO=(mpz_ptr)malloc(sizeof(MP_INT)),L_THREE=(mpz_ptr)malloc(sizeof(MP_INT));mpz_init_set_ui(L_TWO,2);mpz_init_set_ui(L_THREE,3);
    while (TRUE) {printf("p:%s",mpz_get_str(NULL,10,n));if (count !=0) printf(" q:%s",mpz_get_str(NULL,10,factor_list[count-1]));printf("\n");
        if (mpz_cmp_ui(n,1)==0) return count;
        mpz_tdiv_qr_ui(q,r,n,2);
        if (mpz_cmp_ui(r,0)==0) {
            factor_list[count++]=L_TWO;
            mpz_set(n,q);
            continue;
        }
        mpz_tdiv_qr_ui(q,r,n,3);
        if (mpz_cmp_ui(r,0)==0) {
            factor_list[count++]=L_THREE;
            mpz_set(n,q);
            continue;
        }

        //sq =sqrt(n);
        mpz_sqrt(sq, n) ;mpz_add_ui(sq,sq,2);
        //i = 6;
        mpz_set_ui(i, 6L);
        p = FALSE;
        while (mpz_cmp(i,sq)<0) {
            mpz_sub_ui(wm,i,1L);
            mpz_tdiv_qr(q,r,n,wm);
            if (mpz_cmp_ui(r, 0)==0) {
                factor_list[count++]=wm;
                mpz_set(n,q);
                p = TRUE;
                break;
            }
            mpz_add_ui(wp,i,1L);
            mpz_tdiv_qr(q,r,n,wp);
            if (mpz_cmp_ui(r,0) == 0) {
                factor_list[count++]=wp;
                mpz_set(n,q);
                p = TRUE;
                break;
            }
            mpz_add_ui(i,i,6);
        }
        if (!p) {
            factor_list[count++] = n;
            return count;
        }
    }
}
/* 
int factor(unsigned long n, unsigned long * factor_list) {
    int count  = 0; 
    while (TRUE) {
        unsigned long sq = sqrt(n) ; 
        if (n%2 == 0) {
            factor_list[count ++ ] = 2L; 
            n /= 2;
            continue;
        }
        int p = FALSE; 
        for(unsigned long i = 3; i <= sq ;i += 2) {
            if (n % i  == 0 ) {
                factor_list[count ++ ]  = i;
                n /= i;t
                if (n <= 2) return count - 1;   
                // if (count >= MAX_LIST) return - n + 1;
                p = TRUE;   
                break; 
            } 
        }
        if (!p) {
            factor_list[count ++ ] = n; 
            return count;
        }
    }
} 
 */ 
int main(int argc, char * argv[]) {
    // 最大の素因数を持つ2^64-1以下の整数をきちんと分解できることを確認
    // 18446744030759878681=4294967291*4294967291
    // また最大の64bit整数の素因数分解は以下
    // 18446744073709551615 = 3*5*17*257*641*65537*6700417
    //unsigned long n = atol(argv[1]), m = 1;printf("%lu\n",n); 
    mpz_t n,m,l;
    mpz_init_set_str(n,argv[1],10);mpz_init_set(l,n);
    printf("%s\n",mpz_get_str(NULL,10,n)); 
    mpz_ptr *factor_list=(mpz_ptr*)malloc(MAX_LIST*sizeof(MP_INT));
    mpz_init_set_ui(m,1);
    int count = ifactor(n, factor_list); 
    //int count = factor(n, factor_list); 
    for(int i = 0; i< count; i ++ ) {
        mpz_mul(m, m, factor_list[i]); 
        printf("%s ", mpz_get_str(NULL,10, factor_list[i])); 
    }
    if (mpz_cmp(l, m)==0) {printf("OK\n");} 
    else {printf("NG! %s %s\n", mpz_get_str(NULL,10,l), mpz_get_str(NULL,10,m));} 
}    
