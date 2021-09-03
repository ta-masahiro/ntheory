unsigned long mulmod(unsigned long a, unsigned long b, unsigned long c); 

unsigned long powermod(unsigned long apow, unsigned long m,  unsigned long n) {
    unsigned long ans = 1; 
     // unsigned long apow = a; 
    while (m  != 0) {
         // if (m%2  != 0) ans = (ans * apow)%n;
         if (m%2 != 0) ans = mulmod(ans, apow, n);   
         // apow = (apow * apow)%n;
        apow = mulmod(apow, apow, n);   
        m /= 2; // printf("ans= %ld m= %ld apow= %ld\n", ans, m, apow);  
    } 
    return ans %n; 
}
