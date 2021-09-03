#include <stdio.h>
#include <stdlib.h>

unsigned long powermod(unsigned long a, unsigned long b,  unsigned long c); 

int main(int argc, char * argv[]) {
    unsigned long a = atol(argv[1]); 
    unsigned long b = atol(argv[2]); 
    unsigned long c = atol(argv[3]); 

    printf("%lu %lu %lu\n", a, b, c); 
    printf("powepod:  %lu\n", powermod(a, b, c)); 
} 
