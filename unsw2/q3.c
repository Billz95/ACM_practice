#include <stdio.h>

long cal_perm ( int n){
    if (n == 0) return 0;
    long num = (long) n;
    return (num) * (num - 1) / 2 ;
}
int main(int argc, const char *argv[])
{
    int diff[3000] = {0};
    int sum[3000] = {0};
    int n;
    scanf("%d", &n);

    int i = 0;

    while (i < n){
        int c,r;
        scanf("%d %d", &c, &r);
        int d = c - r;
        diff[1000 + d]++;
        sum[c + r]++;
        /** printf("%d, diff[1000+d] = %d\n", d, diff[1000+d]); */
        i++;
    }

    long tot = 0;
    for (i = 0; i < 3000; i++){
        tot += cal_perm(diff[i]);
        tot += cal_perm(sum[i]);
    }
    printf("%ld\n", tot);
    return 0;
}
