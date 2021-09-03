#include <stdio.h>
#include <stdlib.h>

unsigned long mulmod(unsigned long a, unsigned long b, unsigned long c); 

int main(int argc, char * argv[]) {
    unsigned long a = atol(argv[1]); 
    unsigned long b = atol(argv[2]); 
    unsigned long c = atol(argv[3]); 
    printf("a = %lu b = %lu c = %lu\n", a, b, c); 
    printf("in c: %lu  in asm:  %lu\n", (a * b) %c, mulmod(a, b, c)); 
}
