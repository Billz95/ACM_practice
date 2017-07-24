#include <stdio.h>

int getWs(int *bets, int len){

    int i, j;
    int maxWs = 0;
    int sum = 0;
    for ( i = 0; i < len - 1; i++){
        sum = bets[i];
        for ( j=i+1; j < len; j++){
            sum += bets[j];
            if (sum > maxWs) maxWs = sum;
        }
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
