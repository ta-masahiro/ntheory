#include <stdio.h>
#include <stdlib.h>
#include  <time.h>
#define TRUE 1
#define FALSE 0

unsigned long mulmod(unsigned long a, unsigned long b, unsigned long c); 
unsigned long powermod(unsigned long a, unsigned long m,  unsigned long n) {
    unsigned long ans = 1; 
    unsigned long apow = a; 
    while (m  != 0) {
         // if (m%2  != 0) ans = (ans * apow)%n;
         if (m%2 != 0) ans = mulmod(ans, apow, n);   
         // apow = (apow * apow)%n;
        apow = mulmod(apow, apow, n);   
        m /= 2; // printf("ans= %ld m= %ld apow= %ld\n", ans, m, apow);  
    } 
    return ans %n; 
}

int miller_rabin(unsigned long n, unsigned long * p_trials) {

    // if (n<0) n =  - n; 
    // if (n == 2 || n == 3 || n == 61) return TRUE;
    // if (n <= 4) return FALSE; 
    // if (n >= 4294967296L) {printf("Too large number!\n");return 0;}  

    unsigned long m = n - 1; 
    int k  =  0; 
    while (m % 2 == 0) {
        k ++ ; m /= 2;
    }  // printf("k= %d m= %ld\n", k, m); 
    int i = 0; 
    unsigned long a; 
    while ((a = p_trials[i ++ ]) != 0) {
        if (a == n) return TRUE; 
        unsigned long apow = powermod(a, m, n);
         // printf("apow= %ld a= %ld m= %ld n= %ld\n", apow, a, m, n);    
        int p = FALSE;  
        if (apow != 1 && apow != n - 1) {
             // p = FALSE; 
            for(int r = 0; r<k - 1; r ++ ) {
                 // apow = (apow * apow)%n;
                 apow = mulmod(apow, apow, n);  
                if (apow == n - 1) {p = TRUE; break; }
            }
            if (!p) return FALSE;
        } 
    } 
    return TRUE; 
}

#define NO_OF_TRIALS 20

int is_prime(unsigned long n) {
    unsigned long p_t1[] = {2, 3, 61, 0}; 
    unsigned long p_t2[] = {2, 3, 5, 7, 11, 13, 17, 0};
    unsigned long p_t3[NO_OF_TRIALS + 1];
    unsigned long * p_trials;

    if (n<0) n =  - n; 
    switch(n) {
        case 2: case 3: case 5: return TRUE; 
        case 1: case 4: return FALSE;
    }
    switch(n % 30){
        case 1:  case 7: case 11: case 13: case 17: case 19: case 23:  case 29: 
            if (n < 4759123141L) p_trials =  p_t1; 
            else if(n < 341550071728321L) p_trials = p_t2;
            else { 
                for(int i = 0; i<NO_OF_TRIALS; i ++ ) p_t3[i] = mulmod((long)rand() , (long)rand(),n-2)+1;
                p_t3[NO_OF_TRIALS] = 0;p_trials = p_t3;   
            } 
            return miller_rabin(n, p_trials); 
        default: return FALSE;
    } 
}
unsigned long next_prime(unsigned long n) {
    n ++ ; 
    while (TRUE) {
        if (is_prime(n)) return n; 
        n ++ ; 
    }   
}

// test ????????????
// ???????????????????????????3?????????n, m, l????????????n??????m?????????????????????????????????????????????
// l???0?????????????????????????????????????????????
  
int main(int argc, char  *  argv[]) {
     // unsigned long n = atol(argv[1]); 
     // printf("%ld\n", next_prime(n)); 
     unsigned long n = atol(argv[1]), nn = n;  
     unsigned long m = atol(argv[2]);
     // unsigned long n = 1073741824, nn = n, m = n + 100; 
     int l = atoi(argv[3]);
     // int l = 1;   
    unsigned long c = 0;
    srand((unsigned)time(NULL));
    printf("____test of IS_PRIME___\n"); 
    for(; n<m; n ++ ) {
       if (is_prime(n)) {
           c ++ ; 
           if (l) printf("%ld ", n);
       }
    }
    printf("\n%ld\n", c); 
    /* 
    printf("___test of NEXT_PRIME___\n");
    c = 0;  
    while (TRUE) { 
        nn = next_prime(nn);  
        if (nn >= m) break; 
        c ++ ; 
        if (l) printf("%ld ", nn);
    }
    printf("\n%ld\n", c); 
     */ 
}

