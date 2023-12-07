// merge sort
#include <stdio.h>

void merge(int arr[], int p, int q, int r);
void Sort(int arr[], int p, int r);

int main()
{
    int a, p[100], r;
    printf("Enter the size of the array: ");
    scanf("%d", &a);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &p[i]);
    }

    Sort(p, 0, a - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < a; i++)
    {
        printf("%d ", p[i]);
    }

    return 0;
}

void Sort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        Sort(arr, p, q);
        Sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
