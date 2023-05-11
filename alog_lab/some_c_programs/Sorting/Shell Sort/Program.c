#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int arr[], int n)
{
    int gap, i;
    for (gap = n / 2; gap > 0; gap /= 2)
    {

        for (i = gap; i < n; i += 1)
        {

            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

void print(int arr[], int n, FILE *fptr)
{
    clock_t start, end;
    double runtime;
    start = clock();

    shellSort(arr, n);

    end = clock();
    runtime = ((double)(end - start)) / (double)CLOCKS_PER_SEC;
    fprintf(fptr, "%d %.9lf\n", n, runtime);
}

int main()
{
    FILE *fptr = fopen("shellb.txt", "w");
    int n, i;
    for (n = 1000; n <= 100000; n += 1000)
    {
        int lb = 1, ub = 1000000;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            // arr[i] = rand() % (ub - lb + 1) + lb;
            arr[i] = i;
        }
        print(arr, n, fptr);
    }
    fclose(fptr);
}
