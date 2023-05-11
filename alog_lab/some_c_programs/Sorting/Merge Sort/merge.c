#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
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
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void print(int arr[], int n, FILE *fptr)
{
    clock_t start, end;
    double runtime;
    start = clock();

    mergeSort(arr, 0, n - 1);

    end = clock();
    runtime = ((double)(end - start)) / (double)CLOCKS_PER_SEC;
    fprintf(fptr, "%d %.9lf\n", n, runtime);
}

int main()
{
    FILE *fptr = fopen("mergew.txt", "w");
    int n, i;
    for (n = 1000; n <= 100000; n += 10000)
    {
        int lb = 1, ub = 1000000;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            // arr[i] = rand() % (ub - lb + 1) + lb;
            //  if (i < n / 2)
            // arr[i] = i;
            // else
            arr[i] = n - i;
        }
        print(arr, n, fptr);
    }
    fclose(fptr);
}
