#include <stdio.h>

#define max(a, b) (a > b) ? a : b
void pArray(long long *a, long long size){
    long long i;
    for (i = 0; i < size; i++){
        printf("%lld ", a[i]);
    }
    printf("\n");
}

long long kadane(long long *a, int size)
{
    long long here, overall;
    here = overall = 0;
    long long i;
    for( i = 0; i < size; i++) {
        here = max(0, here + a[i]);
        overall = max(overall, here);
    }

    return overall;
}

int main()
{
    int N = 0;
    scanf("%d", &N);

    // init array
    // [col][row]
    long long matrix[1000][1000];
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }

    /** for ( i = 0; i < N; i++) { */
        /** for (j = 0; j < N; j++) { */
            /** printf("%d\t", matrix[i][j]); */
        /** } */
        /** printf("\n"); */
    /** } */
    /** printf("\nDONE\n"); */

    long long overall = 0;
    /** int here = 0; */

    int l, r;
    for (l = 0; l < N; l++) {
        long long array[100] = {0};
        for (r = l; r < N; r++) {
            for ( i = 0; i < N; i++){
                array[i] += matrix[i][r];
            }
            /** pArray(array, N); */
            overall = max(overall, kadane(array, N));
        }
    }

    printf("%lld\n", overall);


    return 0;
}
