#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_LIST 64 
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
                n /= i;
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
    //unsigned long n = atol(argv[1]), m = 1;printf("%lu\n",n); 
    unsigned long n = strtoul(argv[1],0,10), m = 1;printf("%lu\n",n); 
    unsigned long factor_list[MAX_LIST];
    
    int count = factor(n, factor_list); 
    for(int i = 0; i< count; i ++ ) {
        m *=  * (factor_list + i); 
        printf("%lu ",  * (factor_list + i)); 
    }
    if (n == m) {printf("OK\n");} 
    else {printf("NG! %lu %lu\n", n, m);} 
}    
