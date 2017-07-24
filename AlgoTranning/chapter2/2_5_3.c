#include <stdio.h>
int main(int argc, const char *argv[])
{
    int n;
    scanf("%d", &n);
    n = 2 * (n - 1) + 1;
    int i;
    for ( i = 0; 2 * i <= n; i++){
        int j;
        for ( j = 0; j < i; j++){
            printf(" ");
        }

        for ( j = 0; j < n - 2 * i; j++){
            printf("*");
        }

        for ( j = 0; j < i; j++){
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
