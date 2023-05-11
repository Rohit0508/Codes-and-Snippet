#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>

// Get the digit at the specified position
int get_digit(int num, int pos)
{
    int pow = 1;
    for (int i = 0; i < pos; i++)
    {
        pow *= 10;
    }
    return (num / pow) % 10;
}

void radix_sort(int arr[], int n)
{
    int sorted[n];
    int max_digits = 3;
    for (int pos = 0; pos < max_digits; pos++)
    {
        int count[10] = {0};

        // Count occurrences of each digit
        for (int i = 0; i < n; i++)
        {
            count[get_digit(arr[i], pos)]++;
        }

        // Update count array to hold indices of sorted array
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        // Build sorted array
        for (int i = n - 1; i >= 0; i--)
        {
            int digit = get_digit(arr[i], pos);
            sorted[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // Copy sorted array back to input array
        for (int i = 0; i < n; i++)
        {
            arr[i] = sorted[i];
        }
    }
}

void print(int arr[], int n, FILE *fptr)
{
    clock_t start, end;
    double runtime;
    start = clock();

    radix_sort(arr, n);

    end = clock();
    runtime = ((double)(end - start)) / (double)CLOCKS_PER_SEC;
    fprintf(fptr, "%d %.9lf\n", n, runtime);
}

int main()
{
    FILE *fptr = fopen("countw.txt", "w");
    int n, i;
    for (n = 1000; n <= 100000; n += 1000)
    {
        int lb = 1, ub = 999;
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
