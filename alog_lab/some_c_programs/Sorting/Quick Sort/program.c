#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quick_sort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quick_sort(arr, p, q - 1);
        quick_sort(arr, q, r);
    }
}
void print(int arr[], int n, FILE *fptr)
{
    clock_t start, end;
    double runtime;
    start = clock();

    heapsort(arr, n);

    end = clock();
    runtime = ((double)(end - start)) / (double)CLOCKS_PER_SEC;
    fprintf(fptr, "%d %.9lf\n", n, runtime);
}

int main()
{
    FILE *fptr = fopen("heapw.txt", "w");
    int n, i;
    for (n = 1000; n <= 100000; n += 1000)
    {
        int lb = 1, ub = 1000000;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            arr[i] = rand() % (ub - lb + 1) + lb;
        }
        print(arr, n, fptr);
    }
    fclose(fptr);
}