#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void maxheapify(int A[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && A[l] > A[largest])
        largest = l;
    if (r < n && A[r] > A[l])
        largest = r;
    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        maxheapify(A, n, largest);
    }
}

void buildmaxheap(int a[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        maxheapify(a, n, i);
    }
}

void heapsort(int a[], int n)
{
    int i;
    int t = n;
    buildmaxheap(a, n);
    for (i = n - 1; i >= 1; i--)
    {
        swap(&a[0], &a[i]);
        maxheapify(a, i, 0);
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
            // arr[i] = rand() % (ub - lb + 1) + lb;
            // if (i < n / 2)
            //     arr[i] = i;
            // else
            arr[i] = n - i;
        }
        print(arr, n, fptr);
    }
    fclose(fptr);
}
