#include <stdio.h>

int getMaxVal(int *houses, int len, int limit)
{
    int sum[300000] = {houses[0]};
    int heads[300000] = {0};
    int maxVal = 0;
    if (houses[0] < limit) maxVal = houses[0];

    int i;

    for ( i = 1; i < len; i++) {
        heads[i] = heads[i-1];
        sum[i] = sum[i - 1] + houses[i];
        while (sum[i] > limit ) {
            sum[i] -= houses[heads[i]];
            heads[i]++;
        }

        if (sum[i] > maxVal)
            maxVal = sum[i];

    }
    return maxVal;


}

int main(int argc, const char *argv[])

{
    int N = 0;
    int M = 0;

    scanf("%d %d", &N, &M);


    int houses[300000] = {0};
    int i = 0;
    while ( i < N ) {
        scanf("%d", &houses[i]);
        i++;
    }
    int maxVal = getMaxVal(houses, N, M);
    printf("%d", maxVal);





    return 0;
}
