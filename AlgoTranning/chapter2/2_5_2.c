#include <stdio.h>
int main(int argc, const char *argv[])
{
    int a,b,c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    int i;
    int found = 0;
    for ( i = 10; i < 100 && !found; i++){
        if ( i % 3 == a &&
             i % 5 == b &&
             i % 7 == c){
            found = 1;
        }
    }
    if (found){
        printf("%d\n", i);
    } else{
        printf("No answer\n");
    }
    return 0;
}
