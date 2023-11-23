#include <stdio.h>
#include <string.h>

long modular_pow(int base, int exp, int mod){
    if(mod == 1)
        return 0;
    long c = 1;
    for(int e_prime = 0; e_prime < exp; e_prime++){
        c = (long)(c*base)% mod;
    }
    return c;
}

long rtlbinary(long base, long exponent, long modulus){
    if(modulus == 1)
        return 0;
    long result = 1;
    base = base%modulus;
    while (exponent > 0){
        if(exponent%2 == 1)
            result = (result*base) % modulus;
        exponent = exponent >> 1;
        base = (base * base)%modulus;
    }
    return result;
}

void crackhash (int hashvalue, int exponent, int modulus, int elemstohash){
    int hashed_mess;
    for(int i = 0; i <= elemstohash; i++){
        hashed_mess = rtlbinary(i, exponent, modulus);
        if(hashed_mess == hashvalue)
            printf("Message: %7d with Hashed Value %7d\n", i, hashvalue);
    }
}


int main(int argc, char* argv[]){
    if(argc != 3)
        return 1;
    int me = atoi(argv[1]);
    int num_mess = atoi(argv[2]);
    printf("Cracking hashes for MatrNr: %d, with Messages up to %d\n", me, num_mess);
    int elems_to_hash = num_mess;
    int mod = 1999993;
    int M = 1;
    int m = me;
    int hash = 0;
    int array[mod];
    int collision_hash;
    int message;
    int col_count = 0;
    memset(array, -1, sizeof(array)); 
    printf("start\n");
    for(int i = 0; i <= elems_to_hash; i++){
        hash = rtlbinary(i, m, mod);
        if(array[hash] != -1) {
            printf("For %7d\n", i);
            col_count++;
            crackhash(hash, m, mod, elems_to_hash);
        }
        array[hash] = hash;
    }
    printf("done, with %d collisions found\n", col_count);
}