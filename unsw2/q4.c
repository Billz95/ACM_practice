#include <stdio.h>
int main(int argc, const char *argv[])
{
    int n;
    scanf("%d", &n);

    int i = 0;
    int toggle = 0;
    int consec = 0;
    unsigned long long tot = 1;
    while ( i < n){
        int nut;
        scanf("%d", &nut);
        if (toggle  && nut == 0){
            consec++;
        }

        if (nut == 1){
            toggle = 1;
            tot = tot * (unsigned long long)(consec + 1);
            consec = 0;
        }

        i++;
    }
    if (toggle){
        printf("%lld\n", tot);
    } else {
        printf("0\n");
    }
    return 0;
}
