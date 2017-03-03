#include <stdio.h>

int main(int argc, const char *argv[])
{
    int n;
    int m;
    int col[100001] = {0};
    int row[100001] = {0};

    scanf("%d %d", &n, &m);
    long ac = n, ar = n;
    int i;
    for (i = 0; i < m; i++){
        int c, r;
        scanf("%d %d", &c, &r);
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
        printf("%ld ", ac * ar);
        /** printf("\n"); */
    }
    return 0;
}
