#define TRUE 1
#define FALSE 0

unsigned long mulmod(unsigned long a, unsigned long b, unsigned long c); 
unsigned long powermod(unsigned long a, unsigned long m,  unsigned long n);

int miller_rabin(unsigned long n, unsigned long * p_trials) {

    unsigned long m = n - 1; 
    int k  =  0; 
    while (m % 2 == 0) {
        k ++ ; m /= 2;
    }  
    int i = 0; 
    unsigned long a; 
    while ((a = p_trials[i ++ ]) != 0) {
        if (a == n) return TRUE; 
        unsigned long apow = powermod(a, m, n);
        int p = FALSE;  
        if (apow != 1 && apow != n - 1) {
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

