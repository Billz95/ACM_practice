#include <stdio.h>
int check_daff ( int in){
    int a = in / 100;
    int b = in / 10 - a * 10;
    int c = in % 10;
    if (in == a*a*a + b*b*b + c*c*c) return 1;
    return 0;
}
int main(int argc, const char *argv[])
{
    int i;
    for ( i = 100; i < 1000; i++){
        if (check_daff(i)) printf("%d\n", i);
    }

    return 0;
}
