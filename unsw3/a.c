#include <stdio.h>
#define as 5
void p_array(int *chefs)
{
    int i;
    for ( i = 1; i <= as; i++) {
        printf("%d ", chefs[i]);
    }
    printf("\n");
}

int find(int *chefs, int finder)
{
    if (chefs[finder] == finder) return finder;
    int leader = find(chefs, chefs[finder]);
    chefs[finder] = leader;
    return leader;
}

void join(int *chefs, int loser, int winner)
{
    int leader = find(chefs, loser);
    chefs[leader] = winner;
}

void handle_test(int *S, int *chefs)
{
    int test = 0;
    scanf("%d", &test);
    if (test) {
        // give origin
        int d;
        scanf("%d", &d);
        printf("%d\n", find(chefs, d));
        /** p_array(chefs); */
    } else {
        // compare
        int a,b;
        scanf("%d %d", &a, &b);
        if (find(chefs, a) == find(chefs, b)) {
            printf("Invalid query!\n");
            return;
        } else if (S[a] > S[b]) {
            // a wins
            join(chefs, b, a);
        } else if (S[b] > S[a]) {
            // b wins
            join(chefs, a, b);
        }

    }
}


void chef()
{
    int n_chef;
    scanf("%d", &n_chef);
    int i;
    int dishes[100005] = {0};
    int chefs[100005] = {0};
    // read in dish
    for ( i = 1; i <= n_chef; i++) {
        scanf("%d", &dishes[i]);
        chefs[i] = i;
    }

    int n_testCase;
    scanf("%d", &n_testCase);

    for (i = 0; i < n_testCase; i++) {
        handle_test(dishes, chefs);
    }
}

int main(int argc, const char *argv[])
{
    int n;
    scanf("%d", &n);
    int i = 0;
    while (i < n) {
        chef();
        i++;
    }
    return 0;
}
