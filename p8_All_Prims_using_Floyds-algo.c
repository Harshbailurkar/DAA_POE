#include <stdio.h>
int i, j, k;
void floyd(int a[4][4], int n)
{
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    printf("All Pairs Shortest Path is :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int cost[4][4] = {{0, 3, 999, 4}, {8, 0, 2, 999}, {5, 999, 0, 1}, {2, 999, 999, 0}};
    int n = 4;

    floyd(cost, n);
}
