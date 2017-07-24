#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    char buf[100];
    FILE* fin;
    fin = fopen("input.in", "r");
    while (fgets(buf, 100, fin) != NULL)
    {
        int len = strlen(buf) - 1;
        int flag = 1;
        buf[len] = 0;
        for (int i = 0; i < len/2; i++){
            if (buf[i] != buf[len-i-1]){
                printf("%s\n", "NO");
                flag = 0;
                break;
            }

        }
        if (flag) printf("YES\n");
        printf("%s\n\n", buf);
    }

    return 0;
}
