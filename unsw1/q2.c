#include <stdio.h>
#include <string.h>

int abs(int a){
    return (a >= 0) ? a : -a;
}

int findR (int in, int out){
    int a =  abs(in - out);
    int ret = (a >= 13) ? 26-a : a;
    /** printf("from %c to %c is %d rotates\n", out, in, ret); */
    return ret;
}

int main(int argc, const char *argv[])
{
    //read word
    char word[100];
    scanf("%s", word);

    int i;
    int len;
    int rot = 0;
    for (i = 0, len = strlen(word) ; i < len; i++){
        char pre = (i == 0) ? 'a' : word[i-1];
        rot += findR(word[i], pre);

    }

    printf("%d", rot);

    return 0;
}
