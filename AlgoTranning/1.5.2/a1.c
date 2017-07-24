#include <stdio.h>
int main(int argc, const char *argv[])
{
    double a = 0.0/0.0;
    if ( a > 0) printf(">0\n");
    else if ( a == 0) printf("=0\n");
    else if ( a < 0) printf ("< 0\n");
    else printf("the hack\n");

    int b, c;
    scanf("%d%d", &b, &c);
    printf("%d %d\n", b, c);
    return 0;
}
