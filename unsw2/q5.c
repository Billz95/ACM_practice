#include <stdio.h>
int main(int argc, const char *argv[])
{
    int n;
    scanf("%d", &n);
    int i = 0;
    for ( i = 0; i < n; i++){
        long long k, l, h;
        scanf("%lld %lld %lld", &k, &l, &h);
        printf((h-l)/k + 1
    }
    return 0;
}
