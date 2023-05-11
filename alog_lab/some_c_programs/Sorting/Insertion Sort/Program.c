#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int v[], int n, FILE *fptr)
{
	int i,j;
    clock_t start, end;
    double runtime;
    start = clock();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i + 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    end = clock();
    runtime = ((double)(end - start)) / CLOCKS_PER_SEC;
    fprintf(fptr, "%d %lf\n", n, runtime);
}

void selection_sort(int v[], int n, FILE *fptr)
{
    clock_t start, end;
    double runtime;
    start = clock();
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (v[j] < v[min_idx])
                min_idx = j;

        if (min_idx != i)
            swap(&v[min_idx], &v[i]);
    }
    end = clock();
    runtime = ((double)(end - start)) / CLOCKS_PER_SEC;
    fprintf(fptr, "%d %lf\n", n, runtime);
}
void insertion_sort(int arr[], int n, FILE *fptr)
{
    clock_t start, end;
    double runtime;
    start = clock();
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    end = clock();
    runtime = ((double)(end - start)) / CLOCKS_PER_SEC;
    fprintf(fptr, "%d %lf\n", n, runtime);
}

int main()
{
    FILE *fptr1 = fopen("bubblew.txt", "w");
    FILE *fptr2 = fopen("selectionw.txt", "w");
    FILE *fptr3 = fopen("insertionw.txt", "w");
    int n,i;
    for (n = 1000; n <= 100000; n += 5000)
    {
        int lb = 1, ub = 1000000;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            arr[i] = rand() % (ub - lb + 1) + lb;
            //arr[i]=n-i;
        }
        bubble_sort(arr, n, fptr1);
        selection_sort(arr, n, fptr2);
        insertion_sort(arr, n, fptr3);
    }
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
}
