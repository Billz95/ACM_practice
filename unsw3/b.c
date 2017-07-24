#include <stdio.h>

int main(int argc, const char *argv[])
{
    char dropped[100001] = {0};
    int n;
    scanf("%d", &n);

    int top = n;
    int i = 0;
    while ( i < n){
        int drop;
        scanf("%d", &drop);
        dropped[drop] = 1;
        while( top > 0 && dropped[top]){
            printf("%d ", top);
            top--;
        }
        printf("\n");
        i++;
    }
    return 0;
}
