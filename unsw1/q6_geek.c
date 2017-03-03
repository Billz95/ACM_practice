#include <stdio.h>
#include <string.h>
#include <limits.h>

int kadane(int* arr, int* start, int* finish, int n)
{
    int sum = 0, maxSum = INT_MIN, i;

    *finish = -1;

    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i+1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    if (*finish != -1)
        return maxSum;

    maxSum = arr[0];
    *start = *finish = 0;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

void findMaxSum(int M[100][100], int N)
{
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;

    int left, right, i;
    int sum, start, finish;

    for (left = 0; left < N; ++left)
    {
        int temp[100] = {0};

        for (right = left; right < N; ++right)
        {
            for (i = 0; i < N; ++i)
                temp[i] += M[i][right];

            sum = kadane(temp, &start, &finish, N);

            // Compare sum with maximum sum so far. If sum is more, then
            // update maxSum and other output values
            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    // Print final values
    printf("%d", maxSum);
}

// Driver program to test above functions
int main()
{
    int N = 0;
    scanf("%d", &N);

    // init array
    // [col][row]
    int matrix[100][100];
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    findMaxSum(matrix, N);

    return 0;
}
