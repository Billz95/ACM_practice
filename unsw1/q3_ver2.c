#include <stdio.h>

int getWs(int *bets, int len){
    int sum[10000] = {bets[0]};
    int heads[10000] = {0};
    int maxWs = 0;

    int i;
    for ( i = 1; i < len; i++){
        heads[i] = heads[i-1];

        if (sum[i-1] < 0) {
            sum[i] = bets[i];
            heads[i] = i;
        }

        sum[i] = sum[i-1] + bets[i];
        if (heads[i] > 0) sum[i] -= sum[heads[i] - 1];
        if (sum[i] > maxWs) maxWs = sum[i];
    }
    return maxWs;


}

int main(int argc, const char *argv[])
{
    int N = 0;

    scanf("%d", &N);

    while ( N != 0){

        int bets[10000] = {0};
        int i = 0;
        while ( i < N ){
            scanf("%d", &bets[i]);
            i++;
        }

        int ws = getWs(bets, N);

        if (ws <= 0)
            printf("Losing streak.\n");
        else{
            printf("The maximum winning streak is %d.\n", ws);
        }
        scanf("%d", &N);
    }

    return 0;
}
