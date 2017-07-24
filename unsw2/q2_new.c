#include <stdio.h>
#include <math.h>
int main(int argc, const char *argv[])
{
    long long input;
    char primes[10000000] = {0};

    // generate table
    int i, j;
    for ( j = 2; j < 5000000;) {
        /** printf("%d\n", j); */
        for ( i = j; i+j < 10000000;) {
            i += j;
            primes[i] = 1;
        }
        j++;
        while (primes[j] && j < 5000000) j++;
    }
    /** fprintf(stderr, "here\n"); */

    int curlen = 0;
    while (scanf("%lld", &input) == 1) {
        long long i = 2;
        printf("1");

        long long temp = input;
        int j;
        /** for ( j = 0; temp != 1  && j < curlen; j++){ */
        /** if (temp % primes[j] == 0){ */
        /** printf(" x %lld", primes[j]); */
        /** temp /= primes[j]; */
        /** } */
        /** } */
        while ( i <= sqrt(temp) && temp != 1) {
            if (temp % i == 0) {
                printf(" x %lld", i);
                /** if (i != primes[curlen]) */
                /** primes[curlen++] = i; */
                temp /= i;
            } else {
                i++;
                while ( primes[i] == 1 && i <= sqrt(temp)) i++;
            }
        }
        if ( i > sqrt(temp) && temp != 1) printf(" x %lld" ,temp);
        printf("\n");

    }
}
