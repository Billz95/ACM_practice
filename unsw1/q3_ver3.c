#include <stdio.h>
#define max(a, b) (a > b) ? a : b
void main(){
    int N = 0;
    scanf("%d", &N);
    while ( N != 0){
        int i, bet, here = 0, overall = 0;
        for ( i = 0; i < N; i++){
            scanf("%d", &bet);
            here = max(0, here + bet);
            overall = max(overall, here);
        }
        if (overall <= 0)
            printf("Losing streak.\n");
        else{
            printf("The maximum winning streak is %d.\n", overall);
        }
        scanf("%d", &N);
    }
}
