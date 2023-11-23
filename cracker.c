#include <math.h>
#include <stdio.h>

int main (){
    printf("hehe\n");
    unsigned long long value = 0;
    unsigned long long  MatrNr;
    unsigned long long  MatrNrTest = 1234567;
    unsigned long long  modValue = 1999993;
    unsigned long long  M = 1000;
    unsigned long long  h = (unsigned long long) pow((double)M, (double)MatrNrTest);
    h = h%modValue;
    printf("%llu\n", h);
}
