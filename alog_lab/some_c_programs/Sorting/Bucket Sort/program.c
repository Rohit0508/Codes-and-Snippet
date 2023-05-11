#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void bucket(int a[], int n)
{
    int max = getMax(a, n);
    int bucket[max], i;
    for (int i = 0; i <= max; i++)
    {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        bucket[a[i]]++;
    }
    for (int i = 0, j = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            a[j++] = i;
            bucket[i]--;
        }
    }
}

void print(int arr[], int n, FILE *fptr)
{
    clock_t start, end;
    double runtime;
    start = clock();

    bucket(arr, n);

    end = clock();
    runtime = ((double)(end - start)) / (double)CLOCKS_PER_SEC;
    fprintf(fptr, "%d %.9lf\n", n, runtime);
}

int main()
{
    FILE *fptr = fopen("count.txt", "w");
    int n, i;
    for (n = 1000; n <= 100000; n += 1000)
    {
        int lb = 1, ub = 10000;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            // arr[i] = rand() % (ub - lb + 1) + lb;
            arr[i] = n - i;
        }
        print(arr, n, fptr);
    }
    fclose(fptr);
}
