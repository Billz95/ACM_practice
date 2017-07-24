#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 1;
    double cur;
    double last = 0.000000001;
    double sum = 0;
    int sign = 1;
    cur = 1.0 / i;
    while ( cur >= last){
        sum += sign * cur;
        sign = -sign;
        i+=2;
        cur = 1.0 / i;
        /** printf("%lf\n", cur); */
    }
    printf("%.15lf\n", sum * 4);



    return 0;
}
