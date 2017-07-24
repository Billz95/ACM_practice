#include <stdio.h>
int main(int argc, const char *argv[])
{
    unsigned long long n;
    scanf("%lld", &n);
    int res = 1;
    if (n > 0){
        int a[] = {6, 8, 4, 2};
        res = a[n % 4];
    }
    printf("%d", res);

    return 0;
}
