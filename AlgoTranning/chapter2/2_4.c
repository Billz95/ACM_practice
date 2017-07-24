#include <stdio.h>
#include <time.h>
#define MOD 1000000

long long get_six ( long long in){
    return in % 1000000;
}
int main(int argc, const char *argv[])
{
    long long sum = 0;
    long long n;
    scanf("%lld", &n);
    long long last_term = 1;
    int i = 1;

    if ( n > 25) n = 25;

    for (; i < n; i++){
        last_term = last_term * i % MOD;
        printf("%lld\n", last_term);
        sum = (sum + last_term) % MOD;
    }
    printf("%lld\n", sum);
    printf("time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);



    return 0;
}
