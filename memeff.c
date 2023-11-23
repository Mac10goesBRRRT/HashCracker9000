#include <stdio.h>

FILE *fptr;

long modular_pow(int base, int exp, int mod){
    if(mod == 1)
        return 0;
    long c = 1;
    for(int e_prime = 0; e_prime < exp; e_prime++){
        c = (long)(c*base)% mod;
    }
    return c;
}

int main(){
    //int mod = 1999993;
    int mod = 200;
    int M = 1000;
    int m = 1234567;
    char name[] = "resultsX.txt";
    name[7] = '1';
    fptr = fopen(name,"w");

    for(int i = 0; i < mod; i++){
        int value = modular_pow(i,m,mod);
        //fprintf(fptr, "%7d,%7d\n", i, value);
    }
    fclose(fptr);
    printf("done");
}
