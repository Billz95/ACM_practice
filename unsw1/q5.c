#include <stdio.h>

int main(int argc, const char *argv[])
{
    long long n;
    long long m;
    int col[100001] = {0};
    int row[100001] = {0};

    scanf("%lld %lld", &n, &m);
    long long ac = n, ar = n;
    int i;
    for (i = 0; i < m; i++){
        long long c, r;
        scanf("%lld %lld", &c, &r);
        if (!col[c]){
            /** printf("new col\n"); */
            col[c] = 1;
            ac--;
        }

        if (!row[r]){
            /** printf("new row\n"); */
            row[r] = 1;
            ar--;
        }
        /** printf("ac %ld ar %ld\n", ac, ar); */
        printf("%lld ", ac * ar);
        /** printf("\n"); */
    }
    return 0;
}
