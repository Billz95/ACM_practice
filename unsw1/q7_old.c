#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define max(a, b) (a > b) ? a : b
#define min(a, b) (a < b) ? a : b

int main(int argc, const char *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);

    // scan values
    int i;
    int vals[100000] = {0};
    for( i = 0; i < n; i++){
        scanf("%d", &vals[i]);
    }
    /** printf("scanning done\n"); */

    // get kadane h/l
    int h_overall = 0, h_here = 0;
    int l_overall = 0, l_here = 0;
    for ( i = 0; i < n; i++){
        h_here = max(h_here + vals[i], 0);
        l_here = min(l_here + vals[i], 0);

        h_overall = max(h_here, h_overall);
        l_overall = min(l_here, l_overall);
    }
    /** printf("kadane done, h_o %d l_o %d\n", h_overall, l_overall); */

    // find range of power
    int upper = 0;
    int limit = max(h_overall, abs(l_overall));
    /** printf("limit is %d\n", limit); */

    double cur = pow(( double )(k), (double)upper);
    /** printf("cur is %lf\n", cur); */

    char pows_p[900000] = {0};
    char pows_n[900000] = {0};
    while (cur < limit){
        cur = pow(( double )(k), (double)++upper);
        if (cur > 0) pows_p[(int) cur % 900000] = 1;
        else pows_n[abs((int)cur) % 900000] = 1;
        /** printf("cur is %lf\n", cur); */
    }
    /** printf("upper is %d\n", upper); */

    // set up all possible value

    int tot = 0;
    for ( i = 0; i < n; i++){
        int sum = 0;
        int j;
        for ( j = i; j < n; j++){
            sum += vals[j];
            /** printf("sum is %d\n", sum); */
            if ((sum > 0 && pows_p[sum % 900000]) ||
                    ( sum <= 0 && pows_n[abs(sum) % 900000]))
                tot++;
        }
    }

    printf("%d\n", tot);

    return 0;
}
