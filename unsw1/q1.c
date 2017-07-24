#include <stdio.h>

int abs(int a){
    return (a >= 0) ? a : -a;
}

int findD(int a[], int p){
    int dist = 0;
    int i;
    for (i = 0; i < 3; i++){
        dist += abs(a[i] - p);
    }

    /** printf("dist for %d %d %d is %d\n", a[0], a[1], a[2], dist); */


    return dist;
}

int main(int argc, const char *argv[])
{
    int points[3] = {0};

    int i;
    for (i = 0; i < 3 ; i++){
        scanf("%d", &points[i]);
    }

    // min max finder
    int min, max;
    min = max = points[0];
    for (i = 1; i < 3; i++){
        if (points[i] < min){
            min = points[i];
        } else if (points[i] > max){
            max = points[i];
        }
    }
    /** printf("min : %d, max : %d\n", min, max); */

    int minD = 2147483647; // max
    for ( i = min; i < max; i++){
        int dist = findD(points, i);

        if (dist < minD){
            minD = dist;
        }
    }
    printf("%d", minD);

    return 0;
}
