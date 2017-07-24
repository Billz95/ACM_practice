#include <stdio.h>
#define max_n 400000
#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b

void show(int a[], int start, int end)
{
    int i;
    for ( i = start; i < end; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int initTree(int a[],int i, int start, int end)
{
    if ( i >= start && i <= end) {
        return a[i];
    }
    int mid = (start + end) / 2;
    a[i] = initTree(a, i * 2, start, mid) * initTree(a, i*2+1, mid + 1, end);
    return a[i];
}

int getTwo(int in)
{
    /** printf("%d as input\n", in); */
    int i = 1;
    while (i < in) {
        i *= 2;
    }
    /** printf("%d as output\n", i); */
    return i;
}

void update(int a[], int tochange, int val, int i, int start, int end)
{
    if (start == end) {
        a[i] =val;
        return;
    }
    int mid = (start+end) / 2;
    if ( tochange <= mid ) update(a, tochange, val, i*2, start, mid);
    else update(a, tochange, val, i*2 + 1, mid + 1, end);
    a[i] = a[i*2] * a[i*2 + 1];
}

void handle_c(int a[], int first, int second)
{
    // update(a, numE+3, 5, 1, numE, numE * 2);
    update(a, first+ a[0], second , 1,a[0], a[0]*2 );
}

long handle_q(int a[], int left, int right, int i, int start, int end)
{
    /** if (a[i] == 5) { */
        /** printf("left %d right %d i %d start %d end %d\n", left, right, i, start, end); */
    /** } */
    if (start == left && end == right){
        /** printf("**%d**", a[i]); */
        return a[i];
    }
    int mid = (start + end)/2;
    long ans = 1;
    if (left <= mid) ans *= handle_q(a, left, min(right, mid), i * 2, start, mid);
    if (right > mid) ans *= handle_q(a, max(mid + 1, left), right, i * 2 + 1, mid +1, end);
    return ans;
}

int handle_case(int numE, int numQ)
{

    // set to 1
    int a[max_n];
    int i;
    for (i = 0; i < max_n; i++) {
        a[i] = 1;
    }


    int twos = getTwo(numE);
    // read val for array
    for (i = 0; i < numE; i++) {
        scanf("%d*c", &a[twos + i]);
    }
    numE = twos;
    a[0] = twos;
    /** printf("num level = %d\n", twos); */
    // show(a, numE, numE*2);

    initTree(a, 1, numE, numE * 2 - 1);
    show(a, 0, numE*2);
    for ( i = 0; i < numQ; i++) {
        char t;
        int first, second;
        while ( (t = getchar()) == '\n') {
        }
        scanf("%d %d", &first, &second);
        /** fprintf(stderr, " query: %c %d %d\n", t, first, second); */
        if ( t == 'C') {
            handle_c(a, first, second);
        } else {
            long ans = handle_q(a, first - 1 + a[0], second - 1 + a[0], 1, a[0], 2 * a[0]-1);
            printf("ans is %ld\n", ans);
            if (ans > 0) {
                printf("+");
            } else if (ans < 0) {
                printf("-");
            } else {
                printf("0");
            }
        }
        show(a, 0, numE*2);
    }
    printf("\n");

    // update(a, numE+3, 5, 1, numE, numE * 2);
    // show(a, 0, numE*2);


    return 0;
}

int main()
{
    //read n,q
    int numE, numQ;
    while (scanf("%d %d", &numE, &numQ) == 2) {
        handle_case(numE, numQ);
    }
    return 0;
}
