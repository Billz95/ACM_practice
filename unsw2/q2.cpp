#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pair;
typedef long long LL;
const int MAX_V  = 100;
const int MAX_E = 1e4+10;
const int maxn = 1e5+10;
unordered_map<LL,int> mp;

int main(int argc, char const *argv[]) {
    long long input;
    int curlen = 0;
    while (scanf("%lld", &input) == 1){
        long long i = 2;
        printf("1");

        long long temp = input;
        int j;
        for ( j = 0; j < curlen; j++){
            if (temp % primes[j] == 0){
                printf(" x %lld", primes[j]);
                temp /= primes[j];
            }
        }
        while ( temp != 1){
            if (temp % i == 0){
                printf(" x %lld", i);
                primes[curlen++] = i;
                temp /= i;
            } else {
                if ( i == 2){
                    i++;
                } else {
                    i+=2;
                }

            }
        }
        printf("\n");

        return 0;
    }
}
