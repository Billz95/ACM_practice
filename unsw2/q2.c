#include <stdio.h>
int main(int argc, const char *argv[])
{
    /** int input; */
    /** scanf("%d", &input); */

    // generate prime table
    int i, j;
    long long primes[100000] = {0};
    int curlen = 0;

    for ( i = 2; i < 100000; i++) {
        int isPrime = 1;
        for ( j = 0; j < curlen; j++) {
            if ( i % primes[j] == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime){
            primes[curlen++] = i;
        }
    }
    printf("prime len %d", curlen);


    return 0;
}
